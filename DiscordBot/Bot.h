#pragma once
#ifndef DISCORDBOT_H
#define DISCORDBOT_H

#include <string>
#include <vector>
using namespace std;

namespace Bot 
{
	struct addr
	{
		int port;
		string url;
	};

	class DiscordBot 
	{
		public:
			void bot_main();
			DiscordBot();
			DiscordBot(int server_port, string server_addr);
			DiscordBot(string base_addr, string bot_secret, string server_id, vector<string>mon_channel);
			void test();
		private:
			addr server_addr;
			string bot_secret;
			string base_url;
			string server_id;
			vector<string> monitored_channels;
			int send_message(string channel_id,string msg);

			
	};
}
#endif // !DiscordBot