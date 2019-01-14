#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
using namespace std;

//Student��
class Student
{
  private:
	int tag;			  //ɾ�����1:��ɾ0:δɾ
	string studentno;	 //ѧ��
	string studentname;   //����
	string studentmajor;  //רҵ
	string studentclass;  //�༶
	string studentmobile; //�ֻ�
  public:
	Student();
	int gettag();			//��ȡɾ�����
	void settag();			//����ɾ�����
	string getno();			//��ȡѧ��
	void setno(string);		//����ѧ��
	string getname();		//��ȡ����
	void setname(string);   //��������
	string getmajor();		//��ȡרҵ
	void setmajor(string);  //����רҵ
	string getclass();		//��ȡ�༶
	void setclass(string);  //���ð༶
	string getmobile();		//��ȡ�ֻ���
	void setmobile(string); //�����ֻ���
	void disp();			//���ѧ����Ϣ
	~Student();
};

//ȱʡ���캯��
Student::Student()
{
	tag = 0;
}

//��������
Student::~Student() {}

//��ȡɾ�����
int Student::gettag()
{
	return tag;
}

//����ɾ�����
void Student::settag()
{
	tag = 1;
}

//��ȡѧ��
string Student::getno()
{
	return studentno;
}

//����ѧ��
void Student::setno(string sno)
{
	studentno = sno;
}

//��ȡ����
string Student::getname()
{
	return studentname;
}

//��������
void Student::setname(string sname)
{
	studentname = sname;
}

//��ȡרҵ
string Student::getmajor()
{
	return studentmajor;
}

//����רҵ
void Student::setmajor(string smajor)
{
	studentmajor = smajor;
}

//��ȡ�༶
string Student::getclass()
{
	return studentclass;
}

//���ð༶
void Student::setclass(string sclass)
{
	studentclass = sclass;
}

//��ȡ�ֻ���
string Student::getmobile()
{
	return studentmobile;
}

//�����ֻ���
void Student::setmobile(string smobile)
{
	studentmobile = smobile;
}

//���ѧ����Ϣ
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
	Student stu[Max]; //ѧ����¼
  public:
	Studentclass();
	~Studentclass();
	void settop(int n); //��������
	int gettop();		//��ȡ����

	//����
	void stu_append();   //����һ��ѧ��
						 //ɾ��һ��ѧ��
	void deleteno();	 //ѧ��ɾ��
	void deletename();   //����ɾ��
	void deletemajor();  //רҵɾ��
	void deleteclass();  //�༶ɾ��
	void deletemobile(); //�ֻ���ɾ��
	void deleteall();	//ɾ������ѧ����Ϣ

	void insertall(); //��������
	//��ѯ
	void searchno();		  //ѧ�Ų�ѯ
	int searchno(string sno); //ѧ�Ų�ѯ
	void searchname();		  //������ѯ
	void searchmajor();		  //רҵ��ѯ
	void searchclass();		  //�༶��ѯ
	void searchmobile();	  //�ֻ��Ų�ѯ
	//����
	void updatename();   //��������
	void updatemajor();  //����רҵ
	void updateclass();  //���°༶
	void updatemobile(); //�����ֻ���
	//���ѧ����Ϣ
	void dispall();   //����ѧ��
	void disp(int n); //һ��ѧ��

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

//���캯������ѧ����Ϣ
Studentclass::Studentclass()
{
	top = 0;
	ifstream in("student.txt");
	if (!in)
	{
		cout << "�ļ��򲻿�!" << endl;
	}
	while (!in.eof()) //eof���ر�־�Ƿ����ļ�ĩβ
	{
		in >> stu[top];
		top++;
	}
	in.close();
}

