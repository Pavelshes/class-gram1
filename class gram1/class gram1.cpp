// class gram1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<iostream>
#include<math.h>

using namespace std;
class tochka
{
public:
    double x, y;
    tochka()
    {
        x = 0;
        y = 0;
    }
    tochka(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    void set(double _x, double _y)
    {
        x = _x;
        y = _y;
    }

};
class line
{
public:

    tochka A, B;
    line()
    {
        A.set(0, 0);
        B.set(0, 0);
    }
    line(tochka _A, tochka _B)
    {
        A = _A;
        B = _B;
    }
    void set(tochka _A, tochka _B)
    {
        A = _A;
        B = _B;
    }
    double dlina()
    {
        return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
    }
};
class kvad
{
public:
    tochka A, B, C, D;
    line AB, BC, CD, AD;
    kvad()
    {
        A.set(0, 0);
        B.set(0, 0);
        C.set(0, 0);
        D.set(0, 0);
        AB.set(A, B);
        BC.set(B, C);
        CD.set(C, D);
        AD.set(A, D);
    }
    kvad(tochka _A, tochka _B, tochka _C, tochka _D)
    {
        A = _A;
        B = _B;
        C = _C;
        D = _D;
        AB.set(A, B);
        BC.set(B, C);
        CD.set(C, D);
        AD.set(A, D);
    }
public:
    void print()
    {
        cout << "AB=" << AB.dlina() << endl;
        cout << "BC=" << BC.dlina() << endl;
        cout << "CD=" << CD.dlina() << endl;
        cout << "AD=" << AD.dlina() << endl;
        cout << "P=" << AB.dlina() + BC.dlina() + CD.dlina() + AD.dlina() << endl;
        line AC(A, C);
        line BD(B, D);
        cout << "diag AC=" << AC.dlina() << endl;
        cout << "diag BD=" << BD.dlina() << endl;

    }

};
class prim :public kvad
{
protected:
    bool primTF;
    bool proverkaprim()
    {
        line AC(A, C);
        line BD(B, D);
        if (AB.dlina() == CD.dlina() && BC.dlina() == AD.dlina() && AC.dlina() == BD.dlina() && BC.dlina() != AB.dlina())
        {
            cout << "prim" << endl;
            return true;
        }
        else
            cout << "ne prim" << endl;
        return false;

    }
public:
    prim()
    {
        A.set(1, 1);
        B.set(1, 2);
        C.set(3, 2);
        D.set(3, 1);
        AB.set(A, B);
        BC.set(B, C);
        CD.set(C, D);
        AD.set(A, D);
        if (!proverkaprim())
        {
            primTF = false;
        }
        else
            primTF = true;
    }
    prim(tochka _A, tochka _B, tochka _C, tochka _D)
    {
        A = _A;
        B = _B;
        C = _C;
        D = _D;
        AB.set(A, B);
        BC.set(B, C);
        CD.set(C, D);
        AD.set(A, D);
        if (!proverkaprim())
        {

            primTF = false;
        }
        else
            primTF = true;
    }
    void print()
    {
        if (primTF)
        {
            cout << "a=" << AB.dlina() << endl;
            cout << "b=" << BC.dlina() << endl;
            cout << "P=" << 2 * (AB.dlina() + BC.dlina()) << endl;
            cout << "S=" << AB.dlina() * BC.dlina() << endl;
            line AC(A, C);
            cout << "diagonali" << AC.dlina() << endl;
        }
        else
            kvad::print();
    }
};
class paralel :public prim

{
public:
    tochka   A1, B1, C1, D1;
    line A1B1, B1C1, C1D1, A1D1, BB1, CC1, DD1, H;

protected:

    bool paralelTF;
    bool proverkaparalel()
    {
        line AC1(A, C);
        line BD1(B, D);
        if (AB.dlina() * BC.dlina() == A1B1.dlina() * B1C1.dlina() && AB.dlina() * BB1.dlina() == CC1.dlina() * CD.dlina() && BC.dlina() * CC1.dlina() == AD.dlina() * DD1.dlina() && AC1.dlina() == BD1.dlina() && AB.dlina() != BB1.dlina())
        {
            cout << "paralel" << endl;
            return true;
        }
        else
            cout << "ne paralel" << endl;
        return false;

    }
public:
    paralel()
    {
        A.set(1, 1);
        B.set(1, 2);
        C.set(3, 2);
        D.set(3, 1);
        A1.set(2, 2);
        B1.set(2, 3);
        C1.set(4, 3);
        D1.set(4, 2);
        AB.set(A, B);
        BC.set(B, C);
        CD.set(C, D);
        AD.set(A, D);
        A1B1.set(A1, B1);
        B1C1.set(B1, C1);
        C1D1.set(C1, D1);
        A1D1.set(A1, D1);
        if (!proverkaparalel())
        {
            paralelTF = false;
        }
        else
            paralelTF = true;
    }
    paralel(tochka _A, tochka _B, tochka _C, tochka _D, tochka _A1, tochka _B1, tochka _C1, tochka _D1)
    {
        A = _A;
        B = _B;
        C = _C;
        D = _D;
        A1 = _A1;
        B1 = _B1;
        C1 = _C1;
        D1 = _D1;
        AB.set(A, B);
        BC.set(B, C);
        CD.set(C, D);
        AD.set(A, D);
        A1B1.set(A1, B1);
        B1C1.set(B1, C1);
        C1D1.set(C1, D1);
        A1D1.set(A1, D1);
        if (!proverkaparalel())
        {

            paralelTF = false;
        }
        else
            paralelTF = true;
    }
    void print()
    {
        if (paralelTF)
        {
            cout << "a=" << AB.dlina() << endl;
            cout << "b=" << BC.dlina() << endl;
            line CC1(C, C1);
            cout << "h=" << CC1.dlina() << endl;
            cout << "S=" << 2 * (AB.dlina() + BC.dlina() + BC.dlina() + CC1.dlina() + CC1.dlina() + AB.dlina()) << endl;
            cout << "V=" << AB.dlina() * BC.dlina() * CC1.dlina() << endl;
            line AC(A, C);
            cout << "diagonali=" << AC.dlina() << endl;
        }
        else
            prim::print();
    }
};
int main()
{
    LC_ALL,"Rus";
    tochka A(2, 2), B(3, 2), C(3, 3), D(3, 1), A1(2, 2), B1(2, 3), C1(4, 3), D1(4, 2);
    paralel ABCDA1B1D1C1(A, B, C, D, A1, B1, C1, D1);
    ABCDA1B1D1C1.print();
    prim A1B1C1D1(A1, B1, C1, D1);
    A1B1C1D1.print();
    prim ABCC1(A, B, C, C1);
    ABCC1.print();

    system("pause");
}







// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
