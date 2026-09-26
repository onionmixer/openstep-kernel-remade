
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _km_drawrect(word *param_1)

{
  word wVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  byte bVar6;
  undefined *puVar7;
  undefined2 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  byte *pbVar11;
  undefined *puVar12;
  undefined2 *puVar13;
  undefined4 *puVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  
  iVar10 = dword_40B6944 + -0x460;
  if (iVar10 < 0) {
    iVar10 = dword_40B6944 + -0x45f;
  }
  *param_1 = (sword)(iVar10 >> 1) + *param_1;
  iVar10 = _unk_40B694C + -0x340;
  if (iVar10 < 0) {
    iVar10 = _unk_40B694C + -0x33f;
  }
  param_1[1] = (sword)(iVar10 >> 1) + param_1[1];
  *param_1 = *param_1 & 0xfffc;
  wVar1 = param_1[2] + 3;
  param_1[2] = wVar1 & 0xfffc;
  if ((int)((uint)*param_1 + (wVar1 & 0xfffc)) <= dword_40B6944) {
    if ((int)((uint)param_1[1] + (uint)param_1[3]) <= _unk_40B694C) {
      iVar10 = dword_40B6948 * (uint)param_1[1] + (uint)*param_1;
      iVar2 = (uint)(wVar1 >> 2) * (uint)param_1[3];
      if (iVar2 != 0) {
        pbVar3 = (byte *)_kalloc(iVar2);
        iVar4 = _copyinmsg(*(undefined4 *)(param_1 + 4),pbVar3,iVar2);
        if (iVar4 == 0) {
          if (_km_coni == 2) {
            puVar8 = (undefined2 *)(iVar10 * 2 + dword_40B6980);
            iVar10 = 0;
            pbVar16 = pbVar3;
            if (param_1[3] != 0) {
              do {
                iVar4 = 0;
                puVar13 = puVar8;
                pbVar17 = pbVar16;
                if (param_1[2] != 0) {
                  do {
                    pbVar16 = pbVar17 + 1;
                    bVar6 = *pbVar17;
                    *puVar13 = *(undefined2 *)((int)&dword_40B6954 + (uint)(bVar6 >> 6) * 4 + 2);
                    puVar13[1] = *(undefined2 *)
                                  ((int)&dword_40B6954 + ((bVar6 & 0x3f) >> 4) * 4 + 2);
                    puVar13[2] = *(undefined2 *)((int)&dword_40B6954 + (bVar6 & 0xc) + 2);
                    puVar13[3] = *(undefined2 *)((int)&dword_40B6954 + (bVar6 & 3) * 4 + 2);
                    iVar4 = iVar4 + 4;
                    puVar13 = puVar13 + 4;
                    pbVar17 = pbVar16;
                  } while (iVar4 < (int)(uint)param_1[2]);
                }
                puVar8 = (undefined2 *)(dword_40B6940 + (int)puVar8);
                iVar10 = iVar10 + 1;
              } while (iVar10 < (int)(uint)param_1[3]);
            }
          }
          else if (_km_coni < 3) {
            if (_km_coni == 1) {
              puVar9 = (undefined4 *)(iVar10 * 4 + dword_40B6980);
              iVar10 = 0;
              pbVar16 = pbVar3;
              if (param_1[3] != 0) {
                do {
                  iVar4 = 0;
                  puVar14 = puVar9;
                  pbVar17 = pbVar16;
                  if (param_1[2] != 0) {
                    do {
                      pbVar16 = pbVar17 + 1;
                      bVar6 = *pbVar17;
                      *puVar14 = (&dword_40B6954)[bVar6 >> 6];
                      puVar14[1] = (&dword_40B6954)[(bVar6 & 0x3f) >> 4];
                      puVar14[2] = *(undefined4 *)((int)&dword_40B6954 + (bVar6 & 0xc));
                      puVar14[3] = (&dword_40B6954)[bVar6 & 3];
                      iVar4 = iVar4 + 4;
                      puVar14 = puVar14 + 4;
                      pbVar17 = pbVar16;
                    } while (iVar4 < (int)(uint)param_1[2]);
                  }
                  puVar9 = (undefined4 *)(dword_40B6940 + (int)puVar9);
                  iVar10 = iVar10 + 1;
                } while (iVar10 < (int)(uint)param_1[3]);
              }
            }
          }
          else if (_km_coni == 4) {
            puVar7 = (undefined *)(iVar10 + dword_40B6980);
            iVar10 = 0;
            pbVar16 = pbVar3;
            if (param_1[3] != 0) {
              do {
                iVar4 = 0;
                puVar12 = puVar7;
                pbVar17 = pbVar16;
                if (param_1[2] != 0) {
                  do {
                    pbVar16 = pbVar17 + 1;
                    bVar6 = *pbVar17;
                    *puVar12 = *(undefined *)((int)&dword_40B6954 + (uint)(bVar6 >> 6) * 4 + 3);
                    puVar12[1] = *(undefined *)((int)&dword_40B6954 + ((bVar6 & 0x3f) >> 4) * 4 + 3)
                    ;
                    puVar12[2] = *(undefined *)((int)&dword_40B6954 + (bVar6 & 0xc) + 3);
                    puVar12[3] = *(undefined *)((int)&dword_40B6954 + (bVar6 & 3) * 4 + 3);
                    iVar4 = iVar4 + 4;
                    puVar12 = puVar12 + 4;
                    pbVar17 = pbVar16;
                  } while (iVar4 < (int)(uint)param_1[2]);
                }
                puVar7 = puVar7 + dword_40B6940;
                iVar10 = iVar10 + 1;
              } while (iVar10 < (int)(uint)param_1[3]);
            }
          }
          else if (_km_coni == 0x10) {
            pbVar17 = (byte *)((iVar10 >> 2) + dword_40B6980);
            iVar10 = 0;
            pbVar16 = pbVar3;
            if (param_1[3] != 0) {
              do {
                iVar4 = 0;
                pbVar11 = pbVar17;
                pbVar15 = pbVar16;
                if (param_1[2] != 0) {
                  do {
                    pbVar16 = pbVar15 + 1;
                    bVar6 = 0;
                    uVar5 = 0;
                    do {
                      bVar6 = (byte)(((&dword_40B6954)[(int)(uint)*pbVar15 >> (uVar5 & 0x3f) & 3] &
                                     3) << (uVar5 & 0x3f)) | bVar6;
                      uVar5 = uVar5 + 2;
                    } while ((int)uVar5 < 8);
                    *pbVar11 = bVar6;
                    iVar4 = iVar4 + 4;
                    pbVar11 = pbVar11 + 1;
                    pbVar15 = pbVar16;
                  } while (iVar4 < (int)(uint)param_1[2]);
                }
                pbVar17 = pbVar17 + dword_40B6940;
                iVar10 = iVar10 + 1;
              } while (iVar10 < (int)(uint)param_1[3]);
            }
          }
          _kfree(pbVar3,iVar2);
          return 0;
        }
        _kfree(pbVar3,iVar2);
      }
    }
  }
  return 0x16;
}

