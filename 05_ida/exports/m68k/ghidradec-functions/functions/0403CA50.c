
void _ipc_hash_local_insert(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = (param_2 >> 6) % *(uint *)(param_1 + 0x10);
  while (*(int *)(*(int *)(param_1 + 0xc) + 0xc + uVar1 * 0x10) != 0) {
    uVar1 = uVar1 + 1;
    if (*(uint *)(param_1 + 0x10) == uVar1) {
      uVar1 = 0;
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc + uVar1 * 0x10) = param_3;
  return;
}
