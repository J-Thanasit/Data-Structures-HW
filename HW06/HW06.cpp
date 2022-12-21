#include <iostream>
using namespace std;
class Ranking{
private:
    int data[1000];
    int size;
    int left = 0;
    int right = size-1;
    int mid;

public:
    Ranking(int n){
        size = n;
    }
    void inputData(){
        for(int i=0;i<size;i++)
            cin>>data[i];
    }
    int binarySearch(int key){
        int left = 0;
        int right = size-1;
        int mid;
        while(left<=right){
            mid = (left+right)/2;
            if(key == data[mid])
                return mid+1;
            else
                if(key < data[mid])
                    left = mid+1;
                else
                    right = mid-1;
        }
    }
    void merge(int left, int mid, int right){
        int left_end = mid-1;
        int tmp_pos = 0;
        int num_elements = right-left+1;
        int temp[100];
        while((left<=left_end)&&(mid<=right)){
            if(data[left]<=data[mid]){
                temp[tmp_pos] = data[mid];
                tmp_pos = tmp_pos+1;
                mid = mid+1;
            }else{
                temp[tmp_pos] = data[left];
                tmp_pos = tmp_pos+1;
                left = left+1;
            }
        }while(left<=left_end){
            temp[tmp_pos] = data[left];
            left = left+1;
            tmp_pos = tmp_pos+1;
        }while(mid <= right){
            temp[tmp_pos] = data[mid];
            mid = mid+1;
            tmp_pos = tmp_pos+1;
        }for(tmp_pos=num_elements-1;tmp_pos>=0;tmp_pos--){
            data[right] = temp[tmp_pos];
            right = right-1;
        }
    }
    void mergeSort(int left, int right){
        int mid;
        if(left < right){
    		mid = (right + left)/2;
    		mergeSort(left,mid);
            mergeSort(mid+1,right);
            merge(left,mid+1,right);
		}
    }

    int show(int index){
        return data[index-1];
    }
};

