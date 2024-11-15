#include <bits/stdc++.h>
using namespace std;

enum opMode
{
    cooling,
    heating,
    fan_only
};

class SmartDevice {
    protected:
        int deviceID;
        string brandName;
        float powerRating;
    public:
        SmartDevice() {}
        SmartDevice(int d, string b, float f) : deviceID(d), brandName(b), powerRating(f) {}

        virtual void diagnose() = 0;

        float getPowerRating() const { return powerRating; }

        virtual ~SmartDevice() {}
};

class ThermostatDevice : virtual public SmartDevice {
    protected:
        pair<float, float> temperatureRange;
        opMode mode;
    public:
        ThermostatDevice(int d, string b, float f, pair<float, float> t, opMode m) : SmartDevice(d, b, f), temperatureRange(t), mode(m) {}

        virtual double calculatePowerConsumption(double hours) {
            return powerRating * hours;
        }

        virtual void diagnose() override {
            cout << "Device ID: " << deviceID << endl;
            cout << "Brand name: " << brandName << endl;
            cout << "Power rating: " << powerRating << " Watts" << endl;
            cout << "Temperature range: " << temperatureRange.first << " C to " << temperatureRange.second << " C" << endl;
            cout << "Operation mode: ";
            switch (mode) {
                case cooling:
                    cout << "Cooling";
                    break;
                case heating:
                    cout << "Heating";
                    break;
                case fan_only:
                    cout << "Fan Only";
                    break;
            }
            cout << endl;
        }

        virtual ~ThermostatDevice() {}
};

class SecurityCameraDevice : virtual public SmartDevice {
    protected:
        int resolution;
        float recordingHours;
    public:
        SecurityCameraDevice(int d, string b, float p, int r, float rh) : SmartDevice(d, b, p), resolution(r), recordingHours(rh) {}

        virtual double calculateDataUsage(double days) {
            return recordingHours * days;
        }

        virtual void diagnose() override {
            cout << "Device ID: " << deviceID << endl;
            cout << "Brand name: " << brandName << endl;
            cout << "Power rating: " << powerRating << " Watts" << endl;
            cout << "Resolution: " << resolution << " MP" << endl;
            cout << "Recording hours per day: " << recordingHours << " hours" << endl;
        }

        virtual ~SecurityCameraDevice() {}
};

class SmartThermostat : public ThermostatDevice {
    private:
        bool remoteControlEnabled;
    public:
        SmartThermostat(int d, string b, float f, pair<float, float> t, opMode m, bool r) : ThermostatDevice(d, b, f, t, m), remoteControlEnabled(r) {}

        void diagnose() override {
            ThermostatDevice::diagnose();
            cout << "Remote control enabled: " << (remoteControlEnabled? "Yes" : "No") << endl;
        }

        double calculatePowerConsumption(double hours) override {
            if (remoteControlEnabled) {
                return ThermostatDevice::calculatePowerConsumption(hours) * 1.1;
            } else {
                return ThermostatDevice::calculatePowerConsumption(hours);
            }
        }

        ~SmartThermostat() {}
};

class HybridThermostat : public ThermostatDevice, public SecurityCameraDevice {
    private:
        float energySavingEfficiency;
    public:
        HybridThermostat(int d, string b, float f, pair<float, float> t, opMode m, int r, float rh, float e)
            : SmartDevice(d, b, f),
              ThermostatDevice(d, b, f, t, m),
              SecurityCameraDevice(d, b, f, r, rh),
              energySavingEfficiency(e){}

        double calculatePowerConsumption(double hours) override {
            return ThermostatDevice::calculatePowerConsumption(hours) * energySavingEfficiency;
        }

        double calculateDataUsage(double days) {
            return recordingHours * days * energySavingEfficiency;
        }

        void diagnose() override {
            ThermostatDevice::diagnose();
            cout << "Resolution: " << resolution << " MP" << endl;
            cout << "Recording hours per day: " << recordingHours << " hours" << endl;
        }

        ~HybridThermostat() {}
};

void sortDevicesByPower(SmartDevice **devices, int n) {
    sort(devices, devices + n, [](SmartDevice *a, SmartDevice *b)
         { return a->getPowerRating() > b->getPowerRating(); });
}

int main() {
    SmartDevice* devices[4];

    devices[0] = new ThermostatDevice(101, "ThermoMax", 1200.5, {15, 30}, cooling);
    devices[1] = new SecurityCameraDevice(102, "SecureCam", 800.0, 12, 24);
    devices[2] = new ThermostatDevice(103, "HeatControl", 1000.0, {10, 25}, heating);
    devices[3] = new HybridThermostat(104, "HybridThermoSecure", 900.0, {18, 28}, cooling, 8, 12, 0.8);

    sortDevicesByPower(devices, 4);

    cout << "Smart Devices' Information:" << endl;
    cout << endl;
    for (int i = 0; i < 4; i++) {
        devices[i]->diagnose();
        cout << endl;
    }

    cout << "Hybrid Thermostat's information:" << endl;
    cout << endl;
    for (int i = 0; i < 4; ++i) {
        if (HybridThermostat* hybrid = dynamic_cast<HybridThermostat*>(devices[i])) {
            hybrid->diagnose();
            cout << endl;
        }
    }

    for (SmartDevice* device : devices) {
        delete device;
    }

    return 0;
}