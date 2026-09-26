/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001084d0 */

int _setpgid(pid_t param_1,pid_t param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  piVar2 = _active_u;
  piVar1 = *(int **)(DAT_001e875c + 0x24);
  iVar4 = *_active_u;
  if (piVar1[1] < 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
    return (int)piVar2;
  }
  iVar3 = _get_posix_proc((int)*(short *)(iVar4 + 0x30));
  iVar5 = *piVar1;
  local_8 = iVar3;
  if ((iVar5 != 0) && (iVar5 != *(short *)(iVar4 + 0x30))) {
    iVar4 = _pfind(iVar5);
    if ((iVar4 == 0) || (iVar5 = _inferior(iVar4), iVar5 == 0)) {
      iVar4 = DAT_001e875c;
      *(undefined1 *)(DAT_001e875c + 0x68) = 3;
      return iVar4;
    }
    local_8 = _get_posix_proc((int)*(short *)(iVar4 + 0x30));
    iVar5 = DAT_001e875c;
    if (*(int *)(*(int *)(local_8 + 0x10) + 8) != *(int *)(*(int *)(iVar3 + 0x10) + 8))
    goto LAB_001085b6;
    if (*(int *)(iVar4 + 0x28) < 0) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0xd;
      return iVar5;
    }
  }
  if (*(int *)(*(int *)(*(int *)(local_8 + 0x10) + 8) + 4) == iVar4) {
LAB_001085b6:
    iVar4 = DAT_001e875c;
    *(undefined1 *)(DAT_001e875c + 0x68) = 1;
    return iVar4;
  }
  iVar5 = piVar1[1];
  if (iVar5 == 0) {
    piVar1[1] = (int)*(short *)(iVar4 + 0x30);
  }
  else if ((iVar5 != *(short *)(iVar4 + 0x30)) &&
          ((iVar5 = _pgfind(iVar5), iVar5 == 0 ||
           (*(int *)(iVar5 + 8) != *(int *)(*(int *)(iVar3 + 0x10) + 8))))) goto LAB_001085b6;
  iVar4 = _enterpgrp(iVar4,piVar1[1],0);
  return iVar4;
}

