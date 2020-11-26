#ifndef _ACTIVEIDEAGROUP_
#define _ACTIVEIDEAGROUP_

#include <string>
#include <vector>

namespace teuton::parser {
    class ActiveIdeaGroup {
        public:
            ActiveIdeaGroup();
            ~ActiveIdeaGroup();

            void setIdeaName(std::string);
            void setIdeaLevel(int);

            std::string getIdeaName();
            int getIdeaLevel();

        private:
            std::string ideaName;
            int ideaLevel;


    };
}

#endif