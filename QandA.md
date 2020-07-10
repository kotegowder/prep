Some of the questions for Embedded Programmers

1. Using #define statement, how would you declare a manifest constant that returns the number of seconds in a year? Disregard leap years in your answer.

    <details><summary>Click for answer!</summary>

    #define SECONDS_PER_YEAR (365UL * 24UL * 60UL * 60UL)

    </details>

2. Write a 'standard' MIN macro. That is, a macro that takes two arguments and returns the smaller of the two arguments.

    <details><summary>Click for answer!</summary>

    #define MIN(A, B) ((A) < (B) ? (A) : (B))
    
    </details>

3. Using the variable a, write down definitions for the following: <br />
        3.1 An integer <br />
        3.2 A pointer to an integer <br />
        3.3 A pointer to a pointer to an integer <br />
        3.4 An array of ten integers <br />
        3.5 An array of ten pointers to integers <br />
        3.6 A pointer to an array of ten integers <br />
        3.7 A pointer to a funtion that takes an integer argument and return an integer <br />
        3.8 An array of ten pointers to functions that take an integer argument and return an integer <br />
    <details><summary>Click for answer!</summary>

    3.1 int a; <br />
    3.2 int *a; <br />
    3.3 int **a; <br />
    3.4 int a[10]; <br />
    3.5 int *a[10]; <br />
    3.6 int (*a)[10]; <br />
    3.7 int (*a)(int); <br />
    3.8 int (*a[10])(int); <br />
    
    </details>

4. What are the uses of the keyword **static**

    <details><summary>Click for answer!</summary>

    a. A variable declared static within the body of a function maintains its value between function invocations. <br />
    b. A variable declared static within a module (but outside the body of a function) is accessible by all functions  <br />
       within that module. It is not accessible by function within any other module. That is, it is a localized global. <br />
    c. Functions declared static within a module may only be called by other functions within that module. That is, <br />
       the scope of the function is localized to the module within which it is declared. <br />

    </details>

5. What does the keyword **const** mean?

    <details><summary>Click for answer!</summary>

    const means "read-only" <br />
  
    a. const int a; and int const a; <br /> 
        Mean the same thing, a is a const(read-only) integer. <br />
    b. const int *a; <br />
        a is pointer to a const integer(i.e., the integer isn't modifiable, but the pointer is) <br />
    c. int * const a; <br />
        a is const pointer to an integer(i.e., the integer pointed to by a is modifiable, but the pointer is not) <br />
    d. const int * const a; <br />
        a is const pointer to a const integer(i.e., neither the integer pointed to by a, nor the pointer itself may  <br />
        be modified) <br />

    </details>

6. What does the keyword **volatile** mean?

    <details><summary>Click for answer!</summary>

    A volatile variable is one that can change unexpectedly. Consequently, the compiler can make no assumptions about <br />
    the value of the variable. In particular, the optimizer must be careful to reload the variable every time it is  <br />
    used instead of holding a copy in a register. <br />
  
    a.  Hardware registers in peripherals (e.g., status registers) <br />
    b.  Non-stack variables referenced within an interrupt service routine. <br />
    c.  Variables shared by multiple tasks in a multi-threaded application. <br />
    d.  A variable can be both const and volatile <br />
        Example is a read only status register. It is volatile because it can change unexpectedly. It is const because <br />
        the program should not attempt to modify it. <br />

    </details>

7.  Bit Manipulation  <br />
    7.a Set bit 3 of a  <br />
    7.b Clear bit 3 of a  <br />
    
    <details><summary>Click for answer!</summary>

    #define BIT3 (0x1 << 3) <br />
    7.a <br />
      int set_bit3(int a) <br />
      { <br />
        a |= BIT3; <br />
        return a; <br />
      } <br />
    7.b <br />
      int clear_bit3(int a) <br />
      { <br />
        a &= ~BIT3; <br />
      } <br />

    </details>

8.  What does the following code output and why?   <br />
    void foo (void)   <br />
    {   <br />
          unsigned int a = 6;   <br />
          int b = -20;   <br />
          (a+b) > 6 ? puts(" > 6") : puts(" <= 6");   <br />
    }   <br />
    
    <details><summary>Click for answer!</summary>

    The expression involving signed and unsigned types have all operands promoted to unsigned types. <br />
    Thus -20 becomes a very large positive integer and the expression evaluates to greater than 6. <br />

    </details>

9.  **Typedef** : Which method is preferred and why?   <br />
    #define dPS struct s *   <br />
    typedef struct s * tPS;   <br />
    
    <details><summary>Click for answer!</summary>

    Consider the following declarations: <br />
    
    dPS p1, p2; <br />
    tPS p2, p3; <br />
    
    The first one expands to <br />
    struct s * p1, p2; <br />
    
    which defines p1 to be a pointer to structure and p2 to be an actual structure, which is probably not what we wanted.  <br />
    However, the second one correctly defines p3 & p4 to be pointers to structre s. <br />

    </details>
