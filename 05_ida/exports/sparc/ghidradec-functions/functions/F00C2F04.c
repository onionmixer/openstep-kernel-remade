
/* WARNING: Removing unreachable block (ram,0xf00c2fe0) */
/* WARNING: Removing unreachable block (ram,0xf00c3098) */
/* WARNING: Removing unreachable block (ram,0xf00c2fd0) */

undefined8 sub_F00C2F04(char *param_1,undefined4 *param_2,uint *param_3)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  undefined4 unaff_l3;
  int iVar11;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar12;
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
  bVar2 = false;
  iVar11 = 0;
  cVar1 = *param_1;
  pcVar8 = param_1;
  while( true ) {
    iVar7 = (int)cVar1;
    pcVar9 = pcVar8 + 1;
    if (((iVar7 == 0x20) || ((iVar7 - 9U & 0xff) < 2)) || (bVar12 = false, iVar7 == 10)) {
      bVar12 = true;
    }
    if (!bVar12) break;
    cVar1 = *pcVar9;
    pcVar8 = pcVar9;
  }
  if (iVar7 == 0x2d) {
    cVar1 = *pcVar9;
    bVar2 = true;
  }
  else {
    if (iVar7 != 0x2b) goto loc_F00C2F84;
    cVar1 = *pcVar9;
  }
  iVar7 = (int)cVar1;
  pcVar9 = pcVar8 + 2;
loc_F00C2F84:
  bVar12 = true;
  if ((iVar7 == 0x30) && ((*pcVar9 == 'x' || (bVar12 = true, *pcVar9 == 'X')))) {
    iVar7 = (int)pcVar9[1];
    iVar11 = 0x10;
    pcVar9 = pcVar9 + 2;
    bVar12 = false;
  }
  if ((bVar12) && (iVar11 = 10, iVar7 == 0x30)) {
    iVar11 = 8;
  }
  uVar3 = 0xffffffff;
  .udiv(0xffffffff,iVar11);
  iVar4 = -1;
  .urem(0xffffffff,iVar11);
  uVar6 = 0;
  iVar10 = 0;
  do {
    uVar5 = iVar7 - 0x30;
    if (9 < (uVar5 & 0xff)) {
      if (((iVar7 - 0x41U & 0xff) < 0x1a) || (bVar12 = false, (iVar7 - 0x61U & 0xff) < 0x1a)) {
        bVar12 = true;
      }
      if (!bVar12) {
loc_F00C30B4:
        if (iVar10 < 0) {
          uVar6 = 0xffffffff;
        }
        else if (bVar2) {
          uVar6 = -uVar6;
        }
        if (param_2 != (undefined4 *)0x0) {
          if (iVar10 != 0) {
            param_1 = pcVar9 + -1;
          }
          *param_2 = param_1;
        }
        if (param_3 != (uint *)0x0) {
          *param_3 = uVar6;
        }
        return CONCAT44(param_2,(uint)(0 < iVar10));
      }
      uVar5 = iVar7 - 0x37;
      if (0x19 < (iVar7 - 0x41U & 0xff)) {
        uVar5 = iVar7 - 0x57;
      }
    }
    if (iVar11 <= (int)uVar5) goto loc_F00C30B4;
    if (iVar10 < 0) {
loc_F00C308C:
      iVar10 = -1;
    }
    else if (uVar3 < uVar6) {
      iVar10 = -1;
    }
    else {
      iVar10 = 1;
      if ((uVar6 == uVar3) && (iVar4 < (int)uVar5)) goto loc_F00C308C;
      .umul(uVar6,iVar11);
      uVar6 = uVar6 + uVar5;
    }
    iVar7 = (int)*pcVar9;
    pcVar9 = pcVar9 + 1;
  } while( true );
}
