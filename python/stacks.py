#   Stack
#
#   An ADT that stores items in the order in which they were added
#
#   Items are added to and removed from the "top" of a stack
#
#   It works with the principle of "last-in first-out (LIFO)"
#
#   What built-in Python data type is mutable and stores and ordered collection of items?
#       A list.
#
#   Basic Stack Operations
#       Add to the stack
#       Remove from the stack
#       Is the stack empty?
#       How many items are in stack?
#       What is next to be removed?
#
#   Bottom                       Top
#          ---------------------
#          | 0 | 1 | 2 | 3 | 4 |
#          ---------------------
#   Left                         Right
#
#       append() and pop() in O(1) time
#
#   Stack Data
#       Any data type that can be stored in a list can be stored in a stack
#       Limited access because we can only access the data from one place
#
#   Real-World Examples
#       A linter in a text editor can detect missing symbols
#       Reversing the characters in a string
#

class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        """
        Accepts an item as parameter and appends it to the end of the list and returns nothing.
        The runtime of this method is O(1).
        """
        self.items.append(item)

    def pop(self):
        """
        Removes and returns the last item from the list.
        The runtime is O(1).
        """
        if self.items:
            return self.items.pop()
        return None

    def peek(self):
        """
        Returns the last item from the list.
        The runtime is O(1).
        """
        if self.items:
            return self.items[-1]
        return None
    
    def size(self):
        """
        Returns the length of stack list.
        O(1)
        """
        return len(self.items)

    def is_empty(self):
        """
        Returns boolean value whether or not stack is empty.
        O(1).
        """
        return (self.size() == 0)

# Test    
myStack = Stack()
print(myStack.pop())
print(myStack.peek())
print(myStack.size())
print(myStack.is_empty())
myStack.push("Apple")
print(myStack.items)
myStack.push("Banana")
print(myStack.items)
print(myStack.pop())
print(myStack.items)
print(myStack.peek())
print(myStack.items)
print(myStack.size())
print(myStack.is_empty())

# Problem statement
#   Create a function that takes in a string of symbols pairs as a parameter
#   The function should return True if the symbol string is balanced or False if it is not.
#   Requirements
#       The string should only contain opening and closing symbols, like '([{}])' or '(([{])'
#       For symbols to be balanced, each opening symbol must also have a closing symbol, and the symbols must be properly nested.
#       Make use of a stack in your solution.
#   Examples
#   Balanced symbols
#       ([{}])
#       ([]{}())
#       (((())))
#   Unbalanced symbols
#       (([{])
#       [}([){]

def matchSymbols(symbol_str):
    symbol_pairs = {
        '(' : ')',
        '[' : ']',
        '{' : '}',
    }

    openers = symbol_pairs.keys()
    myStack = Stack()

    idx = 0
    while idx < len(symbol_str):
        symbol = symbol_str[idx]

        if symbol in openers:
            myStack.push(symbol)
        else:
            # if the stack is empty, the symbols are unbalanced
            if myStack.is_empty():
                return False
            # If there are still items in Stack, check for mis-match
            else:
                top_item = myStack.pop()
                if symbol != symbol_pairs[top_item]:
                    return False
        idx += 1
    
    if myStack.is_empty():
        return True

    # Stack is not empty so symbols were not balanced
    return False

print("Matching symbols test")
print(matchSymbols("([{}])"))
print(matchSymbols("([]{}())"))
print(matchSymbols("[}([){]"))