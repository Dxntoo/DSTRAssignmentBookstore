#include <iostream>
#include <string>
using namespace std;
struct Book* head = NULL;
struct Book* tail = NULL;
struct Book* next = NULL;
struct Book* prev = NULL;

void displayallbook();
void sortAscending();
void sortDescending();
int main();

struct Book {
	int bookId, quantity;
	string genre, bookTitle;
	float price;

	//Pointers

	Book* tail;
	Book* next;
	Book* prev;

	Book() {
		this->bookId = NULL;
		this->bookTitle = "";
		this->genre = "";
		this->price = NULL;
		this->quantity = NULL;

		this->next = NULL;
		this->prev = NULL;
		this->tail = NULL;
	}

};

void searchBook(int bookId) {

	//Take keyword and search

	struct Book* searchbook;

	searchbook = head;

	//Matching the dataset

	while (searchbook != NULL) {

		if (searchbook->bookId == bookId) {
			cout << "___________________________________________________________________________________________\n";
			cout << "  Book ID ||    Book Title    ||        Genre        ||     Quantity     ||     Price    ||\n";//moved outside the while loop so it doesnt keep repeating the table header
			cout << "-------------------------------------------------------------------------------------------\n";
			cout << "     " << searchbook->bookId <<
				"\t \t" << searchbook->bookTitle <<
				"\t \t" << searchbook->genre <<
				"\t \t       " << searchbook->quantity <<
				"\t \t" << searchbook->price << "  " << "\n";

			goto endsearch;
		}
		else {
			
			searchbook = searchbook->next;
		}

	}
	cout << "Book not found!";
endsearch:;

	cout << endl;

}

void filterbook() {
	//Filter by genre; action, adventure, comedy, romance, scifi, fantasy, horror, others
	// init temp variable
filtermenu:;
	struct Book* filter;

	filter = head;

	string userchoice;
	int decision;
	cout << "Filter by _____: " << endl;

	cout << "1. Action" << endl;
	cout << "2. Adventure" << endl;
	cout << "3. Comedy" << endl;
	cout << "4. Romance" << endl;
	cout << "5. Sci-Fi" << endl;
	cout << "6. Fantasy" << endl;
	cout << "7. Horror" << endl;
	cout << "8. Others" << endl;

	cin >> userchoice;


	if (filter == NULL) {
		cout << "No books found.";
	}

	cout << "___________________________________________________________________________________________\n";
	cout << "  Book ID ||    Book Title    ||        Genre        ||     Quantity     ||     Price    ||\n";//moved outside the while loop so it doesnt keep repeating the table header
	cout << "-------------------------------------------------------------------------------------------\n";

	while (filter != NULL) {
		if (filter->genre == userchoice) {
			
			cout << "     " << filter->bookId <<
				"\t \t" << filter->bookTitle <<
				"\t \t" << filter->genre <<
				"\t \t       " << filter->quantity <<
				"\t \t" << filter->price << "  " << "\n";

			
			filter = filter->next;
		}
		else {
			filter = filter->next;
		}
	}

	cout << "Continue? 1. Yes 2. No" << endl;
	
	cin >> decision;
	if (decision == 1) {
		goto filtermenu;
	}
	else if (decision == 2) {
		goto mainmenu;
	}
	else {
		return;
	}
	
	
mainmenu:;
	main();

}

