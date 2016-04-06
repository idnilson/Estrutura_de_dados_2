#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
private:
  int teste;
protected:
  string nome, sexo;
  int idade;
public:
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
};
