/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001060ec */

pid_t _wait4(pid_t param_1,int *param_2,int param_3,rusage *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  pid_t pVar3;
  undefined1 local_50 [4];
  undefined1 local_4c [72];
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar2 = _wait1(puVar1[2],local_4c,local_50,*puVar1,_wait4);
  if (iVar2 != 0) {
    _unix_syscall_return(iVar2);
  }
  if (puVar1[3] != 0) {
    iVar2 = _copyout(local_4c,puVar1[3],0x48);
  }
  if (puVar1[1] != 0) {
    iVar2 = _copyout(local_50,puVar1[1],4);
  }
  pVar3 = _unix_syscall_return(iVar2);
  return pVar3;
}

