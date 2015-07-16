//-- QUICK SORT, Complexity O(nlog(n)) for average case and O(n^2) for worst case which is a sorted list.
//-- in Quick Sort, we consider a value of the array as pivot and then we divide the array into lower and greater
//-- subarrays in the left and rigth side of the pivot. Which means that every element on the left of the pivot
//-- is lower than pivot and each element on the right side of the pivot is greater than pivot.
//-- We keep doing this till we get to the subarrays of size 1.

#include <iostream>
#include <vector>


void printNum(const std::vector<int> num){

	for (int i = 0; i < num.size() - 1; ++i){

		std::cout << num[i] << " ,";
	}

	std::cout << num[num.size() - 1] << std::endl;
}

unsigned int partition(std::vector<int> &num, int low, int high){

	int pivot_location = high;
	int wall_location = low;
	int temp = 0;

	for (int current_location = low; current_location < high; ++current_location){

		if (num[current_location] < num[pivot_location]){
			
			//-- Swap the current_value with the first value to the right of the wall
			temp = num[current_location];
			num[current_location] = num[wall_location];
			num[wall_location] = temp;

			//-- Move the wall to the right
			++wall_location;
		}
	}

	temp = num[wall_location];
	num[wall_location] = num[pivot_location];
	num[pivot_location] = temp;

	pivot_location = wall_location;

	return  pivot_location;
}

void QuickSort(std::vector<int> &num, int low, int high){

	if (low < high){

		unsigned int pivot_location = partition(num, low, high);

		//-- Sorting the left of the wall
		QuickSort(num, low, pivot_location - 1);

		//-- Sorting the right of the wall
		QuickSort(num, pivot_location + 1, high);

	}

}

int main(int argc, char* argv[]){

  std::vector<int> nums = {6,5,-1,3,-8,4,7,9,2};
	
  printNum(nums);
  QuickSort(nums, 0, nums.size()-1);
  printNum(nums);
	
  return 0;
}