void updatebook() {

	cout << "Update Book Information by ID: " << endl;
	int bookID;
	cin >> bookID;


	Book* current = head;

	while (current != NULL) {
		if (current->bookId == bookID) {
		
			cout << "___________________________________________________________________________________________\n";
			cout << "  Book ID ||    Book Title    ||        Genre        ||     Quantity     ||     Price    ||\n";//moved outside the while loop so it doesnt keep repeating the table header
			cout << "-------------------------------------------------------------------------------------------\n";
			cout << "     " << current->bookId <<
				"\t \t" << current->bookTitle <<
				"\t \t" << current->genre <<
				"\t \t       " << current->quantity <<
				"\t \t" << current->price << "  " << "\n";

		reupdate:;
			cout << "\nChoose the field that you want to update:\n";
			cout << "1. Book Title" << endl;
			cout << "2. Genre" << endl;
			cout << "3. Quantity" << endl;
			cout << "4. Price" << endl;
			cout << "\n5. Save Changes and Exit to Menu" << endl;

			int choiceupdate;
			cin >> choiceupdate;

			switch (choiceupdate)
			{
			case 1:
				
				cout << "Book Title: ";
				cin.ignore();//make sure during the cin, the getline doesn not take enter as an input 
				getline(cin, current->bookTitle);

				while (current->bookTitle == "") {
					cout << "Invalid input\n";
					cout << "Book Title: ";
					getline(cin, current->bookTitle);
				}
				break;
			case 2:
				
				cout << "Genre :";
				cin >> current->genre;
				while (current->genre == "") {
					cout << "Invalid input\n";
					cout << "Genre :";
					cin >> current->genre;
				}
				break;
			case 3:
				
				cout << "Quantity :";
				cin >> current->quantity;
				while (current->quantity <= 0) {
					cout << "Invalid input\n";
					cout << "Quantity :";
					cin >> current->quantity;
				}
				break;
			case 4:
				
				cout << "Price :";
				cin >> current->price;
				while (current->price <= 0) {
					cout << "Invalid input\n";
					cout << "Price :";
					cin >> current->price;
				}
			case 5:
				goto main;
			default:
				cout << "Wrong choice. Please try again.\n" << endl;
			}


			cout << "___________________________________________________________________________________________\n";
			cout << "  Book ID ||    Book Title    ||        Genre        ||     Quantity     ||     Price    ||\n";//moved outside the while loop so it doesnt keep repeating the table header
			cout << "-------------------------------------------------------------------------------------------\n";
			cout << "     " << current->bookId <<
				"\t \t" << current->bookTitle <<
				"\t \t" << current->genre <<
				"\t \t       " << current->quantity <<
				"\t \t" << current->price << "  " << "\n\n\n\n\n";

			
			goto reupdate;
		}
		else
		{
			current = current->next;
		}

		cout << "\nBook not found.\n";
	}

main:;
	main();

}

void sortByQuantity(int order) {

	switch (order) {
		{
	case 1:
		sortAscending();
		displayallbook();
		main();
		break;	//function for ascending order
		}

		{
	case 2:
		sortDescending();
		displayallbook();
		main();
		break;	//function for descending order
		}

	}
	/*int order;
	cin >> order;*/
	//Switch function
	//Ascending order

	//Descending order
}
// traverse forwards
void sortAscending() {
	struct Book* current = NULL, * index = NULL;

	int temp;
	string tempgenre, tempbookTitle;
	float tempprice;

	if (head == NULL) {
		cout << "No books found.";
		return;
	}
	else {
		for (current = head; current->next != NULL; current = current->next) {
			for (index = current->next; index != NULL; index = index->next) {
				if (current->quantity > index->quantity) {

					temp = current->quantity;
					current->quantity = index->quantity;
					index->quantity = temp;

					temp = current->bookId;
					current->bookId = index->bookId;
					index->bookId = temp;

					tempbookTitle = current->bookTitle;
					current->bookTitle = index->bookTitle;
					index->bookTitle = tempbookTitle;

					tempprice = current->price;
					current->price = index->price;
					index->price = tempprice;

					tempgenre = current->genre;
					current->genre = index->genre;
					index->genre = tempgenre;

				}
			}
		}
	}
}

//traverse backwards
void sortDescending() {
	struct Book* current = NULL, * index = NULL;

	int temp;
	string tempgenre, tempbookTitle;
	float tempprice;

	if (head == NULL) {
		cout << "No books found.";
		return;
	}
	else {
		for (current = head; current->next != NULL; current = current->next) {
			for (index = current->next; index != NULL; index = index->next) {
				if (current->quantity < index->quantity) {

					temp = current->quantity;
					current->quantity = index->quantity;
					index->quantity = temp;

					temp = current->bookId;
					current->bookId = index->bookId;
					index->bookId = temp;

					tempbookTitle = current->bookTitle;
					current->bookTitle = index->bookTitle;
					index->bookTitle = tempbookTitle;

					tempprice = current->price;
					current->price = index->price;
					index->price = tempprice;

					tempgenre = current->genre;
					current->genre = index->genre;
					index->genre = tempgenre;

				}
			}
		}
	}
}
void deletebook() {

	cout << "Book ID?";
	int bookid;
	//enters a bookid to be deleted
	cin >> bookid;
	//validation for null
	if (head == NULL) {
		cout << "No Book found!";
		return;
	}
	//creates another instance and have its value as head
	Book* del = head;

	//if the bookId in database matches with search
	if (del->bookId == bookid) {
		//head value changes to the next node
		head = del->next;
		//delete node
		delete(del);

		cout << "Book Deleted Successfully!" << "\n";
		return;
	}

	// find previous node
	Book* prev = head;
	while (prev->next != NULL) {
		if (prev->next->bookId == bookid) {

			// link prev and next
			Book* next = prev->next->next;
			free(prev->next);
			prev->next = next;
			cout << "Book Deleted successfully!" << "\n";
			return;
		}
		prev = prev->next;
	}
	cout << "No Book Record Found!" << "\n";
};

