#pragma once

#include <string>
#include <memory>

#include "imgui.h"

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "GL/glew.h"
#include <GLFW/glfw3.h>



namespace ImageEditor {
	namespace UI {
		class Window
		{
		public:
			Window(const std::string& title, int width, int height);
			virtual ~Window();

			virtual void render() = 0;

			void run();

		protected:
			virtual void init();
			virtual void shutdown();

			std::shared_ptr<ImGuiIO> m_io;
			GLFWwindow* m_window;
			int m_height, m_width;
			std::string m_title;
		};
	}
}
