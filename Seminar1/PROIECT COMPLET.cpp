#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <map>
using namespace std;

/*SUGESTII:
1. Multe comentarii si cod comentat care mai mult induc in eroare
2. La apel, studentii sunt s1, s2, s3 etc. Nu sunt cele mai sugestive denumiri si te pierzi in ei
3. Atributul data din clasa Student ar fi putut fi mai sugestiv, acum e destul de general. La fel si in clasa studentBursier, atributul bursa
care face referire la valoarea bursei este denumit simplu "bursa"
4. Antetul pentru << este scris undeva, iar functia propriu-zisa este scrisa in alta parte, fiind mai greu asa de urmarit.
5. In main, vectorul de note ar fi putut fi creat diferit pentru ca daca dimensiunea era de 20 era cam ineficient sa fac cum am facut mai jos. (linia 785)
*/

class Student
{
	const int idStudent;
	char *nume;
	string data;
	int nrNote;
	float *note;
	char gen[10];
	static int IDuri;

public:
	//constructor fara parametri
	Student() : idStudent(IDuri++)
	{
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->data = "01-01-2020";
		this->nrNote = 0;
		this->note = NULL;
		strcpy(this->gen, "neutru");
	}

	//constructor cu parametri
	Student(const char *nume, string data, int nrNote, float *note, const char *gen) : idStudent(IDuri++)
	{
		if (strlen(nume) > 2)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}

		if (data.size() == 10)
		{
			this->data = data;
		}

		if (nrNote > 0)
			this->nrNote = nrNote;
		if (note != NULL)
		{
			this->note = new float[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
			{
				this->note[i] = note[i];
			}
		}

		if (strlen(gen) > 2)
			strcpy(this->gen, gen);
	}

	//destructor
	~Student()
	{
		if (this->nume)
		{
			delete[] this->nume;
		}
		if (this->note)
		{
			delete[] this->note;
		}
	}

	//constructor de copiere
	Student(const Student &s) : idStudent(IDuri++)
	{
		if (s.nume != NULL)
		{
			this->nume = new char[strlen(s.nume) + 1];
			strcpy(this->nume, s.nume);
		}
		this->data = s.data;
		this->nrNote = s.nrNote;
		this->note = new float[this->nrNote];
		for (int i = 0; i < this->nrNote; i++)
		{
			this->note[i] = s.note[i];
		}
		strcpy(this->gen, s.gen);
	}

	//operator =
	Student &operator=(const Student &s)
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
		this->nume = new char[strlen(s.nume) + 1];
		strcpy(this->nume, s.nume);

		this->data = s.data;

		this->nrNote = s.nrNote;

		if (this->note != NULL)
		{
			delete[] this->note;
		}
		this->note = new float[this->nrNote];
		for (int i = 0; i < this->nrNote; i++)
		{
			this->note[i] = s.note[i];
		}

		strcpy(this->gen, s.gen);

