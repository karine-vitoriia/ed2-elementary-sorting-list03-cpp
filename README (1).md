# Estrutura de Dados II — Exercícios de Fixação

Repositório com as soluções dos 5 exercícios da atividade de **Estrutura de Dados II (EDII)** do curso de **Tecnologia em Análise e Desenvolvimento de Sistemas — IFTM Campus Patrocínio**.

A atividade foi disponibilizada em 26/08/2026 e a entrega está prevista para 09/09/2026.

## 📚 Sobre o projeto

Os exercícios trabalham principalmente com três algoritmos clássicos de ordenação:

- **Bubble Sort**
- **Selection Sort**
- **Insertion Sort**

Além de ordenar os vetores, alguns exercícios pedem informações extras, como quantidade de trocas, quantidade de comparações ou quantidade de inversões.

As questões propostas pedem, respectivamente: contagem de trocas no Bubble Sort, seleção dos `k` menores elementos com Selection Sort, ordenação de um vetor `k`-ordenado com Insertion Sort, ordenação por paridade e ordem com Bubble Sort e contagem de inversões por simulação do Insertion Sort.

---

## 📁 Organização do projeto

Uma organização simples para o repositório é:

```text
.
├── README.md
├── questao1.cpp
├── questao2.cpp
├── questao3.cpp
├── questao4.cpp
└── questao5.cpp
```

Cada arquivo possui:

1. Uma classe `Solution` com a lógica da questão.
2. Uma função `main()` responsável por ler os dados de entrada.
3. A chamada do método da classe.
4. A impressão do resultado.

> Os nomes dos arquivos acima são apenas uma sugestão. Caso os arquivos do repositório tenham outros nomes, basta substituir os nomes usados nos comandos de compilação.

---

# 🧠 Conceitos usados no projeto

## O que é um vetor?

No código, o vetor é representado por `vector<int>`.

Exemplo:

```cpp
vector<int> nums = {4, 3, 2, 1};
```

Nesse caso, temos um vetor com 4 números:

```text
Índice:  0  1  2  3
Valor:   4  3  2  1
```

O primeiro elemento está no índice `0`, o segundo no índice `1` e assim por diante.

## O que é `long long`?

Nos exercícios que contam trocas, comparações ou inversões, foi usado:

```cpp
using ll = long long;
```

Assim, `ll` é apenas um apelido para `long long`.

Isso é útil porque a quantidade de operações pode ser maior que o limite normalmente usado por um `int`.

## Por que `ios_base::sync_with_stdio(false)`?

No `main()` aparece:

```cpp
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```

Essas duas linhas deixam a entrada e a saída um pouco mais rápidas. Elas não mudam a lógica dos algoritmos.

---

# 1️⃣ Questão 1 — Contagem de trocas no Bubble Sort

## 📌 O que a questão pede?

A questão pede para executar o **Bubble Sort tradicional em ordem crescente** e informar:

1. O vetor ordenado.
2. A quantidade total de trocas realizadas.

## 🔍 Como o Bubble Sort funciona?

O Bubble Sort compara elementos vizinhos.

Se o elemento da esquerda for maior que o da direita, os dois são trocados.

Exemplo:

```text
4 3 2 1 5
```

Primeira comparação:

```text
4 > 3
```

Então troca:

```text
3 4 2 1 5
```

Depois:

```text
4 > 2
```

Troca:

```text
3 2 4 1 5
```

E assim por diante até o vetor ficar ordenado.

## 💻 Lógica usada no código

O trecho principal é:

```cpp
for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
        if (nums[j] > nums[j + 1]) {
            swap(nums[j], nums[j + 1]);
            swaps++;
        }
    }
}
```

A ideia é:

- `i` controla as passagens pelo vetor.
- `j` percorre os elementos vizinhos.
- `nums[j] > nums[j + 1]` verifica se os dois estão fora de ordem.
- `swap(...)` troca os dois elementos.
- `swaps++` soma uma troca.

No final, o método devolve o vetor ordenado e o número de trocas:

