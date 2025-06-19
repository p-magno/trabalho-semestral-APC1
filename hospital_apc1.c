#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h> 

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define reset "\e[0m"

struct Paciente {
    char nome[50];
    char tipo_sanguineo[5];
    char gravidade[20]; 
    int tempo_espera;
    char cep[10];
    char telefone[15];
    char logradouro[100];
    char contato_emergencia_nome[50];
    char contato_emergencia_parentesco[20];
};
int main(){
    setlocale(LC_ALL, "pt_BR");
    int opcao = 0;
    struct Paciente pacientes[3];
    int num_pacientes = 0;
    printf(".---.                       .-..-. _          .-.                       .-..-.                   _  .-.       .-.     .--. .---.  .--.     ,-..-.\n");
    printf(": .; :                      : :: ::_;         : :                       : :; :                  :_;.' `.      : :    : .; :: .; :: .--'  .'  :: :\n");
    printf(":   .' .--. ,-.,-.,-. _____ : :: :.-.,-.,-. .-' : .--.    .--.   .--.   :    : .--.  .--. .---. .-.`. .'.--.  : :    :    ::  _.': :      `: :: :\n");
    printf(": .; :' '_.': ,. ,. ::_____:: `' ;: :: ,. :' .; :' .; :  ' .; ; ' .; :  : :: :' .; :`._-.': .; `: : : :' .; ; : :_   : :: :: :   : :__     : ::_;\n");
    printf(":___.'`.__.':_;:_;:_;        `.,' :_;:_;:_;`.__.'`.__.'  `.__,_;`.__.'  :_;:_;`.__.'`.__.': ._.':_; :_;`.__,_;`.__;  :_;:_;:_;   `.__.'    :_;:_;\n");
    printf("                                                                                          : :                                                    \n");
    printf("                                                                                          :_;                                                    \n");

    while (opcao != 4) {
        printf(CYN "+------------------------------------+\n" reset);
        printf(CYN "|        " YEL "MENU DE INTERNACAO" CYN "          |\n" reset);
        printf(CYN "+------------------------------------+\n" reset);
        printf(CYN "|   " GRN "1. Cadastrar novo paciente" CYN "       |\n" reset);
        printf(CYN "|   " BLU "2. Visualizar pacientes ativos" CYN "   |\n" reset);
        printf(CYN "|   " MAG "3. Modificar dados de paciente" CYN "   |\n" reset);
        printf(CYN "|   " RED "4. Sair" CYN "                          |\n" reset);
        printf(CYN "+------------------------------------+\n" reset);
        printf("Escolha uma opcao: ");
        scanf("%i", &opcao);
        while (getchar() != '\n');
        system("clear");
        printf(reset);

        switch (opcao) {
            case 1: {
                if (num_pacientes < 3) {
                    printf("\n--- Cadastro de Paciente ---\n");

                    printf("Nome: ");
                    fflush(stdout);
                    fgets(pacientes[num_pacientes].nome, sizeof(pacientes[num_pacientes].nome), stdin);
                    pacientes[num_pacientes].nome[strcspn(pacientes[num_pacientes].nome, "\n")] = 0;

                    int tipo_sanguineo_valido = 0;
                    while (!tipo_sanguineo_valido) {
                        printf("Tipo Sanguineo (A+, A- , B+, B-, AB+, AB-, O+, O-): ");
                        fflush(stdout);
                        fgets(pacientes[num_pacientes].tipo_sanguineo, sizeof(pacientes[num_pacientes].tipo_sanguineo), stdin);
                        pacientes[num_pacientes].tipo_sanguineo[strcspn(pacientes[num_pacientes].tipo_sanguineo, "\n")] = 0;
                        if (strcmp(pacientes[num_pacientes].tipo_sanguineo, "A+") == 0 ||
                            strcmp(pacientes[num_pacientes].tipo_sanguineo, "A-") == 0 ||
                            strcmp(pacientes[num_pacientes].tipo_sanguineo, "B+") == 0 ||
                            strcmp(pacientes[num_pacientes].tipo_sanguineo, "B-") == 0 ||
                            strcmp(pacientes[num_pacientes].tipo_sanguineo, "AB+") == 0 ||
                            strcmp(pacientes[num_pacientes].tipo_sanguineo, "AB-") == 0 ||
                            strcmp(pacientes[num_pacientes].tipo_sanguineo, "O+") == 0 ||
                            strcmp(pacientes[num_pacientes].tipo_sanguineo, "O-") == 0) {
                            tipo_sanguineo_valido = 1;
                        } else {
                            printf("Tipo sanguineo invalido. Tente novamente.\n");
                        }
                    }

                    int gravidade_valida = 0;
                    while (!gravidade_valida) {
                        printf("Motivo da  Internacao (Contusao, Virose, Infeccao, Outros): ");
                        fflush(stdout);
                        fgets(pacientes[num_pacientes].gravidade, sizeof(pacientes[num_pacientes].gravidade), stdin);
                        pacientes[num_pacientes].gravidade[strcspn(pacientes[num_pacientes].gravidade, "\n")] = 0;
                        if (strcmp(pacientes[num_pacientes].gravidade, "Contusao") == 0) {
                            pacientes[num_pacientes].tempo_espera = 30; 
                            gravidade_valida = 1;
                        } else if (strcmp(pacientes[num_pacientes].gravidade, "Virose") == 0) {
                            pacientes[num_pacientes].tempo_espera = 60;
                            gravidade_valida = 1;
                        } else if (strcmp(pacientes[num_pacientes].gravidade, "Infeccao") == 0) {
                            pacientes[num_pacientes].tempo_espera = 90; 
                            gravidade_valida = 1;
                        } else if (strcmp(pacientes[num_pacientes].gravidade, "Outros") == 0) {
                            pacientes[num_pacientes].tempo_espera = 120;
                            gravidade_valida = 1;
                        } else {
                            printf("Motivo invalido. Tente novamente.\n");
                        }
                    }

                    printf("CEP:   ");
                    fflush(stdout);
                    fgets(pacientes[num_pacientes].cep, sizeof(pacientes[num_pacientes].cep), stdin);
                    pacientes[num_pacientes].cep[strcspn(pacientes[num_pacientes].cep, "\n")] = 0;

                    printf("Telefone (DDD+Numero ): ");
                    fflush(stdout);
                    fgets(pacientes[num_pacientes].telefone, sizeof(pacientes[num_pacientes].telefone), stdin);
                    pacientes[num_pacientes].telefone[strcspn(pacientes[num_pacientes].telefone, "\n")] = 0;
                    
                    printf("Logradouro: ");
                    fflush(stdout);
                    fgets(pacientes[num_pacientes].logradouro, sizeof(pacientes[num_pacientes].logradouro), stdin);
                    pacientes[num_pacientes].logradouro[strcspn(pacientes[num_pacientes].logradouro, "\n")] = 0;
                    printf("Contato de Emergencia (Nome): ");
                    fflush(stdout);
                    fgets(pacientes[num_pacientes].contato_emergencia_nome, sizeof(pacientes[num_pacientes].contato_emergencia_nome), stdin);
                    pacientes[num_pacientes].contato_emergencia_nome[strcspn(pacientes[num_pacientes].contato_emergencia_nome, "\n")] = 0;

                    printf("Contato de Emergencia (Parentesco): ");
                    fflush(stdout);
                    fgets(pacientes[num_pacientes].contato_emergencia_parentesco, sizeof(pacientes[num_pacientes].contato_emergencia_parentesco), stdin);
                    pacientes[num_pacientes].contato_emergencia_parentesco[strcspn(pacientes[num_pacientes].contato_emergencia_parentesco, "\n")] = 0;

                    num_pacientes++;
                    printf("Paciente cadastrado com sucesso!\n");
                } else {
                    printf("Limite de pacientes atingido (maximo de 3).\n");
                }
                printf("Pressione ENTER para continuar...");
                while (getchar() != '\n');
                break;
            }
            case 2: {
                printf("\n--- Pacientes Ativos ---\n");
                if (num_pacientes == 0) {
                    printf("Nenhum paciente cadastrado.\n");
                } else {
                    for (int i = 0; i < num_pacientes; i++) {
                        printf("\nPaciente %d:\n", i + 1);
                        printf("Nome: %s\n", pacientes[i].nome);
                        printf("Tipo Sanguineo: %s\n", pacientes[i].tipo_sanguineo);
                        printf("Motivo da Internacao: %s\n", pacientes[i].gravidade); 
                        printf("Tempo de Espera: %d minutos\n", pacientes[i].tempo_espera);
                        printf("CEP: %s\n", pacientes[i].cep);
                        printf("Telefone: %s\n", pacientes[i].telefone);
                        printf("Logradouro: %s\n", pacientes[i].logradouro);
                        printf("Contato de Emergencia: %s (%s)\n", pacientes[i].contato_emergencia_nome, pacientes[i].contato_emergencia_parentesco);
                    }
                }
                printf("Pressione ENTER para continuar...");
                while (getchar() != '\n');
                break;
            }
            case 3: {
                printf("\n--- Modificar Dados de Paciente ---\n");
                if (num_pacientes == 0) {
                    printf("Nenhum paciente para modificar.\n");
                } else {
                    int id_modificar;
                    printf("Digite o numero do paciente para modificar (1 a %d): ", num_pacientes);
                    scanf("%d", &id_modificar);
                    while ((getchar()) != '\n');

                    if (id_modificar >= 1 && id_modificar <= num_pacientes) {
                        int index = id_modificar - 1;
                        printf("Modificando dados do Paciente %d (%s):\n", id_modificar, pacientes[index].nome);

                        printf("Novo Nome (atual: %s): ", pacientes[index].nome);
                        fgets(pacientes[index].nome, sizeof(pacientes[index].nome), stdin);
                        pacientes[index].nome[strcspn(pacientes[index].nome, "\n")] = 0;
                        int tipo_sanguineo_valido = 0;
                        while (!tipo_sanguineo_valido) {
                            printf("Novo Tipo Sanguineo (atual: %s) (A+, A-, B+, B-, AB+, AB-, O+, O-): ", pacientes[index].tipo_sanguineo);
                            fgets(pacientes[index].tipo_sanguineo, sizeof(pacientes[index].tipo_sanguineo), stdin);
                            pacientes[index].tipo_sanguineo[strcspn(pacientes[index].tipo_sanguineo, "\n")] = 0;
                            if (strcmp(pacientes[index].tipo_sanguineo, "A+") == 0 ||
                                strcmp(pacientes[index].tipo_sanguineo, "A-") == 0 ||
                                strcmp(pacientes[index].tipo_sanguineo, "B+") == 0 ||
                                strcmp(pacientes[index].tipo_sanguineo, "B-") == 0 ||
                                strcmp(pacientes[index].tipo_sanguineo, "AB+") == 0 ||
                                strcmp(pacientes[index].tipo_sanguineo, "AB-") == 0 ||
                                strcmp(pacientes[index].tipo_sanguineo, "O+") == 0 ||
                                strcmp(pacientes[index].tipo_sanguineo, "O-") == 0) {
                                tipo_sanguineo_valido = 1;
                            } else {
                                printf("Tipo sanguineo invalido. Tente novamente.\n");
                            }
                        }

                        int gravidade_valida = 0;
                        while (!gravidade_valida) {
                            printf("Novo Motivo da Internacao (atual: %s) (Contusao, Virose, Infeccao, Outros): ", pacientes[index].gravidade); 
                            fgets(pacientes[index].gravidade, sizeof(pacientes[index].gravidade), stdin);
                            pacientes[index].gravidade[strcspn(pacientes[index].gravidade, "\n")] = 0;
                            if (strcmp(pacientes[index].gravidade, "Contusao") == 0) {
                                pacientes[index].tempo_espera = 30;
                                gravidade_valida = 1;
                            } else if (strcmp(pacientes[index].gravidade, "Virose") == 0) {
                                pacientes[index].tempo_espera = 60;
                                gravidade_valida = 1;
                            } else if (strcmp(pacientes[index].gravidade, "Infeccao") == 0) {
                                pacientes[index].tempo_espera = 90;
                                gravidade_valida = 1;
                            } else if (strcmp(pacientes[index].gravidade, "Outros") == 0) {
                                pacientes[index].tempo_espera = 120;
                                gravidade_valida = 1;
                            } else {
                                printf("Motivo invalido. Tente novamente.\n");
                            }
                        }
                        printf("Novo CEP (atual: %s): ", pacientes[index].cep);
                        fgets(pacientes[index].cep, sizeof(pacientes[index].cep), stdin);
                        pacientes[index].cep[strcspn(pacientes[index].cep, "\n")] = 0;

                        printf("Novo Telefone (atual: %s): ", pacientes[index].telefone);
                        fgets(pacientes[index].telefone, sizeof(pacientes[index].telefone), stdin);
                        pacientes[index].telefone[strcspn(pacientes[index].telefone, "\n")] = 0;
                        printf("Novo Logradouro (atual: %s): ", pacientes[index].logradouro);
                        fgets(pacientes[index].logradouro, sizeof(pacientes[index].logradouro), stdin);
                        pacientes[index].logradouro[strcspn(pacientes[index].logradouro, "\n")] = 0;

                        printf("Novo Contato de Emergencia (Nome) (atual: %s): ", pacientes[index].contato_emergencia_nome);
                        fgets(pacientes[index].contato_emergencia_nome, sizeof(pacientes[index].contato_emergencia_nome), stdin);
                        pacientes[index].contato_emergencia_nome[strcspn(pacientes[index].contato_emergencia_nome, "\n")] = 0;

                        printf("Novo Contato de Emergencia (Parentesco) (atual: %s): ", pacientes[index].contato_emergencia_parentesco);
                        fgets(pacientes[index].contato_emergencia_parentesco, sizeof(pacientes[index].contato_emergencia_parentesco), stdin);
                        pacientes[index].contato_emergencia_parentesco[strcspn(pacientes[index].contato_emergencia_parentesco, "\n")] = 0;

                        printf("Dados do paciente modificados com sucesso!\n");
                    } else {
                        printf("Numero de paciente invalido.\n");
                    }
                }
                printf("Pressione ENTER para continuar...");
                while (getchar() != '\n');
                break;
            }
            case 4: {
                printf(reset);
                printf("\nObrigado por usar o Hospital APC 1!\n");
                printf("Desenvolvido em C por Pedro Magno.\n");
                break;
            }
            default: {
                printf("Opcao invalida! Tente novamente. \n");
                printf("Pressione ENTER para continuar...");
                while (getchar() != '\n');
                break;
            }
        }
    }

    return 0;
}


