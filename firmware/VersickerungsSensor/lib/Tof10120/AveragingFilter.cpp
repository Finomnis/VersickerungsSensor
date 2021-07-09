#include "AveragingFilter.hpp"

AveragingFilter::AveragingFilter(uint32_t filter_size)
    : filter_size{filter_size},
      num_values{0},
      sum{0},
      filtered_value{0, false}
{
}

void AveragingFilter::add_sample(uint16_t value)
{
    num_values++;
    sum += value;

    if (num_values >= filter_size)
    {
        filtered_value.update(sum / float(num_values));
        num_values = 0;
        sum = 0;
    }
}

Value<float> const &AveragingFilter::get_filtered_value() const
{
    return filtered_value;
}

void AveragingFilter::set_invalid()
{
    num_values = 0;
    sum = 0;
    filtered_value.update(0, false);
}
