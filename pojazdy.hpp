

#include "baza.h"
#include "randomgen.h"
#include <vector>
#include <list>//
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <memory>



using namespace std;


template<typename D, typename B>
unique_ptr<D> static_cast_ptr(unique_ptr<B>& base) {
	return unique_ptr<D>(static_cast<D*>(base.release()));
}
template<typename D, typename B>
unique_ptr<D> static_cast_ptr(unique_ptr<B>&& base) {
	return unique_ptr<D>(static_cast<D*>(base.release()));
}

class Pojazd {
public:
	Pojazd() : marka(Random_MarkaG()), model(Random_ModelG()), data(Random_Data()), pojemnosc(Random_Poj()), power(Random_Power()) { }
	Pojazd(string mar, string mod, int dat, double poj, double pow) :marka(mar), model(mod), data(dat), pojemnosc(poj), power(pow) {}
	int getId()  { return id; }//const const
	const int getWiek() const { return wiek; }
	const double getData() const { return data; }//int
	const double getPower() const { return power; }//int
	list<string> getCechy() const { return cechy; }////
	void setId(int ID) { id = ID; }
	void setCechy() {
		cout << "Max 3 cechy!" << endl;
		for (int i = 0; i < 3; ++i) {
			
			string auxiliary;
			cout << "Waiting for new cecha:" << endl;
			cin >> auxiliary;
			cechy.push_front(auxiliary);
			cout << endl << "You want more? y/n" << endl;
			
			cin >> auxiliary;

			if (i!=2 && auxiliary=="n")
			{ break; }
			
		}

	}
	//Pojazd& operator++(int) {
	//	++wiek;
	//	return *this;
	//	}
	friend bool operator<(const Pojazd& P1, const Pojazd& P2);
	//friend bool fun(const Pojazd& P1, const Pojazd& P2);

	//int data;

	void print() { cout << "Marka:" << marka << ", model:" << model << ", data:" << data << ", wiek:" << wiek << ", poj:" << pojemnosc << ", moc:" << power << endl; }
	virtual ~Pojazd() { cout << "Bye Pojazd" << endl; }


	friend Pojazd& operator++(Pojazd& L);
private:
	string marka;
	string model;
	int data;
	double power;
	double pojemnosc;
	int liczba_cech;
	int wiek = 2022 - data;
	bool diesel;
	int id;
	list<string> cechy;
	

	

	//friend void sortby(vector  <shared_ptr<Pojazd>> Katalog);
	//friend void sortby();
};

Pojazd& operator++(Pojazd& L) {
	++L.wiek;
	return L;
}



class Motocykl :public Pojazd {
public:
	static char M;
	Motocykl() :Pojazd((Random_MarkaM()), (Random_ModelM()), (Random_Data()), (Random_Poj()), (Random_Power())), boxer(Random_Boxer()) {}
	Motocykl(string mar, string mod, int dat, double poj, double pow, bool b) :Pojazd(mar, mod, dat, poj, pow), boxer(b) {}
	virtual void print() { cout << "\tBoxer?:\t" << boxer << endl; }
	virtual ~Motocykl() { cout << "Bye motocykl" << endl; }
	bool getBool() { return boxer; }
private:
	bool boxer;
};

class Osobowy :public Pojazd {
public:
	Osobowy() :Pojazd((Random_MarkaO()), (Random_ModelO()), (Random_Data()), (Random_Poj()), (Random_Power())), pasazerowie(Random_Pasazerowie()) {}
	Osobowy(string mar, string mod, int dat, double poj, double pow, int p) :Pojazd(mar, mod, dat, poj, pow), pasazerowie(p) {}
	virtual void print() { cout << "\tPasazerowie?:\t" << pasazerowie << endl; }
	virtual~Osobowy() { cout << "Bye osobowy" << endl; }
private:
	int pasazerowie;

};
class LKW :public Pojazd {
public:
	LKW() :Pojazd((Random_MarkaL()), (Random_ModelL()), (Random_Data()), (Random_Poj()), (Random_Power())), ladunek(Random_Ladunek()) {}
	LKW(string mar, string mod, int dat, double poj, double pow, double l) :Pojazd(mar, mod, dat, poj, pow), ladunek(l) {}
	virtual void  print() { cout << "\tLadunek?:\t" << ladunek << endl; }
	virtual ~LKW() { cout << "Bye lkw" << endl; }
private:
	double ladunek;

};
