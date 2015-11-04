#pragma once
#include "Includes.h"
using namespace std;
class Item {
public:
		int weight;
		int value;
		int level;
		Item(int w, int v, int l){ weight = w; value = v; level = l; };
		Item(){};
		friend ostream& operator<<(ostream& os, const Item in)
		{
			os << "[" << in.weight << "|" << in.value << "|" << in.level << "]";
			return os;
		}
};