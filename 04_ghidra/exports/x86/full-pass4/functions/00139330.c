/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139330 */

undefined4 FUN_00139330(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (param_2 == 1) {
    if (*(int *)(iVar1 + 0x7c) != 0) {
      return 1;
    }
    iVar2 = _selthreadcache(iVar1 + 0x70);
    if (iVar2 != 0) {
      *(byte *)(iVar1 + 0x88) = *(byte *)(iVar1 + 0x88) | 4;
    }
  }
  else if (param_2 < 2) {
    if (param_2 == 0) {
      if (*(short *)(iVar1 + 0x82) == 0) {
        return 1;
      }
      iVar2 = _selthreadcache(iVar1 + 0x78);
      if (iVar2 != 0) {
        *(byte *)(iVar1 + 0x88) = *(byte *)(iVar1 + 0x88) | 0x10;
      }
    }
  }
  else if (param_2 == 2) {
    if ((*(uint *)(iVar1 + 0x7c) < _fifoinfo) && (0 < *(short *)(iVar1 + 0x82))) {
      return 1;
    }
    iVar2 = _selthreadcache(iVar1 + 0x74);
    if (iVar2 != 0) {
      *(byte *)(iVar1 + 0x88) = *(byte *)(iVar1 + 0x88) | 8;
    }
  }
  return 0;
}

