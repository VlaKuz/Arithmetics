#include "tlist.h"

#include <gtest.h>

TEST (List, can_create_list_with_positive_length)
{
	ASSERT_NO_THROW (List<int> Testlist(5));
}


TEST (List, cant_create_list_with_negative_length)
{
	ASSERT_ANY_THROW (List<int> Testlist(-5));
}


TEST (List, can_create_list_with_zero_length)
{
	ASSERT_NO_THROW (List<int> Testlist(0));
}


TEST (List, can_get_size)
{
	List<int> Testlist(5);
	EXPECT_EQ (5, Testlist.GetSize());
}


TEST(List, set_elem_with_positive_normal_index)
{
	List<int> Testlist(5);
	ASSERT_NO_THROW (Testlist[1]);
}


TEST(List, set_elem_with_negative_index)
{
	List<int> Testlist(5);
	ASSERT_ANY_THROW (Testlist[-1]);
}


TEST(List, set_elem_with_too_large_index)
{
	List<int> Testlist(5);
	ASSERT_ANY_THROW (Testlist[10]);
}


TEST(List, can_get_element)
{
	List<int> Testlist(5);
	Testlist[1] = 10;
	EXPECT_EQ(10, Testlist[1]);
}

TEST(List, can_add_elem_with_pos_with_normal)
{
	List<int> Testlist(5);
	Testlist[0]=1;
	Testlist[1]=2;
	Testlist[2]=3;
	Testlist[3]=4;
	Testlist[4]=5;
	List_node<int> *Node=Testlist.Search (3); 
	Testlist.Add(2,Node);
	EXPECT_EQ(2, Testlist[3]);
}

TEST(List, can_change_size_list_after_add_elem_with_pos_with_normal)
{
	List<int> Testlist(5);
	Testlist[0]=1;
	Testlist[1]=2;
	Testlist[2]=3;
	Testlist[3]=4;
	Testlist[4]=5;
	List_node<int> *Node=Testlist.Search (3); 
	Testlist.Add(2,Node);
	EXPECT_EQ(6,Testlist.GetSize());
}


TEST(List, cant_add_zero_node)
{
	List<int> Testlist(5);
	Testlist[0]=1;
	Testlist[1]=2;
	Testlist[2]=3;
	Testlist[3]=4;
	Testlist[4]=5;
	List_node<int> *Node=NULL;
	ASSERT_ANY_THROW (Testlist.Add(3,Node));
}

TEST(List, can_add_elem_with_end)
{
	List<int> Testlist(5);
	Testlist.AddWithEnd(4);
	EXPECT_EQ(4, Testlist[5]);
}

TEST(List, can_change_size_list_after_add_elem_with_end)
{
	List<int> Testlist(5);
	Testlist.AddWithEnd(4);
	EXPECT_EQ(6,Testlist.GetSize());
}


TEST(List, can_add_elem_with_begin)
{
	List<int> Testlist(5);
	Testlist.AddWithBegin(4);
	EXPECT_EQ(4, Testlist[0]);
}

TEST(List, can_change_size_list_after_add_elem_with_begin)
{
	List<int> Testlist(5);
	Testlist.AddWithBegin(4);
	EXPECT_EQ(6,Testlist.GetSize());
}


TEST(List, can_delete_elem_with_normal_pos)
{
	List<int> Testlist(3);
	Testlist[0]=1;
	Testlist[1]=2;
	Testlist[2]=3;
	List_node<int> *Node=Testlist.Search (1); 
	Testlist.DeleteNodeWithPos(Node);
	EXPECT_EQ(3,Testlist[1]);
}

TEST(List, can_change_size_list_after_delete_elem_with_pos_with_normal)
{
	List<int> Testlist(3);
	Testlist[0]=1;
	Testlist[1]=2;
	Testlist[2]=3;
	List_node<int> *Node=Testlist.Search (1); 
	Testlist.DeleteNodeWithPos(Node);
	EXPECT_EQ(2,Testlist.GetSize());
}


