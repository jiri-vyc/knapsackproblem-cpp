#include "HeuristicKnapsackSolver.h"

using namespace std;

bool HeuristicKnapsackSolver::Solve()
{
	SortItems(false);
	m_current_best_price = 0;
	int currWeight = 0;
	for (int i = 1; i <= m_N; i++)
	{
		if (currWeight + m_items[i].weight < m_M)
		{
			currWeight += m_items[i].weight;
			m_current_best_price += m_items[i].value;
			m_result_vector->at(m_items[i].level - 1) = true;
		}
	}
	return true;
}