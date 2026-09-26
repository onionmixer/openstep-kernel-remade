/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00108474 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pid_t _setsid(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *_active_u;
  iVar2 = _get_posix_proc((int)*(short *)(iVar1 + 0x30));
  if ((*(int *)(*(int *)(iVar2 + 0x10) + 0xc) != (int)*(short *)(iVar1 + 0x30)) &&
     (iVar2 = _pgfind((int)*(short *)(iVar1 + 0x30)), iVar2 == 0)) {
    _enterpgrp(iVar1,(int)*(short *)(iVar1 + 0x30),1);
    iVar2 = DAT_001e875c;
    *(int *)(DAT_001e875c + 0x60) = (int)*(short *)(iVar1 + 0x30);
    return iVar2;
  }
  iVar1 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = 1;
  return iVar1;
}

