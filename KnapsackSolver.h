#pragma once
#include "Includes.h"
#include "Item.h"
class KnapsackSolver
{
public:
	KnapsackSolver();
	KnapsackSolver(int M, int N, int * weights, int * values, int id);
	virtual bool Solve() = 0;
	void SetRecursive(bool in);
	void LoadNewParams(int M, int N, int * weights, int * values, int id);
	void PrintParams();
	void PrintResult();
	int GetResult();
	int GetResultId();
protected:
	int m_id;
	int m_M;
	int m_N;
	int m_current_best_price; 
	std::vector<bool>* m_result_vector = NULL;
	std::vector<bool>* m_current_vector = NULL;
	Item * m_items;
	bool m_recursive = false;
	void Log(std::string in);
	bool CheckIfBest(int currWeight, int currValue);
	void SortItems(bool rewriteOrder);
	static int CompareItems(const void * a, const void * b);
};
