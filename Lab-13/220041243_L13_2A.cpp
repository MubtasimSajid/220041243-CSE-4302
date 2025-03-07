#include <bits/stdc++.h>
using namespace std;

class Creature {
    private:
        string name;
        string species;
        int id;
    public:
        Creature(const string &name, const string &species, const int &id) {
            this->name = name;
            this->species = species;
            this->id = id;
        }

        string getName() const {
            return name;
        }

        string getSpecies() const {
            return species;
        }

        int getId() const {
            return id;
        }

        virtual void displayDetails() const {
            cout << "Name: " << name << endl;
            cout << "Species: " << species << endl;
            cout << "ID: " << id << endl;
        }
};

class ActiveCreature : public Creature {
    private:
        string healthStatus;
        set<string> dailyActivities;
    public:
        ActiveCreature(const string &name, const string &species, const int &id, const string &healthStatus) : Creature(name, species, id) {
            this->healthStatus = healthStatus;
        }

        string getHealthStatus() const {
            return healthStatus;
        }

        set<string> getDailyActivities() const {
            return dailyActivities;
        }

        void displayDetails() const override {
            Creature::displayDetails();
            cout << "Health Status: " << healthStatus << endl;
            cout << "Daily Activities: ";
            for (const auto &activity : dailyActivities) {
                cout << activity << " ";
            }
            cout << endl;
        }

        void setHealthStatus(const string &healthStatus) {
            this->healthStatus = healthStatus;
        }

        void addActivities(const string &activities) {
            dailyActivities.insert(activities);
        }

        void removeActivities(const string &activities) {
            dailyActivities.erase(activities);
        }
};

class RecoveringCreature : public Creature {
    private:
        set<string> recoveryStatus;
    public:
        RecoveringCreature(const string &name, const string &species, const int &id) : Creature(name, species, id) {}

        set<string> getRecoveryStatus() const {
            return recoveryStatus;
        }

        void displayDetails() const override {
            Creature::displayDetails();
            cout << "Recovery Status: ";
            for (const auto &status : recoveryStatus) {
                cout << status << " ";
            }
            cout << endl;
        }

        void addRecoveryStatus(const string &status) {
            recoveryStatus.insert(status);
        }

        void removeRecoveryStatus(const string &status) {
            recoveryStatus.erase(status);
        }
};

map<int, ActiveCreature*> activeCreatureMap;
map<int, RecoveringCreature*> recoveringCreaturesMap;

void addCreature(const string &name, const string &species, const int &id, const string &healthStatus) {
    ActiveCreature* activeCreature = new ActiveCreature(name, species, id, healthStatus);
    activeCreatureMap.insert({id, activeCreature});
}

void sendToRecovery(const int &id) {
    if (activeCreatureMap.find(id) == activeCreatureMap.end()) {
        cout << "Creature not found in active creatures." << endl;
        return;
    } else if (recoveringCreaturesMap.find(id) != recoveringCreaturesMap.end()) {
        cout << "Creature already in recovery." << endl;
        return;
    }
    ActiveCreature* activeCreature = activeCreatureMap[id];
    if (activeCreature->getHealthStatus() != "Healthy") {
        RecoveringCreature* recoveringCreature = new RecoveringCreature(activeCreature->getName(), activeCreature->getSpecies(), id);
        recoveringCreature->addRecoveryStatus("Initial Recovery");
        recoveringCreaturesMap.insert({id, recoveringCreature});
        activeCreatureMap.erase(id);
        delete activeCreature;
    }
}

void saveData() {
    ofstream activeFile("active_creatures.txt");
    ofstream recoveryFile("recovery_creatures.txt");

    for (const auto &pair : activeCreatureMap) {
        ActiveCreature* creature = pair.second;
        activeFile << creature->getId() << " " << creature->getName() << " " << creature->getSpecies() << " " << creature->getHealthStatus() << endl;
        for (const auto &activity : creature->getDailyActivities()) {
            activeFile << activity << " ";
        }
        activeFile << endl;
    }

    for (const auto &pair : recoveringCreaturesMap) {
        RecoveringCreature* creature = pair.second;
        recoveryFile << creature->getId() << " " << creature->getName() << " " << creature->getSpecies() << endl;
        for (const auto &status : creature->getRecoveryStatus()) {
            recoveryFile << status << " ";
        }
        recoveryFile << endl;
    }

    activeFile.close();
    recoveryFile.close();
}

void loadData() {
    ifstream activeFile("active_creatures.txt");
    ifstream recoveryFile("recovery_creatures.txt");

    if (!activeFile || !recoveryFile) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    activeCreatureMap.clear();
    recoveringCreaturesMap.clear();

    int id;
    string name, species, healthStatus, line;

    while (activeFile >> id >> name >> species >> healthStatus) {
        ActiveCreature* creature = new ActiveCreature(name, species, id, healthStatus);
        getline(activeFile, line);
        istringstream iss(line);
        string activity;
        while (iss >> activity) {
            creature->addActivities(activity);
        }
        activeCreatureMap.insert({id, creature});
    }

    while (recoveryFile >> id >> name >> species) {
        RecoveringCreature* creature = new RecoveringCreature(name, species, id);
        getline(recoveryFile, line);
        istringstream iss(line);
        string status;
        while (iss >> status) {
            creature->addRecoveryStatus(status);
        }
        recoveringCreaturesMap.insert({id, creature});
    }

    activeFile.close();
    recoveryFile.close();
}

int main(void) {
    addCreature("Dragon", "Fire", 1, "Unhealthy");
    addCreature("Phoenix", "Fire", 2, "Healthy");

    activeCreatureMap[1]->displayDetails();
    activeCreatureMap[2]->displayDetails();

    sendToRecovery(1);

    if (recoveringCreaturesMap.find(1) != recoveringCreaturesMap.end()) {
        recoveringCreaturesMap[1]->displayDetails();
    }

    saveData();
    loadData();

    cout << "After loading data:" << endl;
    for (const auto &pair : activeCreatureMap) {
        pair.second->displayDetails();
    }

    for (const auto &pair : recoveringCreaturesMap) {
        pair.second->displayDetails();
    }

    return 0;
}