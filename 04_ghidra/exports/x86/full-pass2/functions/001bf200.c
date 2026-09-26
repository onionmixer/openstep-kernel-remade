/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bf200 */

void FUN_001bf200(int param_1,int param_2)

{
  undefined4 uVar1;
  int local_8;
  
  if ((*(int *)(param_1 + 4) == 0x6c) && (*(char *)(param_1 + 3) == '\x01')) {
    if ((*(int *)(param_1 + 0x18) == 0x10012002) &&
       ((*(int *)(param_1 + 0x20) == 0x10400808 && (*(int *)(param_1 + 100) == 0x10012002)))) {
      local_8 = 0x1000;
      uVar1 = _EvGetParameterChar(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x1c),
                                  param_1 + 0x24,*(undefined4 *)(param_1 + 0x68),param_2 + 0x2c,
                                  &local_8);
      *(undefined4 *)(param_2 + 0x1c) = uVar1;
    }
    else {
      *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
    }
    if (*(int *)(param_2 + 0x1c) == 0) {
      *(undefined4 *)(param_2 + 0x20) = 0x30000000;
      *(undefined4 *)(param_2 + 0x24) = 0x80008;
      *(undefined4 *)(param_2 + 0x28) = 0x1000;
      *(int *)(param_2 + 0x28) = local_8;
      *(undefined1 *)(param_2 + 3) = 1;
      *(uint *)(param_2 + 4) = (local_8 + 3U & 0xfffffffc) + 0x2c;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

