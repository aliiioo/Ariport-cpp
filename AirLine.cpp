//// AirLine.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
#include<stdio.h>
#include <iostream>
#include<map>
#include<string>
#include<math.h>
#include<stdlib.h>

using namespace std;

class flight
{
private:
	string time;
	string model;
	string type;
	int passengers;
	int runway;
	int flight_number;
	int id;
	flight* nextFlight = nullptr;
	flight* previousNode = nullptr;
public:
	flight(string TT, string MO, string TY, int PASS, int RUN, int FLI, int I)
	{
		time = TT;
		model = MO;
		type = TY;
		passengers = PASS;
		runway = RUN;
		flight_number = FLI;
		id = I;
	}
	flight(string TT, string MO, int PASS, int FLI, int I)
	{
		time = TT;
		model = MO;
		type = "out";
		passengers = PASS;
		flight_number = FLI;
		id = I;
	}
	void settime(string ti)
	{
		time = ti;
	}
	void setmodel(string md)
	{
		model = md;
	}
	void settype(string ty)
	{
		type = ty;
	}
	void setpass(int pas)
	{
		passengers = pas;
	}
	void setrunway(int run)
	{
		runway = run;
	}
	void setflghit_N(int fl_n)
	{
		flight_number = fl_n;
	}
	void setid(int idd)
	{
		id = idd;
	}
	//////////////////////////
	void setnextfli(flight* Nnextflight)
	{
		nextFlight = Nnextflight;
	}
	void setprifli(flight* Privflightt)
	{
		previousNode = Privflightt;
	}
	flight* getprevfli()
	{
		return previousNode;
	}
	flight* getnextflight()
	{
		return nextFlight;
	}
	////////////////////
	string gettime()
	{
		return time;
	}
	string getmodel()
	{
		return model;
	}
	string gettype()
	{
		return type;
	}
	int getpassenger()
	{
		return passengers;
	}
	int getrunway()
	{
		return runway;
	}
	int getflight_number()
	{
		return flight_number;
	}
	int getid()
	{
		return id;
	}
};

class Airport
{
private:
	flight* first;
	int number_of_flights;
public:
	map <string, int> airplane_size;
	double runways[50][6] = { 0 };

