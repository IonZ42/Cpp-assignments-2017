#include "stdafx.h"
#include "Library.h"
#include <iostream>
#include<string>
using namespace std;

BookRecord::BookRecord()
{
	bi = "NAN"; bt = "NAN"; fn = "NAN"; ln = "NAN";
	yp = 2000; nc = 0; nac = 0;
}
BookRecord::BookRecord(string obi, string obt, string ofn, string oln, int oyp, int onc, int onac)
{
	bi = obi; bt = obt; fn = ofn; ln = oln; yp = oyp; nc = onc; nac = onac;
}

istream& operator >>(istream& input, BookRecord& obj)
{
	getline(input, obj.bi, ';');
	if (obj.bi[0]<'A' || obj.bi[0]>'Z') { cout << "sorry,error input!(book ID should start with an uppercase letter)" << endl << "program exit" << endl; abort(); }
	getline(input, obj.bt, ';');
	getline(input, obj.fn, ' ');
	getline(input, obj.ln, ';');
	input >> obj.yp;
	if (obj.yp / 1000 != 1 && obj.yp / 1000 != 2) { cout << "sorry,error input!(invalid published year)" << endl << "program exit" << endl; abort(); }
	input.ignore();
	input >> obj.nc;
	obj.nac = obj.nc;
	return input;
}

ostream& operator <<(ostream& output, BookRecord& obj)
{
	cout << "*******************************" << endl
		<< "Book ID: " << obj.bi << endl
		<< "Title: " << obj.bt << endl
		<< "Author: " << obj.fn << " " << obj.ln << endl
		<< "Year published: " << obj.yp << endl
		<< "Total number of copies: " << obj.nc << endl
		<< "Number available for loan: " << obj.nac << endl;
	return output;
}

//题干要我写，于是这就是唯一的安全性set,get函数（滑稽
void BookRecord::setbi(string x) { bi = x; }
string BookRecord::getbi() const { return bi; }
/*******************/

Borrower::Borrower()
{
	bi = "00000"; fn = "NAN"; ln = "NAN";
	nlb = 0;
	for (int j = 0; j < 5; j++) { bis[j] = "NAN"; }
}
Borrower::Borrower(string obi, string ofn, string oln, int onlb, string* obis)
{
	bi = obi; fn = ofn; ln = oln; nlb = onlb; *bis = *obis;
}

istream& operator >>(istream& input, Borrower& obj)
{
	getline(input, obj.bi, ';');
	if (obj.bi.size() > 6) { cout << "sorry,error input!(borrower ID isn't 5-digit)" << endl << "program exit" << endl; abort(); }
	getline(input, obj.fn, ' ');
	getline(input, obj.ln, ';');
	input >> obj.nlb;
	if (obj.nlb>5 || obj.nlb<1) { cout << "sorry,error input!(invalid loaned books number)" << endl << "program exit" << endl; abort(); }
	input.ignore();
	for (int j = 0; j < obj.nlb; j++) {
		input.ignore();
		if (j != obj.nlb - 1)
			getline(input, obj.bis[j], ';');
		else getline(input, obj.bis[j]);
	}
	return input;
}

ostream& operator <<(ostream& output, Borrower& obj)
{
	cout << "*******************************" << endl
		<< "Borrower ID: " << obj.bi << endl
		<< "Name: " << obj.fn << " " << obj.ln << endl
		<< "Number of loaned books: " << obj.nlb << endl
		<< "IDs of books on loan: ";
	for (int j = 0; j < obj.nlb; j++) {
		cout << obj.bis[j];
		if (j != obj.nlb - 1)cout << " "; else cout << endl;
	}
	return output;
}
/*******************/

Catalogue::Catalogue()
{
	cin >> bn;
	brp = new BookRecord[bn];
	setcatalogue();
}

Catalogue::~Catalogue()
{
	delete brp; brp = NULL;
}

void Catalogue::setcatalogue()
{
	for (int j = 0; j < bn; j++) {
		cin.get();
		cin >> brp[j];
	}
}

void Catalogue::display()
{
	int sum = 0;
	for (int j = 0; j < bn; j++)
	{
		sum += brp[j].nac;
	}
	cout << "Total number of books in catalogue: " << sum << endl << endl;
	for (int j = 0; j < bn; j++) {
		cout << "BookRecord No." << j + 1 << endl
			<< brp[j] << endl;
	}
}
/*******************/

Library::Library()
{
	catalogue;
	cin.get();
	cin >> tbn;
	bwp = new Borrower[tbn];
	setborrowers();
	for (int j = 0; j < tbn; j++) {
		tnlb += bwp[j].nlb;
	}
	dymaticcatalogue();
}
Library::~Library()
{
	delete bwp; bwp = NULL;
}

void Library::setborrowers()
{
	for (int j = 0; j < tbn; j++) {
		cin.get();
		cin >> bwp[j];
	}
}

void Library::dymaticcatalogue()
{
	for (int j = 0; j < tbn; j++) {
		for (int k = 0; k < bwp[j].nlb; k++) {
			for (int t = 0; t < catalogue.bn; t++) {
				if (catalogue.brp[t].nac>0)
				{
					if (bwp[j].bis[k] == catalogue.brp[t].bi)
					{
						catalogue.brp[t].nac--;
					}
				}
			}
		}
	}
}

void Library::display()
{
	cout << endl << "Total number of books on loan: " << tnlb << endl;
	display_books();
	display_borrowers();
}

void Library::display_books()
{
	catalogue.display();
}

void Library::display_borrowers()
{
	cout << "Total number of borrowers: " << tbn << endl << endl;
	for (int j = 0; j < tbn; j++) {
		cout << "Borrower No." << j + 1 << endl
			<< bwp[j] << endl;
	}
}