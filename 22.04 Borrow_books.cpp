#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    bool taken = false;
};

class Library {
private:
    vector<Book> books;

public:
    Library() {
        books = {
            {"The Great Gatsby", "F. Scott Fitzgerald"},
            {"To Kill a Mockingbird", "Harper Lee"},
            {"1984", "George Orwell"},
            {"Pride and Prejudice", "Jane Austen"},
            {"Moby-Dick", "Herman Melville"},
            {"War and Peace", "Leo Tolstoy"},
            {"The Catcher in the Rye", "J.D. Salinger"},
            {"The Hobbit", "J.R.R. Tolkien"},
            {"Brave New World", "Aldous Huxley"},
            {"Crime and Punishment", "Fyodor Dostoevsky"},
            {"Jane Eyre", "Charlotte Brontë"},
            {"The Lord of the Rings", "J.R.R. Tolkien"},
            {"Animal Farm", "George Orwell"},
            {"Wuthering Heights", "Emily Brontë"},
            {"The Odyssey", "Homer"},
            {"The Brothers Karamazov", "Fyodor Dostoevsky"},
            {"One Hundred Years of Solitude", "Gabriel García Márquez"},
            {"The Picture of Dorian Gray", "Oscar Wilde"},
            {"Fahrenheit 451", "Ray Bradbury"},
            {"Dracula", "Bram Stoker"},
            {"The Iliad", "Homer"},
            {"Les Misérables", "Victor Hugo"},
            {"A Tale of Two Cities", "Charles Dickens"},
            {"Don Quixote", "Miguel de Cervantes"},
            {"Ulysses", "James Joyce"},
            {"The Divine Comedy", "Dante Alighieri"},
            {"Hamlet", "William Shakespeare"},
            {"Macbeth", "William Shakespeare"},
            {"The Alchemist", "Paulo Coelho"},
            {"The Little Prince", "Antoine de Saint-Exupéry"},
            {"Slaughterhouse-Five", "Kurt Vonnegut"},
            {"Catch-22", "Joseph Heller"},
            {"The Sun Also Rises", "Ernest Hemingway"},
            {"The Old Man and the Sea", "Ernest Hemingway"},
            {"Anna Karenina", "Leo Tolstoy"},
            {"Madame Bovary", "Gustave Flaubert"},
            {"The Stranger", "Albert Camus"},
            {"The Metamorphosis", "Franz Kafka"},
            {"Siddhartha", "Hermann Hesse"},
            {"Heart of Darkness", "Joseph Conrad"},
            {"The Sound and the Fury", "William Faulkner"},
            {"Lolita", "Vladimir Nabokov"},
            {"Beloved", "Toni Morrison"},
            {"Invisible Man", "Ralph Ellison"},
            {"The Road", "Cormac McCarthy"},
            {"Life of Pi", "Yann Martel"},
            {"The Kite Runner", "Khaled Hosseini"},
            {"A Thousand Splendid Suns", "Khaled Hosseini"},
            {"The Book Thief", "Markus Zusak"},
            {"The Fault in Our Stars", "John Green"},
            {"Gone with the Wind", "Margaret Mitchell"},
            {"The Hunger Games", "Suzanne Collins"},
            {"Harry Potter and the Sorcerer’s Stone", "J.K. Rowling"},
            {"The Da Vinci Code", "Dan Brown"},
            {"Angels & Demons", "Dan Brown"},
            {"The Girl with the Dragon Tattoo", "Stieg Larsson"},
            {"The Shining", "Stephen King"},
            {"It", "Stephen King"},
            {"Misery", "Stephen King"},
            {"Dune", "Frank Herbert"},
            {"Ender’s Game", "Orson Scott Card"},
            {"Neuromancer", "William Gibson"},
            {"Snow Crash", "Neal Stephenson"},
            {"Foundation", "Isaac Asimov"},
            {"I, Robot", "Isaac Asimov"},
            {"The Martian", "Andy Weir"},
            {"Ready Player One", "Ernest Cline"},
            {"Jurassic Park", "Michael Crichton"},
            {"The Time Machine", "H.G. Wells"},
            {"The War of the Worlds", "H.G. Wells"},
            {"Frankenstein", "Mary Shelley"},
            {"The Handmaid’s Tale", "Margaret Atwood"},
            {"Oryx and Crake", "Margaret Atwood"},
            {"The Giver", "Lois Lowry"},
            {"The Maze Runner", "James Dashner"},
            {"Divergent", "Veronica Roth"},
            {"Twilight", "Stephenie Meyer"},
            {"The Chronicles of Narnia", "C.S. Lewis"},
            {"Alice’s Adventures in Wonderland", "Lewis Carroll"},
            {"Through the Looking-Glass", "Lewis Carroll"},
            {"Peter Pan", "J.M. Barrie"},
            {"Treasure Island", "Robert Louis Stevenson"},
            {"Robinson Crusoe", "Daniel Defoe"},
            {"Gulliver’s Travels", "Jonathan Swift"},
            {"The Secret Garden", "Frances Hodgson Burnett"},
            {"Little Women", "Louisa May Alcott"},
            {"Anne of Green Gables", "L.M. Montgomery"},
            {"Heidi", "Johanna Spyri"},
            {"Black Beauty", "Anna Sewell"},
            {"Charlotte’s Web", "E.B. White"},
            {"Matilda", "Roald Dahl"},
            {"The BFG", "Roald Dahl"},
            {"Charlie and the Chocolate Factory", "Roald Dahl"},
            {"The Wind in the Willows", "Kenneth Grahame"},
            {"Watership Down", "Richard Adams"},
            {"The Call of the Wild", "Jack London"},
            {"White Fang", "Jack London"},
            {"Of Mice and Men", "John Steinbeck"},
            {"East of Eden", "John Steinbeck"},
            {"The Grapes of Wrath", "John Steinbeck"}
        };
    }

    void sortByAuthor() {
        for (int i = 0; i < books.size() - 1; i++) {
            for (int j = 0; j < books.size() - i - 1; j++) {
                if (books[j].author > books[j + 1].author) {
                    swap(books[j], books[j + 1]);
                }
            }
        }
    }

    void borrowBook(string key) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == key || books[i].author == key) {
                if (books[i].taken) {
                    cout << "Already taken!\n";
                } else {
                    books[i].taken = true;
                    cout << "Borrowed: " << books[i].title << endl;
                }
                return;
            }
        }
        cout << "Not found!\n";
    }

    void returnBook(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                if (!books[i].taken) {
                    cout << "Was not taken!\n";
                } else {
                    books[i].taken = false;
                    cout << "Returned: " << title << endl;
                }
                return;
            }
        }
        cout << "Not found!\n";
    }

    void report() {
        cout << "\nAvailable:\n";
        for (auto &b : books)
            if (!b.taken)
                cout << b.title << " - " << b.author << endl;

        cout << "\nTaken:\n";
        for (auto &b : books)
            if (b.taken)
                cout << b.title << " - " << b.author << endl;
    }
};

int main() {
    Library lib;
    lib.sortByAuthor();

    int choice;
    string input;

    while (true) {
        cout << "\n Library menu.\n";
        cout << "1. Borrow book\n";
        cout << "2. Return book\n";
        cout << "3. Show report\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        cin.ignore(); 

        if (choice == 1) {
            cout << "Enter title or author: ";
            getline(cin, input);
            lib.borrowBook(input);
        }
        else if (choice == 2) {
            cout << "Enter title to return: ";
            getline(cin, input);
            lib.returnBook(input);
        }
        else if (choice == 3) {
            lib.report();
        }
        else if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}