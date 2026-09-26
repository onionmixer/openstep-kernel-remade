
uint sub_408C552(int param_1)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  word wVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  byte *pbVar9;
  char cVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  byte bVar15;
  uint uVar16;
  byte bStack_86;
  byte bStack_85;
  byte abStack_84 [128];
  byte *pbVar10;
  
  iVar1 = param_1 * 0x86;
  puVar2 = unk_40B51BC + iVar1;
  iVar5 = _ttynty(puVar2);
  uVar6 = param_1 * 0x164;
  pbVar9 = abStack_84;
  if ((*(byte *)((int)&DAT_40b53fc + uVar6 + 6) & 1) != 0) {
    bVar15 = 0x40;
    if (((*(uint *)(iVar5 + 0x10) & 0x201000) == 0x201000) &&
       (((*(uint *)(unk_40B51BC + iVar1 + 0x3a) & 0xc0) == 0x80 ||
        ((*(uint *)(unk_40B51BC + iVar1 + 0x3a) & 0xc0) == 0x40)))) {
      bVar15 = 0x50;
    }
    uVar16 = *(uint *)(unk_40B51BC + iVar1 + 0x3e);
    *(uint *)(unk_40B51BC + iVar1 + 0x3e) = uVar16 & 0xfeffffff;
    if ((uVar16 & 0x800000) == 0) {
      do {
        if (*(word **)(DAT_40b52d0 + uVar6 + 8) == *(word **)(DAT_40b52d0 + uVar6 + 4)) break;
        wVar4 = **(word **)(DAT_40b52d0 + uVar6 + 8);
        uVar16 = *(uint *)(DAT_40b52d0 + uVar6);
        uVar8 = *(int *)(DAT_40b52d0 + uVar6 + 8) + 2U;
        if (uVar16 + dword_40B51A8 * 2 <= *(int *)(DAT_40b52d0 + uVar6 + 8) + 2U) {
          uVar8 = uVar16;
        }
        *(uint *)(DAT_40b52d0 + uVar6 + 8) = uVar8;
        bStack_86 = (byte)(wVar4 >> 8);
        bStack_85 = (byte)wVar4;
        if (bStack_86 == 0) {
          if (abStack_84 != pbVar9) {
            iVar5 = (int)pbVar9 - (int)abStack_84;
            piVar3 = (int *)((int)&_zschars + param_1 * 4);
            *piVar3 = iVar5 + *piVar3;
            pbVar9 = abStack_84;
            if ((unk_40B51BC[iVar1 + 0x41] & 4) != 0) {
              (**(code **)(DAT_40ae4c0 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30 + 4))
                        (abStack_84,iVar5,puVar2);
            }
          }
          uVar16 = (int)(char)bStack_85 ^ *(uint *)(DAT_40b5420 + uVar6);
          *(uint *)(DAT_40b5420 + uVar6) = uVar16 & 0x38 ^ *(uint *)(DAT_40b5420 + uVar6);
          if ((((uVar16 & 0x10) != 0) && ((*(uint *)((int)&DAT_40b53fc + uVar6 + 4) & 0x14) == 4))
             && (*(int *)(DAT_40b5420 + uVar6 + 0xc) == 0)) {
            *(undefined4 *)(DAT_40b5420 + uVar6 + 0xc) = 1;
            _us_timeout(sub_408C984,param_1,&unk_40B23C2,0);
          }
          if (((uVar16 & 0x20) != 0) && ((DAT_40b5420[uVar6 + 3] & 0x20) == 0)) {
            iVar5 = dword_40B51A8 * 2;
            do {
              if (*(byte **)(DAT_40b52d0 + uVar6 + 8) != *(byte **)(DAT_40b52d0 + uVar6 + 4)) {
                bVar7 = **(byte **)(DAT_40b52d0 + uVar6 + 8) & 1;
                goto loc_408C702;
              }
              do {
                bVar7 = 2;
loc_408C702:
                if (bVar7 != 1) {
                  if (*(sword *)(unk_40B51BC + iVar1 + 0x38) == *(sword *)(_cons_tp + 0x38)) {
                    _mini_mon(aSerialNmi,&unk_40A62E7);
                  }
                  if ((unk_40B51BC[iVar1 + 0x41] & 4) == 0) goto loc_408C84E;
                  cVar12 = unk_40B51BC[iVar1 + 0x45];
                  uVar16 = 0x1000000;
                  goto loc_408C7FC;
                }
              } while (*(int *)(DAT_40b52d0 + uVar6 + 8) == *(int *)(DAT_40b52d0 + uVar6 + 4));
              uVar16 = *(uint *)(DAT_40b52d0 + uVar6);
              uVar8 = *(int *)(DAT_40b52d0 + uVar6 + 8) + 2U;
              if (iVar5 + uVar16 <= *(int *)(DAT_40b52d0 + uVar6 + 8) + 2U) {
                uVar8 = uVar16;
              }
              *(uint *)(DAT_40b52d0 + uVar6 + 8) = uVar8;
            } while( true );
          }
        }
        else if ((bVar15 & bStack_86) == 0) {
          bVar7 = *(byte *)((int)&DAT_40b53fc + uVar6 + 3);
          pbVar10 = pbVar9;
          if (&stack0xfffffffc <= pbVar9) {
            iVar5 = (int)pbVar9 - (int)abStack_84;
            piVar3 = (int *)((int)&_zschars + param_1 * 4);
            *piVar3 = iVar5 + *piVar3;
            pbVar10 = abStack_84;
            if ((unk_40B51BC[iVar1 + 0x41] & 4) != 0) {
              (**(code **)(DAT_40ae4c0 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30 + 4))
                        (abStack_84,iVar5,puVar2);
            }
          }
          pbVar9 = pbVar10 + 1;
          *pbVar10 = bVar7 & bStack_85;
        }
        else {
          uVar16 = *(uint *)((int)&DAT_40b53fc + uVar6) & (int)(char)bStack_85;
          if (abStack_84 != pbVar9) {
            iVar5 = (int)pbVar9 - (int)abStack_84;
            piVar3 = (int *)((int)&_zschars + param_1 * 4);
            *piVar3 = iVar5 + *piVar3;
            pbVar9 = abStack_84;
            if ((unk_40B51BC[iVar1 + 0x41] & 4) != 0) {
              (**(code **)(DAT_40ae4c0 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30 + 4))
                        (abStack_84,iVar5,puVar2);
            }
          }
          if ((wVar4 & 0x4000) != 0) {
            uVar16 = uVar16 | 0x1000000;
          }
          if ((wVar4 & 0x1000) != 0) {
            uVar16 = uVar16 | 0x2000000;
          }
          if ((unk_40B51BC[iVar1 + 0x41] & 4) != 0) {
            cVar12 = unk_40B51BC[iVar1 + 0x45];
loc_408C7FC:
            (**(code **)(DAT_40ae4c0 + cVar12 * 0x30))(uVar16,puVar2);
          }
        }
loc_408C84E:
      } while (-1 < (char)unk_40B51BC[iVar1 + 0x3f]);
    }
    if (abStack_84 != pbVar9) {
      iVar5 = (int)pbVar9 - (int)abStack_84;
      piVar3 = (int *)((int)&_zschars + param_1 * 4);
      *piVar3 = iVar5 + *piVar3;
      if ((unk_40B51BC[iVar1 + 0x41] & 4) != 0) {
        (**(code **)(DAT_40ae4c0 + (char)unk_40B51BC[iVar1 + 0x45] * 0x30 + 4))
                  (abStack_84,iVar5,puVar2);
      }
    }
    cVar11 = '\0';
    cVar14 = false;
    cVar12 = false;
    bVar15 = false;
    if ((char)unk_40B51BC[iVar1 + 0x3f] < '\0') {
      if (*(byte **)(DAT_40b52d0 + uVar6 + 8) == *(byte **)(DAT_40b52d0 + uVar6 + 4)) {
        uVar16 = 2;
      }
      else {
        uVar16 = (uint)(char)(**(byte **)(DAT_40b52d0 + uVar6 + 8) & 1);
      }
      cVar11 = 2 < uVar16;
      cVar14 = SBORROW4(2,uVar16);
      cVar12 = (int)(2 - uVar16) < 0;
      bVar15 = cVar11;
      if (uVar16 != 2) {
        if ((*(uint *)(unk_40B5404 + uVar6) & 4) == 0) {
          *(uint *)(unk_40B5404 + uVar6) = *(uint *)(unk_40B5404 + uVar6) | 4;
          _us_timeout(sub_408C50E,param_1,&unk_40B23CA,0);
        }
        cVar14 = false;
        cVar12 = false;
        bVar15 = false;
        if ((*(uint *)(unk_40B51BC + iVar1 + 0x3a) & 0x22) != 0) {
          uVar16 = *(uint *)(DAT_40b52d0 + uVar6 + 4);
          uVar8 = *(uint *)(DAT_40b52d0 + uVar6 + 8);
          if (uVar16 < uVar8) {
            uVar16 = dword_40B51A8 - ((int)(uVar8 - uVar16) >> 1);
          }
          else {
            uVar16 = (int)(uVar16 - uVar8) >> 1;
          }
          cVar11 = uVar16 < dword_40B51B4;
          cVar14 = SBORROW4(uVar16,dword_40B51B4);
          cVar12 = (int)(uVar16 - dword_40B51B4) < 0;
          bVar15 = cVar11;
          if ((int)dword_40B51B4 < (int)uVar16) {
            unk_40B51BC[iVar1 + 0x3e] = unk_40B51BC[iVar1 + 0x3e] | 1;
          }
        }
      }
    }
    cVar13 = (*(byte *)((int)&DAT_40b53fc + uVar6 + 7) & 0x40) == 0;
    if (!(bool)cVar13) {
      uVar16 = *(uint *)(DAT_40b5420 + uVar6) & 5;
      cVar11 = 4 < uVar16;
      cVar14 = SBORROW4(4,uVar16);
      cVar12 = (int)(4 - uVar16) < 0;
      cVar13 = '\0';
      bVar15 = cVar11;
      if (uVar16 == 4) {
        uVar16 = *(uint *)(DAT_40b52d0 + uVar6 + 4);
        uVar8 = *(uint *)(DAT_40b52d0 + uVar6 + 8);
        if (uVar16 < uVar8) {
          uVar16 = dword_40B51A8 - ((int)(uVar8 - uVar16) >> 1);
        }
        else {
          uVar16 = (int)(uVar16 - uVar8) >> 1;
        }
        cVar11 = uVar16 < dword_40B51B4;
        cVar14 = SBORROW4(uVar16,dword_40B51B4);
        cVar12 = (int)(uVar16 - dword_40B51B4) < 0;
        cVar13 = uVar16 == dword_40B51B4;
        bVar15 = cVar11;
        if ((int)uVar16 <= (int)dword_40B51B4) {
          *(uint *)(DAT_40b5420 + uVar6) = *(uint *)(DAT_40b5420 + uVar6) | 1;
          cVar12 = param_1 < 0;
          cVar13 = param_1 == 0;
          cVar14 = '\0';
          bVar15 = 0;
          sub_408CFC8(param_1);
        }
      }
    }
    uVar6 = (uint)(byte)(cVar11 << 4 | cVar12 << 3 | cVar13 << 2 | cVar14 << 1 | bVar15);
  }
  return uVar6;
}

