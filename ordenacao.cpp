#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

class Ordenacao
{
  protected:
    int vetor[10];
    int i, j;

  public:

    Ordenacao()
    {
      srand(time(NULL));
      for(int i = 0; i < 10; i++)
      {
        vetor[i] = rand() % 15;
      }
    }

    void impressao()
    {
        for(i=0; i <= 9; i++)
        {
            cout <<"\nvetor = " << vetor[i] << "\n" << endl;
        }
    }

    void bubbleSort()
    {
      for (j = 9; j > 0; j--)
      {
        for (i = 0; i < j; i++)
        {
          if (vetor[i] > vetor[i+1])
          {
            int aux = vetor[i+1];
            vetor[i+1] = vetor[i];
            vetor[i]= aux;
          }
        }
      }
    }

    void selectionSort()
    {
      int menor, aux;
      for (i = 0; i < 9 - 1; i++)
      {
        menor = i;
        for (j = i + 1; j < 10; j++)
        {
          if (vetor[j] < vetor[menor])
          {
              menor = j;
          }
        }
          aux = vetor[i];
          vetor[i] = vetor[menor];
          vetor[menor] = aux;
      }
    }

    void shellSort()
    {
      int aux = 5;
      int auxTemp;

      while(aux >= 1)
      {
        for(i = aux; i < 10; i++)
        {
          auxTemp = vetor[i];
          for(j = i; j >= aux && vetor[j - aux] > auxTemp; j -= aux)
          {
            vetor[j] = vetor[j - aux];
          }
            vetor[j] = auxTemp;
        }
            aux -= 2;
      }
    }


};
int main()
{
  Ordenacao ordenar;
  cout << "\n||Antes|| "<< endl;
  ordenar.impressao();
  ordenar.bubbleSort();
  cout << "\n||Depois||"<< endl;
  ordenar.impressao();
  cout << endl;

  return 0;
}
