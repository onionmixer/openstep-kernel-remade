/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182118 */

undefined4 _kern_IOUnMapEISADevicePorts(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0xfffffd3f;
  }
  if (*(int *)(*(int *)(param_2 + 0xc) + 0x50) == 0) {
    uVar1 = _kern_dev_map_port_com(param_1,param_2,1);
    return uVar1;
  }
  return 0;
}

