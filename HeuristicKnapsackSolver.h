#pragma once
#include "KnapsackSolver.h"

class HeuristicKnapsackSolver : public KnapsackSolver
{
public:
	bool Solve();
	HeuristicKnapsackSolver() :KnapsackSolver(){
		cout << "Creating HeuristicKnapsackSolver" << endl;
	};
	HeuristicKnapsackSolver(int M, int N, int * weights, int * values, int id) : KnapsackSolver(M, N, weights, values, id){
		cout << "Creating HeuristicKnapsackSolver" << endl;
	};
protected:
	
};