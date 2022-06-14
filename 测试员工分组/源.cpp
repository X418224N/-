#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
#define CEHUA 0
#define MEISHU 1
#define YANFA 2
class Worker {
public:
	string m_name;
	int m_salary;
};
void createperson(vector<Worker>&v)
{
	string nameseed = "abcdefghij";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_name = "Ա��";
		worker.m_name += nameseed[i];
		worker.m_salary = rand() % 10000 + 10000;
		v.push_back(worker);
	}
	
}
void setgroup(vector<Worker>& v, multimap<int, Worker>& m)
{
	for (auto x : v)
	{
		int deptID = rand() % 3;
		m.insert(make_pair(deptID,x));
	}
}
void showwoker(multimap<int, Worker>& m)
{
	cout<< "�߻�����:" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "����" << pos->second.m_name << "����" << pos->second.m_salary << endl;
	}
	cout << "----------------------------------" << endl;
	cout << "����" << endl;
	 pos = m.find(MEISHU);
	 count= m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "����" << pos->second.m_name << "����" << pos->second.m_salary << endl;
	}
	cout << "----------------------------------" << endl;
	cout << "�з�:" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "����" << pos->second.m_name << "����" << pos->second.m_salary << endl;
	}
}
void test01()
{
	vector<Worker>v;
	createperson(v);
	multimap<int, Worker>m;
	setgroup(v,m);
	showwoker(m);
}
int main()
{
	test01();
}
