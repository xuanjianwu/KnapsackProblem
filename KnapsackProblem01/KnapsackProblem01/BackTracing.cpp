#include "ProblemManager.h"

struct cmp {
    bool operator()(PackageItem a, PackageItem b) {
        return ((double)a.value / a.weight) < ((double)b.value / b.weight);
    }
};

class Knap {
public:
    std::vector<PackageItem> ItemVec;
    int c;
    int n;
    int cw;
    int cv;
    int bestV;
    int* selected;
    double Bound(int i);
    void Backtrack(int i);
    Knap(int c, int n, std::priority_queue<PackageItem, std::vector<PackageItem>, cmp> PQueue);
};

Knap::Knap(int c, int n, std::priority_queue<PackageItem, std::vector<PackageItem>, cmp> PQueue) {
    this->c = c;
    this->n = n;
    selected = new int[n];
    for (int i = 0; i < n; i++) {
        this->ItemVec.push_back(PQueue.top());
        PQueue.pop();
    }
    cw = 0;
    cv = 0;
    bestV = 0;
}

void Knap::Backtrack(int i) {
    if (i >= n) {
        bestV = cv;
        return;
    }
    if (cw + ItemVec[i].weight <= c) {
		selected[i] = 1;
        cw += ItemVec[i].weight;
        cv += ItemVec[i].value;
        Backtrack(i + 1);
        cw -= ItemVec[i].weight;
        cv -= ItemVec[i].value;
    }
    if (Bound(i + 1) > bestV) {
		selected[i] = 0;
        Backtrack(i + 1);
    }
}

double Knap::Bound(int i) {
    int leftSize = c - cw;
    int mv = cv;

    while (i < n && ItemVec[i].weight <= leftSize) {
        leftSize -= ItemVec[i].weight;
        mv += ItemVec[i].value;
        i++;
    }
    if (i < n) {
        mv += ItemVec[i].value / ItemVec[i].weight * leftSize;
    }
    return mv;
}

void ProblemManager::BackTracing() {
    //TestData();
    clock_t startTime = clock();

    auto W = 0;

    std::priority_queue<PackageItem, std::vector<PackageItem>, cmp> PQueue;
    for (int i = 0; i < ItemNum; i++) {
        PQueue.push(*ItemList[i]);
        W += ItemList[i]->weight;
    }
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
		if (knap.selected[i] == 1) {
			answers.push_back(knap.ItemVec[i]);
		}
	}
	clock_t endTime = clock();
	ShowAnswer(answers, AnswerInfo("回溯法", static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000));
}