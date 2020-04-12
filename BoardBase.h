#pragma once

#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

#include "Figure.h"
#include "enums.h"


struct BoardBase {
	constexpr static uint32_t widthBoard = 10;
	constexpr static uint32_t heightBoard = 20;
	uint8_t buffer[heightBoard][widthBoard] = {};
	
	void debugPrint() const;
	
	bool allowMove(Direction direction, const Figure &figure) const;
	
	void clear();
	
	bool isCrossedFigureWithBuffer(
		const std::vector<std::vector<uint8_t>> &points,
		int xOffset,
		int yOffset) const;
	
	bool isCrossedFigureWithWalls(
		const std::vector<std::vector<uint8_t>> &points,
		int xOffset,
		int yOffset) const;
	
	// for debug
	void setLine(uint32_t numY, uint32_t value = 1);
	void setPoint(uint32_t x, uint32_t y, uint32_t value = 1);
};