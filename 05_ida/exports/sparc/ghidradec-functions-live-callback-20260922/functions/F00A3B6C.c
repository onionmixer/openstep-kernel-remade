
/* WARNING: Removing unreachable block (ram,0xf00a3ca4) */
/* WARNING: Removing unreachable block (ram,0xf00a3c64) */
/* WARNING: Removing unreachable block (ram,0xf00a3c90) */
/* WARNING: Removing unreachable block (ram,0xf00a3bfc) */

undefined8 _getval(char *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 uVar5;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  char *pcVar6;
  byte *pbVar7;
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
  uVar5 = 1;
  if (*param_1 != '=') {
    *param_2 = 1;
loc_F00A3CC0:
    uVar5 = 0;
    goto locret_F00A3CC4;
  }
  pcVar6 = param_1 + 1;
  iVar1 = (int)*pcVar6;
  uVar4 = 10;
  if (iVar1 == 0x2d) {
    uVar5 = 0xffffffff;
    pcVar6 = param_1 + 2;
    iVar1 = (int)*pcVar6;
  }
  iVar1 = iVar1 + -0x30;
  pbVar7 = (byte *)(pcVar6 + 1);
  if (iVar1 == 0) {
    iVar2 = (int)(char)*pbVar7;
    if (iVar2 < 0x30) {
loc_F00A3BFC:
      iVar2 = (int)(char)*pbVar7;
      _isargsep();
      if (iVar2 == 0) {
        uVar5 = 1;
        goto locret_F00A3CC4;
      }
    }
    else if (iVar2 < 0x38) {
      iVar1 = iVar2 + -0x30;
      pbVar7 = (byte *)(pcVar6 + 2);
      uVar4 = 8;
    }
    else if (iVar2 == 0x62) {
      uVar4 = 2;
      pbVar7 = (byte *)(pcVar6 + 2);
    }
    else {
      if (iVar2 != 0x78) goto loc_F00A3BFC;
      uVar4 = 0x10;
      pbVar7 = (byte *)(pcVar6 + 2);
    }
  }
  while( true ) {
    uVar3 = (uint)*pbVar7;
    pbVar7 = pbVar7 + 1;
    if ((uVar3 < 0x30) || (0x39 < uVar3)) {
      if ((uVar3 - 0x61 & 0xff) < 6) {
        uVar3 = uVar3 - 0x57;
      }
      else {
        if (5 < (uVar3 - 0x41 & 0xff)) {
          _isargsep();
          if (uVar3 != 0) {
            umul(iVar1,uVar5);
            *param_2 = iVar1;
            goto loc_F00A3CC0;
          }
          uVar5 = 1;
          goto locret_F00A3CC4;
        }
        uVar3 = uVar3 - 0x37;
      }
    }
    else {
      uVar3 = uVar3 - 0x30;
    }
    if (uVar4 <= (uVar3 & 0xff)) break;
    umul(iVar1,uVar4);
    iVar1 = iVar1 + (uVar3 & 0xff);
  }
  uVar5 = 1;
locret_F00A3CC4:
  return CONCAT44(param_2,uVar5);
}

