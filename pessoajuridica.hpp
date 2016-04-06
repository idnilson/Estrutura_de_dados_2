#include "iostream"
##include "string"
using namespace std;

class Pessoajuridica:public Pessoa
{
private:
  long cnpj, num_contrato_social;
  string ramo_atividade;
public:
  Pessoajuridica ()
  {
    cnpj = 0;
    num_contrato_social = 0;
    ramo_atividade = "";
  }

  Pessoajuridica (string _nome, int _idade, long _cnpj, long _num_contrato_social, string _ramo_atividade)
  {
    nome = _nome;
    idade = _idade;

    cnpj = _cnpj;
    num_contrato_social = _num_contrato_social;
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

  long getNum_contrato_social ()
  {
    return num_contrato_social;
  }

  void setNum_contrato_social (long _num_contrato_social)
  {
    num_contrato_social = _num_contrato_social;
  }

  string getRamo_atividade ()
  {
    return ramo_atividade;
  }

  void setRamo_atividade (long _ramo_atividade)
  {
    ramo_atividade = _ramo_atividade;
  }
};
