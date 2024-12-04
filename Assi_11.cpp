#include<iostream>
using namespace std;
class Employee{
	
	int EmpID;
	string Name;
	int contact;
	
	public:
	int index;
	Employee(){
		EmpID = -1;
		Name = "";
		contact = -1;
		index = -1;
	}
	void setID(int id){EmpID = id;}
	void setName(int n){Name = n;}
	void setContact(int c){contact = c;}
	void setIndex(int i){ index = i;}
	
	int getID(){ return EmpID;}
	void setEmployee(int EmpID,string N,int contact,int index){
		this->EmpID = EmpID;
		Name = N;
		this->contact = contact;
		this->index = index;
	}
	void printEmployee(){
		cout<<"Details: "<<EmpID<<" - "<<Name<<" - "<<contact<<endl;
	}
	
};
class HashTable{
	int tableSize;
	Employee *ht;
	public:
	HashTable(int size){
		tableSize = size;
		ht = new Employee[tableSize];
	}
	int hash(int value){
		return(value%tableSize);
	}
	void insertIntoHT(int EmpID,string N,int contact){
		int ToBeInsertedAt = hash(EmpID);
		if(ht[ToBeInsertedAt].index == -1){ //position is empty, can insert here
			ht[ToBeInsertedAt].setEmployee(EmpID,N,contact,ToBeInsertedAt);
		}
		else{
			for(int i=0;i<tableSize;i++){
				ToBeInsertedAt = (ToBeInsertedAt+1)%tableSize;
			
				if(ht[ToBeInsertedAt].index == -1){ 
				ht[ToBeInsertedAt].setEmployee(EmpID,N,contact,ToBeInsertedAt);
					return;
				}
			}
			cout<<"HashTable is full"<<endl;
		}
	}
	void searchInHT(int EmpID){
		int ToBeInsertedAt = hash(EmpID);
		if(ht[ToBeInsertedAt].getID() == EmpID){ //data found
			ht[ToBeInsertedAt].printEmployee();
		}
		else{
			for(int i=0;i<tableSize;i++){
				ToBeInsertedAt = (ToBeInsertedAt+1)%tableSize;
			
				if(ht[ToBeInsertedAt].getID() == EmpID){ 
					ht[ToBeInsertedAt].printEmployee();	
					return;
				}
			}
			cout<<EmpID<<"details not found"<<endl;
		}
	}
	void displayHT(){
		for(int i=0;i<tableSize;i++)
			ht[i].printEmployee();
	}
	
};

int main() {
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;
    
    HashTable ht(size);
    int choice;
    
    do {
        cout << "1. Insert\n 2. Search\n 3. Display\n 4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int key, someInt;
                string value;
                cout << "Enter key (int): ";
                cin >> key;
                cout << "Enter value (string): ";
                cin >> value;
                cout << "Enter some integer: ";
                cin >> someInt;
                ht.insertIntoHT(key, value, someInt);
                break;
            }
            case 2: {
                int key;
                cout << "Enter key to search: ";
                cin >> key;
                ht.searchInHT(key);
                break;
            }
            case 3:
                ht.displayHT();
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}