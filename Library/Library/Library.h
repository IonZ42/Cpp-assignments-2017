#ifndef LIBRARY_H
#define LIBRARY_H
#include<iostream>
#include<string>
using namespace std;

//set,get函数已省略,其功能由>>,<<代替,const 和 static都没有用，安全性请不要深究OTZ
//display格式照搬题干

class BookRecord
{
	friend class Catalogue;
	friend class Library;
	friend istream& operator >>(istream&, BookRecord&);
	friend ostream& operator <<(ostream&, BookRecord&);
public:
	BookRecord(); BookRecord(string, string, string, string, int, int, int);
	~BookRecord() {}
	void display() { cout << *this; }
	void setbi(string); string getbi() const;
	/*
	void setbi(string); string getbi() const;
	void setbt(string); string getbt() const;
	void setfn(string); string getfn() const;
	void setln(string); string getln() const;
	void setyp(int); int getyp() const;
	void setnc(int); int getnc() const;
	void setnac(int); int getnac() const;
	*/
private:
	string bi;//book_id
	string bt;//book_title
	string fn;//first_name
	string ln;//last_name
	int yp;//year_published
	int nc;//number_of_copies
	int nac;//number_of_avaliable_copies
};

class Borrower
{
	friend class Library;
	friend istream& operator >>(istream&, Borrower&);
	friend ostream& operator <<(ostream&, Borrower&);
public:
	Borrower(); Borrower(string, string, string, int, string*);
	~Borrower() {}
	void display() { cout << *this; }
	/*
	void setbi(string); string getbi() const;
	void setfn(string); string getfn() const;
	void setln(string); string getln() const;
	void setnlb(int); int getnlb() const;
	void setbis(string*); string* getbis() const;
	*/
private:
	string bi;//borrower_id
	string fn;//first_name
	string ln;//last_name
	int nlb;//number_of_loan_book
	string bis[5];//book_ids_array
};

class Catalogue
{
	friend class Library;
public:
	Catalogue(); ~Catalogue();
	void setcatalogue();
	void display();
	/*
	void setbn();int getbn() const;
	*/
private:
	int bn;//bookrecord_number
	BookRecord* brp;//bookrecord_pointer
};

class Library
{
public:
	Library(); ~Library();
	void setborrowers();
	void dymaticcatalogue();
	void display();
	void display_books();
	void display_borrowers();
	/*
	void settnlb(); int gettnlb()const;
	void settbn(); int gettbn()const;
	*/
private:
	int tnlb;//total_number_of_loan_book
	Catalogue catalogue;
	int tbn;//total_borrower_number
	Borrower*bwp;//borrowers_pointer
};
#endif
