#include <iostream>

using namespace std;
int Lf=1,Rf=1;

void Right(int* arr, int low, int high);


void Left(int* arr, int low, int high) {
    for (int i = low; i < high; i++) {
        if (arr[high] < arr[i]) {
            arr[high] = arr[high] + arr[i];
            arr[i] = arr[high] - arr[i];
            arr[high] = arr[high] - arr[i];
            low = i;
            
            break;
       
        }
          Lf=0;
    }
 if(Lf || Rf)
        Right(arr, low, high);
cout<<"left \n";
    
    
}

void Right(int* arr, int low, int high) {
    for (int i = high; i > low; i--) {
        if (arr[low] > arr[i]) {
            arr[low] = arr[low] + arr[i];
            arr[i] = arr[low] - arr[i];
            arr[low] = arr[low] - arr[i];
            high = i;
        
            break;
           
        }
         Rf=0;
    }
if(Lf || Rf)
        Left(arr, low, high);
cout<<" Right \n";
    
}

int main() {
    int arr[] = {
        53, 17, 92, 34, 78, 25, 61, 9,  47, 56,
        88, 41, 2,  73, 14, 68, 37, 98, 12, 29,
        64, 5,  83, 20, 50, 72, 30, 69, 42, 7,
        90, 38, 80, 49, 3,  60, 26, 81, 59, 21,
        76, 45, 87, 1,  66, 96, 13, 52, 85, 32,
        91, 11, 77, 28, 74, 8,  48, 65, 19, 70,
        35, 54, 86, 22, 67, 4,  99, 10, 58, 31,
        75, 44, 89, 6,  63, 15, 57, 33, 84, 18,
        71, 36, 55, 27, 79, 43, 94, 23, 62, 16,
        82, 24, 51, 95, 40, 46, 97, 39, 19, 0
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
     if(arr[i]>arr[i+1]){
         Lf=Rf=1;//reseting the flags
          Right(arr, i, n - 1);
          i=0;
     }
    }
   
   
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
