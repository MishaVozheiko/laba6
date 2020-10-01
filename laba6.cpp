class PrintEd  // базовый класс
{
public:
	static  PrintEd* begin;   //указатель на начало списка
	PrintEd* next = NULL;
	static void ShowList()  //список
	{
		PrintEd* p = begin;
		while (p)
		{
			p->show();
			p = p->next;
		}
	}
	PrintEd()  //без параметров
	{
		author = new char[81];
	}
	PrintEd(const char* AUTHOR, int YEAROFPUBL)  //с параметрами
	{
		// выделение памяти для name. размер выделяемой памяти = длина строки NAME
		author = new char[strlen(AUTHOR) + 1];
		strcpy(author, AUTHOR);
		yearOfPubl = YEAROFPUBL;
	}
	~PrintEd()  // деструктор
	{
		cout << "PrintEd object deleted" << endl;
	}
	virtual void show() = 0;  //Чистая виртуальная функция
	virtual void input() = 0;

protected:
	char* author;
	int yearOfPubl;
};
class Book :public PrintEd   // производный класс
{
public:
	Book() : PrintEd() {}   //без параметров
	Book(const char* AUTHOR, int YEAROFPUBL, int EDITION, string BOOKNAME, bool AddToList = false) :PrintEd(AUTHOR, YEAROFPUBL) //с параметрами
	{
		if (AddToList)
		{
			PrintEd* p = begin;
			while (p->next)
			{
				p = p->next;
			}
			p->next = this;
		}
		edition = EDITION;
		bookName = BOOKNAME;
	}
	void show()
	{
		cout << "\nКласс: Книга";
		cout << "\nАвтор: " << author;
		cout << "\nГод издания: " << yearOfPubl;
		cout << "\nТираж: " << edition;
		cout << "\nНазвание книги: " << bookName;
		cout << "\n";
	}
	void input()
	{
		cout << "\nАвтор: ";
		cin >> author;
		cout << "\nГод издания: ";
		cin >> yearOfPubl;
		cout << "\nТираж: ";
		cin >> edition;
		cout << "\nНазвание книги: ";
		cin >> bookName;
		cout << "\n";
	}
	~Book()  // деструктор
	{
		cout << "Book object deleted" << endl;
	}
protected:
	int edition;
	string bookName;
};
class Textbook :public Book // производный класс
{
public:
	Textbook() : Book() {}

	Textbook(const char* AUTHOR, int YEAROFPUBL, int EDITION, string BOOKNAME,string SUBJECT, bool AddToList = false) :Book(AUTHOR, YEAROFPUBL, EDITION, BOOKNAME)
	{
		if (AddToList)
		{
			PrintEd* p = begin;
			while (p->next)
			{
				p = p->next;
			}
			p->next = this;
		}
		subject = SUBJECT;
	}
	void show()
	{
		cout << "\nКласс: Учебник";
		cout << "\nАвтор: " << author;
		cout << "\nГод издания: " << yearOfPubl;
		cout << "\nТираж: " << edition;
		cout << "\nНазвание книги: " << bookName;
		cout << "\nПредмет: " << subject;
		cout << "\n";
	}
	void input()
	{
		cout << "\nАвтор: ";
		cin >> author;
		cout << "\nГод издания: ";
		cin >> yearOfPubl;
		cout << "\nТираж: ";
		cin >> edition;
		cout << "\nНазвание книги: ";
		cin >> bookName;
		cout << "\nПредмет: ";
		cin >> subject;
		cout << "\n";
	}
	~Textbook()  // деструктор
	{
		cout << "Textbook object deleted" << endl;
	}
protected:
	string subject;
};
class Magazine :public PrintEd  // производный класс
{
public:
	Magazine() : PrintEd() {}

	Magazine(const char* AUTHOR, int YEAROFPUBL, string PUBLISHER, bool AddToList = false) :PrintEd(AUTHOR, YEAROFPUBL)
	{
		if (AddToList)
		{
			PrintEd* p = begin;
			while (p->next)
			{
				p = p->next;
			}
			p->next = this;
		}
		publisher = PUBLISHER;
	}
	void show()
	{
		cout << "\nКласс: Журнал";
		cout << "\nАвтор: " << author;
		cout << "\nГод издания: " << yearOfPubl;
		cout << "\nИздатель: " << publisher;
		cout << "\n";
	}
	void input()
	{
		cout << "\nАвтор: ";
		cin >> author;
		cout << "\nГод издания: ";
		cin >> yearOfPubl;
		cout << "\nИздатель: ";
		cin >> publisher;
		cout << "\n";
	}
	~Magazine()  // деструктор
	{
		cout << "Magazine object deleted" << endl;
	}
protected:
	string publisher;
};
