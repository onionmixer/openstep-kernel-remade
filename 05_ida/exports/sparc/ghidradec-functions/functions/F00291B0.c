
/* WARNING: Removing unreachable block (ram,0xf0029300) */
/* WARNING: Removing unreachable block (ram,0xf00292d0) */
/* WARNING: Removing unreachable block (ram,0xf00292b0) */
/* WARNING: Removing unreachable block (ram,0xf0029240) */
/* WARNING: Removing unreachable block (ram,0xf00291e8) */
/* WARNING: Removing unreachable block (ram,0xf0029210) */
/* WARNING: Removing unreachable block (ram,0xf002927c) */
/* WARNING: Removing unreachable block (ram,0xf00292b8) */
/* WARNING: Removing unreachable block (ram,0xf00292e8) */
/* WARNING: Removing unreachable block (ram,0xf00291fc) */
/* WARNING: Removing unreachable block (ram,0xf00291cc) */

undefined8 _vn_rename(undefined *param_1,undefined *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined *puVar3;
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
  *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x34) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
  puVar2 = (undefined *)((int)register0x00000038 + -0x18);
  _pn_get(param_1,param_3,puVar2);
  puVar3 = param_2;
  if (param_1 == (undefined *)0x0) {
    puVar3 = (undefined *)((int)register0x00000038 + -0x28);
    _pn_get(param_2,param_3,puVar3);
    if (param_2 == (undefined *)0x0) {
      _lookuppn(puVar2,0,(undefined *)((int)register0x00000038 + -0x2c),
                (undefined *)((int)register0x00000038 + -0x30));
      if (puVar2 == (undefined *)0x0) {
        if (*(int *)((int)register0x00000038 + -0x30) == 0) {
          puVar2 = (undefined *)0x2;
        }
        else {
          puVar2 = puVar3;
          _lookuppn(puVar3,0,(undefined *)((int)register0x00000038 + -0x34),0);
          if (puVar2 == (undefined *)0x0) {
            puVar2 = (undefined *)0x12;
            if ((*(int *)(*(int *)((int)register0x00000038 + -0x30) + 0x24) ==
                 *(int *)(*(int *)((int)register0x00000038 + -0x34) + 0x24)) &&
               (puVar2 = (undefined *)0x1e,
               (*(uint *)(*(int *)(*(int *)((int)register0x00000038 + -0x30) + 0x24) + 0xc) & 1) ==
               0)) {
              _vnode_uncache(*(int *)((int)register0x00000038 + -0x34));
              puVar2 = *(undefined **)((int)register0x00000038 + -0x2c);
              (**(code **)(*(int *)(puVar2 + 0x1c) + 0x30))
                        (puVar2,*(undefined4 *)((int)register0x00000038 + -0x14),
                         *(undefined4 *)((int)register0x00000038 + -0x34),
                         *(undefined4 *)((int)register0x00000038 + -0x24),
                         *(undefined4 *)(_active_u + 0x1c));
            }
          }
        }
      }
      _pn_free((undefined *)((int)register0x00000038 + -0x18));
      _pn_free((undefined *)((int)register0x00000038 + -0x28));
      if (*(int *)((int)register0x00000038 + -0x30) == 0) {
        iVar1 = *(int *)((int)register0x00000038 + -0x2c);
      }
      else {
        _vn_rele();
        iVar1 = *(int *)((int)register0x00000038 + -0x2c);
      }
      if (iVar1 == 0) {
        iVar1 = *(int *)((int)register0x00000038 + -0x34);
      }
      else {
        _vn_rele();
        iVar1 = *(int *)((int)register0x00000038 + -0x34);
      }
      param_1 = puVar2;
      if (iVar1 != 0) {
        _vn_rele();
      }
    }
    else {
      _pn_free(puVar2);
      param_1 = param_2;
    }
  }
  return CONCAT44(puVar3,param_1);
}
