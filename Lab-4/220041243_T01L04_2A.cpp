#include<iostream>
#define endl '\n'
using namespace std;

typedef long long ll;

class Inventory
{
    private:
        string name;
        int ID;
        int quantity;
        static int totalQuantity;
        float price;
        static float totalPrice;
        int maxAmount;

    public:
        Inventory(string productName, int id, float value, int noOfProducts, int max)
        {
            name = productName;
            ID = id;
            price = value;
            quantity = noOfProducts;
            totalQuantity += quantity;
            totalPrice += price * quantity;
            maxAmount = max;
        }

        Inventory()
        {
            name = "";
            ID = 0;
            quantity = 0;
            price = 0;
            maxAmount = 0;
        }

        ~Inventory()
        {
            
        }

        bool isAvailable()
        {
            return quantity > 0;
        }

        void addToInventory(int addedQuantity)
        {
            if ((quantity + addedQuantity) < maxAmount)
            {
                quantity += addedQuantity;
                totalQuantity += addedQuantity;
                totalPrice += addedQuantity * price;
            }
            else
                cout << "Adding quantity failed. Maximum capacity for the product has been reached." << endl;
        }

        void purchase(int purchasedQuantity)
        {
            if (purchasedQuantity <= quantity)
            {
                quantity -= purchasedQuantity;
                totalQuantity -= purchasedQuantity;
                totalPrice -= purchasedQuantity * price;
                cout << "Purchase successful!" << endl;
            }
            else
                cout << "Purchase failed. Only " << quantity << " available." << endl;
        }

        void updatePrice(float discountPercent)
        {
            totalPrice -= (quantity * price);
            price -= (price * discountPercent / 100);
            totalPrice += (quantity * price);

            cout << "Discount applied!" << endl;
        }

        void displayInventoryValue()
        {
            cout << "The total value of the product available in the inventory is: " << price * quantity << endl;
        }

        void displayDetails()
        {
            cout << "Product name: " << name << endl;
            cout << "Product ID: " << ID << endl;
            cout << "Quantity available: " << quantity << endl;
            cout << "Price per unit: " << price << endl;
            cout << "Availability status: ";
            if (isAvailable())
                cout << "Available." << endl;
            else
                cout << "Unavailable." << endl;
        }

        static void displayTotalInventoryValue()
        {
            cout << "Total inventory value is: " << totalPrice << endl;
        }
};

int Inventory::totalQuantity = 0;
float Inventory::totalPrice = 0;

int main(void)
{
    Inventory products[3];

    products[0] = Inventory("Laptop", 1, 100, 95, 10000);
    products[0].addToInventory(5);
    products[0].purchase(10001);
    products[0].purchase(100);
    products[0].updatePrice(5);

    products[0].displayInventoryValue();
    products[0].displayDetails();

    products[1] = Inventory("Mobile", 2, 600, 5, 5000);
    products[2] = Inventory("Watch", 3, 700, 5, 501);

    Inventory::displayTotalInventoryValue();

    return 0;
}