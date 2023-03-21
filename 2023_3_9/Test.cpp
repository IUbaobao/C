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
//#include <iostream>
//#include <vector>
//#include <limits.h>
//#include <math.h>
//using namespace std;
//
//void getdivisor(vector<int>& v, int n)
//{
//	for (int i = 2; i <= sqrt(n); ++i)
//	{
//		if (n%i == 0)
//		{
//			v.push_back(i);
//			if (n / i != i)
//			{
//				v.push_back(n / i);
//			}
//		}
//	}
//}
//
//int jump(int n, int m)
//{
//	vector<int> step(m + 1, INT_MAX);//INT_MAX表示不可到达的位置
//	step[n] = 0;//初始化原位
//	for (int i = n; i <= m; ++i)
//	{
//		if (step[i] == INT_MAX)
//			continue;
//		vector<int> divisor;
//		getdivisor(divisor, i);
//		for (int j = 0; j<divisor.size(); ++j)
//		{
//			//该位置存在就要较小值
//			if (divisor[j] + i <= m && step[i + divisor[j]] != INT_MAX)
//			{
//				step[i + divisor[j]] = step[i] + 1< step[i + divisor[j]] ? step[i] + 1 : step[i + divisor[j]];
//			}
//			else if (i + divisor[j] <= m)
//			{
//				step[i + divisor[j]] = step[i] + 1;
//			}
//
//		}
//	}
//	return step[m] == INT_MAX ? -1 : step[m];
//
//}
//
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	cout << jump(n, m) << endl;
//	return 0;
//}
//
//
////幸运的袋子--回溯
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int Backtracking(vector<int>& v, int n, int index, int sum, int multi)
//{
//	int count = 0;
//	for (int i = index; i<n; ++i)
//	{
//		sum += v[i];
//		multi *= v[i];
//		if (sum>multi)
//		{
//			count += 1 + Backtracking(v, n, i + 1, sum, multi);
//		}
//		else if (v[i] == 1)
//		{
//			count += Backtracking(v, n, i + 1, sum, multi);
//		}
//		else//后面没1
//		{
//			break;
//		}
//		//回溯
//		sum -= v[i];
//		multi /= v[i];
//		//去重
//		while (i<n && v[i] == v[i + 1])
//			++i;
//	}
//	return count;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v(n);
//	for (int i = 0; i<n; ++i)
//	{
//		cin >> v[i];
//	}
//	sort(v.begin(), v.end());
//	cout << Backtracking(v, n, 0, 0, 1) << endl;
//	return 0;
//}
//
//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//class B :public A
//{
//public:
//	B()
//	{
//		cout << "B()" << endl;
//	}
//	~B()
//	{
//		cout << "~B()" << endl;
//	}
//};
//
//int main()
//{
//	B* a = new B();
//	delete a;
//	return 0;
//}




//#include <iostream>
//#include <list>
//#include <vector>
//using namespace std;
////3 1 2 6 4 5 
//int main()
//{
//	int n, m, x = -1, t = 0, k; //注意因为数组下标，x 要-1
//	int a[6] = { 0 };  //用数组判断是否出列
//	scanf("%d %d", &n, &m);
//	while (t != n){  //输出n个值
//		k = m;
//		while (k){
//			x = (x + 1) % n;
//			while (a[x] != 0)
//				x = (x + 1) % n; //每出列一个，都要+1
//			k--;
//		}
//		printf("%d ", x + 1);
//		a[x] = 1; //标记已经出列
//		m++;
//		t++;
//	}
//	return 0;
//}

//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//#include <map>
//using namespace std;
//class myless
//{
//public:
//	bool operator()(const string& s1, const string &s2)
//	{
//		size_t left = atoi(s1.c_str());
//		size_t right = atoi(s2.c_str());
//		return left < right;
//	}
//};
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int t = 0; t < n; ++t)
//	{
//		fflush(stdin);
//		int k;
//		cin >> k;
//		map<string, string, myless> ssmap;
//		fflush(stdin);
//		for (int i = 0; i < k; ++i)
//		{
//			string str1, str2;
//			cin >> str1 >> str2;
//			ssmap[str1] = str2;
//		}
//		int x;
//		cin >> x;
//		unordered_map<int, int> countmap;
//		for (int i = 0; i < x; ++i)
//		{
//			int y;
//			cin >> y;
//			countmap[y]++;
//		}
//		int i = 1;
//		vector<string> vs;
//		if (t != 0)
//			cout << endl;
//		cout << "Case " << t + 1 << ":" << endl;
//		for (auto e : ssmap)
//		{
//			if (countmap[i] != 0)
//			{
//				vs.push_back(e.first + " " + e.second);
//			}
//			else
//			{
//				printf("%03d:", i);
//				cout << e.first << " " << e.second << endl;
//			}
//			++i;
//		}
//		for (auto e : vs)
//		{
//			if (countmap[i] == 0)
//			{
//				printf("%03d:", i);
//				cout << e;
//				if (t != n - 1)
//					cout << endl;
//			}
//			++i;
//		}
//
//	}
//	return 0;
//}



