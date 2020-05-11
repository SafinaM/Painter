#pragma once

#include <vector>
#include <unordered_map>
#include <cstdint>
#include <memory>
#include "enums.h"

struct Figure {
	
	void setOrientationTypeAndDirection(Orientation orientation);
	
	virtual std::vector<std::vector<uint8_t>> getPoints(Orientation orientation) const = 0;
	
	std::vector<std::vector<uint8_t>> getPoints() const;
	
	void move(Direction direction) noexcept;
	
	void setXY(int x, int y) noexcept;
	
	int getXOffset() const noexcept;
	
	int getYOffset() const noexcept;
	
	uint32_t getColor() const noexcept;
	
	Orientation getOrientation() const noexcept;
	
	Direction getDirection() const noexcept;
	
	void setColor(const uint32_t color) noexcept;
	
	static bool areCrossedFigures(const Figure& figure1, const Figure& figure2) noexcept;
	
	Figure(Orientation orientation);
	
	const static std::unordered_map<Orientation, Direction, std::hash<std::size_t>> directionByOrientation;
protected:
	
	Orientation m_orientation;
	Direction m_direction;
	
	std::vector<std::vector<uint8_t>> points;
	
	int m_offsetX = 0;
	int m_offsetY = 0;
	
	uint32_t m_Color = 0;
	
};