/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00106168 */

pid_t _wait(int *param_1)

{
  undefined4 uVar1;
  pid_t pVar2;
  undefined4 local_8;
  
  uVar1 = _wait1(0,0,&local_8,0,_wait);
  *(undefined4 *)(DAT_001e875c + 100) = local_8;
  pVar2 = _unix_syscall_return(uVar1);
  return pVar2;
}

