//Including .hpp file.
#include "BSTProjectTwo.hpp"

int main(){
	//Defining variables/assignments used.
	bst* bst;
	bst = new bst();
	Course course;
	int choice = 0;
	string searchTerm;
	string tempName;
	string fileName;
	string line;
	ifstream input;
	bool loopRelay = true;
	fileName = "";

	//Repeatedly loops menu until loopRelay set to 'false'.
	while(loopRelay){
		cout << "\n";
		cout << "Welcome to the course planner.\n\n\n";
		cout << "==============================\n";
		cout << "1. Load Data Structure.\n";
		cout << "2. Print Course List.\n";
		cout << "3. Print Course.\n";
		cout << "4. Exit\n\n\n";
		cout << "What would you like to do?\n";

		//Try-safe fail. Followed by a throw/catch.
		try{
			if(cin.fail()){
				throw runtime_error("Input failed. Please try again.");
			}
		}

		catch(runtime_error& excpt){
			loopRelay = false;
			cout << excpt.what();
		}

		//Prompting the user for file info.
		switch (choice){
		case 1:

			cout << "Enter the file exactly as \"courseData.csv\" otherwise you must have your own file.\n";
			cout << "File format should be csv with form: \n";
			cout << "course identifier, course name, prerequisite #1,...,prerequisite #n.\n\n\n";
			cout << "Please enter the name of the file you would like to open:\n";
			cin >> fileName;
			cout << "You entered: " << fileName << "\n";

			input.open(fileName);

			if(!input.is_open()){
				cout << "File opening failed!\n";
				loopRelay = false;
			}

			while(getline(input, line)){

				string courseNum;
				string courseName;
				string prerequisites;

				//Create stringstream to read values separated by commas.
				stringstream ss(line);

				//Course object acting as a placeholder while values are read.
				Course course;

				getline(ss, courseNum, ',');
				course.courseNum = courseNum;

				getline(ss, courseName, ',');
				course.courseName = courseName;

				getline(ss, prerequisites, ',');
				course.prerequisites = prerequisites;

				//Store course structures in the binary search tree.

				bst -> Insert(course);
			}

			input.close();
			//Case 1 end.
			break;

			case 2:

			cout << "Printing courses in order.\n\n";
			cout << "==============================\n";

			bst -> InOrder();

			cout << "==============================\n";

			//Case 2 end.
			break;

			case 3: {

				cout << "What is the course identifier?\n";
				cout << "Please enter a value like: CSCI100\n";
				cout << "Enter your search term: \n";
				cin >> searchTerm;

				//Loop searchTerm, capitalize everything due to file data being capitalized already.
				for (unsigned int i = 0; i < searchTerm.size(); i++){
					searchTerm[i] = toupper(searchTerm[i]);
					}

				cout << "Search term was: " << searchTerm << "\n";

				//Temporary course holder.
				Course temp = bst -> Search(searchTerm);

				//Prints requested information.
				cout << temp.courseNum << ", " << temp.courseName << "\n";
				cout << "Prerequisites: " << temp.prerequisites << "\n";

				//Case 3 end.
				break;
			}

			case 4: {

				cout << "Goodbye. \n";

				//Case 4 end. Exit program.
				return 1;
			}

		}
	}

	return 0;
}
