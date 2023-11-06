#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Pracownik {

   // friend class BazaPracownikow;

    private:
        string imie;
        string nazwisko;
        double pensja;
        
    public:
        Pracownik(string imie="Jan", string nazwisko="Nowak", double pensja=1000): imie(imie), nazwisko(nazwisko), pensja(pensja){}
        void pokaz_dane() {
            cout << "Imie: " << imie <<endl << "Nazwisko: " << nazwisko << endl << "Pensja: " << pensja << " PLN" << endl;
        }
};

class PracownikEtatowy: public Pracownik {
    private:
        string stanowisko;
    public:
    PracownikEtatowy(string imie="Jan", string nazwisko="Nowak", double pensja=1000, string stanowisko="projektant"): Pracownik(imie, nazwisko, pensja), stanowisko(stanowisko) {}  
};

class PracownikGodzinowy: public Pracownik {
    private:
    int liczba_godzin;
    double stawka_godzinowa;
    public:
    PracownikGodzinowy(string imie="Jan", string nazwisko="Nowak", int liczba_godzin=160, double stawka_godzinowa=20): Pracownik(imie, nazwisko, liczba_godzin*stawka_godzinowa) {}
};

class BazaPracownikow {
    private:
        vector<Pracownik*> pracownicy;
    public:
        void dodajPracownika(Pracownik* pracownik) {
            pracownicy.push_back(pracownik);
        }
        void usunPracownika(int index) {
            vector<Pracownik*>::iterator pozycja = pracownicy.begin(); 
            advance(pozycja,index);
            pracownicy.erase(pozycja);
        }
        void wypiszPracownikow() {
            for (int i=0; i < pracownicy.size(); i++) {
                pracownicy[i]->pokaz_dane();
            }
        }
};


int main()
{
    BazaPracownikow baza;
    PracownikEtatowy etat1("Adam", "Gajda", 5000, "projektant");
    PracownikEtatowy *e1 = &etat1;
    PracownikGodzinowy godzina1("Jan", "Dziwny", 100, 2);
    PracownikGodzinowy *g1 = &godzina1;
    Pracownik worker;
    Pracownik *w1 = &worker;


    baza.dodajPracownika(e1);
    baza.dodajPracownika(g1);
    baza.wypiszPracownikow();
    baza.usunPracownika(0);
    baza.wypiszPracownikow();
  return 0;
}