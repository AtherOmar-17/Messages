#pragma once

#include <vector>
#include <functional>

enum Message
{
	AOE_Damage,
	Player_Connected,
	Player_Disconnected,
	Messages_Max
};

class MessageManager
{
private:

	static MessageManager* s_instance;

	MessageManager();
	~MessageManager();

	std::vector<std::vector<std::function<void()>>> m_functions;


public:

	static MessageManager* GetInstance()
	{
		if (s_instance == nullptr)
		{
			s_instance = new MessageManager();
		}

		return s_instance;
	}

	static void Release()
	{
		delete s_instance;
		s_instance = nullptr;
	}

	void AddListener(std::function<void()> func, int messageType);

	void BoardcastMessage(int messageType);
};