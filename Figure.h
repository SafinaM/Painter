#pragma once

#include <vector>
#include <cstdint>
#include <memory>
#include "enums.h"

struct Figure {
	
	virtual std::vector<std::vector<uint8_t>> getPoints(Orientation orientation) const = 0;
	
	std::vector<std::vector<uint8_t>> getPoints() const;
	
	void setOrientationType(Orientation orientation);
	
	void move(Direction direction) noexcept;
	
	void setXY(int x, int y) noexcept;
	
	int getXOffset() const noexcept;
	
	int getYOffset() const noexcept;
	
	uint32_t getColor() const noexcept;
	
	void setColor(const uint32_t color) noexcept;

protected:
	std::vector<std::vector<uint8_t>> points;
	
	Orientation m_orientation;
	
	int m_offsetX = 0;
	int m_offsetY = 0;
	
	uint32_t m_Color = 0;
};