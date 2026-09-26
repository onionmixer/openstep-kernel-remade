/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00192438 */

void FUN_00192438(int param_1)

{
  byte *pbVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x30) == 1) {
    pcVar2 = *(code **)(param_1 + 0x38);
    if (((pcVar2 == _unix_syscall_) || (pcVar2 == _mach_kernel_trap_)) || (pcVar2 == _machdep_call_)
       ) {
      pbVar1 = (byte *)(*(int *)(_active_threads + 0x28) + 0xf0);
      *pbVar1 = *pbVar1 | 1;
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xfffffeff;
      return;
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 3;
  }
  _kdp_raise_exception(6,uVar3,0,param_1);
  return;
}

