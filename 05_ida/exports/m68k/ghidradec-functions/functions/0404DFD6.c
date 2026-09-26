
void _vm_set_close_flush(int *param_1,int param_2)

{
  *(byte *)(*param_1 + 0x34) = *(byte *)(*param_1 + 0x34) & 0xdf | (param_2 != 0) << 5;
  return;
}
