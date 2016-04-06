  #include <iostream>
  #include <string>

  using namespace std;

  class Pessoafisica:public Pessoa
  {
    private:
      int rg, cpf;

    public:

      Pessoafisica()
      {
        rg = 0;
        cpf = 0;
      }

      Pessoafisica(string _nome, int idade, int _rg, int _cpf)
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

      int getRg ()
      {
        return rg;
      }

      void setRg (int _rg)
      {
        rg = _rg;
      }

      int getCpf ()
      {
        return cpf;
      }

      void setCpf (int _cpf)
      {
        cpf = _cpf;
      }
  };
