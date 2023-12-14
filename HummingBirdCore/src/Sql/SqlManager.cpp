//
// Created by Kasper de Bruin on 07/12/2023.
//

#include "SqlManager.h"

namespace HummingBirdCore::Sql {
  bool SqlManager::Init(const std::string &host, const std::string &username, const std::string &password) {
    if(s_initialized){
      CORE_WARN("SqlManager is already initialized");
      return false;
    }
    s_mainConnection = new SqlConnection(host);
    if (!s_mainConnection->Connect()) {
      CORE_ERROR("Could not connect to main sql server");
      return false;
    }
    s_initialized = true;
    return true;
  }

  void SqlManager::Shutdown() {
    s_mainConnection->Disconnect();
    delete s_mainConnection;
  }
  SqlConnection *SqlManager::GetMainConnection() {
    if (!s_mainConnection->IsConnected()) {
      CORE_ERROR("Main connection is not connected");
    }
    return s_mainConnection;
  }
}// namespace HummingBirdCore::Sql