#include "Core.hpp"
#include <iostream>
#include <SDL2/SDL_events.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>
#include <imgui.h>

#include "build.hpp"

int mainLoop(SDL::App &app)
{
    bool quit = false;
    SDL_Event e;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    ImGui_ImplSDL2_InitForSDLRenderer(app.getWindow(), app.getRenderer().getRenderer());
    ImGui_ImplSDLRenderer2_Init(app.getRenderer().getRenderer());

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

        ImGui::Begin("Build", nullptr);
        if (ImGui::Button("Build project"))
        {
            buildProject();
        }
        ImGui::End();

        ImGui::Render();

        SDL_RenderSetScale(app.getRenderer().getRenderer(), io.DisplayFramebufferScale.x, io.DisplayFramebufferScale.y);
        SDL_SetRenderDrawColor(app.getRenderer().getRenderer(), 100, 100, 100, 255);
        SDL_RenderClear(app.getRenderer().getRenderer());
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), app.getRenderer().getRenderer());

        SDL_SetRenderDrawColor(app.getRenderer().getRenderer(), 255, 255, 255, 255);

        SDL_RenderPresent(app.getRenderer().getRenderer());
    }

    ImGui_ImplSDLRenderer2_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    return 0;
}