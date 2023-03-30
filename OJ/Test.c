////77组合
//class Solution {
//public:
//	vector<vector<int>>  result;
//	vector<vector<int>> combine(int n, int k) {
//		vector<int> path;
//		backtracking(path, n, k, 1);
//		return result;
//	}
//	void backtracking(vector<int>& path, int n, int k, int index)
//	{
//		if (k == path.size())
//		{
//			result.push_back(path);
//			return;
//		}
//		for (int i = index; i <= n; ++i)
//		{
//			path.push_back(i);
//			backtracking(path, n, k, i + 1);
//			path.pop_back();
//		}
//	}
//};
//class Solution {
//public:
//	vector<vector<int>>  result;
//	vector<vector<int>> combine(int n, int k) {
//		vector<int> path;
//		backtracking(path, n, k, 1);
//		return result;
//	}
//	void backtracking(vector<int>& path, int n, int k, int index)
//	{
//		if (k == path.size())
//		{
//			result.push_back(path);
//			return;
//		}
//		for (int i = index; i <= n - (k - path.size()) + 1; ++i)//优化--剪枝操作
//		{
//			path.push_back(i);
//			backtracking(path, n, k, i + 1);
//			path.pop_back();
//		}
//	}
//};
//
////216. 组合总和 III
//class Solution {
//public:
//	vector<vector<int>> reslut;
//	vector<vector<int>> combinationSum3(int k, int n) {
//
//		vector<int> path;
//		backtracking(path, k, n, 1, 0);
//		return reslut;
//	}
//	void backtracking(vector<int>& path, int k, int n, int startIndex, int sum)
//	{
//		if (sum == n && path.size() == k)
//		{
//			reslut.push_back(path);
//			return;
//		}
//		for (int i = startIndex; i<10; i++)
//		{
//			sum += i;
//			path.push_back(i);
//			backtracking(path, k, n, i + 1, sum);
//			sum -= i;
//			path.pop_back();
//		}
//	}
//};
//class Solution {
//public:
//	vector<vector<int>> reslut;
//	vector<vector<int>> combinationSum3(int k, int n) {
//
//		vector<int> path;
//		backtracking(path, k, n, 1, 0);
//		return reslut;
//	}
//	void backtracking(vector<int>& path, int k, int n, int startIndex, int sum)
//	{
//		if (sum>n)//大于n就没必要继续
//			return;
//		if (sum == n && path.size() == k)
//		{
//			reslut.push_back(path);
//			return;
//		}
//		for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++)//剪枝优化
//		{
//			sum += i;
//
//			path.push_back(i);
//			backtracking(path, k, n, i + 1, sum);
//			sum -= i;
//			path.pop_back();
//		}
//	}
//};
//
////电话号码的字母组合
//class Solution {
//public:
//	string vs[10]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//	vector<string> reslut;
//	vector<string> letterCombinations(string digits) {
//		if (digits.size() == 0)
//			return reslut;
//		string s;
//		backtracking(digits, 0, s);
//		return reslut;
//	}
//	void backtracking(string& digits, int index, string s)
//	{
//		if (s.size() == digits.size())
//		{
//			reslut.push_back(s);
//			return;
//		}
//		string str = vs[digits[index] - '0'];
//		for (auto e : str)
//		{
//			backtracking(digits, index + 1, s + e);
//		}
//	}
//};
//
////39. 组合总和
//class Solution {
//public:
//	vector<vector<int>> reslut;
//	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//		vector<int> path;
//		backtracking(candidates, target, path, 0, 0);
//
//
//		return reslut;
//	}
//	void backtracking(vector<int>& candidates, int target, vector<int>& path, int sum, int index)
//	{
//		if (sum>target)
//			return;
//		if (sum == target)
//		{
//			reslut.push_back(path);
//			return;
//		}
//		for (int i = index; i<candidates.size(); ++i)
//		{
//			path.push_back(candidates[i]);
//			backtracking(candidates, target, path, sum + candidates[i], i);//因为可以重复利用元素，i不用+1往下传
//			path.pop_back();
//		}
//	}
//};
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
////40. 组合总和 II
//class Solution {
//public:
//	vector<vector<int>> reslut;
//	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//		vector<int> path;
//		sort(candidates.begin(), candidates.end());
//		backtracking(candidates, target, path, 0, 0);
//
//		return reslut;
//	}
//	void backtracking(vector<int>& candidates, int target, vector<int>& path, int sum, int index)
//	{
//		if (sum == target)
//		{
//			reslut.push_back(path);
//			return;
//		}
//		if (sum>target || index >= candidates.size())
//			return;
//
//		int prev = candidates[index];
//		for (int i = index; i<candidates.size(); ++i)
//		{
//			if (i != index && prev == candidates[i])
//				continue;
//			prev = candidates[i];
//			path.push_back(candidates[i]);
//			backtracking(candidates, target, path, sum + candidates[i], i + 1);
//			path.pop_back();
//		}
//	}
//};
//
////反转链表——
//list_node* reverse(list_node* head, list_node* end)
//{
//	list_node* cur = head, *prev = nullptr;
//	while (cur != end)
//	{
//		list_node* tmp = cur->next;
//		cur->next = prev;
//		prev = cur;
//		cur = tmp;
//	}
//	return prev;
//}
////部分反转
//list_node * reverse_list(list_node * head, int L, int R)
//{
//	list_node* phead = new list_node;
//	phead->next = head;
//	list_node* cur = phead, *left = phead, *right = phead, *leftprev = phead, *rightnext = phead;
//	while (L--)
//	{
//		leftprev = left;
//		left = left->next;
//	}
//	while (R--)
//	{
//		right = right->next;
//	}
//	rightnext = right->next;
//	list_node* newhead = reverse(left, rightnext);
//	leftprev->next = newhead;
//	left->next = rightnext;
//	return phead->next;
//}

//131. 分割回文串
class Solution {
public:
	vector<vector<string>> reslut;

	vector<vector<string>> partition(string s) {
		vector<string> path;

		backtracking(path, s, 0);
		return reslut;
	}
	void backtracking(vector<string>& path, string&s, int index)
	{
		if (index == s.size())
		{
			reslut.push_back(path);
			return;
		}
		string str;
		for (int i = index; i<s.size(); ++i)
		{
			str += s[i];
			if (!ispalindrome(s, index, i))
				continue;
			path.push_back(str);
			backtracking(path, s, i + 1);
			path.pop_back();
		}

	}

	bool ispalindrome(string& s, int begin, int end)
	{
		while (begin<end)
		{
			if (s[begin++] != s[end--])
				return false;
		}
		return true;
	}
};


#include <stdio.h>
int main()
{
	//vector<int> v;
	//v.push_back(1);
	//Solution s;
	//s.combinationSum2(v, 2);
	char arr[10];
	scanf("%s", arr);
	printf("%s", arr);
	return 0;
}