```cpp
return {nums, swaps};
```

## 📝 Exemplo 1

**Entrada:**

```text
5
4 3 2 1 5
```

**Saída:**

```text
1 2 3 4 5
6
```

Nesse exemplo, foram necessárias 6 trocas para transformar `4 3 2 1 5` em `1 2 3 4 5`. Esse é o primeiro exemplo apresentado no enunciado.

## 📝 Exemplo 2

**Entrada:**

```text
4
1 2 3 4
```

**Saída:**

```text
1 2 3 4
0
```

Como o vetor já está ordenado, nenhuma troca é necessária.

## ⏱️ Complexidade

O Bubble Sort tradicional possui complexidade de tempo de aproximadamente:

```text
O(N²)
```

Isso acontece porque existem dois laços que podem percorrer o vetor várias vezes.

---

# 2️⃣ Questão 2 — Seleção dos k menores elementos

## 📌 O que a questão pede?

A questão pede para executar **somente as primeiras `k` passagens do Selection Sort** e imprimir os `k` primeiros elementos resultantes. A ideia é que, depois de `k` passagens, os `k` menores elementos já estejam posicionados e ordenados no início do vetor.

## 🔍 Como o Selection Sort funciona?

A cada passagem, procuramos o menor elemento da parte que ainda não foi organizada.

Depois colocamos esse menor elemento na posição correta.

Por exemplo:

```text
29 10 14 37 13 42
```

### 1ª passagem

O menor elemento de todo o vetor é `10`.

Ele vai para a primeira posição:

```text
10 29 14 37 13 42
```

### 2ª passagem

Agora procuramos o menor elemento do restante:

```text
29 14 37 13 42
```

O menor é `13`.

Fica:

```text
10 13 14 37 29 42
```

### 3ª passagem

O menor restante é `14`:

```text
10 13 14 37 29 42
```

Como `k = 3`, podemos parar aqui.

Os três primeiros elementos são:

```text
10 13 14
```

## 💻 Lógica usada no código

O trecho principal é:

```cpp
for (int i = 0; i < k; ++i) {
    int min_idx = i;

    for (int j = i + 1; j < n; ++j) {
        if (nums[j] < nums[min_idx]) {
            min_idx = j;
        }
    }

    swap(nums[i], nums[min_idx]);
}
```

O funcionamento é:

- `i` indica a posição que será preenchida.
- `min_idx` guarda o índice do menor elemento encontrado.
- `j` percorre o restante do vetor procurando um valor menor.
- No final da passagem, `swap` coloca o menor elemento na posição `i`.

Depois disso, o código devolve somente os `k` primeiros elementos:

```cpp
return vector<int>(nums.begin(), nums.begin() + k);
```

## 📝 Exemplo 1

**Entrada:**

```text
6 3
29 10 14 37 13 42
```

**Saída:**

```text
10 13 14
```

Esse é o primeiro exemplo do enunciado.

## 📝 Exemplo 2

**Entrada:**

```text
5 2
8 5 3 9 1
```

**Saída:**

```text
1 3
```

As duas primeiras passagens deixam os dois menores valores nas duas primeiras posições.

## ⏱️ Complexidade

Como a busca pelo menor elemento ainda percorre o restante do vetor em cada passagem, a implementação continua tendo comportamento de ordem:

```text
O(N²)
```

A diferença é que, neste exercício, executamos somente as primeiras `k` passagens.

---

# 3️⃣ Questão 3 — Vetor quase-ordenado com Insertion Sort

## 📌 O que a questão pede?

A questão apresenta um vetor **k-ordenado** (ou quase-ordenado). Isso significa que cada elemento está a no máximo `k` posições de sua posição final correta.

O exercício pede para executar o **Insertion Sort**, ordenar totalmente o vetor e contar as comparações feitas pelo laço interno `while`.

## 🔍 Como o Insertion Sort funciona?

A ideia é parecida com organizar cartas na mão.

Pegamos um elemento e verificamos onde ele deve ficar entre os elementos que já estão organizados.

Exemplo simples:

