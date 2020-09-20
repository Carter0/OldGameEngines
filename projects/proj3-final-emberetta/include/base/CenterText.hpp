/*
 * CenterText.hpp
 *
 *  Created on: Apr 6, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_BASE_CENTERTEXT_HPP_
#define INCLUDE_BASE_CENTERTEXT_HPP_

#pragma once

#include <SDL.h>
#include "managers/ResourceManager.hpp"
#include "base/GameObject.hpp"
#include "Util.hpp"
#include "emberetta/ObjectTypes.hpp"

//! \brief Shows You Win.
class CenterText: public GameObject {
public:
	CenterText(Level * level, int localeTag);
	std::ostream& print(std::ostream &out) override;

};



#endif /* INCLUDE_BASE_CENTERTEXT_HPP_ */