//�����������ѧ����Ϣ
Studentclass::~Studentclass()
{
	ofstream out("student.txt");
	if (!out)
	{
		cout << "�ļ��򲻿�!" << endl;
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

//��������
void Studentclass::settop(int n)
{
	top = n;
}

//��ȡ����
int Studentclass::gettop()
{
	return top;
}

//����һ��ѧ��
void Studentclass::stu_append()
{
	string sno, sname, smajor, sclass, smobile;
	cout << "������Ҫ����ѧ����ѧ��:";
	cin >> sno;
	stu[top].setno(sno);
	cout << endl;
	cout << "������Ҫ����ѧ��������:";
	cin >> sname;
	stu[top].setname(sname);
	cout << endl;
	cout << "������Ҫ����ѧ����רҵ:";
	cin >> smajor;
	stu[top].setmajor(smajor);
	cout << endl;
	cout << "������Ҫ����ѧ���İ༶:";
	cin >> sclass;
	stu[top].setclass(sclass);
	cout << endl;
	cout << "������Ҫ����ѧ�����ֻ���:";
	cin >> smobile;
	stu[top].setmobile(smobile);
	cout << endl;
	cout << "Ҫ�����ѧ����ϢΪ:" << endl;
	stu[top].disp();
	cout << endl;
	top++;
}

//ѧ��ɾ��һ��ѧ��
void Studentclass::deleteno()
{
	int temp = -1; //Ҫɾ����ѧ���±�
	string sno;
	cout << "������Ҫɾ��ѧ����ѧ��:";
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
		cout << "ɾ�����!" << endl
			 << endl;
	else
		cout << "û���ҵ�ѧ��Ϊ" << sno << "��ѧ��!" << endl
			 << endl;
}

//����ɾ��һ��ѧ��
void Studentclass::deletename()
{
	int temp = -1; //Ҫɾ����ѧ���±�
	string sname;
	cout << "������Ҫɾ��ѧ��������:";
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
		cout << "ɾ�����!" << endl
			 << endl;
	else
		cout << "û���ҵ�����Ϊ" << sname << "��ѧ��!" << endl
			 << endl;
}

//רҵɾ��һ��ѧ��
void Studentclass::deletemajor()
{
	int temp = -1; //Ҫɾ����ѧ���±�
	string smajor;
	cout << "������Ҫɾ��ѧ����רҵ:";
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
		cout << "ɾ�����!" << endl
			 << endl;
	else
		cout << "û���ҵ�רҵΪ" << smajor << "��ѧ��!" << endl
			 << endl;
}

//�༶ɾ��һ��ѧ��
void Studentclass::deleteclass()
{
	int temp = -1; //Ҫɾ����ѧ���±�
	string sclass;
	cout << "������Ҫɾ��ѧ���İ༶:";
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
		cout << "ɾ�����!" << endl
			 << endl;
	else
		cout << "û���ҵ��༶Ϊ" << sclass << "��ѧ��!" << endl
			 << endl;
}

//�ֻ���ɾ��һ��ѧ��
void Studentclass::deletemobile()
{
	int temp = -1; //Ҫɾ����ѧ���±�
	string smobile;
	cout << "������Ҫɾ��ѧ�����ֻ���:";
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
		cout << "ɾ�����!" << endl
			 << endl;
	else
		cout << "û���ҵ��ֻ���Ϊ" << smobile << "��ѧ��!" << endl
			 << endl;
}

//��������
void Studentclass::insertall()
{
	ifstream in("s.txt");
	if (!in)
	{
		cout << "�ļ��򲻿�!" << endl;
	}
	while (!in.eof())
	{
		in >> stu[top];
		top++;
	}
	in.close();
	cout << "ѧ����Ϣ�������!" << endl
		 << endl;
}

//ɾ������ѧ����Ϣ
void Studentclass::deleteall()
{
	for (int i = 0; i < top; i++)
	{
		stu[i].settag();
	}
	cout << "��ȫ��ɾ��!" << endl
		 << endl;
}

//ѧ�Ų�ѯ
void Studentclass::searchno()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string sno;
	cout << "������Ҫ��ѯѧ����ѧ��:";
	cin >> sno;
	cout << endl;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getno() == sno)
		{
			k = 1;
			cout << "Foundѧ��Ϊ" << sno << "��ѧ��!" << endl
				 << endl;
			stu[i].disp();
			cout << endl;
		}
	}
	if (k == 0)
		cout << "û���ҵ�ѧ��Ϊ" << sno << "��ѧ��!" << endl
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

//������ѯ
void Studentclass::searchname()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string sname;
	cout << "������Ҫ��ѯѧ��������:";
	cin >> sname;
	cout << endl;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getname() == sname)
		{
			k = 1;
			cout << "Found����Ϊ" << sname << "��ѧ��!" << endl
				 << endl;
			stu[i].disp();
		}
	}
	if (k == 0)
		cout << "û���ҵ�����Ϊ" << sname << "��ѧ��!" << endl
			 << endl;
}

//רҵ��ѯ
void Studentclass::searchmajor()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string smajor;
	cout << "������Ҫ��ѯѧ����רҵ:";
	cin >> smajor;
	cout << endl;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getmajor() == smajor)
		{
			k = 1;
			cout << "FoundרҵΪ" << smajor << "��ѧ��!" << endl
				 << endl;
			stu[i].disp();
		}
	}
	if (k == 0)
		cout << "û���ҵ�רҵΪ" << smajor << "��ѧ��!" << endl
			 << endl;
}

//�༶��ѯ
void Studentclass::searchclass()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string sclass;
	cout << "������Ҫ��ѯѧ���İ༶:";
	cin >> sclass;
	cout << endl;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getclass() == sclass)
		{
			k = 1;
			cout << "Found�༶Ϊ" << sclass << "��ѧ��!" << endl
				 << endl;
			stu[i].disp();
		}
	}
	if (k == 0)
		cout << "û���ҵ��༶Ϊ" << sclass << "��ѧ��!" << endl
			 << endl;
}

//�ֻ��Ų�ѯ
void Studentclass::searchmobile()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string smobile;
	cout << "������Ҫ��ѯѧ�����ֻ���:";
	cin >> smobile;
	cout << endl;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getmobile() == smobile)
		{
			k = 1;
			cout << "Found�ֻ�Ϊ" << smobile << "��ѧ��!" << endl
				 << endl;
			stu[i].disp();
		}
	}
	if (k == 0)
		cout << "û���ҵ��ֻ�Ϊ" << smobile << "��ѧ��!" << endl
			 << endl;
}

//��������
void Studentclass::updatename()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string sno;
	string sname;
	cout << "������Ҫ�޸ĵ�ѧ����ѧ��:";
	cin >> sno;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getno() == sno)
		{
			k = 1;
			cout << "������Ҫ�޸ĵ�ѧ��������:";
			cin >> sname;
			stu[i].setname(sname);
			stu[i].disp();
			break;
		}
	}
	if (k == 0)
		cout << "û���ҵ�ѧ��Ϊ" << sno << "��ѧ��!" << endl;
}

//����רҵ
void Studentclass::updatemajor()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string sno;
	string smajor;
	cout << "������Ҫ�޸ĵ�ѧ����ѧ��:";
	cin >> sno;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getno() == sno)
		{
			k = 1;
			cout << "������Ҫ�޸ĵ�ѧ����רҵ:";
			cin >> smajor;
			stu[i].setmajor(smajor);
			stu[i].disp();
			break;
		}
	}
	if (k == 0)
		cout << "û���ҵ�ѧ��Ϊ" << sno << "��ѧ��!" << endl;
}