```text
3 2 1
```

Primeiro pegamos `2` e comparamos com `3`.

Como `3 > 2`, deslocamos `3` para a direita:

```text
3 3 1
```

Depois colocamos `2` na posição correta:

```text
2 3 1
```

Depois fazemos o mesmo com `1`.

Resultado:

```text
1 2 3
```

## 💻 Lógica usada no código

O trecho principal é:

```cpp
for (int i = 1; i < n; ++i) {
    int key = nums[i];
    int j = i - 1;

    while (j >= 0) {
        comparacoes++;

        if (nums[j] > key) {
            nums[j + 1] = nums[j];
            j--;
        } else {
            break;
        }
    }

    nums[j + 1] = key;
}
```

### O que cada parte faz?

`key` guarda o elemento que será inserido:

```cpp
int key = nums[i];
```

`j` começa no elemento anterior:

```cpp
int j = i - 1;
```

Enquanto houver elementos para comparar:

```cpp
while (j >= 0)
```

A comparação é contabilizada:

```cpp
comparacoes++;
```

Se o elemento anterior for maior que `key`, ele é deslocado para a direita:

```cpp
nums[j + 1] = nums[j];
```

Quando encontramos uma posição correta, o laço para:

```cpp
break;
```

Por fim, `key` é colocado no lugar correto:

```cpp
nums[j + 1] = key;
```

## 📝 Exemplo do enunciado

**Entrada:**

```text
6 2
3 2 1 5 4 6
```

O vetor informado pelo enunciado está em uma situação de quase-ordenação com `k = 2`.

A saída apresentada na atividade é:

```text
1 2 3 4 5 6
8
```

O vetor é corretamente ordenado pelo algoritmo.

### ⚠️ Observação sobre a contagem do exemplo

Há uma diferença entre o exemplo do PDF e a implementação apresentada neste repositório.

O código conta **cada entrada no `while` como uma comparação**, inclusive quando a condição `nums[j] > key` é falsa. Seguindo exatamente essa regra do código para a entrada acima, a contagem chega a **7**, e não 8.

Portanto, antes da entrega, vale conferir com o professor qual definição de "comparação" deve ser usada na Questão 3. O enunciado informa `8` para esse exemplo, mas o código fornecido nesta solução, com a lógica atual, produz `7`.

## 📝 Segundo exemplo do enunciado

**Entrada:**

```text
5 1
2 1 4 3 5
```

**Saída apresentada no enunciado:**

```text
1 2 3 4 5
6
```

O exemplo mostra a ideia de um vetor 1-ordenado, em que os elementos estão próximos de suas posições finais.

## ⏱️ Complexidade

O enunciado destaca que, para um vetor `k`-ordenado, o Insertion Sort pode ter comportamento próximo de:

```text
O(N · k)
```

em vez do pior caso quadrático:

```text
O(N²)
```

Isso acontece porque, quando o vetor está quase ordenado, normalmente são necessários poucos deslocamentos para inserir cada elemento.

---

# 4️⃣ Questão 4 — Ordenação por paridade com Bubble Sort

## 📌 O que a questão pede?

Aqui o Bubble Sort é adaptado para seguir **três regras ao mesmo tempo**:

1. Todos os pares devem ficar antes dos ímpares.
2. Os pares devem ficar em ordem crescente.
3. Os ímpares devem ficar em ordem decrescente.

## 🔍 Como a comparação funciona?

O código criou uma função própria:

```cpp
bool shouldSwap(int a, int b)
```

Ela decide se os dois elementos vizinhos precisam trocar de lugar.

### Caso 1 — `a` é par e `b` é ímpar

Não troca.

```text
2 5
```

Já está certo, porque o par deve vir antes do ímpar.

### Caso 2 — `a` é ímpar e `b` é par

Troca.

```text
5 2
```

Fica:

```text
2 5
```

### Caso 3 — os dois são pares

Precisamos de ordem crescente.

Por exemplo:

```text
8 4
```

Troca para:

```text
4 8
```

Por isso o código usa:

```cpp
return a > b;
```

### Caso 4 — os dois são ímpares

Precisamos de ordem decrescente.

Por exemplo:

```text
3 9
```

Troca para:

```text
9 3
```

Por isso o código usa:

```cpp
return a < b;
```

## 📝 Exemplo 1

**Entrada:**

```text
8
5 2 9 8 1 6 3 4
```

Separando mentalmente:

Pares:

```text
2 8 6 4
```

Depois de ordenar os pares de forma crescente:

```text
2 4 6 8
```

Ímpares:

```text
5 9 1 3
```

Depois de ordenar os ímpares de forma decrescente:

```text
9 5 3 1
```

Resultado final:

```text
2 4 6 8 9 5 3 1
```

Esse é exatamente o resultado apresentado no enunciado.

## 📝 Exemplo 2

**Entrada:**

```text
5
7 11 3 1 9
```

Não existe nenhum número par. Então basta ordenar todos os ímpares de forma decrescente:

```text
11 9 7 3 1
```

Saída:

```text
11 9 7 3 1
```



## ⏱️ Complexidade

Como a ordenação continua sendo feita com Bubble Sort, a complexidade da implementação permanece:

```text
O(N²)
```

---

# 5️⃣ Questão 5 — Contagem de inversões com Insertion Sort

## 📌 O que a questão pede?

Uma **inversão** acontece quando existe um par de elementos em que:

```text
i < j
```

e

```text
A[i] > A[j]
```

Ou seja, um número maior aparece antes de um número menor. O enunciado relaciona esse número de inversões aos deslocamentos realizados pelo Insertion Sort.

## 🔍 Exemplo simples

Considere:

```text
2 4 1 3 5
```

Vamos procurar os pares fora de ordem:

- `(2, 1)`
- `(4, 1)`
- `(4, 3)`

Temos 3 inversões.

Portanto:

```text
Quantidade de inversões = 3
```

Esse é o primeiro exemplo do enunciado.

## 💻 Lógica usada no código

O código usa a própria lógica do Insertion Sort para contar os deslocamentos:

```cpp
while (j >= 0 && nums[j] > key) {
    nums[j + 1] = nums[j];
    j--;
    inversoes++;
}
```

Sempre que:

```cpp
nums[j] > key
```

acontece, significa que encontramos um elemento maior que precisa ser deslocado para a direita.

Cada deslocamento corresponde a uma inversão.

Por isso o código faz:

```cpp
inversoes++;
```

## 📝 Exemplo 1

**Entrada:**

```text
5
2 4 1 3 5
```

**Saída:**

```text
3
```

As três inversões são:

```text
(2, 1)
(4, 1)
(4, 3)
```



## 📝 Exemplo 2

**Entrada:**

```text
5
5 4 3 2 1
```

**Saída:**

```text
10
```

Nesse caso, o vetor está completamente invertido.

O número de inversões é:

```text
N(N - 1) / 2
```

Para `N = 5`:

```text
5 × 4 / 2 = 10
```



## ⏱️ Complexidade

A implementação por Insertion Sort possui complexidade de pior caso:

```text
O(N²)
```

---

# 🛠️ Como compilar o projeto

## Opção 1 — Compilando pelo terminal com g++

É possível compilar cada questão separadamente.

### Questão 1

```bash
g++ -std=c++17 questao1.cpp -o questao1
```

Executar:

```bash
./questao1
```

### Questão 2

```bash
g++ -std=c++17 questao2.cpp -o questao2
```

Executar:

```bash
./questao2
```

### Questão 3

```bash
g++ -std=c++17 questao3.cpp -o questao3
```

Executar:

```bash
./questao3
```

### Questão 4

```bash
g++ -std=c++17 questao4.cpp -o questao4
```

Executar:

```bash
./questao4
```

### Questão 5

```bash
g++ -std=c++17 questao5.cpp -o questao5
```

Executar:

```bash
./questao5
```

> No Windows, se estiver usando MinGW pelo terminal, normalmente o executável será gerado como `questao1.exe`, `questao2.exe` etc.

