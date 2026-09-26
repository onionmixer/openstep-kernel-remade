/* GHIDRADEC_FUNCTION index=2650 start=0xf00b154c */

undefined8 _sbusslot(int param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar1;
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
  uVar1 = 0;
  if (_sbus_numslots != 0) {
    param_2 = 0;
    do {
      if ((uint)(param_1 + *(int *)(_sbus_basepage + param_2) * -0x1000) <=
          *(int *)(_sbus_slotsize + param_2) - 1U) goto locret_F00B15B4;
      uVar1 = uVar1 + 1;
      param_2 = param_2 + 4;
    } while (uVar1 < _sbus_numslots);
  }
  uVar1 = 0xffffffff;
locret_F00B15B4:
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2651 start=0xf00b15bc */

/* WARNING: Removing unreachable block (ram,0xf00b15e0) */
/* WARNING: Removing unreachable block (ram,0xf00b15cc) */

undefined8 _slaveslot(int param_1,undefined4 param_2)

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
  uVar1 = 0;
  _getprop(0,aSlaveOnly,0);
  if (uVar1 == 0) {
    iVar2 = -1;
  }
  else {
    _sbusslot();
    if (param_1 == -1) {
      iVar2 = -1;
    }
    else {
      iVar2 = -1;
      if ((uVar1 & 1 << ((byte)param_1 & 0x1f)) != 0) {
        iVar2 = param_1;
      }
    }
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=2652 start=0xf00b161c */

/* WARNING: Removing unreachable block (ram,0xf00b168c) */
/* WARNING: Removing unreachable block (ram,0xf00b1668) */
/* WARNING: Removing unreachable block (ram,0xf00b1644) */
/* WARNING: Removing unreachable block (ram,0xf00b1650) */
/* WARNING: Removing unreachable block (ram,0xf00b167c) */
/* WARNING: Removing unreachable block (ram,0xf00b16dc) */
/* WARNING: Removing unreachable block (ram,0xf00b1630) */

undefined8 _map_regs(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  uint uVar3;
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
  uVar1 = param_1;
  if (param_3 != -1) {
    uVar3 = param_1;
    _splusclock();
    uVar1 = param_2 + (param_1 & 0xfff);
    _map_alloc(uVar1,0);
    _splx(uVar3);
    if (uVar1 == 0) {
      _panic(aOutOfKernelMap);
    }
    iVar2 = _page_size;
    uVar3 = param_2;
    .udiv(param_2,_page_size);
    .urem(param_2,iVar2);
    uVar1 = uVar1 | param_1 & 0xfff;
    if (param_2 != 0) {
      uVar3 = uVar3 + 1;
    }
    iVar2 = 0;
    param_2 = uVar1;
    if (0 < (int)uVar3) {
      do {
        iVar2 = iVar2 + 1;
        _pmap_enter_dev(_kernel_pmap,param_2 & 0xfffff000,param_1,param_3,3,0,1);
        param_2 = param_2 + _page_size;
        param_1 = param_1 + _page_size;
      } while (iVar2 < (int)uVar3);
    }
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2653 start=0xf00b1704 */

/* WARNING: Removing unreachable block (ram,0xf00b1730) */
/* WARNING: Removing unreachable block (ram,0xf00b1720) */
/* WARNING: Removing unreachable block (ram,0xf00b1738) */
/* WARNING: Removing unreachable block (ram,0xf00b1718) */

undefined8 _unmap_regs(uint param_1,int param_2)

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
  param_2 = param_2 + (param_1 & 0xfff);
  uVar1 = _kernel_pmap;
  _pmap_remove(_kernel_pmap,param_1 & 0xfffff000);
  _splusclock();
  _kfree(param_1,param_2);
  _splx(uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2654 start=0xf00b1748 */

/* WARNING: Removing unreachable block (ram,0xf00b174c) */

undefined8 _adddma(uint param_1,undefined4 param_2)

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
  uVar1 = param_1 & 0xf;
  _ipltospl();
  if ((int)_splvm_val < (int)uVar1) {
    _SPLMB = (int)(uVar1 + 0x100) >> 9 & 0xf;
    _splvm_val = uVar1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2655 start=0xf00b1784 */

/* WARNING: Removing unreachable block (ram,0xf00b179c) */

undefined8 _find_slave_devinfo(int param_1,undefined4 param_2,int param_3)

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
    param_1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc);
    while( true ) {
      _strcmp(iVar1,param_2);
      if (iVar1 == 0) {
        iVar1 = _devdesc_found + 1;
        bVar2 = _devdesc_found == param_3;
        _devdesc_found = iVar1;
        if (bVar2) goto locret_F00B17D8;
        param_1 = *(int *)(param_1 + 4);
      }
      else {
        param_1 = *(int *)(param_1 + 4);
      }
      if (param_1 == 0) break;
      iVar1 = *(int *)(param_1 + 0xc);
    }
    param_1 = 0;
  }
locret_F00B17D8:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2656 start=0xf00b17e0 */

/* WARNING: Removing unreachable block (ram,0xf00b1818) */
/* WARNING: Removing unreachable block (ram,0xf00b17ec) */

undefined8 _find_devinfo(int param_1,undefined4 param_2,undefined4 param_3)

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
  _find_slave_devinfo(param_1,param_2,param_3);
  if (iVar1 == 0) {
    while (param_1 != 0) {
      iVar1 = *(int *)(param_1 + 8);
      if (iVar1 == 0) {
        param_1 = *(int *)(param_1 + 4);
      }
      else {
        _find_devinfo(iVar1,param_2,param_3);
        if (iVar1 != 0) goto locret_F00B1840;
        param_1 = *(int *)(param_1 + 4);
      }
    }
    iVar1 = 0;
  }
locret_F00B1840:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2657 start=0xf00b1848 */

/* WARNING: Removing unreachable block (ram,0xf00b1860) */

undefined8 _findDeviceinfoForDevice(undefined4 param_1,undefined4 param_2)

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
  _devdesc_found = 0;
  uVar1 = _top_devinfo;
  _find_devinfo(_top_devinfo,param_1,param_2);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2658 start=0xf00b1870 */

/* WARNING: Removing unreachable block (ram,0xf00b19a8) */
/* WARNING: Removing unreachable block (ram,0xf00b1898) */
/* WARNING: Removing unreachable block (ram,0xf00b19d8) */
/* WARNING: Removing unreachable block (ram,0xf00b1878) */

undefined8 _cnopen(undefined2 param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
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
  iVar2 = _cons_tp;
  _ttynty();
  iVar6 = *_active_u;
  iVar3 = (int)*(sword *)(iVar6 + 0x30);
  wVar1 = *(word *)(_cons_tp + 0x38);
  _get_posix_proc();
  iVar4 = _cons_tp;
  if ((*(uint *)(iVar6 + 0x14) & 0x4000) == 0) {
    if ((*(uint *)(iVar6 + 0x28) & 0x40000000) == 0) {
      _active_u[0x59] = _cons_tp;
      *(undefined2 *)(_active_u + 0x5a) = param_1;
      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(*(int *)(iVar3 + 0x10) + 8);
      *(int *)(*(int *)(*(int *)(iVar3 + 0x10) + 8) + 8) = iVar4;
      iVar4 = (int)*(sword *)(iVar4 + 0x44);
      if (iVar4 == 0) {
        _enterpgrp(iVar6,(int)*(sword *)(iVar6 + 0x30),0);
        iVar4 = _cons_tp;
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 0x10);
        *(sword *)(iVar4 + 0x44) = (sword)*(undefined4 *)(*(int *)(iVar3 + 0x10) + 0xc);
      }
      else if (iVar4 != *(sword *)(iVar6 + 0x2e)) {
        _enterpgrp(iVar6,iVar4,0);
      }
    }
  }
  else {
    iVar5 = *(int *)(*(int *)(iVar3 + 0x10) + 8);
    if ((((*(int *)(iVar5 + 4) == iVar6) && (*(int *)(iVar5 + 8) == 0)) &&
        (*(int *)(iVar2 + 8) == 0)) && ((*(uint *)(iVar3 + 0x18) & 0x40000000) == 0)) {
      _active_u[0x59] = _cons_tp;
      *(undefined2 *)(_active_u + 0x5a) = param_1;
      *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(*(int *)(iVar3 + 0x10) + 8);
      *(int *)(*(int *)(*(int *)(iVar3 + 0x10) + 8) + 8) = iVar4;
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 0x10);
      *(sword *)(iVar4 + 0x44) = (sword)*(undefined4 *)(*(int *)(iVar3 + 0x10) + 0xc);
      *(uint *)(iVar6 + 0x28) = *(uint *)(iVar6 + 0x28) | 0x40000000;
    }
  }
  iVar4 = (int)(sword)wVar1;
  (**(code **)(_cdevsw + (uint)(wVar1 >> 8) * 0x2c))(iVar4,param_2);
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=2659 start=0xf00b1a1c */

undefined8 _cnread(undefined4 param_1,undefined4 param_2)

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
  iVar1 = (int)(sword)*(word *)(_cons_tp + 0x38);
  (**(code **)(DAT_f011c9f8 + (uint)(*(word *)(_cons_tp + 0x38) >> 8) * 0x2c))(iVar1,param_2);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2660 start=0xf00b1a6c */

undefined8 _cnwrite(undefined4 param_1,undefined4 param_2)

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
  iVar1 = (int)(sword)*(word *)(_cons_tp + 0x38);
  (**(code **)(DAT_f011c9fc + (uint)(*(word *)(_cons_tp + 0x38) >> 8) * 0x2c))(iVar1,param_2);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2661 start=0xf00b1abc */

/* WARNING: Removing unreachable block (ram,0xf00b1ae0) */

undefined8 _cnioctl(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

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
  if (param_2 == 0x20007471) {
    param_2 = *_active_u;
    iVar1 = (int)*(sword *)(param_2 + 0x30);
    _get_posix_proc();
    iVar2 = *(int *)(*(int *)(iVar1 + 0x10) + 8);
    _cons_tp = _cons;
    if (*(int *)(iVar2 + 4) == param_2) {
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined2 *)(*(int *)(*(int *)(iVar1 + 0x10) + 8) + 0xc) = 0;
    }
    iVar1 = 0;
    *(uint *)(param_2 + 0x28) = *(uint *)(param_2 + 0x28) & 0xbfffffff;
  }
  else {
    iVar1 = (int)(sword)*(word *)(_cons_tp + 0x38);
    (**(code **)(DAT_f011ca00 + (uint)(*(word *)(_cons_tp + 0x38) >> 8) * 0x2c))
              (iVar1,param_2,param_3,param_4);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2662 start=0xf00b1b8c */

undefined8 _cnselect(undefined4 param_1,undefined4 param_2)

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
  iVar1 = (int)(sword)*(word *)(_cons_tp + 0x38);
  (**(code **)(DAT_f011ca0c + (uint)(*(word *)(_cons_tp + 0x38) >> 8) * 0x2c))(iVar1,param_2);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2663 start=0xf00b1bdc */

/* WARNING: Removing unreachable block (ram,0xf00b1be0) */

undefined8 _cngetc(undefined4 param_1,undefined4 param_2)

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
  uVar1 = 0;
  _kmgetc(0);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2664 start=0xf00b1bf0 */

/* WARNING: Removing unreachable block (ram,0xf00b1bfc) */

undefined8 _cnputc(char param_1,undefined4 param_2)

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
  uVar1 = 0;
  _kmputc(0,(int)param_1);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2665 start=0xf00b1c0c */

/* WARNING: Removing unreachable block (ram,0xf00b1c74) */
/* WARNING: Removing unreachable block (ram,0xf00b1c38) */

undefined8 _cninit(undefined4 param_1,undefined4 param_2)

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
  _cons_tp = _cons;
  _kbddev = 0xffff;
  _mousedev = 0xffff;
  _fbdev = 0xffff;
  _consconfig();
  if ((_rconsdev & 0x7f) != 2) {
    _cons_tp = _zs_tty + (_rconsdev & 0x7f) * 0x88;
    _memcpy(_cons,_cons_tp,0x88);
  }
  *(word *)(_cons_tp + 0x38) = _rconsdev;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2666 start=0xf00b1c90 */

/* WARNING: Removing unreachable block (ram,0xf00b1e7c) */
/* WARNING: Removing unreachable block (ram,0xf00b1e54) */
/* WARNING: Removing unreachable block (ram,0xf00b1de4) */
/* WARNING: Removing unreachable block (ram,0xf00b1db4) */
/* WARNING: Removing unreachable block (ram,0xf00b1d8c) */
/* WARNING: Removing unreachable block (ram,0xf00b1d04) */
/* WARNING: Removing unreachable block (ram,0xf00b1cd8) */
/* WARNING: Removing unreachable block (ram,0xf00b1cbc) */
/* WARNING: Removing unreachable block (ram,0xf00b1cec) */
/* WARNING: Removing unreachable block (ram,0xf00b1d7c) */
/* WARNING: Removing unreachable block (ram,0xf00b1d98) */
/* WARNING: Removing unreachable block (ram,0xf00b1dd0) */
/* WARNING: Removing unreachable block (ram,0xf00b1dfc) */
/* WARNING: Removing unreachable block (ram,0xf00b1e6c) */
/* WARNING: Removing unreachable block (ram,0xf00b1ef8) */
/* WARNING: Removing unreachable block (ram,0xf00b1ca4) */

undefined8 _consconfig(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  char *pcVar4;
  undefined4 unaff_l0;
  undefined *puVar5;
  word wVar6;
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
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0xffffffff;
  iVar1 = -1;
  *(undefined2 *)((int)register0x00000038 + -0x14) = 0xffff;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  _prom_stdin_stdout_equivalence();
  puVar5 = (undefined *)((int)register0x00000038 + -0x118);
  if ((iVar1 != 0) &&
     (puVar3 = puVar5, _prom_get_stdin_dev_name(puVar5,0x100), puVar3 == (undefined *)0x0)) {
    puVar2 = &unk_F011D158;
    _strcmp(&unk_F011D158,puVar5);
    puVar5 = DAT_f013ec00;
    if (puVar2 == (undefined8 *)0x0) {
      _prom_get_stdin_unit();
      puVar3 = DAT_f013ec00;
      if (puVar5 != (undefined *)0xffffffff) {
        wVar6 = 0;
        _prom_get_stdin_subunit();
        if ((puVar3 != (char *)0x0) && (wVar6 = 0, *puVar3 != '\0')) {
          wVar6 = (sword)(char)*puVar3 - 0x61U & 1;
        }
        _rconsdev = wVar6 + (sword)((int)puVar5 << 1) | 0x2600;
      }
    }
  }
  iVar1 = (int)(sword)_rconsdev;
  if (iVar1 != 0) {
    _kbddev = _rconsdev;
    _consdev = _rconsdev;
    _walk_devs(_top_devinfo,_findcons,(undefined *)((int)register0x00000038 + -0x18));
    _options_devinfo = *(undefined4 *)((int)register0x00000038 + -0x10);
    _set_keyclick();
    goto locret_F00B1F3C;
  }
  _prom_stdin_is_keyboard();
  if (iVar1 == 0) {
    puVar3 = (undefined *)((int)register0x00000038 + -0x118);
    puVar5 = puVar3;
    _prom_get_stdin_dev_name(puVar3,0x100);
    if (puVar5 != (undefined *)0x0) goto loc_F00B1E44;
    puVar2 = &unk_F011D160;
    _strcmp(&unk_F011D160,puVar3);
    if (puVar2 != (undefined8 *)0x0) goto loc_F00B1E44;
    _prom_get_stdin_unit();
    pcVar4 = (char *)(int)(sword)_kbddev;
    if (puVar2 != (undefined8 *)0xffffffff) {
      wVar6 = 0;
      _prom_get_stdin_subunit();
      if ((pcVar4 != (char *)0x0) && (wVar6 = 0, *pcVar4 != '\0')) {
        wVar6 = (sword)*pcVar4 - 0x61U & 1;
      }
      _kbddev = wVar6 + (sword)((int)puVar2 << 1) | 0x2600;
      goto loc_F00B1E44;
    }
  }
  else {
loc_F00B1E44:
    pcVar4 = (char *)(int)(sword)_kbddev;
  }
  if (pcVar4 != (char *)0xffffffff) {
    _zsgetspeed();
  }
  _walk_devs(_top_devinfo,_findcons,(undefined *)((int)register0x00000038 + -0x18));
  _options_devinfo = *(undefined4 *)((int)register0x00000038 + -0x10);
  _set_keyclick();
  iVar1 = *(int *)((int)register0x00000038 + -0x18);
  if (iVar1 != -1) {
    if (_mousedev == 0xffff) {
      _mousedev = (sword)iVar1 * 2 + 1U | 0x2600;
    }
    if (_kbddev == 0xffff) {
      _kbddev = (word)(iVar1 << 1) | 0x2600;
    }
  }
  if (_kbddev == 0xffff) {
    _panic(aNoKeyboardFoun);
  }
  _kbddevopen = 0;
  if (_fbdev == -1) {
    _fbdev = *(sword *)((int)register0x00000038 + -0x14);
  }
  _consdev = _kbddev & 0xff | 0xc00;
  _rconsdev = _consdev;
locret_F00B1F3C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2667 start=0xf00b1f44 */

/* WARNING: Removing unreachable block (ram,0xf00b200c) */
/* WARNING: Removing unreachable block (ram,0xf00b1ff0) */
/* WARNING: Removing unreachable block (ram,0xf00b1fa0) */
/* WARNING: Removing unreachable block (ram,0xf00b1f80) */
/* WARNING: Removing unreachable block (ram,0xf00b1fc0) */
/* WARNING: Removing unreachable block (ram,0xf00b2004) */
/* WARNING: Removing unreachable block (ram,0xf00b2020) */
/* WARNING: Removing unreachable block (ram,0xf00b1f50) */

undefined8 _findcons(undefined *param_1,undefined4 *param_2)

{
  sword sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined *puVar5;
  undefined *puVar6;
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
  iVar2 = *(int *)(param_1 + 0xc);
  _strcmp(iVar2,&aOptions);
  if (iVar2 == 0) {
    param_2[2] = param_1;
  }
  else if (*(int *)(param_1 + 0x20) != 0) {
    iVar2 = *(int *)(param_1 + 0xc);
    _strncmp(iVar2,&aZs_2,2);
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x28);
      _getprop(iVar2,aKeyboard_0,0);
      if (iVar2 == 0) {
        uVar4 = *(uint *)(param_1 + 0x28);
        _getprop(uVar4,&aFlags_0,0);
        if ((uVar4 & 0x100) == 0) goto locret_F00B2040;
        uVar3 = *(undefined4 *)(param_1 + 0x2c);
      }
      else {
        uVar3 = *(undefined4 *)(param_1 + 0x2c);
      }
      *param_2 = uVar3;
    }
    else {
      param_1 = DAT_f011d000;
      puVar5 = DAT_f011d000;
      if (DAT_f011d17a._0_2_ == -1) {
        _prom_stdout_is_framebuffer();
        puVar6 = DAT_f011d000;
        if (puVar5 != (undefined *)0x0) {
          _prom_stdoutpath();
          _path_to_devi();
          if (puVar6 != (undefined *)0x0) {
            sVar1 = 99;
            _finddev(99,puVar6);
            DAT_f011d17a._0_2_ = sVar1;
          }
        }
      }
      if (DAT_f011d17a._0_2_ != -1) {
        *(sword *)(param_2 + 1) = DAT_f011d17a._0_2_;
      }
    }
  }
locret_F00B2040:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2668 start=0xf00b2048 */

/* WARNING: Removing unreachable block (ram,0xf00b20c4) */
/* WARNING: Removing unreachable block (ram,0xf00b208c) */
/* WARNING: Removing unreachable block (ram,0xf00b20a0) */
/* WARNING: Removing unreachable block (ram,0xf00b2080) */
/* WARNING: Removing unreachable block (ram,0xf00b2064) */

undefined8 _set_keyclick(int param_1,undefined4 param_2)

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
  int iVar3;
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
  iVar3 = 0;
  if (param_1 != 0) {
    iVar3 = *(int *)(param_1 + 0x28);
    iVar1 = iVar3;
    _getproplen(iVar3,aKeyboardClick);
    if (iVar1 < 1) {
      _printf(aNoSProperty,aKeyboardClick);
    }
    else {
      _getlongprop(iVar3,aKeyboardClick);
      if (iVar3 != 0) {
        iVar2 = iVar3;
        _strcmp();
        if (iVar2 == 0) {
          _keyclick = 1;
        }
        _kfree(iVar3,iVar1);
      }
    }
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=2669 start=0xf00b20d4 */

/* WARNING: Removing unreachable block (ram,0xf00b20e0) */

undefined8 _dmaidentify(int param_1,undefined4 param_2)

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
  _strcmp(param_1,&unk_F011D210);
  if (param_1 == 0) {
    _ndma_map = _ndma_map + 1;
  }
  return CONCAT44(param_2,(uint)(param_1 == 0));
}
/* GHIDRADEC_FUNCTION index=2670 start=0xf00b2110 */

/* WARNING: Removing unreachable block (ram,0xf00b224c) */
/* WARNING: Removing unreachable block (ram,0xf00b223c) */
/* WARNING: Removing unreachable block (ram,0xf00b2154) */
/* WARNING: Removing unreachable block (ram,0xf00b21c8) */
/* WARNING: Removing unreachable block (ram,0xf00b2244) */
/* WARNING: Removing unreachable block (ram,0xf00b21e8) */
/* WARNING: Removing unreachable block (ram,0xf00b2130) */

undefined8 _dmaattach(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 unaff_l0;
  int iVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
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
  if (_dma_map == 0) {
    iVar2 = _ndma_map << 4;
    _kalloc();
    _dma_map = iVar2;
    if (iVar2 != 0) {
      _bzero();
      goto loc_F00B2160;
    }
    iVar5 = *(int *)(param_1 + 0x2c);
    puVar3 = aDmaDNoSpaceFor;
  }
  else {
loc_F00B2160:
    iVar5 = (int)DAT_f011d214._0_1_;
    bVar1 = iVar5 < _ndma_map;
    DAT_f011d214._0_1_ = DAT_f011d214._0_1_ + '\x01';
    *(int *)(param_1 + 0x2c) = iVar5;
    iVar2 = _dma_map;
    if (bVar1) {
      iVar7 = _dma_map + iVar5 * 0x10;
      if (*(int *)(param_1 + 0x10) < 3) {
        puVar6 = *(undefined4 **)(param_1 + 0x14);
        iVar4 = puVar6[1];
        _map_regs(iVar4,puVar6[2],*puVar6);
        *(int *)(iVar2 + iVar5 * 0x10) = iVar4;
        if (iVar4 != 0) {
          *(undefined4 *)(iVar7 + 4) = **(undefined4 **)(param_1 + 0x14);
          *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 4);
          *(undefined *)(iVar7 + 0xc) = 1;
          if (*(int *)(param_1 + 0x18) != 0) {
            _addintr(**(undefined4 **)(param_1 + 0x1c),_dmaintr,*(undefined4 *)(param_1 + 0xc),
                     *(undefined4 *)(param_1 + 0x2c),0,0);
          }
          _report_dev(param_1);
          _attach_devs(param_1);
          uVar8 = 0;
          goto locret_F00B2258;
        }
        iVar5 = *(int *)(param_1 + 0x2c);
        puVar3 = aDmaDUnableToMa;
      }
      else {
        puVar3 = aDmaDBadRegiste;
      }
    }
    else {
      puVar3 = aDmaDBadUnitNum;
    }
  }
  uVar8 = 0xffffffff;
  _printf(puVar3,iVar5);
locret_F00B2258:
  return CONCAT44(param_2,uVar8);
}
/* GHIDRADEC_FUNCTION index=2671 start=0xf00b2260 */

undefined8 _dma_alloc(int param_1,int param_2)

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
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  char *pcVar5;
  undefined4 unaff_i3;
  int iVar6;
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
  iVar6 = 0;
  if (0 < _ndma_map) {
    pcVar5 = (char *)(_dma_map + 3);
    puVar3 = _dma_map;
    do {
      if ((*pcVar5 != '\0') && (*(int *)(pcVar5 + -8) == param_1)) {
        iVar2 = *(int *)(pcVar5 + -4);
        if (iVar2 < 0) {
          iVar2 = iVar2 + 0x1ffffff;
        }
        iVar1 = param_2;
        if (param_2 < 0) {
          iVar1 = param_2 + 0x1ffffff;
        }
        if (iVar2 >> 0x19 == iVar1 >> 0x19) {
          *pcVar5 = '\0';
          uVar4 = *puVar3;
          goto locret_F00B2308;
        }
      }
      pcVar5 = pcVar5 + 0x10;
      iVar6 = iVar6 + 1;
      puVar3 = puVar3 + 4;
    } while (iVar6 < _ndma_map);
  }
  uVar4 = 0;
locret_F00B2308:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=2672 start=0xf00b2310 */

undefined8 _dma_free(int param_1)

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
  int *piVar2;
  undefined4 unaff_i2;
  int iVar3;
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
  iVar3 = 0;
  piVar2 = _dma_map;
  if (0 < _ndma_map) {
    piVar1 = _dma_map + 3;
    do {
      if ((*(char *)piVar1 == '\0') && (*piVar2 == param_1)) {
        *(char *)piVar1 = '\x01';
        break;
      }
      piVar1 = piVar1 + 4;
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 4;
    } while (iVar3 < _ndma_map);
  }
  return CONCAT44(piVar2,param_1);
}
/* GHIDRADEC_FUNCTION index=2673 start=0xf00b237c */

sqword _dmaintr(undefined4 param_1,uint param_2)

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
/* GHIDRADEC_FUNCTION index=2674 start=0xf00b2388 */

/* WARNING: Removing unreachable block (ram,0xf00b2398) */

undefined8 _mmread(sword param_1,undefined4 param_2)

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
  iVar1 = (int)param_1;
  _mmrw(iVar1,param_2,0);
  return CONCAT44(param_2,iVar1);
}

