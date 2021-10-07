#include "Client.h"

void Client::setID(int i) {
	id = i;
}
int Client::getID() const {
	return id;
}
void Client::setName(string fn, string ln) {
	firstName = fn;
	lastName = ln;
}
string Client::getFirstName() const {
	return firstName;
}
string Client::getLastName() const {
	return lastName;
}
Client::Client(int i, string fn, string ln) {
	id = i;
	firstName = fn;
	lastName = ln;
	checking = nullptr;
	saving = nullptr;
}
Client::Client() {
	id = -1;
	firstName = "";
	lastName = "";
	checking = nullptr;
	saving = nullptr;
}