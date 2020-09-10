#ifndef INPUTMANAGER_HEADER
#define INPUTMANAGER_HEADER

#include "Core.h"
#include <map>
#include <vector>
#include <tuple>
#include <SDL.h>

/*Class responsible for handling inputs from a script perspective.
*/
class MOB_API MOB_InputManager {
public:

	MOB_InputManager();

	~MOB_InputManager();

	/*Processes an incoming SDL event and updates the InputManager info accordingly
	*/
	void ProcessKeyEvent(SDL_Event e);

	/*Return true iff key with KeyCode specified was pressed down this frame.
	*/
	bool WasKeyPressed(const char* KeyName);
	/*Return true iff key with KeyCode specified was released this frame.
	*/
	bool WasKeyReleased(const char* KeyName);
	/*Return true iff key with KeyCode specified is held down this frame.
	*/
	bool IsKeyHeld(const char* KeyName);
	/*Return true iff Mouse1 was pressed this frame.
	*/
	bool WasMousePressed();
	/*Return true iff Mouse1 was released this frame.
	*/
	bool WasMouseReleased();
	/*Return location of the mouse.
	*/
	std::tuple<int, int> GetMouseLocation();

	/*Clears lists of pressed down and released keys/mouse
	*/
	void ResetInputState();

	/*Returns singleton instance of MOB_InputManager.
	*/
	static MOB_InputManager* GetInputManager();

private:

	static MOB_InputManager* instance;

	static bool m_Initialized;

	//char*[] KeyNames = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J"]

	//Vector of keys that were pressed down this frame
	std::vector<const char*> m_KeysPressedThisFrame;

	//Vector of keys that were released this frame
	std::vector<const char*> m_KeysReleasedThisFrame;

	//Map of currently pressed down keys
	std::map<const char*, bool> m_HeldKeys;

	bool m_MouseDownThisFrame = false;

	bool m_MouseUpThisFrame = false;

};

#endif