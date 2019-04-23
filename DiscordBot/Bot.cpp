#include "Bot.h"
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json.hpp>
#include <vector>

using namespace Bot;
using namespace nlohmann;


// Public

void DiscordBot::test() 
{
	std::cout << "start test";
	send_message("493843755015864330", "test");
	std::cout << "test done";
}

void DiscordBot::bot_main() 
{
	std::cout << "Main Started" << std::endl;
	while(running)
	{
		/*
			Main loop
		*/
		//TODO get the unread messages and put them into a q
		std::string top_msg;
		for(module umodule : modules)
		{
			std::string name = umodule.get_module_name();
			std::cout << name << std::endl;
		}
	}
	std::cout << "shut down" << std::endl;
}

void DiscordBot::shut_down()
{
	std::cout << "shutting down" << std::endl;
	running = false;
}

// Constructor

DiscordBot::DiscordBot()
{
	std::cout << "Default Constructor" << std::endl;
	running = true;
}

DiscordBot::DiscordBot(int server_port, std::string server)
{
	server_addr = { server_port,server };
	std::cout << "Spesific Constructor" << std::endl;
	std::cout << server_addr.port << std::endl;
	std::cout << server_addr.url << std::endl;
	running = true;
}

DiscordBot::DiscordBot(std::string base_addr, std::string bot_sec, std::string ser_id, std::vector<std::string>mon_channels, std::vector<module>used_modules)
{
	bot_secret = bot_sec;
	base_url = base_addr;
	server_id = ser_id;
	monitored_channels = mon_channels;
	running = true;
	std::cout << "Bot obj created" << std::endl;
}

// Private

int DiscordBot::send_message(std::string channel_id, std::string msg)
{
	std::string path = "/channels/" + channel_id + "/messages";
	std::cout << path << std::endl;
	json j_msg;
	j_msg["content"] = msg;
	j_msg["tts"] = false;
	std::string str_msg = j_msg.dump();
	
	CURL* curl;
	CURLcode res;
	
	curl = curl_easy_init();
	if(curl)
	{
		struct curl_slist* chunk = NULL;
		std::string auth_header = "Authorization: Bot " + bot_secret;
		std::string cont_header = "Content-Type: application/json";
		chunk = curl_slist_append(chunk,auth_header.c_str());
		chunk = curl_slist_append(chunk, cont_header.c_str());
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
		curl_easy_setopt(curl, CURLOPT_URL, base_url + path);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, str_msg);
		
		res = curl_easy_perform(curl);

		if(res != CURLE_OK)
		{
			curl_easy_cleanup(curl);
			std::cout << "curl perform failed due to error: " << curl_easy_strerror(res) << std::endl;
			return 1;
		}
		else
		{
			curl_easy_cleanup(curl);
			std::cout << "curl perform success" << std::endl;
			return 0;
		}
		
	}
	else
	{
		std::cout << "Failed to send message" << std::endl;
		return 1;
	}
}
