#include <iostream>
#include <string>
#include "locuinta.h"
#include "locuinta.cpp"

class Meniu
{
public:
    static Meniu *get()
    {
        if (!instance)
            instance = new Meniu;
        return instance;
    }
    void startMeniu()
    {
        int gata = 0;
        char optiune;
        AgentieImobiliara agentie;
        while (!gata)
        {
            system("cls");
            Optiuni();
            try
            {
                cin >> optiune;
                if (optiune == '1')
                {
                    system("cls");
                    cin >> agentie;
                    cout << "Apasati enter pentru a continua;\n";
                    cin.get();
                }
                else if (optiune == '2')
                {
                    system("cls");
                    cin.get();
                    string tipLocuinta;
                    int corect = 0;
                    while (!corect)
                    {
                        cout << "Tip de locuinta? (Apartament sau Casa): ";
                        getline(cin, tipLocuinta);
                        if (tipLocuinta == "Apartament")
                        {
                            Apartament *A = new Apartament;
                            cout << "\nIntroduceti informatii despre apartament:\n";
                            cin >> *A;
                            cout << endl;
                            agentie.adaugaLocuinta(A);
                            corect = 1;
                        }
                        else if (tipLocuinta == "Casa")
                        {
                            Casa *C = new Casa;
                            cout << "\nIntroduceti informatii despre casa:\n";
                            cin >> *C;
                            cout << endl;
                            agentie.adaugaLocuinta(C);
                            corect = 1;
                        }
                        else
                        {
                            cout << "Alegere invalida.\n";
                        }
                    }
                    cout << "Apasati enter pentru a continua;\n";
                    cin.get();
                    cin.get();
                }
                else if (optiune == '3')
                {
                    system("cls");
                    cout << "Introduceti numarul locuintei care va fi stearsa: ";
                    char i;
                    cin >> i;
                    if (isdigit(i))
                    {
                        agentie.stergeLocuinta(int(i) - 49);
                        cout << "Apasati enter pentru a continua;\n";
                    }
                    else
                        cout << "Alegere invalida, apasati enter pentru a continua";
                    cin.get();
                    cin.get();
                }
                else if (optiune == '4')
                {
                    system("cls");
                    cout << agentie;
                    cout << "Apasati enter pentru a continua;\n";
                    cin.get();
                    cin.get();
                }
                else if (optiune == '5')
                {
                    system("cls");
                    cout << "Programul a fost inchis.\n";
                    gata = 1;
                }
                else
                {
                    system("cls");
                    cout << "Alegere invalida, apasati enter pentru a alege din nou!\n";
                    cin.get();
                    cin.get();
                }
            }
            catch (...)
            {
                system("cls");
                cout << "Alegere invalida, apasati enter pentru a incerca din nou!\n";
                cin.get();
            }
        }
    }
    void Optiuni()
    {
        cout << "Optiunea 1: Cititi un sir nou de locuinte;\n";
        cout << "Optiunea 2: Adaugati o locuinta;\n";
        cout << "Optiunea 3: Stergeti o locuinta;\n";
        cout << "Optiunea 4: Afisati locuintele;\n";
        cout << "Optiunea 5: Inchideti programul.\n";
        cout << "Alegeti o optiune: ";
    }

private:
    static Meniu *instance;
    Meniu() {}
};

Meniu *Meniu::instance = 0;

int main()
{
    system("cls");
    Locuinta::setX();

    Meniu *meniu = meniu->get();
    meniu->startMeniu();

    // asm("mov $1, %esp");
    return 0;
}