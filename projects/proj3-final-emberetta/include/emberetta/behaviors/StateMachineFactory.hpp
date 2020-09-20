/*
 * StateMachineFactory.hpp
 *
 *  Created on: Apr 7, 2020
 *      Author: jaked
 */

#ifndef INCLUDE_EMBERETTA_BEHAVIORS_STATEMACHINEFACTORY_HPP_
#define INCLUDE_EMBERETTA_BEHAVIORS_STATEMACHINEFACTORY_HPP_

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "base/StateComponent.hpp"
#include "base/StatesAndTransitions.hpp"
#include "emberetta/behaviors/EmberettaStates.hpp"

class EmberettaStateMachineFactory {
private:

	EmberettaStateMachineFactory(){}  // Private Singleton
	EmberettaStateMachineFactory(EmberettaStateMachineFactory const&) = delete; // Avoid copy constructor.
	void operator=(EmberettaStateMachineFactory const&) = delete; // Don't allow copy assignment.
	EmberettaStateMachineFactory(EmberettaStateMachineFactory const&&) = delete; // Avoid move constructor.
	void operator=(EmberettaStateMachineFactory const&&) = delete; // Don't allow move assignment.

public:

	/**
	 * @return Instance of the Factory
	 */
	static EmberettaStateMachineFactory& getInstance()
	{
		static EmberettaStateMachineFactory inst;
		return inst;
	}

	static std::shared_ptr<StateComponent> bounceState(GameObject & gameObject) {
		std::shared_ptr<StateComponent::State> stationary = std::make_shared<StationaryState>();
		std::shared_ptr<StateComponent::State> sweep = std::make_shared<BounceState>(2.0f, 1.0f);
		std::shared_ptr<StateComponent> sc = std::make_shared<StateComponent>(gameObject);
		sc->setStartState(stationary);
		sc->addTransition(stationary, sweep, std::make_shared<TimedTransition>(60));
		return sc;
	}
	static std::shared_ptr<StateComponent> circleState(GameObject & gameObject) {
		std::shared_ptr<StateComponent::State> stationary = std::make_shared<StationaryState>();
		std::shared_ptr<StateComponent::State> circle = std::make_shared<CircleState>(.01,5.0f, 200.0f, 320.0f,300.0f);
		std::shared_ptr<StateComponent> sc = std::make_shared<StateComponent>(gameObject);
		sc->setStartState(stationary);
		sc->addTransition(stationary, circle, std::make_shared<TimedTransition>(60));
		return sc;
	}
	static std::shared_ptr<StateComponent> straightState(GameObject & gameObject) {
		std::shared_ptr<StateComponent::State> stationary = std::make_shared<StationaryState>();
		std::shared_ptr<StateComponent::State> straight = std::make_shared<MoveAcrossState>(0.0f,3.0f);
		std::shared_ptr<StateComponent> sc = std::make_shared<StateComponent>(gameObject);
		sc->setStartState(stationary);
		sc->addTransition(stationary, straight, std::make_shared<TimedTransition>(60));
		return sc;
	}
	static std::shared_ptr<StateComponent> randomState(GameObject & gameObject,bool seed = false) {
//		if (seed) {
//			srand(time(0));
//		}
//		switch (rand()%3) {
//		case 0:
//			return bounceState(gameObject);
//		case 1:
//			return circleState(gameObject);
//		case 2:
//			return straightState(gameObject);
//		default:
//			return straightState(gameObject);
//		}
		return straightState(gameObject);
	}
};



#endif /* INCLUDE_EMBERETTA_BEHAVIORS_STATEMACHINEFACTORY_HPP_ */
