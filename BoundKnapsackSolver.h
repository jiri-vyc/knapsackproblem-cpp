#pragma once
#include "TreeKnapsackSolver.h"
class BoundKnapsackSolver : public TreeKnapsackSolver
{
public:
	BoundKnapsackSolver() :TreeKnapsackSolver(){
		m_current_upperBound = 0;
		cout << "Creating BoundKnapsackSolver" << endl;
	};
	BoundKnapsackSolver(int M, int N, int * weights, int * values, int id) : TreeKnapsackSolver(M, N, weights, values, id)
	{
		cout << "Creating BoundKnapsackSolver" << endl;
		m_current_upperBound = 0;
	};
protected:
	int GetMaxBranchPrice(int currItem);
	bool IsPerspective(Item node); 
	int CalculateUpperBound(Item node);
	int m_current_upperBound;
};
