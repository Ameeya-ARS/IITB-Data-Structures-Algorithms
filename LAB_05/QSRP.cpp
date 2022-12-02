#include <cstdlib>
#include <iostream>
#include <ctime>
#include<random>
#include<iomanip>
using namespace std;

int comp=0, swap=0;

int partition(double arr[], int low, int high)
{   
    double temp;
	double pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot) {
			i++;
			temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            ::swap++;
		}
        ::comp++;
	}
    temp = arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    ::swap++;
	return (i + 1);
}

int partition_r(double arr[], int low, int high)
{
    double temp;
	srand(time(NULL));
	int random = low + rand() % (high - low);
    temp = arr[random];
    arr[random] = arr[high];
    arr[high]=temp;
    ::swap++;
	return partition(arr, low, high);
}

void quickSort(double arr[], int low, int high)
{
	if (low < high) {
		int p = partition_r(arr, low, high);
		quickSort(arr, low, p-1);
		quickSort(arr, p+1, high);
	}
}

constexpr int MIN = 10;
constexpr int MAX = 1000;
int main(){
    int N = 10;
    double arr[N];
    srand(time(nullptr));
    for(int i=0;i<N;i++){
        arr[i] =  MIN + (double)(rand()) / ((double)(RAND_MAX/(MAX - MIN)));
    }
    quickSort(arr, 0, N-1);
    cout << ::comp << "  " << ::swap;
    return 0;
}
