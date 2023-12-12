//
// Created by Kasper de Bruin on 06/12/2023.
//

#include "LogInWindow.h"
#include "../Application.h"

namespace KBTools::Security {

  void KBTools::Security::LogInWindow::Render() {
    //Center the window
    Application *app = KBTools::Application::GetApplication();

    ImGui::SetNextWindowSize(ImVec2(400, 200));

    //Center the window
    ImGui::SetNextWindowPos(ImVec2(app->GetWindowWidth() / 2 - 200, app->GetWindowHeight() / 2 - 100));

//    ImGuiWindowFlags flags =
//           ;

    ImGui::Begin("Login Panel", &isOpen, m_flags);
    ImGui::AlignTextToFramePadding();
    ImGui::Text("Username:");
    ImGui::InputText("##username", m_username, sizeof(m_username), 0, nullptr, nullptr);
    ImGui::Text("Password:");
    ImGui::InputText("##password", m_password, sizeof(m_password), 0, nullptr, nullptr);
    ImGui::Checkbox("Remember login details", &m_remember);

    if (ImGui::Button("Login")) {
      if (LoginManager::Login(m_username, m_password)) {
        isOpen = false;
      }else{
        CORE_WARN("Login failed");
        //SHOW IMGUI ERROR MESSAGE
        m_failedLogin = true;
      }
    }

    if(m_failedLogin){
      ImGui::TextColored(ImVec4(1,0,0,1), "Login failed");
    }
    ImGui::End();
  }

  LogInWindow::LogInWindow() : UIWindow( ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings |
                                        ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse |
                                        ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse){
  }

  LogInWindow::~LogInWindow() {
  }
}// namespace KBTools::Security