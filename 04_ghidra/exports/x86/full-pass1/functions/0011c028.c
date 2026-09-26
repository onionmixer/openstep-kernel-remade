/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011c028 */

void _vno_bsd_unlock(int param_1,uint param_2)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x18);
  param_2 = param_2 & *(uint *)(param_1 + 8);
  if ((iVar3 != 0) && (param_2 != 0)) {
    uVar1 = *(ushort *)(iVar3 + 4);
    if ((char)param_2 < '\0') {
      if ((uVar1 & 8) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vno_bsd_unlock__SHLOCK_001db72d);
      }
      sVar2 = *(short *)(iVar3 + 8);
      *(short *)(iVar3 + 8) = sVar2 + -1;
      if ((sVar2 == 1) && (*(byte *)(iVar3 + 4) = *(byte *)(iVar3 + 4) & 0xf7, (uVar1 & 0x10) != 0))
      {
        _wakeup(iVar3 + 8);
      }
      *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffffff7f;
    }
    if ((param_2 & 0x100) != 0) {
      if ((uVar1 & 4) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vno_bsd_unlock__EXLOCK_001db744);
      }
      sVar2 = *(short *)(iVar3 + 10);
      *(short *)(iVar3 + 10) = sVar2 + -1;
      if ((sVar2 == 1) && (*(byte *)(iVar3 + 4) = *(byte *)(iVar3 + 4) & 0xeb, (uVar1 & 0x10) != 0))
      {
        _wakeup(iVar3 + 10);
      }
      *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffeff;
    }
  }
  return;
}

