#include "ProblemManager.h"

struct cmp {
    bool operator()(PackageItem a, PackageItem b) {
        return ((double)a.value / a.weight) < ((double)b.value / b.weight);
    }
};

bool compare2(PackageItem a, PackageItem b) {
	return ((double)a.value / a.weight) > ((double)b.value / b.weight);
}

class Knap {
public:
    std::vector<PackageItem> ItemVec;
    int c;
    int n;
    int cw;
    int cv;
    int bestV;
    int* selected;
	int* best;
    double Bound(int i);
    void Backtrack(int i);
	Knap(int c, int n, PackageItem** PQueue);
};

Knap::Knap(int c, int n, PackageItem** PQueue) {
    this->c = c;
    this->n = n;
    selected = new int[n];
	best = new int[n];
    for (int i = 0; i < n; i++) {
        //this->ItemVec.push_back(PQueue.top());
        //PQueue.pop();
		this->ItemVec.push_back(PQueue[i]);
    }
    cw = 0;
    cv = 0;
    bestV = 0;
}

void Knap::Backtrack(int i) {
    if (i >= n) {
		if (cv > bestV) {
			for (int i = 0; i < n; i++) {
				best[i] = selected[i];
			}
			bestV = cv;
		}     
        return;
    }
    if (cw + ItemVec[i].weight <= c) {
		selected[i] = 1;
        cw += ItemVec[i].weight;
        cv += ItemVec[i].value;
        Backtrack(i + 1);
        cw -= ItemVec[i].weight;
        cv -= ItemVec[i].value;
		selected[i] = 0;
    }
    if (Bound(i + 1) > bestV) {	
        Backtrack(i + 1);
    }
}

double Knap::Bound(int i) {
    int leftSize = c - cw;
    double mv = cv;

    while (i < n && ItemVec[i].weight <= leftSize) {
        leftSize -= ItemVec[i].weight;
        mv += ItemVec[i].value;
        i++;
    }
    if (i < n) {
        mv += ((double)ItemVec[i].value) / ItemVec[i].weight * leftSize;
    }
    return mv;
}

void ProblemManager::BackTracing() {
    //TestData();
    clock_t startTime = clock();

    auto W = 0;

	PackageItem** PQueue;
	PQueue = new PackageItem*[ItemNum];
	for (int i = 0; i < ItemNum; i++) {
		PQueue[i] = new PackageItem(ItemList[i]);
		W += ItemList[i]->weight;
	}
	std::sort(PQueue, PQueue + ItemNum, compare2);

    //std::priority_queue<PackageItem, std::vector<PackageItem>, cmp> PQueue;
    //for (int i = 0; i < ItemNum; i++) {
    //    PQueue.push(*ItemList[i]);
    //    W += ItemList[i]->weight;
    //}
    std::vector<PackageItem> answers;
    if (W <= capacity) {
        for (int i = 0; i < ItemNum; i++) {
            answers.push_back(*ItemList[i]);
        }
        clock_t endTime = clock();
        ShowAnswer(answers, AnswerInfo("回溯法", static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000));
        return;
    }

    Knap knap(capacity, ItemNum, PQueue);
    knap.Backtrack(0);
    //std::cout << knap.bestV << std::endl;
	for (int i = 0; i < knap.n; i++) {
		if (knap.best[i] == 1) {
			answers.push_back(knap.ItemVec[i]);
		}
	}
	clock_t endTime = clock();
	ShowAnswer(answers, AnswerInfo("回溯法", static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000));
}