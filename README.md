# Sistema de Gerenciamento do Programa Saúde na Escola (PSE)

## Sobre o Projeto

Este projeto foi desenvolvido como parte da **Etapa 2 da Atividade de Estudo Programada (AEP)** do curso de Engenharia de Software, com o objetivo de criar um sistema computacional em linguagem C para auxiliar no gerenciamento das ações do Programa Saúde na Escola (PSE).

O sistema permite realizar o cadastro, a consulta, a atualização e o acompanhamento de ações de saúde desenvolvidas em instituições de ensino, facilitando a organização das atividades e o controle das informações.

A aplicação foi construída utilizando os conceitos de programação estruturada, com uso de estruturas (`struct`), vetores globais, funções independentes e validações de dados, proporcionando uma organização modular e um funcionamento mais seguro.

## Funcionalidades

O sistema possui um menu interativo com cinco funcionalidades principais:

### 1. Cadastro de Ações
Permite cadastrar novas ações, informando código identificador, escola, tema, data prevista, público-alvo, responsável e quantidade estimada de participantes.

Também realiza verificações para evitar códigos duplicados e limites de armazenamento excedidos.

### 2. Listagem de Ações
Exibe todas as ações cadastradas, apresentando suas informações, situação atual e dados relacionados ao público previsto e efetivo.

### 3. Pesquisa por Código
Permite localizar uma ação específica por meio de seu código identificador, exibindo todos os dados registrados.

### 4. Atualização de Situação
Possibilita modificar o status de uma ação para uma das seguintes opções:
- Planejada;
- Realizada;
- Cancelada.

Quando uma ação é marcada como realizada, o sistema solicita a quantidade efetiva de participantes.

### 5. Resumo Geral
Apresenta informações estatísticas sobre o gerenciamento das ações, incluindo:
- Total de ações cadastradas;
- Quantidade de ações planejadas, realizadas e canceladas;
- Total de participantes previstos;
- Total de participantes efetivos;
- Taxa percentual de adesão das ações realizadas.

## Tecnologias e Conceitos Utilizados

- **Linguagem C:** desenvolvimento da aplicação.
- **Struct:** organização dos dados das ações.
- **Vetores:** armazenamento dos registros.
- **Funções:** modularização e organização do código.
- **Estruturas condicionais:** controle das operações.
- **Estruturas de repetição:** navegação pelo menu.
- **Validação de dados:** prevenção de entradas inválidas e inconsistências.

## Objetivo Acadêmico

O projeto tem como finalidade aplicar, na prática, os conhecimentos adquiridos durante o curso de Engenharia de Software, especialmente os conceitos de lógica de programação, programação estruturada, organização de dados e desenvolvimento de sistemas.

Além do aprendizado técnico, a proposta busca demonstrar como a tecnologia pode contribuir para a organização e o gerenciamento de atividades relacionadas à saúde e à educação.

## Desenvolvedores

Projeto acadêmico desenvolvido pela equipe:

- Gabriel
- Enzo
- Arthur

**Curso:** Engenharia de Software  
**Projeto:** Atividade de Estudo Programada (AEP) – Etapa 2.
