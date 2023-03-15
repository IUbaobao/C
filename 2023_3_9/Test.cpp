#include "bit_set.h"
#include "BloomFilter.h"

//int main()
//{
//	//test_twobitset();
//	hdm::test_bloomfilter2();
//	return 0;
//}




//在长度 2N 的数组中找出重复 N 次的元素
int repeatedNTimes1(vector<int>& nums) {
	for (int gap = 1; gap <= 3; gap++)
	{
		for (int i = 0; i<nums.size() - gap; i++)
		{
			if (nums[i] == nums[i + gap])
			{
				return nums[i];
			}
		}
	}
	return -1;

}
//
//int repeatedNTimes2(vector<int>& nums) {
//	unordered_set<int > s;
//	for (auto e : nums)
//	{
//		if (s.count(e))
//		{
//			return e;
//		}
//		else
//		{
//			s.insert(e);
//		}
//	}
//	return -1;
//}
//
//int repeatedNTimes3(vector<int>& nums) {
//	unordered_map<int, int > countmap;
//	int x = nums.size() / 2;
//	for (auto e : nums)
//	{
//		countmap[e]++;
//	}
//	for (auto e : nums)
//	{
//		if (countmap[e] == x)
//		{
//			return e;
//		}
//	}
//	return -1;
//}

//两个数组的交集
//vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//	unordered_set<int> s1;
//	unordered_set<int> s2;
//
//	for (auto e : nums1)
//	{
//		s1.insert(e);
//	}
//	for (auto e : nums2)
//	{
//		s2.insert(e);
//	}
//	vector<int> result;
//	for (auto e : s1)
//	{
//		if (s2.count(e))
//		{
//			result.push_back(e);
//		}
//	}
//	return result;
//}
//
////两个数组的交集 II
//vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//	unordered_map<int, int> countmap1;
//	unordered_map<int, int> countmap2;
//
//	for (auto e : nums1)
//	{
//		countmap1[e]++;
//	}
//
//	for (auto e : nums2)
//	{
//		countmap2[e]++;
//	}
//	vector<int> result;
//	for (auto e : countmap1)
//	{
//		if (countmap2[e.first] != 0)
//		{
//			int min = e.second;
//			if (min>countmap2[e.first])
//			{
//				min = countmap2[e.first];
//			}
//			for (int i = 0; i<min; i++)
//			{
//				result.push_back(e.first);
//			}
//		}
//	}
//	return result;
//}

//两句话中的不常见单词
//class Solution {
//public:
//	vector<string> uncommonFromSentences(string s1, string s2) {
//		unordered_map<string, int> countmap1;
//		unordered_map<string, int> countmap2;
//		_uncommonFromSentences(s1, countmap1);
//		_uncommonFromSentences(s2, countmap2);
//		vector<string> result;
//		for (auto &e : countmap1)
//		{
//			if (e.second == 1 && countmap2[e.first] == 0)
//			{
//				result.push_back(e.first);
//			}
//		}
//		for (auto &e : countmap2)
//		{
//			if (e.second == 1 && countmap1[e.first] == 0)
//			{
//				result.push_back(e.first);
//			}
//		}
//		return result;
//	}
//
//	void _uncommonFromSentences(string &s1, unordered_map<string, int>& countmap1)
//	{
//		string ch;
//		for (int i = 0; i <= s1.size(); ++i)
//		{
//			if (i == s1.size())
//			{
//				countmap1[ch]++;
//				ch.clear();
//				break;
//			}
//			if (s1[i] == ' ')
//			{
//				countmap1[ch]++;
//				ch.clear();
//				continue;
//			}
//			ch += s1[i];
//		}
//	}
//};

//编写一个算法来判断一个数 n 是不是快乐数。
//
//「快乐数」?定义为：
//
//对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
//然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//如果这个过程 结果为?1，那么这个数就是快乐数。
//如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
//根据我们的探索，我们猜测会有以下三种可能。
//
//最终会得到
//1
//1。
//最终会进入循环。
//值会越来越大，最后接近无穷大。
//对于
//3
//3 位数的数字，它不可能大于
//243
//243。这意味着它要么被困在
//243
//243 以下的循环内，要么跌到
//1
//1。
//4
//4 位或
//4
//4 位以上的数字在每一步都会丢失一位，直到降到
//3
//3 位为止。所以我们知道，最坏的情况下，算法可能会在
//243
//243 以下的所有数字上循环，然后回到它已经到过的一个循环或者回到
//1
//1。但它不会无限期地进行下去，所以我们排除第三种选择。

