#include <iostream>
#include "class.hpp"
#include <gtest/gtest.h>


using namespace std;



class exampleFixture : public testing::Test 
{
	public:
	exampleFixture(){
		cout << "create fixture" << endl;

		testExPtr = new TestClass();
	}
	~exampleFixture()
	{
		delete testExPtr;
		cout << "delete fixture" << endl;
	}

	void SetUp(){}
	void TearDown(){}
	
	TestClass* testExPtr;
};


TEST_F(exampleFixture, test1)
{
	ASSERT_EQ(3,testExPtr->sum(1,2));
}

TEST_F(exampleFixture, test2)
{
	ASSERT_NE(0,testExPtr->sum(2,3));
}


class TestClass2
{
    public: 
        int sum(int a, int b){ return a + b;}
};

TEST(TestName, test1)
{
	TestClass2 t;

	ASSERT_EQ(3, t.sum(1,2));
}


TEST(TestName, test2)
{
	TestClass t;

	ASSERT_EQ(3, t.sum(1,2));
}





