
void _ipc_kobject_set(int param_1,undefined4 param_2,uint param_3)

{
  *(uint *)(param_1 + 4) = param_3 | *(uint *)(param_1 + 4) & 0xffff0000;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}
