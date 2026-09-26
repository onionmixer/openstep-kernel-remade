/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00160cf8 */

undefined4 _kern_PMSetPowerState(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == &_realhost) {
    uVar1 = _PMSetPowerState(param_2,param_3);
    return uVar1;
  }
  return 0x16;
}

