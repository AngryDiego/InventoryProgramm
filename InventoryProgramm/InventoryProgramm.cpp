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
    
    // !!! ДОПИСАТИ СЕТТЕР ДЛЯ ВАГИ

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


    // зробити метод для використання предмету який було зазначено (itemName)

    // метод для того щоб викинути ОДИН предмет  (itemName)
};

struct Player {
    Inventory inventory;
};


int main() {
    Player player1;

}
