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
	int upperBound = CalculateUpperBound(node);
	//cout << "Checking " << node;
	if (node.weight > this->m_M || upperBound < m_current_upperBound)
	{
		//cout << " - not perspective" << endl;
		 return false;
	}
	//cout << endl;
	m_current_upperBound = upperBound;

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

