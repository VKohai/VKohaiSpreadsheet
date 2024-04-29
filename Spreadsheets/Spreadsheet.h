#pragma once
#include "SpreadsheetCell.h"

class Spreadsheet {
public:
	Spreadsheet(size_t width, size_t height);
	Spreadsheet(const Spreadsheet& src);
	~Spreadsheet();
	
	void SetCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& GetCellAt(size_t x, size_t y) const;

	Spreadsheet& operator=(const Spreadsheet& right);
	void Swap(Spreadsheet& other) noexcept;
private:
	static bool InRange(size_t value, size_t upper);
	void VerifyCoordinates(size_t x, size_t y) const;
	size_t m_width{0}, m_height{0};
	SpreadsheetCell** m_cells{nullptr};
};
