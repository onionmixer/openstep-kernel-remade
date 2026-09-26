/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ceef4 */

int _objc_addModule(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  DAT_001e8748 = DAT_001e8748 + 1;
  if (DAT_001e874c == 0) {
    iVar4 = __objc_create_zone();
    uVar3 = __objc_create_zone((DAT_001e8748 + 1) * 4);
    DAT_001e874c = (**(code **)(iVar4 + 4))(uVar3);
  }
  else {
    puVar2 = (undefined4 *)__objc_create_zone();
    uVar3 = __objc_create_zone(DAT_001e874c,(DAT_001e8748 + 1) * 4);
    DAT_001e874c = (*(code *)*puVar2)(uVar3);
  }
  if (DAT_001e874c == 0) {
    __objc_fatal("unable to reallocate module vector");
  }
  iVar1 = DAT_001e874c;
  iVar4 = DAT_001e8748;
  *(undefined4 *)(DAT_001e874c + -4 + DAT_001e8748 * 4) = param_1;
  *(undefined4 *)(iVar1 + iVar4 * 4) = 0;
  return iVar1;
}

