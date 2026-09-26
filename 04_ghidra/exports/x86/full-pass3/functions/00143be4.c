/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00143be4 */

undefined4 FUN_00143be4(int param_1,int *param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = _iget((int)*(short *)(*(int *)(param_1 + 0x128) + 4),
                *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x128) + 0xc) + 0x20),
                *(undefined4 *)(param_3 + 4));
  if (iVar2 == 0) {
    *param_2 = 0;
  }
  else if (*(int *)(iVar2 + 0xd0) == *(int *)(param_3 + 8)) {
    uVar1 = *(ushort *)(iVar2 + 0x44);
    *(ushort *)(iVar2 + 0x44) = uVar1 & 0xfffe;
    if ((uVar1 & 0x10) != 0) {
      *(ushort *)(iVar2 + 0x44) = uVar1 & 0xffee;
      _wakeup(iVar2);
    }
    *param_2 = iVar2 + 0xc;
    if ((*(ushort *)(iVar2 + 100) & 0x4240) == 0x200) {
      *(byte *)(iVar2 + 0x10) = *(byte *)(iVar2 + 0x10) | 0x80;
    }
  }
  else {
    _idrop(iVar2);
    *param_2 = 0;
  }
  return 0;
}

