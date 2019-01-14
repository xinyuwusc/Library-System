#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
using namespace std;

//Student类
class Student
{
  private:
	int tag;			  //删除标记1:已删0:未删
	string studentno;	 //学号
	string studentname;   //姓名
	string studentmajor;  //专业
	string studentclass;  //班级
	string studentmobile; //手机
  public:
	Student();
	int gettag();			//获取删除标记
	void settag();			//设置删除标记
	string getno();			//获取学号
	void setno(string);		//设置学号
	string getname();		//获取姓名
	void setname(string);   //设置姓名
	string getmajor();		//获取专业
	void setmajor(string);  //设置专业
	string getclass();		//获取班级
	void setclass(string);  //设置班级
	string getmobile();		//获取手机号
	void setmobile(string); //设置手机号
	void disp();			//输出学生信息
	~Student();
};

//缺省构造函数
Student::Student()
{
	tag = 0;
}

//析构函数
Student::~Student() {}

//获取删除标记
int Student::gettag()
{
	return tag;
}

//设置删除标记
void Student::settag()
{
	tag = 1;
}

//获取学号
string Student::getno()
{
	return studentno;
}

//设置学号
void Student::setno(string sno)
{
	studentno = sno;
}

//获取姓名
string Student::getname()
{
	return studentname;
}

//设置姓名
void Student::setname(string sname)
{
	studentname = sname;
}

//获取专业
string Student::getmajor()
{
	return studentmajor;
}

//设置专业
void Student::setmajor(string smajor)
{
	studentmajor = smajor;
}

//获取班级
string Student::getclass()
{
	return studentclass;
}

//设置班级
void Student::setclass(string sclass)
{
	studentclass = sclass;
}

//获取手机号
string Student::getmobile()
{
	return studentmobile;
}

//设置手机号
void Student::setmobile(string smobile)
{
	studentmobile = smobile;
}

//输出学生信息
void Student::disp()
{
	if (!tag)
	{
		cout << setw(10) << studentno << setw(10) << studentname << setw(10) << studentmajor << setw(10) << studentclass << setw(20) << studentmobile << endl;
	}
}

const int Max = 100;
class Studentclass
{
  private:
	int top;
	Student stu[Max]; //学生记录
  public:
	Studentclass();
	~Studentclass();
	void settop(int n); //设置人数
	int gettop();		//获取人数

	//插入
	void stu_append();   //插入一个学生
						 //删除一个学生
	void deleteno();	 //学号删除
	void deletename();   //姓名删除
	void deletemajor();  //专业删除
	void deleteclass();  //班级删除
	void deletemobile(); //手机号删除
	void deleteall();	//删除所有学生信息

	void insertall(); //批量导入
	//查询
	void searchno();		  //学号查询
	int searchno(string sno); //学号查询
	void searchname();		  //姓名查询
	void searchmajor();		  //专业查询
	void searchclass();		  //班级查询
	void searchmobile();	  //手机号查询
	//更新
	void updatename();   //更新姓名
	void updatemajor();  //更新专业
	void updateclass();  //更新班级
	void updatemobile(); //更新手机号
	//输出学生信息
	void dispall();   //所有学生
	void disp(int n); //一个学生

	friend ostream &operator<<(ostream &output, Student &s)
	{
		output << setw(20) << s.getno() << setw(20) << s.getname() << setw(20) << s.getmajor() << setw(20) << s.getclass() << setw(20) << s.getmobile();
		output << endl;
		return output;
	}

	friend istream &operator>>(istream &input, Student &s)
	{
		string sno, sname, sclass, smajor, smobile;
		input >> sno;
		s.setno(sno);
		input >> sname;
		s.setname(sname);
		input >> smajor;
		s.setmajor(smajor);
		input >> sclass;
		s.setclass(sclass);
		input >> smobile;
		s.setmobile(smobile);
		return input;
	}
};

//构造函数读入学生信息
Studentclass::Studentclass()
{
	top = 0;
	ifstream in("student.txt");
	if (!in)
	{
		cout << "文件打不开!" << endl;
	}
	while (!in.eof()) //eof返回标志是否到了文件末尾
	{
		in >> stu[top];
		top++;
	}
	in.close();
}

//析构函数输出学生信息
Studentclass::~Studentclass()
{
	ofstream out("student.txt");
	if (!out)
	{
		cout << "文件打不开!" << endl;
	}
	for (int i = 0; i < top; i++)
	{
		if (stu[i].gettag() == 0)
		{
			out << stu[i];
		}
	}
	out.close();
}

//设置人数
void Studentclass::settop(int n)
{
	top = n;
}

//获取人数
int Studentclass::gettop()
{
	return top;
}

//插入一个学生
void Studentclass::stu_append()
{
	string sno, sname, smajor, sclass, smobile;
	cout << "请输入要插入学生的学号:";
	cin >> sno;
	stu[top].setno(sno);
	cout << endl;
	cout << "请输入要插入学生的姓名:";
	cin >> sname;
	stu[top].setname(sname);
	cout << endl;
	cout << "请输入要插入学生的专业:";
	cin >> smajor;
	stu[top].setmajor(smajor);
	cout << endl;
	cout << "请输入要插入学生的班级:";
	cin >> sclass;
	stu[top].setclass(sclass);
	cout << endl;
	cout << "请输入要插入学生的手机号:";
	cin >> smobile;
	stu[top].setmobile(smobile);
	cout << endl;
	cout << "要插入的学生信息为:" << endl;
	stu[top].disp();
	cout << endl;
	top++;
}

//学号删除一个学生
void Studentclass::deleteno()
{
	int temp = -1; //要删除的学生下标
	string sno;
	cout << "请输入要删除学生的学号:";
	cin >> sno;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getno() == sno)
		{
			temp = i;
			stu[temp].settag();
		}
	}
	if (temp != -1)
		cout << "删除完成!" << endl
			 << endl;
	else
		cout << "没有找到学号为" << sno << "的学生!" << endl
			 << endl;
}

//姓名删除一个学生
void Studentclass::deletename()
{
	int temp = -1; //要删除的学生下标
	string sname;
	cout << "请输入要删除学生的姓名:";
	cin >> sname;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getname() == sname)
		{
			temp = i;
			stu[temp].settag();
		}
	}
	if (temp != -1)
		cout << "删除完成!" << endl
			 << endl;
	else
		cout << "没有找到姓名为" << sname << "的学生!" << endl
			 << endl;
}

