// структура повʼязана з інвентар 

#include <iostream>
#include <vector>

using namespace std;

// vector
// vector<int> = {1,2,3}   

// масив[size]= {1, 2, 3}

struct Item {
private:
    string name;
    int quantity;
    double weight;

    // Геттери та Сеттери
public:
    void setName(string newName) {
        name = newName;
    }
    string getName() {
        return name;
    }
    //---------------------------------------get Quant
    int getQuant() {
        return quantity;
    }
    //---------------------------------------get Weight
    int getWeight() {
        return weight;
    }

    //---------------------------------------get info
    void getInfo() {
        cout << name << " Count: " << quantity << " Weight: " << weight*quantity << endl;
    }
};

struct Inventory {
    //Item items[10];
    vector<Item> items;
    int itemCount;

    double TotalInventoryWeight() {
        double total = 0;
        for (auto& item : items) {
            total += item.getWeight() * item.getQuant();
        }
        return total;
    }

    void PrintInventory() {
        cout << "Player`s inventory be like: " << endl;
        for (auto& item : items) {
            item.getInfo();
        }
    }

    void AddItem() {
        for (auto& item : items) {
            if (items.empty()) {
                items.push_back(item.getName()); //типу я хочу щоб ось весь цей цикл перевіряв інвентар. Та коли знаходив пусте місце, туди пхав айтем
                break;
            }
        }
    }

    void RemoveItem(int slot) {
        for (int index = slot; index = index + 1; index++) {
            if (items.empty()) {
                break;
            }
            else {
                items.push_back("");
            }
        }
    }
};

struct Player {
    Inventory inventory;
};


int main() {
    Player player1;

}