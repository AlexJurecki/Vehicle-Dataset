// baza.cpp: definiuje punkt wejścia dla aplikacji.
//

#include "baza.h"
#include "pojazdy.hpp"
#include "randomgen.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <memory>



class Data {
public:
	Data() { cout << "Welcome to the Data!" << endl; }
	void dodaj_random() {
		Katalog.push_back(make_shared<Motocykl>());
		Katalog.back()->setId(numer);
		numer += 1;
	}
	void dodaj()
	{
		//string	a="BMW";
		//string b="K1200";
		//int c=2010;
		//double d=110;
		//double e=35.5;
		//bool	f=true;
		// 
		//Vehicles.push_back(Motocykl(a, b, c, d, e, f));
		cout << "Would you like to randomize? yes/no" << endl;
		string question;
		cin >> question;
		if ((question == "yes") || (question == "y")) {
			Katalog.push_back(make_shared<Motocykl>());

		}
		else {
			string a, b;
			int c;
			double d, e;
			bool f;
			cout << endl << "Podaj marke:\t";
			cin >> a;
			cout << "Podaj model:\t";
			cin >> b;
			cout << endl << "Podaj Date produkcji:\t";
			cin >> c;
			cout << endl << "Podaj pojemnosc:\t";
			cin >> d;
			cout << endl << "Podaj moc:\t";
			cin >> e;
			cout << endl << "Podaj parametr:\t";
			cin >> f;

			Katalog.push_back(make_shared<Motocykl>(a, b, c, d, e, f));
		}
		Katalog.back()->setId(numer);
		numer += 1;
		//Vehicles.push_back(make_unique<Motocykl>(a, b, c, d, e, f));
		//Vehicles.push_back(Motocykl(a, b, c, d, e, f));
		// 
		//dum(new Motocykl(a, b, c, d, e, f));
	}

	void timeflow() {
		//for (int i = 0; i < size(Katalog);++i) {

		//	Katalog[i]++;
		//}
		//Pojazd&++(Katalog[0]);
		for (auto& it : Katalog) {
			
			++(*it);
			it->print();
		}
	}


	void dodaj_cechy() {
		
		cout << "Gimme cecha" << endl;
		Katalog.back()->setCechy();
	}

	const void drukuj() {
		for (int i = 0; i < size(Katalog); ++i) {
			//Vehicles[i].print();
			cout << Katalog[i]->getId() << "\t";
			Katalog[i]->print();
		//	cout << "\tCechy:";
			//list<string>::iterator it = Katalog[i]->getCechy().begin();
			//for (it; it != Katalog[i]->getCechy().end(); *it++)
			//	cout << *it <<", "<< endl;
			
			
			//dynamic_pointer_cast<Motocykl>(Katalog[i])->print();
			//dynamic_pointer_cast<Pojazd>(Katalog[i])->print();
			static_pointer_cast<Motocykl>(Katalog[i])->print();
			//static_pointer_cast<Pojazd>(Katalog[i])->print();
			//static_cast<Pojazd>(Vehicles[i]).print();
			//cout << Katalog[i].getBool()<<
			//stat_cast_ptr<Motocykl>(Vehicles[i]);
			//auto derived=stat_cast_ptr<Motocykl>(Vehicles[i]);
		}
	}

	const void sortuj() {
		sort(Katalog.begin(), Katalog.end());

	}

	void sortby(){
		cout << "m - moc, i - id, d- data, w-wiek" << endl;
		string input;
		cin >> input;
	sort(Katalog.begin(), Katalog.end(), [input](shared_ptr<Pojazd>& arg1, shared_ptr<Pojazd>& arg2) {
		//////return (arg1->data < arg2->data);
		// 
		//std::cout << arg.isMonster() << std::endl;
		//if (arg.isMonster() == true) {
		
			//return arg1->data>arg2->data; //bullshit afterawrds


		if (input == "m" || input == "moc") {
			return (arg1->getPower() < arg2->getPower());
		}

		if (input == "d" || input == "data") {
			return (arg1->getData() < arg2->getData());
		}

		if (input == "w" || input == "wiek") {
			return (arg1->getWiek() < arg2->getWiek());
		}
		else {
			return (arg1->getId() < arg2->getId());
		}
		//}
	//	else {
		//	return 'y';
	//	}/**/
		});
		//
		
	}

	void eraser(const int& wanted_id) {
		//int i = 0;
		
		//int wanted_id = 1;
		//vector  <shared_ptr<Pojazd>>::iterator it = find(Katalog.begin(), Katalog.end(), wanted_id);
		//auto it = find(Katalog.begin(), Katalog.end(), [](shared_ptr<Pojazd>& arg) {});
		//
	//	if (it != end(Katalog)) {
		//	cout << "Element o id=" << wanted_id << " zajmuje pozycje "<< distance(Katalog.begin(), it) << endl;
		//	Katalog.erase(it);		}
	//	else {	cout << "Element is not present in the given baza danych";	}

		auto it=find_if(Katalog.begin(), Katalog.end(), [wanted_id](const shared_ptr<Pojazd>& arg) {return arg->getId() == wanted_id; });
		//cout << *it;
		Katalog.erase(it);

	}
	
