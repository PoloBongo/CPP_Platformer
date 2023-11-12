#include "Components/Armes.h"
#include "GameObject.h"
#include "Components/FireBullet.h"
#include "SceneManager.h"

Armes::Armes() {
	fireRate = 0.2f;
	fireCooldown = 0;
	mag = 10;
	maxAmo = 10;
	reload = 2.f;
	activeReload = 0.f;
	texture = new sf::Texture();
	if (!texture->loadFromFile("../assets/Sprite/player/weaponBullet/weapon_bullet_0.png")) {
		std::cout << "pas d'image" << std::endl;
	}
}

void Armes::Update(sf::Time _delta) {
	Component::Update(_delta);

	if (activeReload > 0.f) {
		activeReload -= _delta.asSeconds();
	}
	if (activeReload <= 0 && mag <= 0) {
		mag = maxAmo;
	}
	if (fireCooldown > 0.f) {
		fireCooldown -= _delta.asSeconds();
	}

}

void Armes::Shoot() {
	if (mag > 0 && fireCooldown <= 0 && activeReload <= 0) {
		mag -= 1;
		fireCooldown = fireRate;
		bullets.push_back(static_cast<SceneGameAbstract*>(SceneManager::GetActiveScene())->CreateBulletGameObject("Bullet", *texture, 2.5f, 2.5f, GetOwner()));
		if (mag == 0) {
			activeReload = reload;
			fireCooldown = 0.f;
		}
	}

}

void Armes::Render(sf::RenderWindow* _window) {
	Component::Render(_window);
}

void Armes::ClearBullets()
{
	bullets.clear();
}

Armes::~Armes() {
	delete texture;
	this->ClearBullets();
}