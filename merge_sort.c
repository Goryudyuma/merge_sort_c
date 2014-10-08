#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define data_num 100000

void Merge(int data[data_num],int left,int mid,int right){
	int n1=mid-left;
	int n2=right-mid;
	int *L=(int*)malloc(sizeof(int)*(n1+1));
	int *R=(int*)malloc(sizeof(int)*(n2+1));
	int i,j,k;
	
	for(i=0;i<n1;i++){
		L[i]=data[left+i];
	}
	for(j=0;j<n2;j++){
		R[j]=data[mid+j];
	}
	L[i]=INT_MAX;
	R[j]=INT_MAX;
	i=0;
	j=0;
	for(k=left;k<right;k++){
		if(L[i]<=R[j]){
			data[k]=L[i];
			i++;
		}else{
			data[k]=R[j];
			j++;
		}
	}
	free(L);
	free(R);
}

void Merge_Sort(int data[data_num],int left,int right){
	if(left+1<right){
		int mid = (left+right)/2;
		Merge_Sort(data,left,mid);
		Merge_Sort(data,mid,right);
		Merge(data,left,mid,right);
	}
}

int main(){
	srand((unsigned)time(NULL));
	int i,j;
	int n;
	
	int data[data_num];
	for(i=0;i<data_num;i++){
		data[i]=(int)(rand()%INT_MAX);
	}
	
	for(i=0;i<data_num;i++){
		printf("%d\n",data[i]);
	}
	
	Merge_Sort(data,0,data_num);
	
	for(i=0;i<data_num;i++){
		printf("%d\n",data[i]);
	}
	
	return 0;
}
