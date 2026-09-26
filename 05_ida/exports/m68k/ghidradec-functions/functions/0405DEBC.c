
void _vm_map_reference(int param_1)

{
  if (param_1 != 0) {
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  }
  return;
}
