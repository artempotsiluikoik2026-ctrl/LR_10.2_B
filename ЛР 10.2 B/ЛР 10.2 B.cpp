// ЛР 10.2 B.cpp

#include <iostream>
#include <string>
#include <Windows.h> 
#include "Students.h"
using namespace std;

int main()
{ 
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);

    int N;
    do {
        cout << "Enter the number of students N: "; cin >> N;
    } while (N < 1);

    Student* p = new Student[N](); 
    int specialtyNumber;
    Specialty specialty;
    int physics;
    string surname;
    int found;
    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "Choose an action:" << endl << endl;
        cout << " [1] - enter data from the keyboard" << endl;
        cout << " [2] - print data" << endl;
        cout << " [3] - physical sort of data" << endl;
        cout << " [4] - index sort and print data" << endl;
        cout << " [5] - binary search for a student by surname, specialty" << endl;
        cout << "       and Physics grade (first do item [3])"
            << endl << endl;
        cout << " [0] - exit and finish the program" << endl << endl;
        cout << "Enter a value: "; cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            Create(p, N);
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            Sort(p, N);
            break;
        case 4:
            PrintIndexSorted(p, IndexSort(p, N), N);
            break;
        case 5:
            cout << "Enter search keys:" << endl;
            do {
                cout << " specialty (0 - Computer Science, 1 - Informatics," << endl;
                cout << "   2 - Labor Training, 3 - Math and Economics," << endl;
                cout << "   4 - Physics and Informatics): ";
                cin >> specialtyNumber;
            } while (specialtyNumber < 0 || specialtyNumber > 4);
            specialty = (Specialty)specialtyNumber;
            do {
                cout << " Physics grade (1-5): "; cin >> physics;
            } while (physics < 1 || physics > 5);
            cin.get(); 
            cin.sync();

            cout << " surname: "; getline(cin, surname);
            cout << endl;
            if ((found = BinSearch(p, N, surname, specialty, physics)) != -1)
                cout << "Student found at position " << found + 1 << endl;
            else
                cout << "Student not found" << endl;
            break;
        case 0:
            break;
        default:
            cout << "You entered a wrong value! "
                "Enter the number of a menu item" << endl;
        }
    } while (menuItem != 0);
    return 0;
}