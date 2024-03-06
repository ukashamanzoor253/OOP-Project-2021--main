#include<iostream>
#include<string>
#include<conio.h>// header fille for getch function 
#define getch() _getch()//it define the gech()function which is used to  hold the output screen for some time
using namespace std;
//Gloubal  variables
int numOfRoom = 0;
int i, option;
int rn; //roomnumber for search
int roomFoundatIndex;


class Guest {
protected:
	char Address[20];
	int  CnicNumber;
	char FromDate[15];
	char ToDate[15];
	long long int TelNumber;
public:
	char Name[20];//Just for accessing 
	int AdvancedPayment;//Just for accessing 

	void getGuestInfo(int);
	void guestShow(int);
	void removeTheRecord(int);

};

class HotelMangment {
public:
	void ManageRoom();
	void Booking();
	void AvailableRoom();
	void SearchGuest();
	void Clearing();
	void GuestSummaryReport();
};
// **Manage Room ** 
class Room :public HotelMangment, public Guest {
private:
	bool isVip;
	int roomType;
public:
	bool roomStatus;//just for accessing  
	int RoomNumber;//just for accessing  
	int DailyRent; // just for accessing; it is not rule that data member must be private


	void getInfo();
	int searchRoom(int);
	void show(int);

};
Room room[10];//object  of Room class
//geting all informaton about Gust
void Guest::getGuestInfo(int roomFoundatIndex) {
	cout << "\tFull Name: ";
	//cin.getline(Name, 20);
	cin >> room[roomFoundatIndex].Name;
	cin.ignore(20, '\n');
	cout << "\tAddress [just city Name]: ";
	//cin.getline(Address, 20);
	cin >> room[roomFoundatIndex].Address;
	cin.ignore(20, '\n');

	cout << "\tCNIC/Passport Number: ";
	cin >> room[roomFoundatIndex].CnicNumber;
	cout << "\tFrom Date [dd/mm/yyyy]: ";
	cin.ignore(20, '\n');
	//cin.getline(FromDate, 15);
	cin >> room[roomFoundatIndex].FromDate;

	cout << "\tTo Date [dd/mm/yyyy]: ";
	//cin.getline(ToDate, 15);
	cin.ignore(15, '\n');
	cin >> room[roomFoundatIndex].ToDate;
	cin.ignore(15, '\n');
	cout << "\tContact Number: ";
	cin >> room[roomFoundatIndex].TelNumber;
	cin.ignore(15, '\n');
	cout << "\tAdvanced Payment: ";
	cin >> room[roomFoundatIndex].AdvancedPayment;
}
void Guest::guestShow(int nameFoundAtIndex) {
	cout << endl;
	cout << "\t----------" << endl;

	cout << "\tGuest Name= " << room[nameFoundAtIndex].Name << endl;
	cout << "\tRoom Number= " << room[nameFoundAtIndex].RoomNumber << endl;
	cout << "\tAddres= " << room[nameFoundAtIndex].Address << endl;
	cout << "\tTelephone Number= 0" << room[nameFoundAtIndex].TelNumber << endl;
	cout << "\tAdvanced Payment= " << room[nameFoundAtIndex].AdvancedPayment << " $" << endl;
}
void Guest::removeTheRecord(int roomFoundatIndex) {
	room[roomFoundatIndex].Name[0] = 0;
	room[roomFoundatIndex].Address[0] = 0;
	room[roomFoundatIndex].CnicNumber = 0;
	room[roomFoundatIndex].FromDate[0] = 0;
	room[roomFoundatIndex].ToDate[0] = 0;
	room[roomFoundatIndex].TelNumber = 0;
	room[roomFoundatIndex].AdvancedPayment = 0;
}

