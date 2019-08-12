// 多机调度问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string"
#include "iostream"
using namespace std;
bool ui=false;
class JobNode
{
public:
	int ID,time;
};
class MachineNode
{
public:
	int ID,avail;
};
void Sort(JobNode *a,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].time<a[j].time)
			{
				int t=a[i].ID;
				int t1=a[i].time;
				a[i].ID=a[j].ID;
				a[i].time=a[j].time;
				a[j].ID=t;
				a[j].time=t1;
			}
		}
	}
}
void Greedy(JobNode *a,MachineNode *b,int n,int m)
{
	if(n<=m)
	{
		ui=true;
		cout<<"为每个作业分配一台机器"<<endl;
		return;
	}
	Sort(a,n);
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(b[0].avail>b[j].avail)
			{
				int t=b[0].ID;
				int t1=b[0].avail;
				b[0].ID=b[j].ID;
				b[0].avail=b[j].avail;
				b[j].ID=t;
				b[j].avail=t1;
			}
		}
	 	cout<<"将机器"<<b[0].ID<<"从"<<b[0].avail<<"到"<<(b[0].avail+a[i].time)<<"的时间段分配给作业"<<a[i].ID<<endl;
		b[0].avail+=a[i].time;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"请输入作业数量：";
	int s;
	cin>>s;
	JobNode *a=new JobNode[s];
	for(int i=0;i<s;i++)
		a[i].ID=i+1;
	cout<<"请依次输入每个作业所需要的时间:";
	for(int i=0;i<s;i++)
		cin>>a[i].time;
	cout<<"请输入机器数量：";
	int s1;
	cin>>s1;
	MachineNode *b=new MachineNode[s1];
	for(int i=0;i<s1;i++)
		b[i].ID=i+1;
	for(int i=0;i<s1;i++)
		b[i].avail=0;
	cout<<endl;
	Greedy(a,b,s,s1);
	cout<<endl;
    for(int j=1;j<s1;j++)
	{
		if(b[0].avail<b[j].avail)
		{
			int t=b[0].ID;
			int t1=b[0].avail;
			b[0].ID=b[j].ID;
			b[0].avail=b[j].avail;
			b[j].ID=t;
			b[j].avail=t1;
		}
	}
	if(!ui)
	{
	    cout<<"最短加工时间为："<<b[0].avail<<endl;
	}else
	{
		Sort(a,s);
		cout<<"最短加工时间为："<<a[0].time<<endl;
	}
	int z;
	cin>>z;
	return 0;
}

