/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010782c */

void FUN_0010782c(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  while( true ) {
    if (iVar2 == 0) {
      return;
    }
    if (*(char *)(iVar2 + 0x13) == '\x06') break;
    iVar2 = _get_posix_proc((int)*(short *)(iVar2 + 0x30));
    iVar2 = *(int *)(iVar2 + 0xc);
  }
  uVar1 = *(uint *)(param_1 + 4);
  while (uVar1 != 0) {
    _psignal(uVar1,(char *)0x1);
    _psignal(uVar1,(char *)0x13);
    iVar2 = _get_posix_proc((int)*(short *)(uVar1 + 0x30));
    uVar1 = *(uint *)(iVar2 + 0xc);
  }
  return;
}

