#include <iostream>
#include <stdint.h>
#include <conio.h>
#include <string>


using namespace std;

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
void main()
{
	string s;
	s = "awww";
	system("pause");
}