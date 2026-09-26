
/* WARNING: Removing unreachable block (ram,0xf00a3288) */
/* WARNING: Removing unreachable block (ram,0xf00a320c) */
/* WARNING: Removing unreachable block (ram,0xf00a324c) */
/* WARNING: Removing unreachable block (ram,0xf00a3290) */
/* WARNING: Removing unreachable block (ram,0xf00a3234) */

undefined8 _garbage_collect(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 uVar5;
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
  bool bVar6;
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
  uVar5 = 0;
  dword_F013DF70 = dword_F013DF70 + 1;
  iVar3 = param_1[2];
  bVar6 = iVar3 == 0;
  if (!bVar6) {
    iVar2 = *(int *)(iVar3 + 8);
    iVar4 = iVar3;
    while (bVar6 = iVar4 == 0, iVar2 == 0) {
      iVar4 = *(int *)(iVar4 + 0x14);
      if (iVar4 == 0) {
        bVar6 = true;
        break;
      }
      iVar2 = *(int *)(iVar4 + 8);
    }
  }
  if (bVar6) {
    if (iVar3 == 0) {
      iVar3 = *param_1;
    }
    else {
      iVar4 = *(int *)(iVar3 + 0x18);
      while( true ) {
        if (*(char *)(iVar4 + 0xd) == '\x01') {
          _del_any_pool(&_reg_free,iVar3);
          DAT_f013de9c = DAT_f013de9c + -1;
        }
        else if ((byte)(*(char *)(iVar4 + 0xd) - 2U) < 2) {
          _del_any_pool(&_seg_free,iVar3);
          DAT_f013de90._0_4_ = DAT_f013de90._0_4_ + -1;
        }
        _zfree(_pool_zone,iVar3);
        uVar5 = *(undefined4 *)(iVar3 + 0x18);
        iVar3 = *(int *)(iVar3 + 0x14);
        if (iVar3 == 0) break;
        iVar4 = *(int *)(iVar3 + 0x18);
      }
      iVar3 = *param_1;
    }
    *(int *)(iVar3 + 4) = param_1[1];
    uVar1 = _garbage_zone;
    *(int *)param_1[1] = *param_1;
    _zfree(uVar1);
    _kmem_free(uVar5);
  }
  return CONCAT44(param_2,param_1);
}
