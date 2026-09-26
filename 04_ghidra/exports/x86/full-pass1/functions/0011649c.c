/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011649c */

void _sowakeup(int param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = _splimp();
  if (*(int *)(param_2 + 0x10) != 0) {
    _selwakeup(*(int *)(param_2 + 0x10),*(byte *)(param_2 + 0x14) & 0x10);
    _selthreadclear(param_2 + 0x10);
    *(byte *)(param_2 + 0x14) = *(byte *)(param_2 + 0x14) & 0xef;
  }
  _splx(uVar2);
  if ((*(ushort *)(param_2 + 0x14) & 4) != 0) {
    *(ushort *)(param_2 + 0x14) = *(ushort *)(param_2 + 0x14) & 0xfffb;
    if (_nfs_wakeup_one_nfsd == 1) {
      _wakeup_one(param_2);
    }
    else {
      _wakeup(param_2);
    }
  }
  if ((*(byte *)(param_1 + 7) & 2) != 0) {
    sVar1 = *(short *)(param_1 + 0x5a);
    if (sVar1 < 0) {
      _gsignal(-(int)sVar1,0x17);
    }
    else if ((0 < sVar1) && (uVar3 = _pfind((int)sVar1), uVar3 != 0)) {
      _psignal(uVar3,(char *)0x17);
    }
  }
  return;
}

