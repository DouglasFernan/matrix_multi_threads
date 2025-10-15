#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <sstream>
#include <string>

using namespace std;

// para representar uma matriz
typedef vector<vector<int>> Matrix;

// Função que calcula uma linha da matriz resultado (será usada por cada thread)
void multiply_row(const Matrix &A, const Matrix &B, Matrix &result, int row)
{
    int colsB = B[0].size();
    int colsA = A[0].size();
    for (int j = 0; j < colsB; ++j)
    {
        int sum = 0;
        // Calcula o produto escalar para a posição [row][j] do resultado
        for (int k = 0; k < colsA; ++k)
        {
            sum += A[row][k] * B[k][j];
        }
        result[row][j] = sum;
    }
}

// Função que lê uma matriz a partir de um arquivo
Matrix read_matrix(ifstream &fin)
{
    string line;
    int L = 0, C = 0;

    // Encontra e lê o número de linhas (L=)
    while (getline(fin, line))
    {
        if (line.rfind("L=", 0) == 0)
        {
            L = stoi(line.substr(2));
            break;
        }
    }
    // Encontra e lê o número de colunas (C=)
    while (getline(fin, line))
    {
        if (line.rfind("C=", 0) == 0)
        {
            C = stoi(line.substr(2));
            break;
        }
    }

    // Cria a matriz com o tamanho lido
    Matrix mat(L, vector<int>(C));
    // Lê os valores numéricos de cada linha
    for (int i = 0; i < L; ++i)
    {
        getline(fin, line);
        stringstream ss(line);
        for (int j = 0; j < C; ++j)
        {
            ss >> mat[i][j];
        }
    }
    return mat;
}

int main()
{
    string filename;
    cout << "Enter input filename: ";
    cin >> filename;

    // Abre o arquivo para leitura
    ifstream fin(filename);
    // Verifica se o arquivo abriu corretamente
    if (!fin)
    {
        cerr << "Could not open file.\n";
        return 1;
    }

    // Lê as matrizes A e B do arquivo
    Matrix A = read_matrix(fin);
    Matrix B = read_matrix(fin);

    int rowsA = A.size(), colsA = A[0].size();
    int rowsB = B.size(), colsB = B[0].size();

    // Verifica se a multiplicação é possível
    if (colsA != rowsB)
    {
        cerr << "Matrix dimensions do not match for multiplication.\n";
        return 1;
    }

    // Cria a matriz de resultado, preenchida com zeros
    Matrix result(rowsA, vector<int>(colsB, 0));
    // Cria um vetor para guardar as threads
    vector<thread> threads;

    // Cria uma thread para calcular cada linha da matriz resultado
    for (int i = 0; i < rowsA; ++i)
    {
        threads.emplace_back(multiply_row, cref(A), cref(B), ref(result), i);
    }

    // Espera todas as threads finalizarem
    for (auto &t : threads)
    {
        t.join();
    }

    // Imprime o resultado final
    for (const auto &row : result)
    {
        for (size_t j = 0; j < row.size(); ++j)
        {
            cout << row[j];
            if (j + 1 < row.size())
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}