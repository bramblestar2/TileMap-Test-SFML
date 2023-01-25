#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Tile
{
public:
	Tile(sf::Texture& texture, const sf::Vector2f tile_size, const std::string tile_id, 
		 const int num_id, const sf::Vector2i location);

	void setPassthrough(const bool passthrough);
	void setInvisible(const bool invisible);
	void setUnbreakable(const bool unbreakable);
	void setBroken(const bool broken);
	void setBreakResistance(const float resistance);
	void setBreakPercentage(const float percentange);

	bool isPassthrough() const;
	bool isInvisible() const;
	bool isUnbreakable() const;
	bool isBroken() const;
	float getBreakResistence() const;
	float getBreakPercentage() const;

	float breakAmount(const float break_amount);

	bool collision(const sf::FloatRect& collider);

	void draw(sf::RenderTarget& target, const sf::RenderStates& states);

private:
	int m_num_id;
	std::string m_tile_id;
	sf::Vector2f m_tile_size;
	sf::Vector2i m_location;
	sf::Texture* m_texture;
	sf::RectangleShape m_sprite;

	//Properties
	bool m_passthrough;
	bool m_invisible;
	bool m_unbreakable;
	bool m_broken;

	float m_break_resistence;
	float m_break_percentage;

	friend std::ostream& operator<<(std::ostream& out, Tile& data);
};

