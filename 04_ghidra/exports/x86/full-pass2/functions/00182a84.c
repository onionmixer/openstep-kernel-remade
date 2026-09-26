/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182a84 */

undefined4 _driverServer_server_routine(int param_1)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0x14) - 0xa8c;
  if (uVar1 < 0x27) {
    return *(undefined4 *)(&DAT_001e11c8 + uVar1 * 4);
  }
  return 0;
}

