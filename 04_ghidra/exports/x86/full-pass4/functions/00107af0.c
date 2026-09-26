/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107af0 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pid_t _getpgrp(void)

{
  int *piVar1;
  int iVar2;
  pid_t pVar3;
  
  piVar1 = *(int **)(DAT_001e875c + 0x24);
  if (*piVar1 == 0) {
    *piVar1 = (int)*(short *)(*_active_u + 0x30);
  }
  iVar2 = _pfind(*piVar1);
  if (iVar2 == 0) {
    pVar3 = DAT_001e875c;
    *(undefined1 *)(DAT_001e875c + 0x68) = 3;
    return pVar3;
  }
  pVar3 = DAT_001e875c;
  *(int *)(DAT_001e875c + 0x60) = (int)*(short *)(iVar2 + 0x2e);
  return pVar3;
}