//���°༶
void Studentclass::updateclass()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string sno;
	string sclass;
	cout << "������Ҫ�޸ĵ�ѧ����ѧ��:";
	cin >> sno;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getno() == sno)
		{
			k = 1;
			cout << "������Ҫ�޸ĵ�ѧ���İ༶:";
			cin >> sclass;
			stu[i].setclass(sclass);
			stu[i].disp();
			break;
		}
	}
	if (k == 0)
		cout << "û���ҵ�ѧ��Ϊ" << sno << "��ѧ��!" << endl;
}

//�����ֻ���
void Studentclass::updatemobile()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string sno;
	string smobile;
	cout << "������Ҫ�޸ĵ�ѧ����ѧ��:";
	cin >> sno;
	for (int i = 0; i < top; i++)
	{
		if (stu[i].getno() == sno)
		{
			k = 1;
			cout << "������Ҫ�޸ĵ�ѧ�����ֻ���:";
			cin >> smobile;
			stu[i].setmobile(smobile);
			stu[i].disp();
			break;
		}
	}
	if (k == 0)
		cout << "û���ҵ�ѧ��Ϊ" << sno << "��ѧ��!" << endl;
}

//�������ѧ����Ϣ
void Studentclass::dispall()
{
	cout << "ѧ��������Ϣ����:" << endl
		 << endl;
	cout << "   ѧ��" << setw(12) << "����" << setw(12) << "רҵ" << setw(12) << "�༶" << setw(12) << "�ֻ�" << endl;
	for (int i = 0; i < top; i++)
	{
		stu[i].disp();
	}
}

//���һ��ѧ����Ϣ
void Studentclass::disp(int n)
{
	cout << "ѧ��������Ϣ����:" << endl;
	cout << "ɾ�����" << setw(8) << "ѧ��" << setw(12) << "����" << setw(12) << "רҵ" << setw(12) << "�༶" << setw(12) << "�ֻ�" << endl;
	stu[n].disp();
}

//Book	 ͼ����
class Book
{
  private:
	int tag;		  //ɾ�����1:��ɾ0:δɾ
	string bookno;	//ͼ����
	string bookname;  //����
	string author;	//����
	string publisher; //������
	int totalnum;	 //�ݲ�����
	int borrownum;	//�����
	int star;		  //ͼ���Ǽ�1-5
  public:
	Book();
	~Book();
	int getbooktag();		   //��ȡɾ�����
	void setbooktag();		   //����ɾ�����
	string getbookno();		   //��ȡͼ����
	void setbookno(string);	//����ͼ����
	string getbookname();	  //��ȡ����
	void setbookname(string);  //��������
	string getauthor();		   //��ȡ����
	void setauthor(string);	//��������
	string getpublisher();	 //��ȡ������
	void setpublisher(string); //���ó�����
	int gettotalnum();		   //��ȡ�ݲ�����
	void settotalnum(int);	 //���ùݲ�����
	int getborrownum();		   //��ȡ�����
	void setborrownum(int);	//���ý����
	int getstar();			   //��ȡͼ���Ǽ�1-5
	void setstar(int);		   //����ͼ���Ǽ�1-5
	void dispbook();		   //��ʾͼ����Ϣ
	void upborrownum();		   //�������1
	void downborrownum();	  //�������1
};

Book::Book()
{
	tag = 0;
	star = 0;
}

Book::~Book() {}

//��ȡɾ�����
int Book::getbooktag()
{
	return tag;
}

//����ɾ�����
void Book::setbooktag()
{
	tag = 1;
}

//��ȡͼ����
string Book::getbookno()
{
	return bookno;
}

//����ͼ����
void Book::setbookno(string bno)
{
	bookno = bno;
}

//��ȡ����
string Book::getbookname()
{
	return bookname;
}

//��������
void Book::setbookname(string bname)
{
	bookname = bname;
}

//��ȡ����
string Book::getauthor()
{
	return author;
}

//��������
void Book::setauthor(string bauthor)
{
	author = bauthor;
}

//��ȡ������
string Book::getpublisher()
{
	return publisher;
}

//���ó�����
void Book::setpublisher(string bpublisher)
{
	publisher = bpublisher;
}

//��ȡ�ݲ�����
int Book::gettotalnum()
{
	return totalnum;
}

//���ùݲ�����
void Book::settotalnum(int btotalnum)
{
	totalnum = btotalnum;
}

//��ȡ�����
int Book::getborrownum()
{
	return borrownum;
}

//���ý����
void Book::setborrownum(int bborrownum)
{
	borrownum = bborrownum;
}

//��ȡͼ���Ǽ�1-5
int Book::getstar()
{
	return star;
}

//����ͼ���Ǽ�1-5
void Book::setstar(int bstar)
{
	star = bstar;
}

//��ʾͼ����Ϣ
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
			cout << "��";
		}
		cout << endl;
	}
	cout << endl;
}

//�������1
void Book::upborrownum()
{
	borrownum++;
	cout << borrownum << endl;
}

//�������1
void Book::downborrownum()
{
	--borrownum;
	cout << borrownum << endl;
}

