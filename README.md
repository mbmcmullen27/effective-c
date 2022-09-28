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

### Chapter 3: Arithmetic Types

- constants for maximum and minimum representable values are stored in `<limits.h>`
- when declaring an `unsigned` value, the `int` keyword can be omitted 
- loop that never terminates because of integer wraparound
    ```C
    for (unsigned int i = n; i >=0; i--)
    ```
    
- author pens an ugly nested conditional operator (?:) on page (43)
- I think he does this because macros have strict rules about newlines
    ```C
    #define AbsM(i,flag) ((i) >= 0 ? (i) : ((i)==(flag) ? (flag) : -(i)))
    ```

- (44) "Unsigned integers have well-defined wraparound behavior. Signed integer overflow, or the possibility of it, should always be considered a defect."
- if a constant starts with a 0 followed by other digits its an _octal constant_
- _hexadecimal constants_ are prefixed with `0x`
    ```C
    int permissions = 0777 // octal
    int burger = 0xDEADBEEF // hex
    ```
- _implicit conversion_ between types (casting) is sometimes called _coercion_
- (53) "try not t use explicit conversions because casts can disable important diagnostics"
    - which diagnostics?

### Chapter 4: Expressions and Operators

- _side effects_ are changes to the state  of the execution environment
- _function designator_ is an expression that has function type and is used to invoke a function
    - in an expression a function designator is converted to _pointer-to-function returning type_ at compile time
- _variadic functions_ are functions that take a variable number of arguments

- example of passing a function as an argument (see also [exercise_2](./chapter-2/excercise_2.c))
    ```C
    int f(void){
        // ...
        return 0;
    }
    void g(int (*func)(void)) {
        // ...
        if (func() != 0)
            printf("g failed\n");
    }

    g(f);
    ```
    - g could also be defined `g(int func(void))`

- `++i` is equivalent to `i = i + 1` except that _i_ is evaluated only once
    - I remeber being taught that ++i was more efficient because of 'compiler optimizations' and this must be what they meant

- addition is left associative `a + b + c` is equivalent to `((a + b) + c)`
- assignment is right associative `a = b = c` is equivalent to `(a = (b = c))`

QUESTION: what's a _compound literal_?

- a _sequence point_ is the juncture at which all side effects will have completed
    - in between full expressions
    - entering or exiting a called function

- (67) the operand to sizeof is not evaluated
    - does passing an expression to sizeof cause an error?

- (71) "Even though you could use left and right shifts to multiply or divide by a power of two, it's not a good idea to use a shift operation for this purpose. It is best to use the multiplication and division operations and let the compiler determine when to optimize processing by replacing these operations with a shift operation. Performing this substitution yourself is an example of _premature optimization_. Donald Knuth \[...\] has described premature optimization as 'the root of all evil.'"

- (74) on short circuiting logical operators || and &&, "Because of this, unevaluated is not evaluated to determine its value"
    - "Short circuiting is commonly used in operations with pointers"
        ```C
        bool isN(int* ptr, int n) {
            return ptr && *ptr == n; // don't dereference a null pointer
        }
        ```

- (79) C allows a pointer t be formed to each element of an array, including one past the last element of the array object (also reffered to as the _too-far_ pointer)

### Chapter 5: Control Flow

- a _compound statement_ or _block_ isexecuded as a single statement
    - this is why an if statement can have no braces and a single expression, or take a block    

- compiler flag `-Wswitch-enum` will help diagnose unhandled enum values in switch statements
    - there seems to be a lot of useful debugging flags, but how helpful are they if you need to know which ones to include ahead of time?

- smart use of goto and labels: goto chain for cleaning up memory/closing files
    - (94) resources are allocated in a certain order, operated upon, and then released in reverse

##### Excercises
2. find_element in Listing 5-13 already returns the position of the key

### Chapter 6: Dynamically Allocated Memory

- (100) Dynamically allocated memory is allocated from the _heap_, which is simply one or more large, subdividable blocks of memory that are managed by the memory manager

- `calloc` allocates storage for an array of objects:
    ```c
    void *calloc(size_t nmemb, size_t size)
    ```    
    - whats the difference between `calloc` and `reallocarray`?
- to prevent duplicate calls to free and attempts to access freed memory, set a pointer to null after freeing it
    ```c
    char *ptr = malloc(16);
    // ...
    free(ptr);
    ptr = NULL;
    ```
- (110) Starting with C99, the last member of a struct with more than one member can have _incomplete array type_, which means that the [array](./chapter-6/incomplete_array_type.c) has an unknown size.
    - see CERT C rule MEM33-C for more information on allocatin and copying structures containing flexible array members

- you can use [dmalloc](https://dmalloc.com/) to debug memory allocation issues. [example](./chapter-6/dmalloc.c)

### Chapter 7: Characters and Strings

- (122) Instead of specifying a character encoding like java, each C implementation defines botha  _source character set_ in which source files are written and an _execution character set_ used for character and string literals at compile time

- (133) There is some risk that, if the string literal changes during maintenance, a string could unintentionally be changed to a character array with no terinating null character, particularly when the string literal is defined separately from the declaration \[...\] If you don't specify the bound of the array, the compiler will allocate sufficient space for the entire string literal, including the terminating null character.

- (134) POSIX also defines several string-handling functions, such as strdup and strndup, that provide another set of string APIs you can use on POSIX-compliant platforms such as Linux and Unix (IEE Std 1003.1:2018)
    - **POSIX defines functions? So is it a library? What does it actually mean to be POSIX-compliant?**

- (138) common strcpy implementation
    ```c
    char *strcpy(char *dest, const char *src) {
        char *save = dest;
        while (*dest++ = *src++);
        return save;
    }
    ```
    - This is a very dense while loop, it looks very clean 

- (139) don't assume that the C Standard Library functions validate arguments unless the standard explicitly requires them to.
- (140) The gets function is a flawed input function that accepts input without providing any way to specify the size of the destination array. For that reason, it cannot prevent buffer overflows \[...\] the gets function was deprecated in C99 and eliminated from C11. \[...\] You should _never_ use this function, and you should replace any use of the gets function you find in any code you are maintaining.
    - "Because the gets function is so bad, we'll spend some time examining why it's so awful"
    - lol

- Annex K bountds checking interface has a fixed version `gets_s`
- POSIX string functions (strdup, strndup) allocate dynamic memory when called so each need to be followed by a call to free
