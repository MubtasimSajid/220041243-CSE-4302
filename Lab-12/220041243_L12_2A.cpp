#include <bits/stdc++.h>
using namespace std;

class Creature {
    private:
        string name;
        string species;
        string healthStatus;
        int age;

    public:
        Creature(const string &name, const string &species, const string &healthStatus, const int &age) 
            : name(name), species(species), healthStatus(healthStatus), age(age) {}

        string getName() const {
            return name;
        }

        string getSpecies() const {
            return species;
        }

        string getHealthStatus() const {
            return healthStatus;
        }

        int getAge() const {
            return age;
        }

        void setHealthStatus(const string &hs) {
            healthStatus = hs;
        }

        void display() const {
            cout << "Name: " << name << endl;
            cout << "Species: " << species << endl;
            cout << "Health Status: " << healthStatus << endl;
            cout << "Age: " << age << endl;
        }
};

class Sanctuary {
    private:
        vector<Creature> inhabitants;
        deque<Creature> recoveryZone;
        list<Creature> releasedCreatures;
    
    public:
        void addCreature() {
            string name, species, healthStatus;
            int age;

            cout << "Enter creature name: ";
            cin >> name;
            cout << "Enter creature species: ";
            cin >> species;
            cout << "Enter creature health status: ";
            cin >> healthStatus;
            cout << "Enter creature age: ";
            cin >> age;

            inhabitants.push_back(Creature(name, species, healthStatus, age));

            return;
        }

        void sendCreatureToRecovery(const string &name) {
            for (auto &c : inhabitants) {
                if (c.getName() == name) {
                    if (c.getHealthStatus() == "Healthy") {
                        cout << "Creature is already healthy" << endl;
                        return;
                    }
                    recoveryZone.push_back(c);
                    inhabitants.erase(find(inhabitants.begin(), inhabitants.end(), c));
                    return;
                }
            }
        }

        void returnFromRecovery(const string &name) {
            for (auto &c : recoveryZone) {
                if (c.getName() == name) {
                    inhabitants.push_back(c);
                    c.setHealthStatus("Healthy");
                    recoveryZone.erase(find(recoveryZone.begin(), recoveryZone.end(), c));
                    return;
                }
            }
            cout << "Creature not found in the recovery zone" << endl;
            return;
        }

        void releaseCreature(const string &name) {
            for (auto &c : inhabitants) {
                if (c.getName() == name) {
                    if (c.getHealthStatus() == "Healthy") {
                        releasedCreatures.push_back(c);
                        recoveryZone.erase(find(recoveryZone.begin(), recoveryZone.end(), c));
                        return;
                    } else {
                        cout << "Creature must be healthy to be released" << endl;
                        return;
                    }
                }
            }
            cout << "Creature not found in the inhabitants" << endl;
            return;
        }

        void displayCreatures() const {
            cout << "Inhabitants: " << endl;
            for (const auto &c : inhabitants) {
                c.display();
                cout << endl;
            }

            cout << endl;
            cout << "Recovery Zone: " << endl;
            for (const auto &c : recoveryZone) {
                c.display();
                cout << endl;
            }

            cout << endl;
            cout << "Released Creatures: " << endl;
            for (const auto &c : releasedCreatures) {
                c.display();
                cout << endl;
            }
        }

        void saveData() const {
            ofstream outFile("inhabitants.txt");
            if (!outFile) {
                cerr << "Error opening the file for writing: inhabitants.txt" << endl;
                return;
            }

            for (const auto &c : inhabitants) {
                outFile << c.getName() << c.getSpecies() << c.getHealthStatus() << c.getAge() << endl;
            }

            outFile.open("recovery.txt");
            if (!outFile) {
                cerr << "Error opening the file for writing: recovery.txt" << endl;
                return;
            }

            for (const auto &c : recoveryZone) {
                outFile << c.getName() << c.getSpecies() << c.getHealthStatus() << c.getAge() << endl;
            }

            outFile.open("released.txt");
            if (!outFile) {
                cerr << "Error opening the file for writing: released.txt" << endl;
                return;
            }

            for (const auto &c : releasedCreatures) {
                outFile << c.getName() << c.getSpecies() << c.getHealthStatus() << c.getAge() << endl;
            }

            outFile.close();

            return;
        }

        void loadData() {
            int size, age;
            string name, species, healthStatus;
            releasedCreatures.clear();

            ifstream inFile("inhabitants.txt");
            if (!inFile) {
                cerr << "Error opening file for reading: inhabitants.txt" << endl;
                return;
            }

            inhabitants.clear();

            cout << "How many creatures in the sanctuary?" << endl;
            cin >> size;
            for (int i = 0; i < size; ++i) {
                inFile >> name >> species >> healthStatus >> age;
                inhabitants.push_back(Creature(name, species, healthStatus, age));
            }

            ifstream inFile("recovery.txt");
            if (!inFile) {
                cerr << "Error opening file for reading: recovery.txt" << endl;
                return;
            }

            recoveryZone.clear();

            cout << endl << "How many creatures have recovered? " << endl;
            cin >> size;
            for (int i = 0; i < size; ++i) {
                inFile >> name >> species >> healthStatus >> age;
                recoveryZone.push_back(Creature(name, species, healthStatus, age));
            }

            ifstream inFile("released.txt");
            if (!inFile) {
                cerr << "Error opening file for reading: released.txt" << endl;
                return;
            }

            releasedCreatures.clear();

            cout << endl << "How many creatures have been released? " << endl;
            cin >> size;
            for (int i = 0; i < size; ++i) {
                inFile >> name >> species >> healthStatus >> age;
                releasedCreatures.push_back(Creature(name, species, healthStatus, age));
            }

            inFile.close();
        }
};

int main(void) {
    

    return 0;
}