const int Maxb = 100;
//ͼ�����
class BookClass
{
  private:
	int top;		 //ͼ���¼����
	Book book[Maxb]; //ͼ���¼
  public:
	BookClass();
	~BookClass();
	void settop(int n);		 //��������
	int gettop();			 //��ȡ����
	void getbookup(int i);   //�ҵ���Ӧͼ��+1
	void getbookdown(int i); //�ҵ���Ӧͼ��-1
	int bookstar(int i);	 //�õ���Ӧͼ����Ǽ�
	//����
	void book_append(); //����һ����
	void insertall();   //��������
	//ɾ��
	void deletebookno();	//ͼ����ɾ��
	void deletebookname();  //����ɾ��
	void deleteauthor();	//����ɾ��
	void deletepublisher(); //������ɾ��
	void deletestar();		//�Ǽ�ɾ��
	void deleteall();		//ɾ������ͼ����Ϣ
	//��ѯ
	void searchbookno();		  //ͼ���Ų�ѯ
	int searchbookno(string bno); //ͼ���Ų�ѯ
	void searchbookname();		  //������ѯ
	void searchauthor();		  //���߲�ѯ
	void searchpublisher();		  //�������ѯ
	void searchstar();			  //ͼ���Ǽ���ѯ
	//����
	void updatebookname();  //��������
	void updateauthor();	//��������
	void updatepublisher(); //���³�����
	void updatetotalnum();  //���¹ݲ�����
	void updateborrownum(); //���½����
	void updatestar();		//�����Ǽ�
	//���ͼ����Ϣ
	void dispbookall();   //����ͼ��
	void dispbook(int n); //���һ����

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

//���캯������ͼ����Ϣ
BookClass::BookClass()
{
	top = 0;
	ifstream in("book.txt");
	if (!in)
	{
		cout << "�ļ��򲻿�!" << endl;
	}
	while (!in.eof())
	{
		in >> book[top];
		top++;
	}
	in.close();
}

//�����������ͼ����Ϣ
BookClass::~BookClass()
{
	ofstream out("book.txt");
	if (!out)
	{
		cout << "�ļ����ܴ�!" << endl;
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

//��������
void BookClass::settop(int n)
{
	top = n;
}

//��ȡ����
int BookClass::gettop()
{
	return top;
}

//�õ���Ӧͼ����Ǽ�
int BookClass::bookstar(int i)
{
	int k;
	k = book[i].getstar();
	return k;
}

//�ҵ���Ӧͼ������+1
void BookClass::getbookup(int i)
{
	book[i].upborrownum();
	book[i].dispbook();
}

//�ҵ���Ӧͼ������-1
void BookClass::getbookdown(int i)
{
	book[i].downborrownum();
	book[i].dispbook();
}

//����һ����
void BookClass::book_append()
{
	int btotalnum, bborrownum, bstar;
	string bno, bname, bauthor, bpublisher;
	cout << "������Ҫ�������ͼ����:";
	cin >> bno;
	book[top].setbookno(bno);
	cout << endl;
	cout << "������Ҫ�����������:";
	cin >> bname;
	book[top].setbookname(bname);
	cout << endl;
	cout << "������Ҫ�����������:";
	cin >> bauthor;
	book[top].setauthor(bauthor);
	cout << endl;
	cout << "������Ҫ������ĳ�����:";
	cin >> bpublisher;
	book[top].setpublisher(bpublisher);
	cout << endl;
	cout << "������Ҫ������Ĺݲ�����:";
	cin >> btotalnum;
	book[top].settotalnum(btotalnum);
	cout << endl;
	cout << "������Ҫ������Ľ����:";
	cin >> bborrownum;
	book[top].setborrownum(bborrownum);
	cout << endl;
	cout << "������Ҫ�������ͼ���Ǽ�:";
	cin >> bstar;
	book[top].setstar(bstar);
	cout << endl;
	book[top].dispbook();
	top++;
}

//��������
void BookClass::insertall()
{
	ifstream in("b.txt");
	if (!in)
	{
		cout << "�ļ��򲻿�!" << endl;
	}
	while (!in.eof())
	{
		in >> book[top];
		top++;
	}
	in.close();
}

//��ͼ����ɾ��
void BookClass::deletebookno()
{
	int temp = -1; //Ҫɾ����ͼ����±�
	string bno;
	cout << "������Ҫɾ��ͼ���ͼ����:";
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
			cout << "ɾ�����!" << endl;
		}
	}
	if (temp == -1)
		cout << "û���ҵ�ͼ����Ϊ" << bno << "��ͼ��!" << endl;
}

//������ɾ��
void BookClass::deletebookname()
{
	int temp = -1; //Ҫɾ����ͼ����±�
	string bname;
	cout << "������Ҫɾ��ͼ�������:";
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
			cout << "ɾ�����!" << endl;
		}
	}
	if (temp == -1)
		cout << "û���ҵ�����Ϊ" << bname << "��ͼ��!" << endl;
}

//������ɾ��
void BookClass::deleteauthor()
{
	int temp = -1; //Ҫɾ����ͼ����±�
	string bauthor;
	cout << "������Ҫɾ��ͼ�������:";
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
			cout << "ɾ�����!" << endl;
		}
	}
	if (temp == -1)
		cout << "û���ҵ�����Ϊ" << bauthor << "��ͼ��!" << endl;
}

//��������ɾ��
void BookClass::deletepublisher()
{
	int temp = -1; //Ҫɾ����ͼ����±�
	string bpublisher;
	cout << "������Ҫɾ��ͼ��ĳ�����:";
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
			cout << "ɾ�����!" << endl;
		}
	}
	if (temp == -1)
		cout << "û���ҵ�������Ϊ" << bpublisher << "��ͼ��!" << endl;
}

//���Ǽ�ɾ��
void BookClass::deletestar()
{
	int temp = -1; //Ҫɾ����ͼ����±�
	int bstar;
	cout << "������Ҫɾ��ͼ����Ǽ�:";
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
			cout << "ɾ�����!" << endl;
		}
	}
	if (temp == -1)
	{
		cout << "û���ҵ��Ǽ�Ϊ";
		for (int j = 0; j < bstar; j++)
		{
			cout << "��";
		}
		cout << "��ͼ��!" << endl;
	}
}

//ɾ������ͼ����Ϣ
void BookClass::deleteall()
{
	for (int i = 0; i < top; i++)
	{
		book[i].setbooktag();
	}
}

