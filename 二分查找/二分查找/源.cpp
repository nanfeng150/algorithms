#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

template<typename T>
int BinarySerach(T arr[],int n,T target) {
	int begin = 0, end = n - 1;
	while (begin<=end) {
	    int mid = (begin + end) / 2;//数据量过大时，容易整形溢出，解决办法->mid=begin+(end-begin)/2
		if (target == arr[mid]) {
			return mid;//所查找值的下标
		}
		else {
			if (arr[mid] > target) {
				end = mid-1;
			}
			else if (arr[mid] < target)
				begin = mid+1;
		}
	}
	return -1;
}
int main() {
	int arr[6] = { 1,5,7,9,14 ,29};
	int ret = BinarySerach(arr, 6, 29);
	std::cout << ret << std::endl;
	std::cout<<"hello world"<<std::endl;
	std::cout << "hello wrold" << std::endl;
	return 0;
}
