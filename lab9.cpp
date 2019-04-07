#include<iostream>
using namespace std;

class BinaryHeap{
    public:
    // Pointer to array of elements
    int * hArr;
    // Maximum  size of array
    int mSize;
    // Current size of array 
    int cSize;

    BinaryHeap(int mSize){
        // Constructor 
        hArr = new int[mSize];
        this->mSize = mSize;
        cSize = 0;
    }

    void swap(int *a, int *b){
        // Swap elements ... 
        int temp = *a; 
        *a = *b; 
        *b = temp;
    }

    int parent(int i){ return (i-1)/2;}
    int left(int i){ return (i*2)+1;}
    int right(int i){ return (i*2)+2;}

    int getMin(){ return hArr[0]; }

    void insert(int value){
        // Base case. for Heap Overflow
	if(cSize == mSize){
		cout<<"Can't insert more elements\n";
	}
        // Insert the new key at the end.
        else{
        	hArr[cSize] = value;	
		//Check it for all hierarchy with loop
		int i = cSize;
			//Check if it breaks the heap property and fix it. 
		while (i != 0 && hArr[parent(i)]>hArr[i]){
			swap(&hArr[parent(i)],&hArr[i]);
			i = parent(i);
		}
		cSize++;
	}
    }
    void display(){
        // Display the array
        cout<<"The array you made is :\n";
        for(int i = 0;i < cSize; i++){
        	cout<<hArr[i]<<",";
        }
        cout<<endl;
    }
    int extractMin(){
    	return extractMin(0);
    }	
    int extractMin(int index) 
    { 
        //for Empty Heap
        if(cSize == 0){
        	cout<<"No sufficient elements\n";
        	return 0;
        }
        //for Heap with 1 value.
        if(cSize == 1){
        	cSize = 0;
        }
	else{
        //Copy the last element to the root. 
        swap(&hArr[index],&hArr[cSize-1]);
        cSize--;
        
        //Call Heapify on root. 
	MinHeapify(index);
        // Return the min (Store it, before you replace the root with the last element)
        return hArr[index];
        }
    }

    void decreaseKey(int i, int new_val) { 
        if(i<cSize){
        	if(new_val<hArr[i]){
        		hArr[i] = new_val;
       
			while (i != 0 && hArr[i]<hArr[parent(i)]){
				swap(&hArr[i],&hArr[parent(i)]);
				i = parent(i);
			}	  
        	}
        }
        else{
        	cout<<"Not possible\n";
        }

    } 
    // Deletes the element indexed at i. 
    void deleteKeyAt(int i) 
    { 
        decreaseKey(i,hArr[cSize-1]);
        // Call ExtractMin
        extractMin(i);
        
    }

    void MinHeapify(int i) 
    { 
    	int smallest;
        // Compare with left and right
        if(left(i),right(i)< cSize){
		if(hArr[left(i)] < hArr[i]){
			smallest = left(i);
		}
		if(hArr[right(i)] < hArr[smallest]){
			smallest = right(i);
		}
		// Replace with the smallest.
		if(smallest != i){
			swap(&hArr[smallest],&hArr[i]);
			// Call MinHeapify at the replaced child. 
			MinHeapify(smallest);
		}
        }
        else return;      
    } 

};


int main(){
    BinaryHeap BH1(20);
    int n;
    for(int i = 10; i >0 ; i--){
        BH1.insert(i);
       }
     BH1.display();
     cout<<endl;
    cout<<"The new root is "<<BH1.extractMin()<<endl;
    BH1.display();
    cout<<"At which position the value has to be deleted :";cin>>n;
    BH1.deleteKeyAt(n);
    BH1.display();
    cout << endl;
    
}
