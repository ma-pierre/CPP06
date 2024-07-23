/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <mapierre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:37:08 by mapierre          #+#    #+#             */
/*   Updated: 2024/07/23 16:04:24 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.hpp"

uintptr_t serializer::serialize(data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

data* serializer::deserialize(uintptr_t deserial)
{
    return (reinterpret_cast<data*>(deserial));
}
