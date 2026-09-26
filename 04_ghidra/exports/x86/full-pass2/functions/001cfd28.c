/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cfd28 */

void FUN_001cfd28(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  code *pcVar6;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  undefined4 *puVar10;
  
  iVar2 = *(int *)(param_1 + 4);
  for (iVar1 = *(int *)(param_1 + 8); iVar1 != 0; iVar1 = iVar1 + -1) {
    iVar3 = *(int *)(iVar2 + 0xc);
    if (iVar3 != 0) {
      puVar10 = (undefined4 *)(iVar3 + 0xc);
      for (uVar8 = (uint)*(ushort *)(iVar3 + 8); uVar8 != 0; uVar8 = uVar8 - 1) {
        piVar9 = (int *)*puVar10;
        piVar4 = *(int **)(*piVar9 + 0x1c);
        if (piVar4 != (int *)0x0) {
          iVar5 = *piVar4;
          while (iVar5 != 0) {
            piVar4 = (int *)*piVar4;
            iVar5 = *piVar4;
          }
          pcVar6 = (code *)_class_lookupMethodInMethodList(piVar4,PTR_s_load_001f9cec);
          if (pcVar6 != (code *)0x0) {
            (*pcVar6)(piVar9,PTR_s_load_001f9cec);
          }
        }
        puVar10 = puVar10 + 1;
      }
      piVar9 = (int *)(iVar3 + 0xc + (uint)*(ushort *)(iVar3 + 8) * 4);
      for (uVar8 = (uint)*(ushort *)(iVar3 + 10); uVar8 != 0; uVar8 = uVar8 - 1) {
        uVar7 = _objc_getClass(*(undefined4 *)(*piVar9 + 4));
        if ((*(int *)(*piVar9 + 0xc) != 0) &&
           (pcVar6 = (code *)_class_lookupMethodInMethodList
                                       (*(int *)(*piVar9 + 0xc),PTR_s_load_001f9cec),
           pcVar6 != (code *)0x0)) {
          (*pcVar6)(uVar7,PTR_s_load_001f9cec);
        }
        piVar9 = piVar9 + 1;
      }
    }
    iVar2 = iVar2 + 0x10;
  }
  return;
}

