/*
 * EmberettaCamera.hpp
 *
 *  Created on: Apr 6, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_COMPONENTS_EMBERETTACAMERA_HPP_
#define INCLUDE_EMBERETTA_COMPONENTS_EMBERETTACAMERA_HPP_

#include "base/GenericComponent.hpp"

//! \brief Handles Cleanup of objects outside of world
class EmberettaCamera: public GenericComponent {
public:
	EmberettaCamera(GameObject & gameObject);
	virtual void update(Level & level) override;

private:
	//int m_w {640};
	//int m_h {800};
};



#endif /* INCLUDE_EMBERETTA_COMPONENTS_EMBERETTACAMERA_HPP_ */
