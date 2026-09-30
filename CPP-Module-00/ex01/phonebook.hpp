/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:37:44 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/30 11:30:55 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "contact.hpp"

class   PHONEBOOK
{
    private:
        int     _index;
        bool    _full;
        CONTACT _contacts[9];
    public:
        PHONEBOOK(void);//constructor构造函数 初始化成员变量，自动调用，命名与class一样
        ~PHONEBOOK(void);//destructor析构函数 清理资源 销毁数组contacts对象
        
        void    show_instruction(void);//method函数 调用void PHONEBOOK::show_instruction
        void    set_information(void);
        void    get_information(void)const;
};

#endif
