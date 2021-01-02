#include "MOB_InputManager.h"


MOB_InputManager::MOB_InputManager() {
	
}

MOB_InputManager::~MOB_InputManager() {

	delete instance;
}

MOB_InputManager* MOB_InputManager::GetInputManager() {
	if (!m_Initialized) {
		instance = new MOB_InputManager;
		m_Initialized = true;
	}
	return instance;
}

MOB_InputManager* MOB_InputManager::instance;

bool MOB_InputManager::m_Initialized;


void MOB_InputManager::ProcessKeyEvent(SDL_Event e) {
	if (e.type == SDL_KEYDOWN) {
		//the below returns non-zero if its a key repeat instead of the first time the key has been pressed since its been held
		if (!e.key.repeat) {
			const char* KeyName = SDL_GetKeyName(e.key.keysym.sym);
			
			m_HeldKeys.emplace(KeyName, true);
			m_KeysPressedThisFrame.push_back(KeyName);
		}
	}
	else if (e.type == SDL_KEYUP) {
		const char* KeyName = SDL_GetKeyName(e.key.keysym.sym);
		m_HeldKeys.emplace(KeyName, false);
		m_KeysReleasedThisFrame.push_back(KeyName);
	}
	if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
		m_MouseDownThisFrame = true;
	}
	else if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT) {
		m_MouseUpThisFrame = true;
	}
}

bool MOB_InputManager::WasKeyPressed(const char* KeyName) {
	for (int i = 0; i < m_KeysPressedThisFrame.size(); i++) {
		//strcmp returns 0 if both char* are equivalant
		if (strcmp(m_KeysPressedThisFrame[i], KeyName) == 0) {
			return true;
		}
	}
	return false;
}

bool MOB_InputManager::WasKeyReleased(const char* KeyName) {
	for (int i = 0; i < m_KeysReleasedThisFrame.size(); i++) {
		//strcmp returns 0 if both char* are equivalant
		if (strcmp(m_KeysReleasedThisFrame[i], KeyName) == 0) {
			return true;
		}
	}
	return false;
}

bool MOB_InputManager::IsKeyHeld(const char* KeyName) {
	if (m_HeldKeys.count(KeyName) > 0) {
		return m_HeldKeys.at(KeyName);
	}
	else {
		return false;
	}
}

bool MOB_InputManager::WasMousePressed() {
	return m_MouseDownThisFrame;
}

bool MOB_InputManager::WasMouseReleased() {
	return m_MouseUpThisFrame;
}

std::tuple<int, int> GetMouseLocation() {
	int x = 0;
	int y = 0;
	SDL_GetMouseState(&x, &y);
	return std::make_tuple(x, y);
}

void MOB_InputManager::ResetInputState() {
	m_KeysPressedThisFrame.clear();
	m_KeysReleasedThisFrame.clear();
	m_MouseDownThisFrame = false;
	m_MouseUpThisFrame = false;
}