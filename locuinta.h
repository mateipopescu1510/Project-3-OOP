#pragma once
#include <vector>

class Locuinta
{
public:
    Locuinta()
    {
        suprafataUtila = 0;
        discount = 0.0;
        numeClient = "";
        Y = 0;
    }
    Locuinta(int s, float d, std::string n, int y)
    {
        suprafataUtila = s;
        discount = d;
        numeClient = n;
        Y = y;
    }
    Locuinta(const Locuinta &L)
    {
        suprafataUtila = L.suprafataUtila;
        discount = L.discount;
        numeClient = L.numeClient;
        Y = L.Y;
    }
    ~Locuinta() {}
    virtual float CalculChirie() = 0;
    static void setX()
    {
        std::cout << "Introduceti valoarea standard pentru chirie: ";
        std::cin >> X;
    }
    static int getX()
    {
        return X;
    }
    void operator=(const Locuinta &L)
    {
        suprafataUtila = L.suprafataUtila;
        discount = L.discount;
        numeClient = L.numeClient;
    }

    friend std::istream &operator>>(std::istream &, Locuinta &);
    friend std::ostream &operator<<(std::ostream &, const Locuinta &);

protected:
    static int X; // valoarea standard
    int Y;        // daca se aplica discount sau nu
    std::string numeClient;
    int suprafataUtila;
    float discount;
};
int Locuinta::X = 0;

class Apartament : public Locuinta
{
public:
    Apartament()
    {
        etaj = -1;
    }
    Apartament(int s, float d, std::string n, int y, int e)
        : Locuinta(s, d, n, y)
    {
        etaj = e;
    }
    Apartament(const Apartament &A) : Locuinta(A)
    {
        etaj = A.etaj;
    }
    ~Apartament() {}

    float CalculChirie()
    {
        return X * suprafataUtila * (1 - Y * discount / 100.0);
    }

    void operator=(const Apartament &A)
    {
        etaj = A.etaj;
        const Locuinta &Lref = A;
        this->Locuinta::operator=(Lref);
    }
    friend std::istream &operator>>(std::istream &, Apartament &);
    friend std::ostream &operator<<(std::ostream &, const Apartament &);

private:
    int etaj;
};

class Casa : public Locuinta
{
public:
    Casa()
    {

        suprafataCurte = 0;
    }
    Casa(int s, float d, std::string n, int y, int sc)
        : Locuinta(s, d, n, y)
    {
        suprafataCurte = sc;
    }
    Casa(const Casa &C) : Locuinta(C)
    {
        suprafataCurte = C.suprafataCurte;
    }
    ~Casa() {}
    float CalculChirie()
    {
        return X * (suprafataUtila + 0.2 * suprafataCurte) * (1 - Y * discount / 100.0);
    }

    void operator=(const Casa &C)
    {
        suprafataCurte = C.suprafataCurte;
        const Locuinta &Lref = C;
        this->Locuinta::operator=(Lref);
    }
    friend std::istream &operator>>(std::istream &, Casa &);
    friend std::ostream &operator<<(std::ostream &, const Casa &);

private:
    int suprafataCurte;
};

template <class type>
class Repo
{
public:
    Repo() {}
    ~Repo()
    {
        locuinte.clear();
    }
    void adaugaLocuinta(type *loc)
    {
        locuinte.push_back(loc);
    }
    void stergeLocuinta(int i)
    {
        if (i > locuinte.size() || i < 0)
            std::cout << locuinte.size() << " Locuinta nu exista!\n";
        else
        {
            locuinte.erase(locuinte.begin() + i);
            std::cout << "Locuinta nr " << i + 1 << " a fost stearsa!\n";
            std::cout << "Numarul de locuinte din agentie: " << nrLocuinte() << '\n';
        }
    }
    int nrLocuinte()
    {
        return locuinte.size();
    }

protected:
    std::vector<type *> locuinte;
};

class AgentieImobiliara : public Repo<Locuinta>
{
public:
    AgentieImobiliara()
    {
        locuinte.push_back(new Casa(99, 15, "Popescu Calin", 1, 400));
        locuinte.push_back(new Apartament(57, 30, "Anghel Anica", 0, 5));
    }
    AgentieImobiliara(std::vector<Locuinta *> locuinte)
    {
        this->locuinte = locuinte;
    }
    AgentieImobiliara(const AgentieImobiliara &agentie)
    {
        locuinte = agentie.locuinte;
    }
    void operator=(const AgentieImobiliara &agentie)
    {
        locuinte = agentie.locuinte;
    }
    friend std::istream &operator>>(std::istream &, AgentieImobiliara &);
    friend std::ostream &operator<<(std::ostream &, const AgentieImobiliara &);
};