		return *this;
	}

	char *getNume()
	{
		return this->nume;
	}

	//operator <<
	friend ostream &operator<<(ostream &, Student);

	//operator >>
	friend istream &operator>>(istream &, Student &);

	//setter nume
	void setNume(const char *nume)
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}

	//operatori << >> BINARI
	friend ostream &operator<<(ofstream &, Student);
	friend istream &operator>>(ifstream &, Student &);

	//scriere si citire din FISIER BINAR
	void scriereInFisierBinar(ofstream &out)
	{
		//scriu CHAR*
		char buffer[100];
		strcpy(buffer, this->nume);
		out.write(buffer, sizeof(buffer));

		//scriu STRING
		int dimData = this->data.size();
		out.write((char *)&dimData, sizeof(int));
		out.write(this->data.c_str(), dimData + 1);

		//scriu INT
		out.write((char *)&this->nrNote, sizeof(int));

		//scriu FLOAT*
		for (int i = 0; i < this->nrNote; i++)
		{
			out.write((char *)&this->note[i], sizeof(int));
		}

		//scriu CHAR[]
		out.write(this->gen, sizeof(this->gen));
	}

	void citireDinFisierBinar(ifstream &in)
	{
		if (this->nume != NULL)
		{
			delete[] this->nume;
		}
		if (this->note != NULL)
		{
			delete[] this->note;
		}

		//citesc CHAR*
		char bufferNume[100];
		in.read(bufferNume, sizeof(bufferNume));
		this->nume = new char[strlen(bufferNume) + 1];
		strcpy(this->nume, bufferNume);

		//citesc STRING
		int dimData = 0;
		in.read((char *)&dimData, sizeof(int));
		char *auxData = new char[dimData + 1];
		in.read(auxData, dimData + 1);
		this->data = auxData;

		//citesc INT
		in.read((char *)&this->nrNote, sizeof(int));

		//citesc FLOAT*
		this->note = new float[this->nrNote];
		for (int i = 0; i < this->nrNote; i++)
		{
			in.read((char *)&this->note[i], sizeof(float));
		}

		//citesc CHAR[]
		in.read(this->gen, sizeof(this->gen));
	}

	////scriere citire FISIER TEXT
	//friend ostream& operator<<(ofstream&, Student);
	//friend istream& operator>>(istream&, Student&);

	//SUPRAINCARCARI

	////OPERATOR +
	//Student operator+(int valoare) { //student + int
	//	Student aux = *this;
	//	aux.nrNote = this->nrNote + valoare;
	//	return aux;
	//}

	//friend Student operator+(int, Student&);

	Student &operator+(float nota)
	{ //adaugare nota in vectorul de note
		Student temp = *this;
		this->note = new float[this->nrNote + 1];
		for (int i = 0; i < this->nrNote; i++)
		{
			this->note[i] = temp.note[i];
		}
		this->note[this->nrNote] = nota;
		this->nrNote++;
		return *this;
	}

	//operator -
	Student &operator-(float nota)
	{
		Student temp = *this;
		this->note = new float[this->nrNote];
		int i = 0;
		int j = 0;
		while ((i < this->nrNote) && (j < this->nrNote))
		{
			if (temp.note[i] != nota)
			{
				this->note[j] = temp.note[i];
				j++;
			}
			i++;
		}
		this->nrNote = j;
		return *this;
	}

	//operator ++

	//OPERATOR ++ PREINCREMENTARE
	friend const Student &operator++(Student &); //e prin referinta ca e preincrementare si mai intai face incrementarea si ca e fuunctie friend si nu l va avea pe this
	//OPERATOR ++ POSTINCREMENTARE
	friend const Student operator++(Student &, int i); //nu are referinta pt ca returnam aux nu s, ca altfel returna un pointer catre null
	//folosim const ca sa nu apelam operatorul in cascada

	//operator >
	bool operator>(int criteriu)
	{
		if (this->nrNote > criteriu)
		{
			return true;
		}
		else
			return false;
	}

	//operator []
	char operator[](int index)
	{
		if (this->nume != NULL)
		{
			if (index >= 0 && index < strlen(nume))
			{
				return nume[index];
			}
		}
	}

	//operator cast la string
	explicit operator string()
	{
		return this->data;
	}

	//operator !
	bool operator!()
	{
		if (this->note != NULL)
			return false;
		else
			return true;
	}

	//operator ()
	float operator()(int n)
	{ //suma primelor n note
		if (n > 0 && n < this->nrNote)
		{
			float sum = 0;
			for (int i = 0; i < n; i++)
			{
				sum += this->note[i];
			}
			return sum;
		}
		else
		{
			return 0;
		}
	}
};

//operator ++
//const Student& operator++(Student& s) {
//	s.nrNote++;
//	return s;
//}
//
//const Student operator++(Student& s, int i) {
//	Student aux = s;
//	s.nrNote++;
//	return aux;
//}

////operator +
//Student operator+(int val, Student& s) { //int + student
//	Student aux = s;
//	aux.nrNote = s.nrNote + val;
//	return aux;
//}

