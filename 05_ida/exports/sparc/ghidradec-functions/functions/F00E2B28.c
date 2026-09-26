
/* WARNING: Removing unreachable block (ram,0xf00e2c58) */
/* WARNING: Removing unreachable block (ram,0xf00e2d10) */
/* WARNING: Removing unreachable block (ram,0xf00e2c48) */

undefined8 _strtoul(char *param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar10;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar11;
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
  cVar1 = *param_1;
  pcVar7 = param_1;
  while( true ) {
    iVar6 = (int)cVar1;
    pcVar8 = pcVar7 + 1;
    if (((iVar6 == 0x20) || ((iVar6 - 9U & 0xff) < 2)) || (bVar11 = false, iVar6 == 10)) {
      bVar11 = true;
    }
    if (!bVar11) break;
    cVar1 = *pcVar8;
    pcVar7 = pcVar8;
  }
  if (iVar6 == 0x2d) {
    cVar1 = *pcVar8;
    bVar2 = true;
loc_F00E2BA0:
    iVar6 = (int)cVar1;
    pcVar8 = pcVar7 + 2;
  }
  else if (iVar6 == 0x2b) {
    cVar1 = *pcVar8;
    goto loc_F00E2BA0;
  }
  if (((param_3 == 0) || (param_3 == 0x10)) &&
     ((iVar6 == 0x30 && ((*pcVar8 == 'x' || (*pcVar8 == 'X')))))) {
    cVar1 = pcVar8[1];
    param_3 = 0x10;
  }
  else {
    if (((param_3 != 0) && (bVar11 = param_3 == 0, param_3 != 2)) ||
       ((bVar11 = param_3 == 0, iVar6 != 0x30 ||
        ((*pcVar8 != 'b' && (bVar11 = param_3 == 0, *pcVar8 != 'B')))))) goto loc_F00E2C2C;
    cVar1 = pcVar8[1];
    param_3 = 2;
  }
  iVar6 = (int)cVar1;
  pcVar8 = pcVar8 + 2;
  bVar11 = param_3 == 0;
loc_F00E2C2C:
  if ((bVar11) && (param_3 = 10, iVar6 == 0x30)) {
    param_3 = 8;
  }
  uVar3 = 0xffffffff;
  .udiv(0xffffffff,param_3);
  iVar4 = -1;
  .urem(0xffffffff,param_3);
  uVar10 = 0;
  iVar9 = 0;
  do {
    uVar5 = iVar6 - 0x30;
    if (9 < (uVar5 & 0xff)) {
      if (((iVar6 - 0x41U & 0xff) < 0x1a) || (bVar11 = false, (iVar6 - 0x61U & 0xff) < 0x1a)) {
        bVar11 = true;
      }
      if (!bVar11) {
loc_F00E2D2C:
        if (iVar9 < 0) {
          uVar10 = 0xffffffff;
        }
        else if (bVar2) {
          uVar10 = -uVar10;
        }
        if (param_2 != (undefined4 *)0x0) {
          if (iVar9 != 0) {
            param_1 = pcVar8 + -1;
          }
          *param_2 = param_1;
        }
        return CONCAT44(param_2,uVar10);
      }
      uVar5 = iVar6 - 0x37;
      if (0x19 < (iVar6 - 0x41U & 0xff)) {
        uVar5 = iVar6 - 0x57;
      }
    }
    if (param_3 <= (int)uVar5) goto loc_F00E2D2C;
    if (iVar9 < 0) {
loc_F00E2D04:
      iVar9 = -1;
    }
    else if (uVar3 < uVar10) {
      iVar9 = -1;
    }
    else {
      iVar9 = 1;
      if ((uVar10 == uVar3) && (iVar4 < (int)uVar5)) goto loc_F00E2D04;
      .umul(uVar10,param_3);
      uVar10 = uVar10 + uVar5;
    }
    iVar6 = (int)*pcVar8;
    pcVar8 = pcVar8 + 1;
  } while( true );
}
