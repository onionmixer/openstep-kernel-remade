/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001711d8 */

void FUN_001711d8(int *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((((param_1[1] == 0x30) && (-1 < *param_1)) && (param_1[6] == DAT_001e0558)) &&
     ((param_1[8] == DAT_001e055c && (param_1[10] == DAT_001e0560)))) {
    uVar1 = _convert_port_to_map(param_1[2]);
    uVar2 = _vm_deactivate(uVar1,param_1[7],param_1[9],param_1[0xb]);
    *(undefined4 *)(param_2 + 0x1c) = uVar2;
    _vm_map_deallocate(uVar1);
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

