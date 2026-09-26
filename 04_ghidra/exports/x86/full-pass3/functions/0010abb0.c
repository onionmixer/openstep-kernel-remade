/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010abb0 */

int _gettimeofday(timeval *param_1,void *param_2)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 local_c [8];
  
  piVar1 = *(int **)(DAT_001e875c + 0x24);
  iVar3 = DAT_001e875c;
  if (*piVar1 != 0) {
    _microtime(local_c);
    uVar2 = _copyout(local_c,*piVar1,8);
    iVar3 = DAT_001e875c;
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  }
  return iVar3;
}

