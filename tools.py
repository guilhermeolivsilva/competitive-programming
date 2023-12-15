import subprocess
from argparse import ArgumentParser, Namespace
from pathlib import Path


def compile(args: Namespace) -> None:
    """
    Compile the exercise into an executable file.

    Arguments
    ---------
    args : Namespace
        An object of `Namespace` that contains the `platform`, `exercise`
        and `language` fields.

    Returns
    -------
    None
    """
    platform = args.platform
    exercise = args.exercise
    language = args.language

    try:
        compiler = _get_compiler(language)
        path = _mount_exercise_path(
            platform,
            exercise,
            language
        )

        subprocess.run([compiler, path])
    except (ValueError, KeyError):
        print(f"This exercise has not been implemented in {language} yet.")


def _get_compiler(language: str) -> str:
    compiler_map = {
        "cpp": "clang++",
        "rust": "rustc",
        "java": "javac"
    }

    return compiler_map[language]


def _mount_exercise_path(
    platform: str,
    exercise: str,
    language: str
) -> str:
    path = f"{platform}/{exercise}/exercise"
    return _get_extension(language).format(path=path)


def _get_extension(language):
    extension_map = {
        "cpp": "{path}.cpp",
        "rust": "{path}.rs",
        "java": "{path}.java"
    }

    return extension_map[language]


def cleanup(args: Namespace) -> None:
    """
    Clean up the project, deleting compiled files.

    Arguments
    ---------
    args : Namespace
        An object of `Namespace` that contains the `platform`, `exercise`
        and `language` fields.

    Returns
    -------
    None
    """
    files_in_tree = _get_in_tree_files(args.platform)
    files_out_of_tree = _get_out_of_tree_files()

    files_to_remove = files_in_tree + files_out_of_tree

    for file in files_to_remove:
        subprocess.run(["rm", "-rf", file])


def _get_in_tree_files(platform: str) -> list:
    _extensions = _get_extensions()

    return [
        file.resolve()
        for file in Path(platform).glob("**/*")
        if file.suffix in _extensions
    ]


def _get_extensions() -> list:
    return [".class"]


def _get_out_of_tree_files() -> list:
    return ["exercise", "a.out", "input", "output"]


def setup(args: Namespace) -> None:
    """
    Setup a new exercise.
    
    This method creates a new folder for it in the platform's directory and
    copies the template of the selected language to it.

    Arguments
    ---------
    args : Namespace
        An object of `Namespace` that contains the `platform`, `exercise`
        and `language` fields.

    Returns
    -------
    None
    """
    platform = args.platform
    exercise = args.exercise
    language = args.language

    try:
        exercise_path = _mount_exercise_path(
            platform,
            exercise,
            language
        )

        template_path = _mount_template_path(language)

        subprocess.run(["mkdir", "-p", f"beecrowd/{exercise}"])
        subprocess.run(["cp", template_path, exercise_path])
    except (ValueError, KeyError):
        print(f"Could not setup this exercise.")


def _mount_template_path(language: str) -> str:
    path = f"templates/{language}"
    return _get_extension(language).format(path=path)


def _get_mode(mode: str) -> str:
    mode_map = _get_mode_map()

    return mode_map[mode]


def _get_mode_map() -> dict:
    return {
        "compile": compile,
        "cleanup": cleanup,
        "setup": setup
    }


if __name__ == "__main__":
    parser = ArgumentParser(
        prog="AutomaticCompiler",
        description="Compiles any exercise in a given programming language"
    )

    parser.add_argument("-p", "--platform", default="beecrowd")
    parser.add_argument("-e", "--exercise")
    parser.add_argument("-l", "--language", default="cpp")
    parser.add_argument("-m", "--mode", required=True)

    args = parser.parse_args()

    try:
        mode_method = _get_mode(args.mode)
        mode_method(args)
    except KeyError:
        print(f"Unexpected mode `{args.mode}`. Available modes are {_get_mode_map.keys()}")