//专业删除一个学生
void Studentclass::deletemajor()
{
	int temp = -1; //要删除的学生下标
	string smajor;
	cout << "请输入要删除学生的专业:";
	cin >> smajor;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getmajor() == smajor)
		{
			temp = i;
			stu[temp].settag();
		}
	}
	if (temp != -1)
		cout << "删除完成!" << endl
			 << endl;
	else
		cout << "没有找到专业为" << smajor << "的学生!" << endl
			 << endl;
}

//班级删除一个学生
void Studentclass::deleteclass()
{
	int temp = -1; //要删除的学生下标
	string sclass;
	cout << "请输入要删除学生的班级:";
	cin >> sclass;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getclass() == sclass)
		{
			temp = i;
			stu[temp].settag();
		}
	}
	if (temp != -1)
		cout << "删除完成!" << endl
			 << endl;
	else
		cout << "没有找到班级为" << sclass << "的学生!" << endl
			 << endl;
}

//手机号删除一个学生
void Studentclass::deletemobile()
{
	int temp = -1; //要删除的学生下标
	string smobile;
	cout << "请输入要删除学生的手机号:";
	cin >> smobile;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getmobile() == smobile)
		{
			temp = i;
			stu[temp].settag();
		}
	}
	if (temp != -1)
		cout << "删除完成!" << endl
			 << endl;
	else
		cout << "没有找到手机号为" << smobile << "的学生!" << endl
			 << endl;
}

//批量导入
void Studentclass::insertall()
{
	ifstream in("s.txt");
	if (!in)
	{
		cout << "文件打不开!" << endl;
	}
	while (!in.eof())
	{
		in >> stu[top];
		top++;
	}
	in.close();
	cout << "学生信息导入完成!" << endl
		 << endl;
}

//删除所有学生信息
void Studentclass::deleteall()
{
	for (int i = 0; i < top; i++)
	{
		stu[i].settag();
	}
	cout << "已全部删除!" << endl
		 << endl;
}

//学号查询
void Studentclass::searchno()
{
	int k = 0; //查询标记1:Yes 0:No
	string sno;
	cout << "请输入要查询学生的学号:";
	cin >> sno;
	cout << endl;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getno() == sno)
		{
			k = 1;
			cout << "Found学号为" << sno << "的学生!" << endl
				 << endl;
			stu[i].disp();
			cout << endl;
		}
	}
	if (k == 0)
		cout << "没有找到学号为" << sno << "的学生!" << endl
			 << endl;
}

int Studentclass::searchno(string sno)
{
	int k = -1;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getno() == sno)
			k = i;
	}
	return k;
}

//姓名查询
void Studentclass::searchname()
{
	int k = 0; //查询标记1:Yes 0:No
	string sname;
	cout << "请输入要查询学生的姓名:";
	cin >> sname;
	cout << endl;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getname() == sname)
		{
			k = 1;
			cout << "Found姓名为" << sname << "的学生!" << endl
				 << endl;
			stu[i].disp();
		}
	}
	if (k == 0)
		cout << "没有找到姓名为" << sname << "的学生!" << endl
			 << endl;
}

//专业查询
void Studentclass::searchmajor()
{
	int k = 0; //查询标记1:Yes 0:No
	string smajor;
	cout << "请输入要查询学生的专业:";
	cin >> smajor;
	cout << endl;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getmajor() == smajor)
		{
			k = 1;
			cout << "Found专业为" << smajor << "的学生!" << endl
				 << endl;
			stu[i].disp();
		}
	}
	if (k == 0)
		cout << "没有找到专业为" << smajor << "的学生!" << endl
			 << endl;
}

//班级查询
void Studentclass::searchclass()
{
	int k = 0; //查询标记1:Yes 0:No
	string sclass;
	cout << "请输入要查询学生的班级:";
	cin >> sclass;
	cout << endl;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getclass() == sclass)
		{
			k = 1;
			cout << "Found班级为" << sclass << "的学生!" << endl
				 << endl;
			stu[i].disp();
		}
	}
	if (k == 0)
		cout << "没有找到班级为" << sclass << "的学生!" << endl
			 << endl;
}

//手机号查询
void Studentclass::searchmobile()
{
	int k = 0; //查询标记1:Yes 0:No
	string smobile;
	cout << "请输入要查询学生的手机号:";
	cin >> smobile;
	cout << endl;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getmobile() == smobile)
		{
			k = 1;
			cout << "Found手机为" << smobile << "的学生!" << endl
				 << endl;
			stu[i].disp();
		}
	}
	if (k == 0)
		cout << "没有找到手机为" << smobile << "的学生!" << endl
			 << endl;
}

//更新姓名
void Studentclass::updatename()
{
	int k = 0; //查询标记1:Yes 0:No
	string sno;
	string sname;
	cout << "请输入要修改的学生的学号:";
	cin >> sno;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getno() == sno)
		{
			k = 1;
			cout << "请输入要修改的学生的姓名:";
			cin >> sname;
			stu[i].setname(sname);
			stu[i].disp();
			break;
		}
	}
	if (k == 0)
		cout << "没有找到学号为" << sno << "的学生!" << endl;
}

//更新专业
void Studentclass::updatemajor()
{
	int k = 0; //查询标记1:Yes 0:No
	string sno;
	string smajor;
	cout << "请输入要修改的学生的学号:";
	cin >> sno;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getno() == sno)
		{
			k = 1;
			cout << "请输入要修改的学生的专业:";
			cin >> smajor;
			stu[i].setmajor(smajor);
			stu[i].disp();
			break;
		}
	}
	if (k == 0)
		cout << "没有找到学号为" << sno << "的学生!" << endl;
}

//更新班级
void Studentclass::updateclass()
{
	int k = 0; //查询标记1:Yes 0:No
	string sno;
	string sclass;
	cout << "请输入要修改的学生的学号:";
	cin >> sno;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getno() == sno)
		{
			k = 1;
			cout << "请输入要修改的学生的班级:";
			cin >> sclass;
			stu[i].setclass(sclass);
			stu[i].disp();
			break;
		}
	}
	if (k == 0)
		cout << "没有找到学号为" << sno << "的学生!" << endl;
}

