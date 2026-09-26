
/* WARNING: Removing unreachable block (ram,0xf006b514) */
/* WARNING: Removing unreachable block (ram,0xf006b430) */
/* WARNING: Removing unreachable block (ram,0xf006b3f8) */
/* WARNING: Removing unreachable block (ram,0xf006b4e4) */
/* WARNING: Removing unreachable block (ram,0xf006b5f0) */
/* WARNING: Removing unreachable block (ram,0xf006b3e4) */

undefined8
sub_F006B3CC(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  _lookupname(param_1,1,1,0,(undefined *)((int)register0x00000038 + -0x44));
  iVar4 = 4;
  if (param_1 != 0) goto locret_F006B5FC;
  iVar4 = *(int *)((int)register0x00000038 + -0x44);
  _check_exec_access();
  iVar2 = 0;
  if (iVar4 == 0) {
    _vn_rdwr(0,*(undefined4 *)((int)register0x00000038 + -0x44),
             (undefined *)((int)register0x00000038 + -0x40),0x1c,0,1,1,0);
    if (iVar2 == 0) {
      uVar3 = *(uint *)((int)register0x00000038 + -0x40);
      if (uVar3 == 0xfeedface) {
        bVar1 = false;
      }
      else {
        if ((uVar3 != 0xcafebabe) &&
           (*(undefined4 *)((int)register0x00000038 + -0x60) = 0xcafebabe,
           uVar3 != ((uint)*(byte *)((int)register0x00000038 + -0x5d) << 0x18 |
                     (uint)*(byte *)((int)register0x00000038 + -0x5e) << 0x10 |
                     (uint)*(byte *)((int)register0x00000038 + -0x5f) << 8 |
                    (uint)*(byte *)((int)register0x00000038 + -0x60)))) {
          iVar4 = 2;
          goto loc_F006B5F0;
        }
        bVar1 = true;
      }
      iVar4 = *(int *)((int)register0x00000038 + -0x44);
      if (!bVar1) {
        *param_2 = *(undefined4 *)((int)register0x00000038 + -0x40);
        param_2[1] = *(undefined4 *)((int)register0x00000038 + -0x3c);
        param_2[2] = *(undefined4 *)((int)register0x00000038 + -0x38);
        param_2[3] = *(undefined4 *)((int)register0x00000038 + -0x34);
        param_2[4] = *(undefined4 *)((int)register0x00000038 + -0x30);
        param_2[5] = *(undefined4 *)((int)register0x00000038 + -0x2c);
        param_2[6] = *(undefined4 *)((int)register0x00000038 + -0x28);
        *param_3 = 0;
        *param_4 = *(undefined4 *)(**(int **)((int)register0x00000038 + -0x44) + 0x14);
        iVar4 = 0;
        *param_5 = *(undefined4 *)((int)register0x00000038 + -0x44);
        goto locret_F006B5FC;
      }
      _fatfile_getarch(iVar4,(undefined *)((int)register0x00000038 + -0x40),
                       (undefined *)((int)register0x00000038 + -0x20));
      iVar2 = 0;
      if (iVar4 == 0) {
        _vn_rdwr(0,*(undefined4 *)((int)register0x00000038 + -0x44),
                 (undefined *)((int)register0x00000038 + -0x40),0x1c,
                 *(undefined4 *)((int)register0x00000038 + -0x18),1,1,0);
        iVar4 = 4;
        if ((iVar2 == 0) && (iVar4 = 2, *(int *)((int)register0x00000038 + -0x40) == -0x1120532)) {
          *param_2 = 0xfeedface;
          param_2[1] = *(undefined4 *)((int)register0x00000038 + -0x3c);
          param_2[2] = *(undefined4 *)((int)register0x00000038 + -0x38);
          param_2[3] = *(undefined4 *)((int)register0x00000038 + -0x34);
          param_2[4] = *(undefined4 *)((int)register0x00000038 + -0x30);
          param_2[5] = *(undefined4 *)((int)register0x00000038 + -0x2c);
          param_2[6] = *(undefined4 *)((int)register0x00000038 + -0x28);
          *param_3 = *(undefined4 *)((int)register0x00000038 + -0x18);
          *param_4 = *(undefined4 *)((int)register0x00000038 + -0x14);
          iVar4 = 0;
          *param_5 = *(undefined4 *)((int)register0x00000038 + -0x44);
          goto locret_F006B5FC;
        }
      }
    }
    else {
      iVar4 = 4;
    }
  }
  else {
    iVar4 = 6;
  }
loc_F006B5F0:
  _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x44));
locret_F006B5FC:
  return CONCAT44(param_2,iVar4);
}
