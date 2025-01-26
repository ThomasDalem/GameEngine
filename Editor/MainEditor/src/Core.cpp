#include "Core.hpp"
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <imgui.h>
#include <SDL2/SDL_events.h>

int mainLoop(Editor::Window &window)
{
    bool quit = false;
    SDL_Event e;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io{ImGui::GetIO()};
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    //io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui_ImplSDL2_InitForSDLRenderer(window.getWindow(), window.getRenderer());
    ImGui_ImplSDLRenderer2_Init(window.getRenderer());
    bool show = true;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            ImGui_ImplSDL2_ProcessEvent(&e);
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();

        if (show)
        {
            ImGui::Begin("Some panel", &show);
            ImGui::Text("Hello World");
            ImGui::End();
        }

            ImGui::Begin("Other panel", &show);
            ImGui::Text("Hello World");
            ImGui::End();

        ImGui::Render();

        SDL_SetRenderDrawColor(window.getRenderer(), 100, 100, 100, 255);
        SDL_RenderClear(window.getRenderer());
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), window.getRenderer());
        SDL_RenderPresent(window.getRenderer());
    }

    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    return 0;
}