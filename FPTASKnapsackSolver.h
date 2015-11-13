#pragma once
#include "KnapsackSolver.h"
class FPTASKnapsackSolver : public KnapsackSolver
{
public:
	bool Solve();
	FPTASKnapsackSolver() : KnapsackSolver(){
		cout << "Creating FPTASKnapsackSolver" << endl;
		SetError(0.4);
	};
	FPTASKnapsackSolver(int M, int N, int * weights, int * values, int id) : KnapsackSolver(M, N, weights, values, id){
		cout << "Creating FPTASKnapsackSolver" << endl;
		SetError(0.4);
	};
	FPTASKnapsackSolver(double epsilon) : KnapsackSolver(){
		SetError(epsilon);
		cout << "Creating FPTASKnapsackSolver with precision " << epsilon << endl;
	};
	void SetError(double in);
protected:
	double m_eps;
};