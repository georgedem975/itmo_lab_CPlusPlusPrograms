#include <chrono>
#include <iostream>
#include "pch.h"

TEST(testIsRunning, testRun) 
{
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

template <int ... T>
class ListWithArgumentsForPointPolynom;

template <int F, int ... N>
class ListWithArgumentsForPointPolynom<F, N...>
{
public:
	static const int first = F;
	using next = ListWithArgumentsForPointPolynom<N...>;
};

template<>
class ListWithArgumentsForPointPolynom<> {};

template<class P, class Q, int point>
class PointPolinom
{
public:

	PointPolinom<P, Q, point> operator * (const PointPolinom<P, Q, point> other)
	{
		this->sum = this->sum * other.sum;
		return *this;
	}

	PointPolinom<P, Q, point> operator / (const PointPolinom<P, Q, point> other)
	{
		this->sum = this->sum / other.sum;
		return *this;
	}

private:
	template<int temp, int iterator>
	class For 
	{
	public:
		static const unsigned long allSumValue = For<temp, iterator - 1>::allSumValue * temp;
	};

	template<int temp>
	class For<temp, 1> 
	{
	public:
		static const unsigned  long allSumValue = temp * 1;
	};

public:

	static int const sum = For<point, P::first>::allSumValue * Q::first + PointPolinom<P::next, Q::next, point>::sum;

	PointPolinom<P, Q, point> operator + (const PointPolinom<P, Q, point> other)
	{
		this->sum = this->sum + other.sum;
		return *this;
	}

	template<class P1, class Q1, int point1>
	PointPolinom<P, Q, point> operator - (const PointPolinom<P1, Q1, point1> other)
	{
		this->sum = this->sum - other.sum;
		return *this;
	}

	PointPolinom<P, Q, point> operator = (const PointPolinom<P, Q, point> other)
	{
		this->sum = other.sum;
		return *this;
	}

	bool operator == (const PointPolinom<P, Q, point> other)
	{
		return this->sum == other.sum;
	}

	bool operator != (const PointPolinom<P, Q, point> other)
	{
		return (this->operator==(other));
	}

	friend std::ostream& operator <<(std::ostream& output, PointPolinom & polinom)
	{
		output << "value of polinom in point == " << polinom.sum;
		return output;
	}
};

template <int point>
class PointPolinom<ListWithArgumentsForPointPolynom<>, ListWithArgumentsForPointPolynom<>, point>
{
public:
	static int const sum = 0;
};

int resultForTest = 1;
int resultForTestTwo = 1;
int resultForTestThree = 0;
int resultForTestFour = 1;
int resultForTestFive = 1;
int timeOfRunning = 0;

TEST(FirstEqual, Equal)
{
	ASSERT_EQ(250, resultForTest);
}

TEST(SecondEqual, Equal)
{
	ASSERT_EQ(122, resultForTestTwo);
	ASSERT_NE(0, resultForTestTwo);
}

TEST(TimingTest, Time)
{
	ASSERT_GT(100, timeOfRunning);
	std::cout << "\n ------------------ \ntime of running program === " << timeOfRunning << "\n ------------------ \n";
	TimingTest_Time_Test().test_info_;
}

TEST(TimingTest2, Time2)
{
	ASSERT_GT(50, timeOfRunning);
	std::cout << "\n ------------------ \ntime of running program === " << timeOfRunning << " < " <<  50  <<"\n ------------------ \n";
	TimingTest2_Time2_Test().test_info_;
}

TEST(TimingTest3, Time3)
{
	ASSERT_GT(10, timeOfRunning);
	std::cout << "\n ------------------ \ntime of running program === " << timeOfRunning << " < " << 10 << "\n ------------------ \n";
	TimingTest3_Time3_Test().test_info_;
}

TEST(TimingTest4, Time4)
{
	ASSERT_GE(5, timeOfRunning);
	std::cout << "\n ------------------ \ntime of running program === " << timeOfRunning << " <= " << 5 << "\n ------------------ \n";
	TimingTest4_Time4_Test().test_info_;
}

TEST(LatestTest, Test)
{
	if (resultForTestThree == 0)
	{
		std::cout << "\n all test running succses\n";
	}
	else
	{
		std::cout << "\n you have not fatal fail\n";
	}
}

TEST(LatestTestTwo, TestTwo)
{
	ASSERT_GT(resultForTestFour, resultForTest);
}

TEST(LatestTestThree, TestThree)
{
	ASSERT_EQ(resultForTest, resultForTestFive);
}

int main(int argc, char* argv[])
{
	clock_t start = clock();

	using listWithDegrees = ListWithArgumentsForPointPolynom<3>;
	using listWithConstants = ListWithArgumentsForPointPolynom<2>;
	std::cout << PointPolinom<listWithDegrees, listWithConstants, 5>::sum;
	resultForTest = PointPolinom<listWithDegrees, listWithConstants, 5>::sum;
	std::cout << std::endl;
	PointPolinom<listWithDegrees, listWithConstants, 4> temp;
	std::cout << temp;
	PointPolinom<listWithDegrees, listWithConstants, 5> tempTwo;
	resultForTestTwo = PointPolinom<listWithDegrees, listWithConstants, 5>::sum - PointPolinom<listWithDegrees, listWithConstants, 4>::sum;
	resultForTestFour = resultForTestTwo * PointPolinom<listWithDegrees, listWithConstants, 5>::sum;
	resultForTestFive = resultForTestFour / resultForTestTwo;

	clock_t finish = clock();

	timeOfRunning = (int)((float)(finish - start));

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
