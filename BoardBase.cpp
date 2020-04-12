#include "BoardBase.h"

void BoardBase::debugPrint() const {
	for (uint8_t i = 0; i < heightBoard; ++i) {
		for (uint8_t j = 0; j < widthBoard; ++j) {
			std::cout << +buffer[i][j];
		}
		std::cout << std::endl;
	}
}

// for debug
void BoardBase::setLine(uint32_t numY, uint32_t value) {
	for (uint32_t j = 0; j < widthBoard; ++j) {
		buffer[numY][j] = value;
	}
}
void BoardBase::setPoint(uint32_t x, uint32_t y, uint32_t value) {
	buffer[y][x] = value;
}

bool BoardBase::allowMove(Direction direction, const Figure &figure) const {
	const auto& points = figure.getPoints();
	int xOffset = figure.getXOffset();
	int yOffset = figure.getYOffset();
	
	if (direction == Direction::Right) {
		++xOffset;
	} else if (direction == Direction::Left) {
		--xOffset;
	} else if (direction == Direction::Down){
		++yOffset;
	} else {
		std::cerr << "User error: unsupported direction type." << std::endl;
	}
	return
		isCrossedFigureWithBuffer(points, xOffset, yOffset) &&
			isCrossedFigureWithWalls(points, xOffset, yOffset);
}

void BoardBase::clear() {
	for (uint8_t i = 0; i < heightBoard; ++i) {
		for (uint8_t j = 0; j < widthBoard; ++j) {
			buffer[i][j] = 0;
		}
		std::cout << std::endl;
	}
}

bool BoardBase::isCrossedFigureWithBuffer(
	const std::vector<std::vector<uint8_t>> &points,
	int xOffset,
	int yOffset) const {
	for (auto i = 0; i < points.size(); ++i) {
		for (auto j = 0; j < points[0].size(); ++j) {
			// if buffer elements points are busy we cannot do this action
			if (points[i][j] && buffer[i + yOffset][j + xOffset]) {
				return false;
			}
		}
	}
	return true;
}

bool BoardBase::isCrossedFigureWithWalls(
	const std::vector<std::vector<uint8_t>> &points,
	int xOffset,
	int yOffset) const {
	
	for (auto i = 0; i < points.size(); ++i) {
		for (auto j = 0; j < points[0].size(); ++j) {
			if (!points[i][j])
				continue;
			if ((j + xOffset >= widthBoard) ||
				(j + xOffset < 0) ||
				(i + yOffset >= heightBoard)) {
				return false;
			}
		}
	}
	return true;
}
