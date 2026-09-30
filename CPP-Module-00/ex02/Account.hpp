// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

class Account {


public:

	typedef Account		t;//给“类”起的别称“t”

	static int	getNbAccounts( void );//静态函数只能访问静态变量
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	Account( int initial_deposit );//constructor构造函数
	~Account( void );//destructor析构函数 main中return0时执行

	void	makeDeposit( int deposit );//method方法
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;//只读，不修改数据
	void	displayStatus( void ) const;


private://私有 外部不能直接看

	static int	_nbAccounts;//静态成员变量（Static Members） 属于“类”，类内共享
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );//静态函数只能访问静态变量

	//每一个客户的个人信息
	int				_accountIndex;//每创建一个对象object，自动分配一套独立的内存
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

//私有constructor构造函数，必须用公有Account(int initial_deposit)来开户
	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
