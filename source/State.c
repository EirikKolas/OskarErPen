#include "driver/elevio.h"
#include "State.h"



typedef struct OrtState {
    int lastFloor;
    Direction direction;
} OrtState;

static OrtState t = {-1,DOWN};

void updateLastFloor()
{
    int floor = elevio_floorSensor();
    if (floor != -1){
        t.lastFloor = floor;
    }
    return;
}
int getLastFloor()
{
    return t.lastFloor;
}

int getFloor()
{
    return elevio_floorSensor();
}

Direction getDirection()
{
    return t.direction;
}

void setDirection(Direction dir)
{
    t.direction = dir;
    return;
}

void swapDirection()            //Does not swap none, sjekka opp/ned hele tiden shady
{
    switch (getDirection())
    {
    case UP:
        setDirection(DOWN);
        break;
     case DOWN:
        setDirection(UP);
        break;
    default:
        break;
    }
}
/*
Action getAction()
{
    //return t.action;
}

void setAction(Action a)
{
    //t.action = a;
    return;
}*/