	Airport()
	{
		runways[0][0] = 0;
		runways[1][0] = 0.3;
		runways[2][0] = 1;
		runways[3][0] = 1.3;
		runways[4][0] = 2;
		runways[5][0] = 2.3;
		runways[6][0] = 3;
		runways[7][0] = 3.3;
		runways[8][0] = 4;
		runways[9][0] = 4.3;
		runways[10][0] = 5;
		runways[11][0] = 5.3;
		runways[12][0] = 6;
		runways[13][0] = 6.3;
		runways[14][0] = 7;
		runways[15][0] = 7.3;
		runways[16][0] = 8;
		runways[17][0] = 8.3;
		runways[18][0] = 9;
		runways[19][0] = 9.3;
		runways[20][0] = 10;
		runways[21][0] = 10.3;
		runways[22][0] = 11;
		runways[23][0] = 11.3;
		runways[24][0] = 12;
		runways[25][0] = 12.3;
		runways[26][0] = 13;
		runways[27][0] = 13.3;
		runways[28][0] = 14;
		runways[29][0] = 14.3;
		runways[30][0] = 15;
		runways[31][0] = 15.3;
		runways[32][0] = 16;
		runways[33][0] = 16.3;
		runways[34][0] = 17;
		runways[35][0] = 17.3;
		runways[36][0] = 18;
		runways[37][0] = 18.3;
		runways[38][0] = 19;
		runways[39][0] = 19.3;
		runways[40][0] = 20;
		runways[41][0] = 20.3;
		runways[42][0] = 21;
		runways[43][0] = 21.3;
		runways[44][0] = 22;
		runways[45][0] = 22.3;
		runways[46][0] = 23;
		runways[47][0] = 23.3;
		runways[48][0] = 24;
	}
	void mppaa()
	{
		while (true)
		{

			string a;
			cout << "Enter --<model & Runway>-- <end>  \n";
			cin >> a;
			if (a == "end")
			{
				break;
			}
			int Rn;
			cin >> Rn;
			airplane_size[a] = Rn;
		}
		cout << "\nhere is list of in map\n";
		for (auto it = airplane_size.begin(); it != airplane_size.end(); it++)
		{
			cout << (*it).first << "  " << (*it).second << "\n";
		}
		cout << endl;
	}
	double Timer(string TT)
	{
		double z;
		string za = "000";
		int tr = 0;
		bool TT_1 = true, TT_2 = true;
		for (int nm = 0; nm < 5; nm++)
		{
			za[nm] = TT[nm];
			if (TT[nm] == ':' && TT[nm + 1] != '0')
			{
				za[nm] = 9;
				TT_1 = false;
			}
			if (TT_1 == false)
			{
				z = stof(za);
				z = z + 0.30;
				return z;
			}
			if (TT[nm] == ':' && TT[nm + 1] == '0')
			{
				za[nm] = 0;
				TT[nm] = '.';
				TT_2 = false;
			}
			if (TT_2 == false)
			{
				z = stof(za);
				return z;
			}
		}

	}
	void insert_1(string TT, string MO, string TY, int PASS, int RUN, int FLI, int I)
	{
		bool T_4 = true, T_5 = true;
		double z;
		int run_r = RUN;
		int RUN_1 = RUN;
		z = Timer(TT);
		for (int i = 0; i < 49; i++)
		{
			
			if (runways[i][0] == z)
			{
				T_4 = false;
				if (runways[i][RUN] == 0)
				{
					runways[i][RUN] = 1;
					T_5 = false;
					break;
				}
				while (run_r < 5)
				{
					run_r++;
					RUN_1++;
					if (runways[i][run_r] == 0)
					{
						runways[i][run_r] = 1;
						T_5 = false;
						break;						
					}
					
				}
				if (T_5==false)
				{
					RUN = RUN_1;
				}
				if (T_5 == false)
				{
					break;
				}
				run_r = RUN;
				int kl = i;
				int hi = 0;
				bool T_3 = true;
				while (kl < 49)
				{
					hi++;
					while (run_r < 6)
					{
						if (runways[kl + 1][run_r] == 0)
						{
							runways[kl + 1][run_r] = 1;
							char Tt[48][10] = { "0:00","0:30","1:00","1:30","2:00","3:00","3:30","4:00","4:30","5:00","5:30","6:00","6:30",
							"7:00","7:30","8:00","8:30","9:00","9:30","10:00","10:30","11:00","11:30","12:00","12:30","13:00","13:30","14:00",
							"14:30","15:00","15:30","16:00","16:30","17:00","17:30","18:00","18:30","19:00","19:30","20:00","20:30","21:00","21:30",
							"22:00","22:30","23:00","23:30" };
							for (int jj = 0; jj < 48; jj++)
							{
								if (TT == Tt[jj])
								{
									TT = Tt[jj + hi];
									break;
								}
							}
							T_3 = false;
							break;
						}
						run_r++;
					}
					if (T_3 == false)
					{
						break;
					}
					run_r = RUN;
					kl++;
				}
			}
			if (T_4 == false)
			{
				break;
			}
		}

		flight* temp = new flight(TT, MO, TY, PASS, RUN, FLI, I);
		temp->setnextfli(first);
		first = temp;
		airplane_size[MO] = RUN;
	}
	void insert_2(string TT, string MO, int PASS, int FLI, int I)
	{
		bool T_4 = true;
		double z;
		z = Timer(TT);
		int Runii;
		for (auto it = airplane_size.begin(); it != airplane_size.end(); it++)
		{
			if ((*it).first == MO)
			{
				/*cout << "Model = " << (*it).first << "\t Runway =" << (*it).second;*/
				Runii = (*it).second;
			}
		}
		bool T_5 = true;
		int run_r = Runii;
		for (int i = 0; i < 49; i++)
		{
			if (runways[i][0] == z)
			{
				T_4 = false;
				if (runways[i][Runii] == 0)
				{
					runways[i][Runii] = 1;
					T_5 = false;
					break;
				}
				while (run_r < 6)
				{
					if (runways[i][run_r] == 0)
					{
						runways[i][run_r] = 1;
						T_5 = false;
						break;
					}
					run_r++;
				}
				if (T_5 == true)
				{


					run_r = Runii;
					int kl = i;
					int hi = 0;
					bool T_3 = true;
					while (kl < 49)
					{
						hi++;
						while (run_r < 6)
						{
							if (runways[kl + 1][run_r] == 0)
							{
								runways[kl + 1][run_r] = 1;
								char Tt[48][10] = { "0:00","0:30","1:00","1:30","2:00","3:00","3:30","4:00","4:30","5:00","5:30","6:00","6:30",
								"7:00","7:30","8:00","8:30","9:00","9:30","10:00","10:30","11:00","11:30","12:00","12:30","13:00","13:30","14:00",
								"14:30","15:00","15:30","16:00","16:30","17:00","17:30","18:00","18:30","19:00","19:30","20:00","20:30","21:00","21:30",
								"22:00","22:30","23:00","23:30" };
								for (int jj = 0; jj < 48; jj++)
								{
									if (TT == Tt[jj])
									{
										TT = Tt[jj + hi];
										break;
									}
								}
								T_3 = false;
								break;
							}
							run_r++;
						}
						run_r = Runii;
						kl++;
						if (T_3 == false)
						{
							break;
						}

					}
				}
			}
			if (T_4 == false)
			{
				break;
			}
		}
		flight* temp_2 = new flight(TT, MO, PASS, FLI, I);
		temp_2->settype("out");
		temp_2->setnextfli(first);
		temp_2->setrunway(Runii);
		first = temp_2;
	}
	void print()
	{
		bool go = true, n_g = true;
		int num_r;
		cin >> num_r;
		flight* temp = first;
		while (true)
		{
			if (temp == NULL)
			{
				break;
			}
			if ((int)temp->getrunway() == (int)num_r)
			{
				n_g = false;
				int r;
				cout << "\nModel : " << temp->getmodel()
					<< "\nTime : " << temp->gettime()
					<< "\nRunway : ";
				r = temp->getrunway();
				
				string timee = temp->gettime();
				double sata = Timer(timee);
				sata *= 2;
				sata = round(sata);
				int runy = temp->getrunway();
				int dot = 0;
				for (int iii = 0; iii < 5; iii++)
				{
					if (r < 6)
					{
						if (dot == 0)
						{
							if ((int)runways[(int)sata][r] >= (int)0)
							{
								cout << r << " , ";
							}
							dot++;
						}
						else
						{
							if ((int)runways[(int)sata][r] == (int)0)
							{
								cout << r << " , ";
							}
						}
					}
					if (r >= 6)
					{
						break;
					}
					r++;
				}
				cout << endl;				
			
				temp = temp->getnextflight();
			}
			else
			{
				temp = temp->getnextflight();
								
				if (temp== NULL)
				{
					if (num_r != 0)
					{
						cout << "Not found  any fly \n";
					}
					go = false;
					break;
				}
				
			}
		}
		if (n_g == true)
		{
			if (go == false)
			{
				flight* ttm = first;
				if (!ttm)
				{
					cout << "Empty ";
				}
				int rr;
				while (ttm)
				{
					cout << "\nID : " << ttm->getid() << endl << "Time : " << ttm->gettime()
						<< "\tmodel : " << ttm->getmodel() << "\tType : " << ttm->gettype()<< "\tRunway : ";
					rr = ttm->getrunway();
					
					string timee = ttm->gettime();
					double sata = Timer(timee);
					sata *= 2;
					sata = round(sata);
					int runy = ttm->getrunway();
					int dot = 0;
					for (int iiii = 0; iiii < 5; iiii++)
					{
						if (rr < 6)
						{
							if (dot == 0)
							{
								if ((int)runways[(int)sata][rr] >= (int)0)
								{
									cout << rr << " , ";
								}
								dot++;
							}
							else
							{
								if ((int)runways[(int)sata][rr] == (int)0)
								{
									cout << rr << " , ";
								}
							}
						}
						if (rr >= 6)
						{
							break;
						}
						++rr;
					}
					ttm = ttm->getnextflight();
				}

				cout << endl << endl;
				cout << "table of Time & Runways\n";
				for (int i = 0; i < 49; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						if (j == 0)
						{
							cout << runways[i][j] << " :\t ";
						}
						else
						{
							cout << runways[i][j] << "\t ";
						}

					}
					cout << endl;
				}
			}
		}
	}
	void deletee(int fl)
	{
		flight* temp = first;

		while (true)
		{
			if (temp->getflight_number() == fl)
			{
				cout << "Delet was sucsessfully\n";
				string TT = temp->gettime();
				int Run_1 = temp->getrunway();
				double z;
				z = Timer(TT);
				for (int i = 0; i < 49; i++)
				{
					if (runways[i][0]==z)
					{
						runways[i][Run_1] = 0;
					}
				}
				*temp = *temp->getnextflight();
				break;
			}
			else
			{
				temp = temp->getnextflight();
			}
			if (temp == NULL)
			{
				cout << "sorry Delet filed\n";
				break;
			}
		}
	}
	void sort()
	{
		flight* i, * j;
		int min, con = 0;
		bool go = true;
		while (true)
		{

			for (i = first; i != NULL; i = i->getnextflight())
			{
				double sata = Timer(i->gettime());
				sata *= 2;
				sata = round(sata);
				min = sata;
				for (j = i->getnextflight(); j != NULL; j = j->getnextflight())
				{
					double sata_2 = Timer(j->gettime());
					sata_2 *= 2;
					sata_2 = round(sata_2);

					if (sata_2 > min)
					{
						int temp = i->getid();
						i->setid(j->getid());
						j->setid(temp);

						int t_fl = i->getflight_number();
						i->setflghit_N(j->getflight_number());
						j->setflghit_N(t_fl);

						int t_pas = i->getpassenger();
						i->setpass(j->getpassenger());
						j->setpass(t_pas);

						int t_run = i->getrunway();
						i->setrunway(j->getrunway());
						j->setrunway(t_run);

						string t_mod = i->getmodel();
						i->setmodel(j->getmodel());
						j->setmodel(t_mod);

						string t_time = i->gettime();
						i->settime(j->gettime());
						j->settime(t_time);

						string t_ty = i->gettype();
						i->settype(j->gettype());
						j->settype(t_ty);

						con++;
					}
				}

			}
			if (con == 0)
			{
				break;
			}
			con = 0;

		}
	}
	flight* searchById(int DI)
	{
		flight* temp = first;
		int R;
		while (true)
		{
			if (temp->getid() == DI)
			{
				cout << "Ok found in flight_Number : " << temp->getflight_number() << endl;
				cout << "you can fly on These Runways --> " << temp->getrunway() << " , ";
				R = temp->getrunway();
				while (true)
				{
					if (R < 5)
					{
						cout << ++R << " , ";
						R++;
					}
					else
					{
						break;
					}
				}
				cout << "\nDo you want to know more information -- <y|n> --\n";
				string ans;
				cin >> ans;
				if (ans == "y")
				{
					cout << "What do you want to Know about Airplan -- < time , model , runway , all> -- ?\n ";
					string Hh;
					while (true)
					{
						cin >> Hh;
						if (Hh == "time")
						{
							cout << temp->gettime() << endl;
						}
						if (Hh == "model")
						{
							cout << temp->getmodel() << endl;
						}
						if (Hh == "runway")
						{
							cout << temp->getrunway() << endl;
						}
						if (Hh == "all")
						{
							cout << "\nOk All informatin :\n";
							cout << "Time : " << temp->gettime();
							cout << "\nModel : " << temp->getmodel();
							cout << "\nRunway : " << temp->getrunway();
							cout << "\nID : " << temp->getid() << endl;
						}
						return 0;
					}
					return temp;
				}
				return 0;
			}
			else
			{
				temp = temp->getnextflight();
			}
			if (temp->getnextflight() == NULL)
			{
				cout << "Not found  any fly \n";
				return 0;
			}
		}
	}
	flight* searchByFlightNumber(int dt)
	{
		flight* temp = first;
		int R;
		while (true)
		{

			if (temp->getflight_number() == dt)
			{
				cout << "Ok found in ID : " << temp->getid() << endl;
				cout << "you can fly on These Runways --> " << temp->getrunway() << " , ";
				R = temp->getrunway();
				while (true)
				{
					if (R < 5)
					{
						cout << ++R << " , ";
						R++;
					}
					else
					{
						break;
					}
				}
				cout << "\nDo you want to know more information -- <y|n> --\n";
				string ans;
				cin >> ans;
				if (ans == "y")
				{
					cout << "\nWhat do you want to Know about Airplan  -- < time , model , runway , all> -- ?\n  ";
					string Hh;
					while (true)
					{
						cin >> Hh;
						if (Hh == "time")
						{
							cout << temp->gettime() << endl;
						}
						if (Hh == "model")
						{
							cout << temp->getmodel() << endl;
						}
						if (Hh == "runway")
						{
							cout << temp->getrunway() << endl;
						}
						if (Hh == "all")
						{
							cout << "\nOk All informatin :\n";
							cout << "Time : " << temp->gettime();
							cout << "\nModel : " << temp->getmodel();
							cout << "\nRunway : " << temp->getrunway();
							cout << "\nID : " << temp->getid() << endl;
						}
						return 0;
					}
					return temp;
				}
				return 0;
			}
			else
			{
				temp = temp->getnextflight();
			}
			if (!(temp->getnextflight()))
			{
				cout << "Not found  any fly \n";
				return 0;
			}
		}
	}
};

