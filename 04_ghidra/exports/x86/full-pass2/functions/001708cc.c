/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001708cc */

void FUN_001708cc(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint local_c;
  uint local_8;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    uVar1 = _convert_port_to_space(param_1[2]);
    uVar2 = _port_names(uVar1,param_2 + 0xb,&local_8,param_2 + 0xf,&local_c);
    param_2[7] = uVar2;
    _space_deallocate(uVar1);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x40;
      param_2[8] = DAT_001e049c;
      param_2[9] = (uint)PTR_s__62I__001e04a0;
      param_2[10] = DAT_001e04a4;
      param_2[10] = local_8;
      param_2[0xc] = DAT_001e04a8;
      param_2[0xd] = (uint)PTR_s__62I__001e04ac;
      param_2[0xe] = DAT_001e04b0;
      param_2[0xe] = local_c;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

