#include <iostream>
//#include "Hashtable.h"

#include <unordered_set>
#include <unordered_map>
#include <string>
#include "UnorderedSet.h"
#include "UnorderedMap.h"
#include <queue>
#include <functional>
using namespace std;

int main()
{
	//string arr[] = { "Æ»¹û", "Î÷¹Ï", "Ïã½¶", "²ÝÝ®", "Æ»¹û", "Î÷¹Ï", 
	//	"Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶" };
	//hdm::Hashtable<string, int> countmap;

	//for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	//{
	//	auto tmp = countmap.find(arr[i]);
	//	if (tmp)
	//	{
	//		tmp->_kv.second++;
	//	}
	//	else
	//	{
	//		countmap.Insert(make_pair(arr[i], 1));
	//	}
	//}


	//int i = 1;
	//for (auto& e : arr)
	//{
	//	countmap[e]++;
	//}
	//for (auto& e : countmap)
	//{
	//	cout << e.first << ":" << e.second << endl;;
	//}

	//hdm::TestHashTable1();

	//buckethash::TestBuckethash2();

	//hdm::test_unordered_map();
	//priority_queue<int,vector<int>,greater<int>> q;
	//q.push(3);
	//q.push(1);
	//q.push(4);
	//q.push(2);

	//while (!q.empty())
	//{
	//	cout << q.top() << endl;
	//	q.pop();
	//}
	hdm::test_unordered_map2();
	return 0;
}
