#include "products.h"

string Products::getName() const
{
    return name;
}

void Products::setName(string n)
{
    name = n;
    return;
}

string Products::getCategory() const
{
    return category;
}

void Products::setCategory(string c)
{
    category = c;
    return;
}

string Products::getDescription() const
{
    return description;
}

void Products::setDescription(string d)
{
    description = d;
    return;
}

int Products::getAmountStored() const
{
    return amountStored;
}

void Products::setAmountStored(int a)
{
    amountStored = a;
    return;
}

float Products::getRegularPrice() const
{
    return regularPrice;
}

void Products::setRegularPrice(float price)
{
    regularPrice = price;
    return;
}

float Products::getDiscountRate() const
{
    return discountRate;
}

void Products::setDiscountRate(float rate)
{
    discountRate = rate;
    return;
}

void Products::purchaseProduct(int amount)
{
    if (amount > amountStored)
        return;
    amountStored -= amount;
}

void Products::restockProduct(int amount)
{
    amountStored += amount;
}

double Products::calculateDiscount(int amountOfProducts) const
{
    if (amountOfProducts < 5)
        return 0.0;

    double price = amountOfProducts * 1.0 * regularPrice;
    double discount = price * discountRate / 100.0;

    if (amountOfProducts >= 10)
        discount += (price * 3.0 / 100.0);

    return discount;
}

double Products::netTotal(int amountOfProducts) const
{
    double cost = amountOfProducts * 1.0 * regularPrice;
    cost  -= calculateDiscount(amountOfProducts);

    return cost;
}