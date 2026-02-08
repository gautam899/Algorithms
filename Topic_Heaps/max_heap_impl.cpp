#include<iostream>
#include<vector>
#include<climits>

template<typename T>
class MaxHeap {
    private:
        vector<T> array;
	int size; // Number of elements currently in heap.
	int capacity;
    public:
	// Constructor to initialize the heap with a given capacity
	MaxHeap(int capacity){
	    this->size = 0;
	    this->capacity = capacity;
	    this->array.resize(capacity);
	}

	// Function to heapify the node at index i.
	void heapify(int index){
	    int largest = index;
	    int left = 2*index+1; // the left child
	    int right = 2*index+2;
	    // Compare the index with it's left and right child, swap if any of them is greater.

	    // If the left child is greater than parent
	    if(left<size && array[left] > array[index]){
	    	largest = left;
	    }
	    // If the right child is greater than parent 
	    if(right<size && array[right] > array[largest]){
	    	largest = right;
	    }
	    if(largest != index){
	    	swap(array[index], array[largest];
		heapify(largest);
	    }
	}

	void buildHeap(const vector<T>& arr) {
	    // This is the first time when we pass a un-heapified array to build heap function from the main.
	    capacity = arr.size();
	    size = capacity;
	    array = arr;
	    // Instead of starting from the last node we start from size-1 / 2th element.
	    for(int i=(size-1)/2;i>=0;i--){
	    	heapify(i); // heapify works downwards.
	    }
	}
	void insert(T value){
	    if(size == capacity){
	        capacity *= 2;
		array.resize(capacity);
	    }

	    size++;
	    int i = size-1;
	    array[i] = value;

	    // Fix the max heap property if is voilated.
	    while(i!=0 && array[(i-1)/2]<arrary[i]) {
	        swap(array[i], array[(i-1)/2]); // i-1 is the parent of the current element
		i = (i-1)/2;
	    } 
	} 
	T top() {
	    if(size<=0){
	    	return -1;
	    }
	    return array[0];
	}
	
	T pop() {
	    // If size < 0
	    if(size<=0)return -1;
 	    if(size == 1){
	    	size--;
		return array[0];
	    }	    
	    
	    T root = array[0];
	    array[0] = array[size-1]; // Replace the root element with the last element of the array.
	    size--;
	    heapify(0);
	    return root;
	}

	void deleteKey(T key){
	    int index = -1;
	    for(int i=0;i<size;i++){
	    	if(array[i] = key){
		    index = i;
		    break;
		}
	    }

	    // If key is not found
	    if(index==-1){
	    	std::cout<<"Key not found: "<<endl;
		return;
	    }

	    array[index] = array[size-1]; // Replace the index to be deleted with the last element of the array.
	    size--; // reduce the size.
	    // heapify the subtree starting from the index.
	    heapify(index);
	}

	void print const {
	    std::cout << "Max Heap: ";
	    for(int i=0;i<size;i++){
	    	cout<<array[i]<<" ";
	    }
	    cout<<endl;
	}
}

int main() {
    MaxHeap<int> maxHeap(6);
    vector<int> arr = {2,3,4,5,10,15};
    maxHeap.buildHeap(arr);
    maxHeap.print();
}
