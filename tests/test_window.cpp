#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
#include "view/Window.h"


class MockWindow : public ImageEditor::UI::Window {
public:
	MockWindow(const std::string& title, int width, int height)
		: Window(title, width, height) {}

	void init() override {}
	void shutdown() override {}
	void render() override {}
};



TEST_CASE("Window should be created successfully", "[Window]") {
	MockWindow window("Test Window", 800, 600);
}

