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
- A C program is considered _strictly conforming_ if it only uses features of the language specified in the standard
    - no real world program is strictly conforming 

    - _Implementation Defined Behavior_
        - behavior not specified by the standard and may offer different results among implementations but is consistent within an implementation
        - ex: number of bits in a byte    

    - _Unspecified Behavior_
        - behavior for which the standard provides two or more options but imposes no requirement on which option is chosen by an implementation. Each execution of a given expression may have different results or produce a different value than a previous execution of the same expression
        - ex: function parameter storage layout, which can varry among function invocations within the same program

    - _Undefined Behavior_
        - behavior that is not defined by the c standard
        - ex: signed integer overflow and dereferencing an invalid pointer value

    - _Locale Specific Behavior_
        - behavior that depends on local conventions of nationality, culture, and language     