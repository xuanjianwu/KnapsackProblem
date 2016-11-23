#include "ProblemManager.h"

struct cmp {
	bool operator()(PackageItem a, PackageItem b) {
		return ((double)a.value / a.weight) < ((double)b.value / b.weight);
	}
};

void ProblemManager::Greedy(){
    TestData();
	clock_t startTime = clock();

	std::priority_queue<PackageItem, std::vector<PackageItem>, cmp> PQueue;
	for (int i = 0; i < ItemNum; i++) {
		PQueue.push(*ItemList[i]);
	}
	auto leftSize = capacity;
	std::vector<PackageItem> answers;
	while (!PQueue.empty()) {
		PackageItem item = PQueue.top();
		//std::cout << item.id << "  " << (double)item.value/item.weight <<std::endl;
		// 优先队列，找出剩下背包容量可以装的下的单位价值最大的item装入answer
		if (item.weight <= leftSize) {		
			answers.push_back(item);
			leftSize -= item.weight;
		}
		PQueue.pop();
	}
	clock_t endTime = clock();

	//std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << std::endl;
	ShowAnswer(answers, AnswerInfo("贪心算法", static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000));
}