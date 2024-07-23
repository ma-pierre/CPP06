/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:00:35 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/23 16:38:38 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

int main() {
    data d = {42, 42.42, 'h'};

    std::cout << "Values of Struct data before serialization:\n";
    std::cout << "i = " << YELLOW << d.i << RESET << "\n";
    std::cout << "f = " << PINK << d.f << RESET << "\n";
    std::cout << "c = " << ORANGE << d.c << RESET << std::endl;

    uintptr_t serialized = serializer::serialize(&d);
    data* deserialized = serializer::deserialize(serialized);

    if (deserialized == &d)
    {
        std::cout << "Serialized and deserialized worked as expected\n";
        std::cout << "Values of Struct data after deserialization:\n";
        std::cout << "i = " << YELLOW << deserialized->i << RESET << "\n";
        std::cout << "f = " << PINK << deserialized->f << RESET << "\n";
        std::cout << "c = " << ORANGE << deserialized->c << RESET << std::endl;
    }
    else
        std::cout << "Error\n";
    return (0);
}