#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AiStrD3Lab2/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(list_creates_with_size_0)
		{
			List list;
			Assert::IsTrue(list.size_equal(0));
			List.~List();
		}
		
		TEST_METHOD(creating_list_is_empty)
		{
			List list;
			Assert::IsTrue(list.isEmpty());
			List.~List();
		}
		// push_back
		TEST_METHOD(push_back_empty_list) 
		{
			List list;
			list.push_back(5);
			Assert::IsFalse(list.isEmpty());
			List.~List();
		}

		TEST_METHOD(increase_size_push_back) 
		{
			List list;
			list.push_back(5);
			Assert::IsTrue(list.size_equal(1));
			List.~List();
		}

		TEST_METHOD(correct_data_push_back) 
		{
			List list;
			list.push_back(5);
			Assert::IsTrue(list.tail_equal(5));
			List.~List();
		}

		TEST_METHOD(push_back_add_in_tail)
		{
			List list;
			for (int i = 0; i < 6; i++)
				list.push_back(i);
			Assert::IsTrue(list.tail_equal(5));
			List.~List();
		}
		//push front
		TEST_METHOD(empty_list_push_front) 
		{
			List list;
			list.push_front(1);
			Assert::IsFalse(list.isEmpty());
			List.~List();
		}

		TEST_METHOD(increase_size_push_front) 
		{
			List list;
			list.push_front(1);
			Assert::IsTrue(list.size_equal(1));
			List.~List();
		}

		TEST_METHOD(correct_data_push_front) 
		{
			List list;
			list.push_front(0);
			Assert::IsTrue(list.tail_equal(0));
			List.~List();
		}

		TEST_METHOD(change_head_push_front) 
		{
			List list;
			for (int i = 0; i <= 5; i++)
				list.push_front(i);
			Assert::IsTrue(list.head_equal(5));
			List.~List();
		}
		//pop back
		TEST_METHOD(pop_back_list_with_one_elem)
		{
			List list;
			list.push_back(1);
			list.pop_back();
			Assert::IsTrue(list.isEmpty());
			List.~List();
		}

		TEST_METHOD(pop_back_delete_last_elem) 
		{
			List list;
			for (int i = 0; i < 6; i++)
				list.push_back(i);
			list.pop_back();
			Assert::IsTrue(list.tail_equal(4));
			List.~List();
		}

		TEST_METHOD(pop_back_decrease_size) 
		{
			List list;
			list.push_back(1);
			list.pop_back();
			Assert::IsTrue(list.size_equal(0));
			List.~List();
		}

		TEST_METHOD(pop_back_empty_list_exception)
		{
			List list; 
			try
			{
				list.pop_back();
			}
			catch (int error)
			{
				Assert::AreEqual(0, error);
			}
			List.~List();
		}
		//pop front
		TEST_METHOD(pop_front_list_with_one_elem)
		{
			List list;
			list.push_back(1);
			list.pop_front();
			Assert::IsTrue(list.isEmpty());
			List.~List();
		}

		TEST_METHOD(pop_front_delete_last_elem) 
		{
			List list;
			for (int i = 0; i < 6; i++)
				list.push_back(i);
			list.pop_front();
			Assert::IsTrue(list.head_equal(1));
			List.~List();
		}

		TEST_METHOD(pop_front_decrease_size) 
		{
			List list;
			list.push_back(1);
			list.pop_front();
			Assert::IsTrue(list.size_equal(0));
			List.~List();
		}

		TEST_METHOD(pop_front_empty_list_exception) 
		{
			List list;
			try
			{
				list.pop_back();
			}
			catch (int error)
			{
				Assert::AreEqual(0, error);
			}
			List.~List();
		}
		//insert
		TEST_METHOD(insert_index_0_add_head_empty_list) 
		{
			List list;
			list.insert(2, 0);
			Assert::IsFalse(list.isEmpty());
			List.~List();
		}

		TEST_METHOD(insert_index_size_add_tail) 
		{
			List list;
			for (int i = 1; i < 6; i++)
				list.push_back(i);
			list.insert(6, list.get_size());
			Assert::IsTrue(list.tail_equal(6));
			List.~List();
		}
		
		TEST_METHOD(insert_increase_size) 
		{
			List list;
			list.push_back(1);
			list.push_back(3);
			list.insert(2, 1);
			Assert::IsTrue(list.size_equal(3));
			List.~List();
		}

		TEST_METHOD(insert_index_greater_than_size) 
		{
			List list;
			list.push_back(1);
			list.push_back(3);
			try
			{
				list.insert(6, 6);
			}
			catch (int error)
			{
				Assert::AreEqual(1, error);
			}
			List.~List();
		}
		//at
		TEST_METHOD(at_is_correct_index_0)
		{
			List list;
			list.push_back(1);
			list.push_back(3);
			Assert::AreEqual(1, list.at(0));
			List.~List();
		}

		TEST_METHOD(at_is_correct_index_size)
		{
			List list;
			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
			Assert::AreEqual(3, list.at(list.get_size()-1));
			List.~List();
		}

		TEST_METHOD(at_is_correct_middle)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			Assert::AreEqual(2, list.at(1));
			List.~List();
		}

		TEST_METHOD(insert_add_middle)
		{
			List list;
			list.push_back(1);//0
			list.push_back(3);//1
			list.insert(2, 1);
			Assert::AreEqual(2, list.at(1));
			List.~List();
		}

		TEST_METHOD(at_index_greater_than_size)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			try
			{
				list.at(999);
			}
			catch (int error)
			{
				Assert::AreEqual(1, error);
			}
			List.~List();
		}
		//remove
		TEST_METHOD(remove_delete_first)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			list.remove(0);
			Assert::IsTrue(list.head_equal(2));
			List.~List();
		}

		TEST_METHOD(remove_delete_last)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			list.remove(2);
			Assert::IsTrue(list.tail_equal(2));
			List.~List();
		}

		TEST_METHOD(remove_middle)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			list.push_back(4); //3
			list.push_back(5); //4
			list.push_back(6); //5
			list.remove(3);
			Assert::AreEqual(5, list.at(3));
			List.~List();
		}

		TEST_METHOD(remove_position_greater_than_size)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			try
			{
				list.remove(999);
			}
			catch (int error)
			{
				Assert::AreEqual(1, error);
			}
			List.~List();
		}

		TEST_METHOD(remove_decrease_size)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			list.remove(1);
			Assert::IsTrue(list.size_equal(2));
			List.~List();
		}
		//clear
		TEST_METHOD(clear_make_list_empty)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			list.clear();
			Assert::IsTrue(list.isEmpty());
			List.~List();
		}
		TEST_METHOD(clear_size_equals_0)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			list.clear();
			Assert::IsTrue(list.size_equal(0));
			List.~List();
		}
		//set
		TEST_METHOD(set_change_first)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			list.push_back(4); //3
			list.push_back(5); //4
			list.set(0, 99);
			Assert::IsTrue(list.head_equal(99));
			List.~List();
		}

		TEST_METHOD(set_change_last)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			list.push_back(4); //3
			list.push_back(5); //4
			list.set(4, 99);
			Assert::IsTrue(list.tail_equal(99));
			List.~List();
		}

		TEST_METHOD(set_change_middle)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			list.push_back(4); //3
			list.push_back(5); //4
			list.set(2, 99);
			Assert::AreEqual(99, list.at(2));
			List.~List();
		}
		//find first
		TEST_METHOD(find_first_not_included)
		{
			List listA;
			listA.push_back(1); //0
			listA.push_back(2); //1
			listA.push_back(3); //2
			listA.push_back(4); //3
			listA.push_back(5); //4
			List listB;
			listB.push_back(0); //0
			listB.push_back(0); //1
			listB.push_back(0); //2
			Assert::AreEqual(listA.get_size(), listA.find_first(&listB));
			listA.~List(); listB.~List();
		}

		TEST_METHOD(find_first_included_from_0)//ñ ïåðâîãî ýëåìåíòà ðàáîòàåò
		{
			List listA;
			listA.push_back(1); //0
			listA.push_back(2); //1
			listA.push_back(3); //2
			listA.push_back(4); //3
			listA.push_back(5); //4
			List listB;
			listB.push_back(1); //0
			listB.push_back(2); //1
			listB.push_back(3); //2
			Assert::AreEqual((size_t)0, listA.find_first(&listB));
			listA.~List(); listB.~List();
		}
		
		TEST_METHOD(find_first_first_entrance)//âûäàåò èìåííî ïåðâîå âõîæäåíèå
		{
			List listA;
			listA.push_back(1); //0
			listA.push_back(2); //1
			listA.push_back(1); //2
			listA.push_back(2); //3
			listA.push_back(5); //4
			List listB;
			listB.push_back(1); //0
			listB.push_back(2); //1
			Assert::AreEqual((size_t)0, listA.find_first(&listB));
			listA.~List(); listB.~List();
		}

		TEST_METHOD(find_first_half_included_full_included)//ñíà÷àëà âõîäèò ÷àñòè÷íî, ïîòîì öåëèêîì
		{
			List listA;
			listA.push_back(1); //0
			listA.push_back(2); //1
			listA.push_back(1); //2
			listA.push_back(2); //3
			listA.push_back(5); //4
			List listB;
			listB.push_back(1); //0
			listB.push_back(2); //1
			listB.push_back(5); //2
			Assert::AreEqual((size_t)2, listA.find_first(&listB));
			listA.~List(); listB.~List();
		}

		TEST_METHOD(find_first_half_included)//âõîäèò ÷àñòè÷íî
		{
			List listA;
			listA.push_back(1); //0
			listA.push_back(2); //1
			listA.push_back(1); //2
			listA.push_back(2); //3
			listA.push_back(5); //4
			List listB;
			listB.push_back(1); //0
			listB.push_back(2); //1
			listB.push_back(6); //2
			Assert::AreEqual(listA.get_size(), listA.find_first(&listB));
			listA.~List(); listB.~List();
		}

		TEST_METHOD(find_first_second_array_is_empty) //ñïèñîê Â ïóñò
		{
			List listA;
			listA.push_back(1); //0
			listA.push_back(2); //1
			listA.push_back(1); //2
			listA.push_back(2); //3
			listA.push_back(5); //4
			List listB;
			Assert::AreEqual((size_t)0, listA.find_first(&listB));
			listA.~List(); listB.~List();
		}

		TEST_METHOD(find_first_first_array_is_empty) //ïåðâûé ñïèñîê ïóñò
		{
			List listA;
			listA.push_back(1); //0
			listA.push_back(2); //1
			listA.push_back(1); //2
			listA.push_back(2); //3
			listA.push_back(5); //4
			List listB;
			Assert::AreEqual(listB.get_size(), listB.find_first(&listA));
			listA.~List(); listB.~List();
		}

		TEST_METHOD(find_first_both_empty) //îáà ïóñòû
		{
			List listA;
			List listB;
			Assert::AreEqual((size_t)0, listA.find_first(&listB));
			listA.~List(); listB.~List();
		}

	};
}
