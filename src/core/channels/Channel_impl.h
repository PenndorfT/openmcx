/********************************************************************************
 * Copyright (c) 2020 AVL List GmbH and others
 * 
 * This program and the accompanying materials are made available under the
 * terms of the Apache Software License 2.0 which is available at
 * https://www.apache.org/licenses/LICENSE-2.0.
 * 
 * SPDX-License-Identifier: Apache-2.0
 ********************************************************************************/

#ifndef MCX_CORE_CHANNELS_CHANNEL_IMPL_H
#define MCX_CORE_CHANNELS_CHANNEL_IMPL_H

#include "CentralParts.h"
#include "objects/ObjectContainer.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

// ----------------------------------------------------------------------
// Channel

typedef struct ChannelData {
    Object _; // base class

    // ----------------------------------------------------------------------
    // General Information

    ChannelInfo * info;

    // ----------------------------------------------------------------------
    // Value

    // NOTE: This flag gets set if there is a defined value for the
    // channel during initialization.
    int isDefinedDuringInit;
    const void * internalValue;
    ChannelValue value;

} ChannelData;

// ----------------------------------------------------------------------
// ChannelIn

// object that is stored in target component that stores the channel connection
typedef struct ChannelInData {
    Object _; // base class

    struct Connection * connection;

    // ----------------------------------------------------------------------
    // Conversions

    struct TypeConversion * typeConversion;
    struct UnitConversion * unitConversion;
    struct LinearConversion * linearConversion;
    struct RangeConversion * rangeConversion;

    // ----------------------------------------------------------------------
    // Storage in Component

    int isDiscrete;

    void * reference;
} ChannelInData;

// ----------------------------------------------------------------------
// ChannelOut

// object that is provided to consumer of output channel
typedef struct ChannelOutData {
    Object _; // base class

    // Function pointer that provides the value of the channel when called
    const proc * valueFunction;

    // ----------------------------------------------------------------------
    // Conversion

    struct RangeConversion * rangeConversion;
    struct LinearConversion * linearConversion;

    int rangeConversionIsActive;

    // ----------------------------------------------------------------------
    // NaN Handling

    NaNCheckLevel nanCheck;

    size_t countNaNCheckWarning;
    size_t maxNumNaNCheckWarning;

    // ----------------------------------------------------------------------
    // Connections to Consumers

    // A list of all input channels that are connected to this output channel
    ObjectContainer * connections;

} ChannelOutData;

// ----------------------------------------------------------------------
// ChannelLocal

// object that represents internal channels for storage
typedef struct ChannelLocalData {
    Object _; // base class

} ChannelLocalData;

#ifdef __cplusplus
} /* closing brace for extern "C" */
#endif /* __cplusplus */

#endif /* MCX_CORE_CHANNELS_CHANNEL_IMPL_H */