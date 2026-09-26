
/* WARNING: Removing unreachable block (ram,0xf00e57d8) */
/* WARNING: Removing unreachable block (ram,0xf00e577c) */
/* WARNING: Removing unreachable block (ram,0xf00e57f0) */
/* WARNING: Removing unreachable block (ram,0xf00e5764) */

undefined8 _sparcfbFillRect(uint param_1,word *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  uint *puVar5;
  undefined4 unaff_l1;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  uint uVar9;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  word *pwVar10;
  undefined4 unaff_i1;
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
  iVar1 = param_1 * 0x44 + 8;
  iVar7 = _sparcfbs + iVar1;
  if ((param_1 < 0x10) && (*(int *)(_sparcfbs + iVar1) != 0)) {
    uVar6 = (uint)param_2[1];
    uVar9 = (uint)*param_2;
    uVar8 = (uint)param_2[2];
    param_2 = (word *)(uint)param_2[3];
    if (*(int *)(iVar7 + 0x34) == 1) {
      pwVar10 = (word *)0x0;
      if (param_2 != (word *)0x0) {
        do {
          uVar3 = uVar6;
          umul(uVar6,*(undefined4 *)(iVar7 + 0x38));
          iVar1 = *(int *)(iVar7 + 0x14);
          uVar2 = uVar9;
          umul(uVar9,*(undefined4 *)(iVar7 + 0x34));
          puVar4 = (undefined *)(iVar1 + uVar3 + uVar2);
          uVar3 = 0;
          if (uVar8 != 0) {
            do {
              *puVar4 = (char)param_3;
              uVar3 = uVar3 + 1;
              puVar4 = puVar4 + 1;
            } while (uVar3 < uVar8);
          }
          pwVar10 = (word *)((int)pwVar10 + 1);
          uVar6 = uVar6 + 1;
        } while (pwVar10 < param_2);
        pwVar10 = (word *)0x0;
      }
    }
    else {
      pwVar10 = (word *)0x0;
      if (*(int *)(iVar7 + 0x34) == 4) {
        if (param_2 == (word *)0x0) {
          pwVar10 = (word *)0x0;
        }
        else {
          do {
            uVar3 = uVar6;
            umul(uVar6,*(undefined4 *)(iVar7 + 0x38));
            iVar1 = *(int *)(iVar7 + 0x18);
            uVar2 = uVar9;
            umul(uVar9,*(undefined4 *)(iVar7 + 0x34));
            puVar5 = (uint *)(iVar1 + uVar3 + uVar2);
            uVar3 = 0;
            if (uVar8 != 0) {
              do {
                *puVar5 = param_3 << 0x18 | param_3;
                uVar3 = uVar3 + 1;
                puVar5 = puVar5 + 1;
              } while (uVar3 < uVar8);
            }
            pwVar10 = (word *)((int)pwVar10 + 1);
            uVar6 = uVar6 + 1;
          } while (pwVar10 < param_2);
          pwVar10 = (word *)0x0;
        }
      }
      else {
        pwVar10 = (word *)0xfffffd39;
      }
    }
  }
  else {
    pwVar10 = (word *)0xfffffd40;
  }
  return CONCAT44(param_2,pwVar10);
}

