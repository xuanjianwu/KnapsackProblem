#include "ProblemManager.h"

void ProblemManager::SimulatedAnealing() {
	//TestData();

	clock_t startTime = clock();

    int* solution = new int[ItemNum];
    memset(solution, 0, sizeof(int)* ItemNum);
    
    int w = 0, v = 0;
    for (int i = 0; i < ItemNum; i++) {
        w += ItemList[i]->weight * solution[i];
        v += ItemList[i]->value * solution[i];
    }
    double t0 = 500;
    double t = t0;
    double a = 0.95f;
    double e = 0.0001f;
    int L = 10 * ItemNum;

	std::cout << "初始温度:  " << t0 << "  退火系数:  " << a << std::setiosflags(std::ios::fixed) << std::setprecision(5) << "  停止准则系数:  " << e << "  平衡参数:  " << L << std::endl;

    int i, j;
    while (t > e) {
        std::srand(std::time(NULL));
        for (int k = 0; k < L; k++) {
            i = std::rand() % ItemNum;
            if (solution[i] == 0) {
				if (w + ItemList[i]->weight <= capacity) {
					w += ItemList[i]->weight;
					v += ItemList[i]->value;
					solution[i] = 1;
				}
				else {
					j = std::rand() % ItemNum;
					while (solution[j] == 0) {
						j = std::rand() % ItemNum;
					}
					int dw, dv;
					dw = ItemList[i]->weight - ItemList[j]->weight;
					dv = ItemList[i]->weight - ItemList[j]->value;
					if (w + dw <= capacity) {
						if (std::exp(dv / t) || dv > 0) {
							solution[i] = 1;
							solution[j] = 0;
							w += dw;
							v += dv;
						}
					}
				}
			}
			else {
				j = std::rand() % ItemNum;
				while (solution[j] == 1) {
					j = std::rand() % ItemNum;
				}
				int dw, dv;
				dw = ItemList[j]->weight - ItemList[i]->weight;
				dv = ItemList[j]->value - ItemList[i]->value;
				if (w + dw <= capacity) {
					if (std::exp(dv / t) || dv > 0) {
						solution[i] = 0;
						solution[j] = 1;
						w += dw;
						v += dv;
					}
				}
			}
        }
		t *= a;
    }
	std::vector<PackageItem> answers;
	for (int i = 0; i < ItemNum; i++) {
		if (solution[i] == 1) {
			answers.push_back(*ItemList[i]);
		}
	}
	clock_t endTime = clock();
	ShowAnswer(answers, AnswerInfo("模拟退火", static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000));
}