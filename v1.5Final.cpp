#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <chrono>
#include <numeric>
#include <fstream>
#include <random>
#include <list>
#include <sstream>



using std::vector;
using std::right;
using std::left;
using std::setw;
using std::setprecision;
using std::cout;
using std::sort;
using std::string;
using std::cin;
using std::endl;
using std::to_string;
using std::chrono::high_resolution_clock;
using std::ofstream;
using std::accumulate;
using std::ifstream;
using std::ws;
using std::list;
using std::stoi;
class Zmogus {

protected: string Vardas_, Pavarde_;
		 string vardas, pavarde;

public:
	Zmogus(string, string);
	Zmogus();
	~Zmogus();
	virtual void setVardas(string) = 0;
	virtual void setPavarde(string) = 0;
	virtual void setStudentas(string, string, string) = 0;
	string getVardas() const;
	string getPavarde() const;
	string GetVarda() const { return Vardas_; }
	string GetPavarde() const { return Pavarde_;}
};

class studentas: public Zmogus
{
private:
	vector <double> ND;
	vector<int> paz;
	int Egzaminas_;
	double Mediana;
	double Vidurkis;
	double GalutinisMediana;
	double GalutinisVidurkis;

public:
	void setStudentas(string, string, string);
	void setND(int);
	void emptyND();
	int GetEgzaminoPaz() const { return Egzaminas_; }
	int GetNdDydi() const { return ND.size(); }
	void setVardas(string Vardas);
	void setPavarde(string Pavarde);
	void setND(vector <double> ND_);
	void setEgzaminas(int Egzaminas);
	int getEgzaminas() const;
	string getVardas() const;
	string getPavarde() const;
	double getGalutinisVidurkis() const;
	double getGalutinisMediana() const;
	double galutinis_balas(int, double);
	bool operator<(const studentas& s2);
	bool operator>(const studentas& s2);
	bool operator!=(const studentas& s2);
	bool operator==(const studentas& s2);
	double galutinis_balas(int, const std::vector<int>);
	double galutinis_balas(double (*) (std::vector<int>));
	void skaiciavimas();
	~studentas()
		= default; //destruktorius
	studentas& operator=(const studentas& s);
	//studentas(const studentas& OldClass);

};
bool ArSkaiciai(const std::string&);
double Vidurkis2(vector<int>);
double Mediana2(vector<int>);
void failo_generavimas(size_t i);
void SpausdinimasVidurkis(std::ostream& out, vector<studentas> Main, string::size_type x, string::size_type y);
void SpausdinimasMediana(std::ostream& out, vector<studentas> Main, string::size_type x, string::size_type y);
void Skaiciavimai(vector <studentas>& st);
void Ivedimas(vector <studentas>& st);
int Ivestis();
int Ivestis2();


studentas& studentas::operator=(const studentas& s)
{
	if (&s == this)
		return *this;
	Vardas_ = s.getVardas();
	Pavarde_ = s.getPavarde();
	GalutinisMediana = s.getGalutinisMediana();
	GalutinisVidurkis = s.getGalutinisVidurkis();
	return *this;
}
//studentas::studentas(const studentas& OldClass) {
//	Vardas_ = OldClass.Vardas_;
//	Pavarde_ = OldClass.Pavarde_;
//	ND = OldClass.ND;
//	Egzaminas_ = OldClass.Egzaminas_;
//	Vidurkis = OldClass.Vidurkis;
//	Mediana = OldClass.Mediana;
//	GalutinisMediana = OldClass.GalutinisMediana;
//	GalutinisVidurkis = OldClass.GalutinisVidurkis;
//
//}

