
/* WARNING: Removing unreachable block (ram,0xf008bca0) */
/* WARNING: Removing unreachable block (ram,0xf008bbdc) */
/* WARNING: Removing unreachable block (ram,0xf008bbb4) */
/* WARNING: Removing unreachable block (ram,0xf008bb88) */
/* WARNING: Removing unreachable block (ram,0xf008bba4) */
/* WARNING: Removing unreachable block (ram,0xf008bbd0) */
/* WARNING: Removing unreachable block (ram,0xf008bc68) */
/* WARNING: Removing unreachable block (ram,0xf008bcb4) */
/* WARNING: Removing unreachable block (ram,0xf008bb54) */

undefined8 _mach_swapon(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l3;
  int iVar5;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar6;
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
  iVar4 = param_1;
  _suser();
  if (iVar4 == 0) {
    puVar6 = (undefined *)0xd;
    goto locret_F008BCBC;
  }
  puVar3 = (undefined *)((int)register0x00000038 + -0x18);
  *(undefined *)(dword_F0133DDC + 0x38) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  _pn_get(param_1,0,puVar3);
  puVar6 = (undefined *)0x16;
  if (param_1 != 0) goto locret_F008BCBC;
  iVar5 = *(int *)((int)register0x00000038 + -0x10) + 1;
  iVar4 = iVar5;
  _kalloc();
  _strncpy();
  *(undefined *)(iVar5 + iVar4 + -1) = 0;
  puVar6 = puVar3;
  _lookuppn(puVar3,1,0,(undefined *)((int)register0x00000038 + -0x1c));
  _pn_free(puVar3);
  iVar1 = *(int *)((int)register0x00000038 + -0x1c);
  if (puVar6 == (undefined *)0x0) {
    puVar6 = (undefined *)0x16;
    if (*(int *)(*(int *)((int)register0x00000038 + -0x1c) + 0x28) == 1) {
      *(undefined4 **)((int)register0x00000038 + -0x20) = dword_F0130F64;
      if ((undefined4 **)dword_F0130F64 != &dword_F0130F64) {
        do {
          puVar2 = *(undefined4 **)((int)register0x00000038 + -0x20);
          if (puVar2[2] == *(int *)((int)register0x00000038 + -0x1c)) goto loc_F008BC4C;
          puVar2 = (undefined4 *)*puVar2;
          *(undefined4 **)((int)register0x00000038 + -0x20) = puVar2;
        } while ((undefined4 **)puVar2 != &dword_F0130F64);
      }
      puVar2 = *(undefined4 **)((int)register0x00000038 + -0x20);
loc_F008BC4C:
      puVar6 = (undefined *)0x10;
      if ((undefined4 **)puVar2 == &dword_F0130F64) {
        puVar6 = (undefined *)((int)register0x00000038 + -0x20);
        _vnode_pager_file_init
                  (puVar6,*(undefined4 *)((int)register0x00000038 + -0x1c),param_3,param_4);
        iVar1 = *(int *)((int)register0x00000038 + -0x1c);
        if (puVar6 != (undefined *)0x0) goto loc_F008BC94;
        iVar1 = *(int *)((int)register0x00000038 + -0x20);
        *(uint *)(iVar1 + 0x2c) = param_2 & 1;
        *(int *)(iVar1 + 0x28) = iVar4;
        iVar4 = 0;
      }
    }
    iVar1 = *(int *)((int)register0x00000038 + -0x1c);
  }
loc_F008BC94:
  if (iVar1 != 0) {
    _vn_rele();
  }
  if (iVar4 != 0) {
    _kfree(iVar4,iVar5);
  }
locret_F008BCBC:
  return CONCAT44(param_2,puVar6);
}

