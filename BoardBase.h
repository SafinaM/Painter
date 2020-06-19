#pragma once

#include <cstdint>
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>

#include "Figure.h"
#include "enums.h"
#include "Point.h"


struct BoardBase {
	BoardBase(uint32_t width, uint32_t height);
	
	BoardBase(const std::vector<std::vector<uint8_t>>& buf);
	
	template <typename T>
	void debugPrint(const std::vector<std::vector<T>> &buf) const {
		for (uint8_t i = 0; i < m_heightBoard; ++i) {
			for (uint8_t j = 0; j < m_widthBoard; ++j) {
				std::cout << std::setw(3) << +buf[i][j];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	
	virtual bool allowMove(Direction direction, const Figure& figure) const;
	
	void clear();
	
	bool
	isCrossedFigureWithBuffer(
		const std::vector<std::vector<uint8_t>>& points,
		int xOffset,
		int yOffset) const;
	
	bool
	isCrossedFigureWithWalls(
		const std::vector<std::vector<uint8_t>>& points,
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
	
	// ##1##
	// #1x1#
	// ##1## where 1 is Neumann neighborhood
	static const std::array<Point, 4> neumannPoints;
	
private:
	void checking();

protected:
	void incrementOrigins(Direction direction, int& xOffset, int& yOffset) const noexcept;
};

