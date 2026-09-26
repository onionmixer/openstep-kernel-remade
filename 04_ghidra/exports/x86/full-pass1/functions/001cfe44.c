/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cfe44 */

void __objcInit(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  DAT_001e5600 = FUN_001cf3c0();
  pvVar2 = (void *)_getmachheaders();
  if (pvVar2 != (void *)0x0) {
    DAT_001e55f8 = __objc_headerVector(pvVar2);
    uVar4 = 0;
    if (DAT_001e55fc != 0) {
      do {
        FUN_001cf9f4(uVar4 * 0x18 + DAT_001e55f8);
        uVar4 = uVar4 + 1;
      } while (uVar4 < DAT_001e55fc);
    }
    uVar4 = 0;
    if (DAT_001e55fc != 0) {
      do {
        FUN_001cffc0(uVar4 * 0x18 + DAT_001e55f8);
        uVar4 = uVar4 + 1;
      } while (uVar4 < DAT_001e55fc);
    }
    _free(pvVar2);
  }
  uVar4 = 0;
  if (DAT_001e55fc != 0) {
    do {
      puVar6 = *(undefined4 **)(DAT_001e55f8 + 4 + uVar4 * 0x18);
      for (iVar1 = *(int *)(DAT_001e55f8 + 8 + uVar4 * 0x18); iVar1 != 0; iVar1 = iVar1 + -1) {
        iVar3 = puVar6[3];
        iVar5 = 0;
        if (*(short *)(iVar3 + 8) != 0) {
          do {
            __class_install_relationships(*(undefined4 *)(iVar3 + 0xc + iVar5 * 4),*puVar6);
            iVar5 = iVar5 + 1;
            iVar3 = puVar6[3];
          } while (iVar5 < (int)(uint)*(ushort *)(iVar3 + 8));
        }
        puVar6 = puVar6 + 4;
      }
      FUN_001cf4fc(uVar4 * 0x18 + DAT_001e55f8);
      FUN_001cf570(uVar4 * 0x18 + DAT_001e55f8);
      uVar4 = uVar4 + 1;
    } while (uVar4 < DAT_001e55fc);
  }
  uVar4 = 0;
  if (DAT_001e55fc != 0) {
    do {
      FUN_001cf5c0(uVar4 * 0x18 + DAT_001e55f8);
      uVar4 = uVar4 + 1;
    } while (uVar4 < DAT_001e55fc);
  }
  uVar4 = 0;
  if (DAT_001e55fc != 0) {
    do {
      FUN_001cfd28(uVar4 * 0x18 + DAT_001e55f8);
      uVar4 = uVar4 + 1;
    } while (uVar4 < DAT_001e55fc);
  }
  return;
}

