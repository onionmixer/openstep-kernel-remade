
/* WARNING: Removing unreachable block (ram,0xf008b024) */
/* WARNING: Removing unreachable block (ram,0xf008afd4) */
/* WARNING: Removing unreachable block (ram,0xf008aff8) */
/* WARNING: Removing unreachable block (ram,0xf008b098) */
/* WARNING: Removing unreachable block (ram,0xf008af68) */

undefined8 _pagerfile_pager_create(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar5;
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
  puVar5 = _vstruct_zone;
  _zalloc_noblock();
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
    goto locret_F008B0A0;
  }
  uVar1 = (param_2 + _page_mask & ~_page_mask) >> ((byte)_page_shift & 0x1f);
  puVar5[4] = uVar1;
  if (uVar1 == 0) {
    puVar5[2] = 0;
loc_F008B064:
    *puVar5 = 0;
  }
  else {
    uVar2 = uVar1 * 4;
    if (0x40 < uVar2) {
      uVar2 = ((uVar1 - 1 >> 4) + 1) * 4;
    }
    _kalloc_noblock();
    puVar5[2] = uVar2;
    if (puVar5[2] == 0) {
      _zfree(_vstruct_zone,puVar5);
      puVar5 = (undefined4 *)0x0;
      goto locret_F008B0A0;
    }
    iVar3 = puVar5[4];
    if ((uint)(iVar3 * 4) < 0x41) {
      iVar4 = 0;
      if (0 < iVar3) {
        iVar3 = puVar5[2];
        while( true ) {
          *(undefined *)(iVar3 + iVar4 * 4) = 0;
          iVar4 = iVar4 + 1;
          if ((int)puVar5[4] <= iVar4) break;
          iVar3 = puVar5[2];
        }
        goto loc_F008B064;
      }
      *puVar5 = 0;
    }
    else {
      _bzero(puVar5[2],((iVar3 - 1U >> 4) + 1) * 4);
      *puVar5 = 0;
    }
  }
  *(undefined2 *)((int)puVar5 + 0xe) = 1;
  puVar5[5] = *(undefined4 *)(param_1 + 8);
  puVar5[1] = param_1;
  puVar5[3] = puVar5[3] | 0x80000000;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  _vnode_pager_vput(puVar5);
locret_F008B0A0:
  return CONCAT44(param_2,puVar5);
}
