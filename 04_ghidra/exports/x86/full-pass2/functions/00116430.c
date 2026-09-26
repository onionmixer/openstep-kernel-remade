/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116430 */

void _sbwakeup(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = _splimp();
  if (*(int *)(param_1 + 0x10) != 0) {
    _selwakeup(*(int *)(param_1 + 0x10),*(byte *)(param_1 + 0x14) & 0x10);
    _selthreadclear(param_1 + 0x10);
    *(byte *)(param_1 + 0x14) = *(byte *)(param_1 + 0x14) & 0xef;
  }
  _splx(uVar1);
  if ((*(ushort *)(param_1 + 0x14) & 4) != 0) {
    *(ushort *)(param_1 + 0x14) = *(ushort *)(param_1 + 0x14) & 0xfffb;
    if (_nfs_wakeup_one_nfsd == 1) {
      _wakeup_one(param_1);
    }
    else {
      _wakeup(param_1);
    }
  }
  return;
}

