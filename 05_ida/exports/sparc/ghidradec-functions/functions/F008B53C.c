
/* WARNING: Removing unreachable block (ram,0xf008b5d8) */
/* WARNING: Removing unreachable block (ram,0xf008b5c0) */
/* WARNING: Removing unreachable block (ram,0xf008b5c8) */
/* WARNING: Removing unreachable block (ram,0xf008b5e4) */
/* WARNING: Removing unreachable block (ram,0xf008b5a8) */

undefined8 _vnode_pager_setup(undefined4 *param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  if (param_2 == 0) {
    piVar1 = (int *)*param_1;
  }
  else {
    *(word *)(param_1 + 1) = *(word *)(param_1 + 1) | 2;
    piVar1 = (int *)*param_1;
  }
  if (*piVar1 == 0) {
    if ((undefined4 **)dword_F0130F64 != &dword_F0130F64) {
      puVar2 = (undefined4 *)dword_F0130F64[2];
      puVar4 = dword_F0130F64;
      while (puVar2 != param_1) {
        puVar4 = (undefined4 *)*puVar4;
        if ((undefined4 **)puVar4 == &dword_F0130F64) goto loc_F008B5A8;
        puVar2 = (undefined4 *)puVar4[2];
      }
      uVar5 = 0;
      goto locret_F008B5F4;
    }
loc_F008B5A8:
    _vnode_pager_create(param_1);
    if (param_3 != 0) {
      _vm_object_lookup(*(undefined4 *)*param_1);
      _vm_object_cache_object();
    }
  }
  uVar5 = _vstruct_zone;
  uVar3 = _vstruct_zone;
  _zalloc(_vstruct_zone);
  _zfree(uVar5,uVar3);
  uVar5 = *(undefined4 *)*param_1;
locret_F008B5F4:
  return CONCAT44(param_2,uVar5);
}
