//
// Created by huhua on 2021/9/28.
//

#include <gtest/gtest.h>
#include <iostream>
//#include <algorithm>
#include "mhtool/mh/mh.h"
#include <mhtool/mh/mh_path.h>
#include <easybot/easybot.h>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <qt_windows.h>
#endif

static void startApp1(MH &mh);

using namespace mh;

TEST(TestMM, screenshot) {
  // ok, do the work.
//  eb::Process::printAllProcess("mhmain.exe");
//  auto p = eb::Process::findByName("mhmain.exe");
//  auto w = p.getBiggestWindow();
//  cv::Mat mat;
//  w.screenshot(mat);
//
//  ::cv::Mat roi(mat, ::cv::Range(28, 628), ::cv::Range(0, 800));
  MH mh;
  mh.refresh();
  cv::Mat mat;
  mh.gameWin()->screenshot(mat, 1);
  std::cout << "channel: " << mat.channels() << "imgSize: " << mat.size().width << ", height: " << mat.size().height << std::endl;
  cv::imshow("im", mat);
  cv::waitKey(0);

  cv::imwrite("tmp.bmp", mat);
//  std::cout << "p: " << p.getPid() << std::endl;
}

TEST(test_mm, isInstalled) {
  MH mh;
  startApp1(mh);
//    std::cout << mm.getInstallPath() << std::endl;
//    std::cout << mm.getPath().launcherPath() << std::endl;
//    auto myPath = mm.getPath().launcherPath();
//    boost::replace_all(myPath, " ", "^ ");
//    boost::replace_all(myPath, "(", "^(");
//    boost::replace_all(myPath, ")", "^)");
////    std::replace(myPath.begin(), myPath.end(), " ", "^ ");
//    std::cout << "myPath: " << myPath << std::endl;
//    system(myPath.c_str());
  getchar();
}

static void startApp1(MH &mh) {
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
  MhPath path = mh.getPath();
  // additional information
  STARTUPINFO si;
  PROCESS_INFORMATION pi;

  // set the size of the structures
  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  ZeroMemory(&pi, sizeof(pi));

  // start the program up
  CreateProcess(path.launcherPath().c_str(),   // the path
                "",        // Command line
                NULL,           // Process handle not inheritable
                NULL,           // Thread handle not inheritable
                FALSE,          // Set handle inheritance to FALSE
                0,              // No creation flags
                NULL,           // Use parent's environment block
                mh.getInstallPath().c_str(),           // Use parent's starting directory
                &si,            // Pointer to STARTUPINFO structure
                &pi             // Pointer to PROCESS_INFORMATION structure (removed extra parentheses)
  );
  // Close process and thread handles.
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);
#endif
}

