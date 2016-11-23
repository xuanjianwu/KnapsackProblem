#ifndef PROBLEM_MANAGER_H
#define PROBLEM_MANAGER_H

#define ItemNumMin 500
#define ItemNumMax 1000
#define WeightMin 1
#define WeightMax 100
#define ValueMin 1
#define ValueMax 100
#define Ratio 0.5

class ProblemManager {
private:
    int capacity;
    int ItemNum;
    int* WeightArr;
    int* ValueArr;
    static ProblemManager* instance;
    ProblemManager();
    ProblemManager(const ProblemManager&) = delete;

public:
    static ProblemManager* GetInstance();
    ~ProblemManager();
    inline int NextRandom(int min, int max);
    
    void DynamicPlanning();
    void Greedy();
    void BackTracing();
    void SimulatedAnealing();
};



#endif /* PROBLEM_MANAGER_H */