//更新手机号
void Studentclass::updatemobile()
{
	int k = 0; //查询标记1:Yes 0:No
	string sno;
	string smobile;
	cout << "请输入要修改的学生的学号:";
	cin >> sno;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getno() == sno)
		{
			k = 1;
			cout << "请输入要修改的学生的手机号:";
			cin >> smobile;
			stu[i].setmobile(smobile);
			stu[i].disp();
			break;
		}
	}
	if (k == 0)
		cout << "没有找到学号为" << sno << "的学生!" << endl;
}

//输出所有学生信息
void Studentclass::dispall()
{
	cout << "学生基本信息如下:" << endl
		 << endl;
	cout << "   学号" << setw(12) << "姓名" << setw(12) << "专业" << setw(12) << "班级" << setw(12) << "手机" << endl;
	for (int i = 0; i < top; i++)
	{
		stu[i].disp();
	}
}

//输出一个学生信息
void Studentclass::disp(int n)
{
	cout << "学生基本信息如下:" << endl;
	cout << "删除标记" << setw(8) << "学号" << setw(12) << "姓名" << setw(12) << "专业" << setw(12) << "班级" << setw(12) << "手机" << endl;
	stu[n].disp();
}

//Book	 图书类
class Book
{
  private:
	int tag;		  //删除标记1:已删0:未删
	string bookno;	//图书编号
	string bookname;  //书名
	string author;	//作者
	string publisher; //出版社
	int totalnum;	 //馆藏书量
	int borrownum;	//借出量
	int star;		  //图书星级1-5
  public:
	Book();
	~Book();
	int getbooktag();		   //获取删除标记
	void setbooktag();		   //设置删除标记
	string getbookno();		   //获取图书编号
	void setbookno(string);	//设置图书编号
	string getbookname();	  //获取书名
	void setbookname(string);  //设置书名
	string getauthor();		   //获取作者
	void setauthor(string);	//设置作者
	string getpublisher();	 //获取出版社
	void setpublisher(string); //设置出版社
	int gettotalnum();		   //获取馆藏书量
	void settotalnum(int);	 //设置馆藏书量
	int getborrownum();		   //获取借出量
	void setborrownum(int);	//设置借出量
	int getstar();			   //获取图书星级1-5
	void setstar(int);		   //设置图书星级1-5
	void dispbook();		   //显示图书信息
	void upborrownum();		   //借出量加1
	void downborrownum();	  //借出量减1
};

Book::Book()
{
	tag = 0;
	star = 0;
}

Book::~Book() {}

//获取删除标记
int Book::getbooktag()
{
	return tag;
}

//设置删除标记
void Book::setbooktag()
{
	tag = 1;
}

//获取图书编号
string Book::getbookno()
{
	return bookno;
}

//设置图书编号
void Book::setbookno(string bno)
{
	bookno = bno;
}

//获取书名
string Book::getbookname()
{
	return bookname;
}

//设置书名
void Book::setbookname(string bname)
{
	bookname = bname;
}

//获取作者
string Book::getauthor()
{
	return author;
}

//设置作者
void Book::setauthor(string bauthor)
{
	author = bauthor;
}

//获取出版社
string Book::getpublisher()
{
	return publisher;
}

//设置出版社
void Book::setpublisher(string bpublisher)
{
	publisher = bpublisher;
}

//获取馆藏书量
int Book::gettotalnum()
{
	return totalnum;
}

//设置馆藏书量
void Book::settotalnum(int btotalnum)
{
	totalnum = btotalnum;
}

//获取借出量
int Book::getborrownum()
{
	return borrownum;
}

//设置借出量
void Book::setborrownum(int bborrownum)
{
	borrownum = bborrownum;
}

//获取图书星级1-5
int Book::getstar()
{
	return star;
}

//设置图书星级1-5
void Book::setstar(int bstar)
{
	star = bstar;
}

//显示图书信息
void Book::dispbook()
{
	if (!tag)
	{
		cout << bookno << setw(20);
		cout << bookname << setw(15);
		cout << author << setw(15);
		cout << publisher << setw(7);
		cout << totalnum << setw(7);
		cout << borrownum << setw(9);
		for (int i = 0; i < getstar(); i++)
		{
			cout << "☆";
		}
		cout << endl;
	}
	cout << endl;
}

//借出量加1
void Book::upborrownum()
{
	borrownum++;
	cout << borrownum << endl;
}

//借出量减1
void Book::downborrownum()
{
	--borrownum;
	cout << borrownum << endl;
}

const int Maxb = 100;
//图书库类
class BookClass
{
  private:
	int top;		 //图书记录数量
	Book book[Maxb]; //图书记录
  public:
	BookClass();
	~BookClass();
	void settop(int n);		 //设置数量
	int gettop();			 //获取数量
	void getbookup(int i);   //找到对应图书+1
	void getbookdown(int i); //找到对应图书-1
	int bookstar(int i);	 //得到对应图书的星级
	//插入
	void book_append(); //插入一本书
	void insertall();   //批量插入
	//删除
	void deletebookno();	//图书编号删除
	void deletebookname();  //书名删除
	void deleteauthor();	//作者删除
	void deletepublisher(); //出版社删除
	void deletestar();		//星级删除
	void deleteall();		//删除所有图书信息
	//查询
	void searchbookno();		  //图书编号查询
	int searchbookno(string bno); //图书编号查询
	void searchbookname();		  //书名查询
	void searchauthor();		  //作者查询
	void searchpublisher();		  //出版社查询
	void searchstar();			  //图书星级查询
	//更新
	void updatebookname();  //更新书名
	void updateauthor();	//更新作者
	void updatepublisher(); //更新出版社
	void updatetotalnum();  //更新馆藏数量
	void updateborrownum(); //更新借出量
	void updatestar();		//更新星级
	//输出图书信息
	void dispbookall();   //所有图书
	void dispbook(int n); //输出一本书

	friend ostream &operator<<(ostream &output, Book &b)
	{
		output << setw(15) << b.getbookno();
		output << setw(30) << b.getbookname();
		output << setw(20) << b.getauthor();
		output << setw(20) << b.getpublisher();
		output << setw(5) << b.gettotalnum();
		output << setw(5) << b.getborrownum();
		output << setw(5) << b.getstar() << endl;
		return output;
	}

