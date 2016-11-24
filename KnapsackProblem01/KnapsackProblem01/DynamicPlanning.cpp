#include "ProblemManager.h"


void ProblemManager::DynamicPlanning() {
    //TestData();
    clock_t startTime = clock();

    int** BagMatrix = new int*[ItemNum];
    for (int i = 0; i < ItemNum; i++) {
        BagMatrix[i] = new int[capacity + 1];
    }
    //memset(BagMatrix, 0, sizeof(int)* ItemNum * (capacity + 1));
    for (int i = 0; i < ItemNum; i++) {
        for (int j = 0; j < capacity + 1; j++) {
            BagMatrix[i][j] = 0;
        }
    }

    for (int i = 1; i <= capacity; i++) {
        for (int j = 0; j < ItemNum; j++) {
            PackageItem item = *ItemList[j];

			// 背包装不下当前的item
            if (item.weight > i) {
                if (j == 0) {
                    BagMatrix[j][i] = 0;
                }
                else {
                    BagMatrix[j][j] = BagMatrix[j - 1][i];
                }
            }
            else {
                if (j == 0) {
                    BagMatrix[j][i] = item.value;
                    continue;
                }
                else {
                    int itemInBag = BagMatrix[j - 1][i - item.weight] + item.value;
                    BagMatrix[j][i] = BagMatrix[j - 1][i] > itemInBag ? BagMatrix[j - 1][i] : itemInBag;
                }
            }
        }
    }

	// 从价值矩阵找出所需的答案背包列表，矩阵的右上角开始
    std::vector<PackageItem> answers;
    auto leftSize = capacity;
    for (int i = ItemNum - 1; i >= 0; i--) {
        PackageItem item = *ItemList[i];
        if (leftSize == 0) {
            break;
        }
        if (leftSize > 0 && i == 0) {
            answers.push_back(item);
            break;
        }
        if ((BagMatrix[i][leftSize] - BagMatrix[i - 1][leftSize - item.weight]) == item.value) {
            answers.push_back(item);
            leftSize -= item.weight;
        }
    }
    clock_t endTime = clock();
	//std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(6) << static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000 << std::endl;
	ShowAnswer(answers, AnswerInfo("动态规划", static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000));
}