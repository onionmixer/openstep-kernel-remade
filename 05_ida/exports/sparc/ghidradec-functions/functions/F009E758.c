
/* WARNING: Removing unreachable block (ram,0xf009e8f0) */
/* WARNING: Removing unreachable block (ram,0xf009e834) */
/* WARNING: Removing unreachable block (ram,0xf009e7b8) */
/* WARNING: Removing unreachable block (ram,0xf009e7d0) */
/* WARNING: Removing unreachable block (ram,0xf009e8ac) */
/* WARNING: Removing unreachable block (ram,0xf009e94c) */
/* WARNING: Removing unreachable block (ram,0xf009e788) */

undefined8 _pmap_move_page(uint param_1,int param_2,uint param_3)

{
  char cVar1;
  int *piVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  uint *puVar7;
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
  *(uint *)((int)register0x00000038 + 0x44) = param_1;
  dword_F013DEE0 = dword_F013DEE0 + 1;
  if ((param_3 & _page_mask) != 0) {
    _panic(aPmapMovePagePa);
  }
  uVar4 = *(uint *)((int)register0x00000038 + 0x44);
  param_3 = uVar4 + param_3;
  piVar2 = _kernel_pmap;
  while (uVar4 < param_3) {
    _kernel_pmap = piVar2;
    _pmap_page_table_entry(piVar2,uVar4,0);
    if (piVar2 == (int *)0x0) {
      _panic(aPmapMovePageFr);
      cVar1 = cRam0000000d;
    }
    else {
      cVar1 = *(char *)((int)piVar2 + 0xd);
    }
    if (cVar1 == '\x03') {
      iVar5 = *piVar2;
      uVar4 = *(uint *)((int)register0x00000038 + 0x44) >> 10 & 0xfc;
    }
    else if (cVar1 == '\x02') {
      iVar5 = *piVar2;
      uVar4 = *(word *)((int)register0x00000038 + 0x44) & 0xfc;
    }
    else {
      iVar5 = *piVar2;
      uVar4 = (uint)*(byte *)((int)register0x00000038 + 0x44) << 2;
    }
    puVar7 = (uint *)(iVar5 + uVar4);
    if ((*puVar7 & 3) != 2) {
      _panic(aPmapMovePageNu);
    }
    if (*(char *)((int)piVar2 + 0xd) == '\x03') {
      uVar4 = *(uint *)((int)register0x00000038 + 0x44) >> 0xf & 4;
      bVar3 = (byte)(*(uint *)((int)register0x00000038 + 0x44) >> 0xc) & 0x1e;
    }
    else {
      if (*(char *)((int)piVar2 + 0xd) == '\x02') {
        bVar3 = (byte)(*(uint *)((int)register0x00000038 + 0x44) >> 0x12);
        uVar4 = *(uint *)((int)register0x00000038 + 0x44) >> 0x15 & 4;
      }
      else {
        bVar3 = *(byte *)((int)register0x00000038 + 0x44);
        uVar4 = (uint)(bVar3 >> 5) << 2;
      }
      bVar3 = bVar3 & 0x1f;
    }
    uVar6 = *(uint *)((int)piVar2 + uVar4 + 0x10);
    param_1 = (uint)*(byte *)((int)piVar2 + 0xd);
    uVar4 = *puVar7 >> 2 & 7;
    _srmmu_to_vm_prot(uVar4);
    if (param_1 == 3) {
      iVar5 = *(int *)((int)register0x00000038 + 0x44) + _page_size;
    }
    else if (param_1 == 2) {
      iVar5 = *(int *)((int)register0x00000038 + 0x44) + 0x40000;
    }
    else {
      iVar5 = *(int *)((int)register0x00000038 + 0x44) + 0x1000000;
    }
    _pmap_remove(_kernel_pmap,*(undefined4 *)((int)register0x00000038 + 0x44),iVar5);
    iVar5 = _page_size;
    if ((param_1 != 3) && (iVar5 = 0x1000000, param_1 == 2)) {
      iVar5 = 0x40000;
    }
    _pmap_enter_range(_kernel_pmap,param_2,(*puVar7 >> 8) << 0xc,*puVar7 >> 0x1c,iVar5,uVar4,
                      *puVar7 >> 7 & 1,uVar6 & 1 << bVar3);
    if (param_1 == 3) {
      iVar5 = *(int *)((int)register0x00000038 + 0x44) + _page_size;
    }
    else if (param_1 == 2) {
      iVar5 = *(int *)((int)register0x00000038 + 0x44) + 0x40000;
    }
    else {
      iVar5 = *(int *)((int)register0x00000038 + 0x44) + 0x1000000;
    }
    *(int *)((int)register0x00000038 + 0x44) = iVar5;
    if (param_1 == 3) {
      param_2 = param_2 + _page_size;
    }
    else if (param_1 == 2) {
      param_2 = param_2 + 0x40000;
    }
    else {
      param_2 = param_2 + 0x1000000;
    }
    piVar2 = _kernel_pmap;
    uVar4 = *(uint *)((int)register0x00000038 + 0x44);
  }
  _kernel_pmap = piVar2;
  return CONCAT44(param_2,param_1);
}
