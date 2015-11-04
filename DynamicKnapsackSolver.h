#pragma once
#include "KnapsackSolver.h"
class DynamicKnapsackSolver : public KnapsackSolver
{
public:
	bool Solve();
	DynamicKnapsackSolver() :KnapsackSolver(){};
	DynamicKnapsackSolver(int M, int N, int * weights, int * values, int id) : KnapsackSolver(M, N, weights, values, id){
		cout << "Creating DynamicKnapsackSolver" << endl;
	};
protected:

};
