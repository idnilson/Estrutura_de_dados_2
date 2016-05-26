#include <iostream>
#include <locale.h>
#include <cstdlib> /*usar o exit(1) para fechar o programa*/
#include <iomanip>  /*Formatar casa decimais*/

using namespace std;

class Pessoa
{
	protected:
	int idade;
	Pessoa *esquerda, *direita;

	public:

	Pessoa();

	int getIdade();
	void setIdade(int idade);

	Pessoa *getEsquerda();
	void setEsquerda(Pessoa *esquerda);

	Pessoa *getDireita();
	void setDireita(Pessoa *direita);

	void insercaoNo (Pessoa *novo_no);

	void deletar_no_por_no(Pessoa *no);

	Pessoa *noSucessor(Pessoa *no);

	void remocaoNo (Pessoa **no, int idade);

	void emOrdem(Pessoa *raiz_arvore);

	void preOrdem(Pessoa *raiz_arvore);

	void posOrdem(Pessoa *raiz_arvore);

	bool buscaNo(Pessoa *no, int idade);

	int alturaArvore (Pessoa *no);

	int fatorBalanceamento (Pessoa *no);

	Pessoa *rotacaoSimplesDireita (Pessoa *no);

	Pessoa *rotacaoSimplesEsquerda (Pessoa *no);

	Pessoa *balancearArvore(Pessoa **no);

};

Pessoa::Pessoa()
{
	idade = 0;
	esquerda = NULL;
	direita = NULL;
}

int Pessoa::getIdade()
{
	return idade;
}

void Pessoa::setIdade(int idade)
{
	this->idade = idade;
}

Pessoa* Pessoa::getEsquerda()
{
	return esquerda;
}

Pessoa* Pessoa::getDireita()
{
	return direita;
}

void Pessoa::setEsquerda(Pessoa *esquerda)
{
	this->esquerda = esquerda;
}

void Pessoa::setDireita(Pessoa *direita)
{
	this->direita = direita;
}

void Pessoa::insercaoNo(Pessoa *novo_no)
{
	if(novo_no->idade < idade)
	{
		if (esquerda == NULL)
		{
			esquerda = novo_no;
		}
		else
		{
				esquerda->insercaoNo(novo_no);
	  }
	}
	else if (novo_no->idade > idade)
	{
		if (direita == NULL)
		{
			direita = novo_no;
		}
		else
		{
			direita->insercaoNo(novo_no);
		}
	}
	else
	{
		cout << "Não é permitido inserção de nós repetido" << endl;
	}
  //balancearArvore(&(*no));
}

/*Rotação : operação básica para balanceamento da AVL
Dois tipos de rotações: simples e duplas

simples: O nó desbalanceado e seu filho estão
no mesmo sentido da inclinação

duplas: O nó está desbalanceado e seu filho estão
inclinado no sentido inverso ao pai.
-Equivale a duas rotações simples
-Exitem 2 rotações a direita e 2 duplas
  - rotação a direita e a esquerda
*/

int Pessoa::alturaArvore(Pessoa *no)
{
	if(no == NULL)
	{
		return -1;
	}
	else
	{
		int altesq = alturaArvore(no->esquerda);
		int altdir =  alturaArvore(no->direita);
		return ((altesq > altdir) ? altesq : altdir) + 1;
	}
}

/*Responsável por avisar que a árvore está desbalanceada
 e também o sinal de fator de balanceamento, serve pra indicar
 qual rotação que quero escolher

 fator de balanceamento + => foi inserido para lado esquerdo
 fator de balanceamento - => foi inserido para lado direito
*/
int Pessoa::fatorBalanceamento (Pessoa *no)
{
	if(no == NULL)
	{
  	return 0;
  }
  return (alturaArvore(no->getEsquerda()) - alturaArvore(no->getDireita()));
}

