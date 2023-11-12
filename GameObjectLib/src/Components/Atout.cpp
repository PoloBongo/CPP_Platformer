#include "Components/Atout.h"
#include "Components/Button.h"
#include "Components/SpriteRenderer.h"

Atout::Atout() 
{
	RandAtout();
	CreateAtout();
	
};
void Atout::CreateAtout()
{
	if (random_atout == 1) static_cast<float>(SceneManager::GetActiveScene()->GetGameObject("Player")->GetComponent<InputPlayer>()->AddSpeed(SceneManager::GetActiveScene()->GetGameObject("Atout")->GetBonus()));
	if (random_atout == 2) SceneManager::GetActiveScene()->GetGameObject("Player")->GetComponent<Player>()->SetDamage(SceneManager::GetActiveScene()->GetGameObject("Player")->GetComponent<Player>()->GetDamage() + SceneManager::GetActiveScene()->GetGameObject("Atout")->GetBonus());
	if (random_atout == 3) SceneManager::GetActiveScene()->GetGameObject("Player")->GetComponent<Player>()->SetHealthPoint(SceneManager::GetActiveScene()->GetGameObject("Player")->GetComponent<Player>()->GetHealthPoint() + SceneManager::GetActiveScene()->GetGameObject("Atout")->GetBonus());
};

void Atout::RandAtout()
{
	std::srand(std::time(nullptr)); 
	random_atout = std::rand()%3;
	SceneManager::GetActiveScene()->GetGameObject("Atout")->SetBonus(atouts[random_atout]);
}
