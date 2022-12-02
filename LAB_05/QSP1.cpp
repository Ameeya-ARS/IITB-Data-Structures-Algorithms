#include<iostream>
#include<random>
#include<iomanip>
using namespace std;

int comp=0, swap=0;

void quickSort(double arr[],int low,int high){
    int pivot, i, j;
    double temp;
    if(low < high){
        pivot = low;
        i = low;
        j = high;
        while(i<j){
            while(arr[i]<=arr[pivot]&& i<high){
                i++;
            }
            ::comp++;
            while(arr[j]>arr[pivot]){
                j--;
            }
            ::comp++;
            if(i<j){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j]=temp;
                ::swap++;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j]=temp;
        ::swap++;
        quickSort(arr,low,j-1);
        quickSort(arr,j+1,high);
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