#pragma once
#include "KnapsackSolver.h"
class DynamicKnapsackSolver : public KnapsackSolver
{
public:
	bool Solve();
	DynamicKnapsackSolver() :KnapsackSolver(){
		//if (!m_silent) cout << "Creating DynamicKnapsackSolver" << endl;
	};
	DynamicKnapsackSolver(int M, int N, int * weights, int * values, int id) : KnapsackSolver(M, N, weights, values, id){
		//if (!m_silent) cout << "Creating DynamicKnapsackSolver" << endl;
	};
protected:
};
