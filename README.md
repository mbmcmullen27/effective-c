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

### Chapter 2: Objects, Functions and Types

- an _object_ is storage in which you can represent values

- multiple declarations, the following are all valid:
    ```c
    char *src, c;
    int x, y[5];
    int m[12], n[15][3], o[21];
    ```

- (15) "each object has a storage duration that determines its _lifetime_, which is the time during program execution for which the object exists, has storage, ahas a constant address, and retains its last-stored value. Objects must not be referenced outside thier lifetime."

- objects in local scope have _automatic storage duration_, they exist until execution leaves the block they're defined in

- (16) "C distiguishes between _parameters_, which are objects declared as part of the function declaration that acquire a value on entry to the function, and _arguments_, which are comma-separated expressions you include in the function call expression."