//ͼ���Ų�ѯ
void BookClass::searchbookno()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string bno;
	cout << "������Ҫ��ѯ���ͼ����:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			k = 1;
			cout << "Foundͼ����Ϊ" << bno << "����!" << endl;
			book[i].dispbook();
		}
	}
	if (k == 0)
		cout << "û���ҵ�ͼ����Ϊ" << bno << "����!" << endl;
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

//������ѯ
void BookClass::searchbookname()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string bname;
	cout << "������Ҫ��ѯ�������:";
	cin >> bname;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookname() == bname)
		{
			k = 1;
			cout << "Found����Ϊ" << bname << "����!" << endl;
			book[i].dispbook();
		}
	}
	if (k == 0)
		cout << "û���ҵ�����Ϊ" << bname << "����!" << endl;
}

//���߲�ѯ
void BookClass::searchauthor()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string bauthor;
	cout << "������Ҫ��ѯ�������:";
	cin >> bauthor;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getauthor() == bauthor)
		{
			k = 1;
			cout << "Found����Ϊ" << bauthor << "����!" << endl;
			book[i].dispbook();
		}
	}
	if (k == 0)
		cout << "û���ҵ�����Ϊ" << bauthor << "����!" << endl;
}

//�������ѯ
void BookClass::searchpublisher()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string bpublisher;
	cout << "������Ҫ��ѯ��ĳ�����:";
	cin >> bpublisher;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getpublisher() == bpublisher)
		{
			k = 1;
			cout << "Found������Ϊ" << bpublisher << "����!" << endl;
			book[i].dispbook();
		}
	}
	if (k == 0)
		cout << "û���ҵ�������Ϊ" << bpublisher << "����!" << endl;
}

//ͼ���Ǽ���ѯ
void BookClass::searchstar()
{
	int k = 0; //��ѯ���1:Yes 0:No
	int bstar;
	cout << "������Ҫ��ѯ���ͼ���Ǽ�:";
	cin >> bstar;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getstar() == bstar)
		{
			k = 1;
			cout << "Foundͼ���Ǽ�Ϊ" << bstar << "����!" << endl;
			book[i].dispbook();
		}
	}
	if (k == 0)
	{
		cout << "û���ҵ��Ǽ�Ϊ";
		for (int j = 0; j < bstar; j++)
		{
			cout << "��";
		}
		cout << "��ͼ��!" << endl;
	}
}

//��������
void BookClass::updatebookname()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string bno;
	string bname;
	cout << "������Ҫ�޸ĵ�ͼ���ͼ����:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			k = 1;
			cout << "������Ҫ�޸ĵ�ͼ�������:";
			cin >> bname;
			book[i].setbookname(bname);
			book[i].dispbook();
			break;
		}
	}
	if (k == 0)
		cout << "û���ҵ�ͼ����Ϊ" << bno << "��ͼ��!" << endl;
}

//��������
void BookClass::updateauthor()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string bno;
	string bauthor;
	cout << "������Ҫ�޸ĵ�ͼ���ͼ����:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			k = 1;
			cout << "������Ҫ�޸ĵ�ͼ�������:";
			cin >> bauthor;
			book[i].setauthor(bauthor);
			book[i].dispbook();
			break;
		}
	}
	if (k == 0)
		cout << "û���ҵ�ͼ����Ϊ" << bno << "��ͼ��!" << endl;
}

//���³�����
void BookClass::updatepublisher()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string bno;
	string bpublisher;
	cout << "������Ҫ�޸ĵ�ͼ���ͼ����:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			k = 1;
			cout << "������Ҫ�޸ĵ�ͼ��ĳ�����:";
			cin >> bpublisher;
			book[i].setpublisher(bpublisher);
			book[i].dispbook();
			break;
		}
	}
	if (k == 0)
		cout << "û���ҵ�ͼ����Ϊ" << bno << "��ͼ��!" << endl;
}

//���¹ݲ�����
void BookClass::updatetotalnum()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string bno;
	int btotalnum;
	cout << "������Ҫ�޸ĵ�ͼ���ͼ����:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			k = 1;
			cout << "������Ҫ�޸ĵ�ͼ��Ĺݲ�����:";
			cin >> btotalnum;
			book[i].settotalnum(btotalnum);
			book[i].dispbook();
			break;
		}
	}
	if (k == 0)
		cout << "û���ҵ�ͼ����Ϊ" << bno << "��ͼ��!" << endl;
}

//���½����
void BookClass::updateborrownum()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string bno;
	int bborrownum;
	cout << "������Ҫ�޸ĵ�ͼ���ͼ����:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			k = 1;
			cout << "������Ҫ�޸ĵ�ͼ��Ľ����:";
			cin >> bborrownum;
			book[i].setborrownum(bborrownum);
			book[i].dispbook();
			break;
		}
	}
	if (k == 0)
		cout << "û���ҵ�ͼ����Ϊ" << bno << "��ͼ��!" << endl;
}

//�����Ǽ�
void BookClass::updatestar()
{
	int k = 0; //��ѯ���1:Yes 0:No
	string bno;
	int bstar;
	cout << "������Ҫ�޸ĵ�ͼ���ͼ����:";
	cin >> bno;
	for (int i = 0; i < top; i++)
	{
		if (book[i].getbookno() == bno)
		{
			k = 1;
			cout << "������Ҫ�޸ĵ�ͼ����Ǽ�:";
			cin >> bstar;
			book[i].setstar(bstar);
			book[i].dispbook();
			break;
		}
	}
	if (k == 0)
		cout << "û���ҵ�ͼ����Ϊ" << bno << "��ͼ��!" << endl;
}

