#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
#include "SceneManager.h"

class Slider : public Component
{
public:
	Slider();

	void SetSizeBar(float _width, float _height);
	void SetSizeCursor(float _width, float _height);
	void SetPosition(float _x, float _y);
	void SetCursorText(unsigned int _fontSize);
	void SetCursorText(unsigned int _fontSize, float _data);


	void SetTitleText();



	void Render(sf::RenderWindow* _window) override;
	void Update(sf::Time _delta) override;
	bool isClicked(sf::Vector2i _mousePosition);

	float GetPercent(float _x, float _y, float width);

	int GetDataInt() const { return (int)data; }
	float GetDataFloat() const { return data; }
	void SetData(float _data) { data = _data; }

	int GetMaxDataInt() const { return (int)maxData; }
	//float GetMaxDataFloat() const  { return maxData; }
	void SetMaxData(float _max_data) { maxData = _max_data - minData; }
	void SetMinData(float _min_data) { minData = _min_data; }
	
private:
	sf::RectangleShape bar;
	sf::RectangleShape cursor;
	sf::Text cursorText;
	sf::Text titleText;
	sf::Font font;
	unsigned int fontSize;
	float incertitude;
	float data;
	float maxData;
	float minData;
	float percent;
};

