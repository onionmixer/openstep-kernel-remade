/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016ef74 */

void FUN_0016ef74(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    uVar1 = _convert_port_to_host(param_1[2],param_2 + 0x24);
    iVar2 = _host_get_time(uVar1);
    *(int *)(param_2 + 0x1c) = iVar2;
    if (iVar2 == 0) {
      *(undefined4 *)(param_2 + 4) = 0x2c;
      *(undefined4 *)(param_2 + 0x20) = DAT_001e01cc;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

