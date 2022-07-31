#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <algorithm>

void add_word(std::vector <char>& letras,char letra)
{
    letras.push_back(letra);
}
void change_incognito(std::vector <char>& incognita,char letra, std::string palabra,int& vidas)
{
    bool changed;
    for (int i = 0; i < incognita.size(); i++)
    {
        if (palabra[i]==letra)
        {
            incognita[i]=letra;
            changed=true;
        }
    }
    if (!changed)
    {
        vidas++;
    }  
}
void show_incognito(std::vector <char>& incognita)
{
    for (int i = 0; i < incognita.size(); i++)
    {
        std::cout<<incognita[i]<<" ";
    }
    std::cout<<"\n";
}
void sort_letras_usadas(std::vector <char>& letras_usadas)
{
    char temp;
    for (int i = 0; i < letras_usadas.size(); i++)
    {
        for (int j = i+1; j < letras_usadas.size(); j++)
        {
            if (letras_usadas[i]>letras_usadas[j])
            {
                temp=letras_usadas[i];
                letras_usadas[i]=letras_usadas[j];
                letras_usadas[j]=temp;
            }
        }
    }
}
void show_letras_usadas(std::vector <char>& letras_usadas)
{
    sort_letras_usadas(letras_usadas);
    for (int i = 0; i < letras_usadas.size(); i++)
    {
        std::cout<<letras_usadas[i]<<" ";
    }
    std::cout<<"\n";
}
void prepare_vector(std::vector <char>& incognita, std::string palabra)
{
    for (int i = 0; i < palabra.length(); i++)
    {
        if (palabra[i]==' ')
        {
            incognita.push_back(' ');
        }
        else
        {
            incognita.push_back('_');
        }
    }
}
void show_lifes(int& vidas)
{
    char aux=92;
    switch (vidas)
    {
    case 0:
        std::cout<<"____"<<std::endl;
        std::cout<<"|   |"<<std::endl;
        std::cout<<"|"<<std::endl;
        std::cout<<"|"<<std::endl;
        std::cout<<"|"<<std::endl;
        std::cout<<"|"<<std::endl;
        break;
    case 1:
        std::cout<<"____"<<std::endl;
        std::cout<<"|   |"<<std::endl;
        std::cout<<"|   o"<<std::endl;
        std::cout<<"|"<<std::endl;
        std::cout<<"|"<<std::endl;
        std::cout<<"|"<<std::endl;
        break;
    case 2:
        std::cout<<"____"<<std::endl;
        std::cout<<"|   |"<<std::endl;
        std::cout<<"|   o"<<std::endl;
        std::cout<<"|   |"<<std::endl;
        std::cout<<"|"<<std::endl;
        std::cout<<"|"<<std::endl;
        break;
    case 3:
        std::cout<<"____"<<std::endl;
        std::cout<<"|   |"<<std::endl;
        std::cout<<"|   o"<<std::endl;
        std::cout<<"|  /|"<<aux<<std::endl;
        std::cout<<"|"<<std::endl;
        std::cout<<"|"<<std::endl;
        break;
    case 4:
        std::cout<<"____"<<std::endl;
        std::cout<<"|   |"<<std::endl;
        std::cout<<"|   o"<<std::endl;
        std::cout<<"|  /|"<<aux<<std::endl;
        std::cout<<"|   /"<<std::endl;
        std::cout<<"|"<<std::endl;
        break;
    case 5:
        std::cout<<"____"<<std::endl;
        std::cout<<"|   |"<<std::endl;
        std::cout<<"|   o"<<std::endl;
        std::cout<<"|  /|"<<aux<<std::endl;
        std::cout<<"|   /"<<aux<<std::endl;
        std::cout<<"|"<<std::endl;
        break;
    default:
        break;
    }
}
void show_word(std::string& palabra)
{
    for (auto &&i : palabra)
    {
        std::cout<<i;
    }
    std::cout<<"\n";
}
bool word_is_guessed(std::vector <char>& incognita)
{
    char key = '_';
    if (std::find(incognita.begin(),incognita.end(),key) != incognita.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool been_used(std::vector <char>& letras_usadas, char& letra)
{
    for (auto &&i : letras_usadas)
    {
        if (i==letra)
        {
            return true;
        }
    }
    return false;
}

int main(){
    srand(time(0));
    std::string Palabras[10]= {"autos","perros","animales","codigo","comida","brownie","pastel","alemania","valorant","diddy kong"},palabra_adivinar;
    std::vector <char> letras_usadas;
    std::vector <char> palabra_incognita;
    char letra,opcion;
    bool running=true;
    int random= rand()%10,errores=0;
    std::cout<<"Quieres escoger la palabra? (y/n)"<<std::endl;
    std::cin>>opcion;
    if (opcion=='y')
    {
        std::cout<<"Cual va a ser la palabra?\n";
        std::getline(std::cin>>std::ws,palabra_adivinar);
    }
    else
    {
        palabra_adivinar=Palabras[random];
    }
    prepare_vector(palabra_incognita,palabra_adivinar);
    std::cout<<"La palabra a adivinar es: "<<"\n";
    show_incognito(palabra_incognita);
    while (running)
    {
        show_lifes(errores);
        std::cout<<"Ingresa una letra: ";
        std::cin>>letra;
        system("cls");
        if (isalpha(letra))
        {
            if (!been_used(letras_usadas,letra))
            {
                add_word(letras_usadas,letra); 
                change_incognito(palabra_incognita,letra,palabra_adivinar,errores);
                show_incognito(palabra_incognita);
                if (word_is_guessed(palabra_incognita))
                {
                    std::cout<<"Has ganado!"<<std::endl;
                    std::cout<<"Las letras que usaste fueron: ";
                    show_letras_usadas(letras_usadas);
                    break;
                }                
            }
            else
            {
                std::cout<<"Ya usaste esa letra"<<std::endl;
            }
        }
        else
        {
            std::cout<<"No escribiste una letra"<<std::endl;
        }
        std::cout<<"Has usado estas letras: ";
        show_letras_usadas(letras_usadas);
        if (errores==5)
        {
            show_lifes(errores);
            std::cout<<"La palabra era: ";
            show_word(palabra_adivinar); 
            running=false;
        }
    }

    

    system("pause");
    return 0;
}