#include "view/Window.h"


class MyWindow : public ImageEditor::UI::Window
{
public:
	MyWindow(const std::string& title, int width, int height) : Window(title, width, height)
	{
	}

protected:
	void init() override
	{

	}

	void shutdown() override
	{

	}

	void render() override
	{
		ImGui::Text("Hello, ImGui!");
	}
};


int main() {
	MyWindow window("Image Editor", 1200, 800);
	window.run();

	return 0;
}