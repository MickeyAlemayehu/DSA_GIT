#include <iostream>
using namespace std;

const int DefaultListSize = 100;

class AList {
private:
    int maxSize;
    int listSize;
    int curr;
    int* listArray;

public:
    AList(int size = DefaultListSize) {
        maxSize = size;
        listSize = curr = 0;
        listArray = new int[maxSize];
    }

    ~AList() {
        delete[] listArray;
    }


    void add(int value) {
        if (listSize == maxSize) {
            cout << "List is full. Cannot add more elements.\n";
            return;
        }
        listArray[listSize++] = value;
    }

    void clear() {
        delete[] listArray;
        listSize = curr = 0;
        listArray = new int[maxSize];
    }

    void setStart() {
        curr = 0;
    }

    void setEnd() {
        curr = listSize;
    }

    void prev() {
        if (curr != 0) curr--;
    }

    void next() {
        if (curr < listSize) curr++;
    }

    int length() const {
        return listSize;
    }

    bool setPos(int pos) {
        if (pos >= 0 && pos <= listSize) {
            curr = pos;
            return true;
        }
        cout << "Invalid position.\n";
        return false;
    }

    int getValue() const {
        if (listSize == 0) {
            cout << "List is empty.\n";
            return -1;
        }
        return listArray[curr];
    }

    int display(int index) const {
        if (index >= 0 && index < listSize)
            return listArray[index];
        else {
            cout << "Index out of bounds.\n";
            return -1;
        }
    }

    bool insert(int item) {
        if (listSize == maxSize) {
            cout << "Failed: list is full\n";
            return false;
        }
        for (int i = listSize; i > curr; i--) {
            listArray[i] = listArray[i - 1];
                listArray[curr] = item;
        listSize++;
        cout << "Successfully inserted\n";
        return true;
    }
    }

    bool append(int item) {
        if (listSize == maxSize) {
            cout << "Failed: list is full\n";
            return false;
        }
        listArray[listSize++] = item;
        cout << "Successfully appended\n";
        return true;
    }

    bool remove() {
        if (listSize == 0) {
            cout << "Failed: list is empty\n";
            return false;
        }
        for (int i = curr; i < listSize - 1; i++) {
            listArray[i] = listArray[i + 1];
        }
        listSize--;
        cout << "Successfully removed\n";
        return true;
    }
};

void displayMenu() {
    cout << "\nList Operations Menu:\n";
    cout << "1. Append an element\n";
    cout << "2. Remove the element at current position\n";
    cout << "3. Display all elements\n";
    cout << "4. Get the value at current position\n";
    cout << "5. Insert an element at current position\n";
    cout << "6. Insert an element at the beginning\n";
    cout << "7. Insert an element at the end\n";
    cout << "8. Move to next\n";
    cout << "9. Move to previous\n";
    cout << "10. Set position\n";
    cout << "11. Clear the list\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    AList list;
    int choice, item, position;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to append: ";
                cin >> item;
                list.append(item);
                break;

            case 2:
                if (!list.remove()) 
                cout << "Remove operation failed.\n";
                break;

            case 3:
                cout << "List elements: ";
                for (int i = 0; i < list.length(); i++) {
                    cout << list.display(i) << " ";
                }
                cout << endl;
                break;

            case 4:
                cout << "Current value: " << list.getValue() << endl;
                break;

            case 5:
                cout << "Enter element to insert at current position: ";
                cin >> item;
                list.insert(item);
                break;

            case 6:
                list.setStart();
                cout << "Enter element to insert at the beginning: ";
                cin >> item;
                list.insert(item);
                break;

            case 7:
                list.setEnd();
                cout << "Enter element to insert at the end: ";
                cin >> item;
                list.insert(item);
                break;

            case 8:
                list.next();
                cout << "Moved to next.\n";
                break;

            case 9:
                list.prev();
                cout << "Moved to previous.\n";
                break;

            case 10:
                cout << "Enter position: ";
                cin >> position;
                if (!list.setPos(position)) cout << "Invalid position.\n";
                break;

            case 11:
                list.clear();
                cout << "List cleared.\n";
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
