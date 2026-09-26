
/* WARNING: Removing unreachable block (ram,0xf00e6184) */
/* WARNING: Removing unreachable block (ram,0xf00e6118) */
/* WARNING: Removing unreachable block (ram,0xf00e6100) */
/* WARNING: Removing unreachable block (ram,0xf00e616c) */
/* WARNING: Removing unreachable block (ram,0xf00e622c) */
/* WARNING: Removing unreachable block (ram,0xf00e60cc) */

undefined8 _sparcfbRestoreRect(uint param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 unaff_l1;
  int *piVar7;
  uint uVar8;
  undefined4 unaff_l3;
  int *piVar9;
  undefined4 unaff_l4;
  int iVar10;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar11;
  undefined4 unaff_l7;
  int *piVar12;
  undefined4 unaff_i0;
  undefined4 uVar13;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar14;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
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
  iVar2 = param_1 * 0x44 + 8;
  iVar10 = _sparcfbs + iVar2;
  if ((param_1 < 0x10) && (*(int *)(_sparcfbs + iVar2) != 0)) {
    bVar14 = dword_F012EF68 == (int *)0x0;
    piVar9 = dword_F012EF68;
    piVar12 = (int *)0x0;
    if (!bVar14) {
      iVar2 = *dword_F012EF68;
      while (piVar7 = piVar9, bVar14 = piVar7 == (int *)0x0, piVar9 = piVar7, iVar2 == 0) {
        piVar9 = (int *)piVar7[2];
        piVar12 = piVar7;
        if (piVar9 == (int *)0x0) {
          bVar14 = true;
          break;
        }
        iVar2 = *piVar9;
      }
    }
    uVar13 = 0xfffffd3e;
    if ((!bVar14) && (piVar9[3] == *(int *)(iVar10 + 0x34))) {
      wVar1 = *(word *)(piVar9 + 5);
      uVar8 = (uint)*(word *)((int)piVar9 + 0x16);
      iVar2 = *(int *)(iVar10 + 0x38);
      uVar3 = (uint)*(word *)((int)piVar9 + 0x12);
      uVar11 = (uint)*(word *)(piVar9 + 4);
      div(iVar2,*(undefined4 *)(iVar10 + 0x34));
      if (*(int *)(iVar10 + 0x34) == 1) {
        piVar7 = piVar9 + 7;
        umul(uVar3,*(undefined4 *)(iVar10 + 0x38));
        iVar5 = *(int *)(iVar10 + 0x14);
        umul(uVar11,*(undefined4 *)(iVar10 + 0x34));
        puVar4 = (undefined *)(iVar5 + uVar3 + uVar11);
        while (uVar8 = uVar8 - 1, -1 < (int)uVar8) {
          uVar3 = (uint)*(word *)(piVar9 + 5);
          while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
            *puVar4 = *(undefined *)piVar7;
            piVar7 = (int *)((int)piVar7 + 1);
            puVar4 = puVar4 + 1;
          }
          puVar4 = puVar4 + (iVar2 - (uint)wVar1);
        }
      }
      else {
        piVar7 = piVar9 + 7;
        if (*(int *)(iVar10 + 0x34) == 4) {
          umul(uVar3,*(undefined4 *)(iVar10 + 0x38));
          iVar5 = *(int *)(iVar10 + 0x18);
          umul(uVar11,*(undefined4 *)(iVar10 + 0x34));
          piVar6 = (int *)(iVar5 + uVar3 + uVar11);
          while (uVar8 = uVar8 - 1, -1 < (int)uVar8) {
            uVar3 = (uint)*(word *)(piVar9 + 5);
            while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
              *piVar6 = *piVar7;
              piVar7 = piVar7 + 1;
              piVar6 = piVar6 + 1;
            }
            piVar6 = piVar6 + (iVar2 - (uint)wVar1);
          }
        }
      }
      if (piVar12 == (int *)0x0) {
        dword_F012EF68 = (int *)piVar9[2];
      }
      else {
        piVar12[2] = piVar9[2];
      }
      if (dword_F012EF74 < 10) {
        dword_F012EF74 = dword_F012EF74 + 1;
        piVar9[2] = (int)dword_F012EF6C;
        dword_F012EF6C = piVar9;
      }
      else {
        if (piVar9 != (int *)unk_F01330E4) {
          _kmem_free(_kernel_map,piVar9);
          uVar13 = 0;
          goto locret_F00E6254;
        }
        dword_F012EF78 = 0xc04;
      }
      uVar13 = 0;
    }
  }
  else {
    uVar13 = 0xfffffd40;
  }
locret_F00E6254:
  return CONCAT44(param_2,uVar13);
}

