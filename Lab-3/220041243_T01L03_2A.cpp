#include<iostream>
#define endl '\n'
using namespace std;

typedef long long ll;

class Temperature
{
    private:
        float currentTemperature;
        float incrementValue;

    public:
        Temperature()
        {
            currentTemperature = 0;
            incrementValue = 1;
        }

        void setIncrementStep(float value)
        {
            incrementValue = value;
        }

        float getTemperature()
        {
            return currentTemperature;
        }

        float getIncrementValue()
        {
            return incrementValue;
        }

        void increment()
        {
            currentTemperature += incrementValue;
        }

        void resetTemperature()
        {
            currentTemperature = 0;
        }
};

int main(void)
{
    Temperature t1;

    cout << "Default temperature: " << t1.getTemperature() << endl
         << "Default increment step: " << t1.getIncrementValue() << endl
         << endl;

    t1.setIncrementStep(10);
    cout << "Current increment step: " << t1.getIncrementValue() << endl
         << endl;

    t1.increment();
    t1.increment();

    cout << "Temperature after 2 increment operations: " << t1.getTemperature() << endl
         << endl;

    t1.resetTemperature();

    cout << "Temperature after resetting: " << t1.getTemperature() << endl;

    return 0;
}