////operatori << >> FISIER TEXT
//ostream& operator<<(ofstream& out, Student s) {
//	out << s.idStudent << endl;
//	out << s.nume << endl;
//	out << s.data << endl;
//	out << s.nrNote << endl;
//	for (int i = 0; i < s.nrNote; i++) {
//		out << s.note[i] << endl;
//	}
//	return out;
//}
//
//istream& operator>>(ifstream& in, Student& s) {
//
//	char nume[30];
//	in >> nume;
//	s.setNume(nume);
//
//	in >> s.data;
//
//	in >> s.nrNote;
//
//	if (s.note != NULL) {
//		delete[] s.note;
//	}
//	s.note = new float[s.nrNote];
//	for (int i = 0; i < s.nrNote; i++) {
//		in >> s.note[i];
//	}
//
//	in >> s.gen;
//
//	return in;
//
//}

//operatori << >> BINARI
ostream &operator<<(ofstream &fisBin, Student s)
{
	//scriu CHAR*
	char buffer[100];
	strcpy(buffer, s.nume);
	fisBin.write(buffer, sizeof(buffer));

	//scriu STRING
	int dimData = s.data.size();
	fisBin.write((char *)&dimData, sizeof(int));
	fisBin.write(s.data.c_str(), dimData + 1);

	//scriu INT
	fisBin.write((char *)&s.nrNote, sizeof(int));

	//scriu FLOAT*
	for (int i = 0; i < s.nrNote; i++)
	{
		fisBin.write((char *)&s.note[i], sizeof(int));
	}

	//scriu CHAR[]
	fisBin.write(s.gen, sizeof(s.gen));

	return fisBin;
}

istream &operator>>(ifstream &fisBin, Student &s)
{
	if (s.nume != NULL)
	{
		delete[] s.nume;
	}
	if (s.note != NULL)
	{
		delete[] s.note;
	}

	//citesc CHAR*
	char bufferNume[100];
	fisBin.read(bufferNume, sizeof(bufferNume));
	s.nume = new char[strlen(bufferNume) + 1];
	strcpy(s.nume, bufferNume);

	//citesc STRING
	int dimData = 0;
	fisBin.read((char *)&dimData, sizeof(int));
	char *auxData = new char[dimData + 1];
	fisBin.read(auxData, dimData + 1);
	s.data = auxData;

	//citesc INT
	fisBin.read((char *)&s.nrNote, sizeof(int));

	//citesc FLOAT*
	s.note = new float[s.nrNote];
	for (int i = 0; i < s.nrNote; i++)
	{
		fisBin.read((char *)&s.note[i], sizeof(float));
	}

	//citesc CHAR[]
	fisBin.read(s.gen, sizeof(s.gen));

	return fisBin;
}

//operator <<
ostream &operator<<(ostream &out, Student s)
{
	out << "Id student: " << s.idStudent << endl;
	out << "Nume student: " << s.nume << endl;
	out << "Data nasterii: " << s.data << endl;
	out << "Nr note: " << s.nrNote << endl;
	out << "Notele sunt: ";
	for (int i = 0; i < s.nrNote; i++)
	{
		out << s.note[i] << " ";
	}
	out << endl;
	return out;
}

//operator>>
istream &operator>>(istream &in, Student &s)
{
	cout << "Nume: ";
	char nume[30];
	in >> nume;
	s.setNume(nume);
	cout << endl;

	cout << "Data: ";
	in >> s.data;
	cout << endl;

	cout << "Nr note: ";
	in >> s.nrNote;
	cout << endl;

	if (s.note != NULL)
	{
		delete[] s.note;
	}
	s.note = new float[s.nrNote];
	for (int i = 0; i < s.nrNote; i++)
	{
		cout << "Nota " << i + 1 << ": ";
		in >> s.note[i];
	}
	cout << endl;

	cout << "Genul: ";
	in >> s.gen;
	cout << endl;

	return in;
}

int Student::IDuri = 0;

