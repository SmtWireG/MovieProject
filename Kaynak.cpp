#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Movie {

public:
	string title;
	string genre;
	string decade;
	string storyStructre;
	
	Movie(string title, string genre, string decade,string storyStructre) :title(title), genre(genre), decade(decade), storyStructre(storyStructre){}
};

vector<Movie*> createMovieList() {
	vector<Movie*> movies;

	movies.push_back(new Movie("The Godfather", "Crime", "70's", "Character driven transformation story"));
	movies.push_back(new Movie("12 Angry Men", "Drama", "50's", "Taking place in one place"));
	movies.push_back(new Movie("The Dog Day Afternoon", "Comedy", "70's,", "Taking place in one place"));
	movies.push_back(new Movie("Fight Club", "Drama", "90's", "Twist-Driven"));
	movies.push_back(new Movie("Forrest Gump", "Drama", "90's", "Classic Three Act Structure"));
	movies.push_back(new Movie("The Wolf Of Wall Street", "Comedy", "00's", "Biography"));
	movies.push_back(new Movie("3 Idiots", "Comedy", "00's", "Flashback based"));
	movies.push_back(new Movie("Intouchables", "Drama", "00's", "Classic Three Act Structure"));
	movies.push_back(new Movie("The Prestige", "Sci-Fi", "00's", "Twist-Driven"));
	movies.push_back(new Movie("The Notebook", "Romance", "00's", "Flashback based"));
	movies.push_back(new Movie("Star Wars: Episode V - The Empire Strikes Back", "Sci-Fi", "80's", "Classic Three Act Structure"));
	
	return movies;
}

struct Preferences {
	string title;
	string genre;
	string decade;
	string storyStructre;
};


 Preferences askPreferences() {
	 Preferences prefs;
	 
	 cout << "Let's find a movie for you" << endl << endl;

	cout << "Choose a genre   (Comedy - Drama - Crime- Sci-Fi - Romance): " << endl;
	getline(cin, prefs.genre);

	cout << "Choose a decade   (50's - 70's - 80's - 90's - 00's): " << endl;
	getline(cin, prefs.decade);

	cout << "Choose story structre   (Character driven transformation story - Taking place in one place  -  Classic Three Act Structure - Twist-Driven -  Flashback based - Biography): " << endl;
	getline(cin, prefs.storyStructre);

	return prefs;
}


 Movie* findBestMatch(vector<Movie*>& movies, Preferences& prefs) {

	 Movie* bestMatch = nullptr;
	 int highestScore = -1;

	 for (Movie* m : movies) {
		 int score = 0;
		 if (m->genre == prefs.genre) score++;
		 if (m->decade == prefs.decade) score++;
		 if (m->storyStructre == prefs.storyStructre) score++;

		 if (score > highestScore) {
			 highestScore = score;
			 bestMatch = m;
		 }
	 }
	 return bestMatch;
 }


 int main() {

	 vector<Movie*> movieList = createMovieList();

	 try {
		 Preferences prefs = askPreferences();
		 Movie* recommendation = findBestMatch(movieList, prefs);

		 if (recommendation) {
			 cout << "We recommend " << recommendation->title << endl;
		 }
		 else {
			 cout << "Sorry,no exact match.Try different preferences." << endl;
		 }

	 }
	 catch (...) {
		 cout << "An Unexpected error occured." << endl;
	 }


	 for (Movie* m : movieList) {
		 delete m;
	 }


	 return 0;
 }





