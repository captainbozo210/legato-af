/**
 * Implement echo test API in C
 *
 * Copyright (C) Sierra Wireless Inc.
 */

#include "legato.h"
#include "interfaces.h"

#include <string.h>

void ipcTest_EchoSimple
(
    int32_t InValue,
    int32_t *OutValuePtr
)
{
    if (OutValuePtr)
    {
        *OutValuePtr = InValue;
    }
}

void ipcTest_EchoSmallEnum
(
    ipcTest_SmallEnum_t InValue,
    ipcTest_SmallEnum_t* OutValuePtr
)
{
    if (OutValuePtr)
    {
        *OutValuePtr = InValue;
    }
}

#if 0
// Not currently supported on Java
void ipcTest_EchoLargeEnum
(
    ipcTest_LargeEnum_t InValue,
    ipcTest_LargeEnum_t* OutValuePtr
)
{
    if (OutValuePtr)
    {
        *OutValuePtr = InValue;
    }
}
#endif

void ipcTest_EchoSmallBitMask
(
    ipcTest_SmallBitMask_t InValue,
    ipcTest_SmallBitMask_t* OutValuePtr
)
{
    if (OutValuePtr)
    {
        *OutValuePtr = InValue;
    }
}

#if 0
// Not currently supported on Java
void ipcTest_EchoLargeBitMask
(
    ipcTest_LargeBitMask_t InValue,
    ipcTest_LargeBitMask_t* OutValuePtr
)
{
    if (OutValuePtr)
    {
        *OutValuePtr = InValue;
    }
}
#endif

void ipcTest_EchoReference
(
    ipcTest_SimpleRef_t InRef,
    ipcTest_SimpleRef_t *OutRef
)
{
    if (OutRef)
    {
        *OutRef = InRef;
    }
}

void ipcTest_EchoString
(
    const char *InString,
    char *OutString,
    size_t OutStringSize
)
{
    if (OutString)
    {
        strncpy(OutString, InString, OutStringSize);
        OutString[OutStringSize-1] = '\0';
    }
}

#if 0
// Not currently supported on Java.
void ipcTest_EchoArray
(
    const int64_t* InArrayPtr,
    size_t InArraySize,
    int64_t* OutArrayPtr,
    size_t* OutArraySizePtr
)
{
    if (OutArrayPtr)
    {
        if (InArraySize <= *OutArraySizePtr)
        {
            memcpy(OutArrayPtr, InArrayPtr, InArraySize*sizeof(int64_t));
            *OutArraySizePtr = InArraySize;
        }
        else
        {
            memcpy(OutArrayPtr, InArrayPtr, (*OutArraySizePtr)*sizeof(int64_t));
        }
    }
}
#endif

COMPONENT_INIT
{
}