//�������ͼ����Ϣ
void BookClass::dispbookall()
{
	cout << "ͼ����Ϣ����:" << endl;
	cout << "ͼ����" << setw(12);
	cout << "����" << setw(12);
	cout << "����" << setw(12);
	cout << "������" << setw(12);
	cout << "�ݲ�����" << setw(12);
	cout << "�����" << setw(12);
	cout << "ͼ���Ǽ�" << endl;
	for (int i = 0; i < top; i++)
	{
		book[i].dispbook();
	}
}

//���һ������Ϣ
void BookClass::dispbook(int n)
{
	cout << "��ͼ�������Ϣ����:" << endl;
	book[n].dispbook();
}

const int M = 5;

//��������
class BorrowInfo
{
  public:
	string bookno;   //ͼ����
	int borrowyear;  //�������
	int borrowmonth; //�����·�
	int borrowday;   //��������
	int backyear;	//�������
	int backmonth;   //�����·�
	int backday;	 //��������
};

//һ��ѧ��������Ϣ
class BorrowNote
{
  private:
	string borrowno; //����ѧ����ѧ��
	int top;

  public:
	BorrowInfo bookborrow[M]; //����ͼ����Ϣ
	BorrowNote();
	~BorrowNote();
	void settop(int);												 //���ý���ͼ������
	int gettop();													 //��ȡ����ͼ������
	void setborrowno(string);										 //���ý���ѧ����ѧ��
	string getborrowno();											 //��ȡ����ѧ����ѧ��
	void setborrowday(int i, int boryear, int bormonth, int borday); //���ý���ʱ��
	void setbackday(int i, int byear, int bmonth, int bday);		 //���û�������
	void borrowbook(string bno);									 //����
	void backbook(string bno);										 //����
	void disp();													 //��ʾ������Ϣ
};

//���캯��
BorrowNote::BorrowNote()
{
	top = 0;
}

//��������
BorrowNote::~BorrowNote() {}

//���ý���ͼ������
void BorrowNote::settop(int n)
{
	top = n;
}

//��ȡ����ͼ������
int BorrowNote::gettop()
{
	return top;
}

/*//���ý������
void BorrowNote::setborrowyear(int byear)
{
	borrowyear=byear;
}

//��ȡ�������
int BorrowNote::getborrowyear()
{
    return borrowyear;
}

//���ý����·�
void BorrowNote::setborrowmonth(int bmonth)
{
	borrowmonth=bmonth;
}

//��ȡ�����·�
int BorrowNote::getborrowmonth()
{
	return borrowmonth;    
}

//���ý�������
void BorrowNote::setborrowday(int bday)
{
	borrowday=bday;
}

//��ȡ��������
int BorrowNote::getborrowday()
{
	return borrowday;
}
*/

//���ý���ѧ����ѧ��
void BorrowNote::setborrowno(string borno)
{
	borrowno = borno;
}

//��ȡ����ѧ����ѧ��
string BorrowNote::getborrowno()
{
	return borrowno;
}

//���ý���ʱ��
void BorrowNote::setborrowday(int i, int boryear, int bormonth, int borday)
{
	bookborrow[i].borrowyear = boryear;
	bookborrow[i].borrowmonth = bormonth;
	bookborrow[i].borrowday = borday;
}

//���û�������
void BorrowNote::setbackday(int i, int byear, int bmonth, int bday)
{
	bookborrow[i].backyear = byear;
	bookborrow[i].backmonth = bmonth;
	bookborrow[i].backday = bday;
}

//����
void BorrowNote::borrowbook(string bno)
{
	time_t t;
	tm *tp;
	t = time(NULL);
	tp = localtime(&t);
	bookborrow[top].bookno = bno;					 //ͼ����
	bookborrow[top].borrowyear = tp->tm_year + 1900; //�������
	bookborrow[top].borrowmonth = tp->tm_mon + 1;	//�����·�
	bookborrow[top].borrowday = tp->tm_mday;		 //��������
	bookborrow[top].backyear = 0;					 //�������
	bookborrow[top].backmonth = 0;					 //�����·�
	bookborrow[top].backday = 0;					 //��������
	top++;
}

//����
void BorrowNote::backbook(string bno)
{
	int k = -1; //ͼ���±�
	for (int i = 0; i < top; i++)
	{
		if (bookborrow[i].bookno == bno)
		{
			k = i;
		}
	}
	if (k == -1)
		cout << "��δ�����!" << endl;
	else
	{
		time_t t;
		tm *tp;
		t = time(NULL);
		tp = localtime(&t);
		bookborrow[k].backyear = tp->tm_year + 1900; //�������
		bookborrow[k].backmonth = tp->tm_mon + 1;	//�����·�
		bookborrow[k].backday = tp->tm_mday;		 //��������
	}
}

