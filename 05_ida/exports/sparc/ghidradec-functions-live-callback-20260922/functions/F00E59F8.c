
/* WARNING: Removing unreachable block (ram,0xf00e5af0) */
/* WARNING: Removing unreachable block (ram,0xf00e5b8c) */
/* WARNING: Removing unreachable block (ram,0xf00e5c58) */
/* WARNING: Removing unreachable block (ram,0xf00e5cf4) */
/* WARNING: Removing unreachable block (ram,0xf00e5cdc) */
/* WARNING: Removing unreachable block (ram,0xf00e5c40) */
/* WARNING: Removing unreachable block (ram,0xf00e5ad4) */
/* WARNING: Removing unreachable block (ram,0xf00e5ba4) */
/* WARNING: Removing unreachable block (ram,0xf00e5b08) */
/* WARNING: Removing unreachable block (ram,0xf00e5c24) */

qword _sparcfbDrawRect(uint param_1,word *param_2,undefined4 param_3,byte *param_4)

{
  int iVar1;
  word wVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 *puVar6;
  undefined *puVar7;
  undefined4 unaff_l1;
  uint uVar8;
  uint uVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
  undefined4 unaff_i1;
  uint uVar11;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  iVar4 = -0x2c7;
  uVar8 = (uint)param_2[3];
  uVar9 = (uint)*param_2;
  uVar5 = (uint)param_2[1];
  iVar3 = param_1 * 0x44 + 8;
  wVar2 = param_2[2];
  uVar11 = (uint)wVar2;
  iVar10 = _sparcfbs + iVar3;
  if ((param_1 < 0x10) && (*(int *)(_sparcfbs + iVar3) != 0)) {
    switch(param_3) {
    case :
      iVar3 = *(int *)(iVar10 + 0x38);
      div(iVar3,*(undefined4 *)(iVar10 + 0x34));
      if (*(int *)(iVar10 + 0x30) == 0x18) {
        umul(uVar5,*(undefined4 *)(iVar10 + 0x38));
        iVar4 = *(int *)(iVar10 + 0x18);
        umul(uVar9,*(undefined4 *)(iVar10 + 0x34));
        puVar6 = (undefined4 *)(iVar4 + uVar5 + uVar9);
        iVar4 = 0;
        iVar10 = uVar8 - 1;
        uVar5 = 0;
        uVar9 = uVar11;
        if (-1 < iVar10) {
          do {
            while (-1 < (int)(uVar9 - 1)) {
              iVar4 = iVar4 + -1;
              uVar8 = (int)uVar5 >> ((byte)iVar4 & 0x1f);
              if (iVar4 < 0) {
                uVar5 = (uint)*param_4;
                iVar4 = 7;
                param_4 = param_4 + 1;
                uVar8 = (int)uVar5 >> 7;
              }
              *puVar6 = *(undefined4 *)((int)&unk_F00FA060 + (uVar8 & 1) * 4);
              puVar6 = puVar6 + 1;
              uVar9 = uVar9 - 1;
            }
            iVar1 = iVar10 + -1;
            puVar6 = puVar6 + (iVar3 - uVar11);
            uVar9 = uVar11;
            iVar10 = iVar10 + -1;
          } while (-1 < iVar1);
          iVar4 = 0;
        }
      }
      else {
        umul(uVar5,*(undefined4 *)(iVar10 + 0x38));
        iVar4 = *(int *)(iVar10 + 0x14);
        umul(uVar9,*(undefined4 *)(iVar10 + 0x34));
        puVar7 = (undefined *)(iVar4 + uVar5 + uVar9);
        iVar4 = 0;
        iVar10 = uVar8 - 1;
        uVar5 = 0;
        uVar9 = uVar11;
        if (-1 < iVar10) {
          do {
            while (-1 < (int)(uVar9 - 1)) {
              iVar4 = iVar4 + -1;
              uVar8 = (int)uVar5 >> ((byte)iVar4 & 0x1f);
              if (iVar4 < 0) {
                uVar5 = (uint)*param_4;
                iVar4 = 7;
                param_4 = param_4 + 1;
                uVar8 = (int)uVar5 >> 7;
              }
              *puVar7 = *(undefined *)((int)&unk_F00FA068 + (uVar8 & 1));
              puVar7 = puVar7 + 1;
              uVar9 = uVar9 - 1;
            }
            iVar1 = iVar10 + -1;
            puVar7 = puVar7 + (iVar3 - uVar11);
            uVar9 = uVar11;
            iVar10 = iVar10 + -1;
          } while (-1 < iVar1);
          iVar4 = 0;
        }
      }
      break;
    case :
      iVar3 = *(int *)(iVar10 + 0x38);
      div(iVar3,*(undefined4 *)(iVar10 + 0x34));
      if (*(int *)(iVar10 + 0x30) == 0x18) {
        umul(uVar5,*(undefined4 *)(iVar10 + 0x38));
        iVar4 = *(int *)(iVar10 + 0x18);
        umul(uVar9,*(undefined4 *)(iVar10 + 0x34));
        puVar6 = (undefined4 *)(iVar4 + uVar5 + uVar9);
        iVar4 = 0;
        iVar10 = uVar8 - 1;
        uVar5 = 0;
        uVar9 = uVar11;
        if (-1 < iVar10) {
          do {
            while (-1 < (int)(uVar9 - 1)) {
              iVar4 = iVar4 + -2;
              uVar8 = (int)uVar5 >> ((byte)iVar4 & 0x1f);
              if (iVar4 < 0) {
                uVar5 = (uint)*param_4;
                iVar4 = 6;
                param_4 = param_4 + 1;
                uVar8 = (int)uVar5 >> 6;
              }
              *puVar6 = *(undefined4 *)(unk_F00FA06C + (uVar8 & 3) * 4);
              puVar6 = puVar6 + 1;
              uVar9 = uVar9 - 1;
            }
            iVar1 = iVar10 + -1;
            puVar6 = puVar6 + (iVar3 - uVar11);
            uVar9 = uVar11;
            iVar10 = iVar10 + -1;
          } while (-1 < iVar1);
          iVar4 = 0;
        }
      }
      else {
        umul(uVar5,*(undefined4 *)(iVar10 + 0x38));
        iVar4 = *(int *)(iVar10 + 0x14);
        umul(uVar9,*(undefined4 *)(iVar10 + 0x34));
        puVar7 = (undefined *)(iVar4 + uVar5 + uVar9);
        iVar4 = 0;
        iVar10 = uVar8 - 1;
        uVar5 = 0;
        uVar9 = uVar11;
        if (-1 < iVar10) {
          do {
            while (-1 < (int)(uVar9 - 1)) {
              iVar4 = iVar4 + -2;
              uVar8 = (int)uVar5 >> ((byte)iVar4 & 0x1f);
              if (iVar4 < 0) {
                uVar5 = (uint)*param_4;
                iVar4 = 6;
                param_4 = param_4 + 1;
                uVar8 = (int)uVar5 >> 6;
              }
              *puVar7 = unk_F00FA080[uVar8 & 3];
              puVar7 = puVar7 + 1;
              uVar9 = uVar9 - 1;
            }
            iVar1 = iVar10 + -1;
            puVar7 = puVar7 + (iVar3 - uVar11);
            uVar9 = uVar11;
            iVar10 = iVar10 + -1;
          } while (-1 < iVar1);
          iVar4 = 0;
        }
      }
      break;
    case :
    case :
    case :
      iVar4 = -0x2c7;
    }
  }
  else {
    iVar4 = -0x2c0;
  }
  return (qword)CONCAT24(wVar2,iVar4);
}

