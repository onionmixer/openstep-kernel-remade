
void _compute_mach_factor(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  
  puVar9 = _all_psets;
  if ((undefined4 **)_all_psets != &_all_psets) {
    do {
      iVar4 = puVar9[0x47];
      if (0 < iVar4) {
        iVar2 = puVar9[0x41];
        for (puVar1 = (undefined4 *)puVar9[0x45]; puVar1 != puVar9 + 0x45;
            puVar1 = (undefined4 *)puVar1[0x4c]) {
          iVar2 = puVar1[0x41] + iVar2;
        }
        iVar2 = (iVar4 - puVar9[0x44]) + iVar2;
        if (puVar9 == (undefined4 *)_default_pset) {
          iVar2 = iVar2 + -1;
        }
        if (iVar4 < iVar2) {
          iVar3 = (iVar4 * 1000) / (iVar2 + 1);
          iVar4 = (iVar2 << 7) / iVar4;
        }
        else {
          iVar3 = (iVar4 - iVar2) * 1000;
          iVar4 = 0x80;
        }
        puVar9[0x58] = (iVar3 + puVar9[0x58] * 4) / 5;
        puVar9[0x59] = (iVar2 * 1000 + puVar9[0x59] * 4) / 5;
        if (puVar9 == (undefined4 *)_default_pset) {
          piVar5 = (int *)_avenrun;
          piVar7 = (int *)_mach_factor;
          piVar8 = (int *)unk_40AF820;
          do {
            *piVar7 = (iVar3 * (1000 - *piVar8) + *piVar8 * *piVar7) / 1000;
            piVar6 = piVar5 + 1;
            *piVar5 = (iVar2 * 1000 * (1000 - *piVar8) + *piVar8 * *piVar5) / 1000;
            piVar5 = piVar6;
            piVar7 = piVar7 + 1;
            piVar8 = piVar8 + 1;
          } while ((int)piVar6 < 0x40af811);
        }
        puVar9[0x5a] = iVar4 + puVar9[0x5a] >> 1;
      }
      puVar1 = puVar9 + 0x50;
      puVar9 = (undefined4 *)*puVar1;
    } while ((undefined4 **)*puVar1 != &_all_psets);
  }
  return;
}
