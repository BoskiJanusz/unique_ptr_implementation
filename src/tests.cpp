#include <gtest/gtest.h>
#include "my_unique_ptr.hpp"

struct TestObject
{
  int value_;
  TestObject(int value) : value_(value){}
  int multiplyValueByTwo()
  {
    return value_ *= 2;
  }
};

TEST(MyUniqueOtrTest, ArrowOperatorTest)
{
  MyUniquePtr<TestObject> myUniquePtr(new TestObject{20});
  auto expected = 40;

  EXPECT_EQ(expected, myUniquePtr->multiplyValueByTwo());
}

TEST(MyUniqueOtrTest, DereferenceOperatorTest)
{
  MyUniquePtr<TestObject> myUniquePtr(new TestObject(20));
  TestObject& dereferencedObj = *myUniquePtr;

  auto result = dereferencedObj.multiplyValueByTwo();
  auto expected = 40;
  EXPECT_EQ(expected, result);
}