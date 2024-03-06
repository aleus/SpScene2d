#pragma once

#include "Sp/IVisualObject.h"
#include "Sp/ConstructorMacros.h"

#include <memory>

namespace sp
{

class ScenePimpl;

class Scene
{
    public:
        Scene();
        ~Scene();
        DELETE_COPY_MOVE_CONSTRUCTOR(Scene)

        /** Добавляет визуальный объект на сцену для отображения. */
        void add(const IVisualObjectCPtr & visualObject);

        /** Удаляет визуальный объект со сцены. */
        void remove(const IVisualObjectCPtr & visualObject);
        
        /** Вызывает обновление и перерисовку сцены. */
        void update();

    private:
        std::unique_ptr<ScenePimpl> _pimpl;
};

} // namespace sp
