#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

class SellerActions {
    public:
        virtual void serveIceCream() = 0;
        virtual void promoteDeal() = 0;
        virtual void specialOffer() = 0;
        virtual void displayStats() = 0;
        virtual ~SellerActions() {}
};

class BaseSeller : public SellerActions {
    protected:
        string name;
        int stock;
        int sales;
        bool specialOfferReady;
        int turnSales;

    public:
        BaseSeller(string name, int stock)
            : name(name), stock(stock), sales(0), specialOfferReady(false), turnSales(0) {}

        void serveIceCream() override {
            if (stock > 0) {
                int salesPoints = rand() % 23 + 8;
                sales += salesPoints;
                stock--;
                turnSales++;
                cout << name << " served! Sales increased by " << salesPoints
                    << ". Total Sales: " << sales << ", Stock: " << stock << endl;
            } else {
                cout << name << " is out of stock!" << endl;
            }
        }

        void promoteDeal() override {
            if (turnSales > 0) {
                int bonus = turnSales * 10; 
                sales += bonus;
                cout << name << " promoted a deal, earning " << bonus << " bonus sales!" << endl;
            } else {
                cout << name << " couldn't promote a deal this turn." << endl;
            }
        }

        virtual void specialOffer() override = 0;

        void displayStats() override {}

        int getSales() const { return sales; }
        int getStock() const { return stock; }
        void resetTurnSales() { turnSales = 0; }
};

class ConeMaster : public BaseSeller {
    public:
        ConeMaster(int stock) : BaseSeller("Cone Master", stock) {}

        void specialOffer() override {
            if (specialOfferReady) {
                int bonus = 0;
                for (int i = 0; i < 3 && stock > 0; ++i) {
                    int salesPoints = rand() % 23 + 8;
                    bonus += salesPoints;
                    sales += salesPoints;
                    stock--;
                }
                cout << name << " served a specialOffer! Sales increased by " << bonus
                    << ". Total Sales: " << sales << ", Stock: " << stock << endl;
                specialOfferReady = false;
            } else {
                cout << name << "'s special offer is not ready!" << endl;
            }
        }
};

class SundaeWizard : public BaseSeller {
    public:
        SundaeWizard(int stock) : BaseSeller("Sundae Wizard", stock) {}

        void LayeredSundaeBonus(int layers) {
            int bonusSales = layers * 8; 
            sales += bonusSales;
            stock -= layers;
            cout << name << " served LayeredSundaeBonus! Sales increased by " << bonusSales
                << ". Total Sales: " << sales << ", Stock: " << stock << endl;
        }

        void specialOffer() override {
            if (specialOfferReady) {
                sales *= 2;
                cout << name << " served a specialOffer! Sales increased by " << sales
                    << ". Total Sales: " << sales << ", Stock: " << stock << endl;
                specialOfferReady = false;
            } else {
                cout << name << "'s special offer is not ready!" << endl;
            }
        }
};

class IceCreamTruckDriver : public BaseSeller {
    public:
        IceCreamTruckDriver(int stock) : BaseSeller("Ice Cream Truck Driver", stock) {}

        void specialOffer() override {
            if (specialOfferReady) {
                stock += 10;
                cout << name << " served a specialOffer! Stock increased to " << stock << endl;
                specialOfferReady = false;
            } else {
                cout << name << "'s special offer is not ready!" << endl;
            }
        }
};

class CustomerRush {
    private:
        int patience;

    public:
        CustomerRush(int patience) : patience(patience) {}

        void reducePatience() {
            int loss = rand() % 31 + 20;
            patience -= loss;
            cout << "Customer patience decreased by " << loss << ". Remaining: " << patience << endl;
        }

        int getPatience() const { return patience; }
};

class SimulationEngine {
    private:
        vector<BaseSeller *> sellers;
        CustomerRush *customerRush;
        int salesGoal;
        int maxTurns;
        int currentTurn;
        int collectiveSales;

    public:
        SimulationEngine(vector<BaseSeller *> sellers, CustomerRush *customerRush, int salesGoal, int maxTurns)
            : sellers(sellers), customerRush(customerRush), salesGoal(salesGoal), maxTurns(maxTurns),
            currentTurn(0), collectiveSales(0) {}

        void playTurn() {
            cout << "\nTurn " << currentTurn + 1 << ":" << endl;
            for (auto seller : sellers) {
                seller->serveIceCream();
                collectiveSales += seller->getSales();
                cout << "Collective totalSales: " << collectiveSales << endl;
                seller->resetTurnSales();
            }
            customerRush->reducePatience();
            currentTurn++;
        }

        bool checkGameOver() {
            if (collectiveSales >= salesGoal) { 
                cout << "Customer Rush satisfied! Sellers win!" << endl;
                return true;
            }
            if (customerRush->getPatience() <= 0) {
                cout << "Game over! Customer patience ran out." << endl;
                return true;
            }
            if (currentTurn >= maxTurns) {
                cout << "Game over! Maximum turns reached." << endl;
                return true;
            }
            return false;
        }

        void run() {
            cout << "Game begins! Sellers vs. Customer Rush" << endl;
            while (!checkGameOver()) {
                playTurn();
            }
        }
};

int main(void) {
    srand(static_cast<unsigned>(time(0)));

    vector<BaseSeller *> sellers = {
        new ConeMaster(20),
        new SundaeWizard(20),
        new IceCreamTruckDriver(30)};

    int patience = rand() % 501;

    CustomerRush customerRush(patience);
    SimulationEngine simulation(sellers, &customerRush, 300, patience);
    simulation.run();

    for (auto &seller : sellers) {
        delete seller;
    }

    return 0;
}
