#pragma once

#include"List.h"

template<class PType>
class Stack
{
private:
    List<PType> L1;

public:
    void includeTop(PType pIn)
    {
        L1.includeTop(pIn);
    }

    void includeBottom(PType pIn)
    {
        L1.includeBottom(pIn);
    }

    PType removeTop()
    {
        return L1.remove(0);
    }

    PType removeBottom()
    {
        return L1.remove(L1.getListSize()-1);
    }



    PType getTop()
    {
        return L1[0];
    }

    int getStackSize()
    {
        return L1.getListSize();
    }
};
