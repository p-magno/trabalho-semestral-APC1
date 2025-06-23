# trabalho-semestral-APC1 #
Funcionalidades:

O código foi desenvolvido para um sistema de cadastro hospitalar, que identifica os pacientes e o motivo da internação de cada um, podendo salvar os dados de até 3 pacientes por vez (número de leitos) e modificar de acordo com a necessidade. O sistema de cadastro usa armazenamento de dados em memória, usando struct e array. Houve implementação de validação de entrada de dados para o tipo sanguíneo do paciente e o motivo da internação, que vai refletir diretamente no tempo de espera de cada paciente para a enfim internação. 

Os campos de cadastro incluem:

- Nome
- Tipo sanguíneo
- Motivo da internação (e urgência de atendimento de acordo)
- CEP
- Telefone
- Logradouro
- Contato de Emergência (Com o nome e parentesco)

Para testar o programa, você pode compilá-lo com GCC e executá-lo no terminal bash:

gcc hospital_apc1.c -lm -o a.out
./a.out

Atualização: Implementação de validação para entradas não numéricas no menu
A estratégia usada foi implementar a validação de entrada usando "fgets"e "sscanf" ao invés de "scanf", para evitar loops e garantir o bom funcionamento do código

Muito obrigado!

Pedro Magno Rabelo Teles - 2512130072