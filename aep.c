#include <stdio.h>
#include <string.h>

#define MAX_ACOES 100

struct AcaoPSE {
    int codigo;
    char escola[50];
    char tema[50];
    char data_prevista[15];
    char publico_alvo[50];
    char responsavel[50];
    int qtd_prevista;
    int qtd_efetiva;
    char status[15];
};

struct AcaoPSE acoes[MAX_ACOES];
int total = 0;

void cadastrarAcao() {
    if (total >= MAX_ACOES) {
        printf("\nErro: Limite maximo de acoes atingido!\n");
        return;
    }

    int codigoTemp;
    int i; // Declarado aqui em cima para compatibilidade
    
    printf("\n--- CADASTRO DE ACAO DO PSE ---\n");
    printf("Digite o codigo da acao: ");
    scanf("%i", &codigoTemp);

    for (i = 0; i < total; i++) {
        if (acoes[i].codigo == codigoTemp) {
            printf("\nErro: Ja existe uma acao cadastrada com este codigo!\n");
            return;
        }
    }

    acoes[total].codigo = codigoTemp;
    getchar(); // Limpa o buffer do teclado

    printf("Digite o nome da escola: ");
    fgets(acoes[total].escola, 50, stdin);
    acoes[total].escola[strcspn(acoes[total].escola, "\n")] = '\0';

    printf("Digite o tema da acao: ");
    fgets(acoes[total].tema, 50, stdin);
    acoes[total].tema[strcspn(acoes[total].tema, "\n")] = '\0';

    printf("Digite a data prevista (DD/MM/AAAA): ");
    fgets(acoes[total].data_prevista, 15, stdin);
    acoes[total].data_prevista[strcspn(acoes[total].data_prevista, "\n")] = '\0';

    printf("Digite o publico-alvo: ");
    fgets(acoes[total].publico_alvo, 50, stdin);
    acoes[total].publico_alvo[strcspn(acoes[total].publico_alvo, "\n")] = '\0';

    printf("Digite o nome do responsavel: ");
    fgets(acoes[total].responsavel, 50, stdin);
    acoes[total].responsavel[strcspn(acoes[total].responsavel, "\n")] = '\0';

    do {
        printf("Digite a quantidade prevista de participantes: ");
        scanf("%i", &acoes[total].qtd_prevista);
        if (acoes[total].qtd_prevista <= 0) {
            printf("Erro! A quantidade deve ser maior que zero.\n");
        }
    } while (acoes[total].qtd_prevista <= 0);

    strcpy(acoes[total].status, "Planejada");
    acoes[total].qtd_efetiva = 0;

    total++;
    printf("\n[Sucesso] Acao cadastrada com sucesso!\n");
}

void listarAcoes() {
    if (total == 0) {
        printf("\nNenhuma acao cadastrada no sistema.\n");
        return;
    }

    int i; // Declarado aqui em cima
    printf("\n========================================\n");
    printf("         LISTAGEM DE ACOES DO PSE       \n");
    printf("========================================\n");
    for (i = 0; i < total; i++) {
        printf("Codigo: %i\n", acoes[i].codigo);
        printf("Escola: %s\n", acoes[i].escola);
        printf("Tema: %s\n", acoes[i].tema);
        printf("Data: %s\n", acoes[i].data_prevista);
        printf("Publico-Alvo: %s\n", acoes[i].publico_alvo);
        printf("Responsavel: %s\n", acoes[i].responsavel);
        printf("Previstos: %i | Efetivos: %i\n", acoes[i].qtd_prevista, acoes[i].qtd_efetiva);
        printf("Status: %s\n", acoes[i].status);
        printf("----------------------------------------\n");
    }
}

void pesquisarAcao() {
    if (total == 0) {
        printf("\nNenhuma acao cadastrada para pesquisar.\n");
        return;
    }

    int codigoBusca;
    int i; // Declarado aqui em cima
    printf("\n--- PESQUISAR ACAO POR CODIGO ---\n");
    printf("Digite o codigo da acao desejada: ");
    scanf("%i", &codigoBusca);

    int encontrada = 0;
    for (i = 0; i < total; i++) {
        if (acoes[i].codigo == codigoBusca) {
            printf("\n[Acao Encontrada!]\n");
            printf("Codigo: %i\n", acoes[i].codigo);
            printf("Escola: %s\n", acoes[i].escola);
            printf("Tema: %s\n", acoes[i].tema);
            printf("Data: %s\n", acoes[i].data_prevista);
            printf("Publico-Alvo: %s\n", acoes[i].publico_alvo);
            printf("Responsavel: %s\n", acoes[i].responsavel);
            printf("Previstos: %i | Efetivos: %i\n", acoes[i].qtd_prevista, acoes[i].qtd_efetiva);
            printf("Status: %s\n", acoes[i].status);
            encontrada = 1;
            break;
        }
    }

    if (!encontrada) {
        printf("\nAcao com o codigo %i nao foi encontrada.\n", codigoBusca);
    }
}

