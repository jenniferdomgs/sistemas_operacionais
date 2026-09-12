# Sistemas Operacionais

Repositório destinado à disciplina de Sistemas Operacionais - TADS, IFRN
26.2.

## Organização do repositório

Este repositório contém as pastas utilizadas nos estudos e atividades da
disciplina. A aplicação de shell básica está na pasta `shell`; as demais
pastas, como `listas`, reúnem exercícios e outros estudos.

```text
.
├── listas/       # Exercícios e estudos da disciplina
└── shell/        # Aplicação de shell básica
    ├── bin/      # Diretório para executáveis locais
    └── shell.cpp # Código-fonte da aplicação
```

## Requisitos

- Linux ou outro sistema compatível com POSIX;
- compilador C++ com suporte ao C++17, como o `g++`;
- terminal.

## Como executar

Os comandos desta seção devem ser executados no terminal do sistema,
iniciando na raiz do repositório.

### 1. Acessar a pasta da aplicação

```bash
cd /caminho/para/sistemas_operacionais/shell
```

Substitua `/caminho/para` pelo local onde o repositório foi salvo. Por
exemplo, neste ambiente:

```bash
cd /home/jennifer/sistemas_operacionais/shell
```

É importante executar a aplicação a partir da pasta `shell`, pois ela contém
o código-fonte e o diretório `bin` usado na busca por executáveis locais.

### 2. Compilar o código

Ainda dentro da pasta `shell`, execute:

```bash
g++ -Wall shell.cpp -o shell
```

Esse comando transforma `shell.cpp` em um executável chamado `shell`.

### 3. Iniciar a shell

Ainda dentro da pasta `shell`, execute:

```bash
./shell
```

Quando a aplicação iniciar, será exibido o prompt:

```text
𑁍 >
```

Os comandos descritos a seguir devem ser digitados depois desse prompt,
enquanto a aplicação estiver em execução.

## Comandos disponíveis

### Comandos internos

Os comandos internos são processados pela própria aplicação.

| Comando | Descrição | Exemplo |
| --- | --- | --- |
| `pwd` | Exibe o diretório de trabalho atual. | `pwd` |
| `cd <diretório>` | Altera o diretório de trabalho. | `cd ..` |
| `history` | Exibe os dez comandos mais recentes. O índice `0` representa o comando mais recente. | `history` |
| `history -c` | Limpa o histórico da sessão. | `history -c` |
| `exit` | Encerra a shell com código de saída `0`. | `exit` |

Exemplo de sequência dentro da aplicação:

```text
𑁍 > pwd
𑁍 > cd ..
𑁍 > history
𑁍 > exit
```

### Comandos externos

A aplicação também executa programas externos encontrados nos seguintes
diretórios:

- `bin`, relativo ao diretório em que a shell foi iniciada;
- `/bin`;
- `/usr/bin`.

Por isso, comandos comuns do sistema podem ser executados diretamente:

```text
𑁍 > ls
𑁍 > ls -la
𑁍 > echo Olá
𑁍 > date
```

Também é possível informar o caminho de um executável:

```text
𑁍 > /bin/ls
```

## Limitações atuais

Esta é uma implementação básica. No momento:

- os argumentos são separados por espaços;
- não há suporte a aspas para agrupar argumentos;
- não há suporte a pipes (`|`), redirecionamento (`>`, `<`) ou execução em
  segundo plano (`&`);
- o histórico existe apenas durante a execução atual e não é salvo em arquivo;
- somente os diretórios `bin`, `/bin` e `/usr/bin` são pesquisados para
  comandos externos.

## Encerramento

Para sair da aplicação, execute dentro da shell:

```text
𑁍 > exit
```

Depois que a shell for encerrada, os comandos voltarão a ser executados no
terminal normal do sistema.
