/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107cfc */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pid_t _setpgrp(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = *(int **)(DAT_001e875c + 0x24);
  if (*piVar1 == 0) {
    *piVar1 = (int)*(short *)(*_active_u + 0x30);
  }
  iVar2 = _pfind(*piVar1);
  iVar4 = DAT_001e875c;
  if (iVar2 == 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 3;
  }
  else {
    if (((*(short *)(iVar2 + 0x2c) != *(short *)(_active_u[7] + 2)) &&
        (*(short *)(_active_u[7] + 2) != 0)) &&
       (iVar3 = _inferior(iVar2), iVar4 = DAT_001e875c, iVar3 == 0)) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 1;
      return iVar4;
    }
    iVar4 = _enterpgrp(iVar2,piVar1[1],0);
  }
  return iVar4;
}

