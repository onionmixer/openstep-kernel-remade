/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001832c8 */

void FUN_001832c8(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == DAT_001e11c0)) &&
     (param_1[8] == DAT_001e11c4)) {
    uVar1 = _convert_port_to_host(param_1[2],param_1[7],param_1[9]);
    uVar1 = _kern_PMSetPowerManagement(uVar1);
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