int main()
{
	int tavopasirinkimas;
	int antraspasirinkimas;
	string simbolis;
	studentas StudentObj;
	vector <studentas> st;
	int  n;
	vector<int> paz;
	vector<studentas> kietiakai;
	vector <studentas> vargsiukai;
	int vargs = 0;
	string::size_type IlgiausiasVardas = 0, IlgiausiaPavarde = 0;
	int kiet = 0;
	string ivedimas;
	string ivesk;
	string ivestis;
	string raide;

	tavopasirinkimas = Ivestis();
	if (tavopasirinkimas == 1) {
		{
			string s;
			cout << "Jeigu norite skirstyti jau sukurtus Studentu failus (i vargsiukus ir kietiakus), esancius prie sio failo - spauskite S.\n";
			cout << "Jei norite Studentu failus kurti/generuoti is naujo bei tada juos skirstyti - spauskite G\n";
			cin >> s;
			if (s == "G" || s == "g") for (size_t i = 1000; i != 10000000; i *= 10)
			{
				st.clear();
				failo_generavimas(i);
			}
			else if (s != "S" and s != "s" and s != "G" and s != "g") { cout << "Blogai ivestas simbolis"; }
			cout << "Jei studentu pazymius norite rusiuoti pagal mediana, spauskite M" << endl;
			cout << "Jei studentu pazymius norite rusiuoti pagal vidurki, spauskite V" << endl;

			cin >> raide;
			if (raide != "M" && raide != "m" && raide != "V" && raide != "v") {
				cout << "Tokio pasirinkimo nera" << endl;
				exit(1);
			}
			else if (raide == "M" || raide == "m") {
				for (size_t i = 1000; i != 10000000; i *= 10)
				{

					string vardas_,
						pavarde_,
						Egzaminas,
						EntryLine;
					ifstream FileRead("Studentai" + std::to_string(i) + ".txt");

					if (!FileRead.good())
						cout << "Tokio failo nera." << endl;

					while (getline(FileRead, EntryLine))
					{
						std::istringstream ReadLine(EntryLine);
						ReadLine >> vardas_ >> pavarde_ >> Egzaminas;
						;
						IlgiausiasVardas = std::max(IlgiausiasVardas, vardas_.length());
						IlgiausiaPavarde = std::max(IlgiausiaPavarde, pavarde_.length());
						StudentObj.setStudentas(vardas_, pavarde_, Egzaminas);

						if (ReadLine)
						{
							StudentObj.emptyND();
							while (ReadLine >> ivesk)
							{
								if (ArSkaiciai(ivesk))
								{
									int pazymys = stoi(ivesk);

									if (pazymys > 0 && pazymys < 11)
										StudentObj.setND(pazymys);
								}
							}
							st.push_back(StudentObj);
							ReadLine.clear();
						}
						ReadLine.end;
						FileRead.clear();
					}
					FileRead.end;
					auto StartSorting = std::chrono::high_resolution_clock::now();

					vector<studentas> vargsai, kietiakai;
					vector<studentas>::iterator IT = st.begin();

					while (IT != st.end())
					{
						if ((*IT).galutinis_balas(Mediana2) < 5)
							vargsai.push_back(*IT);
						else
							kietiakai.push_back(*IT);
						IT++;
					}

					std::ofstream IrasymasKvaili;
					IrasymasKvaili.open("Vargsai" + to_string(i) + ".txt");
					SpausdinimasMediana(IrasymasKvaili, vargsai, IlgiausiasVardas, IlgiausiaPavarde);
					IrasymasKvaili.close();

					std::ofstream IrasymasProtingi;
					IrasymasProtingi.open("kietiakai" + to_string(i) + ".txt");
					SpausdinimasMediana(IrasymasProtingi, kietiakai, IlgiausiasVardas, IlgiausiaPavarde);
					IrasymasProtingi.close();

					auto EndSorting = std::chrono::high_resolution_clock::now();
					std::cout << std::to_string(i) << " Studentu skirstymas ir isvedimas i vargsiukus ir kietiakus uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(EndSorting - StartSorting).count() << " ms." << std::endl;
				}
			}
			else if (raide == "V" || raide == "v") {
				for (size_t i = 1000; i != 10000000; i *= 10)
				{

					string vardas_,
						pavarde_,
						Egzaminas,
						EntryLine;
					ifstream FileRead("Studentai" + std::to_string(i) + ".txt");

					if (!FileRead.good())
						cout << "Tokio failo nera." << endl;

					while (getline(FileRead, EntryLine))
					{
						std::istringstream ReadLine(EntryLine);
						ReadLine >> vardas_ >> pavarde_ >> Egzaminas;
						;
						IlgiausiasVardas = std::max(IlgiausiasVardas, vardas_.length());
						IlgiausiaPavarde = std::max(IlgiausiaPavarde, pavarde_.length());
						StudentObj.setStudentas(vardas_, pavarde_, Egzaminas);

						if (ReadLine)
						{
							StudentObj.emptyND();
							while (ReadLine >> ivesk)
							{
								if (ArSkaiciai(ivesk))
								{
									int pazymys = stoi(ivesk);

									if (pazymys > 0 && pazymys < 11)
										StudentObj.setND(pazymys);
								}
							}
							st.push_back(StudentObj);
							ReadLine.clear();
						}
						ReadLine.end;
						FileRead.clear();
					}
					FileRead.end;
					auto StartSorting = std::chrono::high_resolution_clock::now();

					vector<studentas> vargsai, kietiakai;
					vector<studentas>::iterator IT = st.begin();

					while (IT != st.end())
					{
						if ((*IT).galutinis_balas(Vidurkis2) < 5)
							vargsai.push_back(*IT);
						else
							kietiakai.push_back(*IT);
						IT++;
					}

					std::ofstream IrasymasKvaili;
					IrasymasKvaili.open("Vargsai" + to_string(i) + ".txt");
					SpausdinimasVidurkis(IrasymasKvaili, vargsai, IlgiausiasVardas, IlgiausiaPavarde);
					IrasymasKvaili.close();

					std::ofstream IrasymasProtingi;
					IrasymasProtingi.open("kietiakai" + to_string(i) + ".txt");
					SpausdinimasVidurkis(IrasymasProtingi, kietiakai, IlgiausiasVardas, IlgiausiaPavarde);
					IrasymasProtingi.close();

					auto EndSorting = std::chrono::high_resolution_clock::now();
					std::cout << std::to_string(i) << " Studentu skirstymas ir isvedimas i vargsiukus ir kietiakus uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(EndSorting - StartSorting).count() << " ms." << std::endl;
				}
			}
		}
		return 0;
	}
	else if (tavopasirinkimas == 2) {
		Ivedimas(st);
		antraspasirinkimas = Ivestis2();
		if (antraspasirinkimas = 1) {
			Skaiciavimai(st);
			cout << "Vardas" << "\t" << setw(23) << "Pavarde" << "\t" << "\t" << "\t" << setw(17) << "Galutinis(Vidurkis)" << endl;
			cout << "_____________________________________________________________________________" << endl;
			for (int i = 0; i < st.size(); i++)
			{
				cout << left << setw(25) << st.at(i).getVardas() << left << setw(15) << st.at(i).getPavarde() << "\t" << left << setw(23) << setprecision(3) << st.at(i).getGalutinisVidurkis() << endl;
			}
		}
		else if (antraspasirinkimas = 2) {
			Skaiciavimai(st);
			cout << "Vardas" << "\t" << setw(23) << "Pavarde" << "\t" << " \t" << "\t" << setw(17) << "Galutinis(Mediana)" << endl;
			cout << "_____________________________________________________________________________" << endl;
			for (int i = 0; i < st.size(); i++)
			{
				cout << left << setw(25) << st.at(i).getVardas() << left << setw(15) << st.at(i).getPavarde() << "\t" << left << setw(23) << setprecision(3) << st.at(i).getGalutinisMediana() << endl;
			}
		}
	}
}

