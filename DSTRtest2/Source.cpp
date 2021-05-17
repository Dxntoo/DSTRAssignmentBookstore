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
			//This prints despite records existing. Maybe due to the loop. 
			searchbook = searchbook->next;
		}

	}
	cout << "Book not found!";
endsearch:;

	cout << endl;

}

void filterbook(/*string category*/) {


}

void updatebook(/*Book book, genre, newdata*/) {

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
//rename it to sort() and remove sortDescending
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
//remove this
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
	/*cin >> addnewbook->bookTitle;*/
	cin.ignore();//make sure during the cin, the getline doesn not take enter as an input 
	getline(cin, addnewbook->bookTitle);

	while (addnewbook->bookTitle == "") {
		cout << "Invalid input\n";
		cout << "Title: ";
		/*cin >> addnewbook->bookTitle;*/
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

//argument takes in user choice in sorting and create and if statement in which if choice is 1, call sort(). If choice is 2, create a reverse traversal function on sort()
void displayallbook(/*int choice*/) { 

	struct Book* temp;
	temp = head;
	
	if (temp == NULL) {
		cout << "No records in the list!";
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

void displaybyId() {

	int tmp;
	struct Book* current = NULL;
	struct Book* index = NULL;
	string tempgenre, tempbookTitle;
	float tempprice;

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


	struct Book* temp;
	temp = head;


	//change this to use head and tail 
	if (temp == NULL) {
		cout << "No records in the list!";
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

	void addnewpurchase() {


	}

	void displayallpurchase() {

	}

	void sortpurchase() {

	}

	void displaypurchase(/* Purchase purchase */) {

	}
};

void Menu() {
	cout << "Welcome, Admin. What would you like to do?";


	cout << endl;
	cout << "1. Add new book" << endl;//
	cout << "2. Display All Books" << endl;//
	cout << "3. Search books by ID" << endl;//
	cout << "4. Filter by category" << endl;
	cout << "5. Update book" << endl;
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
			cout << "Search: \n\n";
			cin >> keyword;
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
		Purchase newPurchase;
		newPurchase.addnewpurchase();
		break;
		}

		{
	case 9:
		//Display All Purchases
		Purchase * displayallpurchase = new Purchase();
		displayallpurchase->displayallpurchase();
		break;
		}

		{
	case 10:
		//Sort Purchases
		Purchase * sortpurchase = new Purchase();
		sortpurchase->sortpurchase();
		break;
		}

		{
	case 11:
		//Search Purchase
		Purchase * displaypurchase = new Purchase();
		displaypurchase->displaypurchase();
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