class StudentBursier : public Student
{
	char *denumireBursa;
	float bursa;

public:
	//constructor fara parametri
	StudentBursier() : Student()
	{
		this->denumireBursa = new char[strlen("Anonim") + 1];
		strcpy(this->denumireBursa, "Anonim");
		this->bursa = 0;
	}

	//constructor cu parametri
	StudentBursier(const char *nume, string data, int nrNote, float *note, const char *gen, const char *denumireBursa, float bursa) : Student(nume, data, nrNote, note, gen)
	{
		this->denumireBursa = new char[strlen(denumireBursa) + 1];
		strcpy(this->denumireBursa, denumireBursa);
		this->bursa = bursa;
	}

	//constructor de copiere
	StudentBursier(const StudentBursier &sb)
	{
		this->denumireBursa = new char[strlen(sb.denumireBursa) + 1];
		strcpy(this->denumireBursa, sb.denumireBursa);
		this->bursa = sb.bursa;
	}

	//operator =
	StudentBursier &operator=(const StudentBursier &sb)
	{
		if (this->denumireBursa != NULL)
		{
			delete[] this->denumireBursa;
		}
		this->denumireBursa = new char[strlen(sb.denumireBursa) + 1];
		strcpy(this->denumireBursa, sb.denumireBursa);
		this->bursa = sb.bursa;
		return *this;
	}

	//destructor
	~StudentBursier()
	{
		if (this->denumireBursa)
		{
			delete[] this->denumireBursa;
		}
	}

	//operator <<
	friend ostream &operator<<(ostream &, StudentBursier);

	//operator !
	bool operator!()
	{
		if (this->bursa == 0)
		{
			return true;
		}
		else
			return false;
	}
};

ostream &operator<<(ostream &out, StudentBursier sb)
{
	out << "Denumire bursa: " << sb.denumireBursa << endl;
	out << "Bursa: " << sb.bursa << " lei" << endl;
	return out;
}

class Grupa
{
	string nrGrupa;
	int nrStudenti;
	Student **studenti;

public:
	//constructor fara parametri
	Grupa()
	{
		this->nrGrupa = "1000";
		this->nrStudenti = 0;
		this->studenti = NULL;
	}

	//constructor cu parametri
	Grupa(string nrGrupa, int nrStudenti, Student **studenti)
	{
		this->nrGrupa = nrGrupa;
		this->nrStudenti = nrStudenti;
		this->studenti = new Student *[this->nrStudenti];
		for (int i = 0; i < this->nrStudenti; i++)
		{
			this->studenti[i] = studenti[i];
		}
	}

	//constructor de copiere
	Grupa(const Grupa &g)
	{
		this->nrGrupa = g.nrGrupa;
		this->nrStudenti = g.nrStudenti;
		this->studenti = new Student *[this->nrStudenti];
		for (int i = 0; i < this->nrStudenti; i++)
		{
			this->studenti[i] = g.studenti[i];
		}
	}

	//operator =
	Grupa &operator=(const Grupa &g)
	{
		this->nrGrupa = g.nrGrupa;
		this->nrStudenti = g.nrStudenti;
		if (this->studenti != NULL)
		{
			delete[] this->studenti;
		}
		this->studenti = new Student *[this->nrStudenti];
		for (int i = 0; i < this->nrStudenti; i++)
		{
			this->studenti[i] = g.studenti[i];
		}
		return *this;
	}

	//destructor
	~Grupa()
	{
		if (this->studenti)
		{
			delete[] this->studenti;
		}
	}

	//operator <<
	friend ostream &operator<<(ostream &, Grupa);

	//adaugare student in vectorul de studenti din grupa
	Grupa &operator+=(Student &s)
	{
		Grupa temp = *this;
		this->studenti = new Student *[this->nrStudenti + 1];
		for (int i = 0; i < this->nrStudenti; i++)
		{
			this->studenti[i] = temp.studenti[i];
		}
		this->studenti[this->nrStudenti] = &s;
		this->nrStudenti++;
		return *this;
	}

