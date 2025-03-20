/*************************************************************************
 * Copyright (c) 2022-2023, NVIDIA CORPORATION. All rights reserved.
 *
 * See LICENSE.txt for license information
 ************************************************************************/

#include "nccl_net.h"
#include "net_device.h"
#include "proxy.h"

static ncclNet_v11_t* ncclNet_v11;
static ncclCollNet_v11_t* ncclCollNet_v11;

ncclNet_t* getNcclNet_v11(void* lib) {
  ncclNet_v11 = (ncclNet_v11_t*)dlsym(lib, "ncclNetPlugin_v11");
  if (ncclNet_v11) {
    INFO(NCCL_INIT | NCCL_NET, "NET/Plugin: Loaded net plugin %s (v11)", ncclNet_v11->name);
    return ncclNet_v11;
  }
  INFO(NCCL_INIT | NCCL_NET, "NET/Plugin: Failed to find ncclNetPlugin_v11 symbol.");
  return nullptr;
}

ncclCollNet_t* getNcclCollNet_v11(void* lib) {
  ncclCollNet_v11 = (ncclCollNet_v11_t*)dlsym(lib, "ncclCollNetPlugin_v11");
  if (ncclCollNet_v11) {
    INFO(NCCL_INIT | NCCL_NET, "NET/Plugin: Loaded collnet plugin %s (v11)", ncclCollNet_v11->name);
    return ncclCollNet_v11;
  }
  INFO(NCCL_INIT | NCCL_NET, "NET/Plugin: Failed to find ncclCollNetPlugin_v11 symbol.");
  return nullptr;
}
