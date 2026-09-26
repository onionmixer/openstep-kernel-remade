/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001700f8 */

void FUN_001700f8(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((((param_1[1] == 0x48) && (*param_1 < 0)) && (param_1[6] == DAT_001e0424)) &&
      ((param_1[8] == DAT_001e0428 && (param_1[10] == DAT_001e042c)))) &&
     ((param_1[0xc] == DAT_001e0430 &&
      ((param_1[0xe] == DAT_001e0434 && ((param_1[0x10] & 0x3fffffffU) == 0x10012011)))))) {
    uVar1 = _netipc_listen(param_1[2],param_1[7],param_1[9],param_1[0xb],param_1[0xd],param_1[0xf],
                           param_1[0x11]);
    *(undefined4 *)(param_2 + 0x1c) = uVar1;
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

