#pragma once
#include "Includes.h"

class Tools{
private:

public:
	static const int SECONDS = 1;
	static const int MILLISECONDS = 1000;
	static const int MICROSECONDS = 1000000;
	static const int NANOSECONDS = 1000000000;

	template <class T>
	static void printArray(T * in, int size)
	{
		int i;
		for (i = 0; i < size-1; i++)
		{
			std::cout << in[i] << " ";
		}
		std::cout << in[i] << std::endl;
	}

	template <class T>
	static void print2DArray(T ** in, int sizeX, int sizeY)
	{
		int i;
		for (i = 0; i < sizeX; i++)
		{
			Tools::printArray<T>(in[i], sizeY);
		}
	}
	
	template <class T>
	static void printVector(std::vector<T>* in)
	{
		unsigned int i;
		for (i = 0; i < in->size() - 1; i++)
			{
				std::cout << in->at(i) << " ";
			}
		std::cout << in->at(i) << std::endl;
	}

	static float GetMyCPUTime(int format)
	{
		HANDLE hProcess;    // specifies the process of interest
		FILETIME lpCreationTime;    // when the process was created
		FILETIME lpExitTime;    // when the process exited
		FILETIME lpKernelTime;    // time the process has spent in kernel mode
		FILETIME lpUserTime;
		LARGE_INTEGER t1, t2;
		if (!format){
			format = Tools::SECONDS;
		}


		hProcess = GetCurrentProcess();
		GetProcessTimes(hProcess, &lpCreationTime, &lpExitTime, &lpKernelTime, &lpUserTime);
		memcpy(&t1, &lpUserTime, sizeof(FILETIME));
		memcpy(&t2, &lpKernelTime, sizeof(FILETIME));
		return ((float)(t1.QuadPart + t2.QuadPart) * 100 / 1000000000 * format); // time in miliseconds
	}

	static string Tools::GetError(const DWORD& dwErrorCode)
	{
		LPTSTR lpErrorText = NULL;

		::FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER,
			0, dwErrorCode, 0, lpErrorText, MAX_PATH, 0);

		string s = lpErrorText;
		::LocalFree(lpErrorText);
		return s;
	}

	static bool Tools::ReadFileData(string filename, int * M, int * N, int * &weights, int * &values)
	{
		string line;
		fstream f;
		int num;
		f.open(filename, ios_base::in);
		if (f.fail())
		{
			cout << "Soubor neexistuje.";
			return false;
		}
		getline(f, line);
		*M = std::stoi(line);
		getline(f, line);
		*N = std::stoi(line);
		weights = new int[*N + 1];
		values = new int[*N + 1];
		weights[0] = 0;
		values[0] = 0;

		getline(f, line);
		istringstream is1(line);
		for (int i = 1; i <= *N; i++)
		{
			is1 >> num;
			weights[i] = num;
		}

		getline(f, line);
		istringstream is2(line);
		for (int i = 1; i <= *N; i++)
		{
			is2 >> num;
			values[i] = num;
		}
		f.close();
		return true;
	}


	static bool Tools::ReadEduxFileData(string filename, int * M, int * N, int * &weights, int * &values, int * id, int line_to_read)
	{
		string line;
		fstream f;
		f.open(filename, ios_base::in);
		if (f.fail())
		{
			cout << "Soubor neexistuje.";
			return false;
		}
		for (int j = 0; j < line_to_read; j++){
			getline(f, line);
		}
		getline(f, line);
		istringstream is2(line);
		is2 >> *id;
		is2 >> *N;
		is2 >> *M;
		weights = new int[*N];
		values = new int[*N];

		int i = 0;
		while (is2 >> weights[i])
		{
			is2 >> values[i];
			i++;
		}
		f.close();
		return true;
	}

};
