/* Copyright 2017 The OpenXLA Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include "xla/frontend_attributes.h"

#include "xla/hlo/ir/hlo_instruction.h"
#include "xla/xla_data.pb.h"

namespace xla {

void SetDisjointReadWriteRegionsAttr(HloInstruction* instruction) {
  FrontendAttributes attrs;
  (*attrs.mutable_map())[xla::kXlaDisjointReadWriteRegions] = "true";
  instruction->add_frontend_attributes(attrs);
}

bool HasDisjointReadWriteRegionsAttr(HloInstruction* instruction) {
  return instruction->frontend_attributes().map().contains(
      xla::kXlaDisjointReadWriteRegions);
}

}  // namespace xla
