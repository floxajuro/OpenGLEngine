#include "EntityManager.h"
#include <iostream>
#include "Helpers.h"

using namespace Engine::Entity;

std::vector<Entity*> EntityManager::_mEntityPool = {};

Entity* EntityManager::Create(std::string const& entityName)
{
	_mEntityPool.push_back(new Entity(entityName));
	return *std::find_if(_mEntityPool.begin(), _mEntityPool.end(), [&entityName](const auto* item) {
		return (item->ID().compare(entityName) == 0);
	});
}

void EntityManager::Delete(Entity const& toDelete)
{
	_mEntityPool.erase(std::remove_if(_mEntityPool.begin(), _mEntityPool.end(), [&toDelete](const auto* item) {
		return (item->ID().compare(toDelete.ID()) == 0);
	}));
}

Entity const* EntityManager::Get(std::string const& id)
{
	const auto it = std::find_if(_mEntityPool.begin(), _mEntityPool.end(), [&id](const auto* item) {
		return (item->ID().compare(id) == 0);
	});
	return (it != _mEntityPool.end()) ? *it : nullptr;
}
