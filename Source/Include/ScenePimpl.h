#pragma once

#include "Sp/ConstructorMacros.h"

#include <memory>
#include <vector>

namespace sp
{

class IVisualObject;
class IRenderFilter;
class IPainterLayer;

class ScenePimpl
{
    public:
        ScenePimpl();
        ~ScenePimpl();
        DELETE_COPY_MOVE_CONSTRUCTOR(ScenePimpl)

        void add(const std::shared_ptr<const IVisualObject> & visualObject);
        void remove(const std::shared_ptr<const IVisualObject> & visualObject);

        void update() const;

    private:
        // TODO Сделать контейнер дружественным к удалениям из середины.
        // Для этого при удалении нужно занулять указатель, но не удалять из контейнера,
        // и увеличивать счётчик удалённых объектов. Когда счётчик перевалит некую величину,
        // проводить очистку вектора.
        // Кроме этого ввести функции begin/end для удаления нескольких объектов.
        // Лучше использовать RAII-объект для этого.
        std::vector<std::shared_ptr<const IVisualObject>> _visualObjects;

        std::vector<std::unique_ptr<IRenderFilter>> _renderFilters;

        std::vector<std::unique_ptr<IPainterLayer>> _painters;
};

} // namespace sp
