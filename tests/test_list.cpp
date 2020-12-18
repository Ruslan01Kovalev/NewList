#include <../gtest/gtest.h>

#include "List.h"

TEST(list, can_create_list)
{
	ASSERT_NO_THROW(List<int> a);
}

TEST(list, can_copy)
{
	List<int> list;
	list.push_back(1);

	List<int> new_list(a);

	EXPECT_EQ(123, new_list[0]);
}

TEST(list, can_push_back)
{
	List<int> list;

	for (int i = 0; i < 2; i++)
		list.push_back(i);

	EXPECT_EQ(1, list[1]);
}

TEST(list, can_push_back_second)
{
	List<int> list;

	list.push_back(22);

	EXPECT_EQ(22, list[0]);
}

TEST(list, can_push_back_)
{
	List<int> list;

	list.push_back(22);
	list.push_back(11);
	list.push_back(232);
	list.push_back(35);

	EXPECT_EQ(35, list[3]);
}


TEST(list, can_pop_back)
{
	List<int> list;

	list.push_back(11);
	list.push_back(33);

	list.pop_back();

	EXPECT_EQ(11, list[0]);
}

TEST(list, cant_pop_in_empty_list)
{
	List<int> a;
	ASSERT_ANY_THROW(a.pop_back());
}

TEST(list, can_push_front)
{
	List<int> list;

	for (int i = 0; i < 5; i++)
		list.push_front(i);

	EXPECT_EQ(0, list[0]);
}

TEST(list, can_pop_front)
{
	List<int> list;

	list.push_back(5);
	list.push_back(10);

	list.pop_front();

	EXPECT_EQ(10, list[0]);
}

TEST(list, can_get_size)
{
	List<int> thislist;

	thislist.push_back(2);
	thislist.push_back(12);

	EXPECT_EQ(2, thislist.GetSize());
}


TEST(list, can_insert)
{
	List<int> thislist;

	thislist.push_back(5);
	thislist.push_back(100);

	thislist.insert(25, 1);
	thislist.insert(13, 1);
	thislist.insert(14, 2);

	EXPECT_EQ(25, thislist[3]);
}


