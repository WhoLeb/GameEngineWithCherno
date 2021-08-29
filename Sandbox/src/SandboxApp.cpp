#include <Hazel.h>

#include "Hazel/Core/Input.h"

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("ExampleLayer")
	{
	}

	void OnUpdate() override
	{
		if(Hazel::Input::IsKeyPressed(Hazel::Key::Tab))
			HZ_TRACE("Tab key is pressed (poll)!");
	}

	void OnEvent(Hazel::Event& e) override
	{
		if (e.GetEventType() == Hazel::EventType::KeyPressed)
		{
			Hazel::KeyPressedEvent& ev = (Hazel::KeyPressedEvent&)e;
			if(ev.GetKeyCode() == Hazel::Key::Tab)
				HZ_TRACE("Tab key is pressed(event)!");
			HZ_TRACE("{0}", (char)ev.GetKeyCode());
		}
	}
};

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Hazel::ImGuiLayer());
	}

	~Sandbox()
	{
	}

};

Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}