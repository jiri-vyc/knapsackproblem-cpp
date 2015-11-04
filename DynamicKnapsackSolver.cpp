#include "DynamicKnapsackSolver.h"

using namespace std;

bool DynamicKnapsackSolver::Solve()
{
	// vypocet - vzdy jen dva sloupce kvuli pameti
	int * m_odd = new int[m_M + 1];
	int * m_even = new int[m_M + 1];
	
	for (int i = 0; i <= m_M; i++) { m_even[i] = 0; }
	
	for (int i = 1; i <= m_N; i++) {
		for (int j = 0; j <= m_M; j++) {
			if (i % 2 == 1) { // odd
				if ((m_items[i].weight <= j) && (m_items[i].value + m_even[j - m_items[i].weight] > m_even[j])) {
					m_odd[j] = m_items[i].value + m_even[j - m_items[i].weight];
				}
				else {
					m_odd[j] = m_even[j];
				}
			}
			else { // even
				if ((m_items[i].weight <= j) && (m_items[i].value + m_odd[j - m_items[i].weight] > m_odd[j])) {
					m_even[j] = m_items[i].value + m_odd[j - m_items[i].weight];
				}
				else {
					m_even[j] = m_odd[j];
				}
			}
		}
	}
	
	// vysledna vaha
	if (m_M % 2 == 1) {
		this->m_current_best_price = m_odd[m_M];
	}
	else {
		this->m_current_best_price = m_even[m_M];
	}

	// uvolneni
	//delete[]weight;
	//delete[]cost;
	delete[]m_odd;
	delete[]m_even;

	return true;
}
