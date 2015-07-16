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
