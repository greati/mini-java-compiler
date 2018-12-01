#ifndef __MJUTILS__
#define __MJUTILS__

#include <string>
#include <vector>

class MJUtils {

    private:

        inline static std::string repeat(std::string c, int n) {
            std::string ret = "";
            while(n > 0) {
                ret += c;
                n--;
            }
            return ret;
        }

        inline static std::string makeLhs(std::string id, std::string iterVar, int n) {
            std::string ret = id;
            for (int i = 0; i < n; ++i)
                ret += "[" + iterVar + std::to_string(i) + "]";
            return ret;
        }

        inline static std::string makeMalloc(std::string baseType, std::vector<int> sizes, int dim, std::string id){
            std::string ret = "";
            int n = sizes.size()-dim;
            std::string lhs = (dim == 0) ? (baseType + repeat("*",n) + " " + id) : makeLhs(id, "i", dim);
            std::string mallocType = baseType + repeat("*", n-1);
            ret += lhs + " = " + "(" + baseType+ repeat("*", n)  + ") malloc(sizeof(" + mallocType + ") * " + std::to_string(sizes[dim]) + ");\n";
            return ret;
        }

    public:


        inline static std::string arrayCreationString(std::string baseType, std::vector<int> sizes, std::string id) {

            std::string ret = "";

            int dim = 0;
            int totalDims = sizes.size();

            while(dim != totalDims) {
                for (int i = 0; i < dim; ++i) {
                    ret += "for (int i"+std::to_string(i)+"=0; i"+std::to_string(i)+"< " + 
                        std::to_string(sizes[i]) + "; ++i"+std::to_string(i)+")\n";
                }

                ret +=makeMalloc(baseType, sizes, dim, id);
                dim++;
            }
            return ret;
        }

};

#endif
