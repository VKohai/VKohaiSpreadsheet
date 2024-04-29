#pragma once
#include <string>

class SpreadsheetCell
{
public:
    SpreadsheetCell() = default;
    SpreadsheetCell(double initialValue);
    SpreadsheetCell(std::string_view initalValue);

    double GetValue() const;
    void SetValue(double value);

    std::string GetString() const;
    void SetString(std::string_view value);

private:
    double m_value{0};

    static std::string DoubleToString(double value);
    static double StringToDouble(std::string_view value);
};
