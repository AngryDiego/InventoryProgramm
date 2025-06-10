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
    void setQuanity(int newQuantity){
        if(newQuantity > 0 && newQuantity <= 64){
            quantity = newQuantity;
        }
    }
    //---------------------------------------get Weight
    int getWeight() {
        return weight;
    }
   //----------------------------------------set Weight 
    void setWeight(double newWeight) {
        if (newWeight > 0) {
            weight = newWeight;
        }
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

    void AddItem(Item newItem) {
        for (auto& item : items) {
           if(item.getName() == newItem.getName()){
            item.setQuanity(item.getQuant() + newItem.getQuant());
           }
           return;
        }
        items.push_back(newItem);

    }

    void RemoveItem(string itemName) {
        for(int i = 0; i < items.size(); i++){
            if(items[i].getName() == itemName){
                items.erase(items.begin() + i);                             // літерали 
                cout << itemName << " has been deleted" << endl;
                return;
            }
        }
    }

    void UseItem(string itemName) {
        for (auto& item : items) {
            if (item.getName() == itemName) {
                cout << item.getName() <<" has been taken in leading hand" << endl;
                return;
            }
        }
        cout << "Item with this name has been not found" << endl;
    }

    void DropItem(string itemName) {
        for (auto& item : items) {
            if (item.getName() == itemName) {
                if (item.getQuant() > 1) {
                    item.setQuanity(item.getQuant() - 1);
                    cout << "one " << itemName << " has been thrown away" << endl;
                    return;
                }
                else {
                    RemoveItem(item.getName());
                    cout << itemName << " has been deleted" << endl;
                    return;
                }
            }
        }
    }
};

struct Player {
    Inventory inventory;//
};


int main() {
    Player player1;
    Item Halberd;

    Halberd.setQuanity(1);
    Halberd.setWeight(4.5);

    player1.inventory.AddItem(Halberd);

}
