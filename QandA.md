Some of the questions for Embedded Programmers

1. Using #define statement, how would you declare a manifest constant that returns the number of seconds in a year? Disregard leap years in your answer.

~~~
#define SECONDS_PER_YEAR (365UL * 24UL * 60UL * 60UL)
~~~

2. Write a 'standard' MIN macro. That is, a macro that takes two arguments and returns the smaller of the two arguments.

~~~
#define MIN(A, B) ((A) < (B) ? (A) : (B))
~~~
