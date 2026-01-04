#include "IrisApplication.hpp"

#include "Atrium_Color.hpp"

#include "Atrium_FrameContext.hpp"
#include "Atrium_GraphicsAPI.hpp"
#include "Atrium_RenderTexture.hpp"
#include "Atrium_WindowManagement.hpp"

#include <chrono>

bool IrisApplication::HandleStartup()
{
	myWindow = GetWindowHandler().NewWindow();
	myWindow->SetTitle("Iris Application Window");
	myWindow->SetSize(Atrium::Vector2<int>(640, 480));
	myWindow->SetWindowState(Atrium::Window::WindowState::Maximized);

	myWindow->OnClosed.Connect(this, [&]() { Exit(); });

	myWindowTarget = GetGraphicsHandler().GetResourceManager().CreateRenderTextureForWindow(*myWindow);

	#if IS_IMGUI_ENABLED
	myImGuiContext.reset(new Atrium::Extension::DearImGuiContext(myWindow, myWindowTarget, [&]() { HandleGUI(); }));
	#endif

	myWindow->Show();

	return true;
}

void IrisApplication::HandleFrameLogic(Atrium::FrameGraphicsContext& aFrameContext)
{
	static auto startPoint = std::chrono::high_resolution_clock::now();
	const auto millisecondsElapsed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - startPoint).count();

	const float secondsElapsed = static_cast<float>(millisecondsElapsed) / 1000.f;

	aFrameContext.ClearColor(
		myWindowTarget,
		Atrium::Lerp(
			Atrium::Color::Predefined::CornflowerBlue,
			Atrium::Color::Predefined::Orange,
			(Atrium::Sine(secondsElapsed) + 1.f) * 0.5f
		)
	);

	#if IS_IMGUI_ENABLED
	myImGuiContext->Render(aFrameContext);
	#endif
}

void IrisApplication::HandleShutdown()
{
	
}


#if IS_IMGUI_ENABLED
void IrisApplication::HandleGUI()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			ImGui::BeginDisabled();
			ImGui::Selectable("New");
			ImGui::Selectable("Open..");
			ImGui::Selectable("Save..");
			ImGui::Selectable("Save as..");
			ImGui::EndDisabled();
			ImGui::EndMenu();
		}

		ImGui::EndMainMenuBar();
	}

	ImGui::DockSpaceOverViewport(0, 0, ImGuiDockNodeFlags_PassthruCentralNode);
}
#endif
