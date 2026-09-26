/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016f9c8 */

undefined4 _mach_server_routine(int param_1)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0x14) - 2000;
  if (uVar1 < 0x68) {
    return *(undefined4 *)(&DAT_001e0564 + uVar1 * 4);
  }
  return 0;
}

