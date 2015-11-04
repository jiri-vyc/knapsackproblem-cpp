#pragma once
#include "TreeKnapsackSolver.h"

class BruteKnapsackSolver : public TreeKnapsackSolver
{
public:
	BruteKnapsackSolver() :TreeKnapsackSolver(){};
	BruteKnapsackSolver(int M, int N, int * weights, int * values, int id) : TreeKnapsackSolver(M, N, weights, values, id){
		cout << "Creating BruteKnapsackSolver" << endl;
	};
protected:
	bool IsPerspective(Item node);
};