	friend istream &operator>>(istream &input, Book &b)
	{
		int btotalnum, bborrownum, bstar;
		string bno, bname, bauthor, bpublisher;
		input >> bno;
		b.setbookno(bno);
		input >> bname;
		b.setbookname(bname);
		input >> bauthor;
		b.setauthor(bauthor);
		input >> bpublisher;
		b.setpublisher(bpublisher);
		input >> btotalnum;
		b.settotalnum(btotalnum);
		input >> bborrownum;
		b.setborrownum(bborrownum);
		input >> bstar;
		b.setstar(bstar);
		return input;
	}
};

//构造函数读入图书信息
BookClass::BookClass()
{
	top = 0;
	ifstream in("book.txt");
	if (!in)
	{
		cout << "文件打不开!" << endl;
	}
	while (!in.eof())
	{
		in >> book[top];
		top++;
	}
	in.close();
}

//析构函数输出图书信息
BookClass::~BookClass()
{
	ofstream out("book.txt");
	if (!out)
	{
		cout << "文件不能打开!" << endl;
	}
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbooktag() == 0)
		{
			out << book[i];
		}
	}
	out.close();
}

//设置数量
void BookClass::settop(int n)
{
	top = n;
}

//获取数量
int BookClass::gettop()
{
	return top;
}

//得到对应图书的星级
int BookClass::bookstar(int i)
{
	int k;
	k = book[i].getstar();
	return k;
}

//找到对应图书借出量+1
void BookClass::getbookup(int i)
{
	book[i].upborrownum();
	book[i].dispbook();
}

//找到对应图书借出量-1
void BookClass::getbookdown(int i)
{
	book[i].downborrownum();
	book[i].dispbook();
}

//插入一本书
void BookClass::book_append()
{
	int btotalnum, bborrownum, bstar;
	string bno, bname, bauthor, bpublisher;
	cout << "请输入要插入书的图书编号:";
	cin >> bno;
	book[top].setbookno(bno);
	cout << endl;
	cout << "请输入要插入书的书名:";
	cin >> bname;
	book[top].setbookname(bname);
	cout << endl;
	cout << "请输入要插入书的作者:";
	cin >> bauthor;
	book[top].setauthor(bauthor);
	cout << endl;
	cout << "请输入要插入书的出版社:";
	cin >> bpublisher;
	book[top].setpublisher(bpublisher);
	cout << endl;
	cout << "请输入要插入书的馆藏数量:";
	cin >> btotalnum;
	book[top].settotalnum(btotalnum);
	cout << endl;
	cout << "请输入要插入书的借出量:";
	cin >> bborrownum;
	book[top].setborrownum(bborrownum);
	cout << endl;
	cout << "请输入要插入书的图书星级:";
	cin >> bstar;
	book[top].setstar(bstar);
	cout << endl;
	book[top].dispbook();
	top++;
}

//批量导入
void BookClass::insertall()
{
	ifstream in("b.txt");
	if (!in)
	{
		cout << "文件打不开!" << endl;
	}
	while (!in.eof())
	{
		in >> book[top];
		top++;
	}
	in.close();
}

//按图书编号删除
void BookClass::deletebookno()
{
	int temp = -1; //要删除的图书的下标
	string bno;
	cout << "请输入要删除图书的图书编号:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			temp = i;
		}
		if (temp != -1)
		{
			book[temp].setbooktag();
			cout << "删除完成!" << endl;
		}
	}
	if (temp == -1)
		cout << "没有找到图书编号为" << bno << "的图书!" << endl;
}

//按书名删除
void BookClass::deletebookname()
{
	int temp = -1; //要删除的图书的下标
	string bname;
	cout << "请输入要删除图书的书名:";
	cin >> bname;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookname() == bname)
		{
			temp = i;
		}
		if (temp != -1)
		{
			book[temp].setbooktag();
			cout << "删除完成!" << endl;
		}
	}
	if (temp == -1)
		cout << "没有找到书名为" << bname << "的图书!" << endl;
}

//按作者删除
void BookClass::deleteauthor()
{
	int temp = -1; //要删除的图书的下标
	string bauthor;
	cout << "请输入要删除图书的作者:";
	cin >> bauthor;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getauthor() == bauthor)
		{
			temp = i;
		}
		if (temp != -1)
		{
			book[temp].setbooktag();
			cout << "删除完成!" << endl;
		}
	}
	if (temp == -1)
		cout << "没有找到作者为" << bauthor << "的图书!" << endl;
}

//按出版社删除
void BookClass::deletepublisher()
{
	int temp = -1; //要删除的图书的下标
	string bpublisher;
	cout << "请输入要删除图书的出版社:";
	cin >> bpublisher;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getpublisher() == bpublisher)
		{
			temp = i;
		}
		if (temp != -1)
		{
			book[temp].setbooktag();
			cout << "删除完成!" << endl;
		}
	}
	if (temp == -1)
		cout << "没有找到出版社为" << bpublisher << "的图书!" << endl;
}

//按星级删除
void BookClass::deletestar()
{
	int temp = -1; //要删除的图书的下标
	int bstar;
	cout << "请输入要删除图书的星级:";
	cin >> bstar;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getstar() == bstar)
		{
			temp = i;
		}
		if (temp != -1)
		{
			book[temp].setbooktag();
			cout << "删除完成!" << endl;
		}
	}
	if (temp == -1)
	{
		cout << "没有找到星级为";
		for (int j = 0; j < bstar; j++)
		{
			cout << "☆";
		}
		cout << "的图书!" << endl;
	}
}

//删除所有图书信息
void BookClass::deleteall()
{
	for (int i = 0; i < top; i++)
	{
		book[i].setbooktag();
	}
}

//图书编号查询
void BookClass::searchbookno()
{
	int k = 0; //查询标记1:Yes 0:No
	string bno;
	cout << "请输入要查询书的图书编号:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			k = 1;
			cout << "Found图书编号为" << bno << "的书!" << endl;
			book[i].dispbook();
		}
	}
	if (k == 0)
		cout << "没有找到图书编号为" << bno << "的书!" << endl;
}

int BookClass::searchbookno(string bno)
{
	int k = -1;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
			k = i;
	}
	return k;
}

//书名查询
void BookClass::searchbookname()
{
	int k = 0; //查询标记1:Yes 0:No
	string bname;
	cout << "请输入要查询书的书名:";
	cin >> bname;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookname() == bname)
		{
			k = 1;
			cout << "Found书名为" << bname << "的书!" << endl;
			book[i].dispbook();
		}
	}
	if (k == 0)
		cout << "没有找到书名为" << bname << "的书!" << endl;
}

