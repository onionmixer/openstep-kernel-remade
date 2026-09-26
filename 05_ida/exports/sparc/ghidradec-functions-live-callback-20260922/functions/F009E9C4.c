
/* WARNING: Removing unreachable block (ram,0xf009ebb4) */
/* WARNING: Removing unreachable block (ram,0xf009eb20) */
/* WARNING: Removing unreachable block (ram,0xf009ea1c) */
/* WARNING: Removing unreachable block (ram,0xf009ea50) */
/* WARNING: Removing unreachable block (ram,0xf009eb40) */
/* WARNING: Removing unreachable block (ram,0xf009e9f4) */
/* WARNING: Removing unreachable block (ram,0xf009ea00) */

undefined8 _pmap_protect(int *param_1,uint *param_2,uint *param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined4 unaff_l0;
  uint *puVar8;
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
  if (param_1 != (int *)0x0) {
    iVar2 = dword_F013DEE4 + 1;
    dword_F013DEE4 = iVar2;
    if (param_4 == 0) {
      _pmap_remove(param_1,param_2,param_3);
    }
    else {
      _splvm();
      do {
        do {
        } while (param_1[6] != 0);
        piVar3 = param_1 + 6;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      *(uint **)((int)register0x00000038 + -0xc) = param_2;
      puVar4 = param_2;
joined_r0xf009ea30:
      if (puVar4 < param_3) {
        piVar3 = param_1;
        _pmap_page_table_entry(param_1,*(undefined4 *)((int)register0x00000038 + -0xc),0);
        if (piVar3 != (int *)0x0) goto loc_f009ea5c;
        *(uint *)((int)register0x00000038 + -0xc) =
             *(int *)((int)register0x00000038 + -0xc) + 0x40000U & 0xfffc0000;
        goto loc_F009EBA0;
      }
      param_1[6] = 0;
      _splx(iVar2);
    }
  }
  return CONCAT44(param_2,param_1);
loc_f009ea5c:
  if (*(char *)((int)piVar3 + 0xd) == '\x03') {
    puVar8 = (uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x40000U & 0xfffc0000);
  }
  else {
    puVar8 = (uint *)0xffffe000;
    if (*(char *)((int)piVar3 + 0xd) == '\x02') {
      puVar8 = (uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x1000000U & 0xff000000);
    }
  }
  if (param_3 < puVar8) {
    puVar8 = param_3;
  }
  puVar4 = *(uint **)((int)register0x00000038 + -0xc);
  if (puVar4 < puVar8) {
    do {
      if (*(char *)((int)piVar3 + 0xd) == '\x03') {
        iVar7 = *piVar3;
        uVar5 = (uint)puVar4 >> 10 & 0xfc;
      }
      else if (*(char *)((int)piVar3 + 0xd) == '\x02') {
        iVar7 = *piVar3;
        uVar5 = *(word *)((int)register0x00000038 + -0xc) & 0xfc;
      }
      else {
        iVar7 = *piVar3;
        uVar5 = (uint)*(byte *)((int)register0x00000038 + -0xc) << 2;
      }
      param_2 = (uint *)(iVar7 + uVar5);
      if ((*param_2 & 3) == 2) {
        piVar6 = param_1;
        _vm_to_srmmu_prot(param_1,1);
        *(int **)((int)register0x00000038 + -0x10) = piVar3;
        _update_pte((undefined *)((int)register0x00000038 + -0x10),
                    *(undefined4 *)((int)register0x00000038 + -0xc),piVar6,*param_2 >> 7 & 1);
        cVar1 = *(char *)((int)piVar3 + 0xd);
      }
      else {
        cVar1 = *(char *)((int)piVar3 + 0xd);
      }
      if (cVar1 == '\x03') {
        puVar4 = (uint *)((*(uint *)((int)register0x00000038 + -0xc) & ~_page_mask) + _page_size);
      }
      else if (cVar1 == '\x02') {
        puVar4 = (uint *)((*(uint *)((int)register0x00000038 + -0xc) & 0xfffc0000) + 0x40000);
      }
      else {
        puVar4 = (uint *)((*(uint *)((int)register0x00000038 + -0xc) & 0xff000000) + 0x1000000);
      }
      *(uint **)((int)register0x00000038 + -0xc) = puVar4;
    } while (puVar4 < puVar8);
loc_F009EBA0:
    puVar4 = *(uint **)((int)register0x00000038 + -0xc);
  }
  goto joined_r0xf009ea30;
}

