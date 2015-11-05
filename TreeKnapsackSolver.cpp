#include "TreeKnapsackSolver.h"

void TreeKnapsackSolver::RecurSolve(int currWeight, int currValue, int currItem)
{
	// we're at the leaf -> the best solution must be here
	if (currItem >= this->m_N)
	{
		// not exceeding knapsack capacity && having the best price
		if (CheckIfBest(currWeight, currValue))
		{
			// update the best price
			this->m_current_best_price = currValue;
			delete this->m_result_vector;
			this->m_result_vector = new std::vector<bool>(*this->m_current_vector);
		}
		return;
	}
	// shall we continue expanding this node?
	if (!IsPerspective({ currWeight, currValue, currItem })) return;
	// put this item into knapsack & solve for subtree
	this->m_current_vector->at(currItem) = true;
	RecurSolve(currWeight + this->m_items[currItem].weight, currValue + this->m_items[currItem].value, currItem + 1);

	// don't put this item into knapsack & solve for subtree
	this->m_current_vector->at(currItem) = false;
	RecurSolve(currWeight, currValue, currItem + 1);
}

void TreeKnapsackSolver::CycleSolve()
{
	int current_level;
	queue<Item> q;
	Item current_item;
	q.push({ 0, 0, 0 });

	while (!q.empty())
	{
		current_item = q.front();
		q.pop();
		current_level = current_item.level;

		if (!this->IsPerspective(current_item)) continue;

		if (current_level >= this->m_N)
		{
			if (CheckIfBest(current_item.weight, current_item.value))
			{
				this->m_current_best_price = current_item.value;
				delete this->m_result_vector;
				this->m_result_vector = new std::vector<bool>(*this->m_current_vector);
			}
			continue;
		}
		q.push({ current_item.weight + m_items[current_level].weight, current_item.value + m_items[current_level].value, current_level + 1 });
		q.push({ current_item.weight, current_item.value, current_level+1 });
		current_level += 1;
	}
}

bool TreeKnapsackSolver::Solve()
{
	m_current_best_price = 0;

	if (m_recursive)
	{
		RecurSolve(0, 0, 0);
	}
	else
	{
		CycleSolve();
	}
	return true;
}

