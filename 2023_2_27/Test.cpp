#include <iostream>
#include "Hashtable.h"

#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
	//string arr[] = { "Æ»¹û", "Î÷¹Ï", "Ïã½¶", "²ÝÝ®", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶" };
	//unordered_map<string, int> countmap;

	//for (auto& e : arr)
	//{
	//	countmap[e]++;
	//}
	//for (auto& e : countmap)
	//{
	//	cout << e.first << ":" << e.second << endl;;
	//}

	hdm::TestHashTable1();
	return 0;
}
