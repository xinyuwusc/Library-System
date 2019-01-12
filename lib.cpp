#include<iostream>
#include<string>
#include<iomanip>
#include <fstream>
#include<time.h>
using namespace std;

//StudentÀà
class Student{
private:
	int tag;              //É¾³ý±ê¼Ç1:ÒÑÉ¾0:Î´É¾   
	string studentno;     //Ñ§ºÅ
	string studentname;   //ÐÕÃû
	string  studentmajor; //×¨Òµ
	string  studentclass; //°à¼¶
	string  studentmobile;//ÊÖ»ú
public:
	Student();
	int gettag();			    //»ñÈ¡É¾³ý±ê¼Ç
	void settag();              //ÉèÖÃÉ¾³ý±ê¼Ç 
	string getno();				//»ñÈ¡Ñ§ºÅ
	void setno(string);			//ÉèÖÃÑ§ºÅ
	string getname();           //»ñÈ¡ÐÕÃû 
	void setname(string);       //ÉèÖÃÐÕÃû
	string getmajor();          //»ñÈ¡×¨Òµ
	void setmajor(string);      //ÉèÖÃ×¨Òµ
	string getclass();          //»ñÈ¡°à¼¶
	void setclass(string);      //ÉèÖÃ°à¼¶
	string getmobile();			//»ñÈ¡ÊÖ»úºÅ
	void setmobile(string);     //ÉèÖÃÊÖ»úºÅ
	void disp();                //Êä³öÑ§ÉúÐÅÏ¢
	~Student();
};

//È±Ê¡¹¹Ôìº¯Êý
Student::Student()
{
	tag=0;
}

//Îö¹¹º¯Êý	
Student::~Student(){}



//»ñÈ¡É¾³ý±ê¼Ç
int Student::gettag()
{
	return tag;
}

//ÉèÖÃÉ¾³ý±ê¼Ç 
void Student::settag()
{
	tag=1;
}

//»ñÈ¡Ñ§ºÅ
string Student::getno()
{
	return studentno;
}

//ÉèÖÃÑ§ºÅ				
void Student::setno(string sno)
{
	studentno=sno;
}

//»ñÈ¡ÐÕÃû
string Student::getname()
{
	return studentname;
}

//ÉèÖÃÐÕÃû
void Student::setname(string sname)
{
	studentname=sname;
}

//»ñÈ¡×¨Òµ
string Student::getmajor()
{
	return studentmajor;
}

//ÉèÖÃ×¨Òµ
void Student::setmajor(string smajor)  
{
	studentmajor=smajor;
}

//»ñÈ¡°à¼¶
string Student::getclass()
{
	return studentclass;
}

//ÉèÖÃ°à¼¶
void Student::setclass(string sclass)
{
	studentclass=sclass;
}

//»ñÈ¡ÊÖ»úºÅ	
string Student::getmobile()
{
	return studentmobile;
}

//ÉèÖÃÊÖ»úºÅ
void Student::setmobile(string smobile)
{
	studentmobile=smobile;
}

//Êä³öÑ§ÉúÐÅÏ¢
void Student::disp()
{
	if(!tag)
	{
		cout<<setw(10)<<studentno<<setw(10)<<studentname<<setw(10)<<studentmajor<<setw(10)<<studentclass<<setw(20)<<studentmobile<<endl;
	}
}



const int Max=100;
class Studentclass{
private:
	int top;
	Student stu[Max];  //Ñ§Éú¼ÇÂ¼
public:
	Studentclass();
	~Studentclass();
    void settop(int n);//ÉèÖÃÈËÊý
	int gettop();      //»ñÈ¡ÈËÊý
	
	//²åÈë
	void stu_append();//²åÈëÒ»¸öÑ§Éú
	//É¾³ýÒ»¸öÑ§Éú
    void deleteno();    //Ñ§ºÅÉ¾³ý
	void deletename();  //ÐÕÃûÉ¾³ý
	void deletemajor(); //×¨ÒµÉ¾³ý
	void deleteclass(); //°à¼¶É¾³ý
	void deletemobile();//ÊÖ»úºÅÉ¾³ý
	void deleteall();   //É¾³ýËùÓÐÑ§ÉúÐÅÏ¢
	
	void insertall();//ÅúÁ¿µ¼Èë
	//²éÑ¯
	void searchno();         //Ñ§ºÅ²éÑ¯
	int searchno(string sno);//Ñ§ºÅ²éÑ¯
	void searchname();       //ÐÕÃû²éÑ¯
	void searchmajor();      //×¨Òµ²éÑ¯
	void searchclass();      //°à¼¶²éÑ¯
	void searchmobile();     //ÊÖ»úºÅ²éÑ¯
	//¸üÐÂ
	void updatename(); //¸üÐÂÐÕÃû
	void updatemajor(); //¸üÐÂ×¨Òµ
	void updateclass(); //¸üÐÂ°à¼¶
	void updatemobile();//¸üÐÂÊÖ»úºÅ
	//Êä³öÑ§ÉúÐÅÏ¢
	void dispall();  //ËùÓÐÑ§Éú
	void disp(int n);//Ò»¸öÑ§Éú

	friend ostream& operator<<(ostream& output,Student& s)
	{
		output<<setw(20)<<s.getno()<<setw(20)<<s.getname()<<setw(20)<<s.getmajor()<<setw(20)<<s.getclass()<<setw(20)<<s.getmobile();
		output<<endl;
		return output;
	}

	friend istream& operator>>(istream& input,Student& s)
	{
		string sno,sname,sclass,smajor,smobile;
		input>>sno;
		s.setno(sno);
		input>>sname;
		s.setname(sname);
		input>>smajor;
		s.setmajor(smajor);
		input>>sclass;
		s.setclass(sclass);
		input>>smobile;
		s.setmobile(smobile);
		return input;
	}
};

//¹¹Ôìº¯Êý¶ÁÈëÑ§ÉúÐÅÏ¢
Studentclass::Studentclass()
{
	top=0;
	ifstream in("student.txt");
	if(!in)
	{
		cout<<"ÎÄ¼þ´ò²»¿ª!"<<endl;
	}
	while(!in.eof())//eof·µ»Ø±êÖ¾ÊÇ·ñµ½ÁËÎÄ¼þÄ©Î²
	{
		in>>stu[top];
		top++;
	}
	in.close();
}

//Îö¹¹º¯ÊýÊä³öÑ§ÉúÐÅÏ¢
Studentclass::~Studentclass()
{
	ofstream out("student.txt");
	if(!out)
	{
		cout<<"ÎÄ¼þ´ò²»¿ª!"<<endl;
	}
	for(int i=0;i<top;i++)
	{
		if(stu[i].gettag()==0)
		{
			out<<stu[i];
		}
	}
	out.close();
}

//ÉèÖÃÈËÊý
void Studentclass::settop(int n)
{
	top=n;
}

//»ñÈ¡ÈËÊý
int Studentclass::gettop()
{
	return top;
}

//²åÈëÒ»¸öÑ§Éú
void Studentclass::stu_append()
{
	string sno,sname,smajor,sclass,smobile;
	cout<<"ÇëÊäÈëÒª²åÈëÑ§ÉúµÄÑ§ºÅ:";
	cin>>sno;
	stu[top].setno(sno);
	cout<<endl;
	cout<<"ÇëÊäÈëÒª²åÈëÑ§ÉúµÄÐÕÃû:";
	cin>>sname;
	stu[top].setname(sname);
	cout<<endl;
	cout<<"ÇëÊäÈëÒª²åÈëÑ§ÉúµÄ×¨Òµ:";
	cin>>smajor;
	stu[top].setmajor(smajor);
	cout<<endl;
	cout<<"ÇëÊäÈëÒª²åÈëÑ§ÉúµÄ°à¼¶:";
	cin>>sclass;
	stu[top].setclass(sclass);
	cout<<endl;
	cout<<"ÇëÊäÈëÒª²åÈëÑ§ÉúµÄÊÖ»úºÅ:";
	cin>>smobile;
	stu[top].setmobile(smobile);
	cout<<endl;
	cout<<"Òª²åÈëµÄÑ§ÉúÐÅÏ¢Îª:"<<endl;
	stu[top].disp();
	cout<<endl;
	top++;
}

//Ñ§ºÅÉ¾³ýÒ»¸öÑ§Éú
void Studentclass::deleteno()
{
	int temp=-1;//ÒªÉ¾³ýµÄÑ§ÉúÏÂ±ê
	string sno;	  
	cout<<"ÇëÊäÈëÒªÉ¾³ýÑ§ÉúµÄÑ§ºÅ:";
	cin>>sno;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getno()==sno)
		{
			temp=i;
			stu[temp].settag();
		}
	}
	if(temp!=-1)
		cout<<"É¾³ýÍê³É!"<<endl<<endl;
	else
		cout<<"Ã»ÓÐÕÒµ½Ñ§ºÅÎª"<<sno<<"µÄÑ§Éú!"<<endl<<endl;
}

//ÐÕÃûÉ¾³ýÒ»¸öÑ§Éú
void Studentclass::deletename()
{
	int temp=-1;//ÒªÉ¾³ýµÄÑ§ÉúÏÂ±ê
	string sname;	  
	cout<<"ÇëÊäÈëÒªÉ¾³ýÑ§ÉúµÄÐÕÃû:";
	cin>>sname;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getname()==sname)
		{
			temp=i;
			stu[temp].settag();
		}
	}
	if(temp!=-1)
		cout<<"É¾³ýÍê³É!"<<endl<<endl;
	else
		cout<<"Ã»ÓÐÕÒµ½ÐÕÃûÎª"<<sname<<"µÄÑ§Éú!"<<endl<<endl;
}

