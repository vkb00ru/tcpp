#include <iostream>
#include <stdint.h>
#include <conio.h>
#include <string>


using namespace std;
class Zakaz;
class client;
class Zakaz
{
	int id;
	int idClient;
	int idTov[5];
	int countTov = 0;
	string status;

public:
	string getStatus() { return status; };
	int getidTov(int i) { return idTov[i]; };
	int getClient() { return idClient; };
	int getcountTov() { return countTov; };
	int getid() { return id; };
	void setStatus(string s) { status = s; };
	void setidTov(int i) { idTov[countTov] = i; countTov++; };
	void setidClient(int i) { idClient = i; };
	void setid(int i) { id = i; };
};
class Manager
{
	friend class client;

	string questions = "";
	int waitIdTov[5];
	int countTov = 0;
public:
	void setquestions(string s) { questions = s; };
	string getquestions() { return questions; };
	int getcountTov() { return countTov; };

	void waitList();
	void addWaitTov(int id);
	string confirmZak();
	void lookTov();
	void checkQuestions();
	void podtverOpl();
	void setStat();
	Manager(string s) :questions(s) {};


private:

};
void Manager::addWaitTov(int id)
{
	waitIdTov[countTov] = id;
	countTov++;
}
void Manager::waitList()
{
	cout << "WaitList: " << endl;
	for (int i(0); i < getcountTov(); i++)
		cout << waitIdTov[i] << " ";
	cout << endl;
}
void Manager::checkQuestions()
{
	cout << getquestions() << endl;
}
string Manager::confirmZak()
{
	int id;
	waitList();
	cout << "Input id for confirm: " << endl;
	cin >> id;
	for (int i(0); i < 5; i++)
		if (waitIdTov[i] == id)
		{
			waitIdTov[i] = 0;
			string mes;
			mes = "Your zakaz " + to_string(id) + " confirmed";
			return mes;
			//c1.setEmail(mes);
		}
	return "";
}
class client
{
	friend class Manager;
	int id;
	Zakaz z;
	string Email = "";
public:
	string getEmail() { return Email; };
	void setEmail(string s) { Email += s + " "; };
	void goClient();
	void question(Manager* m);
	string checkEmail();
	void searchTov();
	void sortTov();
	void Buy(Manager& m1);
	void checkout(Manager& m1);
	client();
	~client();



};
class Tov
{
	int id;
	int price;
	string name;

public:
	int getPrice() { return price; };
	void setPrice(int p) { price = p; };

};

// string client::checkEmail()
//{
//
//}
void client::Buy(Manager& m1)
{
	for (int i(0); i < 5; i++)
	{
		cout << "Set id Tovara: or 0 for exit " << endl;
		cin >> id;
		if (id == 0)
			break;
		z.setidTov(id);
		cout << endl;
	}




}
void client::checkout(Manager& m1)
{
	int idzak;
	Buy(m1);

	cout << "Your Product: " << endl;
	for (int i(0); i < z.getcountTov(); i++)
		cout << z.getidTov(i) << " ";
	cout << endl;
	z.setidClient(this->id);
	cout << "Input idZakaza " << endl;
	cin >> idzak;
	z.setid(idzak);
	m1.addWaitTov(z.getid());
	//m1.waitList();

}
void client::question(Manager* m)
{
	string s;
	cin >> s;
	m->setquestions(s);

}

client::client()
{
}

client::~client()
{
}
void main()
{
	client c1;
	Manager m("");
	Manager* m1 = &m;

	//
	int n;
	while (true)
	{
		cout << "Chose role: " << endl;
		cout << "1: Client " << endl;
		cout << "2: Manager " << endl;
		cin >> n;
		if (n == 1)
		{
			while (true)
			{
				int k;
				cout << "You client!" << endl;
				cout << "1: Question for manager" << endl;
				cout << "2: Checkout" << endl;
				cout << "3: Ceck Email" << endl;
				cout << "9: Exit" << endl;
				cin >> k;
				switch (k)
				{
				case 1:
					cout << "Input message: " << endl;
					c1.question(m1);
					break;
				case 2:

					c1.checkout(*m1);
					break;
				case 3: cout << c1.getEmail();
				default:
					break;
				}
				if (k == 9)
					break;
			}
		}
		if (n == 2)
		{
			while (true)
			{
				int k;
				cout << "You Manager!" << endl;
				cout << "1: Check questions" << endl;
				cout << "2: Confirm Zakaz" << endl;

				cout << "9: Exit" << endl;
				cin >> k;
				switch (k)
				{
				case 1:
					cout << "New message: " << endl;
					m1->checkQuestions();
					break;
				case 2:
					m1->waitList();
					c1.setEmail(m.confirmZak());
					break;
				case 3:

					//m1->confirmZak(m1, c1);
				default:
					break;
				}
				if (k == 9)
					break;
			}

		}

	}



	//m1->checkQuestions();
	system("pause");
}