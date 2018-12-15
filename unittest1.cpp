#include "stdafx.h"
#include "CppUnitTest.h"
#include "../AiStrD3Lab2/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		// при создании списка его размер равен 0 + работа size_equal
		TEST_METHOD(list_creates_with_size_0)
		{
			List list;
			Assert::IsTrue(list.size_equal(0));
		}
		// работа isEmpty
		TEST_METHOD(creating_list_is_empty)
		{
			List list;
			Assert::IsTrue(list.isEmpty());
		}
		// push_back
		TEST_METHOD(push_back_empty_list) // добавл€ет элемент в пустой лист
		{
			List list;
			list.push_back(5);
			Assert::IsFalse(list.isEmpty());
		}

		TEST_METHOD(increase_size_push_back) //размер увеличиваетс€
		{
			List list;
			list.push_back(5);
			Assert::IsTrue(list.size_equal(1));
		}

		TEST_METHOD(correct_data_push_back) // верное значение + работа equal_tail
		{
			List list;
			list.push_back(5);
			Assert::IsTrue(list.tail_equal(5));
		}

		TEST_METHOD(push_back_add_in_tail)//добавл€ет таки в конец
		{
			List list;
			for (int i = 0; i < 6; i++)
				list.push_back(i);
			Assert::IsTrue(list.tail_equal(5));
		}
		//push front
		TEST_METHOD(empty_list_push_front) //лист становитс€ не пуст
		{
			List list;
			list.push_front(1);
			Assert::IsFalse(list.isEmpty());
		}

		TEST_METHOD(increase_size_push_front) //размер увеличиваетс€
		{
			List list;
			list.push_front(1);
			Assert::IsTrue(list.size_equal(1));
		}

		TEST_METHOD(correct_data_push_front) //добавл€етс€ нужный элемент
		{
			List list;
			list.push_front(0);
			Assert::IsTrue(list.tail_equal(0));
		}

		TEST_METHOD(change_head_push_front) // элемент добавл€етс€ в начало
		{
			List list;
			for (int i = 0; i <= 5; i++)
				list.push_front(i);
			Assert::IsTrue(list.head_equal(5));
		}
		//pop back
		TEST_METHOD(pop_back_list_with_one_elem)//удал€ет единственный элемент
		{
			List list;
			list.push_back(1);
			list.pop_back();
			Assert::IsTrue(list.isEmpty());
		}

		TEST_METHOD(pop_back_delete_last_elem) //удал€ет последний элемент
		{
			List list;
			for (int i = 0; i < 6; i++)
				list.push_back(i);
			list.pop_back();
			Assert::IsTrue(list.tail_equal(4));
		}

		TEST_METHOD(pop_back_decrease_size) //уменьшает размер
		{
			List list;
			list.push_back(1);
			list.pop_back();
			Assert::IsTrue(list.size_equal(0));
		 }

		TEST_METHOD(pop_back_empty_list_exception)//исключение
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
		}
		//pop front
		TEST_METHOD(pop_front_list_with_one_elem)//удал€ет единственный элемент
		{
			List list;
			list.push_back(1);
			list.pop_front();
			Assert::IsTrue(list.isEmpty());
		}

		TEST_METHOD(pop_front_delete_last_elem) //удал€ет первый элемент
		{
			List list;
			for (int i = 0; i < 6; i++)
				list.push_back(i);
			list.pop_front();
			Assert::IsTrue(list.head_equal(1));
		}

		TEST_METHOD(pop_front_decrease_size) //уменьшает размер
		{
			List list;
			list.push_back(1);
			list.pop_front();
			Assert::IsTrue(list.size_equal(0));
		}

		TEST_METHOD(pop_front_empty_list_exception) //исключение: пустой список
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
		}
		//insert
		TEST_METHOD(insert_index_0_add_head_empty_list) //индекс 0 - добавл€етс€ голова 
		{
			List list;
			list.insert(2, 0);
			Assert::IsFalse(list.isEmpty());
		}

		TEST_METHOD(insert_index_size_add_tail) // индекс = размер - добавл€етс€ конец
		{
			List list;
			for (int i = 1; i < 6; i++)
				list.push_back(i);
			list.insert(6, list.get_size());
			Assert::IsTrue(list.tail_equal(6));
		}
		
		TEST_METHOD(insert_increase_size) // увеличивает размер списка
		{
			List list;
			list.push_back(1);
			list.push_back(3);
			list.insert(2, 1);
			Assert::IsTrue(list.size_equal(3));
		}

		TEST_METHOD(insert_index_greater_than_size) //исключение: индекс больше размера
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
		}
		//at
		TEST_METHOD(at_is_correct_index_0)
		{
			List list;
			list.push_back(1);
			list.push_back(3);
			Assert::AreEqual(1, list.at(0));
		}

		TEST_METHOD(at_is_correct_index_size)
		{
			List list;
			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
			Assert::AreEqual(3, list.at(list.get_size()-1));
		}

		TEST_METHOD(at_is_correct_middle)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			Assert::AreEqual(2, list.at(1));
		}

		TEST_METHOD(insert_add_middle)
		{
			List list;
			list.push_back(1);//0
			list.push_back(3);//1
			list.insert(2, 1);// сдвинет 3
			Assert::AreEqual(2, list.at(1));
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
		}

		TEST_METHOD(remove_delete_last)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			list.remove(2);
			Assert::IsTrue(list.tail_equal(2));
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
		}

		TEST_METHOD(remove_decrease_size)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			list.remove(1);
			Assert::IsTrue(list.size_equal(2));
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
		}
		TEST_METHOD(clear_size_equals_0)
		{
			List list;
			list.push_back(1); //0
			list.push_back(2); //1
			list.push_back(3); //2
			list.clear();
			Assert::IsTrue(list.size_equal(0));
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

		TEST_METHOD(find_first_included_from_0)//с первого элемента работает
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
		
		TEST_METHOD(find_first_first_entrance)//выдает именно первое вхождение
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

		TEST_METHOD(find_first_half_included_full_included)//сначала входит частично, потом целиком
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

		TEST_METHOD(find_first_half_included)//входит частично
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

		TEST_METHOD(find_first_second_array_is_empty) //список ¬ пуст
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

		TEST_METHOD(find_first_first_array_is_empty) //первый список пуст
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

		TEST_METHOD(find_first_both_empty) //оба пусты
		{
			List listA;
			List listB;
			Assert::AreEqual((size_t)0, listA.find_first(&listB));
			listA.~List(); listB.~List();
		}

	};
}