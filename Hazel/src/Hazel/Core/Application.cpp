#include "hzpch.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Hazel {

	Application::Application()
	{
		m_Window = Window::Create();
		m_Window->SetEventCallback(HZ_BIND_EVENT_FN(OnEvent));
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(HZ_BIND_EVENT_FN(Application::OnWindowClose));

		HZ_CORE_TRACE("{0}", e);
	}

	void Application::Run() {

		while (m_Running)
		{
			glClearColor(1, 0.6, 0.5, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) 
	{
		m_Running = false;
		return true;
	}
}