      #include <iostream>
      #include <cstdlib>
      #include "pessoa.hpp"
      #include "pessoafisica.hpp"
      #include "pessoajuridica.hpp"

      using namespace std;

      int main()
      {
      Pessoa *raiz_arvore = NULL;
      Pessoa *novo_no;

      string nome;
      int i = 1, opcao, idade;


      while(i)
      {

      cout << "\nImforme uma opção abaixo:" <<endl;
      cout << "1 - Inserção de nó." <<endl;
      cout << "2 - Impressão dos nós." <<endl;
      cout << "3 - Sair." <<endl;
      cin>>opcao;

        switch(opcao)
        {
        case 1 :
              novo_no = new Pessoa();
              cout << "\nInforme a idade: " <<endl;
              cin>> idade;
              novo_no->setIdade(idade);
              cout << "" <<endl;

              if (raiz_arvore == NULL)
                {
                    raiz_arvore = novo_no;
                    cout << "\nFoi inserido a raiz!\n" << endl;
                }
              else
              {
              raiz_arvore->insercaoNo(novo_no);
              //cout << endl;
              }
              break;
        case 2:
        if (raiz_arvore != NULL)
            {
              cout << "\nEm Ordem: " <<endl;
              raiz_arvore->emOrdem(raiz_arvore);
              cout << "\nPre Ordem:" <<endl;
              raiz_arvore->preOrdem(raiz_arvore);
              cout << "\nPós Ordem:" <<endl;
              raiz_arvore->posOrdem(raiz_arvore);
            }
        else
          cout << "\nA árvore está vazia.\n" << endl;
              break;
        case 3:
         cout << "\nFinalizado!\n" <<endl;
         exit(1);
         //
        break;
        }
      };


      return 0;
      }
