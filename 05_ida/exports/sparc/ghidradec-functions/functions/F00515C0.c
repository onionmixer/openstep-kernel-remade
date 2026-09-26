
/* WARNING: Removing unreachable block (ram,0xf0051b24) */
/* WARNING: Removing unreachable block (ram,0xf0051a9c) */
/* WARNING: Removing unreachable block (ram,0xf0051a78) */
/* WARNING: Removing unreachable block (ram,0xf00516b8) */
/* WARNING: Removing unreachable block (ram,0xf0051948) */
/* WARNING: Removing unreachable block (ram,0xf00518f0) */
/* WARNING: Removing unreachable block (ram,0xf005197c) */
/* WARNING: Removing unreachable block (ram,0xf0051714) */
/* WARNING: Removing unreachable block (ram,0xf005169c) */
/* WARNING: Removing unreachable block (ram,0xf0051628) */
/* WARNING: Removing unreachable block (ram,0xf0051704) */
/* WARNING: Removing unreachable block (ram,0xf005177c) */
/* WARNING: Removing unreachable block (ram,0xf0051968) */
/* WARNING: Removing unreachable block (ram,0xf0051900) */
/* WARNING: Removing unreachable block (ram,0xf0051934) */
/* WARNING: Removing unreachable block (ram,0xf00519bc) */
/* WARNING: Removing unreachable block (ram,0xf0051aac) */
/* WARNING: Removing unreachable block (ram,0xf0051a48) */
/* WARNING: Removing unreachable block (ram,0xf00515e0) */