//作者查询
void BookClass::searchauthor()
{
	int k = 0; //查询标记1:Yes 0:No
	string bauthor;
	cout << "请输入要查询书的作者:";
	cin >> bauthor;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getauthor() == bauthor)
		{
			k = 1;
			cout << "Found作者为" << bauthor << "的书!" << endl;
			book[i].dispbook();
		}
	}
	if (k == 0)
		cout << "没有找到作者为" << bauthor << "的书!" << endl;
}

//出版社查询
void BookClass::searchpublisher()
{
	int k = 0; //查询标记1:Yes 0:No
	string bpublisher;
	cout << "请输入要查询书的出版社:";
	cin >> bpublisher;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getpublisher() == bpublisher)
		{
			k = 1;
			cout << "Found出版社为" << bpublisher << "的书!" << endl;
			book[i].dispbook();
		}
	}
	if (k == 0)
		cout << "没有找到出版社为" << bpublisher << "的书!" << endl;
}

//图书星级查询
void BookClass::searchstar()
{
	int k = 0; //查询标记1:Yes 0:No
	int bstar;
	cout << "请输入要查询书的图书星级:";
	cin >> bstar;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getstar() == bstar)
		{
			k = 1;
			cout << "Found图书星级为" << bstar << "的书!" << endl;
			book[i].dispbook();
		}
	}
	if (k == 0)
	{
		cout << "没有找到星级为";
		for (int j = 0; j < bstar; j++)
		{
			cout << "☆";
		}
		cout << "的图书!" << endl;
	}
}

//更新书名
void BookClass::updatebookname()
{
	int k = 0; //查询标记1:Yes 0:No
	string bno;
	string bname;
	cout << "请输入要修改的图书的图书编号:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			k = 1;
			cout << "请输入要修改的图书的书名:";
			cin >> bname;
			book[i].setbookname(bname);
			book[i].dispbook();
			break;
		}
	}
	if (k == 0)
		cout << "没有找到图书编号为" << bno << "的图书!" << endl;
}

//更新作者
void BookClass::updateauthor()
{
	int k = 0; //查询标记1:Yes 0:No
	string bno;
	string bauthor;
	cout << "请输入要修改的图书的图书编号:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			k = 1;
			cout << "请输入要修改的图书的作者:";
			cin >> bauthor;
			book[i].setauthor(bauthor);
			book[i].dispbook();
			break;
		}
	}
	if (k == 0)
		cout << "没有找到图书编号为" << bno << "的图书!" << endl;
}

//更新出版社
void BookClass::updatepublisher()
{
	int k = 0; //查询标记1:Yes 0:No
	string bno;
	string bpublisher;
	cout << "请输入要修改的图书的图书编号:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			k = 1;
			cout << "请输入要修改的图书的出版社:";
			cin >> bpublisher;
			book[i].setpublisher(bpublisher);
			book[i].dispbook();
			break;
		}
	}
	if (k == 0)
		cout << "没有找到图书编号为" << bno << "的图书!" << endl;
}

//更新馆藏数量
void BookClass::updatetotalnum()
{
	int k = 0; //查询标记1:Yes 0:No
	string bno;
	int btotalnum;
	cout << "请输入要修改的图书的图书编号:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			k = 1;
			cout << "请输入要修改的图书的馆藏数量:";
			cin >> btotalnum;
			book[i].settotalnum(btotalnum);
			book[i].dispbook();
			break;
		}
	}
	if (k == 0)
		cout << "没有找到图书编号为" << bno << "的图书!" << endl;
}

//更新借出量
void BookClass::updateborrownum()
{
	int k = 0; //查询标记1:Yes 0:No
	string bno;
	int bborrownum;
	cout << "请输入要修改的图书的图书编号:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			k = 1;
			cout << "请输入要修改的图书的借出量:";
			cin >> bborrownum;
			book[i].setborrownum(bborrownum);
			book[i].dispbook();
			break;
		}
	}
	if (k == 0)
		cout << "没有找到图书编号为" << bno << "的图书!" << endl;
}

//更新星级
void BookClass::updatestar()
{
	int k = 0; //查询标记1:Yes 0:No
	string bno;
	int bstar;
	cout << "请输入要修改的图书的图书编号:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			k = 1;
			cout << "请输入要修改的图书的星级:";
			cin >> bstar;
			book[i].setstar(bstar);
			book[i].dispbook();
			break;
		}
	}
	if (k == 0)
		cout << "没有找到图书编号为" << bno << "的图书!" << endl;
}

//输出所有图书信息
void BookClass::dispbookall()
{
	cout << "图书信息如下:" << endl;
	cout << "图书编号" << setw(12);
	cout << "书名" << setw(12);
	cout << "作者" << setw(12);
	cout << "出版社" << setw(12);
	cout << "馆藏数量" << setw(12);
	cout << "借出量" << setw(12);
	cout << "图书星级" << endl;
	for (int i = 0; i < top; i++)
	{
		book[i].dispbook();
	}
}

//输出一本书信息
void BookClass::dispbook(int n)
{
	cout << "该图书基本信息如下:" << endl;
	book[n].dispbook();
}

const int M = 5;

//借阅日期
class BorrowInfo
{
  public:
	string bookno;   //图书编号
	int borrowyear;  //借书年份
	int borrowmonth; //借书月份
	int borrowday;   //借书日期
	int backyear;	//还书年份
	int backmonth;   //还书月份
	int backday;	 //还书日期
};

//一个学生借阅信息
class BorrowNote
{
  private:
	string borrowno; //借阅学生的学号
	int top;

  public:
	BorrowInfo bookborrow[M]; //所借图书信息
	BorrowNote();
	~BorrowNote();
	void settop(int);												 //设置借阅图书数量
	int gettop();													 //获取借阅图书数量
	void setborrowno(string);										 //设置借阅学生的学号
	string getborrowno();											 //获取借阅学生的学号
	void setborrowday(int i, int boryear, int bormonth, int borday); //设置借书时间
	void setbackday(int i, int byear, int bmonth, int bday);		 //设置还书日期
	void borrowbook(string bno);									 //借书
	void backbook(string bno);										 //还书
	void disp();													 //显示借阅信息
};

//构造函数
BorrowNote::BorrowNote()
{
	top = 0;
}

//析构函数
BorrowNote::~BorrowNote() {}

