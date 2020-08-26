#   Queue
#   
#   An ADT that stores items in the order in which they were added.
#
#   Items in a queue are added to the back and removed from the front.
#
#   The queue ADT is like a line of people waiting.
#
#   People join the line at the back and leave the line from the front(first-in first-out or FIFO).
#   The order in which people join the line is preserved.
#
#   What built-in Python data type is mutable and stores an ordered collection of items?
#       A list
#
#   Back                       Front
#        ---------------------
#        | 0 | 1 | 2 | 3 | 4 |
#        ---------------------
#   Left                       Right
#
#   insert(0) in O(n) time      pop() in O(1) time
#
#   Basic Queue Operations
#       Add to the queue (enqueue)
#       Remove fron the queue (dequeue)
#       Is the queue empty?
#       How many items are in the queue?
#       What is next to be removed?
#
#   Any data type that can be stored in a list can be stored in a queue
#   Limited access, because we can only access the data from one place.
#
#   Real-World Example
#       A print queue, so that documents are printed in the order in which they were sent to the machine.
#       

class Queue:

    def __init__(self):
        self.items = []

    def enqueue(self, item):
        """
        Inserts the item at 0th index of the queue list.
        Runtime is O(n), because inserting into the 0th index of queue list forces all the other items in the list to move one index to the right.
        """
        self.items.insert(0, item)

    def dequeue(self):
        """
        Remove and returns the last item from queue list.
        Runtime - O(1).
        """
        if self.items:
            return self.items.pop()
        return None
    
    def peek(self):
        """
        Returns the last item from queue list
        O(1)
        """
        if self.items:
            return self.items[-1]
        return None
    
    def size(self):
        """
        Returns the length of Queue list.
        O(1).
        """
        return len(self.items)

    def is_empty(self):
        """
        Returns boolean value whether or not Queue is empty.
        O(1).
        """        
        return (self.size() == 0)

# Test
myQueue = Queue()
print(myQueue.dequeue())
print(myQueue.peek())
print(myQueue.size())
print(myQueue.is_empty())
myQueue.enqueue("Apple")
print(myQueue.items)
myQueue.enqueue("Banana")
print(myQueue.items)
print(myQueue.dequeue())
print(myQueue.items)
print(myQueue.peek())
print(myQueue.items)
print(myQueue.size())
print(myQueue.is_empty())

# Problem statement
#
#   Create 2 classes that, together, model how a printer could take print jobs out of a print queue.
#
#   Requirements:
#       PrintQueue class that follows the queue data structure implementation.
#       Job class 
#           pages attribute - random, 1 to 10
#           print_page() - decrement pages
#           check_complete() 
#       Printer class
#           get_job() - account for the case where PrintQueue.items is empty.
#           print_job()

import random

class PrintQueue:
    def __init__(self):
        self.items = []
    
    def enqueue(self, item):
        self.items.insert(0, item)

    def dequeue(self):
        if self.items:
            return self.items.pop()
        return None

    def is_empty(self):
        return self.items == []

class Job:
    def __init__(self):
        self.pages = random.randint(1, 11)
    
    def print_pages(self):
        if self.pages > 0:
            self.pages -= 1

    def check_complete(self):
        return self.pages == 0

class Printer:

    def __init__(self):
        self.current_job = None

    def get_job(self, print_queue):
        try:
            self.current_job = print_queue.dequeue()
        except IndexError: # Queue is empty
            return "No more jobs to print"

    def print_job(self, job):
        while job.pages > 0:
            job.print_pages()
        
        if job.check_complete():
            print("Printing complete")
        else:
            print("An error occurred")


print("Test Printer Queue")
job1 = Job()
printQueue = PrintQueue()
printer = Printer()

printQueue.enqueue(job1)
print(printQueue.items)
printer.get_job(printQueue)
print(printQueue.items)
printer.print_job(printer.current_job)