#include <iostream>
#include <iomanip>

using namespace std;

void arrSelectSort(double *, int);
void showArrPtr(double *, int);
void showAverage(double, int);

int main()
{
	double *scores,                        //To dynamically allocate an array
		total = 0.0;                        //Accumulator
	//average;                             //To hold the averge scores
	int numScores;                      //To hold the number of test scores
	
    //Get the number of test scores.
	cout << "How many test scores would you like to process?";
	cin >> numScores;

	//Dynamically allocate an array large enough to hold that many test scores
	scores = new double[numScores];
	if (scores == NULL)
		return 0;

	//Get the test score for each test
	cout << "Enter the test scores below.\n";
	
	
	
	for (int count = 0; count < numScores; count++)
	{
		cout << "Test score #" << (count + 1) << ": ";
		cin >> *(scores + count);
		
	}

	

	//Calculate the total scores
	for (int count = 0; count < numScores; count++)
	{
		total += *(scores + count);
	}
	showAverage(total, numScores);
	//sort the elements of the array pointers
	arrSelectSort(scores, numScores);

	cout << "The test scores in ascending order are: \n";
	showArrPtr(scores, numScores);
	

	//Free memory.
	delete[] scores;
	scores = 0;
	
	

	return 0;

	
}

// bubble sort 
void arrSelectSort(double *array, int size)
{
	int temp;
	bool swap;
	do
	{

		swap = false;

		for (int count = 0; count < (size - 1); count++)
		{
			if (*(array + count) > *(array + count + 1))
			{

				temp = *(array + count);
				*(array + count) = *(array + count + 1);
				*(array + count + 1) = temp;
				swap = true;
			}
		}
	} while (swap);
}

// sort function
void showArrPtr(double *array, int size)
{
	for (int count = 0; count< size; count++)
		cout << *(array + count) << " ";
	cout << endl;
}

// average function
void showAverage(double total, int numScores)
{
	double average;

	//Calculate the average
	average = total / numScores;
	

	//Display the results.
	cout << fixed << showpoint << setprecision(2);
	cout << "Average Score: " << average << endl;

}