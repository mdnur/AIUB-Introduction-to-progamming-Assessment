#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
protected:
    float mileage;
    float price;

public:
    void setMileageAndPrice(/*float mileage, float price*/)
    {
        cout << "Enter mileage :";
        cin >> this->mileage;
        cout << "Enter Car price:";
        cin >> this->price;

        // this->mileage = mileage;
        // this->price = price;
    }
    virtual void display() = 0;
};

class Car : public Vehicle
{
protected:
    float ownershipCost;
    int warranty;
    int capacity;
    string fuelType;

public:
    void setCarData()
    {
        cout << "Enter ownershipCost :";
        cin >> this->ownershipCost;
        cout << "Enter Car warranty:";
        cin >> this->warranty;
        cout << "Enter Car capacity:";
        cin >> this->capacity;
        cout << "Enter Car fuelType only(air or liquid or oil) :";
        cin >> this->fuelType;

        // this->mileage = mileage;
        // this->price = price;
    }
};

class Bike : public Vehicle
{
protected:
    int numberOfCylinder;
    int numberOfGears;
    string coolingType;
    string wheelType;
    float fuelTankSize;

public:
    void setBikeData()
    {
        cout << "Enter numberOfCylinder :";
        cin >> this->numberOfCylinder;
        cout << "Enter Bike numberOfGears:";
        cin >> this->numberOfGears;
        cout << "Enter Bike coolingType:";
        cin >> this->coolingType;
        cout << "Enter Bike wheelType only((alloys or spokes) :";
        cin >> this->wheelType;
        cout << "Enter Bike fuelTankSize  :";
        cin >> this->fuelTankSize;

        // this->mileage = mileage;
        // this->price = price;
    }
};

class Audi : public Car
{
protected:
    int modelType;

public:
    void setModelType()
    {
        cout << "Enter Car Model Type :";
        cin >> this->modelType;
    }
    void display()
    {
        cout << "Audi mileage :" << this->mileage<< endl;;
        cout << "Audi price :" << this->price;
        cout << "Audi ownership cost :" << this->ownershipCost<< endl;;
        cout << "Audi warranty :" << this->warranty<< endl;;
        cout << "Audi Seating Capacity cost :" << this->capacity<< endl;;
        cout << "Audi fuel type :" << this->fuelType<< endl;;
        cout << "Audi model Type:" << this->modelType<< endl;;
    }
};

class Ford : public Car
{
protected:
    int modelType;

public:
    void setModelType()
    {
        cout << "Enter Car Model Type :";
        cin >> this->modelType;
    }
    void display()
    {
        cout << "Ford mileage :" << this->mileage<< endl;;
        cout << "Ford price :" << this->price;
        cout << "Ford ownership cost :" << this->ownershipCost<< endl;;
        cout << "Ford warranty :" << this->warranty<< endl;;
        cout << "Ford Seating Capacity cost :" << this->capacity<< endl;;
        cout << "Ford fuel type :" << this->fuelType<< endl;;
        cout << "Ford model Type:" << this->modelType<< endl;;
    }
};

class Bajaj : public Bike
{
protected:
    string makeType;

public:
    void setMakeType()
    {
        cout << "Enter Bike Make Type :";
        cin >> this->makeType;
    }
    // int numberOfCylinder;
    // int numberOfGears;
    // string coolingType;
    // string wheelType;
    // float fuelTankSize;
    void display()
    {
        cout << "Bajaj mileage :" << this->mileage << endl;;
        cout << "Bajaj price :" << this->price<< endl;;
        cout << "Bajaj number Of Cylinder :" << this->numberOfCylinder<< endl;;
        cout << "Bajaj number Of Gears :" << this->numberOfGears<< endl;;
        cout << "Bajaj co0ling Type :" << this->coolingType<< endl;;
        cout << "Bajaj wheel type :" << this->wheelType<< endl;;
        cout << "Bajaj fuel Tank Size:" << this->fuelTankSize<< endl;;
    }
};

class TVS : public Bike
{
protected:
    string makeType;

public:
    void setMakeType()
    {
        cout << "Enter Bike Make Type :";
        cin >> this->makeType;
    }
    void display()
    {
        cout << "TVS mileage :" << this->mileage<< endl;;
        cout << "TVS price :" << this->price<< endl;;
        cout << "TVS number Of Cylinder :" << this->numberOfCylinder<< endl;;
        cout << "TVS number Of Gears :" << this->numberOfGears<< endl;;
        cout << "TVS co0ling Type :" << this->coolingType<< endl;;
        cout << "TVS wheel type :" << this->wheelType<< endl;;
        cout << "TVS fuel Tank Size:" << this->fuelTankSize<< endl;;
    }
};
void clearIgnore()
{
    cin.clear();
    cin.ignore();
}

int main()
{

    int choice;
    int ch;

    cout << "Enter '1' for Audi and '2' for Two for Ford  and '3' for Two for Bajaj and '4' for Two for TVS  Account: ";
    cin >> ch;

    if (ch == 1)
    {
        Audi audi;
        audi.setMileageAndPrice();
        audi.setCarData();
        audi.setModelType();
        audi.display();
    }
    if (ch == 2)
    {
        Ford ford;
        ford.setMileageAndPrice();
        ford.setCarData();
        ford.setModelType();
        ford.display();
    }
    if (ch == 3)
    {
        Bajaj bajaj;
        bajaj.setMileageAndPrice();
        bajaj.setBikeData();
        bajaj.setMakeType();
        bajaj.display();
    }
    if (ch == 4)
    {
        TVS tvs;
        tvs.setMileageAndPrice();
        tvs.setBikeData();
        tvs.setMakeType();
        tvs.display();
    }

    return 0;
}