# my_libasm

## Description

This is a small library of C functions implemented in assembly language, namely with the [NASM assembler](https://en.wikipedia.org/wiki/Netwide_Assembler). The library contains the following functions:

- [strlen](https://man7.org/linux/man-pages/man3/strlen.3.html)
- [strchr](https://man7.org/linux/man-pages/man3/strchr.3.html)
- [index](https://man7.org/linux/man-pages/man3/index.3.html)
- [memset](https://man7.org/linux/man-pages/man3/memset.3.html)
- [memcpy](https://man7.org/linux/man-pages/man3/memcpy.3.html)
- [memmove](https://man7.org/linux/man-pages/man3/memmove.3.html)
- [strcmp](https://man7.org/linux/man-pages/man3/strcmp.3.html)
- [strncmp](https://man7.org/linux/man-pages/man3/strcmp.3.html)
- [strcasecmp](https://man7.org/linux/man-pages/man3/strcasecmp.3.html)
- [read](https://man7.org/linux/man-pages/man2/read.2.html)
- [write](https://man7.org/linux/man-pages/man2/write.2.html)

## Compatibility

The library is written specifically for Linux systems with an x86-64 architecture. It is not compatible with any other kind of system.

## Compiling

To compile the application, you will need the [NASM assembler](https://en.wikipedia.org/wiki/Netwide_Assembler). On Linux, you can install it by running:

```
sudo apt update
sudo apt install nasm
```
Once nasm is installed, run `make` from the project's root directory.

## Running the tests

The `main.c` file contains usages for each of the implemented functions, along with usages of the corresponding built-in functions for comparison purposes. To execute this small demonstration program, run the `my_libasm` executable file output by the previous step.

