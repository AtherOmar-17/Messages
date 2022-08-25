#include "MessageManager.h"

MessageManager* MessageManager::s_instance = nullptr;

MessageManager::MessageManager()
{
	for (int i = 0; i < Messages_Max; i++)
	{
		m_functions.push_back(std::vector<std::function<void()>>());
	}
}

MessageManager::~MessageManager()
{

}

void MessageManager::AddListener(std::function<void()> func, int messageType)
{
	m_functions[messageType].push_back(func);
}

void MessageManager::BoardcastMessage(int messageType)
{
	for (int i = 0; i < m_functions[messageType].size(); i++)
	{
		m_functions[messageType][i]();
	}
}