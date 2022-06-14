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
		worker.m_name = "员工";
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
	cout<< "策划部门:" << endl;
	multimap<int, Worker>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名" << pos->second.m_name << "工资" << pos->second.m_salary << endl;
	}
	cout << "----------------------------------" << endl;
	cout << "美术" << endl;
	 pos = m.find(MEISHU);
	 count= m.count(MEISHU);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名" << pos->second.m_name << "工资" << pos->second.m_salary << endl;
	}
	cout << "----------------------------------" << endl;
	cout << "研发:" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名" << pos->second.m_name << "工资" << pos->second.m_salary << endl;
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