TEST(List, cant_delete_zero_node)
{
	List<int> Testlist(3);
	Testlist[0]=1;
	Testlist[1]=2;
	Testlist[2]=3;
	List_node<int> *Node=NULL;
	ASSERT_ANY_THROW (Testlist.DeleteNodeWithPos(Node));
}


TEST(List, cant_delete_elem_with_empty_list)
{
	List<int> Testlist;
	ASSERT_ANY_THROW (Testlist.DeleteNodeWithBegin());
}


TEST(List, can_delete_elem_with_end)
{
	List<int> Testlist(3);
	Testlist[0]=1;
	Testlist[1]=2;
	Testlist[2]=3;
	Testlist.DeleteNodeWithEnd();
	EXPECT_EQ(2,Testlist[1]);
}

TEST(List, can_change_size_list_after_delete_elem_with_end)
{
	List<int> Testlist(3);
	Testlist[0]=1;
	Testlist[1]=2;
	Testlist[2]=3;
	Testlist.DeleteNodeWithEnd();
	EXPECT_EQ(2,Testlist.GetSize());
}

TEST(List, can_delete_elem_with_begin)
{
	List<int> Testlist(3);
	Testlist[0]=1;
	Testlist[1]=2;
	Testlist[2]=3;
	Testlist.DeleteNodeWithBegin();
	EXPECT_EQ(2,Testlist[0]);
}

TEST(List, can_change_size_list_after_delete_elem_with_begin)
{
	List<int> Testlist(3);
	Testlist[0]=1;
	Testlist[1]=2;
	Testlist[2]=3;
	Testlist.DeleteNodeWithBegin();
	EXPECT_EQ(2,Testlist.GetSize());
}

TEST(List, cant_delete_elem_with_begin_empty_list)
{
	List<int> Testlist;
	ASSERT_ANY_THROW (Testlist.DeleteNodeWithBegin());
}


TEST(List, cant_delete_elem_with_end_empty_list)
{
	List<int> Testlist;
	ASSERT_ANY_THROW (Testlist.DeleteNodeWithEnd());
}

TEST(List, can_search_node)
{
	List<int> Testlist(3);
	Testlist[1]=2;
	EXPECT_EQ (2,(Testlist.Search(2)->data));
}

TEST(List, can_search_node_with_empty_list)
{
	List<int> Testlist;
	EXPECT_EQ (0,Testlist.Search(1));
}

/*--------------------------------------------------------------------------------------------------*/

TEST(Stack, can_create_empty_stack)
{
	ASSERT_NO_THROW (Stack<int> TestStack);
}

TEST(Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW (Stack<int> TestStack(5));
}

TEST(Stack, can_not_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW (Stack<int> TestStack(-5));
}

TEST(Stack, can_push_elem)
{
	Stack<int> TestStack;
	TestStack.PushElem(1);
	EXPECT_EQ (TestStack.RetTopElem(),1);
}

TEST(Stack, can_del_elem)
{
	Stack<int> TestStack;
	TestStack.PushElem(1);
	EXPECT_EQ (TestStack.DelElem(),1);
}

TEST(Stack, cant_del_elem_from_empty_stack)
{
	Stack<int> TestStack;
	ASSERT_ANY_THROW (TestStack.DelElem());
}

TEST(Stack, can_clear_stack)
{
	Stack<int> TestStack;
	TestStack.PushElem(1);
	TestStack.DelElem();
	EXPECT_EQ (TestStack.EmptyStack(),1);
}

TEST(Stack, not_empty_stack)
{
	Stack<int> TestStack;
	TestStack.PushElem(1);
	EXPECT_EQ (TestStack.EmptyStack(),0);
}

TEST(Stack, stack_top_element)
{
	Stack<int> TestStack;
	TestStack.PushElem(1);
	TestStack.PushElem(5);
	EXPECT_EQ (TestStack.RetTopElem(),5);
}

TEST(Stack, can_del_elem_two_elements)
{
	Stack<int> TestStack;
	TestStack.PushElem(1);
	TestStack.PushElem(10);
	EXPECT_EQ (TestStack.DelElem(),10);
}
