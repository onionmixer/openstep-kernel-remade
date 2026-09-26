/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf128 */

void FUN_001cf128(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  iVar1 = _objc_lookUpClass(*(undefined4 *)(param_1 + 4));
  if (iVar1 == 0) {
    if (DAT_001e5620 == 0) {
      uVar2 = __objc_create_zone();
      DAT_001e5620 = _NXCreateMapTableFromZone
                               (__mapStrHash,__mapStrIsEqual,__mapNoFree,0,0x80,uVar2);
    }
    uVar2 = _NXMapGet(DAT_001e5620,*(undefined4 *)(param_1 + 4));
    iVar1 = __objc_create_zone();
    uVar3 = __objc_create_zone(0xc);
    puVar4 = (undefined4 *)(**(code **)(iVar1 + 4))(uVar3);
    *puVar4 = uVar2;
    puVar4[1] = param_1;
    puVar4[2] = param_2;
    _NXMapInsert(DAT_001e5620,*(undefined4 *)(param_1 + 4),puVar4);
  }
  else {
    __objc_add_category(param_1,param_2);
  }
  return;
}

