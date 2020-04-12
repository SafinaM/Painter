#pragma once

#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

#include "Figure.h"
#include "enums.h"


struct BoardBase {
	BoardBase(uint32_t width, uint32_t height) : m_widthBoard(width), m_heightBoard(height),
		buffer (std::vector<std::vector<uint8_t>>(m_heightBoard, std::vector<uint8_t>(m_widthBoard, 0))) {
	}
	
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
	
	uint32_t getWidth() const noexcept;
	
	uint32_t getHeight() const noexcept;
	
	// for debug
	void setLine(uint32_t numY, uint32_t value = 1);
	void setPoint(uint32_t x, uint32_t y, uint32_t value = 1);
	
	uint32_t m_widthBoard;
	uint32_t m_heightBoard;
	
	std::vector<std::vector<uint8_t>> buffer;
};