#include "KnapsackSolver.h"
#include "BruteKnapsackSolver.h"
#include "BoundKnapsackSolver.h"
#include "DynamicKnapsackSolver.h"
#include "HeuristicKnapsackSolver.h"
#include "FPTASKnapsackSolver.h"

using namespace std;

KnapsackSolver* ChooseSolver(int argc, char* argv[])
{
	KnapsackSolver* solver;
	if (argc > 2)
	{
		if ((string)argv[2] == "dynamic") {
			solver = new DynamicKnapsackSolver();
		}
		else if ((string)argv[2] == "bound") {
			solver = new BoundKnapsackSolver();
			if (argc > 3 && (string)argv[3] == "r") {
				solver->SetRecursive(true);
			}
		}
		else if ((string)argv[2] == "brute"){
			solver = new BruteKnapsackSolver();
			if (argc > 3 && (string)argv[3] == "r") {
				solver->SetRecursive(true);
			}
		}
		else if ((string)argv[2] == "heuristic"){
			solver = new HeuristicKnapsackSolver();
		}
		else if ((string)argv[2] == "fptas"){
			solver = new FPTASKnapsackSolver();
			if (argc > 3) {
				delete solver;
				solver = new FPTASKnapsackSolver(stod((string)argv[3]));
			}
		}
	}
	else
	{
		solver = new BruteKnapsackSolver();
	}
	return solver;
}

int main(int argc, char* argv[])
{
	int M, N, id;
	int * weights;
	int * values;
	
	if (argc <= 1)
	{
		cout << "File not specified." << endl;
		return 0;
	}

	KnapsackSolver* solver;
	solver = ChooseSolver(argc, argv);
	
	fstream f;
	f.open("results.csv", ios_base::app);

	float start_time = Tools::GetMyCPUTime(Tools::MILLISECONDS);
	//cout << "Start time: " << start_time << endl;
	
	for (int i = 0; i < 50; i++)
	{
		if (!Tools::ReadEduxFileData(argv[1], &M, &N, weights, values, &id, i))
		{
			return 0;
		}
		solver->LoadNewParams(M, N, weights, values, id);
		//solver->PrintParams();
		solver->Solve();
		f << solver->GetResultId() << "," << solver->GetResult() << endl;
		solver->PrintResult();
	}

	float end_time = Tools::GetMyCPUTime(Tools::MILLISECONDS);
	//cout << end_time - start_time << endl;
	f << (end_time - start_time);
	f << endl;


	f.close();


	delete []weights;
	delete []values;
	delete solver;

	#ifdef _WIN32
	//cin.get();
	#endif
	return 0;
}