//×¨ÒµÉ¾³ýÒ»¸öÑ§Éú
void Studentclass::deletemajor()
{
	int temp=-1;//ÒªÉ¾³ýµÄÑ§ÉúÏÂ±ê
	string smajor;	  
	cout<<"ÇëÊäÈëÒªÉ¾³ýÑ§ÉúµÄ×¨Òµ:";
	cin>>smajor;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getmajor()==smajor)
		{
			temp=i;
			stu[temp].settag();
		}
	}
	if(temp!=-1)
		cout<<"É¾³ýÍê³É!"<<endl<<endl;
	else
		cout<<"Ã»ÓÐÕÒµ½×¨ÒµÎª"<<smajor<<"µÄÑ§Éú!"<<endl<<endl;
}

//°à¼¶É¾³ýÒ»¸öÑ§Éú
void Studentclass::deleteclass()
{
	int temp=-1;//ÒªÉ¾³ýµÄÑ§ÉúÏÂ±ê
	string sclass;	  
	cout<<"ÇëÊäÈëÒªÉ¾³ýÑ§ÉúµÄ°à¼¶:";
	cin>>sclass;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getclass()==sclass)
		{
			temp=i;
			stu[temp].settag();
		}	
	}
	if(temp!=-1)
		cout<<"É¾³ýÍê³É!"<<endl<<endl;
	else
		cout<<"Ã»ÓÐÕÒµ½°à¼¶Îª"<<sclass<<"µÄÑ§Éú!"<<endl<<endl;
}

//ÊÖ»úºÅÉ¾³ýÒ»¸öÑ§Éú
void Studentclass::deletemobile()
{
	int temp=-1;//ÒªÉ¾³ýµÄÑ§ÉúÏÂ±ê
	string smobile;	  
	cout<<"ÇëÊäÈëÒªÉ¾³ýÑ§ÉúµÄÊÖ»úºÅ:";
	cin>>smobile;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getmobile()==smobile)
		{
			temp=i;
			stu[temp].settag();
		}	
	}
	if(temp!=-1)
		cout<<"É¾³ýÍê³É!"<<endl<<endl;
	else
		cout<<"Ã»ÓÐÕÒµ½ÊÖ»úºÅÎª"<<smobile<<"µÄÑ§Éú!"<<endl<<endl;
}

//ÅúÁ¿µ¼Èë
void Studentclass::insertall()
{
	ifstream in("s.txt");
	if(!in)
	{
		cout<<"ÎÄ¼þ´ò²»¿ª!"<<endl;
	}
	while(!in.eof())
	{
		in>>stu[top];
		top++;
	}
	in.close();
	cout<<"Ñ§ÉúÐÅÏ¢µ¼ÈëÍê³É!"<<endl<<endl;
}

//É¾³ýËùÓÐÑ§ÉúÐÅÏ¢
void Studentclass::deleteall()
{
	for(int i=0;i<top;i++)
	{
		stu[i].settag();
	}
	cout<<"ÒÑÈ«²¿É¾³ý!"<<endl<<endl;
}


//Ñ§ºÅ²éÑ¯
void Studentclass::searchno()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string sno;
	cout<<"ÇëÊäÈëÒª²éÑ¯Ñ§ÉúµÄÑ§ºÅ:";
	cin>>sno;
	cout<<endl;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getno()==sno)
		{
			k=1;
			cout<<"FoundÑ§ºÅÎª"<<sno<<"µÄÑ§Éú!"<<endl<<endl;
			stu[i].disp();
			cout<<endl;
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½Ñ§ºÅÎª"<<sno<<"µÄÑ§Éú!"<<endl<<endl;
}


int Studentclass::searchno(string sno)
{
	int k=-1;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getno()==sno)
			k=i;
	}
	return k;
}
		

//ÐÕÃû²éÑ¯
void Studentclass::searchname()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string sname;
	cout<<"ÇëÊäÈëÒª²éÑ¯Ñ§ÉúµÄÐÕÃû:";
	cin>>sname;
	cout<<endl;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getname()==sname)
		{
			k=1;
			cout<<"FoundÐÕÃûÎª"<<sname<<"µÄÑ§Éú!"<<endl<<endl;
			stu[i].disp();
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½ÐÕÃûÎª"<<sname<<"µÄÑ§Éú!"<<endl<<endl;
}

//×¨Òµ²éÑ¯
void Studentclass::searchmajor()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string smajor;
	cout<<"ÇëÊäÈëÒª²éÑ¯Ñ§ÉúµÄ×¨Òµ:";
	cin>>smajor;
	cout<<endl;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getmajor()==smajor)
		{
			k=1;
			cout<<"Found×¨ÒµÎª"<<smajor<<"µÄÑ§Éú!"<<endl<<endl;
			stu[i].disp();
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½×¨ÒµÎª"<<smajor<<"µÄÑ§Éú!"<<endl<<endl;
}

//°à¼¶²éÑ¯
void Studentclass::searchclass()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string sclass;
	cout<<"ÇëÊäÈëÒª²éÑ¯Ñ§ÉúµÄ°à¼¶:";
	cin>>sclass;
	cout<<endl;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getclass()==sclass)
		{
			k=1;
			cout<<"Found°à¼¶Îª"<<sclass<<"µÄÑ§Éú!"<<endl<<endl;
			stu[i].disp();
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½°à¼¶Îª"<<sclass<<"µÄÑ§Éú!"<<endl<<endl;
}

//ÊÖ»úºÅ²éÑ¯
void Studentclass::searchmobile()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string smobile;
	cout<<"ÇëÊäÈëÒª²éÑ¯Ñ§ÉúµÄÊÖ»úºÅ:";
	cin>>smobile;
	cout<<endl;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getmobile()==smobile)
		{
			k=1;
			cout<<"FoundÊÖ»úÎª"<<smobile<<"µÄÑ§Éú!"<<endl<<endl;
			stu[i].disp();
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½ÊÖ»úÎª"<<smobile<<"µÄÑ§Éú!"<<endl<<endl;
}

//¸üÐÂÐÕÃû
void Studentclass::updatename()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string sno;
	string sname;
	cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÑ§ÉúµÄÑ§ºÅ:";
	cin>>sno;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getno()==sno)
		{
			k=1;
			cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÑ§ÉúµÄÐÕÃû:";
			cin>>sname;
			stu[i].setname(sname);
			stu[i].disp();
			break;
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½Ñ§ºÅÎª"<<sno<<"µÄÑ§Éú!"<<endl;
}

//¸üÐÂ×¨Òµ
void Studentclass::updatemajor()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string sno;
	string smajor;
	cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÑ§ÉúµÄÑ§ºÅ:";
	cin>>sno;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getno()==sno)
		{
			k=1;
			cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÑ§ÉúµÄ×¨Òµ:";
			cin>>smajor;
			stu[i].setmajor(smajor);
			stu[i].disp();
			break;
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½Ñ§ºÅÎª"<<sno<<"µÄÑ§Éú!"<<endl;
}

//¸üÐÂ°à¼¶
void Studentclass::updateclass()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string sno;
	string sclass;
	cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÑ§ÉúµÄÑ§ºÅ:";
	cin>>sno;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getno()==sno)
		{
			k=1;
			cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÑ§ÉúµÄ°à¼¶:";
			cin>>sclass;
			stu[i].setclass(sclass);
			stu[i].disp();
			break;
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½Ñ§ºÅÎª"<<sno<<"µÄÑ§Éú!"<<endl;
}

