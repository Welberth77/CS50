#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Pergunta quantos centavos ao cliente
    int cents = get_cents();

    // Calcule o número de moedas de 25 centavos
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calcule o número de moedas de 10 centavos
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calcule o número de moedas de 5 centavos
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calcule o número de moedas de 1 centavo
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Soma das moedas
    int coins = quarters + dimes + nickels + pennies;

    // Imprima o número total de moedas para dar ao cliente
    printf("%i\n", coins);
}

int get_cents(void)
{
    // Pedindo e valodando valor do troco
    int n;
    do
    {
        n = get_int("Cents: ");
    }
    while (n < 0);
    return n;
}

int calculate_quarters(int cents)
{
    // Calculando moeda de 25
    int cont = 0;
    do
    {
        cents = cents - 25;
        cont++;
    }
    while (cents >= 25);
    return cont;
}

int calculate_dimes(int cents)
{
    // Calculando moeda de 10
    int cont = 0;
    do
    {
        cents = cents - 10;
        cont++;
    }
    while (cents >= 10);
    return cont;
}

int calculate_nickels(int cents)
{
    // Calculando moeda de 5
    int cont = 0;
    do
    {
        cents = cents - 5;
        cont++;
    }
    while (cents >= 5);
    return cont;
}

int calculate_pennies(int cents)
{
    // Calculando moeda de 1
    int cont = 0;
    do
    {
        cents = cents - 1;
        cont++;
    }
    while (cents >= 1);
    return cont;
}
