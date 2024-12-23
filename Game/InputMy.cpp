#include "InputMy.h"

InputMy::InputMy() {
}

InputMy::~InputMy() {
}

bool InputMy::PressKey(int key) {
	return Novice::CheckHitKey(key);
}
