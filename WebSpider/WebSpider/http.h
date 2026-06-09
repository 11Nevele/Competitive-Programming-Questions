#pragma once
#include<winsock2.h>
using namespace std;
class http
{
public:
	string host;
	string object;
	SOCKET mySocket;
	http()
	{
		;
	}
	~http()
	{

	}
	string lowercase(string str)
	{
		for (int i = 0; i < str.length(); i++)
			str[i] = tolower(str[i]);
		return str;
	}
	bool Analyse(std::string url)
	{
		int httpInd = url.find("//");
		string httpPart = url.substr(0, httpInd);
		if(httpPart != "http:" && httpPart != "https:")
			return false;
		int hostInd = url.find("/", httpInd + 2);
		host = url.substr(httpInd + 2, hostInd - httpInd - 2);
		object = url.substr(hostInd, url.length()-1);
		return true;
	}
	bool Init()
	{
		WSADATA wd;
		if (0 != WSAStartup(MAKEWORD(2, 2), &wd))
			return false;
		if (LOBYTE(wd.wVersion) != 2 || HIBYTE(wd.wVersion) != 2)
			return false;
		mySocket = socket(AF_INET, SOCK_STREAM, 0);
		return true;
	}
	bool Connect()
	{
		HOSTENT *p = gethostbyname(host.c_str());
		if (p == NULL)
			return false;
		sockaddr_in sa;
		sa.sin_family = AF_INET;
		sa.sin_port = htons(80);
		memcpy(&sa.sin_addr, p->h_addr, 4);
		if (SOCKET_ERROR == connect(mySocket, (sockaddr*)&sa, sizeof(sockaddr)))
			return false;
		return true;
	}
	bool GetHtml(string& html)
	{

		return true;
	}
};