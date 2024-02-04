# Chapter 11

## Overview

Several features in this chapter rely on the
`C11 Annex K Bounds-Checking Interfaces`. However, support for `Annex K` is
limited in many compilers, such as `gcc` and `clang`. The presence of `Annex K`
support can be verified using the `__STDC_LIB_EXT1__` macro
([error-handling][error-handling]).

To address this limitation, the [safeclib library][safeclib] can be utilized, as
it provides an implementation of these interfaces.

## Safeclib Library

### Manual Installation

Refer to the [safeclib GitHub repository][safeclib] for detailed installation
instructions.

### Installation Script

For convenience, the installation of `safeclib` can be facilitated using the
provided script [install-safeclib.sh](./install-safeclib.sh). This script is
intended for demonstration purposes.

Ensure the following tools are installed:

- libtool
- autoconf
- automake

To use the installation script, execute the following commands:

```sh
sudo ./install-safeclib.sh
```

## Build and Run a Program

To build a program, link the `safeclib` library.

For example:

```sh
cc -o my_program source.c -lsafec
./my_program
```

[safeclib]: https://github.com/rurban/safeclib
[error-handling]: https://en.cppreference.com/w/c/error