void atualizarSituacao() {
    if (total == 0) {
        printf("\nNenhuma acao cadastrada para atualizar.\n");
        return;
    }

    int codigoBusca;
    int i; // Declarado aqui em cima
    printf("\n--- ATUALIZAR SITUACAO DA ACAO ---\n");
    printf("Digite o codigo da acao que deseja atualizar: ");
    scanf("%i", &codigoBusca);

    int encontrada = -1;
    for (i = 0; i < total; i++) {
        if (acoes[i].codigo == codigoBusca) {
            encontrada = i;
            break;
        }
    }

    if (encontrada == -1) {
        printf("\nAcao nao encontrada!\n");
        return;
    }

    int opcaoStatus;
    printf("Situacao atual: %s\n", acoes[encontrada].status);
    printf("Escolha o novo status:\n");
    printf("1 - Planejada\n");
    printf("2 - Realizada\n");
    printf("3 - Cancelada\n");
    printf("Opcao: ");
    scanf("%i", &opcaoStatus);

    if (opcaoStatus == 1) {
        strcpy(acoes[encontrada].status, "Planejada");
        acoes[encontrada].qtd_efetiva = 0;
        printf("\nStatus atualizado para 'Planejada' com sucesso!\n");
    } else if (opcaoStatus == 2) {
        strcpy(acoes[encontrada].status, "Realizada");
        do {
            printf("Digite a quantidade efetiva de participantes: ");
            scanf("%i", &acoes[encontrada].qtd_efetiva);
            if (acoes[encontrada].qtd_efetiva < 0) {
                printf("Erro! A quantidade nao pode ser negativa.\n");
            }
        } while (acoes[encontrada].qtd_efetiva < 0);
        printf("\nStatus atualizado para 'Realizada' com sucesso!\n");
    } else if (opcaoStatus == 3) {
        strcpy(acoes[encontrada].status, "Cancelada");
        acoes[encontrada].qtd_efetiva = 0;
        printf("\nStatus atualizado para 'Cancelada' com sucesso!\n");
    } else {
        printf("\nOpcao de status invalida!\n");
    }
}

void gerarResumo() {
    if (total == 0) {
        printf("\nNenhuma acao cadastrada para gerar resumo.\n");
        return;
    }

    int contPlanejada = 0;
    int contRealizada = 0;
    int contCancelada = 0;
    int totalPrevisto = 0;
    int totalEfetivo = 0;
    int i; // Declarado aqui em cima

    for (i = 0; i < total; i++) {
        totalPrevisto += acoes[i].qtd_prevista;
        
        if (strcmp(acoes[i].status, "Planejada") == 0) {
            contPlanejada++;
        } else if (strcmp(acoes[i].status, "Realizada") == 0) {
            contRealizada++;
            totalEfetivo += acoes[i].qtd_efetiva;
        } else if (strcmp(acoes[i].status, "Cancelada") == 0) {
            contCancelada++;
        }
    }

    float percentualAdesao = 0.0;
    if (totalPrevisto > 0) {
        percentualAdesao = ((float)totalEfetivo / totalPrevisto) * 100.0;
    }

    printf("\n========================================\n");
    printf("          RESUMO GERAL DO PSE           \n");
    printf("========================================\n");
    printf("Total de acoes cadastradas: %i\n", total);
    printf("- Planejadas: %i\n", contPlanejada);
    printf("- Realizadas: %i\n", contRealizada);
    printf("- Canceladas: %i\n", contCancelada);
    printf("----------------------------------------\n");
    printf("Total de participantes previstos: %i\n", totalPrevisto);
    printf("Total de participantes efetivos: %i\n", totalEfetivo);
    printf("Taxa percentual de adesao: %.2f%%\n", percentualAdesao);
    printf("========================================\n");
}

int main() {
    int opcao = -1;

    while (opcao != 0) {
        printf("\n====================================\n");
        printf("    SISTEMA DE GERENCIAMENTO - PSE  \n");
        printf("====================================\n");
        printf("1 - Cadastrar Acao\n");
        printf("2 - Listar Acoes\n");
        printf("3 - Pesquisar Acao\n");
        printf("4 - Atualizar Situacao\n");
        printf("5 - Gerar Resumo Geral\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%i", &opcao);

        if (opcao == 1) {
            cadastrarAcao();
        } else if (opcao == 2) {
            listarAcoes();
        } else if (opcao == 3) {
            pesquisarAcao();
        } else if (opcao == 4) {
            atualizarSituacao();
        } else if (opcao == 5) {
            gerarResumo();
        } else if (opcao == 0) {
            printf("\nEncerrando o programa. Ate logo!\n");
        } else {
            printf("\nOpcao invalida! Escolha uma opcao do menu.\n");
        }
    }

    return 0;
}
