
/* WARNING: Removing unreachable block (ram,0xf0028188) */
/* WARNING: Removing unreachable block (ram,0xf00281e8) */
/* WARNING: Removing unreachable block (ram,0xf002811c) */

undefined8 _access(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined uVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  undefined4 *puVar8;
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
  puVar8 = *(undefined4 **)(dword_F0133DDC + 0x24);
  uVar3 = *puVar8;
  _lookupname(uVar3,0,1,0,(undefined *)((int)register0x00000038 + -0xc));
  *(char *)(dword_F0133DDC + 0x38) = (char)uVar3;
  if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F002820C;
  iVar5 = *(int *)(_active_u + 0x1c);
  uVar1 = *(undefined2 *)(iVar5 + 2);
  uVar2 = *(undefined2 *)(iVar5 + 4);
  *(undefined2 *)(iVar5 + 2) = *(undefined2 *)(iVar5 + 6);
  *(undefined2 *)(*(int *)(_active_u + 0x1c) + 4) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 8);
  uVar6 = puVar8[1];
  if (uVar6 != 0) {
    uVar7 = (uVar6 & 4) << 6;
    if ((uVar6 & 2) == 0) {
loc_F00281A8:
      if ((puVar8[1] & 1) != 0) {
        uVar7 = uVar7 | 0x40;
      }
      iVar5 = *(int *)((int)register0x00000038 + -0xc);
      (**(code **)(*(int *)(iVar5 + 0x1c) + 0x1c))(iVar5,uVar7,*(undefined4 *)(_active_u + 0x1c));
      uVar4 = (undefined)iVar5;
    }
    else {
      iVar5 = *(int *)((int)register0x00000038 + -0xc);
      _isrofile();
      if (iVar5 == 0) {
        uVar7 = uVar7 | 0x80;
        goto loc_F00281A8;
      }
      uVar4 = 0x1e;
    }
    *(undefined *)(dword_F0133DDC + 0x38) = uVar4;
  }
  _vn_rele(*(undefined4 *)((int)register0x00000038 + -0xc));
  *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2) = uVar1;
  *(undefined2 *)(*(int *)(_active_u + 0x1c) + 4) = uVar2;
locret_F002820C:
  return CONCAT44(param_2,param_1);
}
