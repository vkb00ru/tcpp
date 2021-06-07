#include <iostream>
#include <stdint.h>
#include <conio.h>
#include <string>


using namespace std;
class Zakaz;
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
void main()
{
	
	system("pause");
}