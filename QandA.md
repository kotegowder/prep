Some of the questions for Embedded Programmers

1. Using #define statement, how would you declare a manifest constant that returns the number of seconds in a year? Disregard leap years in your answer.

    <details>
    <summary>Click for answer!</summary>

    #define SECONDS_PER_YEAR (365UL * 24UL * 60UL * 60UL)

    </details>

2. Write a 'standard' MIN macro. That is, a macro that takes two arguments and returns the smaller of the two arguments.

    <details>
    <summary>Click for answer!</summary>

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
    <details>
    <summary>Click for answer!</summary>

    3.1 int a;
    3.2 int *a;
    3.3 int **a;
    3.4 int a[10];
    3.5 int *a[10];
    3.6 int (*a)[10];
    3.7 int (*a)(int);
    3.8 int (*a[10])(int);
    
    </details>

4. What are the uses of the keyword **static**

    <details>
    <summary>Click for answer!</summary>

    a. A variable declared static within the body of a function maintains its value between function invocations.
    b. A variable declared static within a module (but outside the body of a function) is accessible by all functions 
       within that module. It is not accessible by function within any other module. That is, it is a localized global.
    c. Functions declared static within a module may only be called by other functions within that module. That is,
       the scope of the function is localized to the module within which it is declared.

    </details>

5. What does the keyword **const** mean?

    <details>
    <summary>Click for answer!</summary>

    const means "read-only"
  
    a. const int a; and int const a; 
        Mean the same thing, a is a const(read-only) integer.
    b. const int *a;
        a is pointer to a const integer(i.e., the integer isn't modifiable, but the pointer is)
    c. int * const a;
        a is const pointer to an integer(i.e., the integer pointed to by a is modifiable, but the pointer is not)
    d. const int * const a;
        a is const pointer to a const integer(i.e., neither the integer pointed to by a, nor the pointer itself may 
        be modified)

    </details>

6. What does the keyword **volatile** mean?

    <details>
    <summary>Click for answer!</summary>

    A volatile variable is one that can change unexpectedly. Consequently, the compiler can make no assumptions about
    the value of the variable. In particular, the optimizer must be careful to reload the variable every time it is 
    used instead of holding a copy in a register.
  
    a.  Hardware registers in peripherals (e.g., status registers)
    b.  Non-stack variables referenced within an interrupt service routine.
    c.  Variables shared by multiple tasks in a multi-threaded application.
    d.  A variable can be both const and volatile
        Example is a read only status register. It is volatile because it can change unexpectedly. It is const because
        the program should not attempt to modify it.

    </details>

7.  Bit Manipulation  <br />
    7.a Set bit 3 of a  <br />
    7.b Clear bit 3 of a  <br />
    
    <details>
    <summary>Click for answer!</summary>

    #define BIT3 (0x1 << 3)
    7.a
      int set_bit3(int a)
      {
        a |= BIT3;
        return a;
      }
    7.b
      int clear_bit3(int a)
      {
        a &= ~BIT3;
      }

    </details>

8.  What does the following code output and why?   <br />
    void foo (void)   <br />
    {   <br />
          unsigned int a = 6;   <br />
          int b = -20;   <br />
          (a+b) > 6 ? puts(" > 6") : puts(" <= 6");   <br />
    }   <br />
    
    <details>
    <summary>Click for answer!</summary>

    The expression involving signed and unsigned types have all operands promoted to unsigned types.
    Thus -20 becomes a very large positive integer and the expression evaluates to greater than 6.

    </details>

9.  **Typedef** : Which method is preferred and why?   <br />
    #define dPS struct s *   <br />
    typedef struct s * tPS;   <br />
    
    <details>
    <summary>Click for answer!</summary>

    Consider the following declarations:
    
    dPS p1, p2;
    tPS p2, p3;
    
    The first one expands to
    struct s * p1, p2;
    
    which defines p1 to be a pointer to structure and p2 to be an actual structure, which is probably
    not what we wanted. 
    However, the second one correctly defines p3 & p4 to be pointers to structre s.

    </details>
