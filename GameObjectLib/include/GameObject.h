#pragma once

#include <string>
#include <vector>

#include "Maths/Vector2.h"
#include "Components/Component.h"

class Component;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject() = default;

	std::string GetName() const { return name; }
	Maths::Vector2<float> GetPosition() const { return position; }

	void SetName(const std::string& _name) { name = _name; }
	void SetPosition(const Maths::Vector2<float>& _position) { position = _position; }

	void SetActive(bool _state) { isActive = _state; }
	bool GetActive() { return isActive; }

	void SetBonus(int _bonus) { bonus = _bonus; }
	int GetBonus() { return bonus; }

	void AddComponent(Component* _component);

	template<typename T>
	T* CreateComponent()
	{
		T* component = new T();
		component->SetOwner(this);
		components.push_back(component);
		return component; 
	}
	
	template<typename T>
	T* GetComponent() {
		for (Component* component : components) {
			// Vérifie si le composant est un Collider
			T* componentResult = dynamic_cast<T*>(component);
			if (componentResult) {
				return componentResult; // Renvoie le Collider trouvé
			}
		}
		return nullptr; // Renvoie nullptr si aucun Collider n'est trouvé
	}



	void RemoveComponent(Component* _component);
	virtual void Start();
	void Update(sf::Time _delta) const;
	void Render(sf::RenderWindow* _window) const;

protected:
	std::string name = "GameObject";
	Maths::Vector2<float> position = Maths::Vector2f::Zero;
	std::vector<Component*> components;
	bool isActive = true;
	int bonus = 0; 
};
