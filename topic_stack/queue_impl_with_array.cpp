/* Possible operations in a queue
 * 1. enqueue
 * 2. dequeue
 * 3. getfront
 * 4. isEmpty
 * 5. isFull
 */
#include<iostream>
#include<vector>

class myQueue {

  private:
    std::vector<int> array;
    int capacity;
    int rear;
    int front;
  public:
    myQueue(int n) {
        // Define Data Structures
        this->capacity = n;
        this->rear = -1;
        this->front = -1;
        this->array.resize(n);
    }

    bool isEmpty() {
        // check if the queue is empty
        if((rear == -1 && front == -1) || (front > rear)) return true;
        return false;
    }

    bool isFull() {
        // check if the queue is full
        if(front == 0 && rear == capacity-1)return true;
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull())return;
        array[++rear] = x;
        if(rear == 0){ front = 0;} // If this is the first element we are inserting
        // in the queue make sure front points to the 0th index.

    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty())return;
        front++;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty())return -1;
        return array[front];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty())return -1;
        return array[rear];
    }
};
