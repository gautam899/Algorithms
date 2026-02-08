#include<iostream>
#include<vector>
class myStack {
  private:
    std::vector<int> array;
    int size;
    int capacity;
  public:
    myStack(int n) {
        // Define Data Structures
        this->size = -1;
        this->capacity = n;
        this->array.resize(n);
    }

    bool isEmpty() {
        // check if the stack is empty
        return (size == -1) ? true : false;
    }

    bool isFull() {
        // check if the stack is full
        return (size == capacity-1) ? true : false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(isFull()) return;
        array[++size] = x;
    }

    void pop() {
        // removes an element from the top of the stack
        if(isEmpty()) return;
        size--;
    }

    int peek() {
        if(isEmpty())return -1;
        // Returns the top element of the stack
        return array[size];
    }
};

int main() {
    myStack stack(10);
    std::cout << stack.isEmpty() << std::endl;
    stack.push(1);
    stack.push(2);
    int top_element = stack.peek();
    std::cout << top_element << std::endl;
    return 0; 
    
}
