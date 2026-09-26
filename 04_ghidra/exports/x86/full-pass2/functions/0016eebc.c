/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016eebc */

void FUN_0016eebc(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((param_1[1] == 0x24) && (-1 < *param_1)) && (param_1[6] == DAT_001e01c0)) {
    uVar1 = _convert_port_to_host_priv(param_1[2],param_1[7],param_1[8]);
    uVar1 = _host_set_time(uVar1);
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

