#include "FPTASKnapsackSolver.h"
#include "DynamicKnapsackSolver.h"

using namespace std;

bool FPTASKnapsackSolver::Solve()
{
	//PrintParams();
	int maxValue = GetSumValue();
	double K = m_eps * maxValue / m_N;
	//cout << "eps=" << m_eps << " K=" << K << endl;
	int b = (int)floor(log2(K));
	//cout << "shifting " << b << "bits" << endl;
	int * new_values = new int[m_N];
	int * new_weights = new int[m_N];
	for (int i = 0; i < m_N; i++){
		new_values[i] = m_items[i].value >> b;
		new_weights[i] = m_items[i].weight;
	}

	DynamicKnapsackSolver* solver = new DynamicKnapsackSolver;
	solver->LoadNewParams(m_M, m_N, new_weights, new_values, m_id);
	solver->SetSilent(true);
	//solver->PrintParams();
	solver->Solve();
	m_result_vector = solver->GetResultVector();
	m_current_best_price = 0;

	for (int i = 0; i < m_N; i++){
		if (m_result_vector->at(i) == 1){
			m_current_best_price += m_items[i].value;
		}
	}

	return true;
}

void FPTASKnapsackSolver::SetError(double in)
{
	m_eps = in;
}