	~Data() {}

	//friend void sortby();


private:
	//vector < unique_ptr<Pojazd>> Vehicles;
	//vector <Pojazd> Vehicles;
	unique_ptr<Pojazd>* Veh;
	unique_ptr<Pojazd> dum;
	vector  <shared_ptr<Pojazd>> Katalog;
	int numer=1;
};
//

//
bool operator<(const Pojazd& P1, const Pojazd& P2) {
	return (P1.power < P2.power);
	/*cout << "m - moc, p - pojemnosc, d- data, w-wiek" << endl;
	string input;
	cin >> input;
	if (input == "m" || input == "moc") {
		
	}
	 input == "p" || input == "pojemnosc") {
		return (P1.pojemnosc < P2.pojemnosc);
	}
	if (input == "d" || input == "data") {
		return (P1.data < P2.data);
	}
	if (input == "w" || input == "wiek") {
		return (P1.wiek < P2.wiek);
	}
	else {
		return (P1.id < P2.id);
	}*/
	
//	return (P1.power < P2.power);
}

/*void sortby(vector  <shared_ptr<Pojazd>> Katalog) {
		sort(Katalog.begin(), Katalog.end(),
		[](const Pojazd& a, const Pojazd& b) -> bool
		{
			return a.data < b.data;
		});
}*/


	class Konsola{
	public:
		//friend Firma;
		Data A;

		Konsola() {}

		void akcja() {
			int stan = 1;
			string akcje;
			cout << "Welcome to Bjarne Inc." << endl;

			for (int turn = 1; turn <= 50; turn++) {

					cout << "Choose wisely: lp,m,rm,break,cech,sortby" << endl;
					cout << "Ruch numer: " << turn + 1 << endl << endl;
					cin >> akcje;
					if (akcje == "lp") {
						A.drukuj();
						cout << endl;
					}
					if (akcje == "m") {
						A.dodaj();
						cout << endl;
					}
					if (akcje == "rm") {
						A.dodaj_random();
						cout << endl;
					}
					if (akcje == "time") {
						A.timeflow();
						cout << endl;
					}
					if (akcje == "sort") {
						A.sortuj();
						A.drukuj();
						cout << endl;
					}
					if (akcje == "sortby") {
						A.sortby();
						A.drukuj();
						cout << endl;
					}
					if (akcje == "cech") {
						A.dodaj_cechy();
						cout << endl;
					}
					if (akcje == "er") {
						cout << "Gimme a id that you would like to erase\t";
						int nr;
						cin >>nr ;
						A.eraser(nr);
						cout << endl;
					}
					if (akcje == "break") {
						
						cout <<"SEEYA"<< endl;
						break;
					}

			}cout << "Koniec gry!" << endl;


		}
		~Konsola() {}
	private:

	};

int main()
{
	ofstream myfile;
	myfile.open("dane.txt");
	myfile << "Boo.\n";
	myfile.close();

	//Motocykl A();
	//Data D;
	//D.dodaj();
	//D.drukuj();
	// 
	// 
	// 
	//unique_ptr<Pojazd> poj(new Motocykl("M","M",1,1,1,false));
	/*
	unique_ptr<Pojazd> poj(new Motocykl("M","M", 1, 1, 1,true));
	poj->print();
	//static_cast_ptr<Pojazd>(poj)->print();
	auto derived_ptr = static_cast_ptr<Pojazd>(poj);
	derived_ptr->print();
	//poj->print();
	Pojazd* f = new Motocykl("M", "M", 1, 1, 1, true);
	f->print();
	static_cast<Pojazd*>(f)->print();
	*/
	vector <Pojazd> VVV;
	VVV.push_back(Pojazd());
	VVV.push_back(Pojazd());
	for (auto& it : VVV) {
		it.print();
			++(it); 
			it.print();
	}//alternative

	/* //trial trial
	cout << "Hello CMake. POJAZD" << endl;
	Pojazd AAA;
	AAA.print();
	cout << "MOTO" << endl;
	Motocykl MMM;
	static_cast<Pojazd>(MMM).print();
	MMM.print();
	cout << "OSOBISTY "<< endl;
	Osobowy OOO;
	static_cast<Pojazd>(OOO).print();
	OOO.print();
	cout << "LORRY" << endl;
	LKW LLL;
	static_cast<Pojazd>(LLL).print();
	LLL.print();
	*/
	Konsola K;
	K.akcja();
	return 0;
}
