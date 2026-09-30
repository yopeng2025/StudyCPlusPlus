/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:37:41 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/29 17:05:38 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>

class CONTACT
{
    private:
        static std::string  _fields_name[5];//static：所有 Contact 对象共用同一份
        std::string         _informations[5];
        
        enum Field //枚举 根据第一个的值0,自动填充剩余的值1234
        {
            FirstName = 0,
            LastName,
            NickName,
            PhoneNumber,
            DarkestSecret
        };
    public:
        CONTACT();
        ~CONTACT();
        bool    set_contact();//method函数
        void    get_contact(int i)const;  
        void    get_specific_contact(void)const;  
};     

#endif