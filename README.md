# effective-c
book notes for "Effective C" by Robert C. Seacord

### Introduction

- The _spirit of c_
    - Trust the programmer (c assumes you know what you're doing)
    - Don't prevent the programmer from doing what needs to be done
    - Keep the language small and simple
    - Provide only one way to do an operation. Also known as _conservation of mechanism_
    - Make it fast

### Chapter 1: Gettting Started With C
- invoke the linux system compiler `cc hello.c`
- `#include` statements are preprocessor directives
- (3) "C defines two possible execution environments: _freestanding_ and _hosted_. A freestanding environment may not provide an operating system and is typically used in embedded programming."
