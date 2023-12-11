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
        compilation_arguments = _mount_compilation_arguments(
            platform,
            exercise,
            language
        )

        subprocess.run([compiler, compilation_arguments])
    except (ValueError, KeyError):
        print(f"This exercise has not been implemented in {language} yet.")


def _get_compiler(language: str) -> str:
    compiler_map = {
        "cpp": "clang++",
        "rust": "rustc",
        "java": "javac"
    }

    return compiler_map[language]


def _mount_compilation_arguments(
    platform: str,
    exercise: str,
    language: str
) -> str:
    path = f"{platform}/{exercise}/exercise"

    extension_map = {
        "cpp": f"{path}.cpp",
        "rust": f"{path}.rs",
        "java": f"{path}.java"
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
        subprocess.run(["rm", "-f", file])


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


if __name__ == "__main__":
    parser = ArgumentParser(
        prog="AutomaticCompiler",
        description="Compiles any exercise in a given programming language"
    )

    parser.add_argument("-p", "--platform", default="beecrowd")
    parser.add_argument("-e", "--exercise")
    parser.add_argument("-l", "--language", default="cpp")
    parser.add_argument("--cleanup", action="store_true")

    args = parser.parse_args()

    if args.cleanup:
        cleanup(args)
    else:
        compile(args)
