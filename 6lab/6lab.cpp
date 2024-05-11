

#include <iostream>
#include <vector>

using namespace std;

class Building {
public:
    virtual void print() const = 0;
};

class ResidentialBuilding : public Building {
public:
    virtual void print() const override = 0;
};

class CommercialBuilding : public Building {
public:
    virtual void print() const override = 0;
};

class House : public ResidentialBuilding {
public:
    void print() const override {
        cout << "Жилой дом (9-20 этажей)" << endl;
    }
};

class Cottage : public ResidentialBuilding {
public:
    void print() const override {
        cout << "Жилой коттедж (1-2 этажа)" << endl;
    }
};

class Office : public CommercialBuilding {
public:
    void print() const override {
        cout << "Офисное здание (12-20 этажей)" << endl;
    }
};

class School : public CommercialBuilding {
public:
    void print() const override {
        cout << "Школа (1-4 этажа)" << endl;
    }
};

class AbstractFactory {
public:
    virtual ResidentialBuilding* createResidentialBuilding() const = 0;
    virtual CommercialBuilding* createCommercialBuilding() const = 0;
};

class HighRiseFactory : public AbstractFactory {
public:
    ResidentialBuilding* createResidentialBuilding() const override {
        return new House();
    }
    CommercialBuilding* createCommercialBuilding() const override {
        return new Office();
    }
};

class LowRiseFactory : public AbstractFactory {
public:
    ResidentialBuilding* createResidentialBuilding() const override {
        return new Cottage();
    }
    CommercialBuilding* createCommercialBuilding() const override {
        return new School();
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    AbstractFactory* highRiseFactory = new HighRiseFactory();
    ResidentialBuilding* house = highRiseFactory->createResidentialBuilding();
    CommercialBuilding* office = highRiseFactory->createCommercialBuilding();
    house->print();
    office->print();

    AbstractFactory* lowRiseFactory = new LowRiseFactory();
    ResidentialBuilding* cottage = lowRiseFactory->createResidentialBuilding();
    CommercialBuilding* school = lowRiseFactory->createCommercialBuilding();
    cottage->print();
    school->print();

    return 0;
}
