#include <iostream>
//Define the MaxNumber of Person
#define PERSONNUMBER 100

using namespace std;

typedef struct Person
{
	string Name;
	char Gender;
	int Age;
	string TelNumber;
	int Score;
} PERSON;

typedef struct ContactData
{
	PERSON person[PERSONNUMBER];
	int curPersonNumber;
} ADDATA;

void Init();
void Quit();
int GetInput();
void CleanScreen();

void JudgeOperate(int Input, ADDATA* addPerson);

int GetTarget(ADDATA* addPerson, string target);
void DisplayTarget(ADDATA* addPerson, int target);
void AddData(ADDATA* addPerson, int targetNumber);

void AddPerson(ADDATA* addPerson);
void Display(ADDATA* addPerson);
void Delete(ADDATA* addPerson);
void Search(ADDATA* addPerson);
void Rewrite(ADDATA* addPerson);
void DeleteAll(ADDATA* addPerson);

/// <summary>
/// This is Main Function
/// </summary>
/// <returns></returns>
int main()
{
	int ret;
	ADDATA addPerson;
	addPerson.curPersonNumber = 0;

	while (1)
	{
		Init();
		ret = GetInput();
		JudgeOperate(ret, &addPerson);
	}

	return 0;
}
////////////////////////////////////////////////////////////////////////////
/// <summary>
/// 
/// This is the Operate Function
/// 
/// </summary>
////////////////////////////////////////////////////////////////////////////
void Init()
{
	cout << "\n";
	cout << "\t\t\t\t" << "**********************************************" << "\n";
	cout << "\t\t\t\t" << "******        Contact System           *******" << "\n";
	cout << "\t\t\t\t" << "******                                 *******" << "\n";
	cout << "\t\t\t\t" << "******     1. Add        Person        *******" << "\n";
	cout << "\t\t\t\t" << "******     2. Display    Person        *******" << "\n";
	cout << "\t\t\t\t" << "******     3. Delete     Person        *******" << "\n";
	cout << "\t\t\t\t" << "******     4. Search     Person        *******" << "\n";
	cout << "\t\t\t\t" << "******     5. Rewrite    Person        *******" << "\n";
	cout << "\t\t\t\t" << "******     6. Delete     AllPerson     *******" << "\n";
	cout << "\t\t\t\t" << "******                                 *******" << "\n";
	cout << "\t\t\t\t" << "******           0. Quit               *******" << "\n";
	cout << "\t\t\t\t" << "**********************************************" << "\n";
}

void Quit()
{
	cout << "Happy Used, Welcome to Use Next Time" << "\n";
	exit(-1);
}

int GetInput()
{
	int Input;
	cout << "Please Input the Operate!" << "\n";
	cin >> Input;

	return Input;
}

void JudgeOperate(int Input, ADDATA* addPerson)
{
	switch (Input)
	{
	case 1:
		AddPerson(addPerson);
		break;
	case 2:
		Display(addPerson);
		break;
	case 3:
		Delete(addPerson);
		break;
	case 4:
		Search(addPerson);
		break;
	case 5:
		Rewrite(addPerson);
		break;
	case 6:
		DeleteAll(addPerson);
		break;
	case 0:
		Quit();
		break;
	default:
		cout << "Your Input is Illegal" << "\n";
		break;
	}
}

void AddPerson(ADDATA* addPerson)
{
	if (PERSONNUMBER == addPerson->curPersonNumber)
	{
		cout << "The Contact System is Full" << "\n";
	}
	else
	{
		AddData(addPerson, addPerson->curPersonNumber);

		addPerson->curPersonNumber++;
	}

	CleanScreen();
}

void Display(ADDATA* addPerson)
{
	if (!addPerson->curPersonNumber)
	{
		cout << "There is no person in Contact System!" << endl;
	}
	else
	{
		for (int i = 0; i < addPerson->curPersonNumber; i++)
		{
			cout << "Name: " << addPerson->person[i].Name << "\t"
				<< "Gender: " << (addPerson->person[i].Gender == ('f' | 'F') ? "Female" : "Male") << "\t"
				<< "Age: " << addPerson->person[i].Age << "\t\t"
				<< "Telphone: " << addPerson->person[i].TelNumber << "\t"
				<< "Score: " << addPerson->person[i].Score << "\n";
		}
	}

	CleanScreen();
}