Pessoa *Pessoa::rotacaoSimplesEsquerda(Pessoa *no)
{
	Pessoa *aux = no->direita;
	no->direita = aux->esquerda;
	aux->esquerda = no;
	return aux;
}
Pessoa *Pessoa::rotacaoSimplesDireita(Pessoa *no)
{
		Pessoa *aux = no->esquerda;
		no->esquerda = aux->direita;
		aux->direita = no;
		return aux;
}

Pessoa *Pessoa::balancearArvore(Pessoa **no)
{
	if ((*no) == NULL)
	{
		return (*no);
	}
	if (fatorBalanceamento((*no)) >= 2)
	{
		if (fatorBalanceamento((*no)->esquerda) == -1) //dupla direita
		{
			(*no)->esquerda = rotacaoSimplesEsquerda((*no)->esquerda);
			cout << "\nesquerda" << endl;
		}
		(*no) = rotacaoSimplesDireita((*no));
		cout << "direita" << endl;
	}
	else if (fatorBalanceamento((*no)) <= -2) //dupla a esquerda
	{
		if (fatorBalanceamento((*no)->direita) == 1)
		{
			(*no)->direita = rotacaoSimplesDireita((*no)->direita);
			cout << "\ndireita" << endl;
		}
		(*no) = rotacaoSimplesEsquerda((*no));
		cout << "esquerda" << endl;
	}
	else
	{
		cout << "\nA árvore já está balanceada.\n" << endl;
	}
	return (*no);
}


Pessoa *Pessoa::noSucessor (Pessoa *no)
{
	if (no == NULL)
	{
		return NULL;
	}
	else if (no->esquerda == NULL)
	{
		return no;
	}
	else
	{
		return noSucessor(no->esquerda);
	}
}

bool Pessoa::buscaNo(Pessoa *no, int idade)
{
	while(no != NULL)
	{
		if (idade == no->idade)
		{
			return true;
		}
		else if (idade < no->idade)
		{
			no = no->esquerda;
		}
		else
		{
			no = no->direita;
		}
	};
		return false;
}

void Pessoa::remocaoNo (Pessoa **no, int idade)
{

	if (!(*no)->buscaNo((*no), idade))
	{
		cout << "\n<<Nó não encontrado ou não existe>>\n" << endl;
	}
	else
	{
		if (idade < (*no)->idade)
		{
			remocaoNo (&(*no)->esquerda, idade);
		}
		else if (idade > (*no)->idade)
		{
			remocaoNo(&(*no)->direita, idade);
		}
		else if ((*no)->esquerda != NULL && (*no)->direita != NULL)
		{
			Pessoa *aux = NULL;
			aux = noSucessor((*no)->direita);
			(*no)->idade = aux->idade;
			remocaoNo(&(*no)->direita, (*no)->idade);
		}
		else
		{
			Pessoa *aux = (*no);
			if ((*no)->esquerda == NULL)
			{
				(*no) = (*no)->direita;
			}
			else
			{
				(*no) = (*no)->esquerda;
			}
			delete (aux);
		}
	}
}

void Pessoa::emOrdem(Pessoa *raiz_arvore)
{
	if(raiz_arvore->getEsquerda()!= NULL)
		emOrdem(raiz_arvore->getEsquerda());

	cout <<"\nIdade: "<< raiz_arvore->getIdade()<<endl;

	if(raiz_arvore->getDireita() != NULL)
		emOrdem(raiz_arvore->getDireita());
}

void Pessoa::posOrdem(Pessoa *raiz_arvore)
{
	if(raiz_arvore->getEsquerda()!=NULL)
		posOrdem(raiz_arvore->getEsquerda());

	if(raiz_arvore->getDireita()!=NULL)
		posOrdem(raiz_arvore->getDireita());

	cout <<"\nIdade: "<< raiz_arvore->getIdade()<<endl;
}

void Pessoa::preOrdem(Pessoa *raiz_arvore)
{
	cout <<"\nIdade: "<< raiz_arvore->getIdade()<<endl;

	if(raiz_arvore->getEsquerda()!=NULL)
	   	preOrdem(raiz_arvore->getEsquerda());

	if(raiz_arvore->getDireita()!=NULL)
		preOrdem(raiz_arvore->getDireita());
}