	//stergere student din vectorul de studenti din grupa
	Grupa &operator-=(Student &s)
	{
		Grupa temp = *this;
		this->studenti = new Student *[this->nrStudenti];
		int i = 0;
		int j = 0;
		while ((i < this->nrStudenti) && (j < this->nrStudenti))
		{
			if (temp.studenti[i]->getNume() != s.getNume())
			{
				this->studenti[j] = temp.studenti[i];
				j++;
			}
			i++;
		}
		this->nrStudenti = j;
		return *this;
	}
};

ostream &operator<<(ostream &out, Grupa g)
{
	out << "Nr grupa: " << g.nrGrupa << endl;
	out << "Nr studenti: " << g.nrStudenti << endl;
	out << "Studenti: " << endl;
	for (int i = 0; i < g.nrStudenti; i++)
	{
		out << *g.studenti[i] << endl;
	}
	out << endl;
	return out;
}

//TEMPLATE

template <class T>
class Vector2
{
	T *elemente;
	int dimensiune;

public:
	Vector2(T *, int);
	~Vector2()
	{
		delete[] elemente;
	}
	T &operator[](int i)
	{
		if (i >= 0 && i < dimensiune)
		{
			return elemente[i];
		}
		else
		{
			return NULL;
		}
	}
	void afisare();
	void sortare();
};

//template <class T>
//Vector2<T>::Vector2(int n) : dimensiune(n)
//{
//	elemente = new T[n];
//	for (int i=0; i<dimensiune; i++)
//	{
//		cout<<"elementul "<<i<<": ";
//		cin>>elemente[i];
//		cout<<endl;
//	}
//}

template <class T>
Vector2<T>::Vector2(T *elem, int dim)
{
	dimensiune = dim;
	elemente = new T[dim];
	for (int i = 0; i < dimensiune; i++)
	{
		elemente[i] = elem[i];
	}
}

template <class T>
void Vector2<T>::afisare()
{
	cout << endl;
	for (int i = 0; i < dimensiune; i++)
	{
		cout << elemente[i] << " ";
	}
}

template <class T>
void Vector2<T>::sortare()
{
	int i, j;
	T aux;
	for (int i = 0; i < dimensiune - 1; i++)
		for (int j = i + 1; j < dimensiune; j++)
		{
			if (elemente[i] > elemente[j])
			{
				aux = elemente[i];
				elemente[i] = elemente[j];
				elemente[j] = aux;
			}
		}
}

