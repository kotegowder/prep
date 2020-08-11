Some of the questions for Embedded Programmers

1. Using #define statement, how would you declare a manifest constant that returns the number of seconds in a year? Disregard leap years in your answer.

    <details><summary>Click for answer!</summary>
    <br />
    #define SECONDS_PER_YEAR (365UL * 24UL * 60UL * 60UL)

    </details>

2. Write a 'standard' MIN macro. That is, a macro that takes two arguments and returns the smaller of the two arguments.

    <details><summary>Click for answer!</summary>
    <br />
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
    <br />
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
    <br />
    a. A variable declared static within the body of a function maintains its value between function invocations. <br />
    b. A variable declared static within a module (but outside the body of a function) is accessible by all functions  <br />
       within that module. It is not accessible by function within any other module. That is, it is a localized global. <br />
    c. Functions declared static within a module may only be called by other functions within that module. That is, <br />
       the scope of the function is localized to the module within which it is declared. <br />

    </details>

5. What does the keyword **const** mean?

    <details><summary>Click for answer!</summary>
    <br />
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
    <br />
    A volatile variable is one that can change unexpectedly. Consequently, the compiler can make no assumptions about <br />
    the value of the variable. In particular, the optimizer must be careful to reload the variable every time it is  <br />
    used instead of holding a copy in a register. <br />
  
    a.  Hardware registers in peripherals (e.g., status registers) <br />
    b.  Non-stack variables referenced within an interrupt service routine. <br />
    c.  Variables shared by multiple tasks in a multi-threaded application. <br />
    d.  A variable can be both const and volatile <br />
        Example is a read only status register. It is volatile because it can change unexpectedly. It is const because <br />
        the program should not attempt to modify it. <br />

    Consider the following example code: <br />

    ~~~
    #include <stdlib.h>
    #include <stdio.h>
    #include <pthread.h>

    int global_variable = 0;
    void read_global( void * );
    void write_global( void * );

    int main( void ) {
        pthread_t thread1, thread2;
        pthread_create( &thread1, NULL, (void *) &read_global, NULL );
        pthread_create( &thread2, NULL, (void *) &write_global, NULL );
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);
        printf( "Exiting main...\n" );
        return EXIT_SUCCESS;
    }

    void write_global( void *void_arg ) {
        int i;
        for ( i = 3; i >= 0; --i ) {
            printf( "%d\n", i );
            sleep( 1 );
        }
        global_variable = 1;
        printf( "Exiting writer...\n" );
    }

    void read_global( void * void_arg ) {
        while ( global_variable == 0 ) {
            // Do nothing
        }
        sleep( 1 );
        printf( "Exiting reader...\n" );
    }
    ~~~

    Below is the snippet of assembly part for **read_global** function when built with and without optimization.
    
    ~~~
    Without optimization:                                                       With optimization:

                                                                                    ldr     r3, .L7
                                                                                    ldr     r3, [r3]
    .L2:                                                                        .L2:
        ldr     r3, .L7     // r3 will have address of global_variable              cmp r3, #0
        ldr     r3, [r3]                                                            beq .L2
        cmp     r3, #0
        beq     .L2

    ~~~

    So what happend when optimization is enabled? <br />
    <br />
    Compiler thinks, after all, nothing in the body of while loop in **read_global** funtion is changing the value of the variable, so why check it each time? The problem is, the variable is being changed, but not in this loop. We must give the optimizer a hint that the varibale *golbal_variable* may change elsewhere, and do so by flagging it as **volatile**.
    <br /> <br />
    **volatile** int global_variable = 0;
    
    Now the code executes as expected. 
    
    </details>

7.  Bit Manipulation  <br />
    7.a Set bit 3 of a  <br />
    7.b Clear bit 3 of a  <br />
    
    <details><summary>Click for answer!</summary>
    <br />
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
    <br />
    The expression involving signed and unsigned types have all operands promoted to unsigned types. <br />
    Thus -20 becomes a very large positive integer and the expression evaluates to greater than 6. <br />

    </details>

