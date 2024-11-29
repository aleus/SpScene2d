#pragma once

#define DELETE_COPY_MOVE_CONSTRUCTOR(Class) \
    DELETE_COPY_CONSTRUCTOR(Class)          \
    DELETE_MOVE_CONSTRUCTOR(Class)

#define DELETE_COPY_CONSTRUCTOR(Class) \
    Class(const Class &) = delete;     \
    Class & operator=(const Class &) = delete;

#define DELETE_MOVE_CONSTRUCTOR(Class) \
    Class(Class &&) = delete;          \
    Class & operator=(Class &&) = delete;
