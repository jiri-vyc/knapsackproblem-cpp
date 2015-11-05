#include "DynamicKnapsackSolver.h"

using namespace std;

bool DynamicKnapsackSolver::Solve()
{
	int C = 0, MAX_W = 1, index;
	for (int i = 0; i < m_N; i++){
		C += this->m_items[i].value;
		MAX_W += this->m_items[i].weight;
	}
	int ** solveArray;
	solveArray = new int*[m_N+1];
	for (int i = 0; i < m_N+1; i++){
		solveArray[i] = new int[C+1];
	}

	for (int i = 0; i < m_N + 1; i++){
		for (int j = 0; j < C + 1; j++){
			solveArray[i][j] = MAX_W;
			if (i == 0 && j > 0) {
				solveArray[0][j] = MAX_W;
			}
			else if (j == 0) {
				solveArray[i][0] = 0;
			}
			else {
				index = j - m_items[i - 1].value;
				if (index >= 0) {
					solveArray[i][j] = min(solveArray[i - 1][j], solveArray[i-1][index] + m_items[i - 1].weight);
				}
				else{
					solveArray[i][j] = min(solveArray[i - 1][j], MAX_W);
				}
			}
			
		}
	}

	int max = 0;
	for (int j = 0; j < C + 1; j++){
		if (j > max && solveArray[m_N][j] <= m_M){
			max = j;
		}
	}
	this->m_current_best_price = max;

	int j = max;
	for (int i = m_N; i > 0; i--){
		if (solveArray[i][j] == solveArray[i - 1][j]){
			m_result_vector->at(i - 1) = 0;
		}
		else{
			m_result_vector->at(i - 1) = 1;
			j -= m_items[i - 1].value;
		}
	}

	return true;
}