9.  **Typedef** : Which method is preferred and why?   <br />
    #define dPS struct s *   <br />
    typedef struct s * tPS;   <br />
    
    <details><summary>Click for answer!</summary>
    <br />
    Consider the following declarations: <br />
    
    dPS p1, p2; <br />
    tPS p2, p3; <br />
    
    The first one expands to <br />
    struct s * p1, p2; <br />
    
    which defines p1 to be a pointer to structure and p2 to be an actual structure, which is probably not what we wanted.  <br />
    However, the second one correctly defines p3 & p4 to be pointers to structre s. <br />

    </details>

10. **Wild** pointers?

    <details><summary>Click for answer!</summary>
    <br />    
    Pointers that store addresses of memory that have not yet been initialized are referred to as *wild* pointers. <br />
    
    After memory is allocated, but used before it is initialized properly, the content of that memory is usually random-unknown junk values. <br />
    Consequently, interesting things may or may not occur - especialy on different platforms.
    
    </details>
    
11. **Dangling** pointers?

    <details><summary>Click for answer!</summary>
    <br />    
    Pointers that store addresses of memory that has been freed are referred to as *dangling* pointers.
    
    A reference to an address that has been deallocated has non-deterministic consequences: the operating system may <br />
    - still flag that memory as allocated, so no issues occur,
    - cause the program to crash, or
    - have reallocated that memory to the same task, but it is now being used for a different purpose(most detrimental, as the other data structure can be corrupted).
    
    Avoiding dangling pointers can be solved by always assigning a pointer the value **NULL** after the memory has been freed: <br />
    <br />
        **free(ptr);** <br />
        **ptr = NULL;**

    </details>

12. What happens if same memory being freed multiple times?

    <details><summary>Click for answer!</summary>
    <br />
    One possible consequence of dangling pointer is that they may be freed multiple times. This can have different results: <br />
    - the allocator will cause the program to stop execution.
    - the memory may have since been allocated again, in which case, you would free memory that was not meant to be freed, or
    - *head corruption* -- the heap is in an inconsistent state and operations that manage it will be unpredictable.
    
    <br />
    Again this is a matter that can be resolved by having as few persistent variable storing addresses and ensuring that when <br/>
    a call to **free(...)** is made, all of those variables must be set to *NULL*.
    
    </details>
    
13. What is **memory leak** ?

    <details><summary>Click for answer!</summary>
    <br />    
    Memory that is allocated but not appropriately deallocated when it is no longer needed; that is, a *memory leak*.
    
    The primary cause of a memory leak is when the last reference to memory is lost by the application. In C and C++ this may happen in one of two ways:
    - The last pointer assigned the memory location is a local variable that then goes out of scope (often when a fuction returns), or
    - The last pointer (local, member or global) assigned the memory location is overwritten.
    <br />
    
    In either case, because the last value storing the address is lost, it is now impossible to call *free(...)* or *delete ...*  to indicate the operating system that the memory is no longer required. Consequently, as long as the application is running, the operating system will simply assume that the memory is being used by the application.
    
    Memory leak can be more serious than one in an application being run:
    - in an embedded system when memory is more limited as compared to what one would expect from a desktop or laptop system,
    - in an embedded system that is meant to execute for an extended period of time (even years),
    - when memory may be shared by multiple processes and where the termination of one of these processes does not necessarily cause the memory to be collected, and 
    - in a device driver
    
    </details>
    