//#include <iostream>
//#include <string>
//#include <map>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int n;//表示多少行数据
//	cin >> n;
//	for (int i = 0; i<n; ++i)
//	{
//		map<string, string> map_;
//		map<int, int> countmap;
//		int k;//
//		cin >> k;
//		for (int j = 0; j<k; ++j)
//		{
//			string tmp1, tmp2;
//			cin >> tmp1 >> tmp2;
//			map_[tmp1] = tmp2;
//		}
//		int m;
//		cin >> m;
//		for (int j = 0; j<m; ++j)
//		{
//			int tmp;
//			cin >> tmp;
//			countmap[tmp]++;
//		}
//		//处理数据
//		vector<string> reslut1;//可以直接坐的
//		vector<string> reslut2;//存滞后的
//		int j = 1;
//		auto it = map_.begin();
//		while (it != map_.end())
//		{
//			if (countmap[j] == 0)
//			{
//				reslut1.push_back(it->first + " " + it->second);
//			}
//			else
//			{
//				reslut2.push_back(it->first + " " + it->second);
//			}
//			j++;
//			it++;
//		}
//		for (auto& e : reslut2)
//		{
//			reslut1.push_back(e);
//		}
//		j = 1;
//		if (i != 0)
//			cout << endl;
//		cout << "Case " << i + 1 << ":" << endl;
//		int x = 0;
//		while (x<reslut1.size())
//		{
//			if (countmap[j] == 0)
//			{
//				if (j<10)
//					cout << "00" << j << ":";
//				else if (j<100)
//					cout << "0" << j << ":";
//				else
//					cout << j << ":";
//				cout << reslut1[x];
//				if (!(x == reslut1.size() - 1 && i == n - 1))
//					cout << endl;
//				x++;
//			}
//			j++;
//		}
//	}
//	return 0;
//}


//
//#include<iostream>
//#include <vector>
//#include <map>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	map<int, int >countmap1, countmap2;
//	vector<int> v(n);
//	for (int i = 0; i<n; ++i)
//	{
//		cin >> v[i];
//		countmap1[v[i]]++;
//		countmap2[v[i]]++;
//	}
//	auto it = countmap1.begin();
//	it++;
//	while (it != countmap1.end())
//	{
//		auto tmp = it;
//		--tmp;
//		it->second += (tmp)->second;
//		it++;
//	}
//	for (int i = 0; i<n; ++i)
//	{
//		cout << countmap1[v[i]] - countmap2[v[i]] << " ";
//	}
//
//	return 0;
//}



//
//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//using namespace std;
//
//
////int main()
////{
////	cout << ("6666" < "Lisi" )<< endl;
////}
//
//bool compare(const pair<string, string>& s1, const pair<string, string> &s2)
//{
//	size_t left = atoi(s1.second.c_str());
//	size_t right = atoi(s2.second.c_str());
//	if (s1.first < s2.first)
//		return true;
//	else if (s1.first == s2.first && left < right)
//		return true;
//	else
//		return false;
//}
//
//
//int main()
//{
//	int n;
//	cin >> n;
//	for (int t = 0; t < n; ++t)
//	{
//		fflush(stdin);
//		int k;
//		cin >> k;
//		vector<pair<string,string>> vs1(k);
//		fflush(stdin);
//		for (int i = 0; i < k; ++i)
//		{
//			string str1, str2;
//			cin >> str1 >> str2;
//			vs1[i] = make_pair(str2, str1);
//		}
//		sort(vs1.begin(), vs1.end(), compare);
//		int x;
//		cin >> x;
//		unordered_map<int, int> countmap;
//		for (int i = 0; i < x; ++i)
//		{
//			int y;
//			cin >> y;
//			countmap[y]++;
//		}
//		int i = 1;
//		vector<string> vs;
//
//		int count = 0;
//		if (t != 0)
//			cout << endl << endl;;
//		cout << "Case " << t + 1 << ":" << endl;
//		for (auto e : vs1)
//		{
//			if (countmap[i] != 0)
//			{
//				vs.push_back(e.second + " " + e.first);
//			}
//			else
//			{
//				printf("%03d:", i);
//				cout << e.second << " " << e.first << endl;
//				count++;
//			}
//			++i;
//		}
//		for (auto e : vs)
//		{
//			if (countmap[i] == 0)
//			{
//				printf("%03d:", i);
//				count++;
//				cout << e;
//				if (count != k)
//					cout << endl;
//
//			}
//			++i;
//		}
//
//	}
//	return 0;
//}



