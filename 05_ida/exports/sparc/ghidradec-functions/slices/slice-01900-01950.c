/* GHIDRADEC_FUNCTION index=1900 start=0xf008ac74 */

/* WARNING: Removing unreachable block (ram,0xf008ac90) */

undefined8 _vnode_pager_vget(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
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
  do {
    do {
    } while (_vstruct_lock != 0);
    puVar1 = &_vstruct_lock;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  *(sword *)(param_1 + 0xe) = *(sword *)(param_1 + 0xe) + 1;
  _vstruct_lock = 0;
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x14));
}
/* GHIDRADEC_FUNCTION index=1901 start=0xf008acc4 */

/* WARNING: Removing unreachable block (ram,0xf008ada4) */
/* WARNING: Removing unreachable block (ram,0xf008ace8) */
/* WARNING: Removing unreachable block (ram,0xf008ae00) */
/* WARNING: Removing unreachable block (ram,0xf008acd0) */

undefined8 _vnode_pager_allocpage(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
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
  _lock_write(param_1 + 0x34);
  if (*(int *)(param_1 + 0x18) == 0) {
    _lock_done(param_1 + 0x34);
    iVar3 = -1;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x24);
    iVar3 = 0;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 7;
    }
    iVar1 = iVar1 >> 3;
    while( true ) {
      iVar2 = *(int *)(param_1 + 0x14) + 7;
      if (iVar2 < 0) {
        iVar2 = *(int *)(param_1 + 0x14) + 0xe;
      }
      if (iVar2 >> 3 <= iVar1) goto loc_F008AD90;
      if (*(char *)(*(int *)(param_1 + 0x10) + iVar1) != -1) break;
      iVar1 = iVar1 + 1;
    }
    iVar3 = 0;
    do {
      iVar2 = iVar3;
      if (iVar3 < 0) {
        iVar2 = iVar3 + 7;
      }
    } while ((((int)*(char *)(*(int *)(param_1 + 0x10) + iVar1 + (iVar2 >> 3)) >>
               ((char)iVar3 + (char)(iVar2 >> 3) * -8 & 0x1fU) & 1U) != 0) &&
            (iVar3 = iVar3 + 1, iVar3 < 8));
loc_F008AD90:
    iVar3 = iVar1 * 8 + iVar3;
    if (*(int *)(param_1 + 0x14) <= iVar3) {
      _panic(aVnodePagerAllo);
    }
    if (*(int *)(param_1 + 0x20) < iVar3) {
      *(int *)(param_1 + 0x20) = iVar3;
    }
    iVar1 = iVar3;
    if (iVar3 < 0) {
      iVar1 = iVar3 + 7;
    }
    iVar1 = iVar1 >> 3;
    *(byte *)(*(int *)(param_1 + 0x10) + iVar1) =
         *(byte *)(*(int *)(param_1 + 0x10) + iVar1) |
         (byte)(1 << ((char)iVar3 + (char)iVar1 * -8 & 0x1fU));
    *(int *)(param_1 + 0x24) = iVar3;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
    _lock_done(param_1 + 0x34);
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=1902 start=0xf008ae10 */

/* WARNING: Removing unreachable block (ram,0xf008ae70) */