//设置借阅图书数量
void BorrowNote::settop(int n)
{
	top = n;
}

//获取借阅图书数量
int BorrowNote::gettop()
{
	return top;
}

/*//设置借书年份
void BorrowNote::setborrowyear(int byear)
{
	borrowyear=byear;
}

//获取借书年份
int BorrowNote::getborrowyear()
{
    return borrowyear;
}

//设置借书月份
void BorrowNote::setborrowmonth(int bmonth)
{
	borrowmonth=bmonth;
}

//获取借书月份
int BorrowNote::getborrowmonth()
{
	return borrowmonth;    
}

//设置借书日期
void BorrowNote::setborrowday(int bday)
{
	borrowday=bday;
}

//获取借书日期
int BorrowNote::getborrowday()
{
	return borrowday;
}
*/

//设置借阅学生的学号
void BorrowNote::setborrowno(string borno)
{
	borrowno = borno;
}

//获取借阅学生的学号
string BorrowNote::getborrowno()
{
	return borrowno;
}

//设置借书时间
void BorrowNote::setborrowday(int i, int boryear, int bormonth, int borday)
{
	bookborrow[i].borrowyear = boryear;
	bookborrow[i].borrowmonth = bormonth;
	bookborrow[i].borrowday = borday;
}

//设置还书日期
void BorrowNote::setbackday(int i, int byear, int bmonth, int bday)
{
	bookborrow[i].backyear = byear;
	bookborrow[i].backmonth = bmonth;
	bookborrow[i].backday = bday;
}

//借书
void BorrowNote::borrowbook(string bno)
{
	time_t t;
	tm *tp;
	t = time(NULL);
	tp = localtime(&t);
	bookborrow[top].bookno = bno;					 //图书编号
	bookborrow[top].borrowyear = tp->tm_year + 1900; //借书年份
	bookborrow[top].borrowmonth = tp->tm_mon + 1;	//借书月份
	bookborrow[top].borrowday = tp->tm_mday;		 //借书日期
	bookborrow[top].backyear = 0;					 //还书年份
	bookborrow[top].backmonth = 0;					 //还书月份
	bookborrow[top].backday = 0;					 //还书日期
	top++;
}

//还书
void BorrowNote::backbook(string bno)
{
	int k = -1; //图书下标
	for (int i = 0; i < top; i++)
	{
		if (bookborrow[i].bookno == bno)
		{
			k = i;
		}
	}
	if (k == -1)
		cout << "您未借此书!" << endl;
	else
	{
		time_t t;
		tm *tp;
		t = time(NULL);
		tp = localtime(&t);
		bookborrow[k].backyear = tp->tm_year + 1900; //还书年份
		bookborrow[k].backmonth = tp->tm_mon + 1;	//还书月份
		bookborrow[k].backday = tp->tm_mday;		 //还书日期
	}
}

//显示借书信息
void BorrowNote::disp()
{
	cout << "学号为:" << borrowno << "的学生的借书信息如下:" << endl;
	for (int i = 0; i < top; i++)
	{
		cout << "图书编号:" << bookborrow[i].bookno << endl;
		cout << "借书日期:" << bookborrow[i].borrowyear << "年" << bookborrow[i].borrowmonth << "月" << bookborrow[i].borrowday << "日" << endl;
		if (bookborrow[i].backyear == 0)
			cout << "此书未还!" << endl;
		else
			cout << "还书日期:" << bookborrow[i].backyear << "年" << bookborrow[i].backmonth << "月" << bookborrow[i].backday << "日" << endl;
		cout << endl;
	}
}

class BorrowClass
{
  private:
	int top;
	BorrowNote note[Max];

  public:
	BorrowClass();
	~BorrowClass();
	void Insert(string borno, string bno);		//插入一个学生借阅信息
	void borrow(Studentclass &S, BookClass &B); //图书借阅
	void back(Studentclass &S, BookClass &B);   //图书归还
	void recommend(BookClass B);				//图书推荐
	//借阅信息查询
	void notesearchno();	 //按学号查询借书记录
	void notesearchbookno(); //按图书编号查询借书记录
	void notesearchname();   //按书名查询借书记录
	void notesearchdate();   //按借书日期查询借书记录
	void dispall();			 //显示所有借书记录

	friend ostream &operator<<(ostream &output, BorrowNote &D)
	{
		output << setw(20) << D.getborrowno();
		output << setw(5) << D.gettop();
		output << endl;
		for (int i = 0; i < D.gettop(); i++)
		{
			output << setw(20) << D.bookborrow[i].bookno;
			output << setw(6) << D.bookborrow[i].borrowyear;
			output << setw(4) << D.bookborrow[i].borrowmonth;
			output << setw(4) << D.bookborrow[i].borrowday;
			output << setw(6) << D.bookborrow[i].backyear;
			output << setw(4) << D.bookborrow[i].backmonth;
			output << setw(4) << D.bookborrow[i].backday;
		}
		output << endl;
		return output;
	}

	friend istream &operator>>(istream &input, BorrowNote &D)
	{
		string borno, bno;
		int t;
		int boryear, bormonth, borday, byear, bmonth, bday;
		input >> borno;
		D.setborrowno(borno);
		input >> t;
		D.settop(t);
		for (int i = 0; i < t; i++)
		{
			input >> bno;
			D.bookborrow[i].bookno = bno;
			input >> boryear >> bormonth >> borday;
			D.setborrowday(i, boryear, bormonth, borday);
			input >> byear >> bmonth >> bday;
			D.setbackday(i, byear, bmonth, bday);
		}
		return input;
	}
};

//构造函数读取借阅信息
BorrowClass::BorrowClass()
{
	top = 0;
	ifstream in("borrow.txt");
	if (!in)
	{
		cout << "文件打不开!" << endl;
	}
	while (!in.eof())
	{
		in >> note[top];
		top++;
	}
	in.close();
}

//析构函数输出借阅信息
BorrowClass::~BorrowClass()
{
	ofstream out("borrow.txt");
	if (!out)
	{
		cout << "文件打不开!" << endl;
	}
	for (int i = 0; i < top; i++)
	{
		out << note[i];
	}
	out.close();
}

//插入一个学生借阅信息
void BorrowClass::Insert(string borno, string bno)
{
	note[top].setborrowno(borno);
	note[top].borrowbook(bno);
	top++;
}