//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<vector<int>> vv(n, vector<int>(2*n-1, 0));
//	vv[0][n-1] = 1;
//	for (int i = 1; i < n; ++i)
//	{
//		int j = n - i - 1;
//		int k = 0; 
//		while (k<(2 * (i+1) - 1))
//		{
//			if (i == 4)
//				int z = 0;
//			if (j!=0 && j!=2*n-2)
//				vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1] + vv[i - 1][j + 1];
//			else if (j == 0)
//				vv[i][j] =1;
//			else
//				vv[i][j] = 1;
//			k++;
//			j++;
//		}
//	}
//	for (int i = 0; i < 2 * n - 1; ++i)
//	{
//		if (vv[n - 1][i] % 2 == 0)
//		{
//			cout << i+1 << endl;;
//			return 0;
//		}
//	}
//	cout << "-1" << endl;
//	return 0;
//}



//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票全价" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票半价" << endl;
//	}
//};
//
//void Func(Person& people)
//{
//	people.BuyTicket();
//}
//
//void Test()
//{
//	Person zhangsan;
//	Func(zhangsan);
//
//	Student John;
//	Func(John);
//	John.BuyTicket();
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//void Func(Person* p)
//{
//	p->BuyTicket();
//}
//int main()
//{
//	Person zhangshan;
//	Func(&zhangshan);
//	mike.BuyTicket();
//	return 0;
//}
//// 以下汇编代码中跟你这个问题不相关的都被去掉了
//void Func(Person* p)
//{
//	...
//		p->BuyTicket();
//	// p中存的是zhangshan对象的指针，将p移动到eax中
//		001940DE mov eax, dword ptr[p]
//		// [eax]就是取eax值指向的内容，这里相当于把zhangshan对象头4个字节(虚表指针)移动到了edx
//		001940E1 mov edx, dword ptr[eax]
//		// [edx]就是取edx值指向的内容，这里相当于把虚表中的头4字节存的虚函数指针移动到了eax
//		00B823EE mov eax, dword ptr[edx]
//		// call eax中存虚函数的指针。这里可以看出满足多态的调用，不是在编译时确定的，是运行起来
//		//以后到对象的中取找的。
//		001940EA call eax
//		00头1940EC cmp esi, esp
//}
//int main()
//{
//	...
//		// 首先BuyTicket虽然是虚函数，但是zhangshan是对象，不满足多态的条件，所以这里是普通函数的调
//		//用转换成地址时，是在编译时已经从符号表确认了函数的地址，直接call 地址
//		mike.BuyTicket();
//		00195182 lea ecx, [mike]
//		00195185 call Person::BuyTicket(01914F6h)
//		...
//}



