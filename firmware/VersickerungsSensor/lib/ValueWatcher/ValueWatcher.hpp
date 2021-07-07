#pragma once

template <typename T>
class Value
{
public:
    Value(T initial_value, bool initially_valid)
        : value{initial_value}, valid{initially_valid}
    {
    }

    void update(T value, bool valid = true)
    {
        if (this->valid == false && valid == false)
        {
            return;
        }

        this->value = value;
        this->valid = valid;
        this->iteration_number++;
    }

    uint64_t get_iteration_number() const
    {
        return iteration_number;
    }

    const T &get_value() const
    {
        return value;
    }
    bool is_valid() const
    {
        return valid;
    }

private:
    T value;
    bool valid;
    uint64_t iteration_number = 0;
};

template <typename T>
class ValueWatcher
{
public:
    ValueWatcher(Value<T> const *parent)
        : iteration_number{parent->get_iteration_number()},
          parent{parent}
    {
    }

    bool new_value_available()
    {
        return iteration_number != parent->get_iteration_number();
    }

    const T &get_value()
    {
        iteration_number = parent->get_iteration_number();
        return parent->get_value();
    }

    bool is_valid()
    {
        iteration_number = parent->get_iteration_number();
        return parent->is_valid();
    }

private:
    uint64_t iteration_number;
    Value<T> const *parent;
};
