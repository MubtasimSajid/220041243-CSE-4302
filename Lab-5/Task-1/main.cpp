#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "products.h"
#define endl '\n'

using namespace std;

typedef long long ll;

bool compareProducts(const Products &p1, const Products &p2)
{
    return p1.getName() < p2.getName();
}

void editInformationByKeyboard(Products &product)
{
    string n, c, d;
    int amount;
    float price, rate;

    cout << "Enter name: ";
    cin >> n;
    cout << "Enter category: ";
    cin >> c;

    product.setName(n);
    product.setCategory(c);

    cout << "Enter description: ";

    char ch;

    while (cin.get(ch))
    {
        if (ch == '.')
            break;
        d.push_back(ch);
    }

    product.setDescription(d);

    cout << "Enter amount in store: ";
    cin >> amount;

    cout << "Enter regular price: ";
    cin >> price;

    cout << "Enter discount rate: ";
    cin >> rate;

    product.setAmountStored(amount);
    product.setRegularPrice(price);
    product.setDiscountRate(rate);

    cout << endl;
}

string randomWord()
{
    int wordLength = 3 + rand() % (7 - 3 + 1);
    string word = "";

    for (int i = 0; i < wordLength; ++i)
    {
        char firstCharacter = 'a';
        if (!i)
            firstCharacter = 'A';
        char randomCharacter = firstCharacter + rand() % 26;
        word.push_back(randomCharacter);
    }

    return word;
}

void generateInformationRandom(Products &product)
{
    string words = "";
    for (int i = 0; i < 3; i++)
        words += randomWord() + " ";
    product.setName(words);

    words = "";
    words += randomWord();
    product.setCategory(words);

    words = "";

    for (int i = 0; i < 10; i++)
        words += randomWord() + " ";
    product.setDescription(words);

    int amountInStore = rand() % 100 + 1;
    product.setAmountStored(amountInStore);

    float regularPrice = rand() % 1000 + 1.0;
    product.setRegularPrice(regularPrice);

    float discountRate = rand() % 10 + 1.0;
    product.setDiscountRate(discountRate);
}

void showAllDiscount(const Products product[], int size)
{
    for (int i = 0; i < size; i++)
        cout << product[i].calculateDiscount(product[i].getAmountStored()) << endl;
    cout << endl;
}

void grossTotal(Products products[], int size)
{
    int itemsToPurchase[size];
    float sum = 0.0f;

    for (int i = 0; i < size; i++)
    {
        itemsToPurchase[i] = rand() % products[i].getAmountStored() + 1;
        sum += products[i].netTotal(itemsToPurchase[i]);
    }

    cout << "Total price: " << sum << endl;
    cout << "Would you like to proceed? [y/n]: " << endl;
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        for (int i = 0; i < size; i++)
            products[i].purchaseProduct(itemsToPurchase[i]);
    }
}

void showAllAlphabetically(Products products[], int size)
{
    sort(products, products + size, compareProducts);

    for (int i = 0; i < size; i++)
        cout << "Name: " << products[i].getName() << ", Current storage: " << products[i].getAmountStored() << endl;
    cout << endl;
}

int main(void)
{
    srand(static_cast<unsigned int>(time(0)));


    Products products[100];

    editInformationByKeyboard(products[0]);
    editInformationByKeyboard(products[1]);

    for (int i = 2; i < 100; i++)
        generateInformationRandom(products[i]);

    showAllDiscount(products, 100);
    grossTotal(products, 100);
    showAllAlphabetically(products, 100);

    return 0;
}