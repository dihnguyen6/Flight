#include "flightplan.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip> // needed to use setw

using namespace std;

_FLIGHTPLAN::_FLIGHTPLAN(void)
	: flights(0), FLIGHTLEG(NULL)
{
	// this is an empty constructor
}

_FLIGHTPLAN::_FLIGHTPLAN(char _flightplanname[256], int _number_of_flights)
{
	// this is the constructor used for a _FLIGHTPLAN_NEW object
	// initialize the attributes
	this->flights = _number_of_flights;
	strcpy(this->flightplanname, _flightplanname);
	
	// reserve memory for the flights to be saved
	FLIGHTLEG = new _FLIGHTLEG[this->flights];
	  
	// addings flights one after another
	_FLIGHTLEG *F;
	
	F = new _FLIGHTLEG(100, string("CDG"), 360, string("DRS"), 440, 540, 8, 2);
	this->add_flight(F);
	delete F;
	
	F = new _FLIGHTLEG(101, string("CDG"), 520, string("DRS"), 600, 490, 8, 4);
	this->add_flight(F);
	delete F;
	
	F = new _FLIGHTLEG(102, string("CDG"), 1290, string("DRS"), 1370, 550, 12, 3);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(103, string("DRS"), 380, string("CDG"), 460, 540, 8, 4);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(104, string("DRS"), 1150, string("CDG"), 1230, 480, 12, 3);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(105, string("DRS"), 1290, string("CDG"), 1370, 530, 8, 2);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(106, string("CPH"), 600, string("DRS"), 670, 710, 12, 1);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(107, string("CPH"), 1180, string("DRS"), 1250, 580, 8, 2);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(108, string("DRS"), 480, string("CPH"), 550, 650, 12, 1);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(109, string("DRS"), 1060, string("CPH"), 1130, 660, 8, 2);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(110, string("DRS"), 480, string("FCO"), 550, 440, 8, 2);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(111, string("DRS"), 930, string("FCO"), 1000, 440, 12, 3);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(112, string("DRS"), 1320, string("FCO"), 1390, 470, 8, 4);
	this->add_flight(F);
	F = NULL;

	F = new _FLIGHTLEG(113, string("FCO"), 590, string("DRS"), 660, 520, 8, 2);
	this->add_flight(F);
	F = NULL;

	F = new _FLIGHTLEG(114, string("FCO"), 1040, string("DRS"), 1110, 500, 12, 3);
	this->add_flight(F);
	F = NULL;

	F = new _FLIGHTLEG(115, string("DRS"), 700, string("IST"), 840, 760, 8, 2);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(116, string("IST"), 880, string("DRS"), 1020, 740, 8, 2);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(117, string("DRS"), 640, string("LHR"), 730, 430, 8, 4);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(118, string("DRS"), 1120, string("LHR"), 1210, 450, 12, 1);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(119, string("LHR"), 390, string("DRS"), 480, 455, 12, 3);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(120, string("LHR"), 780, string("DRS"), 870, 430, 8, 4);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(121, string("LHR"), 1260, string("DRS"), 1350, 400, 12, 1);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(122, string("DRS"), 520, string("SVO"), 680, 810, 12, 3);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(123, string("DRS"), 710, string("SVO"), 870, 790, 12, 1);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(124, string("DRS"), 910, string("SVO"), 1070, 770, 8, 4);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(125, string("SVO"), 730, string("DRS"), 890, 750, 12, 3);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(126, string("SVO"), 920, string("DRS"), 1080, 600, 12, 1);
	this->add_flight(F);
	F = NULL;
	
	F = new _FLIGHTLEG(127, string("SVO"), 1120, string("DRS"), 1280, 630, 8, 4);
	this->add_flight(F);
	F = NULL;
	
	//printf("The flightplan with name %s has been setup\n", this‐>flightplanname);
	
}

_FLIGHTPLAN::~_FLIGHTPLAN(void)
{
	// this is the destructor used for a _FLIGHTPLAN object
	
	// delete the flightplan
	delete[] FLIGHTLEG;
}
 
