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

void lerTextoObrigatorio(char *mensagem, char *destino, int tamanho) {
    do {
        printf("%s", mensagem);
        fgets(destino, tamanho, stdin);
        destino[strcspn(destino, "\n")] = '\0';
        if (strlen(destino) == 0) {
            printf("Erro: Este campo e obrigatorio e nao pode ficar vazio!\n");
        }
    } while (strlen(destino) == 0);
}

void cadastrarAcao() {
    if (total >= MAX_ACOES) {
        printf("\nErro: Limite maximo de acoes atingido!\n");
        return;
    }

    int codigoTemp;
    int i;
    
    printf("\n--- CADASTRO DE ACAO DO PSE ---\n");
    do {
        printf("Digite o codigo da acao (maior que 0): ");
        scanf("%i", &codigoTemp);
        if (codigoTemp <= 0) {
            printf("Erro: O codigo deve ser um numero positivo!\n");
        }
    } while (codigoTemp <= 0);

    for (i = 0; i < total; i++) {
        if (acoes[i].codigo == codigoTemp) {
            printf("\nErro: Ja existe uma acao cadastrada com este codigo!\n");
            return;
        }
    }

    acoes[total].codigo = codigoTemp;
    getchar();

    lerTextoObrigatorio("Digite o nome da escola: ", acoes[total].escola, 50);
    lerTextoObrigatorio("Digite o tema da acao: ", acoes[total].tema, 50);
    lerTextoObrigatorio("Digite a data prevista (DD/MM/AAAA): ", acoes[total].data_prevista, 15);
    lerTextoObrigatorio("Digite o publico-alvo: ", acoes[total].publico_alvo, 50);
    lerTextoObrigatorio("Digite o nome do responsavel: ", acoes[total].responsavel, 50);

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

void exibirAcao(int i) {
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

void listarAcoes() {
    if (total == 0) {
        printf("\nNenhuma acao cadastrada no sistema.\n");
        return;
    }

    int i;
    printf("\n========================================\n");
    printf("         LISTAGEM DE ACOES DO PSE       \n");
    printf("========================================\n");
    for (i = 0; i < total; i++) {
        exibirAcao(i);
    }
}

void pesquisarAcao() {
    if (total == 0) {
        printf("\nNenhuma acao cadastrada para pesquisar.\n");
        return;
    }

    int tipoBusca, i, encontradas = 0;
    printf("\n--- PESQUISAR ACAO ---\n");
    printf("1 - Pesquisar por Codigo\n");
    printf("2 - Pesquisar por Escola\n");
    printf("3 - Pesquisar por Tema\n");
    printf("Escolha o criterio de busca: ");
    scanf("%i", &tipoBusca);
    getchar();

    if (tipoBusca == 1) {
        int codigoBusca;
        printf("Digite o codigo da acao: ");
        scanf("%i", &codigoBusca);
        for (i = 0; i < total; i++) {
            if (acoes[i].codigo == codigoBusca) {
                printf("\n[Acao Encontrada!]\n");
                exibirAcao(i);
                encontradas++;
            }
        }
    } else if (tipoBusca == 2) {
        char escolaBusca[50];
        lerTextoObrigatorio("Digite o nome (ou parte do nome) da escola: ", escolaBusca, 50);
        for (i = 0; i < total; i++) {
            if (strstr(acoes[i].escola, escolaBusca) != NULL) {
                if (encontradas == 0) printf("\n[Acoes Encontradas!]\n");
                exibirAcao(i);
                encontradas++;
            }
        }
    } else if (tipoBusca == 3) {
        char temaBusca[50];
        lerTextoObrigatorio("Digite o tema (ou parte do tema): ", temaBusca, 50);
        for (i = 0; i < total; i++) {
            if (strstr(acoes[i].tema, temaBusca) != NULL) {
                if (encontradas == 0) printf("\n[Acoes Encontradas!]\n");
                exibirAcao(i);
                encontradas++;
            }
        }
    } else {
        printf("\nOpcao de busca invalida!\n");
        return;
    }

    if (encontradas == 0) {
        printf("\nNenhuma acao encontrada com o criterio informado.\n");
    }
}

void atualizarSituacao() {
    if (total == 0) {
        printf("\nNenhuma acao cadastrada para atualizar.\n");
        return;
    }

    int codigoBusca;
    int i;
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
    int i;

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

        if (opcao == 0) {
            printf("\nEncerrando o programa. Ate logo!\n");
        } else if (opcao == 1) {
            cadastrarAcao();
        } else if (opcao == 2) {
            listarAcoes();
        } else if (opcao == 3) {
            pesquisarAcao();
        } else if (opcao == 4) {
            atualizarSituacao();
        } else if (opcao == 5) {
            gerarResumo();
        } else {
            printf("\nOpcao invalida! Escolha uma opcao do menu.\n");
        }
    }

    return 0;
}
