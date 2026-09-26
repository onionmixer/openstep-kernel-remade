
undefined4 _kmrestore(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  undefined2 *puVar9;
  sword sVar10;
  
  if ((unk_40B6904 & 8) != 0) {
    if (dword_40B68E8 != (undefined4 *)0x0) {
      iVar6 = dword_40B6980 + (uint)((int)word_40B68DE << 5) / _km_coni;
      uVar1 = _km_coni * 2;
      iVar5 = 0;
      puVar4 = dword_40B68E8;
      if (0 < word_40B68E4 * 0xc + 0x1a) {
        do {
          puVar7 = (undefined4 *)
                   (dword_40B6940 * (word_40B68DC * 0xc + -0x18 + iVar5) + (iVar6 - 0x60 / uVar1));
          if (_km_coni == 2) {
            iVar2 = 7;
            puVar3 = puVar4;
            puVar9 = (undefined2 *)((int)puVar7 + 0xe);
            if (7 < word_40B68E0 * 8 + 0x11) {
              do {
                puVar4 = (undefined4 *)((int)puVar3 + 2);
                *puVar9 = *(undefined2 *)puVar3;
                iVar2 = iVar2 + 1;
                puVar3 = puVar4;
                puVar9 = puVar9 + 1;
              } while (iVar2 < word_40B68E0 * 8 + 0x11);
            }
          }
          else if ((int)_km_coni < 3) {
            if (_km_coni == 1) {
              puVar7 = puVar7 + 7;
              for (iVar2 = 7; iVar2 < word_40B68E0 * 8 + 0x11; iVar2 = iVar2 + 1) {
                *puVar7 = *puVar4;
                puVar4 = puVar4 + 1;
                puVar7 = puVar7 + 1;
              }
            }
          }
          else if (_km_coni == 4) {
            iVar2 = 7;
            puVar3 = puVar4;
            puVar8 = (undefined *)((int)puVar7 + 7);
            if (7 < word_40B68E0 * 8 + 0x11) {
              do {
                puVar4 = (undefined4 *)((int)puVar3 + 1);
                *puVar8 = *(undefined *)puVar3;
                iVar2 = iVar2 + 1;
                puVar3 = puVar4;
                puVar8 = puVar8 + 1;
              } while (iVar2 < word_40B68E0 * 8 + 0x11);
            }
          }
          else if ((_km_coni == 0x10) &&
                  (iVar2 = 0, puVar3 = puVar4, 0 < (word_40B68E0 + 3 >> 1) + 1)) {
            do {
              puVar4 = puVar3 + 1;
              *puVar7 = *puVar3;
              iVar2 = iVar2 + 1;
              puVar3 = puVar4;
              puVar7 = puVar7 + 1;
            } while (iVar2 < (word_40B68E0 + 3 >> 1) + 1);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < word_40B68E4 * 0xc + 0x1a);
      }
    }
    _km_end_access();
    sVar10 = word_40B6906 + -1;
    iVar6 = (int)(sword)(word_40B6906 + -1);
    _cons_tp = *(undefined4 *)(unk_40B6918 + iVar6 * 4);
    unk_40B6904 = *(word *)(unk_40B6908 + iVar6 * 2) & 8 | unk_40B6904 & 0xfff7;
    word_40B6906 = sVar10;
    if ((unk_40B6908[iVar6 * 2] & 4) != 0) {
      _vidResumeAnimation();
    }
  }
  return 0;
}

