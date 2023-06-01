#include <gtest/gtest.h>
#include "my_unique_ptr.hpp"

struct TestObject
{
  int value_;
  TestObject(int value) : value_(value){}
  TestObject(){};
  int multiplyValueByTwo()
  {
    return value_ *= 2;
  }
};

TEST(MyUniquePtrTest, ArrowOperatorTest)
{
  MyUniquePtr<TestObject> myUniquePtr(new TestObject{20});
  auto expected = 40;

  EXPECT_EQ(expected, myUniquePtr->multiplyValueByTwo());
}

TEST(MyUniquePtrTest, DereferenceOperatorTest)
{
  MyUniquePtr<TestObject> myUniquePtr(new TestObject(20));
  TestObject& dereferencedObj = *myUniquePtr;

  auto result = dereferencedObj.multiplyValueByTwo();
  auto expected = 40;
  EXPECT_EQ(expected, result);
}

TEST(MyUniquePtrTest, FunctionGetExpectedNotNullTest)
{
  MyUniquePtr<TestObject> myUniquePtr(new TestObject(20));
  TestObject* rawPtr = myUniquePtr.get();

  EXPECT_NE(nullptr, rawPtr);
}

TEST(MyUniquePtrTest, FunctionGetExpectedValueTest)
{
  MyUniquePtr<TestObject> myUniquePtr(new TestObject(20));
  TestObject* rawPtr = myUniquePtr.get();

  auto expected = 40;
  auto result = rawPtr->multiplyValueByTwo();
  EXPECT_EQ(expected, result);
}

TEST(MyUniquePtrTest, DefaultConstructorTest)
{
  MyUniquePtr<TestObject> myUniquePtr;
  auto value = myUniquePtr.get();
  EXPECT_EQ(nullptr, value);
}
