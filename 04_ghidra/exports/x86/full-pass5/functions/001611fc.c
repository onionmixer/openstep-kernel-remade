/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001611fc */

void _pset_init(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0x1f;
  *(undefined4 *)(param_1 + 0x108) = 0;
  iVar1 = param_1;
  do {
    *(int *)(iVar1 + 4) = iVar1;
    *(int *)iVar1 = iVar1;
    iVar1 = iVar1 + 8;
  } while (iVar1 <= param_1 + 0xf8);
  *(int *)(param_1 + 0x110) = param_1 + 0x10c;
  *(int *)(param_1 + 0x10c) = param_1 + 0x10c;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  *(int *)(param_1 + 0x120) = param_1 + 0x11c;
  *(int *)(param_1 + 0x11c) = param_1 + 0x11c;
  *(undefined4 *)(param_1 + 0x124) = 0;
  *(undefined4 *)(param_1 + 0x128) = 1;
  *(int *)(param_1 + 0x130) = param_1 + 300;
  *(int *)(param_1 + 300) = param_1 + 300;
  *(undefined4 *)(param_1 + 0x134) = 0;
  *(int *)(param_1 + 0x13c) = param_1 + 0x138;
  *(int *)(param_1 + 0x138) = param_1 + 0x138;
  *(undefined4 *)(param_1 + 0x140) = 0;
  *(undefined4 *)(param_1 + 0x144) = 1;
  *(undefined4 *)(param_1 + 0x148) = 0;
  *(int *)(param_1 + 0x150) = param_1 + 0x14c;
  *(int *)(param_1 + 0x14c) = param_1 + 0x14c;
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined4 *)(param_1 + 0x158) = 0;
  *(undefined4 *)(param_1 + 0x15c) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0x12;
  *(undefined4 *)(param_1 + 0x168) = 1;
  *(undefined4 *)(param_1 + 0x16c) = _min_quantum;
  *(undefined4 *)(param_1 + 0x170) = 0;
  *(undefined4 *)(param_1 + 0x174) = 0;
  *(undefined4 *)(param_1 + 0x178) = 0x80;
  return;
}

