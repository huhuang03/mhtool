//
// Created by huhua on 2021/10/17.
//

#include <utility>
#include <mhtool/mh/mh_window.h>
#include "easybot/window.h"
#include "mhtool/mh/mh.h"

MhWindow::MhWindow(eb::Window mainWindow) : mainWindow(std::move(mainWindow)), _contentWindow(nullptr) {
  auto subWindows = this->mainWindow.getSubWindows();
  for (auto &win : subWindows) {
    auto rect = win.rect();
    if (rect.width == MH::CONTENT_WIDTH && rect.height == MH::CONTENT_HEIGHT) {
      this->_contentWindow = new eb::Window(win.getId());
    }
  }
}

eb::Window *MhWindow::contentWindow() {
  return this->_contentWindow;
}
