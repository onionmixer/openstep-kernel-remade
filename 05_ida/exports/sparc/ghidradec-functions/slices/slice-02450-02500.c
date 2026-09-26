/* GHIDRADEC_FUNCTION index=2450 start=0xf00a46d0 */

/* WARNING: Removing unreachable block (ram,0xf00a46f8) */
/* WARNING: Removing unreachable block (ram,0xf00a470c) */

undefined8 _check_boot_version(int param_1,undefined4 param_2)

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
  if (param_1 == 4) {
    param_1 = 0;
  }
  else if (param_1 == 3) {
    _prom_printf(aNoticeUsingOld);
    param_1 = 1;
  }
  else {
    _panic(aWrongBootInter,4);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2451 start=0xf00a471c */

/* WARNING: Removing unreachable block (ram,0xf00a4798) */
/* WARNING: Removing unreachable block (ram,0xf00a47b4) */
/* WARNING: Removing unreachable block (ram,0xf00a4728) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _init_mem_installed(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
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
  uVar1 = *__bootops;
  _check_boot_version();
  puVar2 = __bootops;
  _old_memlist = uVar1;
  (*(code *)__bootops[0xc])(__bootops,aMemoryUpdate_1);
  if (puVar2 == (undefined4 *)0x0) {
    (*(code *)__bootops[0xd])(__bootops,aMemoryUpdate_2,0);
  }
  _cur_memlist = _memlists;
  _phys_install = _memlists;
  _copy_memlist(*(undefined4 *)__bootops[2],&_cur_memlist,_old_memlist);
  _installed_top_size(_phys_install,&_physmaxpfn,&_physinstalled,_old_memlist);
  _physmax = _physmaxpfn << 0xc;
  _mem_size = _physinstalled << 0xc;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2452 start=0xf00a47e4 */

/* WARNING: Removing unreachable block (ram,0xf00a4820) */

undefined8 _insert_in_mem_regions(int param_1,int param_2)

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
  if ((undefined4 *)dword_F01197AC == (undefined4 *)0x0) {
    dword_F01197AC = _mem_region;
  }
  else if (&_num_regions < dword_F01197AC) {
    _printf(aMoreThanDDisco,0x40);
    goto locret_F00A485C;
  }
  *(int *)((int)dword_F01197AC + 0x10) = param_1;
  *(int *)((int)dword_F01197AC + 0x14) = param_1;
  *(int *)((int)dword_F01197AC + 0x18) = param_1 + param_2;
  _num_regions = _num_regions + 1;
  dword_F01197AC = (undefined *)((int)dword_F01197AC + 0x1c);
locret_F00A485C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2453 start=0xf00a4864 */

/* WARNING: Removing unreachable block (ram,0xf00a4880) */

undefined8 _init_mem_regions(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int iVar6;
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
  if (_phys_avail != 0) {
    uVar1 = *(undefined4 *)(_phys_avail + 4);
    iVar6 = _phys_avail;
    while( true ) {
      _insert_in_mem_regions(uVar1,*(undefined4 *)(iVar6 + 0xc));
      iVar6 = *(int *)(iVar6 + 0x10);
      if (iVar6 == 0) break;
      uVar1 = *(undefined4 *)(iVar6 + 4);
    }
  }
  if ((param_1 != 0) && (param_1 < _mem_size)) {
    uVar5 = _mem_size - param_1;
    puVar3 = &dword_F013CC14 + _num_regions * 7;
    _mem_size = param_1;
    if (uVar5 != 0) {
      piVar4 = (int *)(_num_regions * 0x1c + -0xfec33d4);
      do {
        if (puVar3 < _mem_region) break;
        uVar2 = *piVar4 - piVar4[-1];
        if (uVar5 < uVar2) {
          *piVar4 = *piVar4 - uVar5;
          uVar5 = 0;
        }
        else {
          uVar5 = uVar5 - uVar2;
          piVar4[-2] = 0;
          piVar4[-1] = 0;
          *piVar4 = 0;
          _num_regions = _num_regions + -1;
        }
        piVar4 = piVar4 + -7;
        puVar3 = puVar3 + -7;
      } while (uVar5 != 0);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2454 start=0xf00a494c */

/* WARNING: Removing unreachable block (ram,0xf00a49c4) */

undefined8 _get_from_mem_regions(int param_1,int param_2)

{
  undefined *puVar1;
  uint *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
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
  puVar1 = _mem_region;
  if (_mem_region < _mem_region + _num_regions * 0x1c) {
    puVar2 = (uint *)(_mem_region + 0x14);
    do {
      uVar3 = (*puVar2 - 1) + param_2 & -param_2;
      puVar1 = puVar1 + 0x1c;
      if (uVar3 + param_1 <= puVar2[1]) {
        *puVar2 = uVar3 + param_1;
        goto locret_F00A49D0;
      }
      puVar2 = puVar2 + 7;
    } while (puVar1 < _mem_region + _num_regions * 0x1c);
  }
  _panic(aGetFromMemRegi);
  uVar3 = 0;
locret_F00A49D0:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=2455 start=0xf00a49d8 */

/* WARNING: Removing unreachable block (ram,0xf00a49e0) */

undefined8 _va_to_pfn(uint param_1,undefined4 param_2)

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
  _mmu_probe(param_1,0);
  uVar1 = 0xffffffff;
  if ((param_1 != 0) && ((param_1 & 3) != 0)) {
    uVar1 = param_1 >> 8;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2456 start=0xf00a4a08 */

/* WARNING: Removing unreachable block (ram,0xf00a4a0c) */

undefined8 _va_to_pa(uint param_1,undefined4 param_2)

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
  uVar1 = param_1;
  _va_to_pfn();
  if (uVar1 == 0xffffffff) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = uVar1 << 0xc | param_1 & 0xfff;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2457 start=0xf00a4a38 */

/* WARNING: Removing unreachable block (ram,0xf00a4a74) */
/* WARNING: Removing unreachable block (ram,0xf00a4a54) */

undefined8 _pac_flush(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
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
  for (uVar2 = param_1; uVar2 < param_1 + param_2; uVar2 = uVar2 + 0x1000) {
    uVar1 = param_1;
    _mmu_probe(param_1,0);
    if ((uVar1 != 0) && ((uVar1 & 3) != 0)) {
      _pac_pageflush(uVar1 >> 8);
    }
  }
  return CONCAT44(param_1 + param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2458 start=0xf00a4a94 */

/* WARNING: Removing unreachable block (ram,0xf00a4ac0) */
/* WARNING: Removing unreachable block (ram,0xf00a4ae8) */
/* WARNING: Removing unreachable block (ram,0xf00a4ad4) */
/* WARNING: Removing unreachable block (ram,0xf00a4aa8) */
/* WARNING: Removing unreachable block (ram,0xf00a4af4) */

undefined8 _srmmu_tlbflush(int param_1,undefined4 param_2,undefined4 param_3)

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
  if (param_1 == 3) {
    _mmu_flushpagectx(param_2,param_3);
  }
  else if (param_1 == 2) {
    _mmu_flushseg(param_2,param_3);
  }
  else if (param_1 == 1) {
    _mmu_flushrgn(param_2,param_3);
  }
  else if (param_1 == 0) {
    _mmu_flushctx(param_3);
  }
  else {
    _panic(aSrmmuTlbflushB);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2459 start=0xf00a4b04 */

/* WARNING: Removing unreachable block (ram,0xf00a4b30) */
/* WARNING: Removing unreachable block (ram,0xf00a4b58) */
/* WARNING: Removing unreachable block (ram,0xf00a4b44) */
/* WARNING: Removing unreachable block (ram,0xf00a4b18) */
/* WARNING: Removing unreachable block (ram,0xf00a4b64) */

undefined8 _srmmu_vacflush(int param_1,undefined4 param_2,undefined4 param_3)

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
  if (param_1 == 3) {
    _vac_pagectxflush(param_2,param_3);
  }
  else if (param_1 == 2) {
    _vac_segflush(param_2,param_3);
  }
  else if (param_1 == 1) {
    _vac_rgnflush(param_2,param_3);
  }
  else if (param_1 == 0) {
    _vac_ctxflush(param_3);
  }
  else {
    _panic(aSrmmuVacflushB);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2460 start=0xf00a4b74 */

undefined8 _is_cacheable(uint param_1,undefined4 param_2)

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
  if ((param_1 < _econtig) &&
     (((param_1 < _contexts || (_kernel_seg_pools < param_1)) || (_mxcc != 0)))) {
    uVar1 = 0;
    if (0xefffffff < param_1) {
      uVar1 = (uint)(param_1 <= _econtig);
    }
  }
  else {
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2461 start=0xf00a4bf4 */

/* WARNING: Removing unreachable block (ram,0xf00a4dcc) */
/* WARNING: Removing unreachable block (ram,0xf00a4db0) */
/* WARNING: Removing unreachable block (ram,0xf00a4cd4) */
/* WARNING: Removing unreachable block (ram,0xf00a4c7c) */
/* WARNING: Removing unreachable block (ram,0xf00a4ca0) */
/* WARNING: Removing unreachable block (ram,0xf00a4d30) */
/* WARNING: Removing unreachable block (ram,0xf00a4dc4) */
/* WARNING: Removing unreachable block (ram,0xf00a4dd4) */
/* WARNING: Removing unreachable block (ram,0xf00a4c14) */

undefined8 _copy_page_tables(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 uVar7;
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
  uVar6 = 0xf0000;
  uVar4 = 0xf0000000;
  do {
    uVar1 = uVar4;
    _mmu_probe(uVar4,0);
    if ((uVar1 != 0) && ((uVar1 & 3) == 2)) {
      uVar7 = 7;
      uVar5 = uVar1 >> 7 & 1;
      if ((0xefffffff < uVar4) && (uVar4 <= _etext)) {
        uVar7 = 5;
      }
      if ((0xefffffff < uVar4) && (uVar4 <= _econtig)) {
        uVar5 = uVar4;
        _is_cacheable();
      }
      _pmap_map(uVar4,(uVar1 >> 8) << 0xc,uVar1 >> 0x1c,0x1000,uVar7,uVar5);
      if (((_viking != 0) && ((uVar1 & 0x80) != 0)) && (uVar5 == 0)) {
        _pac_pageflush(uVar1 >> 8);
      }
    }
    uVar6 = uVar6 + 1;
    uVar4 = uVar6 * 0x1000;
  } while (uVar6 < 0xfffff);
  uVar4 = 0xf0000;
  iVar2 = -0x10000000;
  do {
    *(int *)((int)register0x00000038 + -0xc) = iVar2;
    if (*(int *)(_kernel_region + (uint)*(byte *)((int)register0x00000038 + -0xc) * 4) == 0) {
      _pmap_expand(_kernel_pmap,iVar2,2);
    }
    uVar4 = uVar4 + 0x1000;
    iVar2 = uVar4 * 0x1000;
  } while (uVar4 < 0x100000);
  uVar6 = 0;
  uVar4 = _Nl1ptbl_addr >> 6;
  puVar3 = _contexts;
  if (_nctxs != 0) {
    do {
      *puVar3 = uVar4 << 2 | 1;
      uVar6 = uVar6 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar6 < _nctxs);
  }
  if (_vac != 0) {
    _vac_flush(_contexts,_econtig - (int)_contexts);
  }
  _mmu_setctp((_pcontexts >> 6) << 2);
  _mmu_flushall();
  _vac_flushall();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2462 start=0xf00a4de4 */

/* WARNING: Removing unreachable block (ram,0xf00a4e10) */
/* WARNING: Removing unreachable block (ram,0xf00a4e04) */

undefined8 _rminit(int *param_1,int param_2,int param_3,int param_4,int param_5)

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
  if (param_5 < 2) {
    _printf(aRminitMapXMaps,param_1,param_5);
    _panic(&aRminit);
  }
  param_1[param_5 * 2 + -1] = param_4;
  param_1[param_5 * 2 + -2] = 0;
  if (param_5 == 2) {
    *param_1 = 0;
  }
  else {
    *param_1 = param_5 + -3;
    param_1[2] = param_2;
    param_1[3] = param_3;
    param_1[4] = 0;
    if (param_2 == 0) {
      *param_1 = *param_1 + 1;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2463 start=0xf00a4e60 */

/* WARNING: Removing unreachable block (ram,0xf00a4e78) */

undefined8 _rmalloc(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
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
  piVar4 = param_1 + 2;
  if (param_2 < 1) {
    _panic(&aRmalloc);
  }
  if (param_1[2] != 0) {
    iVar1 = *piVar4;
    iVar2 = iVar1 - param_2;
    do {
      if (iVar2 < 0 == SBORROW4(iVar1,param_2)) {
        iVar1 = piVar4[1];
        iVar2 = *piVar4;
        piVar4[1] = iVar1 + param_2;
        *piVar4 = iVar2 - param_2;
        if (iVar2 - param_2 == 0) {
          piVar3 = piVar4 + 1;
          do {
            *piVar4 = piVar3[1];
            piVar4 = piVar4 + 2;
            *piVar3 = piVar3[2];
            piVar3 = piVar3 + 2;
          } while (*piVar4 != 0);
          *param_1 = *param_1 + 1;
        }
        goto locret_F00A4F0C;
      }
      piVar4 = piVar4 + 2;
      iVar1 = *piVar4;
      iVar2 = iVar1 - param_2;
    } while (iVar1 != 0);
  }
  iVar1 = 0;
locret_F00A4F0C:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2464 start=0xf00a4f14 */

/* WARNING: Removing unreachable block (ram,0xf00a5110) */
/* WARNING: Removing unreachable block (ram,0xf00a50a0) */
/* WARNING: Removing unreachable block (ram,0xf00a5120) */

undefined8 _rmfree(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 unaff_l0;
  uint *puVar5;
  uint *puVar6;
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
  if ((param_3 != 0) && (0 < (int)param_2)) {
    do {
      puVar4 = (uint *)(param_1 + 2);
      puVar6 = puVar4;
      if (param_3 < (uint)param_1[3]) {
loc_F00A4F64:
        iVar2 = (int)puVar6 - (int)puVar4;
      }
      else {
        uVar1 = *puVar4;
        puVar5 = puVar4;
        while (iVar2 = (int)puVar5 - (int)puVar4, puVar6 = puVar5, uVar1 != 0) {
          puVar6 = puVar5 + 2;
          if (param_3 < puVar5[3]) goto loc_F00A4F64;
          puVar5 = puVar6;
          uVar1 = *puVar6;
        }
      }
      if (iVar2 != 0) {
        uVar1 = puVar6[-1] + puVar6[-2];
        if (uVar1 < param_3) {
          uVar1 = *puVar6;
          goto loc_F00A5008;
        }
        if (param_3 < uVar1) break;
        uVar1 = puVar6[-2] + param_2;
        puVar6[-2] = uVar1;
        if (*puVar6 == 0) goto loc_F00A50FC;
        param_2 = param_3 + param_2;
        if (param_2 < puVar6[1]) {
          iVar2 = param_1[1];
          goto loc_F00A5100;
        }
        if (param_2 == puVar6[1]) {
          puVar6[-2] = uVar1 + *puVar6;
          if (*puVar6 != 0) {
            puVar4 = puVar6 + 1;
            do {
              *puVar6 = puVar4[1];
              puVar6 = puVar6 + 2;
              *puVar4 = puVar4[2];
              puVar4 = puVar4 + 2;
            } while (*puVar6 != 0);
          }
          iVar2 = *param_1 + 1;
          goto loc_F00A50F8;
        }
        break;
      }
      uVar1 = *puVar6;
loc_F00A5008:
      if (uVar1 == 0) {
        iVar2 = *param_1;
      }
      else {
        uVar1 = puVar6[1];
        if (uVar1 <= param_3 + param_2) {
          if (uVar1 < param_3 + param_2) break;
          puVar6[1] = uVar1 - param_2;
          *puVar6 = *puVar6 + param_2;
          goto loc_F00A50FC;
        }
        iVar2 = *param_1;
      }
      puVar4 = puVar6 + 1;
      if (iVar2 != 0) goto loc_F00A50CC;
      uVar1 = *puVar6;
      while (uVar1 != 0) {
        puVar6 = puVar6 + 2;
        uVar1 = *puVar6;
      }
      puVar4 = puVar6 + -2;
      if ((int)puVar6[-4] < (int)puVar6[-2]) {
        puVar4 = puVar6 + -4;
      }
      _printf(aSRmapOverflowL,puVar6[1],puVar4[1],puVar4[1] + *puVar4);
      *puVar4 = puVar4[2];
      puVar4[1] = puVar4[3];
      puVar4[2] = 0;
      *param_1 = *param_1 + 1;
    } while( true );
  }
  _panic(aBadRmfree);
locret_F00A5128:
  return CONCAT44(param_2,param_1);
loc_F00A50CC:
  do {
    uVar1 = *puVar4;
    *puVar4 = param_3;
    uVar3 = *puVar6;
    puVar4 = puVar4 + 2;
    *puVar6 = param_2;
    puVar6 = puVar6 + 2;
    param_2 = uVar3;
    param_3 = uVar1;
  } while (uVar3 != 0);
  iVar2 = *param_1 + -1;
  param_2 = 0;
loc_F00A50F8:
  *param_1 = iVar2;
loc_F00A50FC:
  iVar2 = param_1[1];
loc_F00A5100:
  if (iVar2 != 0) {
    param_1[1] = 0;
    _wakeup(param_1);
  }
  goto locret_F00A5128;
}
/* GHIDRADEC_FUNCTION index=2465 start=0xf00a5130 */

/* WARNING: Removing unreachable block (ram,0xf00a5144) */

undefined8 _rmget(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
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
  piVar3 = param_1 + 2;
  if (param_2 < 1) {
    _panic(&aRmget);
  }
  if (param_1[2] != 0) {
    uVar2 = param_1[3];
    piVar4 = piVar3;
    while( true ) {
      if ((uVar2 <= param_3) && (param_3 < uVar2 + *piVar4)) {
        iVar1 = *piVar4;
        goto loc_F00A5198;
      }
      piVar3 = piVar4 + 2;
      if (*piVar3 == 0) break;
      uVar2 = piVar4[3];
      piVar4 = piVar3;
    }
  }
  iVar1 = *piVar3;
  piVar4 = piVar3;
loc_F00A5198:
  if (iVar1 != 0) {
    uVar2 = piVar4[1];
    if (param_3 <= uVar2) {
      if (uVar2 == param_3) {
        if (iVar1 == param_2) {
          piVar3 = piVar4 + 1;
          do {
            *piVar4 = piVar3[1];
            piVar4 = piVar4 + 2;
            *piVar3 = piVar3[2];
            piVar3 = piVar3 + 2;
          } while (*piVar4 != 0);
          *param_1 = *param_1 + 1;
          goto locret_F00A52BC;
        }
        piVar4[1] = param_3 + param_2;
        iVar1 = *piVar4 - param_2;
      }
      else if (uVar2 + iVar1 == param_3 + param_2) {
        iVar1 = iVar1 - param_2;
      }
      else {
        piVar3 = piVar4;
        if (*param_1 == 0) goto loc_F00A5230;
        do {
          piVar5 = piVar3;
          piVar3 = piVar5 + 2;
        } while (piVar5[2] != 0);
        piVar5[4] = 0;
        if (piVar5 == piVar4) {
          iVar1 = *param_1;
        }
        else {
          piVar3 = piVar5 + 3;
          do {
            piVar3[-1] = *piVar5;
            *piVar3 = piVar3[-2];
            piVar5 = piVar5 + -2;
            piVar3 = piVar3 + -2;
          } while (piVar5 != piVar4);
          iVar1 = *param_1;
        }
        *param_1 = iVar1 + -1;
        piVar4[3] = param_3 + param_2;
        piVar4[2] = (piVar4[1] + *piVar4) - (param_3 + param_2);
        iVar1 = param_3 - piVar4[1];
      }
      *piVar4 = iVar1;
      goto locret_F00A52BC;
    }
  }
loc_F00A5230:
  param_3 = 0;
locret_F00A52BC:
  return CONCAT44(param_2,param_3);
}
/* GHIDRADEC_FUNCTION index=2466 start=0xf00a52c4 */

undefined8 _rm_avail(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
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
  bool bVar5;
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
  piVar3 = (int *)(param_1 + 8);
  iVar4 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    iVar2 = *piVar3;
    bVar5 = SBORROW4(0,iVar2);
    iVar1 = -iVar2;
    do {
      if (iVar1 < 0 != bVar5) {
        iVar4 = iVar2;
      }
      piVar3 = piVar3 + 2;
      iVar2 = *piVar3;
      bVar5 = SBORROW4(iVar4,iVar2);
      iVar1 = iVar4 - iVar2;
    } while (iVar2 != 0);
  }
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=2467 start=0xf00a5308 */

/* WARNING: Removing unreachable block (ram,0xf00a5334) */
/* WARNING: Removing unreachable block (ram,0xf00a535c) */
/* WARNING: Removing unreachable block (ram,0xf00a5324) */

undefined8 _startrtclock(undefined4 param_1,undefined4 param_2)

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
  if (_hz != 100) {
    _panic(aStartrtclock);
  }
  iVar1 = 1000000;
  .div(1000000,_hz);
  uRamfeffd000 = (iVar1 + 1) * 0x400 & 0x7ffffc00;
  _set_clk_mode(0x80000,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2468 start=0xf00a536c */

/* WARNING: Removing unreachable block (ram,0xf00a5518) */
/* WARNING: Removing unreachable block (ram,0xf00a5388) */

undefined8 _set_clk_mode(uint param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_l0;
  int iVar7;
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
  iVar7 = 4;
  if (_small_4m != 0) {
    iVar7 = 1;
  }
  iVar2 = _small_4m;
  _splaudio();
  param_1 = param_1 & ~_clk_state;
  param_2 = param_2 & _clk_state;
  _clk_state = _clk_state ^ param_1 ^ param_2;
  if ((param_2 & 0x80000) != 0) {
    _clk10_limit = uRamfeffd000;
    uRamfeffd000 = 0;
  }
  if ((param_2 & 0x80) != 0) {
    iVar5 = 0;
    _clk14_config = uRamfeffd010;
    if (iVar7 != 0) {
      iVar6 = 0;
      iVar3 = 0;
      do {
        iVar5 = iVar5 + 1;
        *(undefined4 *)(_clk14_lim + iVar3) = *(undefined4 *)(iVar6 + -0x1007000);
        iVar6 = iVar6 + 0x1000;
        iVar3 = iVar3 + 4;
      } while (iVar5 < iVar7);
    }
    iVar5 = 0;
    uRamfeffd010 = 0xf;
    if (iVar7 != 0) {
      puVar4 = (undefined4 *)0xfeff9000;
      do {
        puVar4[1] = 0;
        *puVar4 = 0x42900000;
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 0x400;
      } while (iVar5 < iVar7);
    }
  }
  if (iVar7 != 0) {
    iVar5 = 1;
    do {
      bVar1 = iVar5 < iVar7;
      iVar5 = iVar5 + 1;
    } while (bVar1);
  }
  if ((param_1 & 0x80000) != 0) {
    uRamfeffd000 = _clk10_limit;
  }
  iVar5 = 0;
  if (((param_1 & 0x80) != 0) && (uRamfeffd010 = _clk14_config, iVar7 != 0)) {
    iVar6 = 0;
    iVar3 = 0;
    do {
      iVar5 = iVar5 + 1;
      *(undefined4 *)(iVar3 + -0x1007000) = *(undefined4 *)(_clk14_lim + iVar6);
      iVar6 = iVar6 + 4;
      iVar3 = iVar3 + 0x1000;
    } while (iVar5 < iVar7);
  }
  _splx(iVar2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2469 start=0xf00a5528 */

/* WARNING: Removing unreachable block (ram,0xf00a5848) */
/* WARNING: Removing unreachable block (ram,0xf00a5818) */
/* WARNING: Removing unreachable block (ram,0xf00a57e4) */
/* WARNING: Removing unreachable block (ram,0xf00a57b0) */
/* WARNING: Removing unreachable block (ram,0xf00a577c) */
/* WARNING: Removing unreachable block (ram,0xf00a5748) */
/* WARNING: Removing unreachable block (ram,0xf00a5714) */
/* WARNING: Removing unreachable block (ram,0xf00a56dc) */
/* WARNING: Removing unreachable block (ram,0xf00a56a4) */
/* WARNING: Removing unreachable block (ram,0xf00a5688) */
/* WARNING: Removing unreachable block (ram,0xf00a566c) */
/* WARNING: Removing unreachable block (ram,0xf00a554c) */
/* WARNING: Removing unreachable block (ram,0xf00a5540) */
/* WARNING: Removing unreachable block (ram,0xf00a565c) */
/* WARNING: Removing unreachable block (ram,0xf00a5678) */
/* WARNING: Removing unreachable block (ram,0xf00a5694) */
/* WARNING: Removing unreachable block (ram,0xf00a56bc) */
/* WARNING: Removing unreachable block (ram,0xf00a56f0) */
/* WARNING: Removing unreachable block (ram,0xf00a5728) */
/* WARNING: Removing unreachable block (ram,0xf00a575c) */
/* WARNING: Removing unreachable block (ram,0xf00a5790) */
/* WARNING: Removing unreachable block (ram,0xf00a57c4) */
/* WARNING: Removing unreachable block (ram,0xf00a57f8) */
/* WARNING: Removing unreachable block (ram,0xf00a582c) */
/* WARNING: Removing unreachable block (ram,0xf00a5850) */
/* WARNING: Removing unreachable block (ram,0xf00a552c) */

undefined8 _set_tod(uint param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar9;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar10;
  undefined4 unaff_i2;
  uint uVar11;
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
  uVar11 = 2;
  uVar2 = param_1;
  _splusclock();
  uVar10 = param_1;
  .div(param_1,0x15180);
  iVar3 = uVar10 + 2;
  .rem(iVar3,7);
  while (0x1e13380 < param_1) {
    while( true ) {
      iVar4 = -0x1e28500;
      if ((uVar11 & 3) != 0) {
        iVar4 = -0x1e13380;
      }
      param_1 = param_1 + iVar4;
      uVar11 = uVar11 + 1;
      if ((uVar11 & 3) != 0) break;
      if (param_1 < 0x1e28501) goto loc_F00A55BC;
    }
  }
loc_F00A55BC:
  uVar10 = 1;
  if (-1 < (int)param_1) {
    do {
      if (((uVar11 & 3) != 0) || (iVar4 = -0x263b80, (uVar10 & 0xffff) != 2)) {
        iVar4 = -(&_clk_state)[uVar10 & 0xffff];
      }
      param_1 = param_1 + iVar4;
      uVar10 = uVar10 + 1;
    } while (-1 < (int)param_1);
  }
  uVar10 = uVar10 - 1;
  if (((uVar11 & 3) == 0) && ((uVar10 & 0xffff) == 2)) {
    iVar4 = 0x263b80;
  }
  else {
    iVar4 = (&_clk_state)[uVar10 & 0xffff];
  }
  param_1 = param_1 + iVar4;
  uVar7 = param_1;
  .rem(param_1,0x3c);
  .div(param_1,0x3c);
  uVar8 = param_1;
  .rem();
  .div(param_1,0x3c);
  uVar9 = param_1;
  .rem();
  uVar5 = param_1;
  .div(param_1,0x18);
  _pmap_change_prot(0xfefffff8,7);
  bVar1 = bRamfefffff8;
  uVar7 = uVar7 & 0xffff;
  bRamfefffff8 = bRamfefffff8 | 0x80;
  uVar6 = uVar7;
  .udiv(uVar7,10);
  .urem(uVar7,10);
  bRamfefffff9 = (char)uVar7 + (char)uVar6 * '\x10' & 0x7f;
  uVar8 = uVar8 & 0xffff;
  uVar7 = uVar8;
  .udiv(uVar8,10);
  .urem(uVar8,10);
  bRamfefffffa = (char)uVar8 + (char)uVar7 * '\x10' & 0x7f;
  uVar9 = uVar9 & 0xffff;
  uVar7 = uVar9;
  .udiv(uVar9,10);
  .urem(uVar9,10);
  bRamfefffffb = (char)uVar9 + (char)uVar7 * '\x10' & 0x3f;
  uVar7 = iVar3 + 1U & 0xffff;
  .udiv(uVar7,10);
  .urem(uVar7,10);
  bRamfefffffc = (byte)uVar7 & 7;
  uVar8 = uVar5 + 1 & 0xffff;
  uVar7 = uVar8;
  .udiv(uVar8,10);
  .urem(uVar8,10);
  bRamfefffffd = (char)uVar8 + (char)uVar7 * '\x10' & 0x3f;
  uVar8 = uVar10 & 0xffff;
  uVar7 = uVar8;
  .udiv(uVar8,10);
  .urem(uVar8,10);
  bRamfefffffe = (char)uVar8 + (char)uVar7 * '\x10' & 0x1f;
  uVar11 = uVar11 & 0xffff;
  uVar7 = uVar11;
  .udiv(uVar11,10);
  .urem(uVar11,10);
  cRamfeffffff = (char)uVar11 + (char)uVar7 * '\x10';
  bRamfefffff8 = bVar1 & 0x7f;
  _pmap_change_prot(0xfefffff8,1);
  _splx(uVar2);
  return CONCAT44(uVar10,param_1);
}
/* GHIDRADEC_FUNCTION index=2470 start=0xf00a5860 */

/* WARNING: Removing unreachable block (ram,0xf00a5970) */
/* WARNING: Removing unreachable block (ram,0xf00a5870) */
/* WARNING: Removing unreachable block (ram,0xf00a5a04) */

undefined8 _get_tod(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar7;
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
  puVar7 = *(undefined4 **)((int)register0x00000038 + 0x40);
  _pmap_change_prot(0xfefffff8,7);
  *(byte *)((int)register0x00000038 + -0x17) =
       (bRamfefffff9 & 0xf) + (char)((bRamfefffff9 & 0x7f) >> 4) * '\n';
  *(byte *)((int)register0x00000038 + -0x16) =
       (bRamfefffffa & 0xf) + (char)((bRamfefffffa & 0x7f) >> 4) * '\n';
  *(byte *)((int)register0x00000038 + -0x15) =
       (bRamfefffffb & 0xf) + (char)((bRamfefffffb & 0x3f) >> 4) * '\n';
  *(byte *)((int)register0x00000038 + -0x14) = bRamfefffffc & 7;
  *(byte *)((int)register0x00000038 + -0x13) =
       (bRamfefffffd & 0xf) + (char)((bRamfefffffd & 0x3f) >> 4) * '\n';
  bRamfefffff8 = bRamfefffff8 & 0xbf;
  *(byte *)((int)register0x00000038 + -0x12) =
       (bRamfefffffe & 0xf) + (char)((bRamfefffffe & 0x1f) >> 4) * '\n';
  *(byte *)((int)register0x00000038 + -0x11) = (bRamfeffffff & 0xf) + (bRamfeffffff >> 4) * '\n';
  _pmap_change_prot(0xfefffff8,1);
  iVar6 = 0;
  if ((((*(byte *)((int)register0x00000038 + -0x12) == 0) ||
       (0xc < *(byte *)((int)register0x00000038 + -0x12))) ||
      (*(byte *)((int)register0x00000038 + -0x13) == 0)) ||
     (((0x1f < *(byte *)((int)register0x00000038 + -0x13) ||
       (0x3b < *(byte *)((int)register0x00000038 + -0x16))) ||
      ((0x3b < *(byte *)((int)register0x00000038 + -0x17) ||
       (*(byte *)((int)register0x00000038 + -0x11) < 2)))))) {
    *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    *puVar7 = 0;
  }
  else {
    iVar4 = 2;
    if (2 < *(byte *)((int)register0x00000038 + -0x11)) {
      iVar6 = 0x1e13380;
      iVar4 = 3;
    }
    iVar3 = 1;
    bVar1 = *(byte *)((int)register0x00000038 + -0x13);
    if (1 < *(byte *)((int)register0x00000038 + -0x12)) {
      iVar5 = 4;
      do {
        if (iVar4 == 0) {
          iVar2 = 0x263b80;
          if (iVar3 != 2) {
            iVar2 = *(int *)((int)&_clk_state + iVar5);
          }
        }
        else {
          iVar2 = *(int *)((int)&_clk_state + iVar5);
        }
        iVar6 = iVar6 + iVar2;
        iVar3 = iVar3 + 1;
        iVar5 = iVar5 + 4;
      } while (iVar3 < (int)(uint)*(byte *)((int)register0x00000038 + -0x12));
      bVar1 = *(byte *)((int)register0x00000038 + -0x13);
    }
    iVar6 = iVar6 + (bVar1 - 1) * 0x15180 + (uint)*(byte *)((int)register0x00000038 + -0x15) * 0xe10
            + (uint)*(byte *)((int)register0x00000038 + -0x16) * 0x3c +
            (uint)*(byte *)((int)register0x00000038 + -0x17);
    if (iVar6 < 0) {
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    }
    else {
      *(int *)((int)register0x00000038 + -0x10) = iVar6;
    }
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    *puVar7 = *(undefined4 *)((int)register0x00000038 + -0x10);
  }
  puVar7[1] = *(undefined4 *)((int)register0x00000038 + -0xc);
  return CONCAT44(param_2,puVar7);
}
/* GHIDRADEC_FUNCTION index=2471 start=0xf00a5b08 */

/* WARNING: Removing unreachable block (ram,0xf00a5b48) */

undefined8 _init_mon_clock(undefined4 param_1,undefined4 param_2)

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
  _kclock14_vec = 0xa1480000;
  _mon_clock_on._0_1_ = 0;
  DAT_f010a004._0_4_ = 0x273c000c;
  DAT_f010a004._4_4_ = 0x81c4e170;
  DAT_f010a004._8_4_ = 0xa810210e;
  _set_clk_mode(0,0x80);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2472 start=0xf00a5b58 */

/* WARNING: Removing unreachable block (ram,0xf00a5b88) */
/* WARNING: Removing unreachable block (ram,0xf00a5b7c) */

undefined8 _start_mon_clock(undefined4 param_1,undefined4 param_2)

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
  if (_mon_clock_on._0_1_ == '\0') {
    _mon_clock_on._0_1_ = '\x01';
    _write_scb_int(0xe,_mon_clock14_vec);
    _set_clk_mode(0x80,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2473 start=0xf00a5b98 */

/* WARNING: Removing unreachable block (ram,0xf00a5bc4) */
/* WARNING: Removing unreachable block (ram,0xf00a5bb4) */

undefined8 _stop_mon_clock(undefined4 param_1,undefined4 param_2)

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
  if (_mon_clock_on._0_1_ != '\0') {
    _mon_clock_on._0_1_ = '\0';
    _set_clk_mode(0,0x80);
    _write_scb_int(0xe,&_kclock14_vec);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2474 start=0xf00a5bd4 */

/* WARNING: Removing unreachable block (ram,0xf00a5c20) */
/* WARNING: Removing unreachable block (ram,0xf00a5bf4) */
/* WARNING: Removing unreachable block (ram,0xf00a5c28) */
/* WARNING: Removing unreachable block (ram,0xf00a5bd8) */

undefined8 _write_scb_int(int param_1,undefined4 *param_2)

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
  iVar1 = param_1 * 0x10;
  _spl8();
  _pmap_change_prot(&loc_F0002100 + iVar1,7);
  *(undefined4 *)(&loc_F0002100 + iVar1) = *param_2;
  *(undefined4 *)(iVar1 + -0xfffdefc) = param_2[1];
  *(undefined4 *)(iVar1 + -0xfffdef8) = param_2[2];
  *(undefined4 *)(iVar1 + -0xfffdef4) = param_2[3];
  _pmap_change_prot(&loc_F0002100 + iVar1,1);
  _splx(param_1);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2475 start=0xf00a5c38 */

/* WARNING: Removing unreachable block (ram,0xf00a5c88) */
/* WARNING: Removing unreachable block (ram,0xf00a5cdc) */
/* WARNING: Removing unreachable block (ram,0xf00a5c44) */

undefined8 _flush_user_windows_to_stack(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  int iVar5;
  int iVar6;
  undefined4 unaff_l3;
  int iVar7;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  int iVar9;
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
  iVar7 = *(int *)(_active_threads + 0x28);
  _flush_user_windows();
  iVar8 = *(int *)(iVar7 + 0x230);
  if (0 < iVar8) {
    param_1 = iVar8 * 0x40 + -0x30;
    iVar9 = iVar8 * 4 + iVar7;
    while( true ) {
      iVar8 = iVar8 + -1;
      if ((*(uint *)(iVar9 + 0x20c) & 7) == 0) {
        iVar1 = iVar7 + param_1;
        _copyout(iVar1,*(uint *)(iVar9 + 0x20c),0x40);
        if ((iVar1 == 0) &&
           (iVar1 = *(int *)(iVar7 + 0x230) + -1, *(int *)(iVar7 + 0x230) = iVar1, iVar8 < iVar1)) {
          iVar6 = iVar8 * 0x40 + 0x10;
          iVar5 = iVar8 * 0x40 + 0x50;
          iVar4 = iVar8 * 4 + iVar7;
          iVar1 = iVar8;
          do {
            iVar2 = iVar7 + iVar5;
            iVar3 = iVar7 + iVar6;
            iVar6 = iVar6 + 0x40;
            iVar5 = iVar5 + 0x40;
            iVar1 = iVar1 + 1;
            *(undefined4 *)(iVar4 + 0x210) = *(undefined4 *)(iVar4 + 0x214);
            _bcopy(iVar2,iVar3,0x40);
            iVar4 = iVar4 + 4;
          } while (iVar1 < *(int *)(iVar7 + 0x230));
        }
      }
      if (iVar8 < 1) break;
      param_1 = param_1 + -0x40;
      iVar9 = iVar9 + -4;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2476 start=0xf00a5d08 */

/* WARNING: Removing unreachable block (ram,0xf00a5e6c) */
/* WARNING: Removing unreachable block (ram,0xf00a5e48) */
/* WARNING: Removing unreachable block (ram,0xf00a5e30) */
/* WARNING: Removing unreachable block (ram,0xf00a5e14) */
/* WARNING: Removing unreachable block (ram,0xf00a5de4) */
/* WARNING: Removing unreachable block (ram,0xf00a5e00) */
/* WARNING: Removing unreachable block (ram,0xf00a5e20) */
/* WARNING: Removing unreachable block (ram,0xf00a5e3c) */
/* WARNING: Removing unreachable block (ram,0xf00a5e5c) */
/* WARNING: Removing unreachable block (ram,0xf00a5ea4) */
/* WARNING: Removing unreachable block (ram,0xf00a5dcc) */

undefined8 _process_aflt(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 uVar5;
  undefined4 unaff_l1;
  undefined4 uVar6;
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
  bool bVar7;
  bool bVar8;
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
  if (*(int *)((int)&_a_head + _cpuid * 4) != *(int *)((int)&_a_tail + _cpuid * 4)) {
    do {
      iVar4 = _cpuid;
      bVar8 = false;
      uVar1 = *(int *)((int)&_a_tail + _cpuid * 4) + 1U & 0x3f;
      *(uint *)((int)&_a_tail + _cpuid * 4) = uVar1;
      iVar4 = uVar1 * 0x18 + iVar4 * 0x600;
      uVar1 = *(uint *)(_a_flts + iVar4 + 4);
      uVar5 = *(undefined4 *)(_a_flts + iVar4 + 8);
      uVar6 = *(undefined4 *)(_a_flts + iVar4 + 0xc);
      if (*(sword *)(_a_flts + iVar4) == 2) {
        bVar8 = (uVar1 & 1) != 0;
        _log_mem_err(uVar1,uVar5,uVar6,0);
        if ((uVar1 & 8) == 0) goto loc_F00A5E74;
        uVar2 = uVar1;
        _fix_nc_ecc(uVar1,uVar5,uVar6);
        bVar7 = !bVar8;
        if (uVar2 == 0xffffffff) {
          _printf(aAfsr0xX,uVar1);
          _printf(aAfar00xXAfar10,uVar5,uVar6);
          _panic(aAsynchronousFa);
          bVar7 = !bVar8;
        }
      }
      else if (*(sword *)(_a_flts + iVar4) == 4) {
        _printf(aMToSAsynchrono);
        _printf(aDueToUserWrite);
        _log_mtos_err(uVar1,uVar5);
        _psignal(*_active_u,10);
        _exception(1,0x309,uVar5);
loc_F00A5E74:
        bVar7 = !bVar8;
      }
      else {
        bVar7 = true;
      }
      if (bVar7) {
        puVar3 = aAfsr0xXAfar00x;
loc_F00A5E9C:
        _printf(puVar3,uVar1,uVar5,uVar6);
      }
      else if (_log_ce_error != 0) {
        puVar3 = aAfsr0xXAfar00x_0;
        goto loc_F00A5E9C;
      }
      _log_ce_error = 0;
    } while (*(int *)((int)&_a_head + _cpuid * 4) != *(int *)((int)&_a_tail + _cpuid * 4));
  }
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=2477 start=0xf00a5ed8 */

/* WARNING: Removing unreachable block (ram,0xf00a60b8) */
/* WARNING: Removing unreachable block (ram,0xf00a6098) */
/* WARNING: Removing unreachable block (ram,0xf00a6080) */
/* WARNING: Removing unreachable block (ram,0xf00a605c) */
/* WARNING: Removing unreachable block (ram,0xf00a602c) */
/* WARNING: Removing unreachable block (ram,0xf00a6004) */
/* WARNING: Removing unreachable block (ram,0xf00a60cc) */
/* WARNING: Removing unreachable block (ram,0xf00a5f78) */
/* WARNING: Removing unreachable block (ram,0xf00a5f44) */
/* WARNING: Removing unreachable block (ram,0xf00a5f14) */
/* WARNING: Removing unreachable block (ram,0xf00a5f2c) */
/* WARNING: Removing unreachable block (ram,0xf00a5f5c) */
/* WARNING: Removing unreachable block (ram,0xf00a5fc4) */
/* WARNING: Removing unreachable block (ram,0xf00a60e4) */
/* WARNING: Removing unreachable block (ram,0xf00a6018) */
/* WARNING: Removing unreachable block (ram,0xf00a6050) */
/* WARNING: Removing unreachable block (ram,0xf00a6070) */
/* WARNING: Removing unreachable block (ram,0xf00a608c) */
/* WARNING: Removing unreachable block (ram,0xf00a60ac) */
/* WARNING: Removing unreachable block (ram,0xf00a60f0) */
/* WARNING: Removing unreachable block (ram,0xf00a5f0c) */

undefined8 _sun4m_l15_async_fault(uint param_1,undefined4 param_2)

{
  word wVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
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
  if (_nofault != 0) {
    _pokefault = 1;
  }
  if ((param_1 & 0x78000000) == 0) {
    _printf(aLevel15ErrorWa);
    _prom_stopcpu(0);
  }
  if ((param_1 & 0x10000000) != 0) {
    _l15_ecc_async_flt();
  }
  if ((param_1 & 0x20000000) != 0) {
    _l15_mts_async_flt();
  }
  if ((param_1 & 0x40000000) != 0) {
    _simple_lock_try(&_module_error);
  }
  if (_module_error != 0) {
    _l15_mod_async_flt();
  }
  uVar6 = DAT_f013ec78._12_4_;
  uVar5 = DAT_f013ec78._8_4_;
  uVar4 = DAT_f013ec78._4_4_;
  uVar3 = DAT_f013ec78._0_4_;
  uVar2 = dword_F013EC74;
  wVar1 = _sys_fatal_flt;
  if ((_nofault != 0) || (_system_fatal == 0)) goto locret_F00A6100;
  _printf(aFatalSystemFau,param_1);
  if (wVar1 == 2) {
    _log_ce_error = 1;
    _log_mem_err(uVar2,uVar3,uVar4,0);
    _printf(aControlRegiste);
    _printf(aEfsr0xXEfar00x,uVar2,uVar3);
    _printf(aEfar10xX,uVar4);
    _panic(aMemoryError);
loc_F00A6098:
    _printf(aAsyncFaultFrom_0);
    _printf(aAfsrXAfarX_0,uVar2,uVar3);
    _log_mtos_err(uVar2,uVar3);
  }
  else {
    if (2 < wVar1) {
      if (wVar1 != 4) goto loc_F00A60C8;
      goto loc_F00A6098;
    }
    if (wVar1 == 1) {
      _printf(aAsyncFaultFrom);
      _printf(aAfsrXAfarX,uVar2,uVar3);
      _mmu_log_module_err(uVar2,uVar3,uVar5,uVar6);
    }
    else {
loc_F00A60C8:
      _printf(aUnknownFaultTy,wVar1);
      _printf(aAfsrXAfarXX,uVar2,uVar3,uVar4);
    }
  }
  _panic(aFatalAsynchron);
  _system_fatal = 0;
locret_F00A6100:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2478 start=0xf00a6108 */

/* WARNING: Removing unreachable block (ram,0xf00a61ac) */
/* WARNING: Removing unreachable block (ram,0xf00a617c) */
/* WARNING: Removing unreachable block (ram,0xf00a6170) */
/* WARNING: Removing unreachable block (ram,0xf00a61a0) */
/* WARNING: Removing unreachable block (ram,0xf00a61b8) */
/* WARNING: Removing unreachable block (ram,0xf00a6128) */

undefined8 _p4m35_l15_async_fault(undefined4 param_1,undefined4 param_2)

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
  if ((uRamfeff8000 & 0x40000000) == 0) {
    _panic(aUnknownLevel15);
  }
  if (_pokefault == -1) {
    _pokefault = 1;
  }
  else {
    if ((uRamfefea050 & 0x80000000) != 0) {
      _printf(aAsyncMemoryFau,uRamfefea050,uRamfefea054);
      _panic(aAsyncMemoryFau_0);
    }
    if ((uRamfefea000 & 0x80000000) != 0) {
      _printf(aAsyncFaultAfsr,uRamfefea000,uRamfefea004);
      _panic(aAsyncHardwareF);
    }
    _panic(aUnknownAsyncFa);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2479 start=0xf00a61c8 */

/* WARNING: Removing unreachable block (ram,0xf00a62b8) */
/* WARNING: Removing unreachable block (ram,0xf00a61dc) */
/* WARNING: Removing unreachable block (ram,0xf00a61d4) */
/* WARNING: Removing unreachable block (ram,0xf00a6230) */
/* WARNING: Removing unreachable block (ram,0xf00a62ac) */
/* WARNING: Removing unreachable block (ram,0xf00a61cc) */

undefined8 _l15_ecc_async_flt(uint param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
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
  uVar1 = param_1;
  _get_efsr_vaddr();
  uVar2 = uVar1;
  _get_efar0_vaddr();
  uVar3 = uVar2;
  _get_efar1_vaddr();
  uRamfefef008 = 0;
  if (_nofault != 0) goto locret_F00A62F0;
  if ((_cpu == 0x72) && ((uVar1 & 0x20002) != 0)) {
    puVar4 = &_system_fatal;
    _simple_lock_try();
    if (puVar4 == (undefined4 *)0x0) {
      _sys_fatal_flt = 2;
      DAT_f013ec72 = 0;
      DAT_f013ec78._8_4_ = 0;
      DAT_f013ec78._12_4_ = 0;
      dword_F013EC74 = uVar1;
      DAT_f013ec78._0_4_ = uVar2;
      DAT_f013ec78._4_4_ = uVar3;
    }
    goto locret_F00A62F0;
  }
  if ((uVar1 & 8) == 0) {
    if ((uVar1 & 1) == 0) goto loc_F00A62B8;
  }
  else if ((uVar2 & 0x8000000) != 0) {
loc_F00A62B8:
    puVar4 = &_system_fatal;
    _simple_lock_try();
    if (puVar4 == (undefined4 *)0x0) {
      _sys_fatal_flt = 2;
      DAT_f013ec72 = 0;
      DAT_f013ec78._8_4_ = 0;
      DAT_f013ec78._12_4_ = 0;
      dword_F013EC74 = uVar1;
      DAT_f013ec78._0_4_ = uVar2;
      DAT_f013ec78._4_4_ = uVar3;
    }
    goto locret_F00A62F0;
  }
  _handle_aflt(_cpuid,2,uVar1,uVar2,uVar3);
locret_F00A62F0:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2480 start=0xf00a62f8 */

/* WARNING: Removing unreachable block (ram,0xf00a6330) */
/* WARNING: Removing unreachable block (ram,0xf00a6380) */

undefined8 _l15_mts_async_flt(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
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
  
  uVar2 = uRamfefea004;
  uVar1 = uRamfefea000;
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
  uRamfefea000 = 0;
  if (_nofault == 0) {
    if ((uVar1 & 0x1080000) == 0) {
      _handle_aflt(_cpuid,4,uVar1,uRamfefea004,0);
    }
    else {
      puVar3 = &_system_fatal;
      _simple_lock_try();
      if (puVar3 == (undefined4 *)0x0) {
        _sys_fatal_flt = 4;
        DAT_f013ec72 = 0;
        dword_F013EC74 = uVar1;
        DAT_f013ec78._0_4_ = uVar2;
        DAT_f013ec78._4_4_ = 0;
        DAT_f013ec78._8_4_ = 0;
        DAT_f013ec78._12_4_ = 0;
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2481 start=0xf00a6390 */

/* WARNING: Removing unreachable block (ram,0xf00a6424) */
/* WARNING: Removing unreachable block (ram,0xf00a64f0) */
/* WARNING: Removing unreachable block (ram,0xf00a63b4) */
/* WARNING: Removing unreachable block (ram,0xf00a63ac) */
/* WARNING: Removing unreachable block (ram,0xf00a6484) */
/* WARNING: Removing unreachable block (ram,0xf00a63fc) */
/* WARNING: Removing unreachable block (ram,0xf00a653c) */
/* WARNING: Removing unreachable block (ram,0xf00a6394) */

undefined8 _l15_mod_async_flt(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  bool bVar3;
  undefined4 unaff_l0;
  uint uVar4;
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
  iVar1 = param_1;
  _mmu_chk_wdreset();
  if (iVar1 != 0) {
    _prom_stopcpu(0);
  }
  _mmu_getasyncflt((undefined *)((int)register0x00000038 + -0x18));
  bVar3 = true;
  if (_mod_info != 0x40) {
    uVar4 = *(uint *)((int)register0x00000038 + -0x18);
    if (_mod_info == 0x41) {
      uVar4 = *(uint *)((int)register0x00000038 + -0x10);
      if ((uVar4 == 0xffffffff) ||
         (uVar5 = *(undefined4 *)((int)register0x00000038 + -0xc), (uVar4 & 0x2000000) == 0))
      goto loc_F00A6530;
      iVar1 = *(int *)((int)register0x00000038 + -0x18);
      _vac_parity_chk_dis(iVar1,uVar4);
      if ((_nofault != 0) && (bVar3 = false, iVar1 == 0)) goto loc_F00A6530;
      puVar2 = &_system_fatal;
      _simple_lock_try();
      bVar3 = false;
      if (puVar2 != (undefined4 *)0x0) goto loc_F00A6530;
      _sys_fatal_flt = 1;
      DAT_f013ec72 = 0;
      DAT_f013ec78._4_4_ = 0;
      DAT_f013ec78._8_4_ = 0;
      DAT_f013ec78._12_4_ = 0;
      dword_F013EC74 = uVar4;
      DAT_f013ec78._0_4_ = uVar5;
    }
    else {
      if ((uVar4 & 1) != 0) {
        uVar5 = *(undefined4 *)((int)register0x00000038 + -0x14);
        if (_nofault == 0) {
          puVar2 = &_system_fatal;
          _simple_lock_try();
          bVar3 = false;
          if (puVar2 != (undefined4 *)0x0) goto loc_F00A64C4;
          _sys_fatal_flt = 1;
          DAT_f013ec72 = 0;
          DAT_f013ec78._4_4_ = 0;
          DAT_f013ec78._8_4_ = 0;
          DAT_f013ec78._12_4_ = 0;
          dword_F013EC74 = uVar4;
          DAT_f013ec78._0_4_ = uVar5;
        }
        bVar3 = false;
      }
loc_F00A64C4:
      uVar4 = *(uint *)((int)register0x00000038 + -0x10);
      if ((uVar4 == 0xffffffff) || ((uVar4 & 1) == 0)) goto loc_F00A6530;
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0xc);
      if (_nofault == 0) {
        puVar2 = &_system_fatal;
        _simple_lock_try();
        bVar3 = false;
        if (puVar2 != (undefined4 *)0x0) goto loc_F00A6530;
        _sys_fatal_flt = 1;
        DAT_f013ec72 = 1;
        DAT_f013ec78._4_4_ = 0;
        DAT_f013ec78._8_4_ = 0;
        DAT_f013ec78._12_4_ = 0;
        dword_F013EC74 = uVar4;
        DAT_f013ec78._0_4_ = uVar5;
      }
    }
  }
  bVar3 = false;
loc_F00A6530:
  if (bVar3) {
    _prom_stopcpu(0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2482 start=0xf00a654c */

undefined8 _send_dirint(int param_1,int param_2)

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
  *(int *)(param_1 * 0x1000 + -0x100bff8) = 1 << ((byte)(param_2 + 0x10) & 0x1f);
  return CONCAT44(param_2 + 0x10,param_1 * 0x1000 + -0x100c000);
}
/* GHIDRADEC_FUNCTION index=2483 start=0xf00a6574 */

undefined8 _clr_dirint(int param_1,int param_2)

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
  *(int *)(param_1 * 0x1000 + -0x100bffc) = 1 << ((byte)(param_2 + 0x10) & 0x1f);
  return CONCAT44(param_2 + 0x10,param_1 * 0x1000 + -0x100c000);
}
/* GHIDRADEC_FUNCTION index=2484 start=0xf00a659c */

/* WARNING: Removing unreachable block (ram,0xf00a6620) */
/* WARNING: Removing unreachable block (ram,0xf00a65dc) */

undefined8
_handle_aflt(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  uint uVar1;
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
  iVar2 = param_1 * 4;
  uVar1 = *(int *)((int)&_a_head + iVar2) + 1U & 0x3f;
  *(uint *)((int)&_a_head + iVar2) = uVar1;
  if (uVar1 == *(uint *)((int)&_a_tail + iVar2)) {
    _panic(aOverflowOfAsyn);
  }
  iVar2 = uVar1 * 0x18 + param_1 * 0x600;
  *(sword *)(_a_flts + iVar2) = (sword)param_2;
  *(undefined4 *)(_a_flts + iVar2 + 4) = param_3;
  *(undefined4 *)(_a_flts + iVar2 + 8) = param_4;
  *(undefined4 *)(_a_flts + iVar2 + 0xc) = param_5;
  _send_dirint(param_1,0xc);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2485 start=0xf00a6630 */

/* WARNING: Removing unreachable block (ram,0xf00a670c) */
/* WARNING: Removing unreachable block (ram,0xf00a669c) */
/* WARNING: Removing unreachable block (ram,0xf00a666c) */
/* WARNING: Removing unreachable block (ram,0xf00a6684) */
/* WARNING: Removing unreachable block (ram,0xf00a66b4) */
/* WARNING: Removing unreachable block (ram,0xf00a6740) */
/* WARNING: Removing unreachable block (ram,0xf00a6644) */

undefined8 _log_mtos_err(uint param_1,uint param_2)

{
  undefined *puVar1;
  undefined6 *puVar2;
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
  if ((param_1 & 0x80000) != 0) {
    _printf(aMultipleErrors_0);
  }
  if ((param_1 & 0x1000000) == 0) {
    puVar1 = aErrorDuringUse;
  }
  else {
    puVar1 = aErrorDuringSup;
  }
  _printf(puVar1);
  if ((param_1 & 0x40000000) != 0) {
    _printf(aLateError);
  }
  if ((param_1 & 0x20000000) != 0) {
    _printf(aTimeoutError_0);
  }
  if ((param_1 & 0x10000000) != 0) {
    _printf(aBusError_0);
  }
  if ((param_1 & 0x1000000) == 0) {
    puVar2 = &aUser_4;
  }
  else {
    puVar2 = &aSupv_3;
  }
  _printf(aRequestedTrans_0,puVar2,*(undefined4 *)(_nameof_siz + (param_1 >> 0x17 & 0x1c)),
          param_1 & 0xf,param_2,param_1 >> 0x14 & 0xf);
  _printf(aSpecificCycleS,*(undefined4 *)(_nameof_ssiz + ((param_1 & 0xe00) >> 7)),param_1 & 0xf,
          param_2 & 0xffffffe0 | param_1 >> 0xc & 0x1f);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2486 start=0xf00a6750 */

/* WARNING: Removing unreachable block (ram,0xf00a6974) */
/* WARNING: Removing unreachable block (ram,0xf00a6940) */
/* WARNING: Removing unreachable block (ram,0xf00a68fc) */
/* WARNING: Removing unreachable block (ram,0xf00a68c0) */
/* WARNING: Removing unreachable block (ram,0xf00a68a4) */
/* WARNING: Removing unreachable block (ram,0xf00a67f8) */
/* WARNING: Removing unreachable block (ram,0xf00a67e0) */
/* WARNING: Removing unreachable block (ram,0xf00a687c) */
/* WARNING: Removing unreachable block (ram,0xf00a68b0) */
/* WARNING: Removing unreachable block (ram,0xf00a68cc) */
/* WARNING: Removing unreachable block (ram,0xf00a6930) */
/* WARNING: Removing unreachable block (ram,0xf00a69d8) */
/* WARNING: Removing unreachable block (ram,0xf00a6958) */
/* WARNING: Removing unreachable block (ram,0xf00a6834) */

undefined8 _log_ce_mem_err(uint param_1,uint param_2,uint param_3,code *param_4)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  uint uVar7;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar9;
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
  uVar4 = (param_2 & 0x700) >> 8;
  iVar8 = 0;
  uVar7 = (uint)(char)_ecc_syndrome_tab[(param_1 & 0xff00) >> 8];
  puVar9 = (undefined *)((param_1 & 0xf0) >> 4);
  if ((uVar4 < 6) && (3 < uVar4)) {
    iVar8 = (int)puVar9 << 3;
  }
  if (uVar7 < 0x48) {
    uVar4 = uVar7 >> 3;
    if (0x3f < uVar7) {
      uVar4 = uVar7 & 7;
    }
    iVar8 = (iVar8 + 7) - uVar4;
    iVar1 = (param_3 & 0xfffffff8) + iVar8;
    (*param_4)(iVar1,param_2 & 0xf);
    if (iVar1 == 0) {
      _printf(aSimmDecodeFunc);
    }
  }
  else {
    iVar6 = 0;
    iVar2 = (param_3 & 0xfffffff8) + iVar8;
    iVar5 = iVar2;
    do {
      iVar1 = iVar5;
      (*param_4)(iVar1,param_2 & 0xf);
      if (iVar1 == 0) {
        _printf(aSimmDecodeFunc_1);
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar2 + iVar6;
    } while (iVar6 < 8);
  }
  iVar6 = 0;
  iVar5 = 0;
  do {
    if (_mem_ce_simm[iVar5] == '\0') {
      _strcpy(_mem_ce_simm + iVar5,iVar1);
      *(int *)(_mem_ce_simm + iVar5 + 8) = *(int *)(_mem_ce_simm + iVar5 + 8) + 1;
      break;
    }
    puVar9 = _mem_ce_simm + iVar5;
    iVar2 = iVar1;
    _strcmp(iVar1,puVar9);
    if (iVar2 == 0) {
      iVar2 = *(int *)(_mem_ce_simm + iVar5 + 8);
      *(uint *)(_mem_ce_simm + iVar5 + 8) = iVar2 + 1U;
      if (0xff < iVar2 + 1U) {
        _printf(aMultipleSofter);
        _printf(aSeenXCorrected,*(undefined4 *)(_mem_ce_simm + iVar5 + 8));
        _printf(aFromSimmS,iVar1);
        _printf(aConsiderReplac);
        *(undefined4 *)(_mem_ce_simm + iVar5 + 8) = 0;
        _log_ce_error = 1;
      }
      break;
    }
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 0xc;
  } while (iVar6 < 0x100);
  if (0xff < iVar6) {
    _printf(aSofterrorMemCe);
  }
  if (_log_ce_error != 0) {
    if (uVar7 < 0x48) {
      puVar3 = aCorrectedSimmA;
    }
    else {
      puVar3 = aPossibleCorrec;
    }
    _printf(puVar3,iVar1);
    _printf(aOffsetIsD,iVar8);
    if (uVar7 < 0x40) {
      _printf(aBit2dWasCorrec,uVar7);
    }
    else if (uVar7 < 0x48) {
      _printf(aEccBit2dWasCor,uVar7 - 0x40);
    }
    else {
      if (uVar7 == 0x49) {
        puVar3 = aThreeBitsWereC;
      }
      else if (uVar7 < 0x4a) {
        if (uVar7 != 0x48) goto locret_F00A69E0;
        puVar3 = aTwoBitsWereCor;
      }
      else if (uVar7 == 0x4a) {
        puVar3 = aFourBitsWereCo;
      }
      else {
        if (uVar7 != 0x4b) goto locret_F00A69E0;
        puVar3 = aMoreThanFourBi;
      }
      _printf(puVar3);
    }
  }
locret_F00A69E0:
  return CONCAT44(_mem_ce_simm,puVar9);
}
/* GHIDRADEC_FUNCTION index=2487 start=0xf00a69e8 */

/* WARNING: Removing unreachable block (ram,0xf00a6a08) */
/* WARNING: Removing unreachable block (ram,0xf00a6a14) */

undefined8 _log_ue_mem_err(uint param_1,int param_2,code *param_3)

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
  iVar1 = param_2;
  (*param_3)(param_2,param_1 & 0xf);
  if (iVar1 == 0) {
    _printf(aSimmDecodeFunc_0,0);
  }
  else {
    _printf(aUncorrectedSim,iVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2488 start=0xf00a6a24 */

/* WARNING: Removing unreachable block (ram,0xf00a6b04) */
/* WARNING: Removing unreachable block (ram,0xf00a6b2c) */
/* WARNING: Removing unreachable block (ram,0xf00a6ad8) */
/* WARNING: Removing unreachable block (ram,0xf00a6ab0) */
/* WARNING: Removing unreachable block (ram,0xf00a6a68) */
/* WARNING: Removing unreachable block (ram,0xf00a6a98) */
/* WARNING: Removing unreachable block (ram,0xf00a6ad0) */
/* WARNING: Removing unreachable block (ram,0xf00a6ae8) */
/* WARNING: Removing unreachable block (ram,0xf00a6b58) */
/* WARNING: Removing unreachable block (ram,0xf00a6b94) */
/* WARNING: Removing unreachable block (ram,0xf00a6a50) */

undefined8 _log_mem_err(uint param_1,uint param_2,undefined4 param_3,int param_4)

{
  undefined *puVar1;
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
  if (param_4 == 0) {
    if (((param_1 & 1) != 0) && (_log_ce_error != 0)) {
      _printf(aSofterrorEccMe);
    }
    if ((param_1 & 0x10000) != 0) {
      _printf(aMultipleErrors_1);
    }
    bVar2 = (param_1 & 8) == 0;
    if (_cpu == 0x72) {
      if ((param_1 & 0x20000) != 0) {
        _printf(aGraphicsError);
      }
      bVar2 = (param_1 & 8) == 0;
      if ((param_1 & 2) != 0) {
        _printf(aMisreferencedS);
        bVar2 = (param_1 & 8) == 0;
      }
    }
    if (bVar2) goto loc_F00A6AD8;
    puVar1 = aUncorrectableE;
  }
  else {
    puVar1 = aUncorrectableE_0;
  }
  _printf(puVar1);
loc_F00A6AD8:
  _prom_nextnode(0);
  _prom_getprop();
  if (*(int *)((int)register0x00000038 + -0xc) == 0) {
    _printf(aNoSimmDecodeFu);
  }
  else if ((param_4 == 0) && ((param_1 & 1) != 0)) {
    _log_ce_mem_err(param_1,param_2,param_3);
  }
  else if ((param_4 != 0) || ((param_1 & 8) != 0)) {
    _log_ue_mem_err(param_2,param_3,*(undefined4 *)((int)register0x00000038 + -0xc));
  }
  if (((param_4 != 0) || ((param_1 & 1) == 0)) || (_log_ce_error != 0)) {
    _printf(aPhysicalAddres_6,param_2 & 0xf,param_3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2489 start=0xf00a6ba4 */

/* WARNING: Removing unreachable block (ram,0xf00a6bb8) */
/* WARNING: Removing unreachable block (ram,0xf00a6bd8) */

undefined8 _fix_nc_ecc(uint param_1,uint param_2)

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
  if ((param_1 & 0x10000) == 0) {
    if ((param_2 & 0x8000000) != 0) {
      _printf(aEccErrorRecove);
      param_1 = 0xffffffff;
    }
  }
  else {
    _printf(aMultipleEccErr);
    param_1 = 0xffffffff;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2490 start=0xf00a6bec */

/* WARNING: Removing unreachable block (ram,0xf00a6c0c) */

undefined8 _p4m35_memerr_init(undefined4 param_1,undefined4 param_2)

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
  uVar1 = 0xf011ac00;
  if (_use_pe == 0) {
    _printf(aParityChecking);
    return CONCAT44(param_2,param_1);
  }
  _p4m35_memerr_init_asm();
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=2491 start=0xf00a6c1c */

/* WARNING: Removing unreachable block (ram,0xf00a6c20) */

undefined8 _p4m35_memerr_disable(undefined4 param_1,undefined4 param_2)

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
  _p4m35_memerr_disable_asm();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2492 start=0xf00a6c30 */

/* WARNING: Removing unreachable block (ram,0xf00a6d74) */
/* WARNING: Removing unreachable block (ram,0xf00a6d4c) */
/* WARNING: Removing unreachable block (ram,0xf00a6d20) */
/* WARNING: Removing unreachable block (ram,0xf00a6cfc) */
/* WARNING: Removing unreachable block (ram,0xf00a6cd0) */
/* WARNING: Removing unreachable block (ram,0xf00a6ca4) */
/* WARNING: Removing unreachable block (ram,0xf00a6c8c) */
/* WARNING: Removing unreachable block (ram,0xf00a6c94) */
/* WARNING: Removing unreachable block (ram,0xf00a6cb0) */
/* WARNING: Removing unreachable block (ram,0xf00a6ce0) */
/* WARNING: Removing unreachable block (ram,0xf00a6d08) */
/* WARNING: Removing unreachable block (ram,0xf00a6d30) */
/* WARNING: Removing unreachable block (ram,0xf00a6d60) */
/* WARNING: Removing unreachable block (ram,0xf00a6d84) */
/* WARNING: Removing unreachable block (ram,0xf00a6d14) */
/* WARNING: Removing unreachable block (ram,0xf00a6c64) */

undefined8 _p4m35_ebe_handler(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
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
  bool bVar4;
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
    uVar1 = 0x6000;
    if ((param_2 & 0x6000) != 0) {
      _printf(aSynchronousPar);
      if ((param_2 >> 2 & 7) == 4) {
        puVar3 = aParityErrorDur;
loc_F00A6CFC:
        _panic(puVar3);
      }
      else {
        _printf(aAttemptingReco);
        param_1 = param_3;
        _p4m35_parerr_reset(param_3);
        param_1 = ~param_1;
        bVar4 = param_1 != 0;
        _mmu_getctx();
        uVar1 = param_3;
        _mmu_probe();
        *(uint *)((int)register0x00000038 + -0xc) = uVar1;
        _printf(aCtx0xXVaddr0xX,param_1,param_3,uVar1,bVar4);
        _p4m35_parerr_recover(param_3,(undefined *)((int)register0x00000038 + -0xc),bVar4);
        if (param_3 == 0xffffffff) {
          puVar3 = aUnrecoverableP;
          goto loc_F00A6CFC;
        }
      }
      _printf(aSystemOperatio);
      goto locret_F00A6D8C;
    }
    _mmu_getctx();
    uVar2 = param_3;
    _mmu_probe();
    *(uint *)((int)register0x00000038 + -0xc) = uVar2;
    _printf(aNonParitySynch);
    _printf(aCtx0xXVaddr0xX_0,uVar1,param_3,*(undefined4 *)((int)register0x00000038 + -0xc),param_2)
    ;
    puVar3 = aSyncMemoryErro;
    param_1 = uVar1;
  }
  else {
    if (param_1 != 1) goto locret_F00A6D8C;
    _printf(aAsynchronousMe);
    _printf(aAddr0xXReg0xX,param_3,param_2);
    puVar3 = aAsyncMemoryErr;
  }
  _panic(puVar3);
locret_F00A6D8C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2493 start=0xf00a6d94 */

/* WARNING: Removing unreachable block (ram,0xf00a6e04) */
/* WARNING: Removing unreachable block (ram,0xf00a6dc8) */
/* WARNING: Removing unreachable block (ram,0xf00a6dc0) */
/* WARNING: Removing unreachable block (ram,0xf00a6de4) */
/* WARNING: Removing unreachable block (ram,0xf00a6e40) */
/* WARNING: Removing unreachable block (ram,0xf00a6d9c) */

undefined8 _p4m35_parerr_reset(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  _memerr_disable();
  piVar2 = &dword_F011B044;
  iVar4 = dword_F011B044;
  if (dword_F011B044 != 0) {
    while( true ) {
      _stphys(param_1,iVar4);
      iVar4 = param_1;
      _ldphys();
      if (iVar4 != *piVar2) {
        _printf(DAT_f011b098,param_1);
        iVar3 = iVar3 + 1;
      }
      piVar2 = piVar2 + 1;
      if (*piVar2 == 0) break;
      iVar4 = *piVar2;
    }
  }
  _memerr_init();
  iVar4 = 0;
  if (iVar3 != 0) {
    iVar4 = -1;
  }
  if (iVar4 == 0) {
    puVar1 = aTransient;
  }
  else {
    puVar1 = aPermanent;
  }
  _printf(aParityErrorAtX,param_1,puVar1);
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=2494 start=0xf00a6e50 */

undefined8 _p4m35_parerr_recover(undefined4 param_1,undefined4 param_2)

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
/* GHIDRADEC_FUNCTION index=2495 start=0xf00a6e5c */

/* WARNING: Removing unreachable block (ram,0xf00a6ecc) */
/* WARNING: Removing unreachable block (ram,0xf00a6eac) */
/* WARNING: Removing unreachable block (ram,0xf00a6eb8) */
/* WARNING: Removing unreachable block (ram,0xf00a6edc) */
/* WARNING: Removing unreachable block (ram,0xf00a6e84) */

undefined8 _getDefaultRoot(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  uint uVar4;
  undefined4 unaff_l3;
  uint uVar5;
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
  uVar4 = 0;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  if (DAT_f01214f4._0_4_ != -0x58585859) {
    _panic(aGetdefaultroot);
  }
  puVar6 = (undefined *)((int)register0x00000038 + -0x18);
  uVar5 = (uint)DAT_f01214f4[0xb];
  do {
    iVar3 = 0;
    while( true ) {
      _sprintf(puVar6,&aSdD_0,iVar3);
      puVar1 = puVar6;
      _IOGetObjectForDeviceName(puVar6,(undefined *)((int)register0x00000038 + -0x1c));
      uVar2 = *(uint *)((int)register0x00000038 + -0x1c);
      if (puVar1 != (undefined *)0x0) break;
      _objc_msgSend(uVar2,paTarget);
      uVar4 = *(uint *)((int)register0x00000038 + -0x1c);
      _objc_msgSend(uVar4,paInquirydevicet);
      if ((uVar5 == (uVar2 & 0xff)) && (((uVar4 & 0xff) == 5 || ((uVar4 & 0xff) == 0))))
      goto locret_F00A6F38;
      iVar3 = iVar3 + 1;
      uVar4 = uVar2;
      if (0xf < iVar3) break;
    }
    if (((uVar4 & 0xff) == uVar5) && (puVar1 != (undefined *)0x0)) {
      puVar6 = (undefined *)0x0;
locret_F00A6F38:
      return CONCAT44(param_2,puVar6);
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2496 start=0xf00a6f40 */

/* WARNING: Removing unreachable block (ram,0xf00a7174) */
/* WARNING: Removing unreachable block (ram,0xf00a7010) */
/* WARNING: Removing unreachable block (ram,0xf00a6f94) */
/* WARNING: Removing unreachable block (ram,0xf00a6fe0) */
/* WARNING: Removing unreachable block (ram,0xf00a722c) */
/* WARNING: Removing unreachable block (ram,0xf00a6fcc) */
/* WARNING: Removing unreachable block (ram,0xf00a7248) */
/* WARNING: Removing unreachable block (ram,0xf00a6fa4) */
/* WARNING: Removing unreachable block (ram,0xf00a7104) */
/* WARNING: Removing unreachable block (ram,0xf00a719c) */
/* WARNING: Removing unreachable block (ram,0xf00a7218) */

undefined8 _setconf(int param_1,undefined4 param_2)

{
  char cVar1;
  sword sVar2;
  char *pcVar3;
  int iVar4;
  undefined *puVar5;
  undefined8 *puVar6;
  undefined5 *puVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  sword sVar8;
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
  sVar8 = 0;
  _rootfs = dword_F011B160;
  if (((_boothowto & 1) == 0) && (pcVar3 = (char *)(int)_rootdevice._0_1_, pcVar3 == (char *)0x0)) {
    _getDefaultRoot();
    iVar4 = -0xfee5000;
    if (pcVar3 != (char *)0x0) goto loc_F00A700C;
    sub_F00A7380();
    if (iVar4 == 0) {
      puVar5 = aNoScsiControll_0;
      goto loc_F00A7104;
    }
    puVar5 = aNoScsiDriveAtD_0;
    goto loc_F00A7248;
  }
  do {
    if ((_boothowto & 1) == 0) {
      pcVar3 = (char *)&_rootdevice;
      if (_rootdevice._0_1_ != '\0') goto loc_F00A700C;
      _getDefaultRoot();
      iVar4 = -0xfee5000;
      if (pcVar3 != (char *)0x0) goto loc_F00A700C;
      sub_F00A7380();
      if (iVar4 == 0) {
        puVar5 = aNoScsiControll;
loc_F00A7104:
        _printf(puVar5);
      }
      else {
        puVar5 = aNoScsiDriveAtD;
loc_F00A7248:
        _printf(puVar5,0);
      }
    }
    else {
      _printf(aRootDevice);
      pcVar3 = (char *)((int)register0x00000038 + -0x88);
      _gets(pcVar3,pcVar3);
loc_F00A700C:
      _printf(aRootOnS,pcVar3);
      dword_F0131560 = &off_F011B108;
      puVar6 = off_F011B108;
      while (puVar6 != (undefined8 *)0x0) {
        if ((*(char *)*dword_F0131560 == *pcVar3) &&
           (*(char *)((int)*dword_F0131560 + 1) == pcVar3[1])) {
          if (*(sword *)(dword_F0131560 + 1) != -1) {
            if (pcVar3[3] == '*') {
              pcVar3[3] = pcVar3[4];
              cVar1 = pcVar3[2];
            }
            else {
              cVar1 = pcVar3[2];
            }
            if (7 < (byte)(cVar1 - 0x30U)) {
              puVar5 = aBadMissingUnit;
              goto loc_F00A7104;
            }
            cVar1 = pcVar3[3];
            if ((byte)(cVar1 + 0x9fU) < 8) {
              sVar2 = cVar1 + -0x61;
            }
            else {
              sVar2 = 0;
              if (cVar1 != '\0') {
                puVar5 = aBadPartitionNu;
                goto loc_F00A7104;
              }
            }
            sVar8 = sVar2;
            param_1 = pcVar3[2] + -0x30;
          }
          if (*(sword *)(dword_F0131560 + 1) == -1) {
            _rootfs = dword_F011B238;
          }
          else {
            _rootfs = DAT_f011b240._0_4_;
            _rootdev = *(word *)(dword_F0131560 + 1) & 0xff00 | (sword)param_1 * 8 + sVar8;
            *(word *)(dword_F0131560 + 1) = _rootdev;
          }
          return CONCAT44(param_2,param_1);
        }
        puVar6 = dword_F0131560[2];
        dword_F0131560 = dword_F0131560 + 2;
      }
    }
    dword_F0131560 = &off_F011B108;
    puVar6 = off_F011B108;
    while (puVar6 != (undefined8 *)0x0) {
      puVar7 = &aUse;
      if ((dword_F0131560 != &off_F011B108) &&
         (puVar7 = (undefined5 *)&DAT_f011b218, dword_F0131560[2] == (undefined8 *)0x0)) {
        puVar7 = &aOr;
      }
      _printf(&aSSD,puVar7,*dword_F0131560);
      puVar6 = dword_F0131560[2];
      dword_F0131560 = dword_F0131560 + 2;
    }
    _printf(&asc_F011B230);
    _boothowto = _boothowto | 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2497 start=0xf00a7268 */

/* WARNING: Removing unreachable block (ram,0xf00a7300) */
/* WARNING: Removing unreachable block (ram,0xf00a730c) */
/* WARNING: Removing unreachable block (ram,0xf00a72e4) */
/* WARNING: Removing unreachable block (ram,0xf00a72ec) */
/* WARNING: Removing unreachable block (ram,0xf00a7314) */
/* WARNING: Removing unreachable block (ram,0xf00a7328) */
/* WARNING: Removing unreachable block (ram,0xf00a726c) */

undefined8 _gets(undefined *param_1,undefined *param_2)

{
  undefined *puVar1;
  undefined uVar2;
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
  
  puVar1 = param_1;
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
    puVar1 = param_1;
  }
loc_F00A726C:
  do {
    _cngetc();
    param_1 = (undefined *)((uint)param_1 & 0x7f);
    if (param_1 == (undefined *)0xd) {
      *param_2 = 0;
locret_F00A733C:
      return CONCAT44(param_2,puVar1);
    }
    uVar2 = SUB41(param_1,0);
    if ((undefined *)0xd < param_1) {
      if (param_1 == (undefined *)0x40) {
loc_F00A7328:
        param_1 = (undefined *)0xa;
        _cnputc();
        param_2 = puVar1;
      }
      else {
        if (param_1 < (undefined *)0x41) {
          if (param_1 == (undefined *)0x15) goto loc_F00A7328;
          *param_2 = uVar2;
        }
        else {
          if (param_1 == (undefined *)0x7f) {
            if (param_2 != puVar1) {
              _cnputc(8);
              _cnputc(8);
              goto loc_F00A72F4;
            }
            goto loc_F00A7300;
          }
          *param_2 = uVar2;
        }
loc_F00A7334:
        param_2 = param_2 + 1;
      }
      goto loc_F00A726C;
    }
    if (param_1 != (undefined *)0x8) {
      if (param_1 != (undefined *)0xa) {
        *param_2 = uVar2;
        goto loc_F00A7334;
      }
      *param_2 = 0;
      goto locret_F00A733C;
    }
loc_F00A72F4:
    if (param_2 == puVar1) {
loc_F00A7300:
      param_1 = (undefined *)0x8;
      _cnputc();
    }
    else {
      _cnputc(0x20);
      param_1 = (undefined *)0x8;
      _cnputc();
      param_2 = param_2 + -1;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2498 start=0xf00a7344 */

/* WARNING: Removing unreachable block (ram,0xf00a7370) */
/* WARNING: Removing unreachable block (ram,0xf00a7364) */

undefined8 _getfsname(undefined4 param_1,undefined4 param_2)

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
  if ((_boothowto & 1) != 0) {
    _printf(aSKeyS,param_1,param_1);
    _gets(param_2,param_2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2499 start=0xf00a7470 */

/* WARNING: Removing unreachable block (ram,0xf00a7558) */
/* WARNING: Removing unreachable block (ram,0xf00a75b8) */
/* WARNING: Removing unreachable block (ram,0xf00a75e8) */
/* WARNING: Removing unreachable block (ram,0xf00a7584) */
/* WARNING: Removing unreachable block (ram,0xf00a7544) */
/* WARNING: Removing unreachable block (ram,0xf00a75d4) */
/* WARNING: Removing unreachable block (ram,0xf00a75f8) */
/* WARNING: Removing unreachable block (ram,0xf00a75a8) */
/* WARNING: Removing unreachable block (ram,0xf00a7610) */
/* WARNING: Removing unreachable block (ram,0xf00a74ec) */

undefined8 _initrootnet(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  sword sVar2;
  bool bVar3;
  int iVar4;
  undefined *puVar5;
  undefined uVar6;
  undefined4 unaff_l0;
  int *piVar7;
  int *piVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar9;
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
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
  bVar3 = false;
  if ((_in_ifaddr == 0) || ((*(word *)(*(int *)(_in_ifaddr + 0x20) + 0xc) & 8) != 0)) {
    piVar8 = dword_F0131560;
    if ((*(sword *)(dword_F0131560 + 1) == -1) ||
       (piVar7 = &off_F011B108, piVar8 = piVar7, sVar2 = DAT_f011b10c._0_2_, off_F011B108 == 0)) {
      uVar6 = *(undefined *)*piVar8;
    }
    else {
      while( true ) {
        if (sVar2 == -1) {
          _path_findnodebyname(*piVar7,0,_top_devinfo);
        }
        piVar8 = piVar7 + 2;
        uVar6 = uRam00000000;
        if (*piVar8 == 0) break;
        piVar1 = piVar7 + 3;
        piVar7 = piVar8;
        sVar2 = *(sword *)piVar1;
      }
    }
    *(undefined *)((int)register0x00000038 + -0x28) = uVar6;
    iVar9 = 2;
    *(undefined *)((int)register0x00000038 + -0x27) = *(undefined *)(*piVar8 + 1);
    *(undefined *)((int)register0x00000038 + -0x26) = 0x30;
    *(undefined *)((int)register0x00000038 + -0x25) = 0;
    _socreate(2,(undefined *)((int)register0x00000038 + -0x2c),2,0);
    if (iVar9 == 0) {
      *(undefined2 *)((int)register0x00000038 + -0x18) = 2;
      do {
        iVar9 = *(int *)((int)register0x00000038 + -0x2c);
        do {
          _ifioctl(iVar9,0xc0206921,(undefined *)((int)register0x00000038 + -0x28));
          if (iVar9 == 0) {
            if (bVar3) {
              _printf(aInitrootnetBoo);
            }
            puVar5 = (undefined *)((int)register0x00000038 + -0x14);
            _inet_ntoa(puVar5);
            _printf(aPrimaryNetwork,(undefined *)((int)register0x00000038 + -0x28),puVar5);
            iVar4 = *(int *)((int)register0x00000038 + -0x2c);
            goto loc_F00A7604;
          }
          if (iVar9 != 0x3c) {
            _printf(aInitrootnetAut);
            iVar4 = *(int *)((int)register0x00000038 + -0x2c);
            goto loc_F00A7604;
          }
          iVar9 = *(int *)((int)register0x00000038 + -0x2c);
        } while (bVar3);
        _printf(aInitrootnetBoo_0);
        bVar3 = true;
      } while( true );
    }
    _printf(aInitrootnetSoc);
    iVar4 = *(int *)((int)register0x00000038 + -0x2c);
loc_F00A7604:
    if (iVar4 != 0) {
      _soclose();
    }
  }
  else {
    iVar9 = 0;
  }
  return CONCAT44(param_2,iVar9);
}

