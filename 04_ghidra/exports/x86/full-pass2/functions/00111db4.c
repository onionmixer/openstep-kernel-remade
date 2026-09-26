/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00111db4 */

void _ptsclose(byte param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (uint)param_1 * 0x10;
  iVar1 = *(int *)(&DAT_001e56d0 + iVar2);
  if (((&DAT_001e56cc)[iVar2] & 1) != 0) {
    (*(code *)(&PTR__ttylclose_001dafec)[*(char *)(iVar1 + 0x47) * 0xc])(iVar1);
    _ttyclose(iVar1);
    *(undefined4 *)(&DAT_001e56cc + iVar2) = 0;
  }
  _ptcwakeup(iVar1,3);
  return;
}

