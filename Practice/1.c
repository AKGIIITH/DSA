#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* arranger(int* arr,int* brr,int arr_size,int brr_size){
    int* arranged=(int*) calloc(sizeof(int),(arr_size+brr_size));
    int i=0;int j=0;int index=0;
    //Arrange until smallest one exhaust
    while(i<arr_size && j<brr_size){
        if(arr[i]<=brr[j]){
            arranged[index]=arr[i];
            i++;
        }
        else{
            arranged[index]=brr[j];
            j++;
        }
        index++;
    }
    //Smallest one will have no entry in loop
    while(i<arr_size){
        arranged[index]=arr[i];
        i++;
        index++;
    }
    //But Larger one will have all element arranged in the loop
    while(j<brr_size){
        arranged[index]=brr[j];
        j++;
        index++;
    }
    return arranged;
}

int* merge_sort(int* arr,int l,int u){
    if(l==u){
        int* single=(int*)calloc(sizeof(int),1);
        single[0]=arr[l];
        return single;
    }
    else{
        int mid=(l+u)/2;
        int* temp_1=merge_sort(arr,l,mid);
        int* temp_2=merge_sort(arr,mid+1,u);
        int size_temp1=mid-l+1;
        int size_temp2=u-mid;
        return arranger(temp_1,temp_2,size_temp1,size_temp2);
    }
}
int main(){
    clock_t start=clock();
    int size=10000;
    // printf("Merge_sort here:\n");
    // printf("Enter Size of Array: ");
    // scanf("%d",&size);

    int arr[size];
    for(int i=0;i<size;i++){
        arr[i]=size-i;
    }

    clock_t mid=clock();

    // for(int i=0;i<size;i++){
    //     scanf("%d",&arr[i]);
    // }

    int* sorted=merge_sort(arr,0,size-1);
    for(int i=0;i<size;i++){
        printf("%d ",sorted[i]);
    }
    clock_t end= clock();
    printf("\n%llf\t%llf",mid-start,end-mid);
}