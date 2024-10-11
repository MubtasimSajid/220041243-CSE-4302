#ifndef PRODUCTS_H
#define PRODUCTS_H

#include<bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define result cout << answer << endl
#define all(entity) entity.begin(), entity.end()
#define forRange(i, n) for (ll i = 0; i < n; i++)
using namespace std;

typedef long long ll;

class Products
{
    private:
        string name;
        string category;
        string description;
        int amountStored;
        float regularPrice;
        float discountRate;
    public:
        Products()
        {
            name = "";
            category = "";
            description = "";
            amountStored = 0;
            regularPrice = 0.0;
            discountRate = 0.0;
        }

        string getName() const;
        void setName(string n);
        string getCategory() const;
        void setCategory(string c);
        string getDescription() const;
        void setDescription(string d);
        int getAmountStored() const;
        void setAmountStored(int a);
        float getRegularPrice() const;
        void setRegularPrice(float price);
        float getDiscountRate() const;
        void setDiscountRate(float rate);

        void purchaseProduct(int amount);
        void restockProduct(int amount);

        double calculateDiscount(int amountOfProducts) const;
        double netTotal(int amountOfProducts) const;
};

#endif