//¸üÐÂÊÖ»úºÅ
void Studentclass::updatemobile()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string sno;
	string smobile;
	cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÑ§ÉúµÄÑ§ºÅ:";
	cin>>sno;
	for(int i=0;i<top;i++)
	{
		if(stu[i].getno()==sno)
		{
			k=1;
			cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÑ§ÉúµÄÊÖ»úºÅ:";
			cin>>smobile;
			stu[i].setmobile(smobile);
			stu[i].disp();
			break;
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½Ñ§ºÅÎª"<<sno<<"µÄÑ§Éú!"<<endl;
}


//Êä³öËùÓÐÑ§ÉúÐÅÏ¢
void Studentclass::dispall()
{
	cout<<"Ñ§Éú»ù±¾ÐÅÏ¢ÈçÏÂ:"<<endl<<endl;
	cout<<"   Ñ§ºÅ"<<setw(12)<<"ÐÕÃû"<<setw(12)<<"×¨Òµ"<<setw(12)<<"°à¼¶"<<setw(12)<<"ÊÖ»ú"<<endl;
	for(int i=0;i<top;i++)
	{
		stu[i].disp();
	}
}

//Êä³öÒ»¸öÑ§ÉúÐÅÏ¢
void Studentclass::disp(int n)
{
	cout<<"Ñ§Éú»ù±¾ÐÅÏ¢ÈçÏÂ:"<<endl;
	cout<<"É¾³ý±ê¼Ç"<<setw(8)<<"Ñ§ºÅ"<<setw(12)<<"ÐÕÃû"<<setw(12)<<"×¨Òµ"<<setw(12)<<"°à¼¶"<<setw(12)<<"ÊÖ»ú"<<endl;
		stu[n].disp();
}



//Book	 Í¼ÊéÀà 
class Book{
private:
	int tag;	      //É¾³ý±ê¼Ç1:ÒÑÉ¾0:Î´É¾   
	string bookno;	  //Í¼Êé±àºÅ   
    string bookname;  //ÊéÃû   
	string author;    //×÷Õß
    string  publisher;//³ö°æÉç
	int totalnum;	  //¹Ý²ØÊéÁ¿
	int borrownum;	  //½è³öÁ¿
    int star;         //Í¼ÊéÐÇ¼¶1-5
public:
	Book();
	~Book();
	int getbooktag();         //»ñÈ¡É¾³ý±ê¼Ç
	void setbooktag();        //ÉèÖÃÉ¾³ý±ê¼Ç
	string getbookno();       //»ñÈ¡Í¼Êé±àºÅ
	void setbookno(string);   //ÉèÖÃÍ¼Êé±àºÅ
	string getbookname();     //»ñÈ¡ÊéÃû
	void setbookname(string); //ÉèÖÃÊéÃû
	string getauthor();       //»ñÈ¡×÷Õß
	void setauthor(string);   //ÉèÖÃ×÷Õß
	string getpublisher();    //»ñÈ¡³ö°æÉç
	void setpublisher(string);//ÉèÖÃ³ö°æÉç
	int gettotalnum();        //»ñÈ¡¹Ý²ØÊéÁ¿
	void settotalnum(int);    //ÉèÖÃ¹Ý²ØÊéÁ¿
	int getborrownum();       //»ñÈ¡½è³öÁ¿
	void setborrownum(int);   //ÉèÖÃ½è³öÁ¿
	int getstar();            //»ñÈ¡Í¼ÊéÐÇ¼¶1-5
	void setstar(int);        //ÉèÖÃÍ¼ÊéÐÇ¼¶1-5
	void dispbook();          //ÏÔÊ¾Í¼ÊéÐÅÏ¢
    void upborrownum();       //½è³öÁ¿¼Ó1
    void downborrownum();     //½è³öÁ¿¼õ1
};

Book::Book()
{
	tag=0;
	star=0;
}

Book::~Book(){}

//»ñÈ¡É¾³ý±ê¼Ç
int Book::getbooktag()
{
	return tag;
}

//ÉèÖÃÉ¾³ý±ê¼Ç
void Book::setbooktag()
{
	tag=1;
}

//»ñÈ¡Í¼Êé±àºÅ
string Book::getbookno()
{
	return bookno;
}

//ÉèÖÃÍ¼Êé±àºÅ
void Book::setbookno(string bno)
{
	bookno=bno;
}

//»ñÈ¡ÊéÃû
string Book::getbookname()
{
	return bookname;
}

//ÉèÖÃÊéÃû
void Book::setbookname(string bname)
{
	bookname=bname; 
}

//»ñÈ¡×÷Õß
string Book::getauthor()
{
	return author;
}

//ÉèÖÃ×÷Õß
void Book::setauthor(string bauthor)
{
	author=bauthor;
}

//»ñÈ¡³ö°æÉç
string Book::getpublisher()
{
	return publisher;
}

//ÉèÖÃ³ö°æÉç
void Book::setpublisher(string bpublisher)
{
	publisher=bpublisher;
}

//»ñÈ¡¹Ý²ØÊéÁ¿
int Book::gettotalnum()
{
	return totalnum;
}

//ÉèÖÃ¹Ý²ØÊéÁ¿
void Book::settotalnum(int btotalnum)
{
	totalnum=btotalnum;
}

//»ñÈ¡½è³öÁ¿
int Book::getborrownum()
{
	return borrownum;
}

//ÉèÖÃ½è³öÁ¿
void Book::setborrownum(int bborrownum)
{
	borrownum=bborrownum;
}

//»ñÈ¡Í¼ÊéÐÇ¼¶1-5
int Book::getstar()
{
	return star;
}

//ÉèÖÃÍ¼ÊéÐÇ¼¶1-5
void Book::setstar(int bstar)
{
	star=bstar;
}

//ÏÔÊ¾Í¼ÊéÐÅÏ¢
void Book::dispbook()
{
	if(!tag)
	{
		cout<<bookno<<setw(20);
		cout<<bookname<<setw(15);
		cout<<author<<setw(15);
		cout<<publisher<<setw(7);
		cout<<totalnum<<setw(7);
		cout<<borrownum<<setw(9);
		for(int i=0;i<getstar();i++)
		{
			cout<<"¡î";
		}
		cout<<endl;
	}	
	cout<<endl;
}

//½è³öÁ¿¼Ó1
void Book::upborrownum()
{
	borrownum++;
	cout<<borrownum<<endl;
}

//½è³öÁ¿¼õ1
void Book::downborrownum()
{
	--borrownum;
	cout<<borrownum<<endl;
}

const int Maxb=100;
//Í¼Êé¿âÀà
class BookClass{
private:
	int top;        //Í¼Êé¼ÇÂ¼ÊýÁ¿
    Book book[Maxb];//Í¼Êé¼ÇÂ¼
public:
	BookClass();
	~BookClass();
	void settop(int n);     //ÉèÖÃÊýÁ¿
	int gettop();           //»ñÈ¡ÊýÁ¿
	void getbookup(int i);  //ÕÒµ½¶ÔÓ¦Í¼Êé+1
	void getbookdown(int i);//ÕÒµ½¶ÔÓ¦Í¼Êé-1	
	int bookstar(int i);//µÃµ½¶ÔÓ¦Í¼ÊéµÄÐÇ¼¶
	//²åÈë
	void book_append();//²åÈëÒ»±¾Êé
	void insertall();  //ÅúÁ¿²åÈë
	//É¾³ý
	void deletebookno();   //Í¼Êé±àºÅÉ¾³ý
	void deletebookname(); //ÊéÃûÉ¾³ý
	void deleteauthor();   //×÷ÕßÉ¾³ý
	void deletepublisher();//³ö°æÉçÉ¾³ý
	void deletestar();     //ÐÇ¼¶É¾³ý
	void deleteall();      //É¾³ýËùÓÐÍ¼ÊéÐÅÏ¢
	//²éÑ¯
	void searchbookno();         //Í¼Êé±àºÅ²éÑ¯
	int searchbookno(string bno);//Í¼Êé±àºÅ²éÑ¯
	void searchbookname();       //ÊéÃû²éÑ¯
	void searchauthor();         //×÷Õß²éÑ¯
	void searchpublisher();      //³ö°æÉç²éÑ¯
	void searchstar();           //Í¼ÊéÐÇ¼¶²éÑ¯
	//¸üÐÂ
	void updatebookname(); //¸üÐÂÊéÃû
	void updateauthor();   //¸üÐÂ×÷Õß
	void updatepublisher();//¸üÐÂ³ö°æÉç
	void updatetotalnum(); //¸üÐÂ¹Ý²ØÊýÁ¿
	void updateborrownum();//¸üÐÂ½è³öÁ¿
	void updatestar();     //¸üÐÂÐÇ¼¶
	//Êä³öÍ¼ÊéÐÅÏ¢
	void dispbookall();//ËùÓÐÍ¼Êé
	void dispbook(int n);//Êä³öÒ»±¾Êé

	friend ostream& operator<<(ostream& output,Book& b)
	{
		output<<setw(15)<<b.getbookno();
		output<<setw(30)<<b.getbookname();
		output<<setw(20)<<b.getauthor();
		output<<setw(20)<<b.getpublisher();
		output<<setw(5)<<b.gettotalnum();
		output<<setw(5)<<b.getborrownum();
		output<<setw(5)<<b.getstar()<<endl;
		return output;
	}

	friend istream& operator>>(istream& input,Book& b)
	{
		int btotalnum,bborrownum,bstar;
		string bno,bname,bauthor,bpublisher;
		input>>bno;
		b.setbookno(bno);
		input>>bname;
		b.setbookname(bname);
		input>>bauthor;
		b.setauthor(bauthor);
		input>>bpublisher;
		b.setpublisher(bpublisher);
		input>>btotalnum;
		b.settotalnum(btotalnum);
		input>>bborrownum;
		b.setborrownum(bborrownum);
		input>>bstar;
		b.setstar(bstar);
		return input;
	}
};

//¹¹Ôìº¯Êý¶ÁÈëÍ¼ÊéÐÅÏ¢
BookClass::BookClass()
{
	top=0;
	ifstream in("book.txt");
	if(!in)
	{
		cout<<"ÎÄ¼þ´ò²»¿ª!"<<endl;
	}
	while(!in.eof())
	{
		in>>book[top];
		top++;
	}
	in.close();
}

//Îö¹¹º¯ÊýÊä³öÍ¼ÊéÐÅÏ¢
BookClass::~BookClass()
{
	ofstream out("book.txt");
	if(!out)
	{
		cout<<"ÎÄ¼þ²»ÄÜ´ò¿ª!"<<endl;
	}
	for(int i=0;i<top;i++)
	{
		if(book[i].getbooktag()==0)
		{
			out<<book[i];
		}
	}
	out.close();
}

//ÉèÖÃÊýÁ¿
void BookClass::settop(int n)
{
	top=n;
}

//»ñÈ¡ÊýÁ¿
int BookClass::gettop()
{
	return top;
}

//µÃµ½¶ÔÓ¦Í¼ÊéµÄÐÇ¼¶
int BookClass::bookstar(int i)
{
	int k;
	k=book[i].getstar();
	return k;
}


//ÕÒµ½¶ÔÓ¦Í¼Êé½è³öÁ¿+1
void BookClass::getbookup(int i)
{
	book[i].upborrownum();
	book[i].dispbook();
}

//ÕÒµ½¶ÔÓ¦Í¼Êé½è³öÁ¿-1
void BookClass::getbookdown(int i)
{
	book[i].downborrownum();
	book[i].dispbook();
}

//²åÈëÒ»±¾Êé
void BookClass::book_append()
{	
	int btotalnum,bborrownum,bstar;
	string bno,bname,bauthor,bpublisher;
	cout<<"ÇëÊäÈëÒª²åÈëÊéµÄÍ¼Êé±àºÅ:";
	cin>>bno;
	book[top].setbookno(bno);
	cout<<endl;
	cout<<"ÇëÊäÈëÒª²åÈëÊéµÄÊéÃû:";
	cin>>bname;
	book[top].setbookname(bname);
	cout<<endl;
	cout<<"ÇëÊäÈëÒª²åÈëÊéµÄ×÷Õß:";
	cin>>bauthor;
	book[top].setauthor(bauthor);
	cout<<endl;
	cout<<"ÇëÊäÈëÒª²åÈëÊéµÄ³ö°æÉç:";
	cin>>bpublisher;
	book[top].setpublisher(bpublisher);
	cout<<endl;
	cout<<"ÇëÊäÈëÒª²åÈëÊéµÄ¹Ý²ØÊýÁ¿:";
	cin>>btotalnum;
	book[top].settotalnum(btotalnum);
	cout<<endl;
	cout<<"ÇëÊäÈëÒª²åÈëÊéµÄ½è³öÁ¿:";
	cin>>bborrownum;
	book[top].setborrownum(bborrownum);
	cout<<endl;
	cout<<"ÇëÊäÈëÒª²åÈëÊéµÄÍ¼ÊéÐÇ¼¶:";
	cin>>bstar;
	book[top].setstar(bstar);
	cout<<endl;
	book[top].dispbook();
	top++;
}

//ÅúÁ¿µ¼Èë
void BookClass::insertall()
{
	ifstream in("b.txt");
	if(!in)
	{
		cout<<"ÎÄ¼þ´ò²»¿ª!"<<endl;
	}
	while(!in.eof())
	{
		in>>book[top];
		top++;
	}
	in.close();
}


//°´Í¼Êé±àºÅÉ¾³ý
void BookClass::deletebookno()
{
	int temp=-1;//ÒªÉ¾³ýµÄÍ¼ÊéµÄÏÂ±ê
	string bno;	  
	cout<<"ÇëÊäÈëÒªÉ¾³ýÍ¼ÊéµÄÍ¼Êé±àºÅ:";
	cin>>bno;
	for(int i=0;i<top;i++)
	{
		if(book[i].getbookno()==bno)
		{
			temp=i;
		}
		if(temp!=-1)
		{
			book[temp].setbooktag();
			cout<<"É¾³ýÍê³É!"<<endl;
		}
	}
	if(temp==-1)
		cout<<"Ã»ÓÐÕÒµ½Í¼Êé±àºÅÎª"<<bno<<"µÄÍ¼Êé!"<<endl;
}

//°´ÊéÃûÉ¾³ý
void BookClass::deletebookname() 
{
	int temp=-1;//ÒªÉ¾³ýµÄÍ¼ÊéµÄÏÂ±ê
	string bname;	  
	cout<<"ÇëÊäÈëÒªÉ¾³ýÍ¼ÊéµÄÊéÃû:";
	cin>>bname;
	for(int i=0;i<top;i++)
	{
		if(book[i].getbookname()==bname)
		{
			temp=i;
		}
		if(temp!=-1)
		{
			book[temp].setbooktag();
			cout<<"É¾³ýÍê³É!"<<endl;
		}
	}
	if(temp==-1)
		cout<<"Ã»ÓÐÕÒµ½ÊéÃûÎª"<<bname<<"µÄÍ¼Êé!"<<endl;
}

//°´×÷ÕßÉ¾³ý
void BookClass::deleteauthor()
{
	int temp=-1;//ÒªÉ¾³ýµÄÍ¼ÊéµÄÏÂ±ê
	string bauthor;	  
	cout<<"ÇëÊäÈëÒªÉ¾³ýÍ¼ÊéµÄ×÷Õß:";
	cin>>bauthor;
	for(int i=0;i<top;i++)
	{
		if(book[i].getauthor()==bauthor)
		{
			temp=i;
		}
		if(temp!=-1)
		{
			book[temp].setbooktag();
			cout<<"É¾³ýÍê³É!"<<endl;
		}
	}
	if(temp==-1)
		cout<<"Ã»ÓÐÕÒµ½×÷ÕßÎª"<<bauthor<<"µÄÍ¼Êé!"<<endl;
}   

//°´³ö°æÉçÉ¾³ý
void BookClass::deletepublisher()
{
	int temp=-1;//ÒªÉ¾³ýµÄÍ¼ÊéµÄÏÂ±ê
	string bpublisher;	  
	cout<<"ÇëÊäÈëÒªÉ¾³ýÍ¼ÊéµÄ³ö°æÉç:";
	cin>>bpublisher;
	for(int i=0;i<top;i++)
	{
		if(book[i].getpublisher()==bpublisher)
		{
			temp=i;
		}
		if(temp!=-1)
		{
			book[temp].setbooktag();
			cout<<"É¾³ýÍê³É!"<<endl;
		}
	}
	if(temp==-1)
		cout<<"Ã»ÓÐÕÒµ½³ö°æÉçÎª"<<bpublisher<<"µÄÍ¼Êé!"<<endl;
} 

//°´ÐÇ¼¶É¾³ý
void BookClass::deletestar()
{
	int temp=-1;//ÒªÉ¾³ýµÄÍ¼ÊéµÄÏÂ±ê
	int bstar;	  
	cout<<"ÇëÊäÈëÒªÉ¾³ýÍ¼ÊéµÄÐÇ¼¶:";
	cin>>bstar;
	for(int i=0;i<top;i++)
	{
		if(book[i].getstar()==bstar)
		{
			temp=i;
		}
		if(temp!=-1)
		{
			book[temp].setbooktag();
			cout<<"É¾³ýÍê³É!"<<endl;
		}
	}
	if(temp==-1)
	{
		cout<<"Ã»ÓÐÕÒµ½ÐÇ¼¶Îª";
		for(int j=0;j<bstar;j++)
		{
			cout<<"¡î";
		}
		cout<<"µÄÍ¼Êé!"<<endl;
	}
}
      
//É¾³ýËùÓÐÍ¼ÊéÐÅÏ¢
void BookClass::deleteall()
{
	for(int i=0;i<top;i++)
	{
		book[i].setbooktag();
	}
}
	
//Í¼Êé±àºÅ²éÑ¯
void BookClass::searchbookno()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string bno;
	cout<<"ÇëÊäÈëÒª²éÑ¯ÊéµÄÍ¼Êé±àºÅ:";
	cin>>bno;
	for(int i=0;i<top;i++)
	{
		if(book[i].getbookno()==bno)
		{
			k=1;
			cout<<"FoundÍ¼Êé±àºÅÎª"<<bno<<"µÄÊé!"<<endl;
			book[i].dispbook();
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½Í¼Êé±àºÅÎª"<<bno<<"µÄÊé!"<<endl;
}


int BookClass::searchbookno(string bno)
{
	int k=-1;
	for(int i=0;i<top;i++)
	{
		if(book[i].getbookno()==bno)
			k=i;
	}
	return k;
}


//ÊéÃû²éÑ¯
void BookClass::searchbookname()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string bname;
	cout<<"ÇëÊäÈëÒª²éÑ¯ÊéµÄÊéÃû:";
	cin>>bname;
	for(int i=0;i<top;i++)
	{
		if(book[i].getbookname()==bname)
		{
			k=1;
			cout<<"FoundÊéÃûÎª"<<bname<<"µÄÊé!"<<endl;
			book[i].dispbook();
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½ÊéÃûÎª"<<bname<<"µÄÊé!"<<endl;
}

//×÷Õß²éÑ¯
void BookClass::searchauthor()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string bauthor;
	cout<<"ÇëÊäÈëÒª²éÑ¯ÊéµÄ×÷Õß:";
	cin>>bauthor;
	for(int i=0;i<top;i++)
	{
		if(book[i].getauthor()==bauthor)
		{
			k=1;
			cout<<"Found×÷ÕßÎª"<<bauthor<<"µÄÊé!"<<endl;
			book[i].dispbook();
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½×÷ÕßÎª"<<bauthor<<"µÄÊé!"<<endl;
}

//³ö°æÉç²éÑ¯
void BookClass::searchpublisher()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string bpublisher;
	cout<<"ÇëÊäÈëÒª²éÑ¯ÊéµÄ³ö°æÉç:";
	cin>>bpublisher;
	for(int i=0;i<top;i++)
	{
		if(book[i].getpublisher()==bpublisher)
		{
			k=1;
			cout<<"Found³ö°æÉçÎª"<<bpublisher<<"µÄÊé!"<<endl;
			book[i].dispbook();
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½³ö°æÉçÎª"<<bpublisher<<"µÄÊé!"<<endl;
}

//Í¼ÊéÐÇ¼¶²éÑ¯
void BookClass::searchstar()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	int bstar;
	cout<<"ÇëÊäÈëÒª²éÑ¯ÊéµÄÍ¼ÊéÐÇ¼¶:";
	cin>>bstar;
	for(int i=0;i<top;i++)
	{
		if(book[i].getstar()==bstar)
		{
			k=1;
			cout<<"FoundÍ¼ÊéÐÇ¼¶Îª"<<bstar<<"µÄÊé!"<<endl;
			book[i].dispbook();
		}
	}
	if(k==0)
	{
		cout<<"Ã»ÓÐÕÒµ½ÐÇ¼¶Îª";
		for(int j=0;j<bstar;j++)
		{
			cout<<"¡î";
		}
		cout<<"µÄÍ¼Êé!"<<endl;
	}
}

//¸üÐÂÊéÃû
void BookClass::updatebookname()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string bno;
	string bname;
	cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÍ¼ÊéµÄÍ¼Êé±àºÅ:";
	cin>>bno;
	for(int i=0;i<top;i++)
	{
		if(book[i].getbookno()==bno)
		{
			k=1;
			cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÍ¼ÊéµÄÊéÃû:";
			cin>>bname;
			book[i].setbookname(bname);
			book[i].dispbook();
			break;
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½Í¼Êé±àºÅÎª"<<bno<<"µÄÍ¼Êé!"<<endl;
}

//¸üÐÂ×÷Õß
void BookClass::updateauthor()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string bno;
	string bauthor;
	cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÍ¼ÊéµÄÍ¼Êé±àºÅ:";
	cin>>bno;
	for(int i=0;i<top;i++)
	{
		if(book[i].getbookno()==bno)
		{
			k=1;
			cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÍ¼ÊéµÄ×÷Õß:";
			cin>>bauthor;
			book[i].setauthor(bauthor);
			book[i].dispbook();
			break;
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½Í¼Êé±àºÅÎª"<<bno<<"µÄÍ¼Êé!"<<endl;
}   

//¸üÐÂ³ö°æÉç
void BookClass::updatepublisher()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string bno;
	string bpublisher;
	cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÍ¼ÊéµÄÍ¼Êé±àºÅ:";
	cin>>bno;
	for(int i=0;i<top;i++)
	{
		if(book[i].getbookno()==bno)
		{
			k=1;
			cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÍ¼ÊéµÄ³ö°æÉç:";
			cin>>bpublisher;
			book[i].setpublisher(bpublisher);
			book[i].dispbook();
			break;
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½Í¼Êé±àºÅÎª"<<bno<<"µÄÍ¼Êé!"<<endl;
}

//¸üÐÂ¹Ý²ØÊýÁ¿
void BookClass::updatetotalnum()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string bno;
	int btotalnum;
	cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÍ¼ÊéµÄÍ¼Êé±àºÅ:";
	cin>>bno;
	for(int i=0;i<top;i++)
	{
		if(book[i].getbookno()==bno)
		{
			k=1;
			cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÍ¼ÊéµÄ¹Ý²ØÊýÁ¿:";
			cin>>btotalnum;
			book[i].settotalnum(btotalnum);
			book[i].dispbook();
			break;
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½Í¼Êé±àºÅÎª"<<bno<<"µÄÍ¼Êé!"<<endl;
}  
  
//¸üÐÂ½è³öÁ¿
void BookClass::updateborrownum()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string bno;
	int bborrownum;
	cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÍ¼ÊéµÄÍ¼Êé±àºÅ:";
	cin>>bno;
	for(int i=0;i<top;i++)
	{
		if(book[i].getbookno()==bno)
		{
			k=1;
			cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÍ¼ÊéµÄ½è³öÁ¿:";
			cin>>bborrownum;
			book[i].setborrownum(bborrownum);
			book[i].dispbook();
			break;
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½Í¼Êé±àºÅÎª"<<bno<<"µÄÍ¼Êé!"<<endl;
}

//¸üÐÂÐÇ¼¶
void BookClass::updatestar()
{
	int k=0;  //²éÑ¯±ê¼Ç1:Yes 0:No
	string bno;
	int bstar;
	cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÍ¼ÊéµÄÍ¼Êé±àºÅ:";
	cin>>bno;
	for(int i=0;i<top;i++)
	{
		if(book[i].getbookno()==bno)
		{
			k=1;
			cout<<"ÇëÊäÈëÒªÐÞ¸ÄµÄÍ¼ÊéµÄÐÇ¼¶:";
			cin>>bstar;
			book[i].setstar(bstar);
			book[i].dispbook();
			break;
		}
	}
	if(k==0)
		cout<<"Ã»ÓÐÕÒµ½Í¼Êé±àºÅÎª"<<bno<<"µÄÍ¼Êé!"<<endl;
}    

//Êä³öËùÓÐÍ¼ÊéÐÅÏ¢
void BookClass::dispbookall()
{
	cout<<"Í¼ÊéÐÅÏ¢ÈçÏÂ:"<<endl;
	cout<<"Í¼Êé±àºÅ"<<setw(12);
	cout<<"ÊéÃû"<<setw(12);
	cout<<"×÷Õß"<<setw(12);
	cout<<"³ö°æÉç"<<setw(12);
	cout<<"¹Ý²ØÊýÁ¿"<<setw(12);
	cout<<"½è³öÁ¿"<<setw(12);
	cout<<"Í¼ÊéÐÇ¼¶"<<endl;
	for(int i=0;i<top;i++)
	{
		book[i].dispbook();
	}
}

//Êä³öÒ»±¾ÊéÐÅÏ¢
void BookClass::dispbook(int n)
{
	cout<<"¸ÃÍ¼Êé»ù±¾ÐÅÏ¢ÈçÏÂ:"<<endl;
		book[n].dispbook();
}


const int M=5;

//½èÔÄÈÕÆÚ
class BorrowInfo{
public: 
	string bookno;	//Í¼Êé±àºÅ
	int borrowyear; //½èÊéÄê·Ý
	int borrowmonth;//½èÊéÔÂ·Ý
	int borrowday;  //½èÊéÈÕÆÚ
	int backyear;   //»¹ÊéÄê·Ý
	int backmonth;  //»¹ÊéÔÂ·Ý
	int backday;    //»¹ÊéÈÕÆÚ
};

//Ò»¸öÑ§Éú½èÔÄÐÅÏ¢
class BorrowNote{
private:
	string borrowno;//½èÔÄÑ§ÉúµÄÑ§ºÅ
	int top;
public:
	BorrowInfo bookborrow[M];//Ëù½èÍ¼ÊéÐÅÏ¢
	BorrowNote();
	~BorrowNote();
	void settop(int);        //ÉèÖÃ½èÔÄÍ¼ÊéÊýÁ¿
	int gettop();            //»ñÈ¡½èÔÄÍ¼ÊéÊýÁ¿
	void setborrowno(string);   //ÉèÖÃ½èÔÄÑ§ÉúµÄÑ§ºÅ
	string getborrowno();       //»ñÈ¡½èÔÄÑ§ÉúµÄÑ§ºÅ
	void setborrowday(int i,int boryear,int bormonth,int borday);//ÉèÖÃ½èÊéÊ±¼ä
	void setbackday(int i,int byear,int bmonth,int bday);        //ÉèÖÃ»¹ÊéÈÕÆÚ
	void borrowbook(string bno);//½èÊé
	void backbook(string bno);  //»¹Êé
	void disp();                //ÏÔÊ¾½èÔÄÐÅÏ¢
};

//¹¹Ôìº¯Êý
BorrowNote::BorrowNote()
{
	top=0;
}

//Îö¹¹º¯Êý
BorrowNote::~BorrowNote(){}

//ÉèÖÃ½èÔÄÍ¼ÊéÊýÁ¿
void BorrowNote::settop(int n)
{
	top=n;
}

//»ñÈ¡½èÔÄÍ¼ÊéÊýÁ¿
int BorrowNote::gettop()
{
	return top;
}

/*//ÉèÖÃ½èÊéÄê·Ý
void BorrowNote::setborrowyear(int byear)
{
	borrowyear=byear;
}

//»ñÈ¡½èÊéÄê·Ý
int BorrowNote::getborrowyear()
{
    return borrowyear;
}

//ÉèÖÃ½èÊéÔÂ·Ý
void BorrowNote::setborrowmonth(int bmonth)
{
	borrowmonth=bmonth;
}

//»ñÈ¡½èÊéÔÂ·Ý
int BorrowNote::getborrowmonth()
{
	return borrowmonth;    
}

//ÉèÖÃ½èÊéÈÕÆÚ
void BorrowNote::setborrowday(int bday)
{
	borrowday=bday;
}

//»ñÈ¡½èÊéÈÕÆÚ
int BorrowNote::getborrowday()
{
	return borrowday;
}
*/

//ÉèÖÃ½èÔÄÑ§ÉúµÄÑ§ºÅ
void BorrowNote::setborrowno(string borno)
{
	borrowno=borno;
}

//»ñÈ¡½èÔÄÑ§ÉúµÄÑ§ºÅ
string BorrowNote::getborrowno()
{
	return borrowno;
}

//ÉèÖÃ½èÊéÊ±¼ä
void BorrowNote::setborrowday(int i,int boryear,int bormonth,int borday)
{
	bookborrow[i].borrowyear=boryear;
	bookborrow[i].borrowmonth=bormonth;
	bookborrow[i].borrowday=borday;
}

//ÉèÖÃ»¹ÊéÈÕÆÚ
void BorrowNote::setbackday(int i,int byear,int bmonth,int bday)
{
	bookborrow[i].backyear=byear;
	bookborrow[i].backmonth=bmonth;
	bookborrow[i].backday=bday;
}

//½èÊé
void BorrowNote::borrowbook(string bno)
{
	time_t  t;  
    tm  *tp;  
    t=time(NULL);  
    tp=localtime(&t);
    bookborrow[top].bookno=bno;                 //Í¼Êé±àºÅ
	bookborrow[top].borrowyear=tp->tm_year+1900;//½èÊéÄê·Ý
	bookborrow[top].borrowmonth=tp->tm_mon+1;   //½èÊéÔÂ·Ý
	bookborrow[top].borrowday=tp->tm_mday;      //½èÊéÈÕÆÚ
	bookborrow[top].backyear=0;                 //»¹ÊéÄê·Ý
	bookborrow[top].backmonth=0;                //»¹ÊéÔÂ·Ý
	bookborrow[top].backday=0;                  //»¹ÊéÈÕÆÚ
	top++;
}

//»¹Êé
void BorrowNote::backbook(string bno)
{
	int k=-1;//Í¼ÊéÏÂ±ê
	for(int i=0;i<top;i++)
	{
		if(bookborrow[i].bookno==bno)
		{
			k=i;
		}
	}
	if(k==-1)
		cout<<"ÄúÎ´½è´ËÊé!"<<endl;
	else
	{
		time_t t;  
		tm  *tp;  
		t=time(NULL);  
		tp=localtime(&t);  
		bookborrow[k].backyear=tp->tm_year+1900;//»¹ÊéÄê·Ý
		bookborrow[k].backmonth=tp->tm_mon+1;   //»¹ÊéÔÂ·Ý
		bookborrow[k].backday=tp->tm_mday;      //»¹ÊéÈÕÆÚ
	}
}

//ÏÔÊ¾½èÊéÐÅÏ¢
void BorrowNote::disp()
{
	cout<<"Ñ§ºÅÎª:"<<borrowno<<"µÄÑ§ÉúµÄ½èÊéÐÅÏ¢ÈçÏÂ:"<<endl;
	for(int i=0;i<top;i++)
	{
		cout<<"Í¼Êé±àºÅ:"<<bookborrow[i].bookno<<endl;
		cout<<"½èÊéÈÕÆÚ:"<<bookborrow[i].borrowyear<<"Äê"<<bookborrow[i].borrowmonth<<"ÔÂ"<<bookborrow[i].borrowday<<"ÈÕ"<<endl;
		if(bookborrow[i].backyear==0)
			cout<<"´ËÊéÎ´»¹!"<<endl;
		else
			cout<<"»¹ÊéÈÕÆÚ:"<<bookborrow[i].backyear<<"Äê"<<bookborrow[i].backmonth<<"ÔÂ"<<bookborrow[i].backday<<"ÈÕ"<<endl;
		cout<<endl;
	}
}


class BorrowClass{
private:
	int top;
	BorrowNote note[Max];
public:
	BorrowClass();
	~BorrowClass();
	void Insert(string borno,string bno);     //²åÈëÒ»¸öÑ§Éú½èÔÄÐÅÏ¢
	void borrow(Studentclass &S,BookClass &B);//Í¼Êé½èÔÄ
	void back(Studentclass &S,BookClass &B);  //Í¼Êé¹é»¹
	void recommend(BookClass B);              //Í¼ÊéÍÆ¼ö
	//½èÔÄÐÅÏ¢²éÑ¯
	void notesearchno();    //°´Ñ§ºÅ²éÑ¯½èÊé¼ÇÂ¼
	void notesearchbookno();//°´Í¼Êé±àºÅ²éÑ¯½èÊé¼ÇÂ¼
	void notesearchname();  //°´ÊéÃû²éÑ¯½èÊé¼ÇÂ¼
	void notesearchdate();  //°´½èÊéÈÕÆÚ²éÑ¯½èÊé¼ÇÂ¼
	void dispall();         //ÏÔÊ¾ËùÓÐ½èÊé¼ÇÂ¼  

	friend ostream& operator<<(ostream& output,BorrowNote& D)
	{
		output<<setw(20)<<D.getborrowno();
		output<<setw(5)<<D.gettop();
		output<<endl;
		for(int i=0;i<D.gettop();i++)
		{
			output<<setw(20)<<D.bookborrow[i].bookno;
			output<<setw(6)<<D.bookborrow[i].borrowyear;
			output<<setw(4)<<D.bookborrow[i].borrowmonth;
			output<<setw(4)<<D.bookborrow[i].borrowday;
			output<<setw(6)<<D.bookborrow[i].backyear;
			output<<setw(4)<<D.bookborrow[i].backmonth;
			output<<setw(4)<<D.bookborrow[i].backday;
		}
		output<<endl;
		return output;
	}

	friend istream& operator>>(istream& input,BorrowNote& D)
	{
		string borno,bno;
		int t;
		int boryear,bormonth,borday,byear,bmonth,bday;
		input>>borno;
		D.setborrowno(borno);
		input>>t;
		D.settop(t);
		for(int i=0;i<t;i++)
		{
			input>>bno;
			D.bookborrow[i].bookno=bno;
			input>>boryear>>bormonth>>borday;
			D.setborrowday(i,boryear,bormonth,borday);
			input>>byear>>bmonth>>bday;
			D.setbackday(i,byear,bmonth,bday);
		}
	  return input;
	}
};

//¹¹Ôìº¯Êý¶ÁÈ¡½èÔÄÐÅÏ¢
BorrowClass::BorrowClass()
{
	top=0;
	ifstream in("borrow.txt");
	if(!in)
	{
		cout<<"ÎÄ¼þ´ò²»¿ª!"<<endl;
	}
	while(!in.eof())
	{
		in>>note[top];
		top++;
	}
	in.close();
}

//Îö¹¹º¯ÊýÊä³ö½èÔÄÐÅÏ¢
BorrowClass::~BorrowClass()
{
	ofstream out("borrow.txt");
	if(!out)
	{
		cout<<"ÎÄ¼þ´ò²»¿ª!"<<endl;
	}
	for(int i=0;i<top;i++)
	{
		out<<note[i];
	}
	out.close();
}

//²åÈëÒ»¸öÑ§Éú½èÔÄÐÅÏ¢
void BorrowClass::Insert(string borno,string bno)
{
	note[top].setborrowno(borno);
	note[top].borrowbook(bno);
	top++;
}

//Í¼Êé½èÔÄ
void BorrowClass::borrow(Studentclass &S,BookClass &B)
{
	string borno;
	string bno;
	cout<<"ÇëÊäÈëÄúµÄÑ§ºÅ:";
	cin>>borno;
	int k1=S.searchno(borno);
	if(k1==-1)
	{
		cout<<"Ã»ÓÐÑ§ºÅÎª:"<<borno<<"µÄÑ§Éú"<<endl<<endl;
		return;
	}
	cout<<"ÇëÊäÈëÒª½èÊéµÄÍ¼Êé±àºÅ:";
	cin>>bno;
	int k2=B.searchbookno(bno);
	if(k2==-1)
	{
		cout<<"Ã»ÓÐÍ¼Êé±àºÅÎª:"<<bno<<"µÄÊé"<<endl<<endl;
		return;
	}
	int s=-1;
	int k=-1;
	for(int i=0;i<top;i++)
	{
		if(note[i].getborrowno()==borno)
		{
			s=i;
			note[i].borrowbook(bno);
			k=B.searchbookno(bno);
			B.getbookup(k);
			cout<<borno<<"½èÔÄ"<<bno<<"³É¹¦!"<<endl<<endl;
		    break;
		}
	}
	if(s==-1)
	{
		Insert(borno,bno);
		k=B.searchbookno(bno);
		B.getbookup(k);
		cout<<borno<<"½èÔÄ"<<bno<<"³É¹¦!"<<endl<<endl;
	}
}


//Í¼Êé¹é»¹
void BorrowClass::back(Studentclass &S,BookClass &B)
{
	string borno;
	string bno;
	cout<<"ÇëÊäÈëÄúµÄÑ§ºÅ:";
	cin>>borno;
	int k1=S.searchno(borno);
	if(k1==-1)
	{
		cout<<"Ã»ÓÐÑ§ºÅÎª:"<<borno<<"µÄÑ§Éú"<<endl<<endl;
		return;
	}
	cout<<"ÇëÊäÈëÒª½èÊéµÄÍ¼Êé±àºÅ:";
	cin>>bno;
	int k2=B.searchbookno(bno);
	if(k2==-1)
	{
		cout<<"Ã»ÓÐÍ¼Êé±àºÅÎª:"<<bno<<"µÄÊé"<<endl<<endl;
		return;
	}
	int k=-1;
	for(int i=0;i<top;i++)
	{
		if(note[i].getborrowno()==borno)
		{
			note[i].backbook(bno);
			k=B.searchbookno(bno);
		    B.getbookdown(k);
			cout<<borno<<"»¹Êé"<<bno<<"³É¹¦!"<<endl<<endl;
		}
	}
}

//Í¼ÊéÍÆ¼ö
void BorrowClass::recommend(BookClass B)
{
	int s;
	for(int i=0;i<B.gettop()-1;i++)
	{
		s=B.bookstar(i);
		if(s==5)
		{
			B.dispbook(i);
		}
	}
	for(i=0;i<B.gettop()-1;i++)
	{
		s=B.bookstar(i);
		if(s==4)
		{
			B.dispbook(i);
		}
	}
	for(i=0;i<B.gettop()-1;i++)
	{
		s=B.bookstar(i);
		if(s==3)
		{
			B.dispbook(i);
		}
	}
	for(i=0;i<B.gettop()-1;i++)
	{
		s=B.bookstar(i);
		if(s==2)
		{
			B.dispbook(i);
		}
	}
	for(i=0;i<B.gettop()-1;i++)
	{
		s=B.bookstar(i);
		if(s==1)
		{
			B.dispbook(i);
		}
	}
}


//°´Ñ§ºÅ²éÑ¯½èÊé¼ÇÂ¼
void BorrowClass::notesearchno()
{
	int k=-1;
	string borno;
	cout<<"ÇëÊäÈëÄúµÄÑ§ºÅ:";
	cin>>borno;
	for(int i=0;i<top;i++)
	{
		if(note[i].getborrowno()==borno)
		{
			k=i;
			note[i].disp();
		}
	}
	if(k==-1)
	{
		cout<<"Ñ§ºÅÎª:"<<borno<<"µÄÑ§ÉúÃ»ÓÐ½èÊé!"<<endl<<endl;
	}
}

/*//°´Í¼Êé±àºÅ²éÑ¯½èÊé¼ÇÂ¼
void BorrowClass::notesearchbookno()
{
	int k=-1;
	string bno;
	cout<<"ÇëÊäÈëÄúÒª²éÑ¯µÄÍ¼Êé±àºÅ:";
	cin>>bno;
	for(int i=0;i<top;i++)
	{
		for(int j=0;j<note[i].gettop();j++)
		{
			if(note[i].bookborrow[j].getbookno()==bno)
			{
				k=i;
			    note[i].disp();		
			}
		}
	}
	if(k==-1)
	{
		cout<<"Í¼Êé±àºÅÎª:"<<bno<<"µÄÍ¼ÊéÎ´±»½è³ö!"<<endl;
	}
}

//°´ÊéÃû²éÑ¯½èÊé¼ÇÂ¼
void BorrowClass::notesearchname()
{
	int k=-1;
	string bname;
	cout<<"ÇëÊäÈëÄúÒª²éÑ¯µÄÊéÃû:";
	cin>>bname;
	for(int i=0;i<top;i++)
	{
		for(int j=0;j<note[i].gettop();j++)
		{
			if(note[i].bookborrow[j].getbookname()==bname)
			{
				k=i;
			    note[i].disp();		
			}
		}
	}
	if(k==-1)
	{
		cout<<"ÊéÃûÎª:"<<bname<<"µÄÍ¼ÊéÎ´±»½è³ö!"<<endl;
	}
}

//°´½èÊéÈÕÆÚ²éÑ¯½èÊé¼ÇÂ¼
void BorrowClass::notesearchdate()
{
	int k=-1;
	int byear;
	int bmonth;
	int bday;
	cout<<"ÇëÊäÈëÄúÒª²éÑ¯µÄ½èÊéÈÕÆÚ:"<<endl;
	cout<<"ÇëÊäÈëÄê·Ý:";
	cin>>byear;
	cout<<endl<<"ÇëÊäÈëÄê·Ý:";
	cin>>bmonth;
	cout<<endl<<"ÇëÊäÈëÈÕÆÚ:";
	cin>>bday;
	for(int i=0;i<top;i++)
	{
		for(int j=0;j<note[i].gettop();j++)
		{
			if(note[i].bookborrow[j].getborrowyear()==byear&&note[i].bookborrow[j].getborrowmonth==bmonth&&note[i].bookborrow[j].getborrowday==bday)
			{
				k=i;
			    note[i].disp();	
			}
		}
	}
	if(k==-1)
	{
		cout<<byear<<"Äê"<<bmonth<<"ÔÂ"<<bday<<"ÈÕ"<<"Ã»ÓÐÈË½èÊé!"<<endl;
	}
}
*/	


//ÏÔÊ¾ËùÓÐ½èÊé¼ÇÂ¼
void BorrowClass::dispall()
{
	for(int i=0;i<top;i++)
		note[i].disp();
}



//×Ó²Ëµ¥
//µ¥¸öÑ§Éú±ÏÒµ
void stu_detete_menu(Studentclass &S)
{
	int choise;
	cout<<"1.°´Ñ§ºÅÉ¾³ý"<<endl<<endl;
	cout<<"2.°´ÐÕÃûÉ¾³ý"<<endl<<endl;
	cout<<"3.°´×¨ÒµÉ¾³ý"<<endl<<endl;
	cout<<"4.°´°à¼¶É¾³ý"<<endl<<endl;
	cout<<"5.°´ÊÖ»úºÅÉ¾³ý"<<endl<<endl;
	cout<<"0.ÍË³ö"<<endl<<endl;
	cout<<"ÇëÊäÈë(0--5):";
	cin>>choise;
	switch(choise)
	{
	case 1:
		S.deleteno();
		break;
	case 2:
		S.deletename();
		break;
	case 3:
		S.deletemajor();
		break;
	case 4:
		S.deleteclass();
		break;
	case 5:
		S.deletemobile();
		break;
	case 0:
		return;
	default:
		cout<<"ÊäÈë´íÎó,ÇëÖØÐÂÊäÈë!"<<endl;
	}
}

//×Ó²Ëµ¥
//Ñ§ÉúÐÅÏ¢²éÑ¯
void stu_search_menu(Studentclass &S)
{
	int choise;
	cout<<"1.²éÑ¯Ñ§ºÅ"<<endl<<endl;
	cout<<"2.²éÑ¯ÐÕÃû"<<endl<<endl;
	cout<<"3.²éÑ¯×¨Òµ"<<endl<<endl;
	cout<<"4.²éÑ¯°à¼¶"<<endl<<endl;
	cout<<"5.²éÑ¯ÊÖ»úºÅ"<<endl<<endl;
	cout<<"0.ÍË³ö"<<endl<<endl;
	cout<<"ÇëÊäÈë(0--5):";
	cin>>choise;
	switch(choise)
	{
	case 1:
		S.searchno();
		break;
	case 2:
		S.searchname();
		break;
	case 3:
		S.searchmajor();
		break;
	case 4:
		S.searchclass();
		break;
	case 5:
		S.searchmobile();
		break;
	case 0:
		return;
	default:
		cout<<"ÊäÈë´íÎó,ÇëÖØÐÂÊäÈë!"<<endl;
	}
}

//×Ó²Ëµ¥
//Ñ§ÉúÐÅÏ¢ÐÞ¸Ä
void stu_update_menu(Studentclass &S)
{
	int choise;
	cout<<"1.¸üÐÂÐÕÃû"<<endl<<endl;
	cout<<"2.¸üÐÂ×¨Òµ"<<endl<<endl;
	cout<<"3.¸üÐÂ°à¼¶"<<endl<<endl;
	cout<<"4.¸üÐÂÊÖ»úºÅ"<<endl<<endl;
	cout<<"0.ÍË³ö"<<endl<<endl;
	cout<<"ÇëÊäÈë(0--4):";
	cin>>choise;
	switch(choise)
	{
	case 1:
		S.updatename();
		break;
	case 2:
		S.updatemajor();
		break;
	case 3:
		S.updateclass();
		break;
	case 4:
		S.updatemobile();
		break;
	case 0:
		return;
	default:
		cout<<"ÊäÈë´íÎó,ÇëÖØÐÂÊäÈë!"<<endl;
	}
}

void stu_main_menu(Studentclass &S)
{
	int choise;
	cout<<setw(6)<<"¡î¡î¡î  »¶Ó­Ê¹ÓÃÑ§ÉúÐÅÏ¢¹ÜÀíÏµÍ³  ¡î¡î¡î"<<endl<<endl;
	cout<<"       1.µ¥¸öÑ§ÉúÈëÑ§"<<endl<<endl;
	cout<<"       2.µ¥¸öÑ§Éú±ÏÒµ"<<endl<<endl;
	cout<<"       3.ÅúÁ¿Ñ§Éúµ¼Èë"<<endl<<endl;
	cout<<"       4.ÅúÁ¿Ñ§ÉúÉ¾³ý"<<endl<<endl;
	cout<<"       5.Ñ§ÉúÐÅÏ¢²éÑ¯"<<endl<<endl;
	cout<<"       6.Ñ§ÉúÐÅÏ¢ÐÞ¸Ä"<<endl<<endl;
	cout<<"       7.ÏÔÊ¾ËùÓÐÑ§ÉúÐÅÏ¢"<<endl<<endl;
	cout<<"       0.ÍË³öÏµÍ³"<<endl<<endl;
	cout<<"       ÇëÊäÈë(0--7):";
	cin>>choise;
    switch(choise)
	{
		case 1:
			S.stu_append();
			break;
		case 2:
			stu_detete_menu(S);
			break;
		case 3:
			S.insertall();
			break;
		case 4:
			S.deleteall();
			break;
		case 5:
			stu_search_menu(S);
			break;
		case 6:stu_update_menu(S);
			break;
		case 7:
			S.dispall();
			break;
		case 0:
			return;
		default:
			cout<<"ÊäÈë´íÎó,ÇëÖØÐÂÊäÈë!"<<endl;
	}
}

//×Ó²Ëµ¥
//µ¥±¾Í¼ÊéÉ¾³ý
void book_delete_menu(BookClass &B)
{
	int choise;
	cout<<"1.°´Í¼Êé±àºÅÉ¾³ý"<<endl<<endl;
	cout<<"2.°´ÊéÃûÉ¾³ý"<<endl<<endl;
	cout<<"3.°´×÷ÕßÉ¾³ý"<<endl<<endl;
	cout<<"4.°´³ö°æÉçÉ¾³ý"<<endl<<endl;
	cout<<"5.°´ÐÇ¼¶É¾³ý"<<endl<<endl;
	cout<<"0.ÍË³ö"<<endl<<endl;
	cout<<"ÇëÊäÈë(0--5):";
	cin>>choise;
	switch(choise)
	{
	case 1:
		B.deletebookno();
		break;
	case 2:
		B.deletebookname();
		break;
	case 3:
		B.deleteauthor();
		break;
	case 4:
		B.deletepublisher();
		break;
	case 5:
		B.deletestar();
		break;
	case 0:
		return;
	default:
			cout<<"ÊäÈë´íÎó,ÇëÖØÐÂÊäÈë!"<<endl;
	}
}	

//×Ó²Ëµ¥
//Í¼ÊéÐÅÏ¢²éÑ¯
void book_search_menu(BookClass &B)
{
	int choise;
	cout<<"1.°´Í¼Êé±àºÅ²éÑ¯"<<endl<<endl;
	cout<<"2.°´ÊéÃû²éÑ¯"<<endl<<endl;
	cout<<"3.°´×÷Õß²éÑ¯"<<endl<<endl;
	cout<<"4.°´³ö°æÉç²éÑ¯"<<endl<<endl;
	cout<<"5.°´ÐÇ¼¶²éÑ¯"<<endl<<endl;
	cout<<"0.ÍË³ö"<<endl<<endl;
	cout<<"ÇëÊäÈë(0--5):";
	cin>>choise;
	switch(choise)
	{
	case 1:
		B.searchbookno();
		break;
	case 2:
		B.searchbookname();
		break;
	case 3:
		B.searchauthor();
		break;
	case 4:
		B.searchpublisher();
		break;
	case 5:
		B.searchstar();
		break;
	case 0:
		return;
	default:
			cout<<"ÊäÈë´íÎó,ÇëÖØÐÂÊäÈë!"<<endl;
	}
}	

//×Ó²Ëµ¥
//¸üÐÂÍ¼ÊéÐÅÏ¢
void book_update_menu(BookClass &B)
{
	int choise;
	cout<<"1.¸üÐÂÊéÃû"<<endl<<endl;
	cout<<"2.¸üÐÂ×÷Õß"<<endl<<endl;
	cout<<"3.¸üÐÂ³ö°æÉç"<<endl<<endl;
	cout<<"4.¸üÐÂ¹Ý²ØÊýÁ¿"<<endl<<endl;
	cout<<"5.¸üÐÂ½è³öÁ¿"<<endl<<endl;
	cout<<"6.¸üÐÂÐÇ¼¶"<<endl<<endl;
	cout<<"0.ÍË³ö"<<endl<<endl;
	cout<<"ÇëÊäÈë(0--6):";
	cin>>choise;
	system("cls");
	switch(choise)
	{
	case 1:
		B.updatebookname();
		break;
	case 2:
		B.updateauthor();
		break;
	case 3:
		B.updatepublisher();
		break;
	case 4:
		B.updatetotalnum();
		break;
	case 5:
		B.updateborrownum();
		break;
	case 6:
		B.updatestar();
		break;
	case 0:
		return;
	default:
			cout<<"ÊäÈë´íÎó,ÇëÖØÐÂÊäÈë!"<<endl;
	}
}	

void book_main_menu(BookClass &B)
{
	int choise;
	cout<<"¡î¡î¡î  »¶Ó­Ê¹ÓÃÍ¼Êé¹ÜÀíÏµÍ³  ¡î¡î¡î"<<endl<<endl;
	cout<<"       1.µ¥±¾Í¼Êé²åÈë"<<endl<<endl;
	cout<<"       2.ÅúÁ¿Í¼Êé²åÈë"<<endl<<endl;
	cout<<"       3.µ¥±¾Í¼ÊéÉ¾³ý"<<endl<<endl;
	cout<<"       4.ÅúÁ¿Í¼ÊéÉ¾³ý"<<endl<<endl;
	cout<<"       5.Í¼ÊéÐÅÏ¢²éÑ¯"<<endl<<endl;
	cout<<"       6.¸üÐÂÍ¼ÊéÐÅÏ¢"<<endl<<endl;
	cout<<"       7.Êä³öËùÓÐÍ¼ÊéÐÅÏ¢"<<endl<<endl;
	cout<<"       0.ÍË³ö"<<endl<<endl;
	cout<<"       ÇëÊäÈë(0--7):";
	cin>>choise;
	system("cls");
	switch(choise)
	{
	case 1:
		B.book_append();
		break;
	case 2:
		B.insertall();
		break;
	case 3:
		book_delete_menu(B);
		break;
	case 4:
		B.deleteall();
		break;
	case 5:
		book_search_menu(B);
		break;
	case 6:
		book_update_menu(B);
		break;
	case 7:
		B.dispbookall();
		break;
	case 0:
		return;
	default:
		cout<<"ÊäÈë´íÎó,ÇëÖØÐÂÊäÈë!"<<endl;
	}
}


void borrow_note_menu(Studentclass &S,BookClass &B,BorrowClass &N)
{
	int choise;
	cout<<"¡î¡î¡î  »¶Ó­Ê¹ÓÃ¶ÁÕß½èÔÄ¹ÜÀíÏµÍ³  ¡î¡î¡î"<<endl<<endl;
	cout<<"       1.Í¼Êé½èÔÄ"<<endl<<endl;
	cout<<"       2.Í¼Êé¹é»¹"<<endl<<endl;
	cout<<"       3.²éÑ¯½èÊé¼ÇÂ¼"<<endl<<endl;
	cout<<"       4.ÍÆ¼öÍ¼Êé"<<endl<<endl;
	cout<<"       5.ÏÔÊ¾ËùÓÐ½èÊé¼ÇÂ¼"<<endl<<endl;
	cout<<"       0.ÍË³ö"<<endl<<endl;
	cout<<"       ÇëÊäÈë(0--5):";
	cin>>choise;
	system("cls");
	switch(choise)
	{
	case 1:
		N.borrow(S,B);
		break;
	case 2:
		N.back(S,B);
		break;
	case 3:
		N.notesearchno();
		break;
	case 4:
		N.recommend(B);
		break;
	case 5:
		N.dispall();
		break;
	case 0:
		return;
	default:
		cout<<"ÊäÈë´íÎó,ÇëÖØÐÂÊäÈë!"<<endl;
	}
}

int main()
{
	int choise1=1,choise2=1,choise3=1;
	string a,pw;
	int flag=111;
begin:
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<setw(40)<<"ÇëÊäÈëÄúµÄÉí·Ý:";
	{
		cin>>a;
		if(a=="111")
		{
			cout<<setw(38)<<"ÇëÊäÈëÃÜÂë:";
			cin>>pw;
			if(pw=="000")
			{
				cout<<"µÇÂ½³É¹¦!"<<endl;
				system("cls");
			}
			else
			{
				cout<<"ÃÜÂë´íÎó!ÇëÖØÐÂÊäÈë!"<<endl;
				goto begin;
			}
		}
	}
	int choise;
	Studentclass S;
	BookClass B;
	BorrowClass N;
	for(;;)
	{
		cout<<setw(6)<<" ¡î¡î¡î¡î  »¶Ó­Ê¹ÓÃÍ¼Êé¹ÜÀíÏµÍ³  ¡î¡î¡î¡î"<<endl<<endl;
		cout<<"          1.Ñ§ÉúÐÅÏ¢¹ÜÀíÏµÍ³"<<endl<<endl;
		cout<<"          2.Í¼Êé¹ÜÀíÏµÍ³"<<endl<<endl;
		cout<<"          3.¶ÁÕß½èÔÄ¹ÜÀíÏµÍ³"<<endl<<endl;
		cout<<"          0.ÍË³öÏµÍ³"<<endl<<endl;
		cout<<"          ÇëÑ¡Ôñ(0--3):";
		cin>>choise;
		system("cls");
		switch(choise)
		{
		case 1:
			stu_main_menu(S);
			break;
		case 2:
			book_main_menu(B);
			break;
		case 3:
			borrow_note_menu(S,B,N);
			break;
		case 0:
			cout<<endl;
			cout<<"»¶Ó­Ê¹ÓÃÍ¼Êé¹ÜÀíÏµÍ³,ÇëÌá³ö±¦¹óÒâ¼û!"<<endl;
			return 0;
		default:
			cout<<"ÊäÈë´íÎó,ÇëÖØÐÂÊäÈë!"<<endl;
		}
	}
	return 0;
}

