#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    system("cls");
    int n = 0;
    while (!(n == 10 || n == 100))
    {
        cout << "Quantos registros deseja obter aleatoriamente, 10 ou 100?" << endl;
        cin >> n;
        cin.ignore();

        if (!(n == 10 || n == 100))
        {
            system("cls");
            cout << "Resposta invalida" << endl;
        }
    }
    return 0;
}