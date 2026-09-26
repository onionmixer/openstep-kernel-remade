
/* WARNING: Removing unreachable block (ram,0xf003b1c0) */
/* WARNING: Removing unreachable block (ram,0xf003b1a4) */
/* WARNING: Removing unreachable block (ram,0xf003b114) */
/* WARNING: Removing unreachable block (ram,0xf003b06c) */
/* WARNING: Removing unreachable block (ram,0xf003b030) */
/* WARNING: Removing unreachable block (ram,0xf003b098) */
/* WARNING: Removing unreachable block (ram,0xf003b160) */
/* WARNING: Removing unreachable block (ram,0xf003b1b4) */
/* WARNING: Removing unreachable block (ram,0xf003b1cc) */
/* WARNING: Removing unreachable block (ram,0xf003afa4) */

undefined8 sub_F003AF74(undefined4 *param_1,undefined4 *param_2,uint *param_3,int param_4)

{
  code *pcVar1;
  undefined4 *puVar2;
  word wVar4;
  int iVar3;
  undefined4 uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  char *pcVar6;
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
  pcVar6 = (char *)param_1[8];
  if ((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) {
    *param_2 = 0xd;
    goto locret_F003B1D4;
  }
  sub_F003BFCC(param_1 + 9,(undefined *)((int)register0x00000038 + -0x48));
  wVar4 = *(word *)((int)register0x00000038 + -0x44) & 0xf000;
  if (wVar4 == 0x2000) {
    iVar3 = *(int *)((int)register0x00000038 + -0x30);
    *(undefined4 *)((int)register0x00000038 + -0x48) = 4;
    if (iVar3 == -1) {
      *(undefined4 *)((int)register0x00000038 + -0x48) = 8;
    }
    else {
loc_F003B000:
      *(sword *)((int)register0x00000038 + -0x10) = (sword)iVar3;
    }
    *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
  }
  else {
    if (wVar4 == 0x6000) {
      iVar3 = *(int *)((int)register0x00000038 + -0x30);
      *(undefined4 *)((int)register0x00000038 + -0x48) = 3;
      goto loc_F003B000;
    }
    uVar5 = 1;
    if (wVar4 == 0xc000) {
      uVar5 = 6;
    }
    *(undefined4 *)((int)register0x00000038 + -0x48) = uVar5;
  }
  *(word *)((int)register0x00000038 + -0x44) = *(word *)((int)register0x00000038 + -0x44) & 0xfff;
  puVar2 = param_1;
  sub_F003C020(param_1,param_3);
  if (puVar2 == (undefined4 *)0x0) {
    *param_2 = 0x46;
    goto locret_F003B1D4;
  }
  param_1 = (undefined4 *)0x1e;
  if ((*param_3 & 1) == 0) {
    if ((*param_3 & 2) == 0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x30);
    }
    else {
      iVar3 = *(int *)(param_4 + 0x1c) + 0x10;
      sub_F003C0BC(iVar3,param_3 + 6);
      if (iVar3 == 0) {
        param_1 = (undefined4 *)0x1e;
        goto loc_F003B16C;
      }
      iVar3 = *(int *)((int)register0x00000038 + -0x30);
    }
    if ((iVar3 == 0) && (iVar3 = param_4, _svckudp_dup(), iVar3 != 0)) {
      uVar5 = *(undefined4 *)(_active_u + 0x1c);
      pcVar1 = *(code **)(puVar2[7] + 0x20);
    }
    else {
      param_1 = puVar2;
      (**(code **)(puVar2[7] + 0x24))
                (puVar2,pcVar6,(undefined *)((int)register0x00000038 + -0x48),0,0x80,
                 (undefined *)((int)register0x00000038 + -0x4c),*(undefined4 *)(_active_u + 0x1c));
      if ((param_1 == (undefined4 *)0x0) || (iVar3 = param_4, _svckudp_dup(), iVar3 == 0)) {
        if (param_1 == (undefined4 *)0x0) {
          _svckudp_dupsave(param_4);
        }
        goto loc_F003B16C;
      }
      uVar5 = *(undefined4 *)(_active_u + 0x1c);
      pcVar1 = *(code **)(puVar2[7] + 0x20);
    }
    param_1 = puVar2;
    (*pcVar1)(puVar2,pcVar6,(undefined *)((int)register0x00000038 + -0x4c),uVar5,0,0);
  }
loc_F003B16C:
  if (param_1 == (undefined4 *)0x0) {
    param_1 = *(undefined4 **)((int)register0x00000038 + -0x4c);
    (**(code **)(param_1[7] + 0x14))
              (param_1,(undefined *)((int)register0x00000038 + -0x48),
               *(undefined4 *)(_active_u + 0x1c));
    if (param_1 == (undefined4 *)0x0) {
      _vattr_to_nattr((undefined *)((int)register0x00000038 + -0x48),param_2 + 9);
      param_1 = param_2 + 1;
      _makefh(param_1,*(undefined4 *)((int)register0x00000038 + -0x4c),param_3);
    }
    _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x4c));
    *param_2 = param_1;
  }
  else {
    *param_2 = param_1;
  }
  _vn_rele(puVar2);
locret_F003B1D4:
  return CONCAT44(param_2,param_1);
}

