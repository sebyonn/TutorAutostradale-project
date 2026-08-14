//file creato da Francesco Barban

#include "../include/randomFunc.h"
#include <random>
#include <algorithm>
#include <iostream>
#include <cmath>

std::string random_plate_generator()
{
    //stringhe da cui verranno scelti caratteri casuali
    const std::string l = "ABCDEFGHJKLMNPQRSTVWXYZ"; //I, O, Q, U mancano nelle targhe italiane per evitare confusione
    const std::string n = "1234567890";
    const std::string letters = l + l + l + l;  //così che le lettere compaiano tante volte quante le loro posizioni possibili, per permettere "doppioni"
    const std::string numbers = n + n + n;  //come per letters
    static std::random_device rd;
    static std::mt19937 generator(rd());

    std::string random_letters(letters);
    std::shuffle(random_letters.begin(), random_letters.end(), generator); //mescola tutti i caratteri di letters in una nuova stringa random_letters

    std::string random_numbers(numbers);
    std::shuffle(random_numbers.begin(), random_numbers.end(), generator);

    std::string s1 = random_letters.substr(0, 2); //prima parte "AA" della stringa
    std::string s2 = random_numbers.substr(0, 3); //seconda parte "111" della stringa
    std::string s3 = random_letters.substr(2, 2); //terza parte "BB" della stringa, inizia da 2 perché altrimenti sarebbe uguale a s1

    std::string plate = s1 + s2 + s3;
    return plate;
}

int random_int(const int left, const int right)
{
    static std::random_device rd;  //static serve a non creare device nuovi ogni volta che viene chiamata la funzione, si userà sempre quello creato alla prima chiamata
    static std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distr(left, right);

    return distr(generator);
}

double random_double(const double left, const double right)
{
    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_real_distribution<double> distr(left, right);

    double rand = std::floor(distr(generator)*10)/10; //tronca alla prima cifra decimale il risultato
    return rand;
}