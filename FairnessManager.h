#ifndef FAIRNESSMANAGER_H
#define FAIRNESSMANAGER_H

#include "Road.h"

class FairnessManager {
public:
    static bool checkFairness(Road &r) {
        return r.getWaitTime() > 3;
    }
};

#endif