
/* WARNING: Removing unreachable block (ram,0xf002cff8) */
/* WARNING: Removing unreachable block (ram,0xf002cf80) */
/* WARNING: Removing unreachable block (ram,0xf002cf04) */
/* WARNING: Removing unreachable block (ram,0xf002cee8) */
/* WARNING: Removing unreachable block (ram,0xf002cf18) */
/* WARNING: Removing unreachable block (ram,0xf002cfac) */
/* WARNING: Removing unreachable block (ram,0xf002d08c) */
/* WARNING: Removing unreachable block (ram,0xf002ce80) */

undefined8 _rtredirect(word *param_1,undefined2 *param_2,uint param_3,int param_4)

{
  undefined2 *puVar1;
  undefined *puVar2;
  undefined2 uVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
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
  bool bVar5;
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
  puVar1 = param_2;
  _ifa_ifwithnet();
  if (puVar1 == (undefined2 *)0x0) {
    _rtstat = _rtstat + 1;
    goto locret_F002D094;
  }
  *(word *)((int)register0x00000038 + -0x1c) = *param_1;
  *(word *)((int)register0x00000038 + -0x1a) = param_1[1];
  *(word *)((int)register0x00000038 + -0x18) = param_1[2];
  *(word *)((int)register0x00000038 + -0x16) = param_1[3];
  *(word *)((int)register0x00000038 + -0x14) = param_1[4];
  *(word *)((int)register0x00000038 + -0x12) = param_1[5];
  *(word *)((int)register0x00000038 + -0x10) = param_1[6];
  *(word *)((int)register0x00000038 + -0xe) = param_1[7];
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  _rtalloc((undefined *)((int)register0x00000038 + -0x20));
  iVar4 = *(int *)((int)register0x00000038 + -0x20);
  if (((iVar4 == 0) || (_bcmp(param_4,iVar4 + 0x14,0x10), param_4 == 0)) &&
     (puVar1 = param_2, _ifa_ifwithaddr(), puVar1 == (undefined2 *)0x0)) {
    bVar5 = iVar4 == 0;
    if (!bVar5) {
      puVar2 = _wildcard;
      (**(code **)(DAT_f010c154 + (uint)*param_1 * 8))(_wildcard,iVar4 + 4);
      bVar5 = iVar4 == 0;
      if (puVar2 != (undefined *)0x0) {
        _rtfree(iVar4);
        iVar4 = 0;
        bVar5 = true;
      }
    }
    if (bVar5) {
      _rtinit(param_1,param_2,0x8030720a,param_3 & 4 | 0x12);
      DAT_f0135282._0_2_ = DAT_f0135282._0_2_ + 1;
      goto locret_F002D094;
    }
    if ((*(word *)(iVar4 + 0x24) & 2) == 0) {
      _rtstat = _rtstat + 1;
    }
    else {
      if ((*(word *)(iVar4 + 0x24) & 4) == 0) {
        if ((param_3 & 4) != 0) {
          _rtinit(param_1,param_2,0x8030720a,param_3 | 0x10);
          DAT_f0135282._0_2_ = DAT_f0135282._0_2_ + 1;
          goto loc_F002D08C;
        }
        uVar3 = *param_2;
      }
      else {
        uVar3 = *param_2;
      }
      *(undefined2 *)(iVar4 + 0x14) = uVar3;
      *(undefined2 *)(iVar4 + 0x16) = param_2[1];
      *(undefined2 *)(iVar4 + 0x18) = param_2[2];
      *(undefined2 *)(iVar4 + 0x1a) = param_2[3];
      *(undefined2 *)(iVar4 + 0x1c) = param_2[4];
      *(undefined2 *)(iVar4 + 0x1e) = param_2[5];
      *(undefined2 *)(iVar4 + 0x20) = param_2[6];
      *(undefined2 *)(iVar4 + 0x22) = param_2[7];
      *(word *)(iVar4 + 0x24) = *(word *)(iVar4 + 0x24) | 0x20;
      DAT_f0135282._2_2_ = DAT_f0135282._2_2_ + 1;
    }
  }
  else {
    _rtstat = _rtstat + 1;
    if (iVar4 == 0) goto locret_F002D094;
  }
loc_F002D08C:
  _rtfree(iVar4);
locret_F002D094:
  return CONCAT44(param_2,param_1);
}

