#include <gtest/gtest.h>
#include <cmath>
#include <sstream>

#include "./head/point.h"
#include "./head/rhombus.h"
#include "./head/5-squere.h"
#include "./head/trpezoid.h"
#include "./head/array.h"

TEST(FigureTest, RhombusDefault) {
    Rhombus<double> r;
    EXPECT_EQ(r.getd1(), 1.0);
    EXPECT_EQ(r.getd2(), 1.0);
}

TEST(FigureTest, RhombusFromParams) {
    Rhombus<double> r(Point<double>(0,0), 2.0, 4.0);
    EXPECT_EQ(r.getd1(), 2.0);
    EXPECT_EQ(r.getd2(), 4.0);
}

TEST(FigureTest, PentagonDefault) {
    Fivesquere<double> p;
    EXPECT_EQ(p.getRadius(), 1.0);
}

TEST(FigureTest, TrapezoidFromParams) {
    Trapezoid<double> t(Point<double>(1,1), 3.0, 2.0, 0.5);
    EXPECT_EQ(t.getRadius(), 3.0);
    EXPECT_EQ(t.getHeight(), 2.0);
}

TEST(IO, RhombusStream) {
    Rhombus<double> r;
    std::istringstream ss("0 0 1 1");
    ss >> r;
    EXPECT_DOUBLE_EQ(r.getCenter().getX(), 0.0);
    EXPECT_DOUBLE_EQ(r.getCenter().getY(), 0.0);
    EXPECT_DOUBLE_EQ(r.getd1(), 1.0);
    EXPECT_DOUBLE_EQ(r.getd2(), 1.0);
}

TEST(IO, PentagonStream) {
    Fivesquere<double> p;
    std::istringstream ss("1 2 5");
    ss >> p;
    EXPECT_DOUBLE_EQ(p.getCenter().getX(), 1.0);
    EXPECT_DOUBLE_EQ(p.getCenter().getY(), 2.0);
    EXPECT_DOUBLE_EQ(p.getRadius(), 5.0);
}


TEST(AreaTest, RhombusArea) {
    Rhombus<double> r(Point<double>(0,0), 4.0, 6.0);
    EXPECT_DOUBLE_EQ(static_cast<double>(r), 12.0);
}

TEST(AreaTest, TrapezoidArea) {
    Trapezoid<double> t(Point<double>(0,0), 3.0, 4.0, 0.5);
    EXPECT_DOUBLE_EQ(static_cast<double>(t), 18.0);
}

TEST(Equality, RhombusEqual) {
    Rhombus<double> a(Point<double>(0,0), 2, 2);
    Rhombus<double> b(Point<double>(0,0), 2, 2);
    EXPECT_TRUE(a == b);
}

TEST(Equality, RhombusNotEqual) {
    Rhombus<double> a(Point<double>(0,0), 2, 2);
    Rhombus<double> b(Point<double>(0,0), 2, 3);
    EXPECT_FALSE(a == b);
}