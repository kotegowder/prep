Some of the questions for Embedded Programmers

1. Using #define statement, how would you declare a manifest constant that returns the number of seconds in a year? Disregard leap years in your answer.

~~~
  #define SECONDS_PER_YEAR (365UL * 24UL * 60UL * 60UL)
~~~

2. Write a 'standard' MIN macro. That is, a macro that takes two arguments and returns the smaller of the two arguments.

~~~
  #define MIN(A, B) ((A) < (B) ? (A) : (B))
~~~

3. Using the variable a, write down definitions for the following: <br />
        3.1 An integer <br />
        3.2 A pointer to an integer <br />
        3.3 A pointer to a pointer to an integer <br />
        3.4 An array of ten integers <br />
        3.5 An array of ten pointers to integers <br />
        3.6 A pointer to an array of ten integers <br />
        3.7 A pointer to a funtion that takes an integer argument and return an integer <br />
        3.8 An array of ten pointers to functions that take an integer argument and return an integer <br />
~~~
  3.1 int a;
  3.2 int *a;
  3.3 int **a;
  3.4 int a[10];
  3.5 int *a[10];
  3.6 int (*a)[10];
  3.7 int (*a)(int);
  3.8 int (*a[10])(int);
~~~
   
