#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <fstream>
#include <sstream>
#include <istream>
#include <set>
#define NUM_OF_REQ 100000
using namespace std;

//This function reads "vms.txt", get all the unique values in id,sub,etc., then randomly produce requests according to those values, and write the request into "request.txt"
int main()
{
	ifstream txtIn("vms.txt", ios::in);
	set<string> id;
	set<string> sub;
	set<string> act;
	set<string> res;
	set<string> con;
	set<string> eff;
	
	string i, s, a, r, c, e;
	while(txtIn >> i >> s >> a >> r >> c >> e)
	{
		id.insert(i);
		sub.insert(s);
		act.insert(a);
		res.insert(r);
		con.insert(c);
		eff.insert(e);
	}
	
	cout<<"id size: "<<id.size()<<endl;
	cout<<"sub size: "<<sub.size()<<endl;
	cout<<"act size: "<<act.size()<<endl;
	cout<<"res size: "<<res.size()<<endl;
	cout<<"con size: "<<con.size()<<endl;
	cout<<"eff size: "<<eff.size()<<endl;
	
	
	set<string>::iterator iter=act.begin();  
	
	ofstream fout("../data/txts/request.txt");
	if(!fout)
		cout<<"Failed to write into txt"<<endl;
	int k=0,j;
	int rad;
	srand(time(NULL));
	while(k<NUM_OF_REQ)
	{
		k++;
		j=0;		
		rad=rand()%sub.size();
		iter=sub.begin();
		while(j<rad)
		{
			iter++;
			j++;
		}
		fout<<*iter<<" ";
		
		j=0;
		rad=rand()%act.size();
		iter=act.begin();
		while(j<rad)
		{
			iter++;
			j++;
		}
		fout<<*iter<<" ";
		
		j=0;
		rad=rand()%res.size();
		iter=res.begin();
		while(j<rad)
		{
			iter++;
			j++;
		}
		fout<<*iter<<" ";
		
		j=0;
		rad=rand()%con.size();
		iter=con.begin();
		while(j<rad)
		{
			iter++;
			j++;
		}
		fout<<*iter<<" ";
		
		j=0;
		rad=rand()%eff.size();
		iter=eff.begin();
		while(j<rad)
		{
			iter++;
			j++;
		}
		fout<<*iter<<" ";
	}
	cout<<""<<endl;
	txtIn.close();
	fout.close();
	cout<<NUM_OF_REQ<<" requests are successfully written!"<<endl;
	return 0;
}
