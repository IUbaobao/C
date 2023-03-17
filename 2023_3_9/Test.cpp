#include "bit_set.h"
#include "BloomFilter.h"

//int main()
//{
//	//test_twobitset();
//	hdm::test_bloomfilter2();
//	return 0;
//}




//�ڳ��� 2N ���������ҳ��ظ� N �ε�Ԫ��
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

//��������Ľ���
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
////��������Ľ��� II
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

//���仰�еĲ���������
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

//��дһ���㷨���ж�һ���� n �ǲ��ǿ�������
//
//����������?����Ϊ��
//
//����һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���͡�
//Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1��
//���������� ���Ϊ?1����ô��������ǿ�������
//��� n �� ������ �ͷ��� true �����ǣ��򷵻� false ��
//�������ǵ�̽�������ǲ²�����������ֿ��ܡ�
//
//���ջ�õ�
//1
//1��
//���ջ����ѭ����
//ֵ��Խ��Խ�����ӽ������
//����
//3
//3 λ�������֣��������ܴ���
//243
//243������ζ����Ҫô������
//243
//243 ���µ�ѭ���ڣ�Ҫô����
//1
//1��
//4
//4 λ��
//4
//4 λ���ϵ�������ÿһ�����ᶪʧһλ��ֱ������
//3
//3 λΪֹ����������֪�����������£��㷨���ܻ���
//243
//243 ���µ�����������ѭ����Ȼ��ص����Ѿ�������һ��ѭ�����߻ص�
//1
//1���������������ڵؽ�����ȥ�����������ų�������ѡ��

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
////����֮��
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


////����֮��
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
////����֮��
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
////������� II
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
////�����
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
////�����������ֵ---��������
//class Solution {
//public:
//	deque<int> dq;
//	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//		vector<int> v;
//		int n = 0;
//		//�Ƚ�k��Ԫ��
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
//		//�����һ�鴰�ڵ�max
//		v.push_back(getmax());
//		return v;
//	}
//
//	void pop(int val)
//	{
//		//Ҫɾ��Ԫ���뵥������ͷ��Ȳ�pop
//		if (val == dq.front())
//		{
//			dq.pop_front();
//		}
//	}
//
//	void push(int val)
//	{
//		//��֤���Ԫ���ڶ��ף���valС��ȫ��pop
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


//��������
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
//			//����ո��"���ڵ����
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



//��ʯ��---��̬�滮
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
//	vector<int> step(m + 1, INT_MAX);//INT_MAX��ʾ���ɵ����λ��
//	step[n] = 0;//��ʼ��ԭλ
//	for (int i = n; i <= m; ++i)
//	{
//		if (step[i] == INT_MAX)
//			continue;
//		vector<int> divisor;
//		getdivisor(divisor, i);
//		for (int j = 0; j<divisor.size(); ++j)
//		{
//			//��λ�ô��ھ�Ҫ��Сֵ
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
////���˵Ĵ���--����
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
//		else//����û1
//		{
//			break;
//		}
//		//����
//		sum -= v[i];
//		multi /= v[i];
//		//ȥ��
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
//	int n, m, x = -1, t = 0, k; //ע����Ϊ�����±꣬x Ҫ-1
//	int a[6] = { 0 };  //�������ж��Ƿ����
//	scanf("%d %d", &n, &m);
//	while (t != n){  //���n��ֵ
//		k = m;
//		while (k){
//			x = (x + 1) % n;
//			while (a[x] != 0)
//				x = (x + 1) % n; //ÿ����һ������Ҫ+1
//			k--;
//		}
//		printf("%d ", x + 1);
//		a[x] = 1; //����Ѿ�����
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
//	int n;//��ʾ����������
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
//		//��������
//		vector<string> reslut1;//����ֱ������
//		vector<string> reslut2;//���ͺ��
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




#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


//int main()
//{
//	cout << ("6666" < "Lisi" )<< endl;
//}

bool compare(const pair<string, string>& s1, const pair<string, string> &s2)
{
	size_t left = atoi(s1.second.c_str());
	size_t right = atoi(s2.second.c_str());
	if (s1.first < s2.first)
		return true;
	else if (s1.first == s2.first && left < right)
		return true;
	else
		return false;
}


int main()
{
	int n;
	cin >> n;
	for (int t = 0; t < n; ++t)
	{
		fflush(stdin);
		int k;
		cin >> k;
		vector<pair<string,string>> vs1(k);
		fflush(stdin);
		for (int i = 0; i < k; ++i)
		{
			string str1, str2;
			cin >> str1 >> str2;
			vs1[i] = make_pair(str2, str1);
		}
		sort(vs1.begin(), vs1.end(), compare);
		int x;
		cin >> x;
		unordered_map<int, int> countmap;
		for (int i = 0; i < x; ++i)
		{
			int y;
			cin >> y;
			countmap[y]++;
		}
		int i = 1;
		vector<string> vs;

		int count = 0;
		if (t != 0)
			cout << endl << endl;;
		cout << "Case " << t + 1 << ":" << endl;
		for (auto e : vs1)
		{
			if (countmap[i] != 0)
			{
				vs.push_back(e.second + " " + e.first);
			}
			else
			{
				printf("%03d:", i);
				cout << e.second << " " << e.first << endl;
				count++;
			}
			++i;
		}
		for (auto e : vs)
		{
			if (countmap[i] == 0)
			{
				printf("%03d:", i);
				count++;
				cout << e;
				if (count != k)
					cout << endl;

			}
			++i;
		}

	}
	return 0;
}
