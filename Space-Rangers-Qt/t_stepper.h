#ifndef T_STEPPER_H
#define T_STEPPER_H

template <typename t_value>
class t_stepper {
public:
    t_stepper(const t_value initial, const t_value step)
        : _value { initial }
        , _step { step }
    {
    }

    t_value next() const {
        const t_value value { _value };

        _value = (_value + _step);

        return value;
    }

    t_value previous() const {
        const t_value value { _value };

        _value = (_value - _step);

        return value;
    }

private:
    mutable t_value _value {};

    const t_value _step {};
};

void test();

#endif // T_STEPPER_H