//Get All Information about Room
void Room::getInfo()
{
	cout << "\n\t*****Room Details*****" << endl;
	cout << "\t Add Room Number: ";
	cin >> RoomNumber;
	roomFoundatIndex = room->searchRoom(RoomNumber);
	if (roomFoundatIndex != -1)
		cout << "\tRoom is already existing " << endl;
	else
	{
		//getting correct input of bool Is VIP variable 
		do
		{
			cout << "\t Room is Vip: " << endl;
			cout << "\t\t 1.Yes" << endl;
			cout << "\t\t 2.NO!  ";
			cin >> option;
			switch (option)
			{
			case 1:
				isVip = true;
				break;

			case 2:
				isVip = false;
				break;

			default:
				cout << "\tWrong Choice, Try Again!." << endl;
			}

		} while (option != 1 && option != 2);
		//getting correct input of RoomType variable 
		do
		{
			cout << "\t Room Type: " << endl;
			cout << "\t\t 1.Single Bed. " << endl;
			cout << "\t\t 2.Double Bed.  ";
			cin >> option;
			switch (option)
			{
			case 1:
				roomType = 1;
				break;

			case 2:
				roomType = 2;
				break;

			default:
				cout << "\tWrong Choice, Try Again!." << endl;
			}
		} while (option != 1 && option != 2);
		cout << "\t Daily Rent: ";
		cin >> DailyRent;
		room[numOfRoom].roomStatus = 1;//true Which indicate its available 
		numOfRoom++;
		system("cls");
		cout << "\n\tRoom Added Successfully!" << endl;

	}
}
//show Record
void Room::show(int roomFoundatIndex) {
	cout << "\t----------" << endl;
	if (room[roomFoundatIndex].roomStatus == 0)
		cout << "\tRoom is Reserved " << endl;
	else
		cout << "\tRoom is Available " << endl;

	if (room[roomFoundatIndex].isVip == true)
		cout << "\tRoom is Vip " << endl;
	else
		cout << "\tRoom is normal." << endl;
	if (room[roomFoundatIndex].roomType == 1)
		cout << "\tRoom is Single Bed " << endl;
	else
		cout << "\tRoom is Double Bed" << endl;
	cout << "\tRoom Number= " << room[roomFoundatIndex].RoomNumber << endl;
	cout << "\tDaily Rent= " << room[roomFoundatIndex].DailyRent << " $" << endl;
	cout << "\t----------" << endl;


}
//search Room
int Room::searchRoom(int rn) {
	int flag = -1;
	//	cout << "\n\t*****Search Room*****" << endl;

	for (i = 0; i < numOfRoom; i++)
	{
		if (room[i].RoomNumber == rn)
		{
			flag = i;
		}
	}
	if (flag != -1)
	{
		return flag;
	}
	else
		return -1;
}
/* Manage Room
		it has  tree fuction which  is
	1- add room
	2- seacrh room
*/
void HotelMangment::ManageRoom() {
	do {
		cout << "\n\t 1.Add Rooms" << endl;
		cout << "\t 2.Search Room" << endl;
		cout << "\t 3.Back To Main menu" << endl;
		cout << "\t Enter Option: ";
		cin >> option;

		switch (option)
		{
		case 1:
			//cout << "\tADD ROOM" << endl;
			if (numOfRoom < 10)// it will  not allow to add more then  10 room
			{
				room[numOfRoom].getInfo();
			}
			else
				cout << "\tsorry there is no space for adding new room" << endl;
			break;
		case 2:
			cout << "\tSearch Room" << endl;
			cout << "\t Enter Room Number: ";
			cin >> rn;
			roomFoundatIndex = room->searchRoom(rn);
			if (roomFoundatIndex != -1)
			{
				system("cls");
				cout << "\n\t*****Show Record*****" << endl;
				room->show(roomFoundatIndex);
			}

			else
				cout << "\t Room is not Founded" << endl;
			break;
		case 3:
			//nothing 
			break;
		default:
			cout << "\tWrong Choice, Try Again!." << endl;
			break;
		}
	} while (option != 3);
}
// Booking
void HotelMangment::Booking() {


	cout << "\n\t*****Booking*****" << endl;
	cout << "\t Enter Room Number: ";
	cin >> rn;
	roomFoundatIndex = room->searchRoom(rn);
	if (roomFoundatIndex != -1)
	{
		if (room[roomFoundatIndex].roomStatus == 1) {
			cout << "\n\t*****Guest Information*****" << endl;
			cout << "\tRoom is available " << endl;
			room[roomFoundatIndex].getGuestInfo(roomFoundatIndex);
			cout << "\n\tRoom Booked Successfully!" << endl;
			room[roomFoundatIndex].roomStatus = 0;
		}
		else
			cout << "\tRoom is already reserved" << endl;
	}
	else
		cout << "\t Room is not Founded" << endl;

}
//show all available rooms
void HotelMangment::AvailableRoom() {
	int flag = -1;
	//cout << "\n\t*****Show All Available Rooms*****" << endl;
	for (i = 0; i < numOfRoom; i++)
	{
		if (room[i].roomStatus == 1)
		{

			room->show(i);


			//cout << "\tPress Enter for Next Room "<<endl;
			getch();//it will hold screen for somemoment 
			flag = 0;
		}
	}
	if (flag == -1)
		cout << "\tAll Rooms Are Reserved. ";

}
//search gust 
void HotelMangment::SearchGuest() {
	char nameForSearch[20];//name for searching
	int flag = -1;
	//cout << "\n\t*****Search Guest*****" << endl;
	//Look that there is guest in the hotel or all rooms are free
	for (i = 0; i < numOfRoom; i++)
	{
		if (room[i].roomStatus == 0)
			flag = 0;
	}
	if (flag != 0)
		cout << "\tAll rooms are free, there is no Guest." << endl;

	else// so we have a guest in the  hotel

	{
		flag = -1;//Initialized again ,so the last value of it will gone;  
		cout << "\t Enter the Name: ";
		cin.ignore(20, '\n');//now get the name and search  
		cin.getline(nameForSearch, 20);
		for (i = 0; i < numOfRoom; i++)
		{
			if (room[i].roomStatus == 0 && strcmp(room[i].Name, nameForSearch) == 0)
			{
				//strcmp fucntion whill check if both name are same or not 
				cout << "\t----------" << endl;
				cout << "\tGust Name: " << room[i].Name << endl;
				cout << "\tRoom Number: " << room[i].RoomNumber << endl;
				cout << "\t----------" << endl;
				flag = 0;
				getch();
			}
		}
		if (flag != 0)
			cout << "\t Person is not found. " << endl;
	}
}
//Clearing the guest 
void HotelMangment::Clearing()
{
	int numberOfDay;
	int billOmount;
	int flag = -1;
	//Look that there is guest in the hotel or all rooms are free
	for (i = 0; i < numOfRoom; i++)
	{
		if (room[i].roomStatus == 0)
			flag = 0;
	}
	if (flag != 0)

		cout << "\tAll rooms are free, there is no Guest." << endl;

	else
	{
		cout << "\tEnter Room Number: ";
		cin >> rn;
		roomFoundatIndex = room->searchRoom(rn);//look if the room is exicting
		if (roomFoundatIndex != -1)
		{
			if (room[roomFoundatIndex].roomStatus == 0)// if this room is reserved so do clearing 
			{
				cout << "\tEnter Number of Days: ";
				cin >> numberOfDay;
				billOmount = numberOfDay * room[roomFoundatIndex].DailyRent;
				billOmount = billOmount - room[roomFoundatIndex].AdvancedPayment;
				room->guestShow(roomFoundatIndex);
				cout << "\tTotal Bill= " << billOmount << " $ only. " << endl;
				cout << "\t----------" << endl;

				room[roomFoundatIndex].roomStatus = 1;
				room->removeTheRecord(roomFoundatIndex);
			}
			else
				cout << "\t This Room is free, no Guest is there. " << endl;
		}

		else
			cout << "\t Room is not Founded" << endl;
	}
}
// show the record of guest which are in the rooms 
void HotelMangment::GuestSummaryReport() {
	int flag = -1;
	for (i = 0; i < numOfRoom; i++)
	{
		if (room[i].roomStatus == 0)
		{
			room->guestShow(i);
			flag = 0;
		}
	}
	if (flag != 0)
		cout << "\tAll rooms are free, there is no Guest." << endl;
}

