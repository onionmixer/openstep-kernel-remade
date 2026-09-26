
/* WARNING: Removing unreachable block (ram,0xf00e2a08) */
/* WARNING: Removing unreachable block (ram,0xf00e2ac0) */
/* WARNING: Removing unreachable block (ram,0xf00e29f8) */

undefined8 _strtol(char *param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  undefined4 unaff_l3;
  uint uVar9;
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
  pcVar6 = param_1;
  while( true ) {
    iVar5 = (int)cVar1;
    pcVar7 = pcVar6 + 1;
    if (((iVar5 == 0x20) || ((iVar5 - 9U & 0xff) < 2)) || (bVar11 = false, iVar5 == 10)) {
      bVar11 = true;
    }
    if (!bVar11) break;
    cVar1 = *pcVar7;
    pcVar6 = pcVar7;
  }
  if (iVar5 == 0x2d) {
    cVar1 = *pcVar7;
    bVar2 = true;
loc_F00E293C:
    iVar5 = (int)cVar1;
    pcVar7 = pcVar6 + 2;
  }
  else if (iVar5 == 0x2b) {
    cVar1 = *pcVar7;
    goto loc_F00E293C;
  }
  if (((param_3 == 0) || (param_3 == 0x10)) &&
     ((iVar5 == 0x30 && ((*pcVar7 == 'x' || (*pcVar7 == 'X')))))) {
    cVar1 = pcVar7[1];
    param_3 = 0x10;
  }
  else {
    if (((param_3 != 0) && (bVar11 = param_3 == 0, param_3 != 2)) ||
       ((bVar11 = param_3 == 0, iVar5 != 0x30 ||
        ((*pcVar7 != 'b' && (bVar11 = param_3 == 0, *pcVar7 != 'B')))))) goto loc_F00E29C8;
    cVar1 = pcVar7[1];
    param_3 = 2;
  }
  iVar5 = (int)cVar1;
  pcVar7 = pcVar7 + 2;
  bVar11 = param_3 == 0;
loc_F00E29C8:
  if ((bVar11) && (param_3 = 10, iVar5 == 0x30)) {
    param_3 = 8;
  }
  uVar9 = 0x80000000;
  if (!bVar2) {
    uVar9 = 0x7fffffff;
  }
  uVar3 = uVar9;
  .urem(uVar9,param_3);
  .udiv(uVar9,param_3);
  uVar10 = 0;
  iVar8 = 0;
  do {
    uVar4 = iVar5 - 0x30;
    if (9 < (uVar4 & 0xff)) {
      if (((iVar5 - 0x41U & 0xff) < 0x1a) || (bVar11 = false, (iVar5 - 0x61U & 0xff) < 0x1a)) {
        bVar11 = true;
      }
      if (!bVar11) {
loc_F00E2ADC:
        if (iVar8 < 0) {
          uVar10 = 0x80000000;
          if (!bVar2) {
            uVar10 = 0x7fffffff;
          }
        }
        else if (bVar2) {
          uVar10 = -uVar10;
        }
        if (param_2 != (undefined4 *)0x0) {
          if (iVar8 != 0) {
            param_1 = pcVar7 + -1;
          }
          *param_2 = param_1;
        }
        return CONCAT44(param_2,uVar10);
      }
      uVar4 = iVar5 - 0x37;
      if (0x19 < (iVar5 - 0x41U & 0xff)) {
        uVar4 = iVar5 - 0x57;
      }
    }
    if (param_3 <= (int)uVar4) goto loc_F00E2ADC;
    if (iVar8 < 0) {
loc_F00E2AB4:
      iVar8 = -1;
    }
    else if (uVar9 < uVar10) {
      iVar8 = -1;
    }
    else {
      iVar8 = 1;
      if ((uVar10 == uVar9) && ((int)uVar3 < (int)uVar4)) goto loc_F00E2AB4;
      .umul(uVar10,param_3);
      uVar10 = uVar10 + uVar4;
    }
    iVar5 = (int)*pcVar7;
    pcVar7 = pcVar7 + 1;
  } while( true );
}
