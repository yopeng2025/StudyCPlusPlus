// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"

//模拟银行的一系列操作（开户、查询、存款、再查询、取款、最终查询），
//以此来验证编写的 Account.cpp 逻辑是否正确
int		main( void ) {

	//创建容器vector，即动态数组，可随时添加删减元素，无需分配内存
	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	//键值对pair 将2个指针捆绑在一起，成员：accounts_t的迭代器，ints_t的迭代器
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );//遍历amounts[]从第一个到最后一个数字之后
	accounts_t::iterator	acc_begin	= accounts.begin(); //返回指向第一个元素
	accounts_t::iterator	acc_end		= accounts.end(); //返回指向最后一个元素之后位置 类似\0

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	//输出当前银行的总览信息（总账户、总金额等）
	Account::displayAccountsInfos();//静态函数
	//输出每个账户的个人金额
	//for_each自动化循环，自动完成从begin到end的过程
	//member function reference（成员函数引用适配器），每轮到一个account就要执行displayStatus
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		//让每个账户存下对应的存款金额
		(*(it.first)).makeDeposit( *(it.second) );
		//解引用 即Account指向的对象 和 int指向的存款金额
		//类似于account.makeDeposit(deposite)， 让account执行makeDeposit函数，参数是d[]的其中一个数额
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );//取款
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
