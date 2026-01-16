/*
 * Copyright (c) 2024 Huawei Technologies Co., Ltd.
 * This file is a part of the CANN Open Software.
 * Licensed under CANN Open Software License Agreement Version 1.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */
#ifndef TILEXR_TYPES_H
#define TILEXR_TYPES_H

#include <hccl_types.h>
#include <map>
#include <string>

namespace TileXR {
constexpr int TILEXR_SUCCESS = 0;
constexpr int TILEXR_ERROR_NOT_INITIALIZED = -1;
constexpr int TILEXR_ERROR_MKIRT = -2;
constexpr int TILEXR_ERROR_PARA_CHECK_FAIL = -3;
constexpr int TILEXR_ERROR_INTERNAL = -4;
constexpr int TILEXR_ERROR_TIMEOUT = -5;
constexpr int TILEXR_ERROR_NOT_FOUND = -7;
constexpr int64_t TILEXR_INVALID_VALUE = -1;

// shared buffer size，这里要和collectives.cce文件中的常量联动修改！！！
constexpr int TILEXR_BUFF_BYTES = 204 * 1024 * 1024;
constexpr int TILEXR_FLAG_BUFF_BYTES = 4 * 1024 * 1024;
constexpr int TILEXR_COMM_BUFFER_SIZE = 200; // 单位MB

enum class ChipName {
    CHIP_310P3 = 0,
    CHIP_910B1,
    CHIP_910B2,
    CHIP_910B3,
    CHIP_910B4,
    CHIP_910B41,
    CHIP_910B2C,
    CHIP_910_9391,
    CHIP_910_9381,
    CHIP_910_9392,
    CHIP_910_9382,
    CHIP_910_9372,
    CHIP_910_9361,
    CHIP_910_9362,
    CHIP_910A5,
    RESERVED,
};

enum class PhysicalLink {
    HCCS = 0,
    PCIE = 1,
    RESERVED,
};

// 包含 物理链路、芯片名称 信息。
struct PhysicalInfo {
    ChipName chipName = ChipName::RESERVED;
    PhysicalLink physicalLink = PhysicalLink::RESERVED;
    uint32_t coreNum = 0;
};

enum class TileXRType {
    ALL_REDUCE = 1,
    TILEXR_TYPE_MAX = 311
};

const std::map<TileXRType, std::string> TILEXR_TYPE2NAME = {
    { TileXRType::ALL_REDUCE, "TileXRAllReduce" },
};


} // namespace TileXR
#endif // TILEXR_TYPES_H
