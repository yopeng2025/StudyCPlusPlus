#include "Account.hpp"
#include <iostream>
#include <ctime>//C标准库的头文件<time.h>
#include <iomanip>
//输入输出的格式化控制 Input/Output Manipulation 
//std::setw(2)（设置宽度为 2） std::setfill('0')（不足位填充 '0'）

//静态成员变量 要在函数外部单独定义
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void    Account::_displayTimestamp(void)
{
    // 1. 获取当前系统时间
    time_t  now = time(0);//从 1970 年至今的总秒数。

    // 2. 将其转换为当地时间结构体
    struct tm *ltm = localtime(&now);//把秒数变成我们看得懂的年、月、日、时、分、秒

    // 3. 按照 [YYYYMMDD_HHMMSS] 格式打印
    std::cout << "["
            << 1900 + ltm->tm_year//tm_year即从1990年开始至今多少年（36）
            << std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon//tm_mon 是从 0 开始的（0-11）
            << std::setfill('0') << std::setw(2) << ltm->tm_mday
            << "_"
            << std::setfill('0') << std::setw(2) << ltm->tm_hour
            << std::setfill('0') << std::setw(2) << ltm->tm_min
            << std::setfill('0') << std::setw(2) << ltm->tm_sec
            << "] ";
    //固定宽度2,如宽度不足2,则填充0
}

int Account::getNbAccounts(void){return _nbAccounts;}
int Account::getTotalAmount(void){return _totalAmount;}
int Account::getNbDeposits(void){return _totalNbDeposits;}
int Account::getNbWithdrawals(void){return _totalNbWithdrawals;}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";"
                << "total:" << getTotalAmount() << ";"
                << "deposits:" << getNbDeposits() << ";"
                << "withdrawals:" << getNbWithdrawals() << std::endl;
}

//每当tests.cpp创建新账户时调用
Account::Account(int initial_deposit)
{
    // 1. 设置该账户的索引（使用当前已有的账户总数作为索引）
    this->_accountIndex = _nbAccounts;
    // 2. 初始化该账户的金额和存取款计数
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    // 3. 更新银行的全局静态变量
    _nbAccounts++;
    _totalAmount += initial_deposit;
    // 4. 打印日志：[时间戳] index:X;amount:Y;created
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"
                << "amount:" << this->_amount << ";"
                << "created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "closed" << std::endl;
}
void    Account::displayStatus(void)const
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";"
            << "amount:" << _amount << ";"
            << "deposits:" << _nbDeposits << ";"
            << "withdrawals:" << _nbWithdrawals << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";"
            << "deposit:" << deposit << ";";
    _amount += deposit;
    _nbDeposits++;
    std::cout << "amount:" << _amount << ";"
            << "nb_deposits:" << _nbDeposits << std::endl;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";"
            << "p_amount:" << _amount << ";";
    if (withdrawal > _amount)
    {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
    else
    {
        _amount -= withdrawal;
        _nbWithdrawals++;
        std::cout << "withdrawal:" << withdrawal << ";"
                << "amount:" << _amount << ";"
                << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
    }
    return true;
}