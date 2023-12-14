# competitive-programming
Solutions to a variety of competitive programming exercises.

# Usage

Simply invoke the ``tools`` script from the project root with the following
arguments:

* ``--platform`` (or ``-p``): the platform where the exercise was listed on
(eg., beecrowd). Defaults to ``beecrowd``.
* ``--exercise`` (or ``-e``): the exercise name or ID.
* ``--language`` (or ``-l``): the programming language of choice for the
solution. Defaults to ``cpp``.
* ``--mode``: operation mode.
  * ``compile``: compiles the exercise and outputs the binary to the project
    root. The program will be compiled to the default output file the compiler
    generates (eg., ``a.out`` for C++ programs). (Except for Java. In this
    case, the ``.class`` is generated at the exercise's folder.)
  * ``cleanup``: remove any compiled programs, as well as any input or output
    files.
  * ``setup``: sets up a new exercise, creating its folder and copying one of
    the templates to it.