//
//
//bool isHappy(int n) {
//	unordered_set<int> s;
//	int num = n;
//	while (1)
//	{
//		int sum = 0;
//		while (n)
//		{
//			sum += ((n % 10)*(n % 10));
//			n /= 10;
//		}
//		if (sum == 1)
//		{
//			return true;
//		}
//		if (s.count(sum))
//		{
//			return false;
//		}
//		else
//		{
//			s.insert(sum);
//		}
//		n = sum;
//	}
//}
//
//
//
////两数之和
//vector<int> twoSum(vector<int>& nums, int target) {
//	unordered_map<int, int> summap;
//	for (int i = 0; i<nums.size(); ++i)
//	{
//		summap[nums[i]] = i + 1;
//	}
//	for (int i = 0; i<nums.size(); ++i)
//	{
//		if (summap[target - nums[i]] != 0 && i != summap[target - nums[i]] - 1)
//		{
//			return vector<int> {i, summap[target - nums[i]] - 1};
//		}
//	}
//	return vector<int> {1, 2};
//}
//


//vector<int> twoSum(vector<int>& nums, int target) {
//	unordered_map<int, int >map;
//	for (int i = 0; i<nums.size(); ++i)
//	{
//		auto it = map.find(target - nums[i]);
//		if (it != map.end())
//		{
//			return vector<int> {i, it->second};
//		}
//		else
//		{
//			map[nums[i]] = i;
//		}
//	}
//	return vector<int>{};
//}


////三数之和
//#include <algorithm>
//#include <vector>
//vector<vector<int>> threeSum(vector<int>& nums) {
//	int left, right;
//	vector<vector<int>> reslut;
//	sort(nums.begin(), nums.end());
//	for (int i = 0; i<nums.size(); ++i)
//	{
//		if (nums[i]>0)
//			break;
//		if (i>0 && nums[i - 1] == nums[i])
//			continue;
//		left = i + 1;
//		right = nums.size() - 1;
//		while (left<right)
//		{
//			int sum = nums[i] + nums[left] + nums[right];
//			if (sum>0) right--;
//			else if (sum<0) left++;
//			else
//			{
//				reslut.push_back(vector<int> {nums[i], nums[left], nums[right]});
//				while (left<right && nums[right] == nums[right - 1])
//					right--;
//				while (left<right && nums[left] == nums[left + 1])
//					left++;
//				left++;
//				right--;
//			}
//		}
//	}
//	return reslut;
//}
//
//int main()
//{
//	vector<int>v = { 0, 0, 0, 0 };
//	vector<vector<int>> t = threeSum(v);
//	return 0;
//}
//
//
//
//
////四数之和
//vector<vector<int>> fourSum(vector<int>& nums, int target) {
//	vector<vector<int>> result;
//	int left, right;
//	sort(nums.begin(), nums.end());
//	for (int i = 0; i<nums.size(); ++i)
//	{
//		if ((target >= 0 && nums[i]>target))
//			break;
//		if (i>0 && nums[i] == nums[i - 1])
//			continue;
//		for (int j = nums.size() - 1; j>i; --j)
//		{
//			if (j<nums.size() - 1 && nums[j] == nums[j + 1])
//				continue;
//			right = j - 1;
//			left = i + 1;
//			while (left<right)
//			{
//				long long  sum = (nums[i] + (long long)nums[j] + nums[left] + nums[right]);
//				if (sum>target) right--;
//				else if (sum<target) left++;
//				else
//				{
//					result.push_back(vector<int>{nums[i], nums[left], nums[right], nums[j]});
//					while (left<right && nums[right] == nums[right - 1])
//						right--;
//					while (left<right && nums[left] == nums[left + 1])
//						left++;
//					left++;
//					right--;
//				}
//			}
//		}
//	}
//	return result;
//}
//
//
////四数相加 II
//int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
//	unordered_map<int, int > map1;
//
//	for (auto e1 : nums1)
//	{
//		for (auto e2 : nums2)
//		{
//			map1[e1 + e2]++;
//		}
//	}
//	int count = 0;
//	for (auto e3 : nums3)
//	{
//		for (auto e4 : nums4)
//		{
//			int sum = e3 + e4;
//			auto it = map1.find(-sum);
//			if (it != map1.end())
//			{
//				count += it->second;
//			}
//		}
//	}
//	return count;
//
//}
//
////赎金信
//bool canConstruct(string ransomNote, string magazine) {
//	unordered_map<char, int> countmap;
//
//	for (auto e : magazine)
//	{
//		countmap[e]++;
//	}
//	for (auto e : ransomNote)
//	{
//		auto it = countmap.find(e);
//		if (it != countmap.end())
//		{
//			--it->second;
//			if (it->second<0)
//				return false;
//		}
//		else
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//
//
//
////滑动窗口最大值---单调队列
//class Solution {
//public:
//	deque<int> dq;
//	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//		vector<int> v;
//		int n = 0;
//		//先进k个元素
//		while (n<k)
//		{
//			push(nums[n++]);
//		}
//
//		for (int i = k; i<nums.size(); ++i)
//		{
//			v.push_back(getmax());
//			pop(nums[i - k]);
//			push(nums[i]);
//		}
//		//求最后一组窗口的max
//		v.push_back(getmax());
//		return v;
//	}
//
//	void pop(int val)
//	{
//		//要删的元素与单调队列头相等才pop
//		if (val == dq.front())
//		{
//			dq.pop_front();
//		}
//	}
//
//	void push(int val)
//	{
//		//保证最大元素在队首，比val小的全部pop
//		while (!dq.empty() && val>dq.back())
//		{
//			dq.pop_back();
//		}
//		dq.push_back(val);
//	}
//	int getmax()
//	{
//		return dq.front();
//	}
//
//};


