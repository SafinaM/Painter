#pragma once

#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

#include "Figure.h"
#include "enums.h"


struct BoardBase {
	BoardBase(uint32_t width, uint32_t height) : widthBoard(width), heightBoard(height) {
		buffer.resize(heightBoard);
		for (uint32_t i = 0; i < heightBoard; ++i) {
			for (uint32_t j = 0; j < heightBoard; ++j) {
				std::vector<uint8_t> tmp;
				tmp.resize(widthBoard);
				buffer.emplace_back(std::move(tmp));
			}
		}
	}
	uint32_t widthBoard;
	uint32_t heightBoard;
	std::vector<std::vector<uint8_t>> buffer;
	
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