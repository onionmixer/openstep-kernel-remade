
/* WARNING: Removing unreachable block (ram,0xf003a850) */
/* WARNING: Removing unreachable block (ram,0xf003a70c) */
/* WARNING: Removing unreachable block (ram,0xf003a6ec) */
/* WARNING: Removing unreachable block (ram,0xf003a7c4) */
/* WARNING: Removing unreachable block (ram,0xf003a85c) */
/* WARNING: Removing unreachable block (ram,0xf003a6b0) */

undefined8 sub_F003A6A4(undefined *param_1,int *param_2,uint *param_3,int param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined *puVar3;
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
  puVar3 = (undefined *)0x0;
  puVar1 = param_1;
  sub_F003C020(param_1,param_3);
  if (puVar1 == (undefined *)0x0) {
    *param_2 = 0x46;
    goto locret_F003A864;
  }
  if ((*param_3 & 1) == 0) {
    if ((*param_3 & 2) != 0) {
      iVar4 = *(int *)(param_4 + 0x1c) + 0x10;
      sub_F003C0BC(iVar4,param_3 + 6);
      if (iVar4 == 0) {
        iVar4 = 0x1e;
        goto loc_F003A858;
      }
    }
    sub_F003BFCC(param_1 + 0x20,(undefined *)((int)register0x00000038 + -0x48));
    if (*(int *)((int)register0x00000038 + -0x20) == -1) {
loc_F003A74C:
      iVar4 = *(int *)(puVar1 + 0x28);
    }
    else {
      if (*(int *)((int)register0x00000038 + -0x1c) == 1000000) {
        *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
        *(undefined4 *)((int)register0x00000038 + -0x1c) = 0xffffffff;
        *(undefined4 *)((int)register0x00000038 + -0x28) = 0xffffffff;
        *(undefined4 *)((int)register0x00000038 + -0x24) = 0xffffffff;
        goto loc_F003A74C;
      }
      iVar4 = *(int *)(puVar1 + 0x28);
    }
    bVar5 = true;
    if (iVar4 == 1) {
      param_1 = DAT_f0133c00;
      if (*(int *)((int)register0x00000038 + -0x30) != -1) {
        iVar4 = *(int *)(puVar1 + 0x1c);
        uVar2 = *(undefined4 *)(_active_u + 0x1c);
        *(undefined *)((int)register0x00000038 + -0x89) = 0;
        puVar3 = puVar1;
        (**(code **)(iVar4 + 0x14))(puVar1,(undefined *)((int)register0x00000038 + -0x88),uVar2);
        bVar5 = puVar3 == (undefined *)0x0;
        if (!bVar5) goto loc_F003A7EC;
        if (*(uint *)((int)register0x00000038 + -0x70) < *(uint *)((int)register0x00000038 + -0x30))
        {
          puVar3 = (undefined *)0x1;
          _vn_rdwr(1,puVar1,(undefined *)((int)register0x00000038 + -0x89),1,
                   *(uint *)((int)register0x00000038 + -0x30) - 1,1,4,0);
          (**(code **)(*(int *)(puVar1 + 0x1c) + 0x48))(puVar1,*(undefined4 *)(_active_u + 0x1c));
        }
      }
      bVar5 = puVar3 == (undefined *)0x0;
    }
loc_F003A7EC:
    if (bVar5) {
      param_1 = (undefined *)((int)register0x00000038 + -0x48);
      puVar3 = puVar1;
      (**(code **)(*(int *)(puVar1 + 0x1c) + 0x18))
                (puVar1,param_1,*(undefined4 *)(_active_u + 0x1c));
      if (puVar3 == (undefined *)0x0) {
        puVar3 = puVar1;
        (**(code **)(*(int *)(puVar1 + 0x1c) + 0x14))
                  (puVar1,param_1,*(undefined4 *)(_active_u + 0x1c));
        if (puVar3 == (undefined *)0x0) {
          _vattr_to_nattr(param_1,param_2 + 1);
          iVar4 = 0;
          goto loc_F003A858;
        }
        *param_2 = (int)puVar3;
      }
      else {
        *param_2 = (int)puVar3;
      }
    }
    else {
      *param_2 = (int)puVar3;
    }
  }
  else {
    iVar4 = 0x1e;
loc_F003A858:
    *param_2 = iVar4;
  }
  _vn_rele(puVar1);
locret_F003A864:
  return CONCAT44(param_2,param_1);
}
