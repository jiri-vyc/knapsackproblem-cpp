#include "KnapsackSolver.h"

using namespace std;

KnapsackSolver::KnapsackSolver(int M, int N, int * weights, int * values, int id)
{
	this->m_items = new Item[2];
	this->m_result_vector = new vector<bool>(2, 0);
	this->m_current_vector = new vector<bool>(2, 0);
	this->LoadNewParams(M, N, weights, values, id);
}

void KnapsackSolver::LoadNewParams(int M, int N, int * weights, int * values, int id)
{
	this->m_current_best_price = 0;
	this->m_M = M;
	this->m_N = N;
	this->m_id = id;
	delete this->m_current_vector;
	delete this->m_result_vector;
	this->m_result_vector = new vector<bool>(this->m_N, 0);
	this->m_current_vector = new vector<bool>(this->m_N, 0);

	Item* items = new Item[m_N + 1];

	for (int i = 0; i <= m_N; i++)
	{
		items[i].weight = weights[i];
		items[i].value = values[i];
	}

	for (int i = 1; i <= m_N; i++)
	{
		items[i].level = i;
	}

	m_items = items;
}


void KnapsackSolver::PrintParams()
{
	cout << "Knapsack size: " << this->m_M << endl;
	cout << "Item count: " << this->m_N << endl;
	cout << "Items: ";
	Tools::printArray(this->m_items, this->m_N);
}

void KnapsackSolver::PrintResult()
{
	cout << "Best price: " << this->m_current_best_price << endl;
	cout << "Used items: ";
	Tools::printVector<bool>(this->m_result_vector);
}

int KnapsackSolver::GetResult()
{
	return this->m_current_best_price;
}

int KnapsackSolver::GetResultId()
{
	return this->m_id;
}


bool KnapsackSolver::CheckIfBest(int currWeight, int currValue)
{
	return (currWeight <= this->m_M && currValue > this->m_current_best_price) ? true : false;
}

void KnapsackSolver::SetRecursive(bool in)
{
	cout << "Setting recursive to " << in << endl;
	m_recursive = in;
}
KnapsackSolver::KnapsackSolver()
{
	this->m_current_best_price = 0;
	this->m_M = 0;
	this->m_N = 0;
	this->m_id = -1;
}

int KnapsackSolver::CompareItems(const void * a, const void * b)
{
	return (((float)(*(Item*)b).value / (float)(*(Item*)b).weight - (float)(*(Item*)a).value / (float)(*(Item*)a).weight) < 0 ? -1 : 1);
}

void KnapsackSolver::SortItems(bool rewriteOrder)
{
	qsort(m_items + 1, m_N, sizeof(Item), KnapsackSolver::CompareItems);

	if (rewriteOrder)
	{
		for (int i = 1; i <= m_N; i++)
		{
			m_items[i].level = i;
		}
	}

}
