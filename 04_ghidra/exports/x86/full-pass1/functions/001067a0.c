/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001067a0 */

undefined4 _init_process(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _suser();
  if (iVar1 == 0) {
    uVar2 = 8;
  }
  else {
    iVar1 = *_active_u;
    if (*(int *)(iVar1 + 0x4c) != 0) {
      *(undefined4 *)(*(int *)(iVar1 + 0x4c) + 0x50) = *(undefined4 *)(iVar1 + 0x50);
    }
    if (*(int *)(iVar1 + 0x50) != 0) {
      *(undefined4 *)(*(int *)(iVar1 + 0x50) + 0x4c) = *(undefined4 *)(iVar1 + 0x4c);
    }
    if (*(int *)(*(int *)(iVar1 + 0x44) + 0x48) == iVar1) {
      *(undefined4 *)(*(int *)(iVar1 + 0x44) + 0x48) = *(undefined4 *)(iVar1 + 0x4c);
    }
    *(int *)(iVar1 + 0x44) = iVar1;
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    *(undefined4 *)(iVar1 + 0x50) = 0;
    if (*(short *)(iVar1 + 0x2e) != *(short *)(iVar1 + 0x30)) {
      _enterpgrp(iVar1,(int)*(short *)(iVar1 + 0x30),0);
    }
    *(undefined2 *)(iVar1 + 0x32) = 0;
    uVar2 = 0;
  }
  return uVar2;
}

