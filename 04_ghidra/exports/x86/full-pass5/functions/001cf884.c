/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf884 */

void __objc_addHeader(undefined4 param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  
  pvVar1 = DAT_001e55f8;
  DAT_001e55fc = DAT_001e55fc + 1;
  if (DAT_001e55f8 == (void *)0x0) {
    iVar2 = __objc_create_zone();
    uVar3 = __objc_create_zone(DAT_001e55fc * 0x18);
    DAT_001e55f8 = (void *)(**(code **)(iVar2 + 4))(uVar3);
  }
  else {
    iVar2 = __objc_create_zone();
    uVar3 = __objc_create_zone(DAT_001e55fc * 0x18);
    DAT_001e55f8 = (void *)(**(code **)(iVar2 + 4))(uVar3);
    _memcpy(DAT_001e55f8,pvVar1,(DAT_001e55fc + -1) * 0x18);
    iVar2 = __objc_create_zone();
    uVar3 = __objc_create_zone(pvVar1);
    (**(code **)(iVar2 + 8))(uVar3);
  }
  iVar2 = DAT_001e55fc;
  pvVar1 = DAT_001e55f8;
  *(undefined4 *)((int)DAT_001e55f8 + DAT_001e55fc * 0x18 + -0x18) = param_1;
  *(undefined4 *)((int)pvVar1 + iVar2 * 0x18 + -0x14) = 0;
  *(undefined4 *)((int)pvVar1 + iVar2 * 0x18 + -0x10) = 0;
  *(undefined4 *)((int)pvVar1 + iVar2 * 0x18 + -0xc) = 0;
  *(undefined4 *)((int)pvVar1 + iVar2 * 0x18 + -8) = 0;
  *(undefined4 *)((int)pvVar1 + iVar2 * 0x18 + -4) = 0;
  return;
}

