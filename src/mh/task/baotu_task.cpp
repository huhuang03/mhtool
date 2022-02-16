//
// Created by huhua on 2022/2/15.
//
#include <mhtool/mh/task/baotu_task.h>
#include <mhtool/mh/mh.h>
#include <mhtool/comm/log.h>

Result BaotuTask::run() {
  try {
    MH::inst()->checkHasLogin().checkWithThrow();
    auto xiaoer = mh::city::changan->jiudian->xiaoer;
    xiaoer->come().checkWithThrow();
    xiaoer->clickMe().checkWithThrow();
    BaotuTaskInfo info;
    xiaoer->takeBaotuTask(&info).checkWithThrow();
    // assert have the task.
  } catch (std::runtime_error &err) {
    std::cerr << err.what() << std::endl;
  }
  try {
    auto xiaoer = mh::city::changan->jiudian->xiaoer;
    xiaoer->come().checkWithThrow();
    xiaoer->clickMe().checkWithThrow();
    BaotuTaskInfo info;
    xiaoer->takeBaotuTask(&info).checkWithThrow();
    // assert have the task.
  } catch (std::runtime_error &err) {
    Log::i(err.what());
  }
}