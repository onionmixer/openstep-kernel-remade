/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cd284 */

undefined4 * FUN_001cd284(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)param_1[1];
  puVar2 = param_1;
  if ((*(byte *)(param_1 + 4) & 2) == 0) {
    puVar2 = (undefined4 *)*param_1;
  }
  if ((*(byte *)(puVar2 + 4) & 4) == 0) {
    if (puVar1 != (undefined4 *)0x0) {
      puVar2 = puVar1;
      if ((*(byte *)(puVar1 + 4) & 2) == 0) {
        puVar2 = (undefined4 *)*puVar1;
      }
      if ((*(byte *)(puVar2 + 4) & 4) == 0) {
        FUN_001cd284(puVar1);
      }
    }
    puVar1 = param_1;
    if ((*(byte *)(param_1 + 4) & 2) == 0) {
      puVar1 = (undefined4 *)*param_1;
    }
    if ((*(byte *)(puVar1 + 4) & 4) == 0) {
      puVar1 = param_1;
      if ((*(byte *)(param_1 + 4) & 2) == 0) {
        puVar1 = (undefined4 *)*param_1;
      }
      puVar2 = param_1;
      if ((*(byte *)(param_1 + 4) & 2) == 0) {
        puVar2 = (undefined4 *)*param_1;
      }
      puVar1[4] = puVar2[4] | 4;
      _objc_msgSend(param_1,PTR_s_initialize_001f9ad8);
    }
  }
  return param_1;
}

