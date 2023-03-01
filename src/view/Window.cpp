#include <stdexcept>
#include "Window.h"



namespace ImageEditor {

	namespace UI {

		Window::Window(const std::string& title, int width, int height)
			: m_title(title), m_width(width), m_height(height)
		{
			if (!glfwInit()) {
				throw std::runtime_error("Failed to initialize GLFW");
			}

#if defined(__APPLE__)
			const char* glsl_version = "#version 410";
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#else
			const char* glsl_version = "#version 330";
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif



			m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
			if (m_window == NULL) {
				glfwTerminate();
				throw std::runtime_error("Failed to create GLFW window");
			}

			// Initialize GLEW
			glfwMakeContextCurrent(m_window);
			glfwSwapInterval(1); // Enable vsync

			if (glewInit() != GLEW_OK) {
				glfwTerminate();
				throw std::runtime_error("Failed to initalize GLEW");
			}


			// Initialize ImGui
			IMGUI_CHECKVERSION();
			ImGui::CreateContext();
			m_io = std::make_shared<ImGuiIO>(ImGui::GetIO());

			// Initialize GLFW and OpenGL3 bindings for ImGui
			ImGui_ImplGlfw_InitForOpenGL(m_window, true);
			ImGui_ImplOpenGL3_Init(glsl_version);

			// Setup Dear ImGui style
			ImGui::StyleColorsDark();

			init();
		}

		Window::~Window() {
			shutdown();

			// Shutdown GLFW and OpenGL3 bindings for ImGui
			ImGui_ImplOpenGL3_Shutdown();
			ImGui_ImplGlfw_Shutdown();

			// Shutdown ImGui
			ImGui::DestroyContext();

			// Destroy window & terminate GLFW
			glfwDestroyWindow(m_window);
			glfwTerminate();
		}

		void Window::run() {
			while (!glfwWindowShouldClose(m_window)) {
				glfwPollEvents();

				// Start the ImGui frame
				ImGui_ImplOpenGL3_NewFrame();
				ImGui_ImplGlfw_NewFrame();
				ImGui::NewFrame();

				render();

				ImGui::Render();
				glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
				glClear(GL_COLOR_BUFFER_BIT);
				ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

				glfwSwapBuffers(m_window);
			}
		}
		void Window::init()
		{

		}

		void Window::shutdown()
		{

		}
	}
}
