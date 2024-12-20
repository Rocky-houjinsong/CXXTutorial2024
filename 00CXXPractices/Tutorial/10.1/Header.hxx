/**
 * Date: 2024年11月04日21:10:56
 * Info: 表示 几何图形的基类
 */

#pragma once
#include <cmath>

/**   抽象基类 - 几何图形*/
struct Shape {
    static constexpr double Pi {3.1415926};  // 常量 Pi
    /** 角度 转 弧度*/
    static constexpr double Deg2Rad(double deg){
        return deg * Pi / 180;
    }
     /** 弧度 转 角度*/
    static constexpr double Rad2Deg(double rad){
        return rad * 180 / Pi;
    }
     /** 周长 纯虚函数*/
    virtual double perimeter() const = 0;
     /**  面积 纯虚函数*/
    virtual double area() = 0;

};

 /** 三角形 */
class Triangle : public Shape {
     /** 默认字段的 访问权限 private 三角形 的 三条边 */
    double _a;
    double _b; 
    double _c;

    public:
        Triangle(double a, double b, double c) 
            : _a{a}, _b{b}, _c{c} {} // 构造函数

        double perimeter() const { return _a + _b + _c;}

        double area() const {
            double s { (_a + _b + _c) / 2};
            double std::sqrt ( s * (s - _a) * (s - _b) * (s - _c));
        }
};

 /** 圆形 */
class Circle : public Shape {
    double _r ;  //圆半径

    public:
        Circle(double r) : _r{r} {} 

        double perimeter() const { return 2 * Pi * _r;}

        double area() const { return Pi * _r * _r ;} 
        
};

 /**
  * TODO: 抽象平行四边形 基类
  * 
  *  */

