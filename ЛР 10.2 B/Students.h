// Students.h 

#include <string>
using namespace std;

enum Specialty { COMPUTER_SCIENCE, INFORMATICS, LABOR_TRAINING, MATH_ECONOMICS, PHYSICS_INFORMATICS };

struct Student
{
    string surname;
    unsigned course;
    Specialty specialty;
    int physics;
    int math;
    union 
    {
        int programming;       
        int numerical_methods; 
        int pedagogy;        
    };
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void Sort(Student* p, const int N);
int* IndexSort(Student* p, const int N);
void PrintIndexSorted(Student* p, int* I, const int N);
int BinSearch(Student* p, const int N, const string surname, const Specialty specialty, const int physics);