bool studentas::operator<(const studentas& s2)
{
	if (Vardas_ != s2.getVardas())
		return Vardas_ < s2.getVardas();
	else
		return Pavarde_ < s2.getPavarde();
}

bool studentas::operator>(const studentas& s2)
{
	if (Vardas_ != s2.getVardas())
		return Vardas_ > s2.getVardas();
	else
		return Pavarde_ > s2.getPavarde();
}

bool studentas::operator==(const studentas& s2)
{
	if (Vardas_ == s2.getVardas() &&
		Pavarde_ == s2.getPavarde() &&
		GalutinisMediana == s2.getGalutinisMediana() &&
		GalutinisVidurkis == s2.getGalutinisVidurkis())
	{
		return true;
	}
}

bool studentas::operator!=(const studentas& s2)
{
	if (Vardas_ != s2.getVardas() ||
		Pavarde_ != s2.getPavarde() ||
		GalutinisMediana != s2.getGalutinisMediana() ||
		GalutinisVidurkis != s2.getGalutinisVidurkis())
	{
		return false;
	}


}

Zmogus::Zmogus() {}

Zmogus::Zmogus(string Vardas, string Pavarde)
{
	Vardas_ = Vardas;
	Pavarde_ = Pavarde;
}
Zmogus::~Zmogus() {}
int Ivestis() {
	string ivestis;
	int tavopasirinkimas;
	cout << "Pasirinkite:\n"
		"Jei norite dirbti su failu (failo kurimas/generavimas, rusiavimas is failo) - spauskite 1\n"
		"Jei norite studentu duomenys vesti i konsole - spauskite 2" << endl;
	while (cin >> ivestis) {
		if (ivestis == "1")
		{
			tavopasirinkimas = 1;
		}
		else if (ivestis == "2")
		{
			tavopasirinkimas = 2;
		}
		else {
			cout << "Blogai ivestas skaicius, bandykite is naujo" << endl;
			exit(1);
		}
		return tavopasirinkimas;
	}
}
int Ivestis2() {
	string ivestis;
	int antraspasirinkimas;
	cout << "Pasirinkite:\n"
		"Jei norite studentu galutini bala gauti pagal vidurki - spauskite 1\n"
		"Jei norite studentu galutini bala gauti pagal mediana -  spauskite 2" << endl;
	while (cin >> ivestis) {
		if (ivestis == "1")
		{
			antraspasirinkimas = 1;
		}
		else if (ivestis == "2")
		{
			antraspasirinkimas = 2;
		}
		else {
			cout << "Blogai ivestas skaicius, bandykite is naujo" << endl;
			exit(1);
		}
		return antraspasirinkimas;
	}
}

