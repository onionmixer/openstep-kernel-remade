/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014473c */

undefined4 FUN_0014473c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x28) == 5) {
    iVar1 = *(int *)(param_1 + 0x30);
    if ((*(byte *)(iVar1 + 200) & 1) == 0) {
      uVar2 = FUN_00143e24(iVar1,param_2,0,0);
    }
    else {
      uVar2 = _uiomove(iVar1 + 0x8c,*(undefined4 *)(iVar1 + 0x6c),0,param_2);
    }
    if ((*(ushort *)(iVar1 + 0x44) & 0x46) != 0) {
      *(ushort *)(iVar1 + 0x44) = *(ushort *)(iVar1 + 0x44) | 8;
      _microtime(&_iuniqtime);
      if ((*(byte *)(iVar1 + 0x44) & 4) != 0) {
        *(undefined4 *)(iVar1 + 0x74) = _iuniqtime;
      }
      if ((*(byte *)(iVar1 + 0x44) & 2) != 0) {
        *(undefined4 *)(iVar1 + 0x7c) = _iuniqtime;
      }
      if ((*(byte *)(iVar1 + 0x44) & 0x40) != 0) {
        *(undefined4 *)(iVar1 + 0x4c) = 0;
        *(undefined4 *)(iVar1 + 0x84) = _iuniqtime;
      }
      *(byte *)(iVar1 + 0x44) = *(byte *)(iVar1 + 0x44) & 0xb9;
    }
  }
  else {
    uVar2 = 0x16;
  }
  return uVar2;
}

