// Write aprogram to perform binary search no an unsorted random list of at least 50 elements. The key element should be user input. Use the Divide &Conquer method ot implement this program.


#include<iostream>
#include<vector>
#include<random>
using namespace std;

void merge(int array[], int const left, 
           int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    int *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];

    for (int i = 0; i < subArrayTwo; i++)
        rightArray[i] = array[mid + 1 + i];

    int indexOfSubArrayOne = 0, 
         indexOfSubArrayTwo = 0; 
 

    int indexOfMergedArray = left; 

    while (indexOfSubArrayOne < subArrayOne && 
           indexOfSubArrayTwo < subArrayTwo) 
    {
        if (leftArray[indexOfSubArrayOne] <= 
            rightArray[indexOfSubArrayTwo]) 
        {
            array[indexOfMergedArray] = 
            leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = 
            rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
     
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) 
    {
        array[indexOfMergedArray] = 
        leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) 
    {
        array[indexOfMergedArray] = 
        rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}
 
void mergeSort(int array[], 
               int const begin, 
               int const end)
{
    // Returns recursively
    if (begin >= end)
        return; 
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void binarysearch(int a, int arr[], bool &check, int &loc){
    int start = 0;
    int end = 4999;
    while(start <= end){
        int mid = start + (end- start)/2;
        if(a == arr[mid]){
            check = true;
            loc = mid;
            break;
        }
        else if(a < arr[mid]){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
}


int main(){
    int arr[5000];
    for(int i = 0 ; i < 5000 ; i++){
        arr[i] = 1 + (rand() % 5000);
    }

    mergeSort(arr, 0, 4999);
    int a; 
    cout << "Enter the Number : ";
    cin >> a;
    bool check = false;
    int loc = -1;
    binarysearch(a, arr, check, loc);
    if(check == true){
        cout << "Element Found !! " << endl;
        cout << "Location of element is " <<loc << endl;
    }
    else{
        cout << "Element Not Found :( ";
    }

    return 0;
}
// TC  = O(nlogn)
// SC = O(n)