void studentas::setStudentas(string vardas_, string pavarde_, string Egzaminas)
{
	Vardas_ = vardas_;
	Pavarde_ = pavarde_;
	Egzaminas_ = atoi(Egzaminas.c_str());
}

void studentas::setND(int rezultatas) {
	paz.push_back(rezultatas);
}

void studentas::emptyND()
{
	paz.clear();
}


void studentas::setVardas(string Vardas)
{
	vardas = Vardas;
}

void studentas::setPavarde(string Pavarde){
	pavarde = Pavarde;
}

void studentas::setND(vector <double> ND_)
{
	ND = ND_;
}

void studentas::setEgzaminas(int Egzaminas)
{
	Egzaminas_ = Egzaminas;
}

int studentas::getEgzaminas() const
{
	return Egzaminas_;
}

string studentas::getVardas() const
{
	return vardas;
}

string studentas::getPavarde() const
{
	return pavarde;
}

double studentas::getGalutinisVidurkis() const
{
	return GalutinisVidurkis;
}

double studentas::getGalutinisMediana() const
{
	return GalutinisMediana;
}

double studentas::galutinis_balas(int Egzaminas, double namu_darbai)
{
	return 0.4 * Egzaminas + 0.6 * namu_darbai;
}
double studentas::galutinis_balas(int Egzaminas, const vector<int> namu_darbai)
{
	if (paz.size() == 0)
		throw std::domain_error("Studentas neatliko nei vieno namu darbo.");
	return galutinis_balas(Egzaminas, Vidurkis2(paz));
}

double studentas::galutinis_balas(double (*Criteria)(vector<int>))
{
	return galutinis_balas(Egzaminas_, Criteria(paz));
}

double Vidurkis2(vector<int> pazymiai)
{
	if (pazymiai.size() == 0)
		throw std::domain_error("Skaiciavimo atlikti negalima. Iveskite duomenis.");

	return std::accumulate(pazymiai.begin(), pazymiai.end(), 0.0) / pazymiai.size();
}
double Mediana2(vector<int> pazymiai)
{
	typedef vector <int>::size_type VecSize;
	VecSize size = pazymiai.size();
	sort(pazymiai.begin(), pazymiai.end());
	VecSize Middle = size / 2;

	if (size % 2 == 0)
		return (pazymiai[Middle - 1] + pazymiai[Middle]) / 2;
	else
		return pazymiai[Middle];
}
void studentas::skaiciavimas()
{

	sort(ND.begin(), ND.end());
	int position = ND.size();

	if (position % 2 == 0)
	{
		Mediana = ((ND.at(position / 2)) + (ND.at(position / 2 - 1))) / 2;
	}
	else
	{
		Mediana = ND.at(position / 2);
	}
	GalutinisMediana = (0.4 * Mediana) + (0.6 * Egzaminas_);

	for (int j = 0; j < ND.size(); j++)
	{
		Vidurkis += ND.at(j);
	}
	Vidurkis = Vidurkis / ND.size();
	GalutinisVidurkis = (0.4 * Vidurkis) + (0.6 * Egzaminas_);
}
void failo_generavimas(size_t i)
{
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::default_random_engine eng(seed);
	std::uniform_int_distribution <int> Interval(1, 10), skaicius(10, 20);

	int Studentu_skaicius = i,
		ND_skaicius = skaicius(eng);

	std::ofstream Write;
	auto StartSorting = std::chrono::high_resolution_clock::now();
	Write.open("Studentai" + to_string(i) + ".txt");
	for (size_t j = 1; j <= Studentu_skaicius; j++)
	{
		Write << "Vardas" + to_string(j) << " Pavarde" + to_string(j) << " " << Interval(eng);

		vector <int> Rezultatai;
		vector <int>::iterator IT;

		for (size_t k = 0; k < ND_skaicius; k++)
			Rezultatai.push_back(Interval(eng));

		for (IT = Rezultatai.begin(); IT < Rezultatai.end(); IT++)
			Write << " " << *IT;

		Write << endl;
	}
	Write.close();
	auto EndSorting = std::chrono::high_resolution_clock::now();
	cout << to_string(i) << " Studentu failo kurimas uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(EndSorting - StartSorting).count() << " ms." << std::endl;
}
bool ArSkaiciai(const string& str) {
	return all_of(str.begin(), str.end(), ::isdigit);
}

