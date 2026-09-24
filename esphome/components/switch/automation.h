#pragma once

#include "esphome/core/component.h"
#include "esphome/core/automation.h"
#include "esphome/components/switch/switch.h"

namespace esphome::switch_ {

template<typename... Ts> class SwitchCondition final : public Condition<Ts...> {
 public:
  SwitchCondition(Switch *parent, bool state) : parent_(parent), state_(state) {}
  bool check(const Ts &...x) override { return this->parent_->state == this->state_; }

 protected:
  Switch *parent_;
  bool state_;
};

}  // namespace esphome::switch_
