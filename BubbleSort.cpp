#include <iostream>
#include <vector>


void printNum(const std::vector<int> num){

	for (int i = 0; i < num.size() - 1; ++i){

		std::cout << num[i] << " ,";
	}

	std::cout << num[num.size() - 1] << std::endl;
}

void BubbleSort(std::vector<int> &num){

	unsigned int length = num.size();
	int temp=0;

	for (int i = 0; i < length-1; ++i){

		for (int j = 0; j < length - 1; ++j){

			if (num[j] <= num[j + 1]){
				temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}


		}

		printNum(num);
	}


}


int main(int argc, char* argv[]){
  
  std::vector<int> nums = {6,5,-1,3,-8,4,7,9,2};
  BubbleSort(nums);
 	
  return 0;


}
