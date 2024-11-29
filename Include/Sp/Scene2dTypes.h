#pragma once

namespace sp
{

using Scene2dInt = int;
using Scene2dFloat = double;

// TODO Добавить методы сравнения и, возможно, арифметические операции
struct Point2d
{
    Scene2dInt x;
    Scene2dInt y;
};

struct Point2dF
{
    Scene2dFloat x;
    Scene2dFloat y;
};

struct Size2d
{
    Scene2dInt width;
    Scene2dInt height;
};

struct Size2dF
{
    Scene2dFloat width;
    Scene2dFloat height;
};

struct Rect2d
{
    Scene2dInt left;
    Scene2dInt top;
    Scene2dInt width;
    Scene2dInt height;
};

struct Rect2dF
{
    Scene2dFloat left;
    Scene2dFloat top;
    Scene2dFloat width;
    Scene2dFloat height;
};

} // namespace sp
