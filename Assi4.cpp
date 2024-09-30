#include <iostream>
using namespace std;

class textEditor {
    string text;
    textEditor* next;
    textEditor* prev;
public:
    textEditor() {
        text = "NULL";
        next = NULL;
        prev = NULL;
    }
    textEditor(string s) {
        text = s;
        next = NULL;
        prev = NULL;
    }
    friend class textBuffer;
};

class textBuffer {
    textEditor* head;
public:
    textBuffer() {
        head = NULL;
    }
    void insert_text(string s);
    void delete_text(string s);
    void display_text();
    void search_text(string s);
    void print_reverse();
};

void textBuffer::insert_text(string s) {
    cout << endl;
    textEditor* t = new textEditor(s);
    if (head == NULL) {
        head = t;
        return;
    } else {
        textEditor* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = t;
        t->prev = temp;
    }
}

void textBuffer::delete_text(string s) {
    if (head == NULL) {
        cout << "Text Not Exist!";
        return;
    }

    textEditor* temp = head;
    if (temp->text == s) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp->next != NULL) {
        if (temp->next->text == s) {
            textEditor* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            if (temp->next != NULL)
                temp->next->prev = temp;
            delete nodeToDelete;
            return;
        }
        temp = temp->next;
    }
}

void textBuffer::search_text(string s) {
    cout << endl;
    textEditor* temp = head;
    if (head == NULL) {
        cout << "Text Not Found!" << endl;
        return;
    }
    while (temp != NULL) {
        if (temp->text == s) {
            cout << "Text Found" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Text Not Found!" << endl;
}

void textBuffer::display_text() {
    cout << endl;
    textEditor* temp = head;
    if (head == NULL) {
        return;
    }
    while (temp != NULL) {
        cout << temp->text << " ";
        temp = temp->next;
    }
    cout << endl;
}

void textBuffer::print_reverse() {
    cout << endl;
    textEditor* temp = head;
    if (head == NULL) {
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        cout << temp->text << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() 
{
    textBuffer t;
    string str;
    int choice;
    char ch;
    do 
    {
        cout << endl;
        cout << "1.Insert Text\n2.Delete Text\n3.Display Text\n4.Search Text\n5.Print Text In Reverse Order\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
        {
            case 1:
                cout << endl << "Enter Text: ";
                cin >> str;
                t.insert_text(str);
                break;

            case 2:
                cout << endl << "Enter Text: ";
                cin >> str;
                t.delete_text(str);
                break;

            case 3:
                t.display_text();
                break;

            case 4:
                cout << endl << "Enter Text: ";
                cin >> str;
                t.search_text(str);
                break;

            case 5:
                t.print_reverse();
                break;
            default:
                return 0;
        }
        cout << "\nEnter Y to continue: ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    return 0;
}