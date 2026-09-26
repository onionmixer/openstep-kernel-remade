/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001121e0 */

void _ptcclose(byte param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = (uint)param_1 * 0x10;
  iVar4 = *(int *)(&DAT_001e56d4 + iVar5);
  iVar1 = *(int *)(&DAT_001e56d0 + iVar5);
  (*(code *)(&PTR__ttymodem_001db00c)[*(char *)(iVar1 + 0x47) * 0xc])(iVar1,0);
  if (((&DAT_001e56cc)[iVar5] & 1) != 0) {
    _forceclose((int)*(short *)(&DAT_001e56c8 + iVar5));
    iVar2 = (uint)(byte)(&DAT_001e56c8)[iVar5] * 0x10;
    iVar5 = *(int *)(&DAT_001e56d0 + iVar2);
    if (((&DAT_001e56cc)[iVar2] & 1) != 0) {
      (*(code *)(&PTR__ttylclose_001dafec)[*(char *)(iVar5 + 0x47) * 0xc])(iVar5);
      _ttyclose(iVar5);
      *(undefined4 *)(&DAT_001e56cc + iVar2) = 0;
    }
    _ptcwakeup(iVar5,3);
  }
  uVar3 = _spltty();
  if (*(int *)(iVar4 + 4) != 0) {
    _selthreadclear(iVar4 + 4);
  }
  if (*(int *)(iVar4 + 8) != 0) {
    _selthreadclear(iVar4 + 8);
  }
  _splx(uVar3);
  *(undefined4 *)(iVar1 + 0x24) = 0;
  iVar4 = _ttynty(iVar1);
  *(undefined4 *)(iVar4 + 8) = 0;
  return;
}