14. How to Detect, Debug and Prevent Stack-overflow ?

    <details><summary>Click for answer!</summary>
    <br />    
    
    The below article assumes person reading will have prior understading of stack implementation - which include local variables, their memory allocation and how stack works.
    
    **Stackoverflow** <br />
    Let's consider we have stack of 1024 bytes allocated in our project.
    
    Now let's consider an example <br />
    <br />
    void foo(void) {<br />
        int x[1024] = {0};<br />
        int y = 10;<br />
        int z = 5;<br />
        :<br />
        :<br />
    }<br />

    When function *foo* is called, variable x is allocated onto stack which consumes 1024 bytes. Assuming working with single stack, there is already stack corruption happened as before entering the function stack *PUSH* has happened and tehe subsequent varaible allocation (y and z) goes onto overwrite the adjacent memory regions. Which is formally referred to as *Stackoverflow*.
    <br />
    
    **Stackoverflow detection**
    1.  *Using debugger* <br />
        <br />
        Debuggers allow us to set breakpoints based on register value. Whenever stack pointer register hits the lower bound of stack address, debugger stops and we can get to know that the stack is filled up at some point of code execution. Then if you step over, in very few steps you will probably run into the run-time error which confirms the stack overflow condition. 
        <br />
        So once you are sure the problem is on stack allocation, just double the stack size and see if that fixes-up the issue. If not, that means your bug is someplace else in your code!.

    2.  *Using an MMU or MPU* <br />
        <br />
        If processor supports Memory Management Unit(MMU) or a Memory Protection Unit (MPU), then these special hardware devices integrated alongside the CPU can be configured to detect when a task attempts to access invalid memory locations, whether code, data, or stack.

    3.  *Using a CPU with stack overflow detection* <br />
        <br />
        Some processors, however, do have simple stack pointer overflow detection registers. When the CPU's stack pointer goes below the value set in this register, an exception is generated and the exception handler ensures that the offending code does not do further damage (possibly issue a warning about the faulty code). It's the OS which takes care of CPU's stack overflow detection register is written with a proper value for a given task/thread during context switches.

    4.  *Software-based stack overflow detection* <br />
        <br />
        Whenever OS switches from one task to another, it calls a *hook* function which allows programmer to extend the capabilities of the context switch function. 
        <br />
        Before a task is *switched* in, the *hook* code should ensure that the stack pointer to load into the CPU does not the exceed the *limit* value present task TCB.

    5.  *Counting the amount of free stack space* <br />
        <br />
        Another way to check for stack overflows is to allocate more stack space than is anticipated to be used for the stack, then, monitor and possibly display actual maximum stack usage at run-time. <br />
        <br />
        First, the task stack needs to be cleared (i.e., filled with zeros) when the task is created. Next, a low priority task *walks the stack* of each task created, from the bottom towards the top, counting the number of zeros entries. When the task finds a non-zero value, the process is stopeed and the usage of the stack can be computed (in number of bytes used or as a percentage). Then, adjust the size of the stacks (by recompiling the code) to allocate a more *reasonable* value (either increase or decrease the amount of stack space for each task). For this to be effective, however, run the application long enough for the stack to grow to its highest value.
        <br />

    **Best Practices to avoid stack overflows**
    1.  *Don't allocate arrays on the stack* <br />
        <br />
        It's always a good idea to not declare arrays on the stack.<br />
        If you need to limit the access to an array to only with a function, then declare it as local static then the compiler will allocate the array outside the stack.

    2.  *Pass pointers instead of big structures to functions*<br />
        <br />
        If a structure contains a big array member and if passed directly to a function, the program will certainly crash as a copy of the entire struct will be made and this copy will be sent to the function and the function will try to allocate this copy on the stack.
        <br />
        Instead, it's a better idea to pass it as a pointer. However care should be taken if values should not be changed inside a function by using *const* qualifier.

    3.  *Avoid recursive functions*<br />
        <br />
        Recursive functions are functions that all themselves.<br />
        A recursive function with large local array variable, when called itself multiple times may result in stack overflow.

    4.  *What not keep all varibale global?* <br />
        <br />
        -   **Pushing and Popping data in and out of stack can help reduce the RAM usage as compared to keeping everything global**. When RAM consuption goes up with a function call, the function return would bring back RAM consumption back to the original value as it was before function call.
        -   If everything is kept global, it will **pollute the namespace** as each global variable name should be unique.
        
    </details>

15. What is buffer overflow?

    <details><summary>Click for answer!</summary>
    <br />
    
    Very similar to stack overflow, where one writes to an array pass its end.

    </details>
    
16. **Cache**

    <details><summary>Click for answer!</summary>
    <br />
    
    ~~~
    Very high speed memory that supplies the most recently used instructions and/or data to the CPU with few if any wait states. 
    
    There are three different categories, graded in levels: L1, L2 and L3. L2 cache is generally built into the processor chip 
    and is the smallest in size.
    However, it is also the fastest type of memory for the CPU to read. Multi-core CPUs will generally have a seperate L1 cache
    for each core.

    L2 and L3 caches are larger than L1, but take longer to access. 

    Cache memory generally tends to operate in a number of different configurations:
    - direct mapping
    - fully associative mapping
    - set associative mapping
    
    ~~~

    </details>