void Pessoa::deletar_no_por_no(Pessoa *no)
{
	if (no != NULL)
	{
		if(no->getEsquerda()!=NULL)
			deletar_no_por_no(no->getEsquerda());

		if(no->getEsquerda()!=NULL)
			deletar_no_por_no(no->getDireita());
	delete (no);
	cout << "<<Nós removidos>>" <<endl;
	}
	else
	{
		cout <<"\n<<Não possui nós para remoção>>\n"<<endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");

	Pessoa *raiz_arvore = NULL;
	Pessoa *novo_no;

	string nome;
	int i = 1, opcao, idade, resultado;


	while(i)
	{
		cout << "\nImforme uma opção abaixo:\n" <<endl;
		cout << "1 - Inserção de nó." <<endl;
		cout << "2 - Impressão dos nós." <<endl;
		cout << "3 - Remoção da idade na árvore." <<endl;
	  cout << "4 - Remoção de nó por nó." <<endl;
		cout << "5 - Busca." <<endl;
		cout << "6 - ALtura da árvore." << endl;
		cout << "7 - Fator de balanceamento." << endl;
		cout << "8 - Balancear arvore." << endl;
		cout << "9 - Sair.\n" << endl;
    cin  >> opcao;

		switch(opcao)
		{
			case 1:
		 	 novo_no = new Pessoa();
			 cout << "\nInforme a idade: " <<endl;
			 cin >> idade;
			 novo_no->setIdade(idade);
			 cout <<""<<endl;

			 if (raiz_arvore == NULL)
			 {
			  	raiz_arvore = novo_no;
			  	cout << "\n Foi inserido a raiz!" << endl;
			 }
			 else
			  	raiz_arvore->insercaoNo(novo_no);
			break;

			case 2:
				if (raiz_arvore != NULL)
				{
				  cout << "\nEm Ordem:" <<endl;
					raiz_arvore->emOrdem(raiz_arvore);
					cout << "\nPre Ordem:" <<endl;
					raiz_arvore->preOrdem(raiz_arvore);
					cout << "\nPós Ordem:" <<endl;
					raiz_arvore->posOrdem(raiz_arvore);
				}
				else
				{
			   		cout << "\n<<Não existe nos na Árvore>>" <<endl;
				}
			break;

			case 3:
				cout << "\nInforme a idade para ser removida:\n" << endl;
				cin >> idade;
				raiz_arvore->remocaoNo(&raiz_arvore, idade);
			break;

			case 4:
				raiz_arvore->deletar_no_por_no(raiz_arvore);
				raiz_arvore = NULL;
			break;
			case 5:
				if (raiz_arvore != NULL)
				{
					cout << "\nInforme a idade para ser buscada:\n" << endl;
					cin >> idade;
					cout << "Idade encontrada? {1 - True | 0 - False}\n" << raiz_arvore->buscaNo(raiz_arvore, idade) << endl;
				}
				else
				{
					cout << "\n<<Não exite nós para ser buscado>>\n" << endl;
				}
			break;
			case 6:
        if (raiz_arvore != NULL)
				{
					int total;
					total = raiz_arvore->alturaArvore(raiz_arvore);
					cout << "\nO total é:\n" << total << endl;
				}
				else
				{
					cout << "\nNão existe nó" << endl;
				}
			break;
			case 7:
			if (raiz_arvore != NULL)
			{
				int fator = raiz_arvore->fatorBalanceamento(raiz_arvore);
				cout << "\nO fato de balanceamento é:\n"<< fator << endl;
			}
			else
			{
				cout << "\nNão existe nós na árvore.\n" << endl;
			}
			break;
      case 8:
				raiz_arvore->balancearArvore(&raiz_arvore);
			break;
			case 9:
				cout << "\n<<Programa Finalizado>>\n" << endl;
				exit(1);
			break;

			break;
			default:
				cout << "\n<<Opção Inválida>>\n" <<endl;
		}
	};
	return 0;
}
