
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _km_eraserect(word *param_1)

{
  undefined4 uVar1;
  word wVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  int iVar9;
  
  uVar1 = (&dword_40B6954)[*(uint *)(param_1 + 4) & 3];
  iVar9 = dword_40B6944 + -0x460;
  if (iVar9 < 0) {
    iVar9 = dword_40B6944 + -0x45f;
  }
  *param_1 = (sword)(iVar9 >> 1) + *param_1;
  iVar9 = _unk_40B694C + -0x340;
  if (iVar9 < 0) {
    iVar9 = _unk_40B694C + -0x33f;
  }
  param_1[1] = (sword)(iVar9 >> 1) + param_1[1];
  *param_1 = *param_1 & 0xfffc;
  wVar2 = param_1[2] + 3 & 0xfffc;
  param_1[2] = wVar2;
  if ((int)((uint)*param_1 + (uint)wVar2) <= dword_40B6944) {
    uVar4 = (uint)param_1[3];
    if ((int)(uVar4 + param_1[1]) <= _unk_40B694C) {
      iVar9 = (uint)*param_1 + dword_40B6948 * (uint)param_1[1];
      if (_km_coni == 0x10) {
        puVar5 = (undefined *)((iVar9 >> 2) + dword_40B6980);
        iVar9 = 0;
        if (uVar4 != 0) {
          do {
            iVar3 = 0;
            puVar7 = puVar5;
            if (param_1[2] != 0) {
              do {
                *puVar7 = (char)uVar1;
                iVar3 = iVar3 + 4;
                puVar7 = puVar7 + 1;
              } while (iVar3 < (int)(uint)param_1[2]);
            }
            puVar5 = puVar5 + dword_40B6940;
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)(uint)param_1[3]);
        }
      }
      else {
        puVar6 = (undefined4 *)(iVar9 + dword_40B6980);
        iVar9 = 0;
        if (uVar4 != 0) {
          do {
            iVar3 = 0;
            puVar8 = puVar6;
            if (param_1[2] != 0) {
              do {
                *puVar8 = uVar1;
                iVar3 = _km_coni + iVar3;
                puVar8 = puVar8 + 1;
              } while (iVar3 < (int)(uint)param_1[2]);
            }
            puVar6 = (undefined4 *)(dword_40B6940 + (int)puVar6);
            iVar9 = iVar9 + 1;
          } while (iVar9 < (int)(uint)param_1[3]);
        }
      }
      return 0;
    }
  }
  return 0x16;
}

