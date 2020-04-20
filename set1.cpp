#include <iostream>
#include <set>
using namespace std;
/*
关联容器:利用键值对
key
value

set是一种利用平衡二叉树
实现一个只有值得关联容器

set容器中的值绝对是唯一而且有序
与它对应另一个关联容器multiset
multiset容器中的元素是可以重复出现
*/
//定义排序类型
class CMP
{
  public:
  	bool  operator ()(int a,int b)
  	{
  		//return (a<b);
  		return a>b;
  	}
};

void output(set<int> s)
{
	set<int>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<"\t";
	}
	cout<<endl;
}
void output(set<int,CMP> s)
{
	set<int,CMP>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<"\t";
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	set<int> s1;
	s1.insert(20);
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(80);
	s1.insert(60);
	// pair<set<int>::iterator,bool> p
	// =s1.insert(400);
	// if(p.second)
	// {
	// 	cout<<*(p.first);
	// }
	// else
	// {
	// 	cout<<"insert fail\n";
	// }
	//set<int> s2(s1.begin(),s1.end());
	// int a[]={1,5,3,0,9};
	// set<int> s2(a,a+5);

    int a[]={1,5,3,0,9};
	set<int,CMP> s3(a,a+5);
	//output(s3);
    set<int,CMP> s4;
    s4.insert(101);
    s4.insert(90);
    s4.insert(13);
    s4.insert(67);
    s4.insert(73);
    output(s4);
	return 0;
}