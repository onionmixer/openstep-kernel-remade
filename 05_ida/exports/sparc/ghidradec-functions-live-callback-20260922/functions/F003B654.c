
/* WARNING: Removing unreachable block (ram,0xf003b7d0) */
/* WARNING: Removing unreachable block (ram,0xf003b7b0) */
/* WARNING: Removing unreachable block (ram,0xf003b730) */
/* WARNING: Removing unreachable block (ram,0xf003b698) */
/* WARNING: Removing unreachable block (ram,0xf003b6d4) */
/* WARNING: Removing unreachable block (ram,0xf003b7a0) */
/* WARNING: Removing unreachable block (ram,0xf003b7bc) */
/* WARNING: Removing unreachable block (ram,0xf003b7dc) */
/* WARNING: Removing unreachable block (ram,0xf003b684) */

undefined8 sub_F003B654(undefined4 *param_1,undefined4 *param_2,uint *param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  char *pcVar3;
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
  bool bVar4;
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
  pcVar3 = (char *)param_1[8];
  if ((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) {
    *param_2 = 0xd;
    goto locret_F003B7E4;
  }
  sub_F003BFCC(param_1 + 9,(undefined *)((int)register0x00000038 + -0x48));
  *(undefined4 *)((int)register0x00000038 + -0x48) = 2;
  puVar1 = param_1;
  sub_F003C020(param_1,param_3);
  if (puVar1 == (undefined4 *)0x0) {
    *param_2 = 0x46;
    goto locret_F003B7E4;
  }
  param_1 = (undefined4 *)0x1e;
  if ((*param_3 & 1) == 0) {
    if ((*param_3 & 2) != 0) {
      iVar2 = *(int *)(param_4 + 0x1c) + 0x10;
      sub_F003C0BC(iVar2,param_3 + 6);
      if (iVar2 == 0) {
        param_1 = (undefined4 *)0x1e;
        goto loc_F003B7D8;
      }
    }
    param_1 = puVar1;
    (**(code **)(puVar1[7] + 0x34))
              (puVar1,pcVar3,(undefined *)((int)register0x00000038 + -0x48),
               (undefined *)((int)register0x00000038 + -0x4c),*(undefined4 *)(_active_u + 0x1c));
    bVar4 = param_1 == (undefined4 *)0x0;
    if (param_1 == (undefined4 *)0x11) {
      iVar2 = param_4;
      _svckudp_dup();
      if (iVar2 != 0) {
        param_1 = puVar1;
        (**(code **)(puVar1[7] + 0x20))
                  (puVar1,pcVar3,(undefined *)((int)register0x00000038 + -0x4c),
                   *(undefined4 *)(_active_u + 0x1c),0,0);
        bVar4 = param_1 == (undefined4 *)0x0;
        if (!bVar4) goto loc_F003B794;
        param_1 = puVar1;
        (**(code **)(puVar1[7] + 0x14))
                  (puVar1,(undefined *)((int)register0x00000038 + -0x48),
                   *(undefined4 *)(_active_u + 0x1c));
      }
      bVar4 = param_1 == (undefined4 *)0x0;
    }
loc_F003B794:
    if (bVar4) {
      _vattr_to_nattr((undefined *)((int)register0x00000038 + -0x48),param_2 + 9);
      param_1 = param_2 + 1;
      _makefh(param_1,*(undefined4 *)((int)register0x00000038 + -0x4c),param_3);
      _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x4c));
    }
    if (param_1 == (undefined4 *)0x0) {
      _svckudp_dupsave(param_4);
      goto loc_F003B7D8;
    }
    *param_2 = param_1;
  }
  else {
loc_F003B7D8:
    *param_2 = param_1;
  }
  _vn_rele(puVar1);
locret_F003B7E4:
  return CONCAT44(param_2,param_1);
}

