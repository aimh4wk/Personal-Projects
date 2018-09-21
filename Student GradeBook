#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

// Constants
const int MAX_ENTRIES = 30;								// Maximum number of entries the user can enter

// Function Prototypes
void SelectionSort(string student_name[], int test_score[], char grade_score[], int amtofdata);
void BubbleSort(int test_score[], string student_name[], char grade_score[], int amtofdata);
void DisplaySort(ofstream &file, int flag, string name[], int score[], char letter[], int size);
void DisplayReport(ofstream &file, int score[], char letter[], int size);

int main()
{
	// Variable/Pointer/Array declarations
	ofstream outfile;									// Used for output to a file
	string student_name[MAX_ENTRIES];					// Array for student names
	int *test_score;									// Pointer for student test scores
	char grade_score[MAX_ENTRIES];						// Array for students grades
	int count = 0;										// General accumulator
	int i;												// Index 
	int amtofdata;										// Stores the amount of times the user wants to enter data
	char letter_grade[5] = { 'A','B','C','D','F' };		// Array that holds a generic letter grade
	int grade[5] = { 90, 80, 70, 60, 0 };				// Array that holds grade break points

	// Welcome Message
	cout << fixed << setprecision(2);
	cout << endl;
	cout << "This is a gradebook application that will let the user enter a students name and grade " << endl
		<< "between 0 and 100. The user may enter up to 30 students. After the user has finished, the program will " << endl
		<< "display all of the data that the user entered with the names in alphabetical order, and then " << endl
		<< "display the students in order from highest to lowest grades. Then it will display a " << endl
		<< "report with the total number of students with each grade and the median, highest, and lowest " << endl
		<< "grade. It will output this to the console directly aswell as to a text file." << endl << endl;

	// Get initial data to allocate dynamic memory to an array
	do
	{
		cout << "How many students will you be entering today? (MAX " << MAX_ENTRIES << "): ";
		cin >> amtofdata;
		if (amtofdata > MAX_ENTRIES || amtofdata <= 0)
		{
			cout << "Please enter a number between 1 and 30 Please!";
			cout << endl;
			cout << "How many students will you be entering today? (MAX " << MAX_ENTRIES << "): ";
			cin >> amtofdata;
		}
	} while (amtofdata > MAX_ENTRIES || amtofdata <= 0);


	// Dynamically allocate memory to an array
	test_score = new int[amtofdata];
	if (test_score == NULL)
		return 0;

	// Input Section
	do
	{
		// Get students name
		cout << "Enter one of your student's name: ";
		cin >> student_name[count];

		// Get the test score of the student
		cout << "Enter the student's test score: ";
		do {
			cin >> test_score[count];
			if (test_score[count] > 100) // Check if scores are out of input ranges
				cout << "Test scores can NOT exceed 100. Re-enter test score." << endl;
			if (test_score[count] < 0)
				cout << "Test scores can NOT be less than zero. Re-enter test score." << endl;
		} while (test_score[count] < 0 || test_score[count] > 100);
		count++; // Increase count
	} while (count < amtofdata);


	// Assign a letter grade to the each student
	for (i = 0; i < count; i++)
	{
		for (int x = 0; x < 5; x++)
		{
			if (test_score[i] >= grade[x])
			{
				grade_score[i] = letter_grade[x]; // Found grade and assigned letter
				x = 5; // Exit the loop
			}
		}
	}

	// Function Call to sort names alphabetically
	SelectionSort(student_name, test_score, grade_score, amtofdata);

	// Output Data

	//opens file
	string newFile = "StudentGradeBook.txt";
	outfile.open(newFile, ios::trunc);

	// Display the grades in alphbetical order
	DisplaySort(outfile, 1, student_name, test_score, grade_score, amtofdata);

	// Function Call to sort grades from highest to lowest
	BubbleSort(test_score, student_name, grade_score, amtofdata);

	// Display a grade from highest to lowest
	DisplaySort(outfile, 2, student_name, test_score, grade_score, amtofdata);

	//Display Grade Book Report
	DisplayReport(outfile, test_score, grade_score, amtofdata);
	
	//closes the opened file
	outfile.close();

	// Free memory
	delete[] test_score;

	system("pause");
	return 0;
}

// Function that sorts names in alphabetical order
void SelectionSort(string student_name[], int test_score[], char grade_score[], int amtofdata)
{
	int i, minimum_i, temp, temp2;			// Index, minimum value, temporary value, temporary value 2
	string temp3;						    // Temporary value for string

	for (i = 0; i < (amtofdata - 1); i++)
	{
		minimum_i = i;
		temp3 = student_name[i];
		temp = test_score[i];
		temp2 = grade_score[i];

		for (int j = i + 1; j < amtofdata; j++)
		{
			if (student_name[j] < temp3)
			{
				temp3 = student_name[j];
				minimum_i = j;

				temp = test_score[j];
				minimum_i = j;

				temp2 = grade_score[j];
				minimum_i = j;
			}
		}

		student_name[minimum_i] = student_name[i];
		student_name[i] = temp3;

		test_score[minimum_i] = test_score[i];
		test_score[i] = temp;

		grade_score[minimum_i] = grade_score[i];
		grade_score[i] = temp2;
	}
	return;
}