void Skaiciavimai(vector <studentas>& st)
{


	for (int i = 0; i < st.size(); i++)
	{

		st.at(i).skaiciavimas();

	}
}
void SpausdinimasVidurkis(std::ostream& out, vector<studentas> Main, string::size_type x, string::size_type y)
{
	for (std::vector<studentas>::iterator IT = Main.begin(); IT != Main.end(); IT++)
	{
		out << (*IT).GetVarda() << string(x + 1 - (*IT).GetVarda().size(), ' ');
		out << (*IT).GetPavarde() << string(y + 1 - (*IT).GetPavarde().size(), ' ');
		std::streamsize prec = cout.precision();
		out << std::fixed << setprecision(2) << (*IT).galutinis_balas(Vidurkis2) << " " << endl;
	}
	for (auto i = 0; i != x + y + 10; i++)
		out << "-";
	out << endl;
}
void SpausdinimasMediana(std::ostream& out, vector<studentas> Main, string::size_type x, string::size_type y) {
	for (std::vector<studentas>::iterator IT = Main.begin(); IT != Main.end(); IT++)
	{
		out << (*IT).GetVarda() << string(x + 1 - (*IT).GetVarda().size(), ' ');
		out << (*IT).GetPavarde() << string(y + 1 - (*IT).GetPavarde().size(), ' ');
		std::streamsize prec = cout.precision();
		out << std::fixed << setprecision(2) << (*IT).galutinis_balas(Mediana2) << " " << endl;
	}
	for (auto i = 0; i != x + y + 10; i++)
		out << "-";
	out << endl;

}
void Ivedimas(vector<studentas>& st) {
	int h;
	int t;
	int egzaminas;
	int pasirinkimas;
	int k;
	string  Vardas, Pavarde;
	vector<double> ND0;

	cout << "Kiek mokiniu bus?" << endl;
label1:
	cin >> k;
	if (k > 0)
	{
		studentas Data;
		for (int i = 0; i < k; i++)
		{
			cout << "Iveskite studento varda ir pavarde:" << endl;
			cin >> Vardas;
			Data.setVardas(Vardas);
			cin >> Pavarde;
			Data.setPavarde(Pavarde);
			cout << "Jei norite rezultatus vesti patys, spauskite 1. Jei norite, kad rezultatus jums generuotu automatiskai, iveskite 2" << endl;
			cin >> pasirinkimas;


			if (pasirinkimas == 1)
			{
				cout << "Iveskite studento egzamino rezultata:" << endl;
			label2:
				cin >> egzaminas;
				if (egzaminas > 0 and egzaminas < 11)
					Data.setEgzaminas(egzaminas);
				else
				{
					cout << "Toks pasirinkimas negalimas, bandykite dar karta";
					goto label2;
				}
				cout << "Iveskite studento namu darbu pazymiu skaiciu" << endl;
			label3:
				cin >> h;
				if (egzaminas > 0)
				{
					cout << "Iveskite pazymius " << endl;
					for (int j = 0; j < h; j++)
					{
					label4:
						cin >> t;
						if (t > 0 and t < 11)
						{
							ND0.push_back(t);
						}
						else
						{
							cout << "Toks pasirinkimas negalimas, bandykite dar karta ";
							goto label4;
						}
					}
				}
				else
				{
					cout << "Toks pasirinkimas negalimas, bandykite dar karta";
					goto label3;
				}
			}


			else if (pasirinkimas == 2)
			{
				srand(time(0));
				Data.setEgzaminas((1 + rand() % 10));
				cout << "Iveskite studento namu darbu pazymiu skaiciu:" << endl;
				cin >> h;

				for (int j = 0; j < h; j++)
				{
					t = (1 + rand() % 10);
					ND0.push_back(t);
				}
			}
			Data.setND(ND0);
			st.push_back(Data);
			ND0.clear();
		}
	}
	else
	{
		cout << "Bandykite dar karta" << endl;
		goto label1;
	}
}