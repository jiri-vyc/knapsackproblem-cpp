#include "BoundKnapsackSolver.h"

using namespace std;

int BoundKnapsackSolver::CalculateUpperBound(Item node)
{
	int currBound = node.value;
	int currWeight = node.weight;
	int i = 0;
	int partV = 0;
	while (currWeight + m_items[node.level + i].weight < m_M && node.level + i <= m_N)
	{
		currBound += m_items[node.level+i].value;
		currWeight += m_items[node.level+i].weight;
		i++;
	}

	partV = (m_M - currWeight) / m_items[node.level + i].weight * m_items[node.level + i].value;
	currBound += partV;

	return currBound;
}

bool BoundKnapsackSolver::IsPerspective(Item node)
{
	int maxPrice = GetMaxBranchPrice(node.level);
	if (node.weight > this->m_M || node.value + maxPrice < m_current_best_price)
	{
		 return false;
	}
	return true;
}

int BoundKnapsackSolver::GetMaxBranchPrice(int currItem)
{
	int result = 0;
	for (int i = currItem; i < m_N; i++)
	{
		result += this->m_items[i].value;
	}
	return result;
}

