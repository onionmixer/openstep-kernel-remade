/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00187068 */

void _catch_trap(int param_1)

{
  int *piVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  
  if (((*(byte *)(param_1 + 0x42) & 2) == 0) && ((*(byte *)(param_1 + 0x3c) & 3) != 3)) {
    _kernel_trap(param_1);
    return;
  }
  piVar1 = *(int **)(*(int *)(_active_threads + 0x28) + 0xec);
  iVar4 = 0;
  if (piVar1 != (int *)0x0) {
    iVar4 = *piVar1;
  }
  if (iVar4 != 0) {
    uVar2 = *(uint *)(param_1 + 0x30);
    bVar3 = (byte)uVar2;
    if (uVar2 < 0x20) {
      uVar2 = (uint)((*(uint *)(iVar4 + 0x2c) & 1 << (bVar3 & 0x1f)) != 0);
    }
    else {
      if ((int)uVar2 < 0) {
        uVar2 = uVar2 + 7;
      }
      uVar2 = (int)(uint)*(byte *)(((int)uVar2 >> 3) + iVar4 + 0x2c) >>
              (bVar3 - (char)(((int)uVar2 >> 3) << 3) & 0x1f) & 1;
    }
    if (uVar2 == 0) {
      iVar4 = _PCexception(_active_threads,param_1);
      goto LAB_001870ea;
    }
  }
  iVar4 = 0;
LAB_001870ea:
  if (iVar4 == 0) {
    _user_trap(param_1);
  }
  return;
}

