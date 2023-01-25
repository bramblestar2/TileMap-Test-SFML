#include "Tile.h"

Tile::Tile(sf::Texture& texture, const sf::Vector2f tile_size, const std::string tile_id,
		   const int num_id, const sf::Vector2i location)
{
	m_texture = &texture;
	m_tile_id = tile_id;
	m_tile_size = tile_size;
	m_num_id = num_id;
	m_location = location;

	setBreakPercentage(0);
	setBreakResistance(0);
	setBroken(false);
	setInvisible(false);
	setPassthrough(false);
	setUnbreakable(false);


	//Set sprite
	m_sprite.setSize(tile_size);
	m_sprite.setTexture(m_texture, true);
	m_sprite.setPosition(sf::Vector2f(location.x * tile_size.x, location.y * tile_size.y));
}

void Tile::setPassthrough(const bool passthrough)
{
	m_passthrough = passthrough;
}

void Tile::setInvisible(const bool invisible)
{
	m_invisible = invisible;
}

void Tile::setUnbreakable(const bool unbreakable)
{
	m_unbreakable = unbreakable;
}

void Tile::setBroken(const bool broken)
{
	m_broken = broken;
}

void Tile::setBreakResistance(const float resistance)
{
	m_break_resistence = resistance;
}

void Tile::setBreakPercentage(const float percentange)
{
	m_break_percentage = percentange;
}

bool Tile::isPassthrough() const
{
	return m_passthrough;
}

bool Tile::isInvisible() const
{
	return m_invisible;
}

bool Tile::isUnbreakable() const
{
	return m_unbreakable;
}

bool Tile::isBroken() const
{
	return m_broken;
}

float Tile::getBreakResistence() const
{
	return m_break_resistence;
}

float Tile::getBreakPercentage() const
{
	return m_break_percentage;
}

float Tile::breakAmount(const float break_amount)
{
	float damage = m_break_resistence / break_amount;
	m_break_percentage -= damage;

	return damage;
}

bool Tile::collision(const sf::FloatRect& collider)
{
	if (!m_broken && !m_passthrough)
		return m_sprite.getGlobalBounds().intersects(collider);
	else
		return false;
}

void Tile::draw(sf::RenderTarget& target, const sf::RenderStates& states)
{
	if (!m_invisible)
		target.draw(m_sprite, states);
}

std::ostream& operator<<(std::ostream& out, Tile& data)
{
	out << data.m_num_id << " " << data.m_tile_id << " " << data.m_tile_size.x << " " <<
		data.m_tile_size.y << " " << data.m_location.x << " " << data.m_location.y << " " << 
		data.m_passthrough << " " << data.m_invisible << " " << data.m_unbreakable << " " << 
		data.m_broken << " " << data.m_break_resistence << " " << data.m_break_percentage;

	return out;
	// TODO: insert return statement here
}