//解析参数
//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	string s;
//	getline(cin, s);
//	vector<string> vs;
//	string str;
//	int i = 0;
//	while (i <= s.size())
//	{
//		if (s[i] == ' ')
//		{
//			vs.push_back(str);
//			str.clear();
//			while (s[i] == ' ')
//			{
//				i++;
//			}
//		}
//		else if (s[i] == '"')
//		{
//			while (i<s.size() && s[++i] != '"')
//			{
//				str += s[i];
//			}
//			//处理空格和"相邻的情况
//			while (s[i] == ' ' || s[i] == '"')
//			{
//				i++;
//			}
//			vs.push_back(str);
//			str.clear();
//		}
//		else
//		{
//			str += s[i];
//			++i;
//		}
//		if (i == s.size() && str.size()!=0)
//		{
//			vs.push_back(str);
//		}
//
//	}
//	cout << vs.size() << endl;
//	for (auto& e : vs)
//	{
//		cout << e << endl;
//	}
//	return 0;
//}
//
//



//跳石板---动态规划
#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;

void getdivisor(vector<int>& v, int n)
{
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n%i == 0)
		{
			v.push_back(i);
			if (n / i != i)
			{
				v.push_back(n / i);
			}
		}
	}
}

int jump(int n, int m)
{
	vector<int> step(m + 1, INT_MAX);//INT_MAX表示不可到达的位置
	step[n] = 0;//初始化原位
	for (int i = n; i <= m; ++i)
	{
		if (step[i] == INT_MAX)
			continue;
		vector<int> divisor;
		getdivisor(divisor, i);
		for (int j = 0; j<divisor.size(); ++j)
		{
			//该位置存在就要较小值
			if (divisor[j] + i <= m && step[i + divisor[j]] != INT_MAX)
			{
				step[i + divisor[j]] = step[i] + 1< step[i + divisor[j]] ? step[i] + 1 : step[i + divisor[j]];
			}
			else if (i + divisor[j] <= m)
			{
				step[i + divisor[j]] = step[i] + 1;
			}

		}
	}
	return step[m] == INT_MAX ? -1 : step[m];

}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << jump(n, m) << endl;
	return 0;
}


//幸运的袋子--回溯
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Backtracking(vector<int>& v, int n, int index, int sum, int multi)
{
	int count = 0;
	for (int i = index; i<n; ++i)
	{
		sum += v[i];
		multi *= v[i];
		if (sum>multi)
		{
			count += 1 + Backtracking(v, n, i + 1, sum, multi);
		}
		else if (v[i] == 1)
		{
			count += Backtracking(v, n, i + 1, sum, multi);
		}
		else//后面没1
		{
			break;
		}
		//回溯
		sum -= v[i];
		multi /= v[i];
		//去重
		while (i<n && v[i] == v[i + 1])
			++i;
	}
	return count;
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i<n; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout << Backtracking(v, n, 0, 0, 1) << endl;
	return 0;
}