void arrive()
{
	string time;
	string model;
	string type;
	int passengers;
	int runway;
	int flight_number;
	int id;
	Airport won;
	cout << "List of Airline is existence \n\n";
	won.mppaa();
	cout << "choice--<insert , Delet , SerchbyID , serchbyFL , sort , print , help , map , end >--";
	while (1)
	{
		cout << "Enter your order\n";
		string a;
		cin >> a;
		if (a == "insert")
		{
			cout << "have a Runway ? (y|n)\n";
			cin >> a;
			if (a == "y")
			{
				cout << "time--<00:00>-- : ";
				cin >> time;
				cout << "Model : ";
				cin >> model;
				cout << "type--<in|out>-- : ";
				cin >> type;
				cout << "passengers : ";
				cin >> passengers;
				cout << "Runway--<1 to 5>--: ";
				cin >> runway;
				cout << "Flight_Number : ";
				cin >> flight_number;
				cout << "id : ";
				cin >> id;
				won.insert_1(time, model, type, passengers, runway, flight_number, id);
			}
			else
			{
				cout << "time--<00:00>-- : ";
				cin >> time;
				cout << "Model : ";
				cin >> model;
				cout << "passengers : ";
				cin >> passengers;
				cout << "Flight_Number : ";
				cin >> flight_number;
				cout << "id : ";
				cin >> id;
				won.insert_2(time, model, passengers, flight_number, id);
			}
			continue;
		}
		if (a == "Delet")
		{
			cout << "which Flight_Number want to remove ?\n";
			int del;
			cin >> del;
			won.deletee(del);
		}
		if (a == "SerchbyID")
		{
			cout << "Enter id \n";
			int id;
			cin >> id;
			won.searchById(id);
		}
		if (a == "serchbyFL")
		{
			cout << "Enter flght_number \n";
			int fl;
			cin >> fl;
			won.searchByFlightNumber(fl);
		}
		if (a == "print")
		{
			won.print();
		}
		if (a == "sort")
		{
			won.sort();
			won.sort();
		}
		if (a == "help")
		{
			int H_h;
			cout << "\ndo you have ---> flightNumber Or ---> id \n";
			cin >> a;
			if (a == "id")
			{
				cout << "enter ID\n";
				cin >> H_h;
				won.searchById(H_h);
			}
			if (a == "flightNumber")
			{
				cout << "enter Flght_Num\n";
				cin >> H_h;
				won.searchByFlightNumber(H_h);
			}
		}
		if (a == "map")
		{
			won.mppaa();
		}
		if (a == "end")
		{
			cout << "bye...";
			break;
		}
	}
}

int main()
{
	system("color 09");
	string manager;
	cout << "\t\t\t\t\tHello welcome to Alfa Airport website \n\n"
		<< "Are you the manager ? <y|n> : ";
	cin >> manager;
	if (manager == "y")
	{
		cout << "\nAdmin access\n\n";
		arrive();
	}
	else if (manager == "n")
	{
		cout << "\n\n the list is Empty\n";
	}
	cout << "By ... ";

}



//
//// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
//// Debug progra//m: F5 or Debug > Start Debugging menu
//
//// Tips for Getting Started: 
////   1. Use the Solution Explorer window to add/manage files
////   2. Use the Team Explorer window to connect to source control
////   3. Use the Output window to see build output and other messages
////   4. Use the Error List window to view errors
////   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
////   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

