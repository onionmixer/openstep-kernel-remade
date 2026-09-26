
void _thread_timeout_setup(int param_1)

{
  *(code **)(param_1 + 0x130) = _thread_timeout;
  *(int *)(param_1 + 0x134) = param_1;
  _init_timeout_element(param_1 + 0x110);
  *(code **)(param_1 + 0x160) = _thread_depress_timeout;
  *(int *)(param_1 + 0x164) = param_1;
  _init_timeout_element(param_1 + 0x140);
  return;
}