---

# 💻 Como executar no CLion

O projeto também pode ser aberto no **CLion**.

Uma forma simples é deixar cada questão como um executável separado.

Exemplo de estrutura:

```text
questao1.cpp  → executável questao1
questao2.cpp  → executável questao2
questao3.cpp  → executável questao3
questao4.cpp  → executável questao4
questao5.cpp  → executável questao5
```

No CLion:

1. Abra o projeto.
2. Configure o `CMakeLists.txt` para criar um executável para cada arquivo.
3. Selecione a questão desejada na configuração de execução.
4. Clique em **Run**.
5. Digite a entrada no console.
6. Confira a saída.

## Exemplo de `CMakeLists.txt`

Caso os arquivos tenham exatamente os nomes usados neste README, pode ser usado:

```cmake
cmake_minimum_required(VERSION 3.20)
project(EDII_Exercicios)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(questao1 questao1.cpp)
add_executable(questao2 questao2.cpp)
add_executable(questao3 questao3.cpp)
add_executable(questao4 questao4.cpp)
add_executable(questao5 questao5.cpp)
```

Assim, cada questão possui seu próprio `main()` e pode ser executada separadamente.

---

# 🧪 Como testar o projeto

Os testes podem ser feitos usando os exemplos fornecidos pela própria atividade.

## Teste da Questão 1

Entrada:

```text
5
4 3 2 1 5
```

Saída esperada:

```text
1 2 3 4 5
6
```

## Teste da Questão 2

Entrada:

```text
6 3
29 10 14 37 13 42
```

Saída esperada:

```text
10 13 14
```

## Teste da Questão 3

Entrada:

```text
6 2
3 2 1 5 4 6
```

O vetor esperado ao final é:

```text
1 2 3 4 5 6
```

O PDF apresenta `8` comparações para esse caso, mas a implementação deste repositório, com `comparacoes++` dentro do `while`, conta `7`. Essa diferença deve ser conferida antes da entrega.

## Teste da Questão 4

Entrada:

```text
8
5 2 9 8 1 6 3 4
```

Saída esperada:

```text
2 4 6 8 9 5 3 1
```

## Teste da Questão 5

Entrada:

```text
5
2 4 1 3 5
```

Saída esperada:

```text
3
```

---

# ✅ Resumo das soluções

| Questão | Algoritmo | O que o programa calcula |
|---|---|---|
| 1 | Bubble Sort | Vetor ordenado + quantidade de trocas |
| 2 | Selection Sort | Os `k` menores elementos |
| 3 | Insertion Sort | Vetor ordenado + quantidade de comparações |
| 4 | Bubble Sort adaptado | Pares crescentes antes de ímpares decrescentes |
| 5 | Insertion Sort | Quantidade de inversões |

---

# 📌 Detalhamento rápido das ideias

### Questão 1

```text
Compara vizinhos → troca se estiverem fora de ordem → conta a troca
```

### Questão 2

```text
Procura o menor → coloca na posição atual → repete k vezes
```

### Questão 3

```text
Pega um elemento → compara com os anteriores → desloca os maiores → insere no lugar correto
```

### Questão 4

```text
Compara vizinhos usando uma regra personalizada de paridade e ordem
```

### Questão 5

```text
Executa a lógica do Insertion Sort → cada deslocamento representa uma inversão
```

---

# 📖 Observações finais

- As soluções recebem os dados pela entrada padrão (`cin`).
- Os resultados são mostrados pela saída padrão (`cout`).
- Os vetores são armazenados usando `vector<int>`.
- As contagens são armazenadas em `long long` por segurança.
- O projeto utiliza C++ e pode ser compilado com padrão **C++17**.
- Cada questão pode ser compilada e executada de forma independente.

A atividade limita `N` a até `10^4` nas questões apresentadas e define os valores de `k` conforme cada exercício.

---

## 👩‍💻 Autor

Projeto desenvolvido para a disciplina de **Estrutura de Dados II — IFTM Campus Patrocínio**.
