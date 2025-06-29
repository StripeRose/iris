#include "IrisApplication.hpp"

#include <chrono>

bool IrisApplication::HandleStartup()
{
	myWindow.reset(new Atrium::Window());
	myWindow->SetTitle("Iris Application Window");
	myWindow->SetSize(Atrium::Size(640, 480));

	myWindow->OnClosed.Connect(this, [&](auto&) { Exit(); });

	myImGuiHandler.reset(new Atrium::ImGuiHandler(*myWindow, [&]() { HandleGUI(); }));

	myWindow->SetWindowState(Atrium::Window::WindowState::Maximized);
	myWindow->Show();

	return true;
}

void IrisApplication::HandleFrameLogic()
{
	static auto startPoint = std::chrono::high_resolution_clock::now();
	const auto millisecondsElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startPoint).count();

	const float secondsElapsed = static_cast<float>(millisecondsElapsed) / 1000.f;

	Atrium::Graphics::ClearColor(
		*myWindow,
		Atrium::Lerp(
			Atrium::Color::Predefined::CornflowerBlue,
			Atrium::Color::Predefined::Orange,
			(Atrium::Sine(secondsElapsed) + 1.f) * 0.5f
		)
	);

	myImGuiHandler->Render();
}

void IrisApplication::HandleShutdown()
{
	
}

void IrisApplication::HandleGUI()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("DMX"))
		{
			myDMXHandler.HandleGUI_MenuItems();
			ImGui::EndMenu();
		}

		ImGui::EndMainMenuBar();
	}

	ImGui::DockSpaceOverViewport(0, 0, ImGuiDockNodeFlags_PassthruCentralNode);

	myDMXHandler.HandleGUI();
}
