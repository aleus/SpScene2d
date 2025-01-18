#pragma once

#include "Sp/ConstructorMacros.h"
#include "Scene2dTypes.h"

namespace sp
{

/** @brief Камера для Scene2d. */
class Camera
{
public:
    Camera();
    DELETE_COPY_MOVE_CONSTRUCTOR(Camera)

    inline const auto & translation() const { return _translation; }
    inline const auto & scale() const { return _scale; }

    void setTranslation(const Point2dF & translation);
    void setScale(const Point2dF & scale);

private:
    Point2dF _translation; ///< Смещение сцены относительно начального положения в единицах сцены
    Point2dF _scale { .x = 1.0, .y = 1.0 }; ///< Масштабирование сцены
};

} // namespace sp
