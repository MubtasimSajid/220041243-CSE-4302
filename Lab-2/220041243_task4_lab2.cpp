#include<bits/stdc++.h>
#define endl '\n'
#define result cout << answer << endl
using namespace std;

typedef long long ll;

enum typesOfFuel
{
    Petrol,
    Diesel,
    Electric,
    Hybrid
};

typedef struct carInformation
{
    string brandName;
    string model;
    int makingYear;
    typesOfFuel fuelType;
    int mileage;
    float costOfFuel;
} carInfo;

bool fuelEfficient (carInfo car)
{
    return (car.mileage >= 15);
}

float fuelConsumption (carInfo car)
{
    return 100.0 / car.mileage;
}

float fuelCost (carInfo car)
{
    float answer = fuelConsumption(car);

    if (car.fuelType == Petrol)
        answer *= 0.89;
    else if (car.fuelType == Diesel)
        answer *= 3.24;
    else if (car.fuelType == Hybrid)
        answer *= 2.45;
    else if (car.fuelType == Electric)
        answer = 0;

    return answer;
}

void displayCarInformation (carInformation *cars, int carNo)
{
    for (int i = 0; i < carNo; i++)
    {
        cout << "Car " << i + 1 << ":" << endl;
        cout << "Brand: " << cars[i].brandName << endl;
        cout << "Model: " << cars[i].model << endl;
        cout << "Year: " << cars[i].makingYear << endl;
        cout << "Fuel Type: ";
        switch (cars[i].fuelType)
        {
            case Petrol:
                cout << "Petrol" << endl;
                break;
            case Diesel:
                cout << "Diesel" << endl;
                break;
            case Electric:
                cout << "Electric" << endl;
                break;
            case Hybrid:
                cout << "Hybrid" << endl;
                break;
        }
        cout << "Mileage: " << cars[i].mileage << " km/l" << endl;

        if (cars[i].fuelType == Electric)
            cout << "This car is electric, efficiency is measured in km/charge." << endl;

        if (fuelEfficient(cars[i]))
            cout << "This car is fuel-efficient." << endl;
        else
            cout << "This car is not fuel-efficient." << endl;

        if (cars[i].fuelType != Electric)
            cout << "Estimated fuel cost for 100 km: $" << cars[i].costOfFuel << endl;

        cout << endl;
    }

    cin.get();
}

int main(void)
{
    int carNo;

    cout << "Please enter the number of cars (at least 3): ";
    cin >> carNo;
    cout << endl;

    if (carNo < 3)
    {
        cout << "At least 3 cars are required." << endl;
        cout << "Press any key to terminate the program." << endl;
        cin.get();
        return 0;
    }

    carInfo cars[carNo];
    string fuel;

    for (int i = 0; i < carNo; i++)
    {
        cout << "Input no.: " << i + 1 << endl;

        cout << "Enter the car's brand: ";
        cin >> cars[i].brandName;

        cout << "Enter the car's model: ";

        char ch;
        int enter = 0;
        while (cin.get(ch))
        {
            if (ch == '\n') 
            {
                enter++;
                if (enter >= 2)
                    break;
            }
            if (ch != ' ') 
            {
                cars[i].model += ch;
            }
        }

        cout << "Enter the year that car was made: ";
        cin >> cars[i].makingYear;

        cout << "Enter the type of fuel the car consumes: ";
        cin >> fuel;

        if (fuel == "Petrol")
            cars[i].fuelType = Petrol;
        else if (fuel == "Diesel")
            cars[i].fuelType = Diesel;
        else if (fuel == "Electric")
            cars[i].fuelType = Electric;
        else if (fuel == "Hybrid")
            cars[i].fuelType = Hybrid;
        else
        {
            cout << "Invalid fuel type. Press any key to exit the program." << endl;
            cin.get();
            return 0;
        }

        cout << "Enter the car's mileage in km/l (press 0 if the car is electric): ";
        cin >> cars[i].mileage;

        cars[i].costOfFuel = fuelCost(cars[i]);

        cout << endl;
    }

    cout << "Here are the details of the cars:" << endl
         << endl;

    displayCarInformation(cars, carNo);

    cin.get();

    return 0;
}