int main()
{
	//use do while loop for iterate
	do {
		cout << "\n\t*****Hotel Managment Saystem*****" << endl;
		cout << "\t 1.Manage Rooms" << endl;
		cout << "\t 2.Check-In Room(booking)" << endl;
		cout << "\t 3.Available Rooms" << endl;
		cout << "\t 4.Search Guest" << endl;
		cout << "\t 5.Check-Out Room(clearing)" << endl;
		cout << "\t 6.Guest Summary Report" << endl;
		cout << "\t 7.Exit" << endl;
		cout << "\t Enter Option: ";
		cin >> option;
		cout << endl;
		//switch option
		switch (option)
		{
		case 1:
			system("cls");
			cout << "\n\t*****Manage Rooms*****" << endl;
			room[numOfRoom].ManageRoom();
			break;
		case 2:
			system("cls");
			cout << "\n\t*****Check-In Room(booking)*****" << endl;
			if (numOfRoom == 0)
				cout << "\tRooms data is not available.\n\tPlease add the rooms first" << endl;
			else
				room->Booking();

			break;
		case 3:
			system("cls");
			cout << "\n\t*****Show All Available Rooms*****" << endl;

			if (numOfRoom == 0)
				cout << "\tRooms data is not available.\n\tPlease add the rooms first" << endl;
			else
				room->AvailableRoom();
			break;
		case 4:
			system("cls");
			cout << "\n\t*****Search Guest*****" << endl;
			if (numOfRoom == 0)
				cout << "\tRooms data is not available.\n\tPlease add the rooms first" << endl;
			else
				room->SearchGuest();
			break;
		case 5:
			system("cls");
			cout << "\n\t*****Check-Out Room(clearing)*****" << endl;

			if (numOfRoom == 0)
				cout << "\tRooms data is not available.\n\tPlease add the rooms first" << endl;
			else
				room->Clearing();
			break;
		case 6:
			system("cls");
			cout << "\n\t*****Guest Summary Report*****" << endl;

			if (numOfRoom == 0)
				cout << "\tRooms data is not available.\n\tPlease add the rooms first" << endl;
			else
				room->GuestSummaryReport();
			break;
		case 7:
			system("cls");
			cout << "\tThank You For using Software." << endl;
			break;
		default:
			system("cls");
			cout << "\tWrong Choice, Try Again!." << endl;
			break;
		}
	} while (option != 7);
	//system("puase");
	return 0;
}