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

- objects declared with [static storage](./chapter-2/static.c) persist after their function has exited
    - static objects must be initialized with a constant value and not a variable
        ```c
        int *func(int i) {
            const int j = i; // ok
            static int k = j; // error
            return &k;
        }
        ```

- An _alignment_ represents the number of bytes between successive addresses ad which a given bject can be allocated
    - [example](./chapter-2/alignment.c)
    - I'm not sure I understand the example correctly, why does the author use the type 'unsigned char' to declare a buffer for the struct S?
    - I am noticing that he hasn't used typedef for the struct so you can't use it like a normal type ` S buffer[sizeof(struct S)] `
    - is that why it needs realignment using _Alignas? 

- C has 3 character types, char [a-zA-Z0-9], signed char and unsigned char, which can represent integer values
    - there is also a wide character type, wchar_t to allow large character sets (non English letters)

- a function declared with no parameters accepts any number of arguments of any type

- `str[i]` is equivalent to `*(str + i)`

- _POSIX_ stands for Portable Operating System Interface

- you can use a struct definition as a type definition for a pointer
- sigline and sigline_p are available for use right away, they have been defined but are uninitialized
    ```C
    struct sigrecord {
        int signum;
        char signame[20];
        char sigdesc[100];
    } sigline, *sigline_p;
    ```
- SEE page 31 for an explanation of tags and self referential structs
- examples:
    ```C
    struct tnode {
        int count;
        struct tnode *left;
        struct tnode *right;
    }

    typedef struct tnode {
        int count;
        struct tnode *left;
        struct tnode *right;
    } tnode;

    typedef struct tnode tnode;
    struct tnode {
        int count;
        tnode *left;
        tnode *right;
    } tnode;
    ```

- (33) "Objects of _volatile_-qualified types serve a special purpose. Static volatile qualified objects are used to model momory-mapped input/output (I/O) ports, and static constant volatile-qualifed objects odel memory-mapped input ports such as a real-time clock. The values stored in these objects may change without the knowledge of the compiler \[...\] Using a volatile-qualified type lets the compiler know that the value may change, and ensures that every access to the real-time clock occurs (otherwise, an access to the real-time clock may be optimized away or replaced by a previously read and cached value)."

