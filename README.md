# competitive-programming
Solutions to a variety of competitive programming exercises.

# Usage

Simply invoke the ``compile`` script from the project root with the following
arguments:

* ``--platform`` (or ``-p``): the platform where the exercise was listed on
(eg., beecrowd). Defaults to ``beecrowd``.
* ``--exercise`` (or ``-e``): the exercise name or ID.
* ``--language`` (or ``-l``): the programming language of choice for the
solution. Defaults to ``cpp``.
* ``--cleanup``: remove any compiled programs, as well as any input or output
files. This execution mode only requires a ``platform`` to be specified.

The program will be compiled to the default output file the compiler generates
(eg., ``a.out`` for C++ programs).
