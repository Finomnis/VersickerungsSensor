#pragma once

#include "tinyfsm.hpp"

#include <Arduino.h>

namespace SystemStateMachine::States::ChangeTimeStateMachine
{
    struct IncreaseValue : tinyfsm::Event
    {
    };

    struct NextField : tinyfsm::Event
    {
    };

    class ChangeTimeState
        : public tinyfsm::Fsm<ChangeTimeState>
    {
        // tinyfsm needs access to react, entry and exit function
        friend class Fsm;

    public:
        static int32_t highlight_start();
        static int32_t highlight_end();

    private:
        /* default reaction for unhandled events */
        void react(tinyfsm::Event const &){};

        /* react overloads */
        virtual void react(IncreaseValue const &){};
        virtual void react(NextField const &){};

        virtual int32_t get_highlight_start() const = 0;
        virtual int32_t get_highlight_end() const = 0;

        void entry(void){};
        void exit(void){};
    };

    namespace States
    {
        class Finished
            : public ChangeTimeState
        {
            inline int32_t get_highlight_start() const override
            {
                return 0;
            }
            inline int32_t get_highlight_end() const override
            {
                return 0;
            }
        };

        class EditYear
            : public ChangeTimeState
        {
            void react(IncreaseValue const &e) override;
            inline void react(NextField const &e) override
            {
                transit<Finished>();
            }

            inline int32_t get_highlight_start() const override
            {
                return 0;
            }
            inline int32_t get_highlight_end() const override
            {
                return 2;
            }
        };

        class EditMonth
            : public ChangeTimeState
        {
            void react(IncreaseValue const &e) override;
            inline void react(NextField const &e) override
            {
                transit<EditYear>();
            }

            inline int32_t get_highlight_start() const override
            {
                return 3;
            }
            inline int32_t get_highlight_end() const override
            {
                return 5;
            }
        };

        class EditDay
            : public ChangeTimeState
        {
            void react(IncreaseValue const &e) override;
            inline void react(NextField const &e) override
            {
                transit<EditMonth>();
            }

            inline int32_t get_highlight_start() const override
            {
                return 6;
            }
            inline int32_t get_highlight_end() const override
            {
                return 8;
            }
        };

        class EditHour
            : public ChangeTimeState
        {
            void react(IncreaseValue const &e) override;
            inline void react(NextField const &e) override
            {
                transit<EditDay>();
            }

            inline int32_t get_highlight_start() const override
            {
                return 9;
            }
            inline int32_t get_highlight_end() const override
            {
                return 11;
            }
        };

        class EditMinute
            : public ChangeTimeState
        {
            void react(IncreaseValue const &e) override;
            inline void react(NextField const &e) override
            {
                transit<EditHour>();
            }

            inline int32_t get_highlight_start() const override
            {
                return 12;
            }
            inline int32_t get_highlight_end() const override
            {
                return 14;
            }
        };
    }
}
