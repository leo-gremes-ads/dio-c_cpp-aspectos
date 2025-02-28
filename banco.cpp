#include <iostream>
#include <string>

// Aspecto que será comum a todos os métodos, será referenciado em todas as funções
#define LOG_TRANSACAO(mensagem) \
    std::cout << "[LOG] Transação: " << mensagem << std::endl;

class ContaBancaria
{
	private:
	std::string titular;
	double saldo;

	public:
	ContaBancaria(std::string nome, double saldo_inicial)
	{
		titular = nome;
		saldo = saldo_inicial;
		LOG_TRANSACAO("Conta criada para " + titular + " com saldo inicial de R$ " + std::to_string(saldo_inicial));
	}

	void depositar(double valor)
	{
		if (valor > 0) {
			saldo += valor;
			LOG_TRANSACAO("Depósito de R$ " + std::to_string(valor) + " realizado na conta de " + titular);
		} else {
			std::cout << "Valor de depósito inválido!" << std::endl;
		}
	}

	void sacar(double valor)
	{
		if (valor > 0 && saldo >= valor) {
			saldo -= valor;
			LOG_TRANSACAO("Saque de R$ " + std::to_string(valor) + " realizado na conta de " + titular);
		} else {
			std::cout << "Saldo insuficiente ou valor de saque inválido!" << std::endl;
		}
	}

	void consultarSaldo()
	{
		std::cout << "Saldo atual de " << titular << ": R$ " << saldo << std::endl;
	}
};

int main()
{
	ContaBancaria conta1("Alcebíades", 2754.44);
    
	conta1.depositar(502.37);
	conta1.sacar(200.0);
	conta1.consultarSaldo();
	conta1.sacar(5000);
	conta1.consultarSaldo();
	return 0;
}
