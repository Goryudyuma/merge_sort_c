#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

//何個の配列をソートするか。
#define data_num 100000

void Merge(int data[data_num],int left,int mid,int right){
	//変数の用意。
	//n1は左半分の個数
	int n1=mid-left;
	//n2は右半分の個数
	int n2=right-mid;
	//左半分の数が入る配列を、動的生成。+1は番兵分。
	int *L=(int*)malloc(sizeof(int)*(n1+1));
	//右半分の数が入る配列を、動的生成。+1は番兵分。
	int *R=(int*)malloc(sizeof(int)*(n2+1));
	//for文用変数用意。
	int i,j,k;
	
	//配列に左半分の数を入れる。
	for(i=0;i<n1;i++){
		L[i]=data[left+i];
	}
	//配列に右半分の数を入れる。
	for(j=0;j<n2;j++){
		R[j]=data[mid+j];
	}

	//番兵の追加。
	L[i]=INT_MAX;
	R[j]=INT_MAX;
	//iとjはさっき使ったので、初期化。
	i=0;
	j=0;

	//元の配列に入れていく。
	for(k=left;k<right;k++){
		//小さい方を追加していく。
		if(L[i]<=R[j]){
			data[k]=L[i];
			i++;
		}else{
			data[k]=R[j];
			j++;
		}
	}

	//メモリの開放。
	free(L);
	free(R);
}

void Merge_Sort(int data[data_num],int left,int right){
	if(left+1<right){
		//真ん中を出す。切り捨て。
		int mid = (left+right)/2;

		//左半分を再帰でソート。
		Merge_Sort(data,left,mid);

		//右半分を再帰でソート。
		Merge_Sort(data,mid,right);

		//結果を統合。
		Merge(data,left,mid,right);
	}
}

int main(){
	//randの準備
	srand((unsigned)time(NULL));
	
	//変数と配列の用意
	int i;
	int data[data_num];

	//乱数でランダムに配列に追加する。
	for(i=0;i<data_num;i++){
		data[i]=(int)(rand()%INT_MAX);
	}
	
	//とりあえずプリント。ランダムになってるか確認。
	for(i=0;i<data_num;i++){
		printf("%d\n",data[i]);
	}
	
	//MergeSortの実行。
	Merge_Sort(data,0,data_num);
	
	//ソートできてるか確認のためにプリント。
	for(i=0;i<data_num;i++){
		printf("%d\n",data[i]);
	}
	
	return 0;
}
