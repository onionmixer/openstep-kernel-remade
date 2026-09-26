/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116144 */

void _soisconnected(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    iVar2 = _soqremque(param_1,0);
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_soisconnected_001db350);
    }
    _soqinsque(iVar1,param_1,1);
    _sowakeup(iVar1,iVar1 + 0x24);
    _wakeup(iVar1 + 0x54);
  }
  *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) & 0xfff3 | 2;
  _wakeup(param_1 + 0x54);
  _sowakeup(param_1,param_1 + 0x24);
  _sowakeup(param_1,param_1 + 0x3c);
  return;
}

