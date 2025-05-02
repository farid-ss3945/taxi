#include <iostream>
#include <fstream>
#include <string>

class Expedition {
public:
    virtual ~Expedition() = default;
    virtual void printInfo() const = 0;
    virtual std::string getType() const = 0;
};

class NorthPoleExpedition : public Expedition {
    std::string name;
    int year;
    double temperature;
public:
    NorthPoleExpedition(const std::string& name, int year, double temperature)
        : name(name), year(year), temperature(temperature) {}

    void printInfo() const override {
        std::cout << "North Pole Expedition: " << name << ", " << year << ", " << temperature << "°C\n";
    }

    std::string getType() const override {
        return "North";
    }

    const std::string& getName() const { return name; }
    int getYear() const { return year; }
    double getTemperature() const { return temperature; }
};

class SouthPoleExpedition : public Expedition {
    std::string name;
    int year;
    double distance;
public:
    SouthPoleExpedition(const std::string& name, int year, double distance)
        : name(name), year(year), distance(distance) {}

    void printInfo() const override {
        std::cout << "South Pole Expedition: " << name << ", " << year << ", " << distance << " km\n";
    }

    std::string getType() const override {
        return "South";
    }

    const std::string& getName() const { return name; }
    int getYear() const { return year; }
    double getDistance() const { return distance; }
};

void readExpeditions(const std::string& filename, Expedition** expeditions, int maxSize, int& actualCount) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Failed to open the input file!\n";
        return;
    }

    std::string line;
    actualCount = 0;

    while (std::getline(inFile, line) && actualCount < maxSize) {
        auto delimiterPos = line.find(';');
        std::string type = line.substr(0, delimiterPos);
        line.erase(0, delimiterPos + 1);

        delimiterPos = line.find(';');
        std::string name = line.substr(0, delimiterPos);
        line.erase(0, delimiterPos + 1);

        delimiterPos = line.find(';');
        int year = std::stoi(line.substr(0, delimiterPos));
        line.erase(0, delimiterPos + 1);

        double value = std::stod(line);

        if (type == "North") {
            expeditions[actualCount++] = new NorthPoleExpedition(name, year, value);
        } else if (type == "South") {
            expeditions[actualCount++] = new SouthPoleExpedition(name, year, value);
        }
    }
    inFile.close();
}

void writeExpeditions(const std::string& filename, Expedition** expeditions, int count) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Failed to open the output file!\n";
        return;
    }

    for (int i = 0; i < count; ++i) {
        if (expeditions[i]->getType() == "North") {
            auto* northExp = static_cast<NorthPoleExpedition*>(expeditions[i]);
            outFile << "North;" << northExp->getName() << ";" << northExp->getYear() << ";" << northExp->getTemperature() << "\n";
        } else if (expeditions[i]->getType() == "South") {
            auto* southExp = static_cast<SouthPoleExpedition*>(expeditions[i]);
            outFile << "South;" << southExp->getName() << ";" << southExp->getYear() << ";" << southExp->getDistance() << "\n";
        }
    }
    outFile.close();
}

void freeExpeditions(Expedition** expeditions, int count) {
    for (int i = 0; i < count; ++i) {
        delete expeditions[i];
    }
}

int main() {
    const int maxSize = 100;  
    Expedition* expeditions[maxSize];
    int actualCount = 100;

    readExpeditions("expeditions_out.txt", expeditions, maxSize, actualCount);
    if (actualCount == 0) {
        std::cerr << "No expeditions found in the file!\n";
        return 1;
    }

    for (int i = 0; i < actualCount; ++i) {
        expeditions[i]->printInfo();
    }

    writeExpeditions("expeditions_out.txt", expeditions, actualCount);
    freeExpeditions(expeditions, actualCount);

    std::cout << "Expedition data successfully written to expeditions_out.txt!\n";
    return 0;
}