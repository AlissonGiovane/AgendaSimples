// Incluindo arquivos de cabeçalho
#include<iostream>   // Entrada/saída padrão em C++
#include<conio.h>    // Para a função getch()
#include<fstream>    // Para manipulação de arquivos
using namespace std;

// Variáveis globais
string nome, sobrenome, numero_telefone;

// Funções
void adicionarContato();
void pesquisarContato();
void ajuda();
void sair();
bool verificar_digitos(string);
bool verificar_numeros(string);

int main()
{
    short int escolha;
    system("cls");  // Limpa a tela do console
    system("color 0A");  // Define a cor do texto e fundo no console
    cout << "\n\n\n\t\t\tGerenciamento de Contatos.";
    cout << "\n\n\t1. Adicionar Contato\n\t2. Pesquisar Contato\n\t3. Ajuda\n\t4. Sair\n\t> ";
    cin >> escolha;

    switch (escolha)
    {
        case 1:
            adicionarContato();
            break;
        case 2:
            pesquisarContato();
            break;
        case 3:
            ajuda();
            break;
        case 4:
            sair();
            break;
        default:
            cout << "\n\n\tEntrada Inválida!";
            cout << "\n\tPressione Qualquer Tecla Para Continuar...";
            getch();
            main();
    }
    return 0;
}

void sair()
{
    system("cls");
    cout << "\n\n\n\t\tObrigado Por Usar!";
    exit(1);  // Encerra o programa
}

void ajuda()
{
    cout << "Isso exibe ajuda";
}

void adicionarContato()
{
    ofstream telefone("numero.txt", ios::app);  // Abre o arquivo em modo de adição
    system("cls");
    cout << "\n\n\tDigite o Primeiro Nome : ";
    cin >> nome;
    cout << "\n\tDigite o Sobrenome : ";
    cin >> sobrenome;
    cout << "\n\tDigite o Número de Telefone com 11 Digitos : ";
    cin >> numero_telefone;

    if (verificar_digitos(numero_telefone) == true)
    {
        if (verificar_numeros(numero_telefone) == true)
        {
            if (telefone.is_open())
            {
                telefone << nome << " " << sobrenome << " " << numero_telefone << endl;
                cout << "\n\tContato Salvo com Sucesso!";
            }
            else
            {
                cout << "\n\tErro ao Abrir o Arquivo!";
            }
        }
        else
        {
            cout << "\n\tUm Número de Telefone Deve Conter Apenas Números!";
        }
    }
    else
    {
        cout << "\n\tUm Número de Telefone Deve Ter 11 Dígitos.";
    }
    telefone.close();  // Fecha o arquivo
}

void pesquisarContato()
{
    bool encontrado = false;
    ifstream meuArquivo("numero.txt");  // Abre o arquivo em modo de leitura
    string palavra_chave;
    cout << "\n\tDigite o Nome para Pesquisar : ";
    cin >> palavra_chave;
    while (meuArquivo >> nome >> sobrenome >> numero_telefone)
    {
        if (palavra_chave == nome || palavra_chave == sobrenome)
        {
            system("cls");
            cout << "\n\n\n\t\tDetalhes do Contato..";
            cout << "\n\n\tPrimeiro Nome : " << nome;
            cout << "\n\tSobrenome : " << sobrenome;
            cout << "\n\tNúmero de Telefone : " << numero_telefone;
            encontrado = true;
            break;
        }
    }
    if (encontrado == false)
        cout << "\n\tNenhum Contato Encontrado";
}

bool verificar_digitos(string x)
{
    if (x.length() == 11)
        return true;
    else
        return false;
}

bool verificar_numeros(string x)
{
    bool verificar = true;

    for (int i = 0; i < x.length(); i++)
    {
        if (!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            verificar = false;
            break;
        }
    }

    if (verificar == true)
        return true;
    if (verificar == false)
        return false;
}
