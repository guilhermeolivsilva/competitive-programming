import subprocess
from argparse import ArgumentParser


def compile(args: ArgumentParser) -> None:
    """
    Compile the exercise into an executable file.

    Arguments
    ---------
    args : ArgumentParser
        An object of `ArgumentParser` that contains the `platform`, `exercise`
        and `language` fields.

    Returns
    -------
    None
    """

    platform = args.platform
    exercise = args.exercise
    language = args.language

    compiler = _get_compiler(language)
    compilation_arguments = _mount_compilation_arguments(
        platform,
        exercise,
        language
    )

    subprocess.run([compiler, compilation_arguments])


def _get_compiler(language: str) -> str:
    compiler_map = {
        "cpp": "clang++"
    }

    return compiler_map[language]


def _mount_compilation_arguments(
    platform: str,
    exercise: str,
    language: str
) -> str:
    path = f"{platform}/{exercise}/exercise"

    extension_map = {
        "cpp": f"{path}.cpp"
    }

    return extension_map[language]


if __name__ == "__main__":
    parser = ArgumentParser(
        prog="AutomaticCompiler",
        description="Compiles any exercise in a given programmin language"
    )

    parser.add_argument("-p", "--platform")
    parser.add_argument("-e", "--exercise")
    parser.add_argument("-l", "--language")

    args = parser.parse_args()

    compile(args)
