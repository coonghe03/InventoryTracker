#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Item {
private:
    int id;
    string name;
    int quantity;
public:
    Item(int _id, string _name, int _quantity) {
        id = _id;
        name = _name;
        quantity = _quantity;
    }

    int getId() const { return id; }
    string getName() const { return name; }
    int getQuantity() const { return quantity; }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};

class Inventory {
private:
    vector<Item> items;
public:
    void addItem(int id, string name, int quantity) {
        items.push_back(Item(id, name, quantity));
        cout << "Item added successfully!\n";
    }

    void viewItems() {
        if (items.empty()) {
            cout << "Inventory is empty.\n";
            return;
        }
        for (const auto& item : items) {
            item.display();
        }
    }

    void searchItem(string keyword) {
        bool found = false;
        for (const auto& item : items) {
            if (item.getName().find(keyword) != string::npos) {
                item.display();
                found = true;
            }
        }
        if (!found) cout << "Item not found.\n";
    }

    void deleteItem(int id) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getId() == id) {
                items.erase(it);
                cout << "Item deleted.\n";
                return;
            }
        }
        cout << "Item with given ID not found.\n";
    }
};

int main() {
    Inventory inventory;
    int choice;

    while (true) {
        cout << "\n--- Inventory Tracker ---\n";
        cout << "1. Add Item\n2. View Items\n3. Search Item\n4. Delete Item\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, quantity;
            string name;
            cout << "Enter ID: "; cin >> id;
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Quantity: "; cin >> quantity;
            inventory.addItem(id, name, quantity);
        } else if (choice == 2) {
            inventory.viewItems();
        } else if (choice == 3) {
            string keyword;
            cout << "Enter keyword to search: ";
            cin >> keyword;
            inventory.searchItem(keyword);
        } else if (choice == 4) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            inventory.deleteItem(id);
        } else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
