//Version 11
#include <iostream>
#include <string>

//************************************ Start Book Management**********************************//

using namespace std;
struct Book* head = NULL;
struct Book* tail = NULL;
struct Book* next = NULL;
struct Book* prev = NULL;

struct Purchase* pHead = NULL;
struct Purchase* pTail = NULL;
struct Purchase* pNext = NULL;
struct Purchase* pPrev = NULL;


void displayallbook();
void sortAscending();
void sortDescending();
int main();

struct Book {
	int bookId, quantity;
	string genre, bookTitle;
	float price;
	//Pointers
	Book* head;
	Book* tail;
	Book* next;
	Book* prev;

	Book() {
		this->bookId = NULL;
		this->bookTitle = "";
		this->genre = "";
		this->price = NULL;
		this->quantity = NULL;
		this->head = NULL;
		this->next = NULL;
		this->prev = NULL;
		this->tail = NULL;
	}

};

//**********************************Start Search For Book By ID************************************//

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
	cout << "Book not found!\n";
	cout << "Type 'Exit' to exit or";
endsearch:;

	cout << endl;

}

//***********************************Start Filter Book By Genre***********************************//

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
		cout << "No books found.\n\n";//added \n\n
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

//**********************************Start Update Book By ID************************************//

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
				break;
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


	}
	cout << "\nBook not found. Returned to Main Menu.\n";
main:;
	main();

}



//**********************************Start Sort Book By Quantity************************************//


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

}

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


//**********************************Start Delete Book By ID************************************//


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
		head = del->next;    //head value changes to the next node
		del->prev = NULL;
		delete(del);//delete node
		cout << "Book Deleted Successfully!" << "\n";
		return;
	}
	Book* prev = head;// find previous node
	while (prev->next != NULL) {
		Book* current = prev->next;
		if (current->bookId == bookid) {
			// link prev and next
			Book* next = current->next;
			prev->next = next;
			if (next != NULL) {
				next->prev = prev;
			}
			else {
				tail = prev;
			}
			delete(current);
			cout << "Book Deleted successfully!" << "\n";
			return;
		}
		prev = prev->next;
	}
	cout << "No Book Record Found!" << "\n";
};



//**********************************Start Add Book By ID************************************//



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
			checkID = NULL;
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


//**********************************Start Displaying All Books************************************//


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


//**********************************Start Displaying Booking By ID in Ascending Order************************************//


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

//**********************************Purchase Management************************************//

struct Purchase {
	int purchaseId;
	float totalPrice;
	Book* book;
	/*int bookId, quantity;
	string genre, bookTitle;
	float price;*/

	Purchase* pHead;
	Purchase* pTail;
	Purchase* pNext;
	Purchase* pPrev;

	

	Purchase() {
		this->purchaseId = NULL;
		this->book = NULL;
		this->totalPrice = NULL;
		this->pHead = NULL;
		this->pTail = NULL;
		this->pNext = NULL;
		this->pPrev = NULL;
	}



};
int bookId, quantity;
string bookTitle, genre;
float price;

