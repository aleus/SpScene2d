#include "Sp/Camera.h"

using namespace sp;

Camera::Camera()
{

}

void Camera::setTranslation(const Point2dF & translation)
{
    _translation = translation;
}

void Camera::setScale(const Point2dF & scale)
{
    _scale = scale;
}
