#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "UaiBank.h"


int ID, USER_AMOUNT, NEW_AGE;
float NEW_BALANCE;
char USERDATA[140], NEW_NAME[101];
int TRANSFER_BOOL = 0;
int NON_EXISTENT_ID = 0;


void operations ()
{
    int op;

    setlocale(LC_ALL, "Portuguese");

    scanf("%d", &op);
    puts("");

    switch(op)
    {
        case 1:
            USER_AMOUNT = 1;
            new_user();
            break;

        case 2:
            multiple_users();
            USER_AMOUNT = 0;
            break;

        case 3:
            find_user();
            break;

        case 4:
            transfer();
            TRANSFER_BOOL = 0;
            break;

        case 5:
            remove_user();
            TRANSFER_BOOL = 0;
            break;

        case 6:
            exit(0);

        default:
            puts("Opção inválida, tente novamente\n");

    }
    // limpar buffer
    int c;
    while ((c = getchar()) != '\n' ) {}

    menu();
}

int validation()
{
    int v;

    setlocale(LC_ALL, "Portuguese");

    do
    {
        scanf("%d", &v);
        if ( !(v == 0 || v == 1) )
        {
            puts("Número inválido, tente novamente");

            // limpar buffer
            int c;
            while ((c = getchar()) != '\n' ) {}
        }
    } while ( !(v == 0 || v == 1) );

    return v;
}

