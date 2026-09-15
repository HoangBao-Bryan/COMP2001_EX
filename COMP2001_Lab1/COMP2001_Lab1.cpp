#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 10;

// Nguyen Hoang Bao
// COMP2001 Lab1

struct MovieRec {
	int year;
	string name;
	double time;
};

int loadArray(MovieRec[]);
void showArray(ofstream& fout, MovieRec[], int);

int main()
{
	MovieRec initialMovie[SIZE];
	int length = 0;

	ofstream fout("movie.report");
	if (!fout.is_open())
	{
		cout << "can't open movie.report file";
		system("pause");
		exit(-1);
	}

	length = loadArray(initialMovie);

	showArray(fout, initialMovie, length);

	fout.close();
	system("type movie.data");
	system("type movie.report"); 

	system("pause");
	return 0;
}

int loadArray(MovieRec initialMovie[])
{
	int length = 0;
	ifstream fin("movie.data");
	if (!fin.is_open())
	{
		cout << "Error opening movie.data file ";
		system("pause");
		exit(-1);
	}

	for (length; length < SIZE; length++)
	{
		fin >> initialMovie[length].year;
		fin.ignore(80, '\n');
		getline(fin, initialMovie[length].name);
		fin >> initialMovie[length].time;
	}
	return length;

}

void showArray(ofstream& fout, MovieRec initialMovie[], int length)
{
	for (int index = 0; index < length; index++)
	{
		fout << initialMovie[index].year << endl;
		fout << initialMovie[index].name << endl;
		fout << initialMovie[index].time << endl;
	}
}

