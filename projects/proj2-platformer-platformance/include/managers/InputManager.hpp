#pragma once
#ifndef INCLUDE_PLATFORMACE_INPUTMANAGER_HPP_
#define INCLUDE_PLATFORMACE_INPUTMANAGER_HPP_

#include <SDL.h>
#include <set>
#include "TinyMath.hpp"

//! \brief Class for managing (keyboard) input.
class InputManager {
private:

  InputManager() = default; // Private Singleton
  InputManager(InputManager const&) = delete; // Avoid copy constructor.
  void operator=(InputManager const&) = delete; // Don't allow copy assignment.
  
public:

  /**
   * @returns A reference to the InputManager singleton
   */
  static InputManager &getInstance(); //!< Get the instance.

  /**
   * Starts the InputManager
   */
  void startUp();

  /**
   * Stops the InputManager
   */
  void shutDown();

  void resetForFrame(); //!< Reset key state for a new frame.
  void handleEvent(const SDL_Event & e); //!< Update key state based on an event.
  bool isKeyDown(SDL_Keycode k) const; //!< Get if a key is currently down.
  bool isKeyPressed(SDL_Keycode k) const; //!< Get if a key was pressed this frame.

  /**
   * Checks to see if leftMouse is clicked
   * @returns true if it is clicked
   */
  inline bool isLeftMouseClicked() { return leftBClicked; }

  /**
   * Checks to see if rightMouse is clicked
   * @returns true if it is clicked
   */
  inline bool isRightMouseClicked() { return rightBClicked; }

  /**
   * Checks to see if leftButton is down
   * @returns true if it is pressed
   */
  inline bool isLeft() { return leftB; }

  /**
   * Checks to see if right Mouse is donw
   * @returns true if it is pressed
   */
  inline bool isRight() { return rightB; }

  /**
   * Gives the user the mouse position relative to the SDL window
   * @returns Vector2D of the mouse position
   */
  inline Vector2D getMousePos() { return Vector2D(mouseX, mouseY);}
  
private:

  std::set<SDL_Keycode> mKeysDown;
  std::set<SDL_Keycode> mKeysPressed;
  bool leftB = false;
  bool rightB = false;
  bool leftBClicked = false;
  bool rightBClicked = false;
  int mouseX, mouseY;

};

#endif