//图书借阅
void BorrowClass::borrow(Studentclass &S, BookClass &B)
{
	string borno;
	string bno;
	cout << "请输入您的学号:";
	cin >> borno;
	int k1 = S.searchno(borno);
	if (k1 == -1)
	{
		cout << "没有学号为:" << borno << "的学生" << endl
			 << endl;
		return;
	}
	cout << "请输入要借书的图书编号:";
	cin >> bno;
	int k2 = B.searchbookno(bno);
	if (k2 == -1)
	{
		cout << "没有图书编号为:" << bno << "的书" << endl
			 << endl;
		return;
	}
	int s = -1;
	int k = -1;
	for (int i = 0; i < top; i++)
	{
		if (note[i].getborrowno() == borno)
		{
			s = i;
			note[i].borrowbook(bno);
			k = B.searchbookno(bno);
			B.getbookup(k);
			cout << borno << "借阅" << bno << "成功!" << endl
				 << endl;
			break;
		}
	}
	if (s == -1)
	{
		Insert(borno, bno);
		k = B.searchbookno(bno);
		B.getbookup(k);
		cout << borno << "借阅" << bno << "成功!" << endl
			 << endl;
	}
}

//图书归还
void BorrowClass::back(Studentclass &S, BookClass &B)
{
	string borno;
	string bno;
	cout << "请输入您的学号:";
	cin >> borno;
	int k1 = S.searchno(borno);
	if (k1 == -1)
	{
		cout << "没有学号为:" << borno << "的学生" << endl
			 << endl;
		return;
	}
	cout << "请输入要借书的图书编号:";
	cin >> bno;
	int k2 = B.searchbookno(bno);
	if (k2 == -1)
	{
		cout << "没有图书编号为:" << bno << "的书" << endl
			 << endl;
		return;
	}
	int k = -1;
	for (int i = 0; i < top; i++)
	{
		if (note[i].getborrowno() == borno)
		{
			note[i].backbook(bno);
			k = B.searchbookno(bno);
			B.getbookdown(k);
			cout << borno << "还书" << bno << "成功!" << endl
				 << endl;
		}
	}
}

//图书推荐
void BorrowClass::recommend(BookClass B)
{
	int s;
	for (int i = 0; i < B.gettop() - 1; i++)
	{
		s = B.bookstar(i);
		if (s == 5)
		{
			B.dispbook(i);
		}
	}
	for (i = 0; i < B.gettop() - 1; i++)
	{
		s = B.bookstar(i);
		if (s == 4)
		{
			B.dispbook(i);
		}
	}
	for (i = 0; i < B.gettop() - 1; i++)
	{
		s = B.bookstar(i);
		if (s == 3)
		{
			B.dispbook(i);
		}
	}
	for (i = 0; i < B.gettop() - 1; i++)
	{
		s = B.bookstar(i);
		if (s == 2)
		{
			B.dispbook(i);
		}
	}
	for (i = 0; i < B.gettop() - 1; i++)
	{
		s = B.bookstar(i);
		if (s == 1)
		{
			B.dispbook(i);
		}
	}
}

//按学号查询借书记录
void BorrowClass::notesearchno()
{
	int k = -1;
	string borno;
	cout << "请输入您的学号:";
	cin >> borno;
	for (int i = 0; i < top; i++)
	{
		if (note[i].getborrowno() == borno)
		{
			k = i;
			note[i].disp();
		}
	}
	if (k == -1)
	{
		cout << "学号为:" << borno << "的学生没有借书!" << endl
			 << endl;
	}
}

/*//按图书编号查询借书记录
void BorrowClass::notesearchbookno()
{
	int k=-1;
	string bno;
	cout<<"请输入您要查询的图书编号:";
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
		cout<<"图书编号为:"<<bno<<"的图书未被借出!"<<endl;
	}
}

//按书名查询借书记录
void BorrowClass::notesearchname()
{
	int k=-1;
	string bname;
	cout<<"请输入您要查询的书名:";
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
		cout<<"书名为:"<<bname<<"的图书未被借出!"<<endl;
	}
}

//按借书日期查询借书记录
void BorrowClass::notesearchdate()
{
	int k=-1;
	int byear;
	int bmonth;
	int bday;
	cout<<"请输入您要查询的借书日期:"<<endl;
	cout<<"请输入年份:";
	cin>>byear;
	cout<<endl<<"请输入年份:";
	cin>>bmonth;
	cout<<endl<<"请输入日期:";
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
		cout<<byear<<"年"<<bmonth<<"月"<<bday<<"日"<<"没有人借书!"<<endl;
	}
}
*/

//显示所有借书记录
void BorrowClass::dispall()
{
	for (int i = 0; i < top; i++)
		note[i].disp();
}

//子菜单
//单个学生毕业
void stu_detete_menu(Studentclass &S)
{
	int choise;
	cout << "1.按学号删除" << endl
		 << endl;
	cout << "2.按姓名删除" << endl
		 << endl;
	cout << "3.按专业删除" << endl
		 << endl;
	cout << "4.按班级删除" << endl
		 << endl;
	cout << "5.按手机号删除" << endl
		 << endl;
	cout << "0.退出" << endl
		 << endl;
	cout << "请输入(0--5):";
	cin >> choise;
	switch (choise)
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
		cout << "输入错误,请重新输入!" << endl;
	}
}

//子菜单
//学生信息查询
void stu_search_menu(Studentclass &S)
{
	int choise;
	cout << "1.查询学号" << endl
		 << endl;
	cout << "2.查询姓名" << endl
		 << endl;
	cout << "3.查询专业" << endl
		 << endl;
	cout << "4.查询班级" << endl
		 << endl;
	cout << "5.查询手机号" << endl
		 << endl;
	cout << "0.退出" << endl
		 << endl;
	cout << "请输入(0--5):";
	cin >> choise;
	switch (choise)
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
		cout << "输入错误,请重新输入!" << endl;
	}
}

//子菜单
//学生信息修改
void stu_update_menu(Studentclass &S)
{
	int choise;
	cout << "1.更新姓名" << endl
		 << endl;
	cout << "2.更新专业" << endl
		 << endl;
	cout << "3.更新班级" << endl
		 << endl;
	cout << "4.更新手机号" << endl
		 << endl;
	cout << "0.退出" << endl
		 << endl;
	cout << "请输入(0--4):";
	cin >> choise;
	switch (choise)
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
		cout << "输入错误,请重新输入!" << endl;
	}
}

