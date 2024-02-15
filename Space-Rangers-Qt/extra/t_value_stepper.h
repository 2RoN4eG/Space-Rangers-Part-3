#ifndef T_VALUE_STEPPER_H
#define T_VALUE_STEPPER_H

template <typename t_value>
class t_value_stepper {
public:
    t_value_stepper(const t_value initial, const t_value step)
        : _value { initial }
        , _step { step }
    {
    }


    t_value get_value_and_generate_next() const {
        const t_value value { _value };

        _value = (_value + _step);

        return value;
    }

    t_value next() const { return get_value_and_generate_next(); }


    t_value get_value_and_generate_previous() const {
        const t_value value { _value };

        _value = (_value - _step);

        return value;
    }

    t_value previous() const {
        return get_value_and_generate_previous();
    }

private:
    mutable t_value _value {};

    const t_value _step {};
};

void test();

#endif // T_VALUE_STEPPER_H
