/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010c100 */

int _uprintf(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(_active_u + 0x168);
  iVar2 = _active_u;
  if (iVar1 != 0) {
    _ttycheckoutq(iVar1,1);
    _prf(param_1,&stack0x00000008,2,iVar1);
    iVar2 = 0;
  }
  return iVar2;
}