void main()
{
	Student s1;

	float *vectorNote1 = new float[4];
	vectorNote1[0] = 9.5;
	vectorNote1[1] = 10;
	vectorNote1[2] = 8.5;
	vectorNote1[3] = 9;

	float *vectorNote2 = new float[2];
	vectorNote2[0] = 5;
	vectorNote2[1] = 6.5;

	Student s2("Soare", "03-08-1999", 4, vectorNote1, "feminin");
	Student s3("Popescu", "08-02-2020", 2, vectorNote2, "masculin");

	Student s4 = s1;
	Student s5;
	s5 = s2;

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;

	//Student s6;
	//cin >> s6;
	//cout << s6 << endl;

	//scriere si citire fisier BINAR cu OPERATORI << >>
	ofstream fisBinScriere("studenti.dat", ios::out | ios::binary);
	if (fisBinScriere.is_open())
	{
		fisBinScriere << s3;
		fisBinScriere.close();
	}

	Student s7;
	ifstream fisBinCitire("studenti.dat", ios::in | ios::binary);
	if (fisBinCitire.is_open())
	{
		fisBinCitire >> s7;
		fisBinCitire.close();
	}
	cout << s7 << endl;

	//scriere si citire fisier BINAR cu FUNCTII
	ofstream fisierBinScriere2("studenti2.dat", ios::out | ios::binary);
	if (fisierBinScriere2.is_open())
	{
		s3.scriereInFisierBinar(fisierBinScriere2);
		fisierBinScriere2.close();
	}

	Student s8;
	ifstream fisierBinCitire2("studenti2.dat", ios::in | ios::binary);
	if (fisierBinCitire2.is_open())
	{
		s8.citireDinFisierBinar(fisierBinCitire2);
		cout << s8 << endl;
		fisierBinCitire2.close();
	}

	//scriere+citire din fisier text
	ofstream f("fisier.txt", ios::app);
	if (f.is_open())
	{
		f << s4;
		f.close();
	}

	//ifstream f2("fisier.txt", ios::in);
	//if (f2.is_open()) {
	//	f2 >> s4;
	//	f2.close();
	//}
	//cout << "Citire s4 din fisier: " << endl << s4 << endl;

	/*cout << s1 + 10 << endl;
	cout << 10 + s1 << endl;*/

	cout << s1 + 9.5 << endl;

	cout << s3 - 5 << endl;

	cout << "Operator []" << endl;
	try
	{
		cout << s2[20] << endl;
	}
	catch (exception *e)
	{
		cout << e->what() << "Exceptie prinsa!" << endl;
	}
	catch (string e)
	{
		cout << e << "Exceptie prinsa!" << endl;
	}
	catch (...)
	{
		cout << "Exceptie prinsa!" << endl;
	}

	cout << (string)s4 << endl;

	cout << s2(2) << endl;

	StudentBursier sb1;
	cout << sb1 << endl;

	StudentBursier sb2("Ionescu", "09-05-2020", 4, vectorNote1, "masculin", "bursa de performanta", 1200);
	cout << sb2 << endl;

	if (!sb2)
	{
		cout << "Studentul nu are bursa" << endl;
	}
	else
	{
		cout << "Studentul are bursa" << endl;
	}

	Student **vectorStudenti = new Student *[4];
	vectorStudenti[0] = &s1;
	vectorStudenti[1] = &s2;
	vectorStudenti[2] = &s3;
	vectorStudenti[3] = &s4;

	Grupa g1("1054", 4, vectorStudenti);
	cout << g1 << endl;

	g1 += s5;
	cout << g1 << endl;

	g1 -= s4;
	cout << g1 << endl;

	cout << "====================STL VECTOR=======================" << endl;
	vector<Student> vs;
	vs.push_back(s2);
	vs.push_back(s3);
	vs.push_back(s4);
	vector<Student>::iterator it;
	for (it = vs.begin(); it != vs.end(); it++)
	{
		cout << *it << endl;
	}

	cout << "======================STL LISTA==========================" << endl;
	list<Student> ls;
	ls.push_back(s2);
	ls.push_back(s3);
	ls.push_back(s4);
	list<Student>::iterator it2;
	for (it2 = ls.begin(); it2 != ls.end(); it2++)
	{
		cout << *it2 << endl;
	}

	cout << "Lista dupa stergerea primului student: " << endl;
	ls.pop_front(); //sterge primul elem
	for (it2 = ls.begin(); it2 != ls.end(); it2++)
	{
		cout << *it2 << endl;
	}

	//cout << "=========================STL SET============================" << endl;
	//set<Student> ss;
	//ss.insert(s2);
	//ss.insert(s3);
	//set<Student>::iterator it3;
	//for (it3 = ss.begin(); it3 != ss.end(); it3++) {
	//	cout << *it3 << endl;
	//}

	cout << "==========================STL MAP==================================" << endl;
	map<int, Student> ms;
	ms.insert(make_pair(11111, s2));
	ms.insert(make_pair(22222, s3));
	map<int, Student>::iterator it4;
	for (it4 = ms.begin(); it4 != ms.end(); it4++)
	{
		cout << it4->first << " - " << it4->second.getNume() << endl; //afisare cheie si valoare
	}

	cout << "==============TEMPLATE===================" << endl;
	Vector2<int> vi(new int[4]{2, 4, 5, 2}, 4);
	vi.afisare();
	cout << endl;

	Student *vectStud = new Student[3];
	vectStud[0] = s2;
	vectStud[1] = s3;
	vectStud[2] = s5;
	Vector2<Student> vsTemp(vectStud, 3);
	vsTemp.afisare();

	int x;
	cin >> x;
}