void _FLIGHTPLAN::add_flight(struct _FLIGHTLEG *FLIGHT)
{

	// start to find out if there is an empty array field available to store FLIGHTLEG FLIGHT
	int new_pos = 10000;
	int i;
	for (i = 0; i < this->flights; i++)
	{
		if (this->FLIGHTLEG[i].flight_num < 0)
		{
			new_pos = i;
			break;
		}
	}
	
	if (new_pos < this->flights)
	{
		// there are still unused flights in the flightplan
		this->FLIGHTLEG[new_pos].flight_num = FLIGHT->flight_num;
		
		this->FLIGHTLEG[new_pos].ORIG_APT = FLIGHT->ORIG_APT;
		this->FLIGHTLEG[new_pos].DEST_APT = FLIGHT->DEST_APT;
		
		this->FLIGHTLEG[new_pos].dept_minute = FLIGHT->dept_minute;
		this->FLIGHTLEG[new_pos].arr_minute = FLIGHT->arr_minute;
		this->FLIGHTLEG[new_pos].fare = FLIGHT->fare;
		this->FLIGHTLEG[new_pos].seats = FLIGHT->seats;
		this->FLIGHTLEG[new_pos].ac_id = FLIGHT->ac_id;
	}
	else
	{
		// no unused flights available in the flightplan: reserve more memory
		// printf("Not enough memory ‐ going to reserve more!\n");
		
		// 1.) save existing flights
		_FLIGHTLEG *OLDFLIGHTLEG;
		OLDFLIGHTLEG = new _FLIGHTLEG[this->flights];
		for (i = 0; i < this->flights; i++)
		{
			OLDFLIGHTLEG[i] = this->FLIGHTLEG[i];
		}
		
		// 2.) destroy existing array _FLIGHTLEG
		delete[] this->FLIGHTLEG;
		  
		// 3.) re‐allocated enough memory for array _FLIGHTLEG to store one more flight
		this->FLIGHTLEG = new _FLIGHTLEG[this->flights + 1];
	 
		// 4.) restore the save FLIGHTLEGs
		for (i = 0; i < this->flights; i++)
		{
			this->FLIGHTLEG[i] = OLDFLIGHTLEG[i];
		}
		  
		// 5.) save the additional flight
		this->FLIGHTLEG[this->flights].flight_num = FLIGHT->flight_num;
		this->FLIGHTLEG[this->flights].ORIG_APT = FLIGHT->ORIG_APT;
		this->FLIGHTLEG[this->flights].DEST_APT = FLIGHT->DEST_APT;
	  
		this->FLIGHTLEG[this->flights].dept_minute = FLIGHT->dept_minute;
		this->FLIGHTLEG[this->flights].arr_minute = FLIGHT->arr_minute;
		this->FLIGHTLEG[this->flights].fare = FLIGHT->fare;
		this->FLIGHTLEG[this->flights].seats = FLIGHT->seats;
		this->FLIGHTLEG[this->flights].ac_id = FLIGHT->ac_id;
	  
		// 6.) increase the number of stored flightlegs
		this->flights++;
		// 7.) release the temporary array
		delete[] OLDFLIGHTLEG;
	 }
}
 

void _FLIGHTPLAN::print()
{
	int i;
	printf("We have %d flights\n", this->flights);
	
	for (i = 0; i < this->flights; i++)
	{
		this->FLIGHTLEG[i].print();
	}
}



int _FLIGHTPLAN::apstrToIndex(const string & name)
{
	for (int i = 0; i < 7; i++)
		if (name == indexToApstr(i))
			return i;

	return -1;
}

const string& _FLIGHTPLAN::indexToApstr(int index)
{
	// static vor Variablen innerhalb von Funktionen/Methoden bedeutet:
	// die Variable wird nur beim ersten Funktionsaufruf deklariert und initialisiert
	// die Adresse/Referenz der Variable darf von der Funktion zurückgegeben werden
	static const string empty = "";
	static const string cities[] = { "DRS","CPH","SVO","LHR","CDG","FCO","IST" };

	// Fehlerhaften Input abfangen
	if (index < 0 || index >6)
		return empty;

	return cities[index];
}

void _FLIGHTPLAN::printNetworkData(const int matrix[7][7], string title)
{
	// Hier: Code zur Erstellung einer tabellarischen Ausgabe
	for (int i = 0; i < 7; i++) // Tabellenkopf
	{
		cout << "\t" << indexToApstr(i);
	}
	cout << endl;


	for (int i = 0; i < 7; i++)  // äußere Schleife Zeilen
	{
		cout << indexToApstr(i) << "\t";

		for (int j = 0; j < 7; j++) // innere Schleife Spalten
		{
			cout << matrix[i][j] << "\t"; // geht in Zeile 1 alle Spalten durch, springt dann wieder in die äußere Schleife, dadurch springt es in 2. Zeile und geht wieder alle dazugehörigen Spalten durch
		}
		cout << endl;
	}
}


