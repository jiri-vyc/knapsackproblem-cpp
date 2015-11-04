#pragma once
#include "KnapsackSolver.h"

class TreeKnapsackSolver : public KnapsackSolver
{
public:
	bool Solve();
	TreeKnapsackSolver() :KnapsackSolver(){};
	TreeKnapsackSolver(int M, int N, int * weights, int * values, int id) : KnapsackSolver(M, N, weights, values, id){	};
protected:
	void RecurSolve(int currWeight, int currValue, int currItem);
	void CycleSolve();
	virtual bool IsPerspective(Item node) = 0;
};
