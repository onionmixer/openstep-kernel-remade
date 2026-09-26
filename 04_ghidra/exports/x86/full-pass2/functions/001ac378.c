/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ac378 */

void FUN_001ac378(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  if (6 < param_3) {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228,param_3);
    _IOLog("%s unregisterUnixDisk: Bogus partition (%d)\n",uVar1);
    return;
  }
  if (*(char *)(param_1 + 0x116) != '\0') {
    **(undefined4 **)(param_1 + 0x118) = 0;
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x118) + 4 + param_3 * 4) = 0;
  return;
}

