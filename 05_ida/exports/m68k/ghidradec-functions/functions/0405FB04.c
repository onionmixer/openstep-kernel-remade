
void _vm_object_reference(int param_1)

{
  if (param_1 != 0) {
    *(sword *)(param_1 + 0x14) = *(sword *)(param_1 + 0x14) + 1;
  }
  return;
}