void addnewpurchase() {

	//For iteration
	struct Book* addBookPurchase = head;

	//Create new instance of purchase
	struct Purchase* newpurchase = pHead;
	//Create empty new instance of bookquantity
	

	int purchaseId;
	
reenterbooks:;
	//Validate for existing purchase ID
	cout << "Purchase ID: " << endl;
	cin >> purchaseId;

	while ((purchaseId <= 0 || purchaseId >= 1000000)) {
		cout << "Invalid input\n";
		cout << "ID: ";
		cin >> purchaseId;
	}


	//reenterbooks
	int BookID;
	int decision;
	int purchaseQuantity;

	

	cout << "Book ID: " << endl;
	cin >> BookID;

	//addBookPurchase: Book type that takes in the full database of books
	//while addbookpurchase != NULL then if addbookpurchase bookid matches users input then proceed to newpurchase
	//if the addbookpurchase = NULL then move to next
	
	//newpurchase: Purchase type that takes in its own var but also a Book obj. Book obj contains full database unless new Book();
	//if newpurchase is empty, create a new instance and fill purchaseId of user input and book obj of addbookpurchase. 
	//
	
	//bookquantity: Book type that is completely empty and only takes in books that fits what the user chose and also has its own quantity value.
	//bookquantity var takes in newpurchase var then couts all data for purchase.


	while (addBookPurchase != NULL) {
		if (addBookPurchase->bookId == BookID) {
			//Filter it here with selected books
			// Add Purchase

			if (newpurchase == NULL) {
				newpurchase = new Purchase();
				newpurchase->book = new Book();


				newpurchase->purchaseId = purchaseId;
				newpurchase->book->bookId = addBookPurchase->bookId;
				newpurchase->book->bookTitle = addBookPurchase->bookTitle;
				newpurchase->book->genre = addBookPurchase->genre;
				cout << "Quantity" << endl;
				cin >> newpurchase->book->quantity;
				newpurchase->book->price = addBookPurchase->price;

				cout << newpurchase->book->bookId << endl; 
				cout << newpurchase->book->bookTitle << endl;
				cout << newpurchase->book->genre << endl;
				cout << newpurchase->book->quantity << endl;
				cout << newpurchase->book->price << endl;

				

				//Maths to deduct products from main book linked list
				addBookPurchase->quantity = addBookPurchase->quantity - newpurchase->book->quantity;
				
				cout << addBookPurchase->quantity;

				//newpurchase = newpurchase->pNext; // added newpurchase next
				
				while (newpurchase != NULL) {
					cout << "___________________________________________________________________________________________________________\n";
					cout << "  Purchase ID ||  Book ID ||    Book Title    ||        Genre        ||     Quantity     ||     Price    ||\n";
					cout << "-----------------------------------------------------------------------------------------------------------\n";

					if (newpurchase->purchaseId == purchaseId) {

						cout << "     " << newpurchase->purchaseId <<
							"\t \t" << newpurchase->book->bookId <<
							"\t \t" << newpurchase->book->bookTitle <<
							"\t \t" << newpurchase->book->genre <<
							"\t \t       " << newpurchase->book->quantity <<
							"\t \t" << newpurchase->book->price << "  " << "\n";


						

						newpurchase = newpurchase->pNext;

					}


					
					/*if (pHead == NULL) {
						newpurchase->pPrev = NULL;
						pHead = newpurchase;
						pTail = newpurchase;

					}
					else if (pHead != NULL) {
						newpurchase->pPrev = pTail;
						pTail->pNext = newpurchase;
						pTail = newpurchase;
						pTail->pNext = NULL;
					}*/
					//removed break

				}
				
				
			}
			else {
				
				cout << newpurchase->book->bookId << endl;
				cout << newpurchase->book->bookTitle << endl;
				cout << newpurchase->book->genre << endl;
				cout << newpurchase->book->quantity << endl;
				cout << newpurchase->book->price << endl;

				newpurchase->purchaseId = purchaseId;
				newpurchase->book->bookId = addBookPurchase->bookId;
				newpurchase->book->bookTitle = addBookPurchase->bookTitle;
				newpurchase->book->genre = addBookPurchase->genre;
				cout << "Quantity" << endl;
				cin >> newpurchase->book->quantity;
				newpurchase->book->price = addBookPurchase->price;

				cout << newpurchase->book->bookId << endl;
				cout << newpurchase->book->bookTitle << endl;
				cout << newpurchase->book->genre << endl;
				cout << newpurchase->book->quantity << endl;
				cout << newpurchase->book->price << endl;

				//Maths
				addBookPurchase->quantity = addBookPurchase->quantity - newpurchase->book->quantity;

				cout << addBookPurchase->quantity;

				while (newpurchase != NULL) {
					cout << "___________________________________________________________________________________________________________\n";
					cout << "  Purchase ID ||  Book ID ||    Book Title    ||        Genre        ||     Quantity     ||     Price    ||\n";
					cout << "-----------------------------------------------------------------------------------------------------------\n";

					if (newpurchase->purchaseId == purchaseId) {

						cout << "     " << newpurchase->purchaseId <<
							"\t \t" << newpurchase->book->bookId <<
							"\t \t" << newpurchase->book->bookTitle <<
							"\t \t" << newpurchase->book->genre <<
							"\t \t       " << newpurchase->book->quantity <<
							"\t \t" << newpurchase->book->price << "  " << "\n";

						
						
						newpurchase = newpurchase->pNext;
					}
					
					
					//removed break;
					
				}



				
				
				
			}

			
			
		
		}
		
		addBookPurchase = addBookPurchase->next;
		
	}
	
	
	
	

	main();
}

void displayallpurchase() {
	
	struct Purchase* newpurchase = pHead;

	cout << newpurchase->book->bookId << endl;
	cout << newpurchase->book->bookTitle << endl;
	cout << newpurchase->book->genre << endl;
	cout << newpurchase->book->quantity << endl;
	cout << newpurchase->book->price << endl;


	if (newpurchase == NULL) {
		cout << "No records in the list!\n\n";
	}

	cout << "___________________________________________________________________________________________________________\n";
	cout << "  Purchase ID ||  Book ID ||    Book Title    ||        Genre        ||     Quantity     ||     Price    ||\n";
	cout << "-----------------------------------------------------------------------------------------------------------\n";

	while (newpurchase != NULL) {
		
		cout << "     " << newpurchase->purchaseId <<
			"\t \t" << newpurchase->book->bookId <<
			"\t \t" << newpurchase->book->bookTitle <<
			"\t \t" << newpurchase->book->genre <<
			"\t \t       " << newpurchase->book->quantity <<
			"\t \t" << newpurchase->book->price << "  " << "\n";
		newpurchase = newpurchase->pNext;
	}

	cout << endl;
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
	cout << "4. Filter Book by Genre" << endl;
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
			cout << "Search next ID:\n\n";

			cin >> keyword;
			if (keyword == 'Exit') {
				break;
			}
			searchBook(keyword);

			cout << "Keep searching by selecting 1.Yes, 2.No\n\n";
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
		int decision = 1;
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