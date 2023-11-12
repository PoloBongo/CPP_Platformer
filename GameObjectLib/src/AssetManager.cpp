#include "AssetManager.h"

 void AssetManager::AddAsset(std::string _key, sf::Texture _texture)
{
	if (AssetManager::assets.find(_key) == AssetManager::assets.end()) {
		AssetManager::assets.insert(std::make_pair(_key, _texture));
	}
}

 void AssetManager::LoadAsset(std::string _key, std::string _fileName)
 {
	 if (AssetManager::assets.find(_key) != AssetManager::assets.end()) {
		 AssetManager::assets.at(_key).loadFromFile(_fileName);
	 }
 }