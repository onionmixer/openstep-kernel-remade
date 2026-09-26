/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018019c */

void _KernDeviceInterruptDispatchShared(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0xc);
  _IODisableInterrupt(param_1);
  (*pcVar1)(param_1,param_2,*(undefined4 *)(param_1 + 0x10));
  return;
}

