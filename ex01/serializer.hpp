/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:33:26 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/23 16:27:08 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "data.hpp"
#include <stdint.h>
#include <iostream>

const std::string YELLOW = "\033[33m";
const std::string ORANGE = "\033[38;5;214m";
const std::string PINK = "\033[38;5;200m";
const std::string RESET = "\033[0m"; 

class serializer
{
private:
    serializer();
    serializer(const serializer &cpy);
    serializer &operator=(const serializer& other);
public:
    static uintptr_t serialize(data *ptr);
    static data* deserialize(uintptr_t deserial);
};


#endif