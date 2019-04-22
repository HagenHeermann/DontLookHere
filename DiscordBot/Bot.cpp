#include "Bot.h"
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json.hpp>
#include <vector>

using namespace Bot;
using namespace std;
using namespace nlohmann;


// Public

void DiscordBot::test() 
{
	cout << "start test";
	send_message("493843755015864330", "test");
	cout << "test done";
}

void DiscordBot::bot_main() 
{
	cout << "Main Started" << endl;
	CURL* curl;
	CURLcode res;

	curl = curl_easy_init();
	if (curl) 
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://google.com");
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
		{
			cout << "failed" << endl;
			cout << "error code:" << curl_easy_strerror(res) << endl;
			curl_easy_cleanup(curl);
		}
		else
		{
			cout << "success" << endl;
			curl_easy_cleanup(curl);
		}
	}
}

// Constructor

DiscordBot::DiscordBot()
{
	cout << "Default Constructor" << endl;
}

DiscordBot::DiscordBot(int server_port, std::string server)
{
	server_addr = { server_port,server };
	cout << "Spesific Constructor" << endl;
	cout << server_addr.port << endl;
	cout << server_addr.url << endl;

}

DiscordBot::DiscordBot(string base_addr, string bot_sec, string ser_id,vector<string>mon_channels)
{
	bot_secret = bot_sec;
	base_url = base_addr;
	server_id = ser_id;
	monitored_channels = mon_channels;
	cout << "Bot obj created" << endl;
}

// Private

int DiscordBot::send_message(string channel_id, string msg)
{
	string path = "/channels/" + channel_id + "/messages";
	cout << path << endl;
	json j_msg;
	j_msg["content"] = msg;
	j_msg["tts"] = false;
	string str_msg = j_msg.dump();
	
	CURL* curl;
	CURLcode res;
	
	curl = curl_easy_init();
	if(curl)
	{
		struct curl_slist* chunk = NULL;
		string auth_header = "Authorization: Bot " + bot_secret;
		string cont_header = "Content-Type: application/json";
		chunk = curl_slist_append(chunk,auth_header.c_str());
		chunk = curl_slist_append(chunk, cont_header.c_str());
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
		curl_easy_setopt(curl, CURLOPT_URL, base_url + path);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, str_msg);
		
		res = curl_easy_perform(curl);

		if(res != CURLE_OK)
		{
			curl_easy_cleanup(curl);
			cout << "curl perform failed due to error: " << curl_easy_strerror(res) << endl;
			return 1;
		}
		else
		{
			curl_easy_cleanup(curl);
			cout << "curl perform success" << endl;
			return 0;
		}
		
	}
	else
	{
		cout << "Failed to send message" << endl;
		return 1;
	}
}