void new_user()
{

    setlocale(LC_ALL, "Portuguese");
    do
    {
        do
        {
            do
            {
                printf("Digite o seu nome\n");

                // limpar buffer
                int c;
                while ((c = getchar()) != '\n' ) {}

                fgets(NEW_NAME, sizeof(NEW_NAME), stdin);

                // retirar '\n' do final da string NEW_NAME
                size_t len = strlen(NEW_NAME);
                if (len > 0 && NEW_NAME[len-1] == '\n')
                {
                    NEW_NAME[len-1] = '\0';
                }

                // retirar espa�os no final do nome
                for (size_t i = 0; i < strlen(NEW_NAME); i++)
                {
                    if (NEW_NAME[i] == ' ' && NEW_NAME[i+1] == ' ')
                    {
                        NEW_NAME[i] = '\0';
                    }
                }


                // verificando se h� n�meros ou caract�res especiais no nome
                int non_alpha = 0;
                for (size_t i = 0; i < strlen(NEW_NAME); i++)
                {
                    if(!(isalpha(NEW_NAME[i])) && NEW_NAME[i] != ' ')
                    {
                        puts("Seu nome não pode conter números nem caracteres especiais, tente novamente");
                        printf("Gostaria de continuar ou voltar ao início? \nDigite 0 para continuar ou 1 para voltar ao começo\n");

                        if (validation() == 0)
                        {
                            non_alpha = 1;
                        }
                        else
                        {
                            return;
                        }
                        break;
                    }
                }

                // verificando se a string cont�m mais de 100 caracteres
                if (non_alpha != 0) {}

                else if (strlen(NEW_NAME) > 100)
                {
                    // limpar buffer
                    int c;
                    while ((c = getchar()) != '\n') {}

                    puts("Nome grande demais. O nome do usuário deve ter até 100 caracteres");
                    printf("Gostaria de continuar ou voltar ao início? \nDigite 0 para continuar ou 1 para voltar ao começo\n");

                    if (validation() == 0) {}
                    else
                    {
                        return;
                    }

                }

                else
                {
                    break;
                }
            } while (1);

            puts("");

            do
            {
                puts("Digite a sua idade");

                if (scanf("%d", &NEW_AGE) == 1 )
                {
                    if (NEW_AGE < 0)
                    {
                        puts("Idade inválida");
                        puts("Gostaria de continuar ou voltar ao início?");
                        puts("Digite 0 para continuar ou 1 para voltar ao começo");

                        if (validation() == 0) {}
                        else
                        {
                            return;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    puts("Idade inválida");
                    puts("Gostaria de continuar ou voltar ao início?");
                    puts("Digite 0 para continuar ou 1 para voltar ao começo");

                    // limpar bufffer
                    int c;
                    while ((c = getchar()) != '\n') {}

                    if (validation() == 0) {}
                    else
                    {
                        return;
                    }
                }

            } while (1);

            puts("");

            do
            {
                puts("Digite o seu saldo");

                if (scanf("%f", &NEW_BALANCE) == 1)
                {
                    if (NEW_BALANCE < 0)
                    {
                        puts("Saldo insuficiente");
                        puts("Gostaria de continuar ou voltar ao início?");
                        puts("Digite 0 para continuar ou 1 para voltar ao começo");

                        if (validation() == 0) {}
                        else
                        {
                            return;
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    puts("Saldo inválido");
                    puts("Gostaria de continuar ou voltar ao início?");
                    puts("Digite 0 para continuar ou 1 para voltar ao começo");

                    // limpar bufffer
                    int c;
                    while ((c = getchar()) != '\n') {}

                    if (validation() == 0) {}
                    else
                    {
                        return;
                    }

                }

            } while (1);

            puts("");

            puts("\nSuas informações estão corretas?\n");
            printf("Nome: %s \nIdade: %d \nSaldo: %.2f\n", NEW_NAME, NEW_AGE, NEW_BALANCE);
            puts("\nDigite 0 se não ou 1 se sim");

            if (validation() == 0) {}
            else
            {
                break;
            }

        } while (1);


        FILE * UData;

        UData = fopen("UserData.txt", "a");
        fprintf(UData, "\n%s;%d;%.2f", NEW_NAME, NEW_AGE, NEW_BALANCE);
        fclose(UData);
        puts("\nUsuário cadastrado com sucesso!\n");

        USER_AMOUNT--;
    }while (USER_AMOUNT > 0);
}

void multiple_users()
{
    do
    {
        puts("Quantos usuários gostaria de cadastrar?");

        if (scanf("%d", &USER_AMOUNT) == 1)
        {
            if (!(USER_AMOUNT > 0))
            {
                puts("Valor inválido, insira um número maior que 0");
            }
            else
            {
                break;
            }
        }
        else
        {
           puts("Valor inválido, tente novamente");
           // limpar bufffer
            int c;
            while ((c = getchar()) != '\n') {}
        }
    } while (!(USER_AMOUNT > 0));

    new_user();
}

void find_user()
{
    // usu�rio ser� encontrado pela quantidade de linhas a serem puladas no arquivo
    // o usu�rio de id=1, por exemplo, estar� na linha 2, pois uma linha ser� pulada
    NON_EXISTENT_ID = 0;
    memset(NEW_NAME, 0, sizeof(NEW_NAME));

    do
    {
        if (TRANSFER_BOOL == 0)
        {
            puts("Digite o ID do usuário que deseja acessar");
        }


        // se tiver n�o n�mero: pergunta se que ir pra menu ou reiniciar loop
        //se for tudo n�mero mas id !> 0: pergunta se que ir pra menu ou reiniciar loop
        if (scanf("%d", &ID) != 1 || !(ID > 0))
        {
            // limpar bufffer
            int c;
            while ((c = getchar()) != '\n') {}

            puts("ID inválida, tente novamente\n");
            puts("Gostaria de continuar ou voltar ao início?");
            puts("Digite 0 para continuar ou 1 para voltar ao começo");
            if (validation() == 0)
            {
                if (TRANSFER_BOOL == 1)
                {
                    puts("Digite a ID");
                }
            }
            else
            {
                menu();
            }
        }
        else
        {
            break;
        }
    } while (1);

    FILE *UData;

    UData = fopen("UserData.txt", "r");

    int current_line = 0;
    char buffer[140];
    int keep_reading = 1;

    do
    {
        fgets(buffer, 140, UData);

        if ((feof(UData) && current_line != ID) || (current_line == ID && buffer[0] == '-'))
        {
            keep_reading = 0;
            puts("ID inexistente\n");
            NON_EXISTENT_ID = 1;
        }

        else if (current_line == ID)
        {
            keep_reading = 0;
            snprintf(USERDATA, sizeof(USERDATA), "%s", buffer);

            // separando informa��es de USERDATA
            int index_1=0;
            int index_2=0;
            for (int i = 0; i < strlen(USERDATA); i++)
            {
                if (USERDATA[i] == ';' && index_1 == 0)
                {
                    index_1 = i;
                    memcpy(NEW_NAME, USERDATA, index_1);
                }
                else if (USERDATA[i] == ';' && index_2 == 0)
                {
                    // obtendo NEW_AGE
                    char age_convert[4];
                    index_2 = i;
                    memcpy(age_convert, USERDATA+index_1+1, index_2-index_1-1);
                    NEW_AGE = atoi(age_convert);

                    // obtendo NEW_BALANCE
                    char balance_convert[10];
                    memcpy(balance_convert, USERDATA+index_2+1 , strlen(USERDATA)-index_2-1);
                    NEW_BALANCE = atof(balance_convert);
                }
            }
            puts("O usuário especificado é:\n");
            printf("Nome: %s\n", NEW_NAME);
            printf("Idade: %d\n", NEW_AGE);
            printf("Saldo: %.2f\n\n", NEW_BALANCE);

        }

        current_line++;

    } while(keep_reading == 1);

    fclose(UData);
}

void transfer()
{
    float transfer, balance_1, balance_2;
    int id_1, id_2, age_1, age_2;
    char name_1[101], name_2[101],userdata_1[140], userdata_2[140];

    NON_EXISTENT_ID = 0;

    do
    {
        TRANSFER_BOOL = 1;
        puts("Digite o ID daquele que terá o dinheiro traferido");
        find_user();

        if (NON_EXISTENT_ID == 1)
        {
            continue;
        }

        puts("A conta está correta?\n");
        puts("Digite 0 para não ou 1 para sim");
        if (validation() == 1)
        {
            break;
        }
        else
        {
            continue;
        }
    } while (1);

    id_1 = ID;
    balance_1 = NEW_BALANCE;
    sprintf(name_1, NEW_NAME);
    age_1 = NEW_AGE;

    do
    {
        puts("Digite o ID da conta a receber os fundos");
        find_user();

        if (NON_EXISTENT_ID == 1)
        {
            continue;
        }

        if (ID == id_1)
        {
            puts("As duas contas não podem ser iguais");
            continue;
        }

        puts("A conta está correta?\n");
        puts("Digite 0 para não ou 1 para sim");
        if (validation() == 1)
        {
            break;
        }
        else
        {
            continue;
        }
    } while (1);

    id_2 = ID;
    balance_2 = NEW_BALANCE;
    sprintf(name_2, NEW_NAME);
    age_2 = NEW_AGE;

    do
    {
        printf("Insira um valor a ser transferido, seu saldo é de %.2f\n", balance_1);
        scanf("%f", &transfer);
        puts("");

        if (!(transfer <= balance_1))
        {
            puts("Saldo insuficiente");
            puts("Digite 0 para inserir outro valor ou 1 para voltar ao início");

            if (validation() == 0)
            {
                continue;
            }
            else
            {
                return;
            }
            if (!(transfer > 0))
            {
                puts("Valor de transferência inválido");
                puts("Digite 0 para tentar novamente ou 1 para voltar ao início");
                if (validation() == 0)
                {
                    continue;
                }
                else
                {
                    return;
                }
            }
        }
        break;
    }while (1);

    balance_1 -= transfer;
    balance_2 += transfer;

    sprintf(userdata_1, "%s;%d;%.2f\n", name_1, age_1, balance_1);
    sprintf(userdata_2, "%s;%d;%.2f\n", name_2, age_2, balance_2);

    // editando informa��es no arquivo
    FILE *UData, *temp;
    UData = fopen("UserData.txt", "r+");
    temp = fopen("temp_file.txt", "w");

    if (UData == NULL || temp == NULL)
    {
        printf("Erro ao abrir arquivo(s)\n\n");
        menu();
    }

    int current_line = 0;
    char buffer[140];
    char replace[140];
    int keep_reading = 1;


    do
    {
        fgets(buffer, 140, UData);

        if (current_line == id_1)
        {
            fputs(userdata_1, temp);
        }
        else if (current_line == id_2)
        {
            fputs(userdata_2, temp);
        }
        else
        {
            fputs(buffer, temp);
        }
        if (feof(UData))
        {
            keep_reading = 0;
        }

        current_line++;

    } while (keep_reading == 1);

    fclose(UData);
    fclose(temp);

    remove("UserData.txt");
    rename("temp_file.txt", "UserData.txt");

    puts("Transação efetuada com sucesso\n");
}

void remove_user()
{
    int current_line = 0;
    char buffer[140];
    int keep_reading = 1;

    NON_EXISTENT_ID = 0;
    TRANSFER_BOOL = 1;
    do
    {
        puts("Digite a ID do usuário que deseja remover");
        find_user();
        if (NON_EXISTENT_ID == 1)
        {
            puts("Digite 0 para tentar novamente ou 1 para voltar ao começo");
            if (validation() == 0)
            {
                continue;
            }
            else
            {
                menu();
            }
        }
        puts("Deseja realmente removê-lo?");
        puts("Digite 0 para não ou 1 para sim");

        if (validation() == 0) {}
        else
        {
            keep_reading = 0;
        }
    } while (keep_reading == 1);

    keep_reading = 1;

    FILE *UData, *temp;

    UData = fopen("UserData.txt", "r+");
    temp = fopen("temp_file.txt", "w");

    if (UData == NULL || temp == NULL)
    {
        printf("Erro ao abrir arquivo(s)\n\n");
        menu();
    }

    do{
        fgets(buffer, 140, UData);

        if (feof(UData) && current_line != ID)
        {
            keep_reading = 0;
            fputs(buffer, temp);
        }

        else if (current_line == ID)
        {
            if (feof(UData))
            {
                fputs("-", temp);
                break;
            }
            else
            {
                fputs("-\n", temp);
            }
        }
        else
        {
            fputs(buffer, temp);
        }

        // se current_line != ID: copiar em temp
        // se current_line == ID: "-\n"
        // se current_line == ID e �ltima linha: "-"
        // se �ltima linha e current_line != ID: copiar em temp e keep_reading = 0
        current_line++;
    } while (keep_reading == 1);

    fclose(UData);
    fclose(temp);

    remove("UserData.txt");
    rename("temp_file.txt", "UserData.txt");

    puts("A conta foi removida com sucesso!\n");
}

void menu ()
{
    setlocale(LC_ALL, "Portuguese");

    puts("O que deseja fazer?");
    puts("Digite 1 para registrar um novo usuário");
    puts("Digite 2 para registrar mais de um novo usuário");
    puts("Digite 3 para buscar um usuário por id");
    puts("Digite 4 para realizar uma transferência");
    puts("Digite 5 para remover um usuário por id");
    puts("Digite 6 para sair");

    operations();
}