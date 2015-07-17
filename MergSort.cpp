#include <iostream>
#include <vector>

void printNum(const std::vector<int> num){

	for (int i = 0; i < num.size() - 1; ++i){

		std::cout << num[i] << " ,";
	}

	std::cout << num[num.size() - 1] << std::endl;
}



//-- MERGE SORT, complexity of O(n log(n)) for an average and worst case
void MergSortedLists(std::vector<int> &num1, std::vector<int> &num2, std::vector<int> &MergNum){

	int index1 = 0;
	int index2 = 0;

	while (index1 != num1.size() && index2 != num2.size() )
	{
		if (num1[index1] < num2[index2]){
			MergNum.push_back(num1[index1]);
			++index1;
		}
		else
		{
			MergNum.push_back (num2[index2]);
			++index2;
		}

	}

	if (index2 == num2.size()){
		for (int i = index1; i < num1.size(); ++i){
			MergNum.push_back(num1[i]);
		}
	}

	if (index1 == num1.size()){
		for (int i = index2; i < num2.size(); ++i){
			MergNum.push_back(num2[i]);
		}
	}

}

void MergSort(std::vector<int> &num, std::vector<int> &SortedNum){

	//-- Contains the sorted list
	//std::vector<int> SortedNum;
	std::vector<int> SortedNum1;
	std::vector<int> SortedNum2;

	if (num.size() > 1)
	{
		//-- Create two lists to be merged!
		std::vector<int>::iterator middle = num.begin() + (num.size() / 2);
		std::vector<int> num1(num.begin(), middle);
		std::vector<int> num2(middle, num.end());

		MergSort(num1, SortedNum1);
		MergSort(num2, SortedNum2);

		//-- Merg the two slited sorted sublists
		MergSortedLists(SortedNum1, SortedNum2,  SortedNum);
		
		//-- Clear each sub lists
		SortedNum1.clear();
		SortedNum1.clear();
	}
	if (num.size() == 1){
		SortedNum.push_back(num[0]);
	}

}

int main(int argc, char* argv[])
{
	
	std::vector<int> nums = {-6,5,-1, 8, 4, 2, 3, 7,6};
	std::vector<int> sortedNum;
	
	printNum(nums);
	MergSort(nums,sortedNum);
	printNum(sortedNum);
	
	return 0;
	
}
