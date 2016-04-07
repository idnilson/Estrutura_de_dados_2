  #include <iostream>
  #include <string>

  using namespace std;

  class Pessoafisica:public Pessoa
  {
    private:
      long rg, cpf;

    public:

      Pessoafisica()
      {
        rg = 0;
        cpf = 0;
      }

      Pessoafisica(string _nome, long _idade, long _rg, long _cpf)
      {
        nome = _nome;
        idade = _idade;

        rg = _rg;
        cpf = _cpf;
      }

      ~Pessoafisica()
      {
        cout << "Deletando a instancia da classe pessoa fisica" <<endl;
      }

      long getRg ()
      {
        return rg;
      }

      void setRg (long _rg)
      {
        rg = _rg;
      }

      int getCpf ()
      {
        return cpf;
      }

      void setCpf (long _cpf)
      {
        cpf = _cpf;
      }
  };
