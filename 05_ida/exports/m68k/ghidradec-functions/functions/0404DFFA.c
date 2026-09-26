
void _vm_set_error(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x30) = param_2;
  return;
}
