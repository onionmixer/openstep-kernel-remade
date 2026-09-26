/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ccf4c */

void FUN_001ccf4c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_001e55b0 == 0) {
    uVar1 = __objc_create_zone();
    DAT_001e55b0 = _NXCreateMapTableFromZone(0x1cca30,0x1ccab0,0x1ccb3c,0,8,uVar1);
  }
  iVar2 = _NXMapGet(DAT_001e55b0,*(undefined4 *)(param_1 + 8));
  if (iVar2 == 0) {
    _NXMapInsert(DAT_001e55b0,*(undefined4 *)(param_1 + 8),param_1);
  }
  return;
}