undefined8 _vnode_pager_findpage(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 *puVar3;
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
  puVar3 = param_1;
  if ((param_1 == (undefined4 *)0x0) &&
     (param_1 = dword_F0130F64, puVar3 = dword_F0130F64,
     (undefined4 **)dword_F0130F64 == &dword_F0130F64)) {
    uVar2 = 5;
  }
  else {
    do {
      puVar1 = param_1;
      _vnode_pager_allocpage();
      if (puVar1 != (undefined4 *)0xffffffff) {
        uVar2 = 0;
        *(char *)param_2 = (char)param_1[0xc];
        *param_2 = *param_2 & 0xff000000 | (uint)puVar1 & 0xffffff;
        goto locret_F008AEA4;
      }
      puVar1 = dword_F0130F64;
      if ((undefined4 **)param_1 != &dword_F0130F64) {
        puVar1 = (undefined4 *)*param_1;
      }
      param_1 = puVar1;
    } while (puVar3 != puVar1);
    uVar2 = 5;
  }
locret_F008AEA4:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1903 start=0xf008af5c */

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
/* GHIDRADEC_FUNCTION index=1904 start=0xf008b4d0 */

/* WARNING: Removing unreachable block (ram,0xf008b4f0) */
/* WARNING: Removing unreachable block (ram,0xf008b52c) */
/* WARNING: Removing unreachable block (ram,0xf008b4dc) */

undefined8 _vnode_pager_create(undefined4 *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar1;
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
  puVar1 = _vstruct_zone;
  _zalloc();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    _bzero();
    *puVar1 = 0;
    *(undefined2 *)((int)puVar1 + 0xe) = 1;
    *(undefined4 **)*param_1 = puVar1;
    puVar1[5] = param_1;
    puVar1[3] = puVar1[3] & 0x7fffffff;
    *(sword *)((int)param_1 + 6) = *(sword *)((int)param_1 + 6) + 1;
    _vnode_pager_vput(puVar1);
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=1905 start=0xf008b53c */

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
/* GHIDRADEC_FUNCTION index=1906 start=0xf008b5fc */

/* WARNING: Removing unreachable block (ram,0xf008b640) */
/* WARNING: Removing unreachable block (ram,0xf008b6c0) */
/* WARNING: Removing unreachable block (ram,0xf008b608) */

undefined8 _vnode_pagein(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  int *piVar3;
  bool bVar4;
  undefined4 unaff_l3;
  int *piVar5;
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
  piVar5 = *(int **)(*(int *)(param_1 + 0x14) + 0x28);
  piVar3 = piVar5;
  _vnode_pager_vget();
  bVar4 = false;
  iVar2 = *(int *)(param_1 + 0x18) + *(int *)(*(int *)(param_1 + 0x14) + 0x2c);
  if (piVar5[3] < 0) {
    piVar1 = piVar5;
    sub_F008B138(piVar5,iVar2,1,(undefined *)((int)register0x00000038 + -0xc));
    if (piVar1 == (int *)0x5) {
      bVar4 = true;
    }
    else {
      iVar2 = (*(uint *)((int)register0x00000038 + -0xc) & 0xffffff) << ((byte)_page_shift & 0x1f);
      piVar3 = *(int **)(*(int *)(unk_F0130F70 + (uint)*(byte *)((int)register0x00000038 + -0xc) * 4
                                 ) + 8);
    }
  }
  piVar1 = (int *)0x1;
  if ((!bVar4) &&
     (piVar1 = piVar3, (**(code **)(piVar3[7] + 0x74))(piVar3,param_1,iVar2),
     param_2 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(*piVar3 + 0x34);
  }
  _vnode_pager_vput(piVar5);
  return CONCAT44(param_2,piVar1);
}
/* GHIDRADEC_FUNCTION index=1907 start=0xf008b6d0 */

/* WARNING: Removing unreachable block (ram,0xf008b800) */
/* WARNING: Removing unreachable block (ram,0xf008b764) */
/* WARNING: Removing unreachable block (ram,0xf008b750) */
/* WARNING: Removing unreachable block (ram,0xf008b80c) */
/* WARNING: Removing unreachable block (ram,0xf008b814) */
/* WARNING: Removing unreachable block (ram,0xf008b6e0) */

undefined8 _vnode_pageout(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  int *piVar5;
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
  piVar3 = *(int **)(*(int *)(param_1 + 0x14) + 0x28);
  piVar5 = piVar3;
  _vnode_pager_vget();
  uVar2 = *(int *)(param_1 + 0x18) + *(int *)(*(int *)(param_1 + 0x14) + 0x2c);
  iVar4 = _page_size;
  if (((-1 < piVar3[3]) && (uVar1 = *(uint *)(*piVar5 + 0x14), uVar1 < uVar2 + _page_size)) &&
     (iVar4 = 0, uVar2 <= uVar1)) {
    iVar4 = uVar1 - uVar2;
  }
  if (piVar3[3] < 0) {
    piVar5 = piVar3;
    sub_F008B138(piVar3,uVar2,0,(undefined *)((int)register0x00000038 + -0xc));
    if (piVar5 == (int *)0x5) {
      _vnode_pager_vput(piVar3);
      piVar5 = (int *)0x2;
      goto locret_F008B81C;
    }
    piVar5 = *(int **)(*(int *)(unk_F0130F70 + (uint)*(byte *)((int)register0x00000038 + -0xc) * 4)
                      + 8);
    uVar2 = (*(uint *)((int)register0x00000038 + -0xc) & 0xffffff) << ((byte)_page_shift & 0x1f);
    if (*(uint *)(*piVar5 + 0x14) < uVar2 + iVar4) {
      *(uint *)(*piVar5 + 0x14) = uVar2 + iVar4;
    }
  }
  if (iVar4 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    (**(code **)(piVar5[7] + 0x78))(piVar5,*(undefined4 *)(param_1 + 0x24),iVar4,uVar2);
  }
  if (piVar5 == (int *)0x0) {
    *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 0x400;
    _pmap_clear_modify(*(undefined4 *)(param_1 + 0x24));
  }
  else {
    _printf(aVnodePageoutFa);
  }
  _vnode_pager_vput(piVar3);
locret_F008B81C:
  return CONCAT44(param_2,piVar5);
}
/* GHIDRADEC_FUNCTION index=1908 start=0xf008b824 */

/* WARNING: Removing unreachable block (ram,0xf008b878) */
/* WARNING: Removing unreachable block (ram,0xf008b85c) */
/* WARNING: Removing unreachable block (ram,0xf008b838) */

undefined8 _vnode_has_page(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
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
  bool bVar2;
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
  if (param_1 == 0) {
    _panic(aVnodeHasPageFa);
    iVar1 = iRam0000000c;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc);
  }
  if (iVar1 < 0) {
    sub_F008B138(param_1,param_2,1,(undefined *)((int)register0x00000038 + -0xc));
    bVar2 = param_1 == 5;
    param_1 = 1;
    if (bVar2) {
      param_1 = 0;
    }
  }
  else {
    _panic(aVnodeHasPageCa);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1909 start=0xf008b888 */

/* WARNING: Removing unreachable block (ram,0xf008b9e8) */
/* WARNING: Removing unreachable block (ram,0xf008b9a8) */
/* WARNING: Removing unreachable block (ram,0xf008b8ec) */
/* WARNING: Removing unreachable block (ram,0xf008b928) */
/* WARNING: Removing unreachable block (ram,0xf008b9b8) */
/* WARNING: Removing unreachable block (ram,0xf008ba60) */
/* WARNING: Removing unreachable block (ram,0xf008b894) */

undefined8 _vnode_pager_file_init(undefined4 *param_1,int *param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined *puVar6;
  undefined4 unaff_l1;
  uint uVar7;
  sword *psVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar9;
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
  *param_1 = 0;
  _mfs_uncache(param_2);
  piVar9 = (int *)0x10;
  if ((*(uint *)(*param_2 + 0x38) & 0x8000000) == 0) {
    puVar6 = (undefined *)((int)register0x00000038 + -0x48);
    psVar8 = *(sword **)(_active_u + 0x1c);
    (**(code **)(param_2[7] + 0x14))(param_2,puVar6,psVar8);
    if (param_3 < *(uint *)((int)register0x00000038 + -0x30)) {
      _vattr_null(puVar6);
      *(uint *)((int)register0x00000038 + -0x30) = param_3;
      piVar9 = param_2;
      (**(code **)(param_2[7] + 0x18))(param_2,puVar6,psVar8);
      if (piVar9 != (int *)0x0) goto locret_F008BAC8;
      iVar4 = *param_2;
      uVar7 = param_3;
    }
    else {
      iVar4 = *param_2;
      uVar7 = *(uint *)((int)register0x00000038 + -0x30);
    }
    puVar3 = (undefined4 *)0x40;
    *(uint *)(iVar4 + 0x14) = uVar7;
    _kalloc();
    *(sword *)((int)param_2 + 6) = *(sword *)((int)param_2 + 6) + 1;
    puVar3[2] = param_2;
    *psVar8 = *psVar8 + 1;
    uVar1 = _page_shift;
    *(sword **)(*param_2 + 0x30) = psVar8;
    puVar3[3] = 0;
    uVar7 = _page_mask;
    puVar3[9] = 0;
    puVar3[7] = (param_3 + uVar7 & ~uVar7) >> ((byte)uVar1 & 0x1f);
    if (param_4 == 0) {
      piVar9 = (int *)param_2[9];
      (**(code **)(piVar9[1] + 0xc))(piVar9,(undefined *)((int)register0x00000038 + -0x88));
      if (piVar9 != (int *)0x0) {
        _kfree(puVar3,0x40);
        goto locret_F008BAC8;
      }
      param_4 = *(uint *)((int)register0x00000038 + -0x80);
      .umul(param_4,*(undefined4 *)((int)register0x00000038 + -0x84));
    }
    param_4 = param_4 >> ((byte)_page_shift & 0x1f);
    puVar3[5] = param_4;
    puVar3[6] = param_4;
    iVar4 = puVar3[5] + 7;
    if (iVar4 < 0) {
      iVar4 = puVar3[5] + 0xe;
    }
    iVar4 = iVar4 >> 3;
    _kalloc();
    puVar3[4] = iVar4;
    iVar4 = 0;
    if (0 < (int)puVar3[5]) {
      do {
        iVar5 = iVar4;
        if (iVar4 < 0) {
          iVar5 = iVar4 + 7;
        }
        iVar5 = iVar5 >> 3;
        *(byte *)(puVar3[4] + iVar5) =
             *(byte *)(puVar3[4] + iVar5) & ~(byte)(1 << ((char)iVar4 + (char)iVar5 * -8 & 0x1fU));
        iVar4 = iVar4 + 1;
      } while (iVar4 < (int)puVar3[5]);
    }
    puVar3[8] = 0xffffffff;
    puVar3[0xb] = 0;
    _lock_init(puVar3 + 0xd,1);
    puVar2 = puVar3;
    if ((undefined4 **)dword_F0130F68 != &dword_F0130F64) {
      *dword_F0130F68 = puVar3;
      puVar2 = dword_F0130F64;
    }
    dword_F0130F64 = puVar2;
    puVar3[1] = dword_F0130F68;
    *puVar3 = &dword_F0130F64;
    piVar9 = (int *)0x0;
    iVar4 = dword_F0130F6C + 1;
    dword_F0130F68 = puVar3;
    dword_F0130F6C = iVar4;
    puVar3[0xc] = iVar4;
    *(undefined4 **)(unk_F0130F70 + iVar4 * 4) = puVar3;
    *param_1 = puVar3;
  }
locret_F008BAC8:
  return CONCAT44(param_2,piVar9);
}
/* GHIDRADEC_FUNCTION index=1910 start=0xf008bad0 */

/* WARNING: Removing unreachable block (ram,0xf008baf8) */

undefined8 _vnode_pager_shutdown(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
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
  if ((undefined4 **)dword_F0130F64 != &dword_F0130F64) {
    do {
      puVar1 = dword_F0130F64;
      _vn_rele(dword_F0130F64[2]);
      puVar3 = (undefined4 *)*puVar1;
      puVar2 = (undefined4 *)puVar1[1];
      puVar1 = puVar2;
      if ((undefined4 **)puVar3 != &dword_F0130F64) {
        puVar3[1] = puVar2;
        puVar1 = dword_F0130F68;
      }
      dword_F0130F68 = puVar1;
      if ((undefined4 **)puVar2 != &dword_F0130F64) {
        *puVar2 = puVar3;
        puVar3 = dword_F0130F64;
      }
      dword_F0130F64 = puVar3;
      dword_F0130F6C = dword_F0130F6C + -1;
    } while ((undefined4 **)dword_F0130F64 != &dword_F0130F64);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1911 start=0xf008bb50 */

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
/* GHIDRADEC_FUNCTION index=1912 start=0xf008bcc4 */

undefined8 _vswap_allocate(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar5;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  int iVar6;
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
  puVar4 = (undefined4 *)0x0;
  iVar6 = 0;
  if (dword_F0130F6C < 2) {
    if (dword_F0130F6C == 1) {
      puVar4 = dword_F0130F64;
    }
  }
  else {
    uVar5 = 0;
    do {
      if ((undefined4 **)dword_F0130F64 != &dword_F0130F64) {
        puVar2 = dword_F0130F64;
        do {
          param_2 = puVar2[2];
          if (((int)uVar5 < 2) && (puVar2[0xb] == 0)) {
            puVar3 = (undefined4 *)*puVar2;
          }
          else {
            if ((uVar5 & 1) == 0) {
              if (*(undefined **)(param_2 + 0x1c) != _ufs_vnodeops) {
                puVar3 = (undefined4 *)*puVar2;
                goto loc_F008BD60;
              }
              iVar1 = puVar2[6];
            }
            else {
              iVar1 = puVar2[6];
            }
            if (iVar6 < iVar1) {
              puVar3 = (undefined4 *)*puVar2;
              puVar4 = puVar2;
              iVar6 = iVar1;
            }
            else {
              puVar3 = (undefined4 *)*puVar2;
            }
          }
loc_F008BD60:
          puVar2 = puVar3;
        } while ((undefined4 **)puVar3 != &dword_F0130F64);
      }
      uVar5 = uVar5 + 1;
    } while ((puVar4 == (undefined4 *)0x0) && ((int)uVar5 < 4));
  }
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=1913 start=0xf008bd9c */

/* WARNING: Removing unreachable block (ram,0xf008bdb8) */
/* WARNING: Removing unreachable block (ram,0xf008bda4) */

undefined8 _vnode_alloc(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  _vswap_allocate();
  iVar1 = 0;
  if (param_1 != 0) {
    _pagerfile_pager_create();
    iVar1 = param_1;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1914 start=0xf008bdcc */

/* WARNING: Removing unreachable block (ram,0xf008bef0) */
/* WARNING: Removing unreachable block (ram,0xf008be98) */
/* WARNING: Removing unreachable block (ram,0xf008bf04) */
/* WARNING: Removing unreachable block (ram,0xf008be00) */

undefined8 _vnode_pager_truncate(uint *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
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
  iVar6 = *(int *)(unk_F0130F70 + (*param_1 >> 0x18) * 4);
  uVar2 = *param_1 & 0xffffff;
  piVar5 = *(int **)(iVar6 + 8);
  if (*(int *)(iVar6 + 0x20) <= (int)uVar2) {
    _lock_write(iVar6 + 0x34);
    iVar1 = uVar2 - 1;
    if (iVar1 < 0) {
      iVar1 = *(int *)(iVar6 + 0x1c);
    }
    else {
      do {
        iVar3 = iVar1;
        if (iVar1 < 0) {
          iVar3 = iVar1 + 7;
        }
        if (((int)*(char *)(*(int *)(iVar6 + 0x10) + (iVar3 >> 3)) >>
             ((char)iVar1 + (char)(iVar3 >> 3) * -8 & 0x1fU) & 1U) != 0) {
          *(int *)(iVar6 + 0x20) = iVar1;
          break;
        }
        iVar1 = iVar1 + -1;
      } while (-1 < iVar1);
      iVar1 = *(int *)(iVar6 + 0x1c);
    }
    iVar3 = *(int *)(iVar6 + 0x20) + 1;
    if (((iVar1 != 0) && (iVar1 < iVar3)) &&
       ((uint)(iVar3 << ((byte)_page_shift & 0x1f)) <= *(uint *)(*piVar5 + 0x14))) {
      _vattr_null((undefined *)((int)register0x00000038 + -0x48));
      *(int *)((int)register0x00000038 + -0x30) = iVar3 << ((byte)_page_shift & 0x1f);
      uVar4 = *(undefined4 *)(_active_u + 0x1c);
      *(undefined4 *)(_active_u + 0x1c) = *(undefined4 *)(*piVar5 + 0x30);
      (**(code **)(piVar5[7] + 0x18))
                (piVar5,(undefined *)((int)register0x00000038 + -0x48),
                 *(undefined4 *)(*piVar5 + 0x30));
      if (piVar5 != (int *)0x0) {
        _printf(aVnodeDeallocpa,*(undefined4 *)(iVar6 + 0x28),piVar5);
      }
      *(undefined4 *)(_active_u + 0x1c) = uVar4;
    }
    _lock_done(iVar6 + 0x34);
  }
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=1915 start=0xf008bfc8 */

/* WARNING: Removing unreachable block (ram,0xf008c190) */
/* WARNING: Removing unreachable block (ram,0xf008c07c) */
/* WARNING: Removing unreachable block (ram,0xf008c048) */
/* WARNING: Removing unreachable block (ram,0xf008c0e0) */
/* WARNING: Removing unreachable block (ram,0xf008c154) */
/* WARNING: Removing unreachable block (ram,0xf008c0f4) */
/* WARNING: Removing unreachable block (ram,0xf008c064) */
/* WARNING: Removing unreachable block (ram,0xf008c124) */
/* WARNING: Removing unreachable block (ram,0xf008c1b0) */
/* WARNING: Removing unreachable block (ram,0xf008bfcc) */

undefined8 _vnode_dealloc(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 unaff_l3;
  uint uVar7;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  int iVar8;
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
  puVar1 = param_1;
  _vnode_pager_vget();
  dword_F0111EA8 = 0;
  if (-1 < (int)param_1[3]) {
    *(word *)(puVar1 + 1) = *(word *)(puVar1 + 1) & 0xfffd;
    *(undefined4 *)*puVar1 = 0;
    _vn_rele();
    goto loc_F008C15C;
  }
  iVar4 = param_1[4];
  iVar8 = param_1[1];
  if ((uint)(iVar4 * 4) < 0x41) {
    iVar2 = 0;
    if (iVar4 < 1) {
      iVar4 = param_1[4];
    }
    else {
      iVar4 = param_1[2];
      while( true ) {
        *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(iVar4 + iVar2 * 4);
        sub_F008AEAC((undefined *)((int)register0x00000038 + -0xc));
        *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1[2] + iVar2 * 4);
        sub_F008BF14((undefined *)((int)register0x00000038 + -0xc));
        iVar2 = iVar2 + 1;
        if ((int)param_1[4] <= iVar2) break;
        iVar4 = param_1[2];
      }
      iVar4 = param_1[4];
    }
    if (0 < iVar4) {
      uVar3 = param_1[2];
      goto loc_F008C124;
    }
    iVar4 = *(int *)(iVar8 + 0xc);
  }
  else {
    uVar7 = 0;
    if (iVar4 - 1U >> 4 != 0xffffffff) {
      iVar4 = 0;
      do {
        if (*(int *)(param_1[2] + iVar4) == 0) {
          iVar2 = param_1[4];
        }
        else {
          uVar6 = 0;
          iVar2 = param_1[2];
          do {
            iVar5 = uVar6 * 4;
            *(undefined4 *)((int)register0x00000038 + -0xc) =
                 *(undefined4 *)(*(int *)(iVar2 + iVar4) + iVar5);
            sub_F008AEAC((undefined *)((int)register0x00000038 + -0xc));
            uVar6 = uVar6 + 1;
            *(undefined4 *)((int)register0x00000038 + -0xc) =
                 *(undefined4 *)(*(int *)(param_1[2] + iVar4) + iVar5);
            sub_F008BF14((undefined *)((int)register0x00000038 + -0xc));
            iVar2 = param_1[2];
          } while (uVar6 < 0x10);
          _kfree(*(undefined4 *)(iVar2 + iVar4),0x40);
          iVar2 = param_1[4];
        }
        uVar7 = uVar7 + 1;
        iVar4 = iVar4 + 4;
      } while (uVar7 < (iVar2 - 1U >> 4) + 1);
      iVar4 = param_1[4];
    }
    uVar3 = param_1[2];
    iVar4 = (iVar4 - 1U >> 4) + 1;
loc_F008C124:
    _kfree(uVar3,iVar4 << 2);
    iVar4 = *(int *)(iVar8 + 0xc);
  }
  *(int *)(iVar8 + 0xc) = iVar4 + -1;
loc_F008C15C:
  iVar4 = 0;
  if (0 < dword_F0111EA8) {
    iVar8 = 0;
    do {
      iVar4 = iVar4 + 1;
      *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(unk_F0130FB0 + iVar8);
      _vnode_pager_truncate((undefined *)((int)register0x00000038 + -0xc));
      iVar8 = iVar8 + 4;
    } while (iVar4 < dword_F0111EA8);
  }
  _zfree(_vstruct_zone,param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1916 start=0xf008c1c0 */

/* WARNING: Removing unreachable block (ram,0xf008c26c) */
/* WARNING: Removing unreachable block (ram,0xf008c274) */
/* WARNING: Removing unreachable block (ram,0xf008c260) */

undefined8 _vnode_uncache(int *param_1,undefined4 param_2)

{
  word wVar1;
  bool bVar2;
  undefined4 unaff_l0;
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
  if (((int *)*param_1 != (int *)0x0) && (*(int *)*param_1 != 0)) {
    bVar2 = false;
    if ((undefined *)param_1[7] == _ufs_vnodeops) {
      wVar1 = *(word *)(param_1[0xc] + 0x44);
      if ((wVar1 & 1) != 0) {
        bVar2 = true;
        *(word *)(param_1[0xc] + 0x44) = wVar1 & 0xfffe;
      }
    }
    else if ((undefined *)param_1[7] == _nfs_vnodeops) {
      wVar1 = *(word *)(param_1[0xc] + 0x60);
      if ((wVar1 & 1) != 0) {
        bVar2 = true;
        *(word *)(param_1[0xc] + 0x60) = wVar1 & 0xfffe;
      }
    }
    _mfs_uncache(param_1);
    _vm_object_lookup(*(undefined4 *)*param_1);
    _vm_object_cache_object();
    if (bVar2) {
      if ((undefined *)param_1[7] == _ufs_vnodeops) {
        *(word *)(param_1[0xc] + 0x44) = *(word *)(param_1[0xc] + 0x44) | 1;
      }
      else if ((undefined *)param_1[7] == _nfs_vnodeops) {
        *(word *)(param_1[0xc] + 0x60) = *(word *)(param_1[0xc] + 0x60) | 1;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1917 start=0xf008c2d8 */

/* WARNING: Removing unreachable block (ram,0xf008c2f8) */

undefined8 _vnode_pager_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  uVar1 = 0x18;
  _zinit(0x18,240000,_page_size,0,aVnodePagerStru);
  _vstruct_zone = uVar1;
  _vstruct_lock = 0;
  dword_F0130F68 = &dword_F0130F64;
  dword_F0130F64 = &dword_F0130F64;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1918 start=0xf008c328 */

sqword _NXFlush(undefined4 param_1,uint param_2)

{
  undefined4 unaff_l0;
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=1919 start=0xf008c334 */

/* WARNING: Removing unreachable block (ram,0xf008c358) */
/* WARNING: Removing unreachable block (ram,0xf008c360) */
/* WARNING: Removing unreachable block (ram,0xf008c344) */

undefined8
_NXPrintf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
         undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  uVar1 = param_1;
  _splusclock();
  _vlog(3,param_2,(undefined *)((int)register0x00000038 + 0x4c));
  _splx(uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1920 start=0xf008c370 */

/* WARNING: Removing unreachable block (ram,0xf008c378) */

undefined8 _abort(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  _panic(aObjcFatalError);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1921 start=0xf008c388 */

/* WARNING: Removing unreachable block (ram,0xf008c42c) */
/* WARNING: Removing unreachable block (ram,0xf008c400) */
/* WARNING: Removing unreachable block (ram,0xf008c39c) */
/* WARNING: Removing unreachable block (ram,0xf008c394) */
/* WARNING: Removing unreachable block (ram,0xf008c3e8) */
/* WARNING: Removing unreachable block (ram,0xf008c418) */
/* WARNING: Removing unreachable block (ram,0xf008c43c) */
/* WARNING: Removing unreachable block (ram,0xf008c38c) */

undefined8 _autoconf(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined (*pauVar2) [16];
  undefined4 unaff_l0;
  undefined *puVar3;
  undefined4 unaff_l1;
  undefined4 *puVar4;
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
  sub_F008C44C();
  _IOInitGeneralFuncs();
  _volCheckInit();
  puVar4 = &_pseudo_inits;
  puVar3 = DAT_f012eaf0;
  pauVar2 = paNxconditionloc;
  iVar1 = DAT_f012eaf0._0_4_;
  while (paNxconditionloc = pauVar2, iVar1 != 0) {
    (**(code **)puVar3)(*puVar4);
    puVar3 = (undefined *)((int)puVar3 + 8);
    puVar4 = puVar4 + 2;
    pauVar2 = paNxconditionloc;
    iVar1 = *(int *)puVar3;
  }
  _objc_msgSend(pauVar2,paAlloc);
  dword_F0130FF0 = pauVar2;
  _objc_msgSend();
  _kernel_thread(_IOTask_kern,sub_F008C65C,0);
  _objc_msgSend(dword_F0130FF0,paLockwhen,1);
  _objc_msgSend(dword_F0130FF0,paFree);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1922 start=0xf008c518 */

undefined8 __io_vm_task_self(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(_IOTask_kern + 0xc));
}
/* GHIDRADEC_FUNCTION index=1923 start=0xf008c530 */

undefined8 __io_vm_task_current(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc));
}
/* GHIDRADEC_FUNCTION index=1924 start=0xf008c54c */

undefined8 __io_vm_task(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0xc));
}
/* GHIDRADEC_FUNCTION index=1925 start=0xf008c55c */

undefined8 __io_vm_task_pmap(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x24));
}
/* GHIDRADEC_FUNCTION index=1926 start=0xf008c56c */

/* WARNING: Removing unreachable block (ram,0xf008c588) */
/* WARNING: Removing unreachable block (ram,0xf008c570) */

undefined8 __io_task_get_port(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  _port_reference(param_1);
  _object_copyout(_IOTask_kern,param_1,6,(undefined *)((int)register0x00000038 + -0xc));
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
}
/* GHIDRADEC_FUNCTION index=1927 start=0xf008c59c */

/* WARNING: Removing unreachable block (ram,0xf008c5b4) */

undefined8 __io_get_kern_port(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  iVar1 = _IOTask_kern;
  _object_copyin(_IOTask_kern,param_1,6,0,(undefined *)((int)register0x00000038 + -0xc));
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1928 start=0xf008c5d4 */

/* WARNING: Removing unreachable block (ram,0xf008c5f0) */

undefined8 __io_convert_port_in(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  iVar1 = *(int *)(_active_threads + 0xc);
  _object_copyin(iVar1,param_1,6,0,(undefined *)((int)register0x00000038 + -0xc));
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1929 start=0xf008c610 */

/* WARNING: Removing unreachable block (ram,0xf008c630) */
/* WARNING: Removing unreachable block (ram,0xf008c614) */

undefined8 __io_convert_port_out(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  _port_reference(param_1);
  _object_copyout(*(undefined4 *)(_active_threads + 0xc),param_1,6,
                  (undefined *)((int)register0x00000038 + -0xc));
  return CONCAT44(param_2,*(undefined4 *)((int)register0x00000038 + -0xc));
}
/* GHIDRADEC_FUNCTION index=1930 start=0xf008c644 */

/* WARNING: Removing unreachable block (ram,0xf008c64c) */

undefined8 __io_host_priv_self(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
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
  uVar1 = dword_F0135174;
  __io_convert_port_out(dword_F0135174);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1931 start=0xf008c830 */

/* WARNING: Removing unreachable block (ram,0xf008c83c) */

undefined8 __io_setDriverPowerState(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  sub_F008C79C(paSetpowerstate,param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1932 start=0xf008c84c */

/* WARNING: Removing unreachable block (ram,0xf008c858) */

undefined8 __ioSetDriverPowerManagementState(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  sub_F008C79C(paSetpowermanage,param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1933 start=0xf008c95c */

/* WARNING: Removing unreachable block (ram,0xf008c984) */
/* WARNING: Removing unreachable block (ram,0xf008c98c) */
/* WARNING: Removing unreachable block (ram,0xf008c960) */

undefined8 _KernLockAcquire(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
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
  iVar1 = param_1;
  _curipl();
  if (param_1 != 0) {
    if (iVar1 < *(int *)(param_1 + 8)) {
      _ipltospl();
      _splx();
      *(int *)(param_1 + 0xc) = iVar1;
    }
    else {
      *(int *)(param_1 + 0xc) = iVar1;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1934 start=0xf008c9a0 */

/* WARNING: Removing unreachable block (ram,0xf008c9b8) */
/* WARNING: Removing unreachable block (ram,0xf008c9b0) */

undefined8 _KernLockRelease(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  if (param_1 != 0) {
    _ipltospl(*(undefined4 *)(param_1 + 0xc));
    _splx();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1935 start=0xf008ddf0 */

/* WARNING: Removing unreachable block (ram,0xf008def4) */
/* WARNING: Removing unreachable block (ram,0xf008de88) */
/* WARNING: Removing unreachable block (ram,0xf008de44) */
/* WARNING: Removing unreachable block (ram,0xf008ded8) */
/* WARNING: Removing unreachable block (ram,0xf008de58) */
/* WARNING: Removing unreachable block (ram,0xf008ddfc) */

undefined8
__KernBusMemoryCreateMapping
          (uint param_1,int param_2,uint *param_3,int param_4,uint param_5,int param_6)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar4;
  undefined4 unaff_i3;
  int iVar5;
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
  iVar5 = *(int *)(param_4 + 0xc);
  _vm_map_reference(iVar5);
  if ((param_5 & 0xff) == 0) {
    uVar1 = *param_3 & ~_page_mask;
  }
  else {
    uVar1 = *(uint *)(iVar5 + 0x14);
  }
  *param_3 = uVar1;
  iVar3 = iVar5;
  _vm_map_find(iVar5,0,0,param_3,param_2,(int)(char)param_5);
  if (iVar3 == 0) {
    uVar4 = *param_3 & ~_page_mask;
    uVar1 = param_2 + _page_mask & ~_page_mask;
    _vm_map_inherit(iVar5,uVar4,uVar4 + uVar1,2);
    param_1 = param_1 & ~_page_mask;
    if (param_6 == 0) {
      uVar2 = 2;
    }
    else {
      uVar2 = 1;
      if (param_6 != 1) {
        uVar2 = 0;
      }
    }
    for (; uVar1 != 0; uVar1 = uVar1 - _page_size) {
      _pmap_enter_cache_spec(*(undefined4 *)(iVar5 + 0x24),uVar4,param_1,3,1,uVar2);
      uVar4 = uVar4 + _page_size;
      param_1 = param_1 + _page_size;
    }
    _vm_map_deallocate(iVar5);
    iVar3 = 0;
    param_2 = 0;
  }
  else {
    _vm_map_deallocate(iVar5);
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=1936 start=0xf008e338 */

/* WARNING: Removing unreachable block (ram,0xf008e3a8) */
/* WARNING: Removing unreachable block (ram,0xf008e380) */
/* WARNING: Removing unreachable block (ram,0xf008e3b0) */
/* WARNING: Removing unreachable block (ram,0xf008e340) */

undefined8 _KernBusInterruptDispatch(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l1;
  undefined4 *puVar4;
  code *pcVar5;
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
  pcVar5 = *(code **)(param_1 + 0x28);
  _KernLockAcquire(*(undefined4 *)(param_1 + 0x1c));
  puVar4 = *(undefined4 **)(*(int *)(param_1 + 0x14) + 4);
  for (iVar2 = *(int *)(param_1 + 0x18); 0 < iVar2; iVar2 = iVar2 + -1) {
    uVar1 = *puVar4;
    puVar4 = puVar4 + 1;
    (*pcVar5)(uVar1,param_2);
  }
  _KernLockAcquire(*(undefined4 *)(param_1 + 0x24));
  uVar3 = 0;
  if (0 < *(int *)(param_1 + 0x18)) {
    uVar3 = (uint)(*(int *)(param_1 + 0x20) == 0);
  }
  _KernLockRelease(*(undefined4 *)(param_1 + 0x24));
  _KernLockRelease(*(undefined4 *)(param_1 + 0x1c));
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1937 start=0xf008e3c0 */

/* WARNING: Removing unreachable block (ram,0xf008e3f0) */
/* WARNING: Removing unreachable block (ram,0xf008e3d0) */

undefined8 _KernBusInterruptSuspend(int param_1,undefined4 param_2)

{
  int iVar1;
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
  if (param_1 != 0) {
    _KernLockAcquire(*(undefined4 *)(param_1 + 0x24));
    iVar2 = *(int *)(param_1 + 0x20);
    iVar1 = iVar2 + 1;
    *(int *)(param_1 + 0x20) = iVar1;
    if (iVar1 < 0) {
      *(int *)(param_1 + 0x20) = iVar2;
    }
    _KernLockRelease(*(undefined4 *)(param_1 + 0x24));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1938 start=0xf008e400 */

/* WARNING: Removing unreachable block (ram,0xf008e42c) */
/* WARNING: Removing unreachable block (ram,0xf008e410) */

undefined8 _KernBusInterruptResume(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  if (param_1 != 0) {
    _KernLockAcquire(*(undefined4 *)(param_1 + 0x24));
    if (0 < *(int *)(param_1 + 0x20)) {
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
    }
    _KernLockRelease(*(undefined4 *)(param_1 + 0x24));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1939 start=0xf008ebd0 */

/* WARNING: Removing unreachable block (ram,0xf008ec04) */
/* WARNING: Removing unreachable block (ram,0xf008ebdc) */
/* WARNING: Removing unreachable block (ram,0xf008ec18) */
/* WARNING: Removing unreachable block (ram,0xf008ec0c) */
/* WARNING: Removing unreachable block (ram,0xf008ebd4) */

undefined8 _KernDeviceInterruptMsgRelease(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
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
  _ipc_object_reference(*(undefined4 *)(param_1 + 0x2c));
  _KernLockAcquire(*(undefined4 *)(param_1 + 0x30));
  uVar1 = *(uint *)(param_1 + 0x60);
  *(uint *)(param_1 + 0x60) = uVar1 & 0x7fffffff;
  if ((uVar1 & 0x20000000) == 0) {
    _KernLockRelease(*(undefined4 *)(param_1 + 0x30));
  }
  else {
    _KernLockRelease(*(undefined4 *)(param_1 + 0x30));
    sub_F008EB5C(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1940 start=0xf008ec28 */

undefined8 _KernDeviceInterruptDispatch(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  (**(code **)(param_1 + 0xc))(param_1,param_2,*(undefined4 *)(param_1 + 0x10));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1941 start=0xf008ec48 */

/* WARNING: Removing unreachable block (ram,0xf008ec50) */

undefined8 _KernDeviceInterruptDispatchShared(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  code *pcVar1;
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
  pcVar1 = *(code **)(param_1 + 0xc);
  _IODisableInterrupt(param_1);
  (*pcVar1)(param_1,param_2,*(undefined4 *)(param_1 + 0x10));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1942 start=0xf008ec70 */

/* WARNING: Removing unreachable block (ram,0xf008ec88) */
/* WARNING: Removing unreachable block (ram,0xf008ec9c) */
/* WARNING: Removing unreachable block (ram,0xf008ec74) */

undefined8 _IOEnableInterrupt(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar2;
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
  _KernLockAcquire(*(undefined4 *)(param_1 + 8));
  cVar1 = *(char *)(param_1 + 0x18);
  uVar2 = *(undefined4 *)(param_1 + 4);
  *(undefined *)(param_1 + 0x18) = 0;
  _KernLockRelease(*(undefined4 *)(param_1 + 8));
  if (cVar1 != '\0') {
    _KernBusInterruptResume(uVar2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1943 start=0xf008ecac */

/* WARNING: Removing unreachable block (ram,0xf008ecc8) */
/* WARNING: Removing unreachable block (ram,0xf008ecdc) */
/* WARNING: Removing unreachable block (ram,0xf008ecb0) */

undefined8 _IODisableInterrupt(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar2;
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
  _KernLockAcquire(*(undefined4 *)(param_1 + 8));
  cVar1 = *(char *)(param_1 + 0x18);
  uVar2 = *(undefined4 *)(param_1 + 4);
  *(undefined *)(param_1 + 0x18) = 1;
  _KernLockRelease(*(undefined4 *)(param_1 + 8));
  if (cVar1 == '\0') {
    _KernBusInterruptSuspend(uVar2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1944 start=0xf008ecec */

/* WARNING: Removing unreachable block (ram,0xf008edb4) */
/* WARNING: Removing unreachable block (ram,0xf008ed8c) */
/* WARNING: Removing unreachable block (ram,0xf008ed34) */
/* WARNING: Removing unreachable block (ram,0xf008ed04) */
/* WARNING: Removing unreachable block (ram,0xf008ed78) */
/* WARNING: Removing unreachable block (ram,0xf008edac) */
/* WARNING: Removing unreachable block (ram,0xf008ed20) */
/* WARNING: Removing unreachable block (ram,0xf008ecf0) */

undefined8 _IOSendInterrupt(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x14);
  _curipl();
  if (param_1 < 0xb) {
    _KernLockAcquire(*(undefined4 *)(iVar2 + 0x30));
    if ((*(uint *)(iVar2 + 0x60) & 0xc0000000) == 0) {
      *(uint *)(iVar2 + 0x60) = *(uint *)(iVar2 + 0x60) | 0x80000000;
      _KernLockRelease(*(undefined4 *)(iVar2 + 0x30));
      *(undefined4 *)(iVar2 + 0x14) = dword_F0112054;
      *(undefined4 *)(iVar2 + 0x18) = DAT_f0112058._0_4_;
      *(undefined4 *)(iVar2 + 0x1c) = DAT_f0112058._4_4_;
      *(undefined4 *)(iVar2 + 0x20) = DAT_f0112058._8_4_;
      *(undefined4 *)(iVar2 + 0x24) = DAT_f0112058._12_4_;
      *(undefined4 *)(iVar2 + 0x28) = param_3;
      *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar2 + 0x2c);
      iVar1 = iVar2;
      _ipc_mqueue_send_interrupt();
      if (iVar1 != 0) {
        _KernLockAcquire(*(undefined4 *)(iVar2 + 0x30));
        *(uint *)(iVar2 + 0x60) = *(uint *)(iVar2 + 0x60) & 0x7fffffff | 0x40000000;
        _KernLockRelease(*(undefined4 *)(iVar2 + 0x30));
        _calloutEntryDispatch(iVar2 + 0x38);
      }
    }
    else {
      _KernLockRelease(*(undefined4 *)(iVar2 + 0x30));
    }
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1945 start=0xf009028c */

undefined8 _dev_server_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1946 start=0xf0090298 */

/* WARNING: Removing unreachable block (ram,0xf00902c0) */

undefined8 _convert_port_to_dev(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = 0;
  if (param_1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if ((param_1[2] & 0xffffU) == 0xc) {
      iVar2 = param_1[5];
    }
    *param_1 = 0;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1947 start=0xf00902fc */

/* WARNING: Removing unreachable block (ram,0xf0090318) */
/* WARNING: Removing unreachable block (ram,0xf0090328) */
/* WARNING: Removing unreachable block (ram,0xf0090304) */

undefined8 _create_dev_port(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  iVar1 = _ipc_space_kernel;
  _ipc_port_alloc_special();
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    _ipc_kobject_set();
    _IOConvertPort(iVar1,0,1);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1948 start=0xf0090344 */

/* WARNING: Removing unreachable block (ram,0xf0090370) */
/* WARNING: Removing unreachable block (ram,0xf0090384) */
/* WARNING: Removing unreachable block (ram,0xf0090354) */

undefined8 _destroy_dev_port(int *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 unaff_l0;
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
  if (param_1 != (int *)0x0) {
    _IOConvertPort(param_1,1,0);
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    _ipc_port_destroy(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1949 start=0xf0090394 */

/* WARNING: Removing unreachable block (ram,0xf00903b8) */

undefined8
_kern_IOLookupByObjectNumber(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined (*pauVar1) [12];
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
  if (param_1 == 0) {
    pauVar1 = (undefined (*) [12])0xfffffd3f;
  }
  else {
    pauVar1 = paIodevice_0;
    _objc_msgSend(paIodevice_0,paLookupbyobject_0,param_2,param_3,param_4);
  }
  return CONCAT44(param_2,pauVar1);
}