//��ʾ������Ϣ
void BorrowNote::disp()
{
	cout << "ѧ��Ϊ:" << borrowno << "��ѧ���Ľ�����Ϣ����:" << endl;
	for (int i = 0; i < top; i++)
	{
		cout << "ͼ����:" << bookborrow[i].bookno << endl;
		cout << "��������:" << bookborrow[i].borrowyear << "��" << bookborrow[i].borrowmonth << "��" << bookborrow[i].borrowday << "��" << endl;
		if (bookborrow[i].backyear == 0)
			cout << "����δ��!" << endl;
		else
			cout << "��������:" << bookborrow[i].backyear << "��" << bookborrow[i].backmonth << "��" << bookborrow[i].backday << "��" << endl;
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
	void Insert(string borno, string bno);		//����һ��ѧ��������Ϣ
	void borrow(Studentclass &S, BookClass &B); //ͼ�����
	void back(Studentclass &S, BookClass &B);   //ͼ��黹
	void recommend(BookClass B);				//ͼ���Ƽ�
	//������Ϣ��ѯ
	void notesearchno();	 //��ѧ�Ų�ѯ�����¼
	void notesearchbookno(); //��ͼ���Ų�ѯ�����¼
	void notesearchname();   //��������ѯ�����¼
	void notesearchdate();   //���������ڲ�ѯ�����¼
	void dispall();			 //��ʾ���н����¼

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

//���캯����ȡ������Ϣ
BorrowClass::BorrowClass()
{
	top = 0;
	ifstream in("borrow.txt");
	if (!in)
	{
		cout << "�ļ��򲻿�!" << endl;
	}
	while (!in.eof())
	{
		in >> note[top];
		top++;
	}
	in.close();
}

//�����������������Ϣ
BorrowClass::~BorrowClass()
{
	ofstream out("borrow.txt");
	if (!out)
	{
		cout << "�ļ��򲻿�!" << endl;
	}
	for (int i = 0; i < top; i++)
	{
		out << note[i];
	}
	out.close();
}

//����һ��ѧ��������Ϣ
void BorrowClass::Insert(string borno, string bno)
{
	note[top].setborrowno(borno);
	note[top].borrowbook(bno);
	top++;
}

//ͼ�����
void BorrowClass::borrow(Studentclass &S, BookClass &B)
{
	string borno;
	string bno;
	cout << "����������ѧ��:";
	cin >> borno;
	int k1 = S.searchno(borno);
	if (k1 == -1)
	{
		cout << "û��ѧ��Ϊ:" << borno << "��ѧ��" << endl
			 << endl;
		return;
	}
	cout << "������Ҫ�����ͼ����:";
	cin >> bno;
	int k2 = B.searchbookno(bno);
	if (k2 == -1)
	{
		cout << "û��ͼ����Ϊ:" << bno << "����" << endl
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
			cout << borno << "����" << bno << "�ɹ�!" << endl
				 << endl;
			break;
		}
	}
	if (s == -1)
	{
		Insert(borno, bno);
		k = B.searchbookno(bno);
		B.getbookup(k);
		cout << borno << "����" << bno << "�ɹ�!" << endl
			 << endl;
	}
}

//ͼ��黹
void BorrowClass::back(Studentclass &S, BookClass &B)
{
	string borno;
	string bno;
	cout << "����������ѧ��:";
	cin >> borno;
	int k1 = S.searchno(borno);
	if (k1 == -1)
	{
		cout << "û��ѧ��Ϊ:" << borno << "��ѧ��" << endl
			 << endl;
		return;
	}
	cout << "������Ҫ�����ͼ����:";
	cin >> bno;
	int k2 = B.searchbookno(bno);
	if (k2 == -1)
	{
		cout << "û��ͼ����Ϊ:" << bno << "����" << endl
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
			cout << borno << "����" << bno << "�ɹ�!" << endl
				 << endl;
		}
	}
}

//ͼ���Ƽ�
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

//��ѧ�Ų�ѯ�����¼
void BorrowClass::notesearchno()
{
	int k = -1;
	string borno;
	cout << "����������ѧ��:";
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
		cout << "ѧ��Ϊ:" << borno << "��ѧ��û�н���!" << endl
			 << endl;
	}
}

/*//��ͼ���Ų�ѯ�����¼
void BorrowClass::notesearchbookno()
{
	int k=-1;
	string bno;
	cout<<"��������Ҫ��ѯ��ͼ����:";
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
		cout<<"ͼ����Ϊ:"<<bno<<"��ͼ��δ�����!"<<endl;
	}
}

//��������ѯ�����¼
void BorrowClass::notesearchname()
{
	int k=-1;
	string bname;
	cout<<"��������Ҫ��ѯ������:";
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
		cout<<"����Ϊ:"<<bname<<"��ͼ��δ�����!"<<endl;
	}
}

//���������ڲ�ѯ�����¼
void BorrowClass::notesearchdate()
{
	int k=-1;
	int byear;
	int bmonth;
	int bday;
	cout<<"��������Ҫ��ѯ�Ľ�������:"<<endl;
	cout<<"���������:";
	cin>>byear;
	cout<<endl<<"���������:";
	cin>>bmonth;
	cout<<endl<<"����������:";
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
		cout<<byear<<"��"<<bmonth<<"��"<<bday<<"��"<<"û���˽���!"<<endl;
	}
}
*/

//��ʾ���н����¼
void BorrowClass::dispall()
{
	for (int i = 0; i < top; i++)
		note[i].disp();
}

//�Ӳ˵�
//����ѧ����ҵ
void stu_detete_menu(Studentclass &S)
{
	int choise;
	cout << "1.��ѧ��ɾ��" << endl
		 << endl;
	cout << "2.������ɾ��" << endl
		 << endl;
	cout << "3.��רҵɾ��" << endl
		 << endl;
	cout << "4.���༶ɾ��" << endl
		 << endl;
	cout << "5.���ֻ���ɾ��" << endl
		 << endl;
	cout << "0.�˳�" << endl
		 << endl;
	cout << "������(0--5):";
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
		cout << "�������,����������!" << endl;
	}
}

//�Ӳ˵�
//ѧ����Ϣ��ѯ
void stu_search_menu(Studentclass &S)
{
	int choise;
	cout << "1.��ѯѧ��" << endl
		 << endl;
	cout << "2.��ѯ����" << endl
		 << endl;
	cout << "3.��ѯרҵ" << endl
		 << endl;
	cout << "4.��ѯ�༶" << endl
		 << endl;
	cout << "5.��ѯ�ֻ���" << endl
		 << endl;
	cout << "0.�˳�" << endl
		 << endl;
	cout << "������(0--5):";
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
		cout << "�������,����������!" << endl;
	}
}

