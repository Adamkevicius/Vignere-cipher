// Antroji praktinė užduotis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int main()
{
	//kodo pradzia
	char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	string tekstas;
	string raktas;
	int teksto_indeksai[300];
	int x;
	cout << "Pasirinkite funkcija: 1.Sifravimas" << endl;
	cout << right << setw(36) << "2.Desifravimas" << endl;
	cout << right << setw(48) << "3.Sifravimas ASCII koduote" << endl;
	cout << right << setw(50) << "4.Desifravimas ASCII koduote" << endl;
	cin >> x;
	if (x != 1 and x != 2 and x != 3 and x != 4) {
		cout << "Klaida" << endl;
		exit(0);
	}
	cout << "Iveskite teksta - ";
	cin >> tekstas;
	for (int i = 0; i < tekstas.length(); i++) {
		tekstas[i] = toupper(tekstas[i]); // Didziosios raides

	}
	//cout << tekstas << endl;
	//cout << sizeof(alphabet) << endl; // Masyvo dydis
	for (int i = 0; i < tekstas.length(); i++) {
		//cout << tekstas[i] << endl;
		for (int j = 0; j < sizeof(alphabet); j++) {
			if (alphabet[j] == tekstas[i]) {
				//cout << "Pozicija: " << j << endl; // suzinome indeksu pozicijas
				teksto_indeksai[i] = j; // issaugom indeksus
			}
		}
	}
	for (int i = 0; i < tekstas.length(); i++) {
		//cout << indeksai[i] << endl; //indeksu pozicijos
	}
	//kartojam veiksmus su raktu
	cout << "Iveskite slaptaji rakta - ";
	cin >> raktas;
	for (int i = 0; i < raktas.length(); i++) {
		raktas[i] = toupper(raktas[i]);
	}
	//cout << raktas << endl;
	//sulyginam testksto ir rakto ilgi
	string naujas_raktas;
	for (int i = 0, j = 0; i < tekstas.length(); i++) {
		if (j < raktas.length()) {
			naujas_raktas += raktas[j];
			j++;
		}
		else {
			j = 0;
			naujas_raktas += raktas[j];
			j++;
		}


	}
	//naujo rakto indekesu pozicijos
	int naujo_rakto_indeksai[300];
	for (int i = 0; i < naujas_raktas.length(); i++) {
		for (int j = 0; j < sizeof(alphabet); j++) {
			if (alphabet[j] == naujas_raktas[i]) {
				naujo_rakto_indeksai[i] = j;
			}
		}
	}


	//cout << naujas_raktas << endl;

	// Sifravimas
	string uzsifruotas_tekstas;
	int uzsifruoto_teksto_indeksai[300];
	if (x == 1) {

		for (int i = 0; i < tekstas.length(); i++) {
			uzsifruoto_teksto_indeksai[i] = (teksto_indeksai[i] + naujo_rakto_indeksai[i]) % sizeof(alphabet);
			//cout << "pozicija " << uzsifruoto_teksto_indeksai[i] << endl;


		}
		//Sifruojame teksta
		for (int i = 0; i < tekstas.length(); i++) {
			for (int j = 0; j < sizeof(alphabet); j++) {
				if (j == uzsifruoto_teksto_indeksai[i]) {
					uzsifruotas_tekstas += alphabet[j];

				}
			}
		}
		cout << "Jusu uzsifruotas tekstas - " << uzsifruotas_tekstas << endl;
		return 0;
	}

	//Desifravimas
	string desifruotas_tekstas;
	int desifruoto_teksto_indeksai[300];
	int mod = 26;
	if (x == 2) {
		for (int i = 0; i < tekstas.length(); i++) {

			desifruoto_teksto_indeksai[i] = (teksto_indeksai[i] - naujo_rakto_indeksai[i] + mod) % sizeof(alphabet);
			//cout << "pozicija " << desifruoto_teksto_indeksai[i] << endl;

		}
		// Desifruojame teksta
		for (int i = 0; i < tekstas.length(); i++) {
			for (int j = 0; j < sizeof(alphabet); j++) {
				if (j == desifruoto_teksto_indeksai[i]) {
					desifruotas_tekstas += alphabet[j];


				}
			}
		}
		cout << "Jusu desifruotas tekstas - " << desifruotas_tekstas << endl;

		return 0;
	}
	//acii
	int ascii_sifravimas;
	char ascii_tekstas[300];
	
	if (x == 3) {
		for (int i = 0; i < tekstas.length(); i++) {
			ascii_sifravimas = ((int(tekstas[i]) + int(naujas_raktas[i])) % 26);
			ascii_tekstas[i] = alphabet[ascii_sifravimas];
			cout << "Jusu uzsifruotas ASCII tekstas - " << ascii_tekstas[i];
			
			
		}
		cout << endl;
	}
	
	//ascii desifravimas
	int ascii_desifravimas;
	char ascii_desifruotas_tekstas[300];

	if (x == 4) {
		for (int i = 0; i < tekstas.length(); i++) {
			ascii_desifravimas = ((int(tekstas[i]) - int(naujas_raktas[i]) + 26) % 26);
			ascii_desifruotas_tekstas[i] = alphabet[ascii_desifravimas];
			cout<<"Jusu desifruotas ASCII tekstas - " << ascii_desifruotas_tekstas[i];
		}
		cout << endl;


	}


	return 0;
		
			
		
}
	
	