void stu_main_menu(Studentclass &S)
{
	int choise;
	cout << setw(6) << "☆☆☆  欢迎使用学生信息管理系统  ☆☆☆" << endl
		 << endl;
	cout << "       1.单个学生入学" << endl
		 << endl;
	cout << "       2.单个学生毕业" << endl
		 << endl;
	cout << "       3.批量学生导入" << endl
		 << endl;
	cout << "       4.批量学生删除" << endl
		 << endl;
	cout << "       5.学生信息查询" << endl
		 << endl;
	cout << "       6.学生信息修改" << endl
		 << endl;
	cout << "       7.显示所有学生信息" << endl
		 << endl;
	cout << "       0.退出系统" << endl
		 << endl;
	cout << "       请输入(0--7):";
	cin >> choise;
	switch (choise)
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
	case 6:
		stu_update_menu(S);
		break;
	case 7:
		S.dispall();
		break;
	case 0:
		return;
	default:
		cout << "输入错误,请重新输入!" << endl;
	}
}

//子菜单
//单本图书删除
void book_delete_menu(BookClass &B)
{
	int choise;
	cout << "1.按图书编号删除" << endl
		 << endl;
	cout << "2.按书名删除" << endl
		 << endl;
	cout << "3.按作者删除" << endl
		 << endl;
	cout << "4.按出版社删除" << endl
		 << endl;
	cout << "5.按星级删除" << endl
		 << endl;
	cout << "0.退出" << endl
		 << endl;
	cout << "请输入(0--5):";
	cin >> choise;
	switch (choise)
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
		cout << "输入错误,请重新输入!" << endl;
	}
}

//子菜单
//图书信息查询
void book_search_menu(BookClass &B)
{
	int choise;
	cout << "1.按图书编号查询" << endl
		 << endl;
	cout << "2.按书名查询" << endl
		 << endl;
	cout << "3.按作者查询" << endl
		 << endl;
	cout << "4.按出版社查询" << endl
		 << endl;
	cout << "5.按星级查询" << endl
		 << endl;
	cout << "0.退出" << endl
		 << endl;
	cout << "请输入(0--5):";
	cin >> choise;
	switch (choise)
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
		cout << "输入错误,请重新输入!" << endl;
	}
}

//子菜单
//更新图书信息
void book_update_menu(BookClass &B)
{
	int choise;
	cout << "1.更新书名" << endl
		 << endl;
	cout << "2.更新作者" << endl
		 << endl;
	cout << "3.更新出版社" << endl
		 << endl;
	cout << "4.更新馆藏数量" << endl
		 << endl;
	cout << "5.更新借出量" << endl
		 << endl;
	cout << "6.更新星级" << endl
		 << endl;
	cout << "0.退出" << endl
		 << endl;
	cout << "请输入(0--6):";
	cin >> choise;
	system("cls");
	switch (choise)
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
		cout << "输入错误,请重新输入!" << endl;
	}
}

void book_main_menu(BookClass &B)
{
	int choise;
	cout << "☆☆☆  欢迎使用图书管理系统  ☆☆☆" << endl
		 << endl;
	cout << "       1.单本图书插入" << endl
		 << endl;
	cout << "       2.批量图书插入" << endl
		 << endl;
	cout << "       3.单本图书删除" << endl
		 << endl;
	cout << "       4.批量图书删除" << endl
		 << endl;
	cout << "       5.图书信息查询" << endl
		 << endl;
	cout << "       6.更新图书信息" << endl
		 << endl;
	cout << "       7.输出所有图书信息" << endl
		 << endl;
	cout << "       0.退出" << endl
		 << endl;
	cout << "       请输入(0--7):";
	cin >> choise;
	system("cls");
	switch (choise)
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
		cout << "输入错误,请重新输入!" << endl;
	}
}

void borrow_note_menu(Studentclass &S, BookClass &B, BorrowClass &N)
{
	int choise;
	cout << "☆☆☆  欢迎使用读者借阅管理系统  ☆☆☆" << endl
		 << endl;
	cout << "       1.图书借阅" << endl
		 << endl;
	cout << "       2.图书归还" << endl
		 << endl;
	cout << "       3.查询借书记录" << endl
		 << endl;
	cout << "       4.推荐图书" << endl
		 << endl;
	cout << "       5.显示所有借书记录" << endl
		 << endl;
	cout << "       0.退出" << endl
		 << endl;
	cout << "       请输入(0--5):";
	cin >> choise;
	system("cls");
	switch (choise)
	{
	case 1:
		N.borrow(S, B);
		break;
	case 2:
		N.back(S, B);
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
		cout << "输入错误,请重新输入!" << endl;
	}
}

int main()
{
	int choise1 = 1, choise2 = 1, choise3 = 1;
	string a, pw;
	int flag = 111;
begin:
	cout << endl
		 << endl
		 << endl
		 << endl
		 << endl
		 << endl;
	cout << setw(40) << "请输入您的身份:";
	{
		cin >> a;
		if (a == "111")
		{
			cout << setw(38) << "请输入密码:";
			cin >> pw;
			if (pw == "000")
			{
				cout << "登陆成功!" << endl;
				system("cls");
			}
			else
			{
				cout << "密码错误!请重新输入!" << endl;
				goto begin;
			}
		}
	}
	int choise;
	Studentclass S;
	BookClass B;
	BorrowClass N;
	for (;;)
	{
		cout << setw(6) << " ☆☆☆☆  欢迎使用图书管理系统  ☆☆☆☆" << endl
			 << endl;
		cout << "          1.学生信息管理系统" << endl
			 << endl;
		cout << "          2.图书管理系统" << endl
			 << endl;
		cout << "          3.读者借阅管理系统" << endl
			 << endl;
		cout << "          0.退出系统" << endl
			 << endl;
		cout << "          请选择(0--3):";
		cin >> choise;
		system("cls");
		switch (choise)
		{
		case 1:
			stu_main_menu(S);
			break;
		case 2:
			book_main_menu(B);
			break;
		case 3:
			borrow_note_menu(S, B, N);
			break;
		case 0:
			cout << endl;
			cout << "欢迎使用图书管理系统,请提出宝贵意见!" << endl;
			return 0;
		default:
			cout << "输入错误,请重新输入!" << endl;
		}
	}
	return 0;
}
