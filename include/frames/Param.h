#ifndef __PARAM__
#define __PARAM__

#include <string>
#include <vector>
#include <memory>

class Param {
    
    public:
        std::vector<int> sizes;
        std::shared_ptr<void> content;

        Param() {}

        Param(std::vector<int> _sizes, std::shared_ptr<void> _content)
            : sizes {_sizes}, content {_content} {} 

};

#endif
