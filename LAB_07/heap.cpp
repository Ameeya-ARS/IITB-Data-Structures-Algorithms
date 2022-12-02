#include<iostream>
#include<climits>
#include <stdlib.h>
#include<time.h>
using namespace std;

int ins_swap = 0 , del_swap = 0;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

class Heap
{
	int *harr;
	int capacity;
	int heap_size;
public:
	Heap(int capacity);

	void Heapify(int );

	int parent(int i);

	int left(int i);

	int right(int i);

	int delMin();

	int getMin();

	void insert(int k);
};

Heap::Heap(int cap)
{
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

int Heap::parent(int i){
    return (i-1)/2;
}

int Heap::left(int i){
    return (2*i + 1);
}

int Heap::right(int i){
    return (2*i + 2);
}

void Heap::insert(int k)
{
	if (heap_size == capacity)
	{
		cout << "Heap is already Full" << endl;
		return;
	}

	heap_size++;
	int i = heap_size - 1;
	harr[i] = k;

	while (i != 0 && harr[parent(i)] > harr[i])
	{
	swap(&harr[i], &harr[parent(i)]);
    ::ins_swap++;
	i = parent(i);
	}
}


int Heap::delMin()
{
	if (heap_size <= 0)
		return INT_MAX;
	if (heap_size == 1)
	{
		heap_size--;
		return harr[0];
	}

	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	Heapify(0);

	return root;
}

int Heap::getMin(){
    return harr[0];
}

void Heap::Heapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i])
		smallest = l;
	if (r < heap_size && harr[r] < harr[smallest])
		smallest = r;
	if (smallest != i)
	{
		swap(&harr[i], &harr[smallest]);
        ::del_swap++;
		Heapify(smallest);
	}
}



int main()
{   
    int ins_count = 0, del_count = 0;
    int N = 10000;
	Heap h(1048576);
    // srand(1);
    // for (int i = 0; i < N; i++) {
    //     h.insert(rand());
    // }
    // for (int i=0;i<N/5;i++){
    //     int check = rand()%2;
    //     int num = (rand()%1000000) + N;
    //     if(check==0) {
    //         h.insert(num);
    //         ins_count++;
    //     }
    //     else {
    //         h.delMin();
    //         del_count++;
    //     }
    // }
    // double ins = (::ins_swap*1.0)/ins_count;
    // double del = (::del_swap*1.0)/del_count;
    // cout << ins << endl;
    // cout << del << endl;

	h.insert(5); h.insert(2); h.insert(9);
	h.insert(4); h.insert(8); h.insert(1);
	h.insert(6); h.insert(7); h.insert(3);
	cout << h.getMin() << endl;
	cout << h.delMin() << endl;
	cout << h.getMin() << endl;
	return 0;
}
