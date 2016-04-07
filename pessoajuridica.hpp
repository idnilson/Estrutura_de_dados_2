#include "iostream"
#include "string"
using namespace std;

class Pessoajuridica:public Pessoa
{
private:
  long cnpj;
  string ramo_atividade;
public:
  Pessoajuridica ()
  {
    cnpj = 0;
    ramo_atividade = "";
  }

  Pessoajuridica (string _nome, long _idade, long _cnpj, string _ramo_atividade)
  {
    nome = _nome;
    idade = _idade;

    cnpj = _cnpj;
    ramo_atividade = _ramo_atividade;
  }

  ~Pessoajuridica ()
  {
    cout << "Deletando a pessoa juridica" <<endl;
    cout << endl;
  }

  long getCnpj ()
  {
    return cnpj;
  }

  void setCnpj (long _cnpj)
  {
    cnpj = _cnpj;
  }

  string getRamo_atividade ()
  {
    return ramo_atividade;
  }

  void setRamo_atividade (string _ramo_atividade)
  {
    ramo_atividade = _ramo_atividade;
  }
};
