
/* WARNING: Removing unreachable block (ram,0xf009c824) */
/* WARNING: Removing unreachable block (ram,0xf009c804) */
/* WARNING: Removing unreachable block (ram,0xf009c810) */
/* WARNING: Removing unreachable block (ram,0xf009c870) */
/* WARNING: Removing unreachable block (ram,0xf009c7ec) */

undefined8 _pmap_create(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  int *piVar3;
  undefined4 uVar4;
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
  dword_F013DEAC = dword_F013DEAC + 1;
  if (param_1 == 0) {
    puVar5 = _pmap_zone;
    _zalloc();
    if (puVar5 == (undefined4 *)0x0) {
      _panic(aPmapCreatePmap);
    }
    _bzero(puVar5,0x28);
    puVar5[4] = 0xfff;
    puVar5[3] = 0xfff;
    _pmap_alloc_reg_entry(puVar5);
    uVar2 = 0xf0000;
    uVar4 = *puVar5;
    piVar3 = (int *)*_kernel_pmap;
    iVar1 = -0x10000000;
    do {
      *(int *)((int)register0x00000038 + -0xc) = iVar1;
      uVar2 = uVar2 + 0x1000;
      _set_ptp(uVar4,iVar1,
               (*(uint *)(*piVar3 + (uint)*(byte *)((int)register0x00000038 + -0xc) * 4) >> 2) << 6)
      ;
      iVar1 = uVar2 * 0x1000;
    } while (uVar2 < 0x100000);
    puVar5[6] = 0;
    puVar5[5] = 0;
    puVar5[7] = 1;
  }
  else {
    puVar5 = (undefined4 *)0x0;
  }
  return CONCAT44(param_2,puVar5);
}