void addNewBook() {

	struct Book* addnewbook = new Book();

	struct Book* checkID;
	checkID = head;

	//change init values 
	cout << "ID: " << endl;
	cin >> addnewbook->bookId;
	while (checkID != NULL) {

		if (addnewbook->bookId == checkID->bookId) {
			cout << "Duplicate book! Enter a valid book ID" << "\n";
			cin >> addnewbook->bookId;
			checkID == NULL;
		}
		else {
			checkID = checkID->next;
		}
		//Duplicate only works with the previous record and not from beginning

	}

	while ((addnewbook->bookId <= 0 || addnewbook->bookId >= 1000000)) {
		cout << "Invalid input\n";
		cout << "ID: ";
		cin >> addnewbook->bookId;
	}


	cout << "Title: " << endl;
	cin.ignore();//make sure during the cin, the getline doesn not take enter as an input 
	getline(cin, addnewbook->bookTitle);

	while (addnewbook->bookTitle == "") {
		cout << "Invalid input\n";
		cout << "Title: ";
		getline(cin, addnewbook->bookTitle);
	}



	cout << "Genre: " << endl;
	cin >> addnewbook->genre;
	while (addnewbook->genre == "") {
		cout << "Invalid input\n";
		cout << "Genre: ";
		cin >> addnewbook->genre;
	}

	cout << "Quantity: " << endl;
	cin >> addnewbook->quantity;
	while (addnewbook->quantity < 0 || addnewbook->quantity > 999) {
		cout << "Invalid input\n";
		cout << "Quantity: ";
		cin >> addnewbook->quantity;
	}

	cout << "Price: " << endl;
	cin >> addnewbook->price;
	while (addnewbook->price < 0) {
		cout << "Invalid input\n";
		cout << "Price: ";
		cin >> addnewbook->price;
	}

	//Linking

	if (head == NULL) {
		addnewbook->prev = NULL;
		head = addnewbook;
		tail = addnewbook;

	}
	else if (head != NULL) {
		addnewbook->prev = tail;
		tail->next = addnewbook;
		tail = addnewbook;
		tail->next = NULL;
	}

	cout << "\n\n\n";
	cout << "Book added!" << endl;


}


void displayallbook() { 

	struct Book* temp;
	temp = head;
	
	if (temp == NULL) {
		cout << "No records in the list!\n\n";
	}
	cout << "___________________________________________________________________________________________\n";
	cout << "  Book ID ||    Book Title    ||        Genre        ||     Quantity     ||     Price    ||\n";//moved outside the while loop so it doesnt keep repeating the table header
	cout << "-------------------------------------------------------------------------------------------\n";
	while (temp != NULL) {

		cout << "     " << temp->bookId <<
			"\t \t" << temp->bookTitle <<
			"\t \t" << temp->genre <<
			"\t \t       " << temp->quantity <<
			"\t \t" << temp->price << "  " << "\n";
		temp = temp->next;

	}
	
	cout << endl;

}
//Issue 1
void displaybyId() {

	int tmp;
	struct Book* current = NULL;
	struct Book* index = NULL;
	string tempgenre, tempbookTitle;
	float tempprice;
	struct Book* temp;
	temp = head;

	if (temp == NULL && current == NULL && index == NULL) {
		cout << "No records in the list!\n\n";
		return;
	}

	//Bubble sort algo 
	for (current = head; current->next != NULL; current = current->next) {
		for (index = current->next; index != NULL; index = index->next) {
			if (current->bookId > index->bookId) {

				tmp = current->quantity;
				current->quantity = index->quantity;
				index->quantity = tmp;

				tmp = current->bookId;
				current->bookId = index->bookId;
				index->bookId = tmp;

				tempbookTitle = current->bookTitle;
				current->bookTitle = index->bookTitle;
				index->bookTitle = tempbookTitle;

				tempprice = current->price;
				current->price = index->price;
				index->price = tempprice;

				tempgenre = current->genre;
				current->genre = index->genre;
				index->genre = tempgenre;

			}
		}
	}

	


	
	cout << "___________________________________________________________________________________________\n";
	cout << "  Book ID ||    Book Title    ||        Genre        ||     Quantity     ||     Price    ||\n";
	cout << "-------------------------------------------------------------------------------------------\n";
	while (temp != NULL) {

		cout << "     " << temp->bookId <<
			"\t \t" << temp->bookTitle <<
			"\t \t" << temp->genre <<
			"\t \t       " << temp->quantity <<
			"\t \t" << temp->price << "  " << "\n";
		temp = temp->next;

	}


	cout << endl;
}