undefined8 sub_F00515C0(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  word wVar5;
  int iVar6;
  undefined *puVar7;
  int iVar8;
  uint *puVar9;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar10;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar11;
  undefined4 unaff_l5;
  uint uVar12;
  undefined4 unaff_l6;
  word wVar13;
  undefined4 unaff_l7;
  uint *puVar14;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar15;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_2 + 0x14);
  if (1 < param_3) {
    _panic(&aRwip);
  }
  wVar13 = *(word *)(param_1 + 100) & 0xf000;
  if (wVar13 == 0x8000) {
    iVar6 = *(int *)(param_2 + 8);
  }
  else if (wVar13 == 0x4000) {
    iVar6 = *(int *)(param_2 + 8);
  }
  else if (wVar13 == 0xa000) {
    iVar6 = *(int *)(param_2 + 8);
  }
  else {
    _panic(aRwipType);
    iVar6 = *(int *)(param_2 + 8);
  }
  if (iVar6 < 0) {
    iVar6 = 0x16;
  }
  else {
    uVar12 = iVar6 + *(int *)(param_2 + 0x14);
    if ((int)uVar12 < 0) {
      iVar6 = 0x16;
    }
    else if (*(int *)(param_2 + 0x14) == 0) {
      iVar6 = 0;
    }
    else {
      if (param_3 == 1) {
        if ((wVar13 == 0x8000) && ((uint)_active_u[0x9a] < uVar12)) {
          _psignal(*_active_u,0x19);
          iVar6 = 0x1b;
          goto locret_F0051B48;
        }
      }
      else {
        *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 4;
      }
      puVar14 = *(uint **)(param_1 + 0x40);
      iVar11 = *(int *)(param_1 + 0x50);
      uVar12 = *(uint *)(iVar11 + 0x30);
      *(uint *)((int)register0x00000038 + -0x1c) = (uint)(param_3 != 1);
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
      iVar6 = *(int *)(param_2 + 8);
      while( true ) {
        iVar1 = iVar6;
        .udiv(iVar6,uVar12);
        iVar2 = iVar6;
        .urem(iVar6,uVar12);
        uVar10 = *(uint *)(param_2 + 0x14);
        if (uVar12 - iVar2 < *(uint *)(param_2 + 0x14)) {
          uVar10 = uVar12 - iVar2;
        }
        if (param_3 == 0) {
          uVar3 = *(int *)(param_1 + 0x70) - iVar6;
          if ((int)uVar3 < 1) {
            iVar6 = 0;
            goto locret_F0051B48;
          }
          if ((int)uVar3 < (int)uVar10) {
            uVar10 = uVar3;
          }
        }
        puVar7 = (undefined *)0x0;
        if ((param_4 & 4) != 0) {
          puVar7 = (undefined *)((int)register0x00000038 + -0xc);
        }
        iVar8 = param_1;
        _bmap(param_1,iVar1,*(undefined4 *)((int)register0x00000038 + -0x1c),iVar2 + uVar10,puVar7);
        iVar8 = iVar8 << ((byte)*(undefined4 *)(iVar11 + 100) & 0x1f);
        if ((((*(char *)(dword_F0133DDC + 0x38) == '\x1c') && (param_3 == 1)) &&
            (0 < *(int *)((int)register0x00000038 + -0x14) - *(int *)(param_2 + 0x14))) &&
           ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0)) break;
        iVar6 = (int)*(char *)(dword_F0133DDC + 0x38);
        if (iVar6 != 0) goto locret_F0051B48;
        bVar15 = iVar1 + -0xb < 0;
        if (param_3 == 1) {
          if (iVar8 < 0) goto locret_F0051B48;
          bVar15 = iVar1 + -0xb < 0;
          if ((*(uint *)(param_1 + 0x70) < *(int *)(param_2 + 8) + uVar10) &&
             (((wVar13 == 0x4000 || (wVar13 == 0x8000)) ||
              (bVar15 = iVar1 + -0xb < 0, wVar13 == 0xa000)))) {
            uVar3 = *(int *)(param_2 + 8) + uVar10;
            *(uint *)(param_1 + 0x70) = uVar3;
            if (*(uint *)(*(int *)(param_1 + 0xc) + 0x14) < uVar3) {
              *(uint *)(*(int *)(param_1 + 0xc) + 0x14) = uVar3;
            }
            if ((param_4 & 4) != 0) {
              *(undefined4 *)((int)register0x00000038 + -0xc) = 1;
            }
            bVar15 = iVar1 + -0xb < 0;
          }
        }
        if (iVar1 == 0xb || bVar15 != SBORROW4(iVar1,0xb)) {
          if (*(uint *)(param_1 + 0x70) <
              (uint)(iVar1 + 1 << ((byte)*(undefined4 *)(iVar11 + 0x50) & 0x1f))) {
            puVar9 = (uint *)(((*(uint *)(param_1 + 0x70) & ~*(uint *)(iVar11 + 0x48)) +
                              *(int *)(iVar11 + 0x34)) - 1 & *(uint *)(iVar11 + 0x4c));
          }
          else {
            puVar9 = *(uint **)(iVar11 + 0x30);
          }
        }
        else {
          puVar9 = *(uint **)(iVar11 + 0x30);
        }
        if (param_3 == 0) {
          if (iVar8 < 0) {
            _geteblk();
            _bzero(puVar9[8],puVar9[5]);
            puVar9[10] = 0;
          }
          else if (*(int *)(param_1 + 0x58) + 1 == iVar1) {
            puVar4 = puVar14;
            _breada(puVar14,iVar8,puVar9,_rablock,_rasize);
            puVar9 = puVar4;
          }
          else {
            puVar4 = puVar14;
            _bread(puVar14,iVar8,puVar9);
            puVar9 = puVar4;
          }
          *(int *)(param_1 + 0x58) = iVar1;
          puVar4 = puVar9;
        }
        else {
          puVar4 = puVar14;
          if (uVar10 == uVar12) {
            _getblk(puVar14,iVar8,puVar9);
          }
          else {
            _bread(puVar14,iVar8,puVar9);
          }
        }
        if ((int)(puVar4[5] - puVar4[10]) < (int)uVar10) {
          uVar10 = puVar4[5] - puVar4[10];
        }
        if ((*puVar4 & 4) != 0) {
          _brelse(puVar4,uVar10);
          iVar6 = 5;
          goto locret_F0051B48;
        }
        iVar6 = puVar4[8] + iVar2;
        _uiomove(iVar6,uVar10,param_3,param_2);
        *(char *)(dword_F0133DDC + 0x38) = (char)iVar6;
        if ((((param_4 & 4) != 0) && ((*(word *)(param_1 + 100) & 0x200) != 0)) &&
           ((_stickyhack != 0 && ((*(word *)(param_1 + 100) & 0x49) == 0)))) {
          *puVar4 = *puVar4 | 0x400000;
        }
        if (param_3 == 0) {
          if (uVar10 + iVar2 == uVar12) {
            uVar3 = *puVar4;
loc_F0051A40:
            *puVar4 = uVar3 | 0x80;
          }
          else if (*(int *)(param_2 + 8) == *(int *)(param_1 + 0x70)) {
            uVar3 = *puVar4;
            goto loc_F0051A40;
          }
          _brelse(puVar4);
        }
        else {
          if (((param_4 & 4) == 0) && ((*(word *)(param_1 + 100) & 0xf000) != 0x4000)) {
            if (uVar10 + iVar2 == uVar12) {
              *puVar4 = *puVar4 | 0x80;
              _bawrite();
              wVar5 = *(word *)(param_1 + 0x44);
            }
            else {
              _bdwrite(puVar4);
              wVar5 = *(word *)(param_1 + 0x44);
            }
          }
          else {
            _bwrite(puVar4);
            wVar5 = *(word *)(param_1 + 0x44);
          }
          *(word *)(param_1 + 0x44) = wVar5 | 0x42;
          if (*(sword *)(_active_u[7] + 6) != 0) {
            *(word *)(param_1 + 100) = *(word *)(param_1 + 100) & 0xf3ff;
          }
        }
        iVar6 = *(int *)((int)register0x00000038 + -0xc);
        if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto loc_F0051B18;
        if ((*(int *)(param_2 + 0x14) < 1) || (uVar10 == 0)) goto loc_F0051B14;
        iVar6 = *(int *)(param_2 + 8);
      }
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
loc_F0051B14:
      iVar6 = *(int *)((int)register0x00000038 + -0xc);
loc_F0051B18:
      if (iVar6 != 0) {
        _iupdat(param_1,1);
      }
      iVar6 = (int)*(char *)(dword_F0133DDC + 0x38);
    }
  }
locret_F0051B48:
  return CONCAT44(param_2,iVar6);
}
