#include <fstream>  //leitura e escrita de arquivos
#include <iostream> //entrada pelo teclado e saida pela prompt
#include <time.h>   // trabalhar com o relogio do sistema
#include <stdlib.h>

using namespace std;
// inspiraçao pra funçao de sorteio
//https://wagnergaspar.com/como-gerar-numeros-aleatorios-com-a-funcao-rand-sem-repeticao/

bool verifica_numero(int vet[], int n, int aux)
{
    for (int i = 0; i < n; i++)
        if (vet[i] == aux)
            return true;
    return false;
}

void sorteia_numero(int vet[], int n, int qtddReg) //funçao para sortear a posiçao dos registros a serem impressos na tela ou arquivo
{
    srand(time(NULL));

    int aux;
    for (int i = 0; i < n; i++)
    {
        do
        {
            aux = rand() % qtddReg;
        } while (verifica_numero(vet, n, aux));

        vet[i] = aux;
    }
}

void func_teste(int tamT, int tamA, ifstream finT, ifstream finA)
{
    int n = 0;
    Artists art;
    Tracks tr;
    while (!(n == 10 || n == 100)) // loop para chamar o teste adequadamente;
    {
        cout << "Quantos registros deseja obter aleatoriamente, 10 ou 100?" << endl;
        cin >> n;
        cin.ignore();

        if (!(n == 10 || n == 100))
        {
            system("cls");
            cout << "Resposta invalida" << endl;
        }
        else if (n == 10)
        { // chamar funçao pra pegar 10 registros e imprimilos na tela
            int vetA[n], vetT[n];
            sorteia_numero(vetA, n, tamA);
            sorteia_numero(vetT, n, tamT);

            cout << "Registros Artists" << endl;
            for (int i = 0; i < n; i++)
            {
                finA.seekg(0, vetA * tamA);
                finA.read((char *)&art, tamA);
                cout << art.<< endl; // colocar os parametros a serem impressos
            }
            finA.seekg(0, finA.beg);
            cout << "Registros Tracks" << endl;
            for (int i = 0; i < n; i++)
            {
                finT.seekg(0, vetB * tamB);
                finT.read((char *)&tr, tamB);
                cout << tr.<< endl; // colocar os parametros a serem impressos
            }
            finT.seekg(0, finT.beg);
        }
        else //n= 100 ----- chamar funçao pra pegar 100 registros e criar arquivo de texto
        {
            int vetA[n], vetT[n];
            sorteia_numero(vetA, n, tamA);
            sorteia_numero(vetT, n, tamT);
            ofstream foutT, foutA;
            foutT.open("");
            foutA.open("");
            cout << "Registros Artists" << endl;
            for (int i = 0; i < n; i++)
            {
                finA.seekg(0, vetA * tamA);
                finA.read((char *)&art, tamA);
                foutA << vetA[i] << endl; // colocar os parametros a serem impressos
            }
            finA.seekg(0, finA.beg);
            foutA.close();
            cout << "Registros Tracks" << endl;
            for (int i = 0; i < n; i++)
            {
                finT.seekg(0, vetB * tamB);
                finT.read((char *)&tr, tamB);
                foutT << tr.<< endl; // colocar os parametros a serem impressos
            }
            finT.seekg(0, finT.beg);
            foutT.close();
        }
    }
    return vet[];
}

int main(int argc, char **argv) // MAIN
{
    //fonte pra mecher com seekg e tellg
    //https://www.cplusplus.com/reference/istream/istream/seekg/
    ifstream finT, finA;
    finT.open("", ios::binary);
    finA.open("", ios::binary);
    finT.seekg(0, finT.end);
    finA.seekg(0, finA.end);

    int tamT = tellg(finT) / sizeof(tr);
    int tamA = tellg(finA) / sizeof(art);

    finT.seekg(0, finT.beg);
    finA.seekg(0, finA.beg);

    func_teste(tamT, tamA, finT, finA);
    finT.close();
    finA.close();
    return 0;
}