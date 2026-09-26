/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cf95c */

void __objc_removeHeader(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (DAT_001e55fc != 0) {
    do {
      if ((*(int *)(DAT_001e55f8 + uVar6 * 0x18) == param_1) &&
         (uVar5 = uVar6, uVar6 < DAT_001e55fc - 1)) {
        do {
          puVar1 = (undefined4 *)(uVar5 * 0x18 + DAT_001e55f8);
          puVar2 = puVar1 + 6;
          for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar1 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar1 = puVar1 + 1;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < DAT_001e55fc - 1);
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < DAT_001e55fc);
  }
  DAT_001e55fc = DAT_001e55fc - 1;
  puVar2 = (undefined4 *)__objc_create_zone();
  uVar3 = __objc_create_zone(DAT_001e55f8,DAT_001e55fc * 0x18);
  DAT_001e55f8 = (*(code *)*puVar2)(uVar3);
  return;
}

