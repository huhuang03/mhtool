//
// Created by th on 2022/2/20.
//

#ifndef MH_TOOL_SRC_MH_SCENE_H_
#define MH_TOOL_SRC_MH_SCENE_H_
#include <string>
#include <opencv2/core.hpp>

namespace mh {

/**
 * 这里的场景就是普通的场景，场景一定有名字，可以显示坐标的
 *
 * better to decide the little map size or the cv do that?
 */
class Scene {
 public:
  std::string name;
  cv::Size2i size;
  cv::Size2i mapSize;
  bool hasMap;
  cv::Rect2i showMap();
};
}
#endif //MH_TOOL_SRC_MH_SCENE_H_
