
uint * _ipc_entry_lookup(int param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  
  if (param_2 >> 8 < *(uint *)(param_1 + 0x10)) {
    puVar2 = (uint *)((param_2 >> 8) * 0x10 + *(int *)(param_1 + 0xc));
    uVar1 = *puVar2;
    if (param_2 << 0x18 == (uVar1 & 0xff000000)) {
      if ((uVar1 & 0x1f0000) == 0) {
        return (uint *)0x0;
      }
      return puVar2;
    }
    uVar1 = uVar1 & 0x800000;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x30);
  }
  if (uVar1 == 0) {
    return (uint *)0x0;
  }
  puVar2 = (uint *)_ipc_splay_tree_lookup(param_1 + 0x18,param_2);
  return puVar2;
}

