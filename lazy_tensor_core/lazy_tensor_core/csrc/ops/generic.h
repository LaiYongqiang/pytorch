#pragma once

#include "lazy_tensor_core/csrc/ts_backend/TsNode.h"

namespace torch_lazy_tensors {
namespace ir {
namespace ops {

// Generic IR Node implementation for nodes which can simply be described by a
// specific OpKind and a lowering function. IR nodes carrying metadata should
// not be using this class (and have the metadata captured by the LowerFn), but
// they should instead create a dedicated IR node. Doing the former would limit
// IR introspection.
class Generic : public TsNode {
 public:
  Generic(OpKind op, OpList operands,
          torch::lazy::Shape shape, size_t num_outputs = 1,
          torch::lazy::hash_t hash_seed = static_cast<uint32_t>(0x5a2d296e9));

  Generic(OpKind op, OpList operands,
          const std::function<torch::lazy::Shape()>& shape_fn,
          size_t num_outputs = 1, torch::lazy::hash_t hash_seed = static_cast<uint32_t>(0x5a2d296e9));

  Generic(OpKind op, OpList operands,
          size_t num_outputs = 1, torch::lazy::hash_t hash_seed = static_cast<uint32_t>(0x5a2d296e9));

  Generic(OpKind op, torch::lazy::Shape shape, size_t num_outputs,
          torch::lazy::hash_t hash_seed);

 private:
  torch::lazy::hash_t hash_seed_;
};

}  // namespace ops
}  // namespace ir
}  // namespace torch_lazy_tensors
