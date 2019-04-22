// DiscordBot.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include <fstream>
#include <iostream>
#include <iostream>
#include <json.hpp>
#include <curl/curl.h>
#include "Bot.h"

using namespace Bot;
using namespace std;
using namespace nlohmann;

int main()
{
	//Config init
	ifstream confreader;
	confreader.open("config.json");
	if (!confreader) 
	{
		// Config fail
		curl_global_cleanup();
		cout << "Failed to read config" << endl;
		return 1;
	}
	else
	{
		json configs;
		confreader >> configs;
		cout << configs["name"] << endl;
		

		// curl global init
		//curl_global_init(CURL_GLOBAL_ALL);

		//Bot::DiscordBot bot(1,"pog");
		//bot.bot_main();
		curl_global_cleanup();
		cout << "Stop" << endl;
		return 0;
	}

}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
