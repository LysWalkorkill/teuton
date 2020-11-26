#ifndef _STATEVIEWS_
#define _STATEVIEWS_

#include <string>
#include <vector>

namespace teuton::parser {
    class StateViews {
        public:
            StateViews();
            ~StateViews();

            void setCurrentPowerProjection(float);
            void setPrestige(float);
            void setStability(float);
            void setLegitimacy(float);
            void setManpower(float);
            void setInnovativeness(float);

            float getCurrentPowerProjection();
            float getPrestige();
            float getStability();
            float getLegitimacy();
            float getManpower();
            float getInnovativeness();

        private:
            float currentPowerProjection;
            float prestige;
            float stability;
            float legitimacy;
            float manpower;
            float innovativeness;
    };
}

#endif