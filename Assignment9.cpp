#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#define ARRAYSIZE 100

//Implement the data structure here
class Stack
{
    int stackArray[ARRAYSIZE]; // stack array to store elements
    int top; // top variable to keep track
public:
    
    // constructor 
    Stack()
    {
        top = 0; 
    }
    
    // determine if stack is empty or not
    bool stackEmpty()
    {
        if (top == 0){
            return true;
        } else {
            return false;
        }
    }
    // function push to put in elements in to the stack
    void push(int element)
    {
        // overflows
        if (top == ARRAYSIZE){
            return; 
        } else {
            stackArray[top] = element;
            top++; 
        }
    }
    
    // function pop to take away the last element added in the stack
    int pop() {
        // underflows 
        if (stackEmpty()) {
            return -1;
        } else {
            top--; 
            return stackArray[top + 1]; 
        }
    }
    
    // function to check if the top is empty
    int check() {
        return stackArray[top - 1];
    }
    // print 
    void printStack() {
        for (int i = 0; i < top; i++) {
            printf("%d\n", stackArray[i]);
        }
    }
    
};

int main(int argc, const char * argv[]) {
    
    // declaring class instance
    Stack myStack;

    //Ask for the number of HR operations and read
    int numberOfHROperations;
    printf("Enter the number of HR operations:\n");
    scanf("%d", &numberOfHROperations);
    
    //Ask for the operations and IDs
    printf("Input the operations and IDs:\n");
    
    std::vector<char> operations;
    std::vector<int> ids;
    
    //Read the operations and IDs from stdin
    for (int i = 0; i < numberOfHROperations; i++){
        char operation;
        int id;
        scanf(" %c%d", &operation, &id);
        operations.push_back(operation);
        ids.push_back(id);
    }
    
    //Solve the question
    for (int i = 0; i < numberOfHROperations; i++) {
        if (operations[i] == '+') {
        // only pushing ids when its '+'
        myStack.push(ids[i]); 
        } else {
            int laidOff = ids[i];
            if (laidOff != myStack.check()) {
                printf("FAIL\n");
                return 0;
            } 
            // pop when it is not push
            else {
                myStack.pop();
            }
                
        }
    }
    
    printf("PASS\n");
    return 0;
}
