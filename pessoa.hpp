#include <iostream>
#include <string>

using namespace std;

//void emOrdem(Pessoa *raiz_arvore);
class Pessoa
{
private:
  int teste;
protected:
  string nome, sexo;
  int idade;
  Pessoa *esquerda, *direita;
public:

  //void emOrdem(Pessoa *raiz_arvore);

  Pessoa ()
  {
    nome = "";
    idade = 0;
  }

  Pessoa (string _nome, int _idade)
  {
    nome = _nome;
    idade = _idade;
  }

  ~Pessoa()
  {
    cout << "Deletando a instancia da classe pessoa" <<endl;
    cout << endl;
  }

  string getNome()
  {
    return nome;
  }

  void setNome(string _nome)
  {
    nome = _nome;
  }

  int getIdade()
  {
    return idade;
  }

  void setIdade(int _idade)
  {
    idade = _idade;
  }

  Pessoa* getEsquerda()
  {
    return esquerda;
  }

  void setEsquerda(Pessoa *_esquerda)
  {
    esquerda = _esquerda;
  }

  Pessoa* getDireita()
  {
    return esquerda;
  }

  void setDireita(Pessoa *_direita)
  {
    direita = _direita;
  }

                     void insercaoNo(Pessoa *novo_no)
                    {
                        if(novo_no->idade <= this->idade)
                            {
                                if (this->esquerda == NULL)
                                    {
                                        this->esquerda = novo_no;
                                        cout << "ok- esq -1";
                                    }
                                    else
                                        {
                                            this->esquerda->insercaoNo(novo_no);
                                            cout << "ok- esq";
                                        }
                            }
                            else
                            {
                                if (this->direita == NULL)
                                 {
                                    this->direita = novo_no;
                                    cout << "ok - dir -1";
                                    //cout << "\nNó inserido na direita!" << endl;
                                  }
                                  else
                                   {
                                     this->direita->insercaoNo(novo_no);
                                      cout << "ok - dir";
                                     //cout << "\nNó inserido na direita!" << endl;
                                   }
                             }
                          }

                            void emOrdem(Pessoa *raiz_arvore)
                                    {

                                    if(raiz_arvore->getEsquerda()!=NULL)
                                    emOrdem(raiz_arvore->getEsquerda());

                                    cout << "\nIdade: " << raiz_arvore->getIdade()<<endl;

                                    if(raiz_arvore->getDireita()!=NULL)
                                    emOrdem(raiz_arvore->getDireita());
                                    }

       void posOrdem(Pessoa *raiz_arvore)
       {

       if(raiz_arvore->getEsquerda()!=NULL)
       posOrdem(raiz_arvore->getEsquerda());

       if(raiz_arvore->getDireita()!=NULL)
       posOrdem(raiz_arvore->getDireita());

       cout << "\nIdade: " << raiz_arvore->getIdade() <<endl;
       }

       void preOrdem(Pessoa *raiz_arvore)
        {
        cout << "\nIdade: " << raiz_arvore->getIdade()<<endl;

        if(raiz_arvore->getEsquerda()!=NULL)
        preOrdem(raiz_arvore->getEsquerda());

        if(raiz_arvore->getDireita()!=NULL)
        preOrdem(raiz_arvore->getDireita());
        }



};
