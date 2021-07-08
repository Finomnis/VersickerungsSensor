#pragma once

#define NOMOVE_NOCOPY(name)                 \
public:                                     \
    name(const name &) = delete;            \
    name(name &&) = delete;                 \
    name &operator=(const name &) = delete; \
    name &operator=(name &&) = delete;      \
    virtual ~name() = default
