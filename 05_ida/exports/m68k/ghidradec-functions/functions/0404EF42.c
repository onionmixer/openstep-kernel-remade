
void _pset_init(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x100) = 0x1f;
  *(undefined4 *)(param_1 + 0x104) = 0;
  iVar1 = 0;
  iVar2 = param_1;
  do {
    *(int *)(iVar2 + 4) = iVar2;
    *(int *)iVar2 = iVar2;
    iVar2 = iVar2 + 8;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  iVar1 = param_1 + 0x108;
  *(int *)(param_1 + 0x10c) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x110) = 0;
  iVar1 = param_1 + 0x114;
  *(int *)(param_1 + 0x118) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined4 *)(param_1 + 0x120) = 1;
  iVar1 = param_1 + 0x124;
  *(int *)(param_1 + 0x128) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 300) = 0;
  iVar1 = param_1 + 0x130;
  *(int *)(param_1 + 0x134) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 1;
  iVar1 = param_1 + 0x140;
  *(int *)(param_1 + 0x144) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined4 *)(param_1 + 0x150) = 0;
  *(undefined4 *)(param_1 + 0x154) = 0x12;
  *(undefined4 *)(param_1 + 0x158) = 1;
  *(undefined4 *)(param_1 + 0x15c) = _min_quantum;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  *(undefined4 *)(param_1 + 0x168) = 0x80;
  return;
}
