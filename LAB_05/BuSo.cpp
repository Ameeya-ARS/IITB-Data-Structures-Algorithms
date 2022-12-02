# include<iostream>
# include<random>
# include <iomanip>
using namespace std;

int comp=0, swap=0;

void bubbleSort(double arr[], int n){
    double temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                ::swap++;
            }
            ::comp++;
        }
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
        cout << arr[i] <<" ";
    }
    bubbleSort(arr, N);
    cout << endl;
    for(int i=0;i<N;i++){
        cout << arr[i] << " ";
    }
    return 0;
}