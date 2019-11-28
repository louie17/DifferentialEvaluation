// MTADE.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <memory>

#include "differential_evolution.hpp"
#include "objective_function.h"

using namespace de;

#define VARS_COUNT 20
#define POPULATION_SIZE 200

int main(int argc, char *argv[])
{
	try
	{
		/**
		* �������ʼ��constraints����
		*
		* ���ȴ���һ��Ĭ��constraints����(double type, min -1.0e6, max 1.0e6)��
		* Ȼ��Ŀ�꺯���е�������������Ϊʵ�����ͣ�-10<=x<=10,-100<=y<=100.
		*/
		constraints_ptr constraints(std::make_shared< constraints >(VARS_COUNT, 1.0e-6, 1.0e6));
		(*constraints)[0] = std::make_shared< real_constraint >(-10, 10);//width
		(*constraints)[1] = std::make_shared< real_constraint >(-100, 100);//depth
		(*constraints)[2] = std::make_shared< real_constraint >(-100, 100);//heigth

		/**
		* ʵ����Ŀ�꺯��
		*
		* Ŀ�꺯���������κ���de :: DVectorPtr��Ϊ����������˫���ȵĺ������ӡ� ������ͨ�����ã�ָ�����ָ�봫�ݡ�
		*/
		sphere_function of;

		/**
		* ʵ������������������һ�����ڲ�ֽ�������һ�����ڴ�����
		*/
		listener_ptr listener(std::make_shared< null_listener >());
		processor_listener_ptr processor_listener(std::make_shared< null_processor_listener >());

		/**
		* �ò��д�������������4����Ŀ�꺯����������ʵ�����������ļ��ϡ�
		*/
		processors< sphere_function >::processors_ptr _processors(std::make_shared< processors< sphere_function > >(4, std::ref(of), processor_listener));

		/**
		* ʵ����һ���򵥵���ֹ���ԣ�������10000��֮��ֹͣ�Ż����̡�
		*/
		termination_strategy_ptr terminationStrategy(std::make_shared< max_gen_termination_strategy >(1000));

		/**
		* ʵ����ѡ�����-���ǽ�ʹ����õĸ�/�Ӳ���
		*/
		selection_strategy_ptr selectionStrategy(std::make_shared< best_parent_child_selection_strategy >());

		/**
		* ʵ�����������-���ǽ�ʹ�ñ������1��Ȩ�غͽ������ӷֱ�����Ϊ0.5��0.9
		*/
		mutation_strategy_arguments mutation_arguments(0.5, 0.9);
		mutation_strategy_ptr mutationStrategy(std::make_shared< mutation_strategy_1 >(VARS_COUNT, mutation_arguments));

		/**
		* ʹ����ǰ�����Լ�������������������͸��ֲ���ʵ������ֽ�����
		*/
		differential_evolution< sphere_function > de(VARS_COUNT, POPULATION_SIZE, _processors, constraints, true, terminationStrategy, selectionStrategy, mutationStrategy, listener);

		/**
		* �����Ż�����
		*/
		de.run();

		/**
		* ���Ż������л����Ѹ���
		*/
		individual_ptr best(de.best());

		/**
		* Print out the result
		*/
		std::cout << "minimum value for the " << /*of->name() << */" is " << best->cost() << " for x=" << (*best->vars())[0] << ", y=" << (*best->vars())[1] << std::endl;
	}
	catch (const de::exception& e)
	{
		/**
		* Print out any errors that happened during the initialization
		* or optimization phases
		*/
		std::cout << "an error occurred: " << e.what();
	}

	return 0;
}

