#include <iostream>
#include <string>
using namespace std;

class HIWorld {
public:
    string StateName;
    float IndexHappy;

    HIWorld(string name = "", float happy = 0.0) {
        StateName = name;
        IndexHappy = happy;
    }
};

class Stack {
private:
    HIWorld stack[5];
    int top;

public:
    Stack() : top(-1) {}

    void display();
    void push(HIWorld state);
    void pop();
    HIWorld stackTop();
    HIWorld getBottom();
};

void Stack::display() {
    // Task 1: Complete this function to display all states in the stack.
    if (top == -1) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "States in the stack:" << endl;
        for (int i = top; i >= 0; --i) {
            cout << "State: " << stack[i].StateName << ", Happiness Index: " << stack[i].IndexHappy << endl;
        }
    }
}

void Stack::push(HIWorld state) {
    // Task 2: Complete this function to push a new state onto the stack.
    if (top < 4) {
        top++;
        stack[top] = state;
        cout << "Pushed " << state.StateName << " onto the stack." << endl;
    } else {
        cout << "Stack is full. Cannot push more states!" << endl;
    }
}

void Stack::pop() {
    // Task 3: Complete this function to pop the top state off the stack.
    if (top == -1) {
        cout << "Stack is empty! Cannot pop." << endl;
    } else {
        cout << "Popped " << stack[top].StateName << " from the stack." << endl;
        top--;
    }
}

HIWorld Stack::stackTop() {
    // Task 4: Complete this function to return the state at the top.
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return HIWorld();
    }
    return stack[top];
}

HIWorld Stack::getBottom() {
    // Task 5: Return the state at the bottom of the stack.
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return HIWorld();
    }
    return stack[0];  // Bottom is always the first element in the stack
}

int main() {
    Stack stack;

    // Initializing 3 states
    HIWorld s1("California", 7.5);
    HIWorld s2("Texas", 6.8);
    HIWorld s3("Florida", 7.1);

    // Tasks to be implemented
    cout << "Pushing 3 states onto the stack:" << endl;
    stack.push(s1);
    stack.push(s2);
    stack.push(s3);

    cout << "\nDisplaying all states in the stack:" << endl;
    stack.display();

    cout << "\nDisplaying the top state:" << endl;
    HIWorld topState = stack.stackTop();
    cout << "Top State: " << topState.StateName << ", Index: " << topState.IndexHappy << endl;

    cout << "\nPopping the top state:" << endl;
    stack.pop();
    stack.display();

    cout << "\nDisplaying the top and bottom-most states:" << endl;
    HIWorld bottomState = stack.getBottom();
    topState = stack.stackTop();
    cout << "Top State: " << topState.StateName << ", Index: " << topState.IndexHappy << endl;
    cout << "Bottom State: " << bottomState.StateName << ", Index: " << bottomState.IndexHappy << endl;

    return 0;
}
