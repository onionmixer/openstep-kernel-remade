/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00171b88 */

void FUN_00171b88(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    uVar1 = _convert_port_to_host
                      (param_1[2],param_2 + 0x24,param_2 + 0x2c,param_2 + 0x34,param_2 + 0x3c,
                       param_2 + 0x44,param_2 + 0x4c);
    iVar2 = _host_stack_usage(uVar1);
    *(int *)(param_2 + 0x1c) = iVar2;
    if (iVar2 == 0) {
      *(undefined4 *)(param_2 + 4) = 0x50;
      *(undefined4 *)(param_2 + 0x20) = DAT_001e07a4;
      *(undefined4 *)(param_2 + 0x28) = DAT_001e07a8;
      *(undefined4 *)(param_2 + 0x30) = DAT_001e07ac;
      *(undefined4 *)(param_2 + 0x38) = DAT_001e07b0;
      *(undefined4 *)(param_2 + 0x40) = DAT_001e07b4;
      *(undefined4 *)(param_2 + 0x48) = DAT_001e07b8;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

