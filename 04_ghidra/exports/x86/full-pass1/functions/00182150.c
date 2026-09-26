/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182150 */

undefined4
_kern_IOMapEISADeviceMemory
          (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          char param_6,undefined4 param_7)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xfffffd3f;
  }
  else {
    uVar1 = _kern_dev_map_phys(param_1,*(undefined4 *)(param_2 + 0xc),param_3,param_4,param_5,
                               (int)param_6,param_7);
  }
  return uVar1;
}

