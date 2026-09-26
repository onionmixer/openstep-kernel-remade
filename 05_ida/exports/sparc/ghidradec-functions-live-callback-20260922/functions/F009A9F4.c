
/* WARNING: Removing unreachable block (ram,0xf009aa98) */
/* WARNING: Removing unreachable block (ram,0xf009aa2c) */
/* WARNING: Removing unreachable block (ram,0xf009aaf4) */
/* WARNING: Removing unreachable block (ram,0xf009a9f8) */

undefined8 _swift_vac_init(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
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
  _swift_vac_init_asm();
  _vac_mode = aWritethru;
  if (_swift_kdnx == 1) {
    piVar1 = _kernel_pmap;
    _pmap_page_table_entry(_kernel_pmap,0xfefe0000,0);
    piVar2 = _kernel_pmap;
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0xfefe0000;
    if (*(char *)((int)piVar1 + 0xd) == '\x03') {
      puVar3 = (uint *)(*piVar1 + 0x80);
    }
    else if (*(char *)((int)piVar1 + 0xd) == '\x02') {
      puVar3 = (uint *)(*piVar1 + 0xfc);
    }
    else {
      puVar3 = (uint *)(*piVar1 + (uint)*(byte *)((int)register0x00000038 + -0xc) * 4);
    }
    *puVar3 = *puVar3 & 0xffffffe3 | 0x14;
    _pmap_page_table_entry(piVar2,0xfefea000,0);
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0xfefea000;
    if (*(char *)((int)piVar2 + 0xd) == '\x03') {
      puVar3 = (uint *)(*piVar2 + 0xa8);
    }
    else if (*(char *)((int)piVar2 + 0xd) == '\x02') {
      puVar3 = (uint *)(*piVar2 + 0xfc);
    }
    else {
      puVar3 = (uint *)(*piVar2 + (uint)*(byte *)((int)register0x00000038 + -0xc) * 4);
    }
    *puVar3 = *puVar3 & 0xffffffe3 | 0x14;
    _mmu_flushall();
  }
  return CONCAT44(param_2,param_1);
}

