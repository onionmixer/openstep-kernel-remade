/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf0d4 */

void FUN_001cf0d4(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (DAT_001e5620 != 0) {
    puVar2 = (undefined4 *)_NXMapRemove(DAT_001e5620,*(undefined4 *)(param_1 + 8));
    while (puVar2 != (undefined4 *)0x0) {
      __objc_add_category(puVar2[1],puVar2[2]);
      puVar1 = (undefined4 *)*puVar2;
      _free(puVar2);
      puVar2 = puVar1;
    }
  }
  return;
}

