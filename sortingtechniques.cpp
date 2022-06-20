#include <iostream>
using namespace std;
int partition(int arr[],int low,int uper){
    int pivot= arr[low];
    int start= low;
    int end= uper;
    while(start<end){
        while(arr[start]<=pivot){
            start++;

        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
            swap(arr[start],arr[end]);
        }
        swap(arr[low],arr[end]);
    }
    return end;
}

void quicksort(int arr[],int low,int uper){
    if(low<uper){
        int loc= partition(arr,low,uper);
        quicksort(arr,low,loc-1);
        quicksort(arr,loc+1,uper);
    }
}
void merge(int arr[],int low, int mid,int uper){
    int n1= mid-low+1;
    int n2 = uper-mid;// kio k hme mid ko mid+1 se start krna tha pr hmne isko mid se is lye +1 nai kia
    int a[n1];
    int b[n2];
    for(int i=0; i<n1;i++){
        a[i]=arr[low+i];
    }
    for(int i = 0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }

    int i= low;
    int j = mid+1;
    int k= low;
    while(i<=mid && j<=uper){
        if(arr[i]<=arr[j]){
             b[k]=a[i];
            k++;
            j++;
        }
        else{
            b[k]=a[j];
            j++;
            k++;
        }
        if(i>mid){
            while(j<=uper)
                b[k]=a[j];
            j++;
            k++;
        }
        else{
            while(i<=mid) {
                b[k] = a[i];
                i++;
                k++;
            }
        }

    }

}
void mergesort(int arr[],int low,int uper){
    if(low<uper){
       int  mid = (low + uper)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,uper);
        merge(arr,low,mid,uper);
    }
}
int main(){
    int arr[5]={12,11,34,3,2};

  /*  int count = 1;
    while(count<5){
        for(int i =0; i<5-count;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i+1],arr[i]);
            }

        }
        count++;
    }*/

    for(int i =0; i<4;i++){
        for(int j =0 ;j<5;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
            }

        }
    }

    cout<<"the sorted array after bubble sort is : ";
    for(int i= 0;i<5;i++){
        cout<<arr[i];
        cout<<" ";
    }
cout<<endl;

    for(int i = 0; i<4;i++){
       int  min=i;
        for(int j=i+1; j<5;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(arr[min],arr[i]);
        }
    }
    cout<<"the sorted array after selection sort is : ";
    for(int i= 0;i<5;i++){
        cout<<arr[i];
        cout<<" ";
    }

    for(int i = 1; i<5;i++){
        int temp= arr[i];
        int j =i-1;
        while(j>=0&& arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    cout<<"\nthe sorted array after insert sort is : ";
    for(int i= 0;i<5;i++){
        cout<<arr[i];
        cout<<" ";
    }
    quicksort(arr,0,4);

    cout<<"\nthe sorted array after quick sort is : ";
    for(int i= 0;i<5;i++){
        cout<<arr[i];
        cout<<" ";
    }
    mergesort(arr,0,4);

    cout<<"\nthe sorted array after merge sort is : ";
    for(int i= 0;i<5;i++){
        cout<<arr[i];
        cout<<" ";
    }
    return 0;
}