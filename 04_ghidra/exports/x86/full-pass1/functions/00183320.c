/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00183320 */

void FUN_00183320(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    uVar1 = _convert_port_to_host(param_1[2]);
    uVar1 = _kern_PMRestoreDefaults(uVar1);
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