// Function that sorts grades in descending order
void BubbleSort(int test_score[], string student_name[], char grade_score[], int amtofdata)
{
	int test_temp;				// Temporary test value
	string name_temp;			// Temporary value for name
	char grade_temp;			// Temporary value for grade
	bool swap;					// Boolean flag
	int last = amtofdata - 1;	

	do
	{
		swap = false;
		for (int i = 0; i < last; i++)
		{
			if (test_score[i] < test_score[i + 1])
			{
				name_temp = student_name[i];
				student_name[i] = student_name[i + 1];
				student_name[i + 1] = name_temp;

				test_temp = test_score[i];
				test_score[i] = test_score[i + 1];
				test_score[i + 1] = test_temp;

				grade_temp = grade_score[i];
				grade_score[i] = grade_score[i + 1];
				grade_score[i + 1] = grade_temp;

				swap = true;
			}
		}
		last--;
	} while (swap != false);
	return;
}

//Function to display sorted grades
void DisplaySort(ofstream &file, int flag, string name[], int score[], char letter[], int size)
{
	switch (flag) {
	case 1:
		cout << "\nSTUDENT GRADE BOOK\n";
		cout << "-------------------" << endl;
		cout << "Student Grades in Alphabetical Order:\n" << endl;
		file << "\nSTUDENT GRADE BOOK\n";
		file << "-------------------" << endl;
		file << "Student Grades in Alphabetical Order:\n" << endl;
		break;
	case 2:
		cout << "\nSorted Student Grades from Highest to Lowest:\n" << endl;
		file << "\nSorted Student Grades from Highest to Lowest:\n" << endl;
		break;
	default:
		cout << "Error, undefined operation requested." << endl;
		file << "Error, undefined operation requested." << endl;
		system("pause");
	}
	cout << setw(15) << left << "    Name" << setw(8) << left << "Score" << setw(4) << left << "Grade" << endl;
	file << setw(15) << left << "    Name" << setw(8) << left << "Score" << setw(4) << left << "Grade" << endl;

	for (int i = 0; i < size; ++i)
	{
		cout << setw(2) << left << i + 1 << ". " << setw(13) << left << name[i] << setw(8) << left << score[i] << setw(4) << left << letter[i] << endl;
		file << setw(2) << left << i + 1 << ". " << setw(13) << left << name[i] << setw(8) << left << score[i] << setw(4) << left << letter[i] << endl;
	}
}

//function to display grade book report
void DisplayReport(ofstream &file, int score[], char letter[], int size)
{
	char letter_grade[5] = { 'A','B','C','D','F' };
	int numGrade[5] = { 0, 0, 0, 0, 0 },
		medGrade = 0;
	double percent[5];

	//calculate number of Letter Grades
	for (int i = 0; i < size; i++)
	{
		switch (letter[i])
		{
		case 'A':
			numGrade[0]++;
			break;
		case 'B':
			numGrade[1]++;
			break;
		case 'C':
			numGrade[2]++;
			break;
		case 'D':
			numGrade[3]++;
			break;
		case 'F':
			numGrade[4]++;
			break;
		default:
			cout << "Error, Undefinded operation requested" << endl;
			file << "Error, Undefinded operation requested" << endl;
			system("pause");
		}
	}

	//calculates percentage of letter grades
	for (int i = 0; i < 5; i++)
		percent[i] = (static_cast <double> (numGrade[i]) / size) * 100;


	//finds median grade.
	//if amount of data is odd
	if (size % 2)
		medGrade = score[size / 2];
	//if amount of data is even 
	else
		medGrade = (score[(size / 2) - 1] + score[size / 2]) / 2;

	//display end report
	cout << "\nGRADE BOOK REPORT\n";
	cout << "-------------------" << endl;
	file << "\nGRADE BOOK REPORT\n";
	file << "-------------------" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << fixed << setprecision(1);
		cout << setw(35) << left << "Total Number of Students with Grade " << letter_grade[i] << setw(3) << left << ": " << setw(4) << left << numGrade[i] << setw(4) << right << percent[i] << "%\n";
		
		file << fixed << setprecision(1);
		file << setw(35) << left << "Total Number of Students with Grade " << letter_grade[i] << setw(3) << left << ": " << setw(4) << left << numGrade[i] << setw(4) << right << percent[i] << "%\n";
	}

	cout << setw(36) << left << "The Highest Grade in your Class is: " << setw(2) << left << score[0] << endl;
	cout << setw(36) << left << "The Lowest Grade in your Class is: " << setw(2) << left << score[size - 1] << endl;
	cout << setw(36) << left << "The Median Grade in your Class is: " << setw(2) << left << medGrade << endl;
	file << setw(36) << left << "The Highest Grade in your Class is: " << setw(2) << left << score[0] << endl;
	file << setw(36) << left << "The Lowest Grade in your Class is: " << setw(2) << left << score[size - 1] << endl;
	file << setw(36) << left << "The Median Grade in your Class is: " << setw(2) << left << medGrade << endl;
}
