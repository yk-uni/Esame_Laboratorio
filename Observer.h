//
// Created by yashk on 06/07/2024.
//

#ifndef ESAME_LABORATORIO_OBSERVER_H
#define ESAME_LABORATORIO_OBSERVER_H

#include <string>

using namespace std;

class Observer {
public:
    virtual ~Observer()=default;

    virtual void update(const string& listName)=0;
};

#endif //ESAME_LABORATORIO_OBSERVER_H
