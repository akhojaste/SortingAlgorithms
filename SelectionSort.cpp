#include <iostream>
#include <vector>

void printNum(const std::vector<int> num){

	for (int i = 0; i < num.size() - 1; ++i){

		std::cout << num[i] << " ,";
	}

	std::cout << num[num.size() - 1] << std::endl;
}


//-- SELECTION SORT, average complexity of O(N^2)
void SelectionSort(std::vector<int> &num, int low){

	int length = num.size();

	if (low < length){

		//-- Finding the minimum
		int minVal = num[low];
		int index = low;
		for (int i = low; i < length; ++i){

			if (num[i] < minVal){
				minVal = num[i];
				index = i;
			}
		}

		int temp = num[low];
		num[low] = minVal;
		num[index] = temp;

		SelectionSort(num, low + 1);
	}
}

int main(int argc, char* argv[])
{
  std::vector<int> nums = {-6,5,-1,3,-8,4,7,9,2, 12, -23, -1, 15};
  
  printNum(nums);
  SelectionSort(nums, 0);
  printNum(nums);
	
  return 0;
}