//�Ӳ˵�
//ѧ����Ϣ�޸�
void stu_update_menu(Studentclass &S)
{
	int choise;
	cout << "1.��������" << endl
		 << endl;
	cout << "2.����רҵ" << endl
		 << endl;
	cout << "3.���°༶" << endl
		 << endl;
	cout << "4.�����ֻ���" << endl
		 << endl;
	cout << "0.�˳�" << endl
		 << endl;
	cout << "������(0--4):";
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
		cout << "�������,����������!" << endl;
	}
}

void stu_main_menu(Studentclass &S)
{
	int choise;
	cout << setw(6) << "����  ��ӭʹ��ѧ����Ϣ����ϵͳ  ����" << endl
		 << endl;
	cout << "       1.����ѧ����ѧ" << endl
		 << endl;
	cout << "       2.����ѧ����ҵ" << endl
		 << endl;
	cout << "       3.����ѧ������" << endl
		 << endl;
	cout << "       4.����ѧ��ɾ��" << endl
		 << endl;
	cout << "       5.ѧ����Ϣ��ѯ" << endl
		 << endl;
	cout << "       6.ѧ����Ϣ�޸�" << endl
		 << endl;
	cout << "       7.��ʾ����ѧ����Ϣ" << endl
		 << endl;
	cout << "       0.�˳�ϵͳ" << endl
		 << endl;
	cout << "       ������(0--7):";
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
		cout << "�������,����������!" << endl;
	}
}

//�Ӳ˵�
//����ͼ��ɾ��
void book_delete_menu(BookClass &B)
{
	int choise;
	cout << "1.��ͼ����ɾ��" << endl
		 << endl;
	cout << "2.������ɾ��" << endl
		 << endl;
	cout << "3.������ɾ��" << endl
		 << endl;
	cout << "4.��������ɾ��" << endl
		 << endl;
	cout << "5.���Ǽ�ɾ��" << endl
		 << endl;
	cout << "0.�˳�" << endl
		 << endl;
	cout << "������(0--5):";
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
		cout << "�������,����������!" << endl;
	}
}

//�Ӳ˵�
//ͼ����Ϣ��ѯ
void book_search_menu(BookClass &B)
{
	int choise;
	cout << "1.��ͼ���Ų�ѯ" << endl
		 << endl;
	cout << "2.��������ѯ" << endl
		 << endl;
	cout << "3.�����߲�ѯ" << endl
		 << endl;
	cout << "4.���������ѯ" << endl
		 << endl;
	cout << "5.���Ǽ���ѯ" << endl
		 << endl;
	cout << "0.�˳�" << endl
		 << endl;
	cout << "������(0--5):";
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
		cout << "�������,����������!" << endl;
	}
}

//�Ӳ˵�
//����ͼ����Ϣ
void book_update_menu(BookClass &B)
{
	int choise;
	cout << "1.��������" << endl
		 << endl;
	cout << "2.��������" << endl
		 << endl;
	cout << "3.���³�����" << endl
		 << endl;
	cout << "4.���¹ݲ�����" << endl
		 << endl;
	cout << "5.���½����" << endl
		 << endl;
	cout << "6.�����Ǽ�" << endl
		 << endl;
	cout << "0.�˳�" << endl
		 << endl;
	cout << "������(0--6):";
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
		cout << "�������,����������!" << endl;
	}
}

void book_main_menu(BookClass &B)
{
	int choise;
	cout << "����  ��ӭʹ��ͼ�����ϵͳ  ����" << endl
		 << endl;
	cout << "       1.����ͼ�����" << endl
		 << endl;
	cout << "       2.����ͼ�����" << endl
		 << endl;
	cout << "       3.����ͼ��ɾ��" << endl
		 << endl;
	cout << "       4.����ͼ��ɾ��" << endl
		 << endl;
	cout << "       5.ͼ����Ϣ��ѯ" << endl
		 << endl;
	cout << "       6.����ͼ����Ϣ" << endl
		 << endl;
	cout << "       7.�������ͼ����Ϣ" << endl
		 << endl;
	cout << "       0.�˳�" << endl
		 << endl;
	cout << "       ������(0--7):";
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
		cout << "�������,����������!" << endl;
	}
}

void borrow_note_menu(Studentclass &S, BookClass &B, BorrowClass &N)
{
	int choise;
	cout << "����  ��ӭʹ�ö��߽��Ĺ���ϵͳ  ����" << endl
		 << endl;
	cout << "       1.ͼ�����" << endl
		 << endl;
	cout << "       2.ͼ��黹" << endl
		 << endl;
	cout << "       3.��ѯ�����¼" << endl
		 << endl;
	cout << "       4.�Ƽ�ͼ��" << endl
		 << endl;
	cout << "       5.��ʾ���н����¼" << endl
		 << endl;
	cout << "       0.�˳�" << endl
		 << endl;
	cout << "       ������(0--5):";
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
		cout << "�������,����������!" << endl;
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
	cout << setw(40) << "�������������:";
	{
		cin >> a;
		if (a == "111")
		{
			cout << setw(38) << "����������:";
			cin >> pw;
			if (pw == "000")
			{
				cout << "��½�ɹ�!" << endl;
				system("cls");
			}
			else
			{
				cout << "�������!����������!" << endl;
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
		cout << setw(6) << " �����  ��ӭʹ��ͼ�����ϵͳ  �����" << endl
			 << endl;
		cout << "          1.ѧ����Ϣ����ϵͳ" << endl
			 << endl;
		cout << "          2.ͼ�����ϵͳ" << endl
			 << endl;
		cout << "          3.���߽��Ĺ���ϵͳ" << endl
			 << endl;
		cout << "          0.�˳�ϵͳ" << endl
			 << endl;
		cout << "          ��ѡ��(0--3):";
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
			cout << "��ӭʹ��ͼ�����ϵͳ,������������!" << endl;
			return 0;
		default:
			cout << "�������,����������!" << endl;
		}
	}
	return 0;
}
