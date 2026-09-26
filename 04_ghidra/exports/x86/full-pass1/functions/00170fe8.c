/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00170fe8 */

void FUN_00170fe8(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if ((((param_1[1] == 0x28) && (*param_1 < 0)) && (param_1[6] == DAT_001e0528)) &&
     ((param_1[8] & 0x3fffffffU) == 0x10012011)) {
    uVar1 = _convert_port_to_space(param_1[2]);
    uVar2 = _port_set_backup(uVar1,param_1[7],param_1[9],param_2 + 9);
    param_2[7] = uVar2;
    _space_deallocate(uVar1);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x28;
      param_2[8] = DAT_001e052c;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