void Delete(ADDATA* addPerson)
{
	string target;
	cout << "Please Input the Name that need to Delete:" << endl;
	cin >> target;

	int ret = GetTarget(addPerson, target);

	if (-1 == ret)
	{
		cout << "There is No that Person!" << endl;
	}
	else
	{
		for (int i = ret; i < addPerson->curPersonNumber; i++)
		{
			addPerson->person[i] = addPerson->person[i + 1];
		}

		addPerson->curPersonNumber--;
		cout << "Delete Success!" << endl;
	}

	CleanScreen();
}

void Search(ADDATA* addPerson)
{
	string target;
	cout << "Please Input the Name that need to Search:" << endl;
	cin >> target;

	int ret = 0;
	ret = GetTarget(addPerson, target);
	if (-1 == ret)
	{
		cout << "This is no that Person!" << endl;
	}
	else
	{
		cout << "Name: " << addPerson->person[ret].Name << "\t"
			<< "Gender: " << (addPerson->person[ret].Gender == ('f' | 'F') ? "Female" : "Male") << "\t"
			<< "Age: " << addPerson->person[ret].Age << "\t\t"
			<< "Telphone: " << addPerson->person[ret].TelNumber << "\t"
			<< "Score: " << addPerson->person[ret].Score << "\n";
	}

	CleanScreen();
}

void Rewrite(ADDATA* addPerson)
{
	string target;
	cout << "Please Input the Name that need to Modify:" << endl;
	cin >> target;

	int ret = GetTarget(addPerson, target);

	if (-1 == ret)
	{
		cout << "There is No that Person!" << endl;
	}
	else
	{
		AddData(addPerson, ret);
	}

	CleanScreen();
}

void DeleteAll(ADDATA* addPerson)
{
	char judge;
	cout << "If you wan to Delete All the Data:(Y/N)" << endl;
	cin >> judge;

	if (('y' | 'Y') == judge)
	{
		addPerson->curPersonNumber = 0;
		cout << "The Contact System has been Emptied!" << endl;
	}
	CleanScreen();
}

void CleanScreen()
{
	system("pause");
	system("cls");
}


////////////////////////////////////////////////////////////////////////////
/// <summary>
/// 
/// Some Function About Details, For example:  Simplify the code
/// 
/// </summary>
/// <param name="addPerson"></param>
/// <param name="target"></param>
/// <returns></returns>
////////////////////////////////////////////////////////////////////////////


/// <summary>
/// 
/// This Function is to judge target which is in the Contact System
/// 
/// </summary>
/// <param name="addPerson"></param>
/// <param name="target"></param>
/// <returns></returns>
int GetTarget(ADDATA* addPerson, string target)
{
	for (int i = 0; i < addPerson->curPersonNumber; i++)
	{
		if (target == addPerson->person[i].Name)
		{
			return i;
		}
	}

	return -1;
}

void DisplayTarget(ADDATA* addPerson, int target)
{
	if (-1 == target)
	{
		cout << "This is no that Person!" << endl;
	}
	else
	{
		cout << "Name: " << addPerson->person[target].Name << "\t"
			<< "Gender: " << (addPerson->person[target].Gender == ('f' | 'F') ? "Female" : "Male") << "\t"
			<< "Age: " << addPerson->person[target].Age << "\t\t"
			<< "Telphone: " << addPerson->person[target].TelNumber << "\t"
			<< "Score: " << addPerson->person[target].Score << "\n";
	}
}

/// <summary>
/// 
/// This Function is Add the Data to the targetNumber
/// Paraments:
///				ADDATA* addPerson         this is Data array
///				int targetNumber		  This is the subscript of the array element to add data
/// </summary>
/// <param name="addPerson"></param>
/// <param name="targetNumber"></param>
void AddData(ADDATA* addPerson, int targetNumber)
{
	string name;
	cout << "Please Input Name:" << "\n";
	cin >> name;
	addPerson->person[targetNumber].Name = name;

	char gender;
	cout << "Please Input Gender:(F/M)" << "\n";
	cin >> gender;
	addPerson->person[targetNumber].Gender = gender;

	int age;
	cout << "Please Input Age:(16-130)" << "\n";
	cin >> age;
	addPerson->person[targetNumber].Age = age;

	string telphone;
	cout << "Please Input Telphone:" << "\n";
	cin >> telphone;
	addPerson->person[targetNumber].TelNumber = telphone;

	int score;
	cout << "Please Input Score:(0-150)" << "\n";
	cin >> score;
	addPerson->person[targetNumber].Score = score;
}