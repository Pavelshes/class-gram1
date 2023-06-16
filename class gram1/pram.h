#pragma once
class   Rectangle
{
private:
    float a;
    float b;
public:
    Rectangle(float _a, float _b) : a(_a), b(_b)
    {
    }
    float Ploshcha();
    float Perumetr();
};