struct Purchase {
	int purchaseId;
	Book* bookItem;
	float totalPrice;

	Purchase* head;
	Purchase* next;
	Purchase* prev;

	Purchase() {
		this->purchaseId = NULL;
		this->bookItem = NULL;
		this->totalPrice = NULL;
		this->head = NULL;
		this->next = NULL;
		this->prev = NULL;
	}

	
};

void addnewpurchase() {


}

void displayallpurchase() {

}

void sortpurchase() {

}

void displaypurchase(/* Purchase purchase */) {

}

void Menu() {
	cout << "Welcome, Admin. What would you like to do?";


	cout << endl;
	cout << "1. Add new book" << endl;//
	cout << "2. Display All Books" << endl;//
	cout << "3. Search books by ID" << endl;//
	cout << "4. Filter by category" << endl;
	cout << "5. Update book" << endl;//
	cout << "6. Sort by quantity" << endl;//
	cout << "7. Delete book" << endl;//
	cout << "8. Add New Purchase" << endl;
	cout << "9. Display All Purchase" << endl;
	cout << "10. Sort Purchase" << endl;
	cout << "11. Display Specific Purchase by ID\n\n" << endl;

	cout << "12. Exit" << endl;
}

int main() {
	int userchoice;
	Menu();
	cin >> userchoice;
	//do while loop
	switch (userchoice) {
		{
	case 1:
		//Add Book
		int decision = 1;
		do {
			addNewBook();
			displayallbook();
			cout << "Would you like to add more books? 1. Yes 2. No";
			cin >> decision;
		} while (decision == 1);
		main();
		break;
		}

		{
	case 2:
		//Display All Books
		int decision = 1;
		displaybyId();
		cout << "Would you like to be returned to the Main Menu? 1.Yes 2.Exit \n\n\n";
		cin >> decision;
		if (decision == 1) {
			cout << "Returned to main menu. Choose an option \n\n\n";
			main();
		}
		else {
			break;
		}
		//added so it doesnt quit application immediately
		break;
		}

		{
	case 3:
		//Search for a Book
		int keyword;
		int flag = 1;
		do {
			displayallbook();
			cout << "Search:           (Type 'Exit' to exit)\n\n";
			cin >> keyword;
			if (keyword == 'Exit') {
				break;
			}
			searchBook(keyword);

			cout << "Keep searching? 1. Yes 2. No\n\n";
			cin >> flag;

		} while (flag == 1);
		main();
		break;
		}

		{
	case 4:
		//Filter Books
		filterbook();
		break;
		}

		{
	case 5:
		//Update Book
		updatebook();
		break;
		}

		{
	case 6:
		//Sort Books
		cout << "Which order would you like to sort it by? 1. Ascending 2. Descending\n\n";
		int order;
		cin >> order;
		sortByQuantity(order);
		//display by traversing using head or tail
		break;
		}

		{
	case 7:
		//Delete Books
		deletebook();
		displayallbook();
		main();
		break;
		}

		{
	case 8:
		//Add Purchase
		addnewpurchase();
		break;
		}

		{
	case 9:
		//Display All Purchases
		displayallpurchase();
		break;
		}

		{
	case 10:
		//Sort Purchases
		sortpurchase();
		break;
		}

		{
	case 11:
		//Search Purchase
		displaypurchase();
		break;
		}

		{

	case 12:
		//Exit
		break;
		}

		{
	default:
		cout << "Wrong choice.";
		break;
		}
	}


}