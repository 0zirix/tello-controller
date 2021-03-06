#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include <QObject>
#include <QVector3D>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>

class FaceDetector : public QObject
{
    Q_OBJECT
public:
    explicit FaceDetector(QObject *parent = nullptr);

    bool enabled;
    float scale_factor;
    int min_neighbors;

signals:
    void faceframe(cv::Mat& matrix);
    void faceoffset(QVector3D& offset);

public slots:
    void detect(cv::Mat& src);

private:
    cv::Mat matrix;
    cv::CascadeClassifier classifier;
};

#endif // FACEDETECTOR_H
