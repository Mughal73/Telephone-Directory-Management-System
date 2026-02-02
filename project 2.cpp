#include<iostream>
#include<string>
using namespace std;
class TelephoneDirectory
{
	private:
		string ids[100];
	    string names[100];
    	string addresses[100];
    	string phones[100];
    	int count;
	public:
		TelephoneDirectory()
		{
			count = 0;
		}
		void insertStudent()
		{
			cout << "Enter ID: ";
        	cin >> ids[count];
        	cout << "Enter Name: ";
        	cin.ignore();
        	getline(cin, names[count]);
        	cout << "Enter Address: ";
        	getline(cin, addresses[count]);
        	cout << "Enter Phone Number: ";
        	cin >> phones[count];
        	for (int i = 0; i < count; i++)
			{
            	if (ids[i] == ids[count])
				{
                	cout << "ID already exists, cannot insert." << endl;
                	return;
            	}
        	}
        	count++;
        	cout << "Record saved successfully." << endl;
		}
		void updateStudent()
		{
			string id;
        	cout << "Enter ID or Name: ";
        	cin >> id;
        	for (int i = 0; i < count; i++)
			{
            	if (ids[i] == id || names[i] == id)
				{
                	cout << "Current Information: " << endl;
                	cout << "ID: " << ids[i] << ", Name: " << names[i] << ", Address: " << addresses[i] << ", Phone: " << phones[i] << endl;
        	        char choice;
            	    cout << "Do you want to update? [y/n]: ";
                	cin >> choice;
            	    if (choice == 'y')
					{
                    	cout << "Enter New ID: ";
                    	cin >> ids[i];
                    	cout << "Enter New Name: ";
                    	cin.ignore();
                    	getline(cin, names[i]);
                    	cout << "Enter New Address: ";
                    	getline(cin, addresses[i]);
                    	cout << "Enter New Phone Number: ";
                    	cin >> phones[i];
                    	cout << "Record updated successfully." << endl;
                	}
                	return;
            	}
        	}
        	cout << "Record not found." << endl;
		}
		void deleteStudent()
		{
        	string id;
        	cout << "Enter ID: ";
        	cin >> id;
        	for (int i = 0; i < count; i++)
        	{
            	if (ids[i] == id)
				{
                	cout << "Current Information: " << endl;
                	cout << "ID: " << ids[i] << ", Name: " << names[i] << ", Address: " << addresses[i] << ", Phone: " << phones[i] << endl;
                	char choice;
                	cout << "Do you want to delete this record? [y/n]: ";
                	cin >> choice;
                	if (choice == 'y') {
                    	for (int j = i; j < count - 1; j++)
						{
                        	ids[j] = ids[j + 1];
                        	names[j] = names[j + 1];
                        	addresses[j] = addresses[j + 1];
                        	phones[j] = phones[j + 1];
                    	}
                    	count--;
                    	cout << "Record deleted successfully." << endl;
                	}
            	    return;
            	}
        	}
        	cout << "Record not found." << endl;
    	}
		void searchStudent()
		{
			string id;
			cout << "Enter ID or Name: ";
        	cin >> id;
        	for (int i = 0; i < count; i++)
			{
            	if (ids[i] == id || names[i] == id)
				{
                	cout << "Record Found: " << endl;
                	cout << "ID: " << ids[i] << ", Name: " << names[i] << ", Address: " << addresses[i] << ", Phone: " << phones[i] << endl;
                	return;
            	}
        	}
        	cout << "Record not found." << endl;
    	}
    	void listDirectory()
		{
        	cout << "Showing All Members: " << endl;
        	for (int i = 0; i < count; i++)
			{
            	cout << "ID: " << ids[i] << ", Name: " << names[i] << ", Address: " << addresses[i] << ", Phone: " << phones[i] << endl;
        	}
        	cout << "Total " << count << " records shown successfully." << endl;
    	}
};

int main() {
    TelephoneDirectory directory;
    int option = 0;

    cout << "*************************************" << endl;
    cout << "Telephone Directory: Main Menu" << endl;
    cout << "*************************************" << endl;

    while (option != 6) {
        cout << "1. Insert a new student" << endl;
        cout << "2. Update an existing student" << endl;
        cout << "3. Delete a record" << endl;
        cout << "4. Search for a student" << endl;
        cout << "5. List directory" << endl;
        cout << "6. Exit" << endl;
        cout << "Select Option [1-6]: ";
        cin >> option;

        if (option == 1) {
            directory.insertStudent();
        } else if (option == 2) {
            directory.updateStudent();
        } else if (option == 3) {
            directory.deleteStudent();
        } else if (option == 4) {
            directory.searchStudent();
        } else if (option == 5) {
            directory.listDirectory();
        } else if (option == 6) {
            cout << "Exiting..." << endl;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}