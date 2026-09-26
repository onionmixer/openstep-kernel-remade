/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00170d70 */

void FUN_00170d70(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint local_8;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e0500)) {
    uVar1 = _convert_port_to_space(param_1[2]);
    uVar2 = _port_set_status(uVar1,param_1[7],param_2 + 0xb,&local_8);
    param_2[7] = uVar2;
    _space_deallocate(uVar1);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x30;
      param_2[8] = DAT_001e0504;
      param_2[9] = (uint)PTR_s__62I__001e0508;
      param_2[10] = DAT_001e050c;
      param_2[10] = local_8;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

