/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001553fc */

int _old_mach_port_get_receive_status(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_28 [2];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = _mach_port_get_receive_status(param_1,param_2,local_28);
  if (iVar1 == 0) {
    *param_3 = local_28[0];
    param_3[1] = local_20;
    param_3[2] = local_1c;
    param_3[3] = local_18;
    param_3[4] = local_14;
    param_3[5] = local_10;
    param_3[6] = local_c;
    param_3[7] = local_8;
    iVar1 = 0;
  }
  return iVar1;
}

