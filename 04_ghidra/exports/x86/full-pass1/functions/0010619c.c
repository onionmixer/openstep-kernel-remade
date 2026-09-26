/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010619c */

pid_t _wait3(int *param_1,int param_2,rusage *param_3)

{
  int iVar1;
  int iVar2;
  pid_t pVar3;
  undefined1 local_4c [72];
  
  iVar1 = *(int *)(*(int *)(DAT_001e875c + 0x24) + 8);
  iVar2 = _wait1(*(undefined4 *)(*(int *)(DAT_001e875c + 0x24) + 4),local_4c,DAT_001e875c + 100,0,
                 _wait3);
  if (iVar2 != 0) {
    _unix_syscall_return(iVar2);
  }
  if (iVar1 != 0) {
    iVar2 = _copyout(local_4c,iVar1,0x48);
  }
  pVar3 = _unix_syscall_return(iVar2);
  return pVar3;
}