//
//class Person {
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person {
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//	/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，虽然也可以构成重写(因
//	为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),但是该种写法不是很规范，不建议
//	这样使用*/
//	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
//};
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	return 0;
//}
//

//协变
//class A{};
//class B : public A {};
//class Person 
//{
//public:
//	virtual A* f() 
//	{ 
//		return new A; 
//	}
//};
//class Student : public Person 
//{
//public:
//	virtual B* f() //函数名和参数要一样,返回类型要是派生类对象的指针或者引用
//	{ 
//		return new B; 
//	}
//};

//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函
////数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}
//#include <string>
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	int i = 0, j = 0;
//	while (i < s1.size() && j < s2.size())
//	{
//		if (s1[i] == '*')
//		{
//			if (s1[i + 1] == s2[j])
//				++i;
//			else
//				++j;
//		}
//		else if (s1[i] == '?')
//		{
//			++i;
//			++j;
//		}
//		else
//		{
//			if (islower(s1[i]) && !islower(s2[j]))
//				s1[i] -= 32;
//			else if (islower(s2[j]) && !islower(s1[i]))
//				s2[i] -= 32;
//			if (s1[i] != s2[j])
//			{
//				cout << "false" << endl;
//				return 0;
//			}
//			++i;
//			++j;
//		}
//	}
//	if (j<s2.size())
//		cout << "false" << endl;
//	else
//		cout << "true" << endl;
//	return 0;
//}
//
//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};

//
//class Car{
//public:
//	virtual void Drive(){}
//};
//class Benz :public Car {
//public:
//	//没有构成重写会报错
//	virtual void Drive(int x) override 
//	{ cout << "Benz-舒适" << endl; }
//};
//
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-操控" << endl;
//	}
//};
//void Test()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//}
//
//// 这里常考一道笔试题：sizeof(Base)是多少？
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//	Base b;
//	return 0;
//}



// 针对上面的代码我们做出以下改造
// 1.我们增加一个派生类Derive去继承Base
// 2.Derive中重写Func1
// 3.Base再增加一个虚函数Func2和一个普通函数Func3
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Base::Func1()" << endl;
//	}
//	virtual void Func2()
//	{
//		cout << "Base::Func2()" << endl;
//	}
//	void Func3()
//	{
//		cout << "Base::Func3()" << endl;
//	}
//private:
//	int _b = 1;
//};
//class Derive : public Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Derive::Func1()" << endl;
//	}
//private:
//	int _d = 2;
//};

//class A
//{
//	A()
//	{}
//};

//class B : public A
//{
//public:
//	B()
//	{}
//};

//int main()
//{
//	int a = 1;
//	cout << "栈:" << &a << endl;
//
//	int* b = new int;
//	cout << "堆：" << b << endl;
//
//
//	const char* str = "abc";
//	cout << "代码段/常量区：" << (void*)str << endl;
//
//	static int c = 1;
//	cout << "静态区/数据段:" << &c << endl;
//
//	Base be;
//	cout << "虚表:" << (void*)(*(int*)&(be)) << endl;
//
//	return 0;
//}



//class Base {
//public:
//	virtual void func1() { cout << "Base::func1" << endl; }
//	virtual void func2() { cout << "Base::func2" << endl; }
//private:
//	int a;
//};
//class Derive :public Base {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//	virtual void func4() { cout << "Derive::func4" << endl; }
//private:
//	int b;
//};
//
//typedef void(*VFPTR) ();
//
//void printBTable(VFPTR vTable[])
//{
//	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
//	cout << "虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf("第%d个虚函数地址：0x%x->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}

//int main()
//{
//	Base B;
//	Derive D;
//	// 思路：取出b、d对象的头4bytes，就是虚表的指针，前面我们说了虚函数表本质是一个存虚函数
//	//指针的指针数组，这个数组最后面放了一个nullptr
//	// 1.先取b的地址，强转成一个int*的指针
//	// 2.再解引用取值，就取到了b对象头4bytes的值，这个值就是指向虚表的指针
//	// 3.再强转成VFPTR*，因为虚表就是一个存VFPTR类型(虚函数指针类型)的数组。
//	// 4.虚表指针传递给PrintVTable进行打印虚表
//	// 5.需要说明的是这个打印虚表的代码经常会崩溃，因为编译器有时对虚表的处理不干净，虚表最
//	//后面没有放nullptr，导致越界，这是编译器的问题。我们只需要点目录栏的 - 生成 - 清理解决方案，再
//	//编译就好了。
//	VFPTR* vTableb = (VFPTR*)(*((int*)&B));
//	printBTable(vTableb);
//
//	VFPTR* vTabled = (VFPTR*)(*((int*)&D));
//	printBTable(vTabled);
//	return 0;
//}
//
//
//class Base1 {
//public:
//	virtual void func1() { cout << "Base1::func1" << endl; }
//	virtual void func2() { cout << "Base1::func2" << endl; }
//private:
//	int b1;
//};
//class Base2 {
//public:
//	virtual void func1() { cout << "Base2::func1" << endl; }
//	virtual void func2() { cout << "Base2::func2" << endl; }
//private:
//	int b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//	virtual void func1() { cout << "Derive::func1" << endl; }
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:
//	int d1;
//};
//typedef void(*VFPTR) ();
//void PrintVTable(VFPTR vTable[])
//{
//	cout << " 虚表地址>" << vTable << endl;
//	for (int i = 0; vTable[i] != nullptr; ++i)
//	{
//		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
//		VFPTR f = vTable[i];
//		f();
//	}
//	cout << endl;
//}
//int main()
//{
//	Base1 b1;
//	Base2 b2;
//	Derive d;
//	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTableb1);
//	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
//	PrintVTable(vTableb2);
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class A{
//public:
//	A(char *s) { cout << s << endl; }
//	~A(){}
//};
////class B :virtual public A
//class B : public A
//
//{
//public:
//	B(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
////class C :virtual public A
//class C :public A
//{
//public:
//	C(char *s1, char*s2) :A(s1) { cout << s2 << endl; }
//};
//class D :public B, public C
//{
//public:
//	D(char *s1, char *s2, char *s3, char *s4) :C(s1, s3),B(s1, s2)
//	{
//		cout << s4 << endl;
//	}
//};
//int main() {
//	D *p = new D("class A", "class B", "class C", "class D");
//	delete p;
//	return 0;
//}


//class Base1 { public: int _b1; };
//class Base2 { public: int _b2; };
//class Derive : public Base1, public Base2 { public: int _d; };
//int main(){
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	return 0;
//}
//class A
//{
//public:
//	void func(int val = 1){ std::cout << "A->" << val << std::endl; }
//	virtual void test(){ func(); }
//};
//class B : public A
//{
//public:
//	void func(int val = 0){ std::cout << "B->" << val << std::endl; }
//};
//int main(int argc, char* argv[])
//{
//	A*p = new B;
//	p->test();
//	return 0;
//}
//
//公共子串计算
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	string s1, s2;
//	cin >> s1 >> s2;
//	int maxcount = 0;
//
//	int i = 0, j = 0, previ = 0, prevj = 0;
//	while (i < s1.size())
//	{
//		previ = i;
//		j = 0;
//		while (j < s2.size())
//		{
//			prevj = j;
//			i = previ;
//			int count = 0;
//			while (j < s2.size())
//			{
//				if (s1[i] == s2[j])
//				{
//					count++;
//					++i;
//					++j;
//				}
//				else
//					break;
//			}
//			if (count > maxcount)
//				maxcount = count;
//			j = prevj + 1;
//		}
//		i = previ + 1;
//	}
//	cout << maxcount << endl;
//	return 0;
//}



//
//#include <iostream>
//#include <string>
//#include <deque>
//using namespace std;
//
//int main()
//{
//	int n;
//	deque<int> dq;
//	cin >> n;
//
//	for (int i = 0; i < n; ++i)
//	{
//		dq.push_back(i + 1);
//	}
//	string s;
//	cin >> s;
//	int k = 1;
//	for (size_t i = 0; i<s.size(); ++i)
//	{
//		if (s[i] == 'U')
//		{
//			if (k == 1)
//			{
//				if (n>4)
//				{
//					dq.clear();
//					dq = { n - 3, n - 2, n - 1, n };
//
//				}
//				k = n;
//			}
//			else
//			{
//				if (k==dq.front())
//				{
//					dq.pop_back();
//					dq.push_front(dq.front() - 1);
//				}
//				k -= 1;
//
//
//			}
//		}
//		else//D
//		{
//			if (k == n)
//			{
//				if (n>4)
//				{
//					dq.clear();
//					dq = { 1, 2, 3, 4 };
//				}
//				k = 1;
//			}
//			else
//			{
//				if (k==dq.back())
//				{
//					dq.pop_front();
//					dq.push_back(dq.back() + 1);
//				}
//				k += 1;
//			}
//		}
//	}
//	while (!dq.empty())
//	{
//		cout << dq.front() << " ";
//		dq.pop_front();
//	}
//	cout << endl;
//	cout << k << endl;
//	return 0;
//}
//洗牌
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void shuffle(vector<int>& left, vector<int>& right, int k, int n)
{
	if (k == 0)
		return;
	vector<int> sum(left.size() + right.size());
	int i = left.size() - 1, j = right.size() - 1, z = 0;
	while (i >= 0 && j >= 0)
	{
		sum[z++] = right[j--];
		sum[z++] = left[i--];
	}
	if (k == 1)
	{
		for (int i = sum.size() - 1; i >= 0; --i)
		{
			cout << sum[i] << " ";
		}
		cout << endl;
	}
	i = 0;
	left.clear();
	right.clear();
	while (i<sum.size())
	{
		if (i<n)
			right.push_back(sum[i]);
		else
			left.push_back(sum[i]);
		++i;
	}
	reverse(left.begin(), left.end());
	reverse(right.begin(), right.end());
	shuffle(left, right, k - 1, n);
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i<t; ++i)
	{
		int n, k;
		cin >> n >> k;
		vector<int> left(n), right(n);
		for (int j = 0; j<n; ++j)
			cin >> left[j];
		for (int j = 0; j<n; ++j)
			cin >> right[j];
		shuffle(left, right, k, n);
	}
	return 0;
}









