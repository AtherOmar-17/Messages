#include <iostream>
#include "MessageManager.h"

class Callback
{
public:

	void SetCallbackFunction(std::function<void(int)> func)
	{
		m_function = func;
	}

	void Execute()
	{
		m_function(10);
	}

private:

	std::function<void(int)> m_function;
};

class Player
{
public:

	Player()
	{

	}

	Player(Player const& otherPlayer)
	{
		name = otherPlayer.name;
	}

	std::string name;
};

void DisplayMessage(int number)
{
	std::cout << "Hello World " << number << std::endl;
}

void PlayerConnectedCallback()
{
	std::cout << "Player Connected" << std::endl;
}

int main()
{

	MessageManager::GetInstance()->AddListener(std::bind(PlayerConnectedCallback), Player_Connected);

	MessageManager::GetInstance()->BoardcastMessage(Player_Connected);

	return 0;
}