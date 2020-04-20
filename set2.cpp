#include <iostream>
#include <set>
#include <string.h>
using namespace std;
//容器中存放自定义类型



class student
{
friend 
ostream& operator <<(ostream& out,student s)
;
friend bool operator <(student s1,student s2);
public:	
	student(int _sid,const char* _name)
	{
		sid=_sid;
		strcpy(name,_name);
	}

	bool operator ==(const student s)
	{
		return this->sid==s.sid;
	}
private:
	int sid;
	char name[20];
};

ostream& operator <<(ostream& out,student s)
{
	out<<s.sid<<"\t"<<s.name<<endl;
	return out;
}
//只能是友元方式重载
bool operator <(student s1,student s2)
{
	return s1.sid<s2.sid;
}



struct CMP
{
	bool  operator ()(student s1,student s2)
	{
		return !(s1<s2);
	}
};

void output(set<student> s)
{
	set<student>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<"\t";
	}
	cout<<endl;
}

void output(set<student,CMP> s)
{
	set<student,CMP>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<"\t";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	// set<student> s1;
	// s1.insert(student(123,"s123"));
	// s1.insert(student(124,"s124"));
	// s1.insert(student(127,"s125"));
	// s1.insert(student(126,"s126"));
	// s1.insert(student(122,"s127"));
	// pair<set<student>::iterator,bool> p
	// =s1.insert(student(122,"s127"));
	// if(!p.second)
	// 	cout<<"insert fail\n";
	// output(s1);

	set<student,CMP> s1;
	s1.insert(student(123,"s123"));
	s1.insert(student(124,"s124"));
	s1.insert(student(127,"s125"));
	s1.insert(student(126,"s126"));
	s1.insert(student(122,"s127"));
	output(s1);
	return 0;
}