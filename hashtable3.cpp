#include <iostream>
#include <vector>
#define N 20
using namespace std;
/*实现键值(key  value)对的hash表*/
//定义键值对类型
template <class T1,class T2>
class keyvalue
{
friend ostream& operator <<(ostream& out,keyvalue<int,string> v);
public:
	T1 key;
	T2 value;
};
ostream& operator <<(ostream& out,keyvalue<int,string> v)
{
	out<<v.key<<"\t"<<v.value<<"\t";
	return out;
}
//定义hash表,利用容器存
class hashtable
{
public:
	hashtable()
	{

	}

	int hashkey(string value)
	{
      int sum=0;
      int i=0;
      for(i=0;i<value.length();i++)
      {
      	sum=sum+value[i];
      }
      return sum%N;        
	}

	void  inserttable(int _key, string value)
	{
	  keyvalue<int,string> v;
	  v.key=_key;
	  v.value=value;
      int key=hashkey(v.value);
      table[key].push_back(v);
	}

	pair<bool,vector<keyvalue<int,string> >::iterator>  find(string _value)
	{
	   pair<bool,vector<keyvalue<int,string> >::iterator> ret;
       ret.first=false;
       int key=hashkey(_value);
       if(table[key].size()!=0)
       {
       	vector<keyvalue<int,string> >::iterator it;
       	for(it=table[key].begin();it!=table[key].end();it++)
       	{
       		if((*it).value==_value)
       		{
       			ret.first=true;
       			ret.second=it;
       			break;
       		}
       	}
       }
       return ret;
	}

	void deleteelement(string _value)
	{
		pair<bool,vector<keyvalue<int,string> >::iterator> ret;
		ret=find(_value);
		int key=hashkey(_value);
		if(ret.first)
		{
           table[key].erase(ret.second);
		}
	}

	void  outputelement()
	{
		int i;
		for(i=0;i<N;i++)
		{
			if(table[i].size()>0)
			{
				vector<keyvalue<int,string> >::iterator it;
				for(it=table[i].begin();it!=table[i].end();it++)
				{
					cout<<*it;
				}
				cout<<endl;
			}
		}
	}
private:
	vector<keyvalue<int,string> > table[N];
};


int main(int argc, char const *argv[])
{
	hashtable h1;
	h1.inserttable(1,"abcd");
	h1.inserttable(10,"erter");
	h1.inserttable(11,"7876");
	h1.inserttable(13,"dfgdfg");
	h1.inserttable(18,"vxcv");
	h1.inserttable(19,"432423");
    h1.inserttable(13,"uioiu");
	h1.inserttable(145,"asdas");
	h1.inserttable(190,"enum");
          h1.outputelement();
    h1.deleteelement("asdas1");
    h1.outputelement();
	return 0;
}

//补充:key 唯一性 有序性  只读性
//建议把hash函数写成函数指针,
//在实例化时传递具体函数
//模板类uy