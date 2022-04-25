#include<iostream>
#include<windows.h>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;


enum Specialnists
{
	computer_science,
	informatics,
	math_a_economics,
	physics_and_informatics,
	labor_education
};

struct Student
{
	char prizv[20];
	//string prizv;
	int kyrs;
	Specialnists specialst;
	int math_grade;
	int physics_grade;
	union
	{
		int programing_grade;
		int chisel_metod_grade;
		int pedagogic_grade;
	};

};
void ToFile(Student& stud, const int N, char* filename);
void Create(Student &stud, const int N, char* filename)
{
	//fstream f("Student1.bit", ios::binary,ios::app);
	int specialst;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); cin.sync();
		cout << " �������: "; /*getline(cin, stud.prizv);*/cin.getline(stud.prizv,20);
		cout << " ����: "; cin >> stud.kyrs;
		cout << " ������������ (0 - ��������� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
		cin >> specialst;
		stud.specialst = (Specialnists)specialst;
		cout << " ������ � ����������: "; cin >> stud.math_grade;
		cout << " ������ � ������: "; cin >> stud.physics_grade;

		switch (stud.specialst)
		{
		case computer_science:
			cout << " ������ � ������������� : "; cin >> stud.programing_grade;
			break;
		case informatics:
			cout << " ������ � ��������� ������ : "; cin >> stud.chisel_metod_grade;
			break;
		default:
			cout << " ������ � ��������� ��������� : "; cin >> stud.pedagogic_grade;
			break;
		}
		cout << endl;
		ToFile(stud, N,filename);
	}
	//f.close();

}

void ToFile(Student& stud, const int N, char* filename)
{
	ofstream f(filename, ios::binary | ios::app);
	/*for (int i = 0; i < N; i++)
	{*/
		f.write((char*)&stud, sizeof(Student));
	//}
	f.close();
}

void PrintFromFile(Student& stud, const int N,string *List, char* filename)
{
	ifstream f(filename, ios::binary);
	int num = 1;
	cout << "======================================================================================================================================================================================="
		<< endl;
	cout << "| � |     �������     | ���� |      ������������      | ������ � ���������� | ������ � ������ | ������ � ������������� | ������ � ��������� ������ | ������ � ��������� ��������� |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;
	while (f.read((char*)&stud, sizeof(Student)))
	{
		cout << "| " << setw(1) << right << num++ << " ";
		cout << "| " << setw(17) << left << stud.prizv
			<< "| " << setw(4) << right << stud.kyrs << " "
			<< "| " << setw(23) << left << List[stud.specialst] << " "
			<< "| " << setw(19) << right << stud.math_grade << " "
			<< "| " << setw(15) << right << stud.physics_grade << " ";
		switch (stud.specialst)
		{
		case computer_science:
			cout << "| " << setw(22) << setprecision(2) << fixed << right
				<< stud.programing_grade << " |" << setw(29) << right << " |" << setw(32) << right << " |" << endl;
			break;
		case informatics:
			cout << "| " << setw(24) << setprecision(2) << fixed << right
				<< " |" << setw(27) << right << stud.chisel_metod_grade << " |" << setw(32) << right << " |" << endl;
			break;
		default:
			cout << "| " << setw(24) << setprecision(2) << fixed << right
				<< " |" << setw(29) << right << " |" << setw(30) << right << stud.pedagogic_grade << " |" << endl;
			break;
		}
	}
	/*for (int j = 0; j < N; j++)
	{
		f.read((char*)&stud, sizeof(Student));
		for (int i = 0; i < N; i++)
		{
			cout << "| " << setw(1) << right << i + 1 << " ";
			cout << "| " << setw(17) << left << stud[i].prizv
				<< "| " << setw(4) << right << stud[i].kyrs << " "
				<< "| " << setw(23) << left << List[stud[i].specialst] << " "
				<< "| " << setw(19) << right << stud[i].math_grade << " "
				<< "| " << setw(15) << right << stud[i].physics_grade << " ";
			switch (stud[i].specialst)
			{
			case computer_science:
				cout << "| " << setw(22) << setprecision(2) << fixed << right
					<< stud[i].programing_grade << " |" << setw(29) << right << " |" << setw(32) << right << " |" << endl;
				break;
			case informatics:
				cout << "| " << setw(24) << setprecision(2) << fixed << right
					<< " |" << setw(27) << right << stud[i].chisel_metod_grade << " |" << setw(32) << right << " |" << endl;
				break;
			default:
				cout << "| " << setw(24) << setprecision(2) << fixed << right
					<< " |" << setw(29) << right << " |" << setw(30) << right << stud[i].pedagogic_grade << " |" << endl;
				break;
			}
		}
	}*/
	
	cout << "======================================================================================================================================================================================="
		<< endl;
	cout << endl;
}

double Vidminno(Student& stud, const int N,char* filename)
{
	ifstream f(filename, ios::binary);
	int k = 0/*,i=0*/;
	while (f.read((char*)&stud, sizeof(Student)))
	{
		switch (stud.specialst)
		{
		case computer_science:
			if (stud.math_grade == 5 && stud.physics_grade == 5 && stud.programing_grade == 5)
			{
				k++;
			}
			break;
		case informatics:
			if (stud.math_grade == 5 && stud.physics_grade == 5 && stud.chisel_metod_grade == 5)
			{
				k++;
			}
			break;
		default:
			if (stud.math_grade == 5 && stud.physics_grade == 5 && stud.pedagogic_grade == 5)
			{
				k++;
			}
			break;
		}
		/*for (int i = 0; i < N; i++)
		{
			switch (stud[i].specialst)
			{
			case computer_science:
				if (stud[i].math_grade == 5 && stud[i].physics_grade == 5 && stud[i].programing_grade == 5)
				{
					k++;
				}
				break;
			case informatics:
				if (stud[i].math_grade == 5 && stud[i].physics_grade == 5 && stud[i].chisel_metod_grade == 5)
				{
					k++;
				}
				break;
			default:
				if (stud[i].math_grade == 5 && stud[i].physics_grade == 5 && stud[i].pedagogic_grade == 5)
				{
					k++;
				}
				break;
			}
		}*/
	}
	return 100.0 * k / N;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string List[] = {
	"��������� �����",
	"�����������",
	"���������� �� ��������",
	"Գ���� �� �����������",
	"������� ��������"
	};
	char fname[60];
	cout << "������ ��'� �����: "; cin.getline(fname, 60);
	int N;
	cout << "������ N: "; cin >> N;
	Student stud;
	Student* stud2 = new Student[N];
	Create(stud, N,fname);
	PrintFromFile(stud, N,List, fname);
	cout << "³������ ��������, �� ������� �� \"������\"" << endl;
	cout << Vidminno(stud,N, fname) << endl;
	return 0;
}
