#pragma once

#include "Medicine.h"

typedef enum
{
    ACTION_ADD,
    ACTION_DELETE,
    ACTION_UPDATE,
    ACTION_UPDATE_QUANTITY
} ActionType;

typedef struct
{
    ActionType type;
    Medicine medicineBefore;
    Medicine medicineAfter;
    int medicineIndex;
} Action;
