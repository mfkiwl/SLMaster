/**
 * @file circleGridCalibrator.h
 * @author Evans Liu (1369215984@qq.com)
 * @brief
 * @version 0.1
 * @date 2024-03-19
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef CIRCLEGRIDCALIBRATOR_H
#define CIRCLEGRIDCALIBRATOR_H

#include "calibrator.h"

namespace slmaster {
namespace calibration {

class SLMASTER_API CircleGridCalibrator : public Calibrator {
  public:
    CircleGridCalibrator();
    ~CircleGridCalibrator();
    bool
    findFeaturePoints(const cv::Mat &img, const cv::Size &featureNums,
                      std::vector<cv::Point2f> &points,
                      const ThreshodMethod threshodType = ADAPTED) override;
    double calibrate(const std::vector<cv::Mat> &imgs, cv::Mat &intrinsic,
                     cv::Mat &distort, const cv::Size &featureNums,
                     float &process,
                     const ThreshodMethod threshodType = ADAPTED,
                     const bool blobBlack = true) override;
    inline void setDistance(const float trueDistance) override {
        distance_ = trueDistance;
    };

  private:
    inline void setRadius(const std::vector<float> &radius) override{};

    float distance_;
};
} // namespace calibration
} // namespace slmaster

#endif // CIRCLEGRIDCALIBRATOR_H
