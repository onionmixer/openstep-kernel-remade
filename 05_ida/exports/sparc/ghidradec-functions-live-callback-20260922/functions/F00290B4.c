
/* WARNING: Removing unreachable block (ram,0xf0029188) */
/* WARNING: Removing unreachable block (ram,0xf002910c) */
/* WARNING: Removing unreachable block (ram,0xf00290f0) */
/* WARNING: Removing unreachable block (ram,0xf0029170) */
/* WARNING: Removing unreachable block (ram,0xf00291a0) */
/* WARNING: Removing unreachable block (ram,0xf00290d0) */

undefined8 _vn_link(undefined *param_1,undefined *param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined4 unaff_l0;
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
  *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  puVar3 = (undefined *)((int)register0x00000038 + -0x18);
  _pn_get(param_2,param_3,puVar3);
  if (param_2 == (undefined *)0x0) {
    _lookupname(param_1,param_3,1,0,(undefined *)((int)register0x00000038 + -0x1c));
    param_2 = param_1;
    if (param_1 == (undefined *)0x0) {
      param_2 = puVar3;
      _lookuppn(puVar3,1,(undefined *)((int)register0x00000038 + -0x20),0);
      puVar1 = *(undefined **)((int)register0x00000038 + -0x1c);
      if (param_2 == (undefined *)0x0) {
        iVar2 = *(int *)((int)register0x00000038 + -0x20);
        param_2 = (undefined *)0x12;
        if ((*(int *)(puVar1 + 0x24) == *(int *)(iVar2 + 0x24)) &&
           (param_2 = (undefined *)0x1e, (*(uint *)(*(int *)(puVar1 + 0x24) + 0xc) & 1) == 0)) {
          (**(code **)(*(int *)(iVar2 + 0x1c) + 0x2c))
                    (puVar1,iVar2,*(undefined4 *)((int)register0x00000038 + -0x14),
                     *(undefined4 *)(_active_u + 0x1c));
          param_2 = puVar1;
        }
      }
    }
    _pn_free((undefined *)((int)register0x00000038 + -0x18));
    if (*(int *)((int)register0x00000038 + -0x1c) == 0) {
      iVar2 = *(int *)((int)register0x00000038 + -0x20);
    }
    else {
      _vn_rele();
      iVar2 = *(int *)((int)register0x00000038 + -0x20);
    }
    if (iVar2 != 0) {
      _vn_rele();
    }
  }
  return CONCAT44(puVar3,param_2);
}

