
/* WARNING: Removing unreachable block (ram,0xf009c6ec) */
/* WARNING: Removing unreachable block (ram,0xf009c624) */
/* WARNING: Removing unreachable block (ram,0xf009c60c) */
/* WARNING: Removing unreachable block (ram,0xf009c6cc) */
/* WARNING: Removing unreachable block (ram,0xf009c6f8) */
/* WARNING: Removing unreachable block (ram,0xf009c5f0) */

undefined8 _pmap_change_prot(uint *param_1,int param_2)

{
  int *piVar1;
  undefined2 *puVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
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
  
  piVar1 = _kernel_pmap;
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
  *(uint **)((int)register0x00000038 + 0x44) = param_1;
  puVar2 = &_pmap_info;
  dword_F013DEA8 = dword_F013DEA8 + 1;
  if (param_2 != 0) {
    piVar4 = _kernel_pmap + 6;
    _splvm();
    do {
      do {
      } while (*piVar4 != 0);
      piVar3 = piVar4;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    piVar4 = piVar1;
    _pmap_page_table_entry(piVar1,*(undefined4 *)((int)register0x00000038 + 0x44),0);
    if (*(char *)((int)piVar4 + 0xd) == '\x03') {
      uVar5 = *(uint *)((int)register0x00000038 + 0x44) & ~_page_mask;
    }
    else {
      if (*(char *)((int)piVar4 + 0xd) == '\x02') {
        uVar5 = 0xfffc0000;
      }
      else {
        uVar5 = 0xff000000;
      }
      uVar5 = *(uint *)((int)register0x00000038 + 0x44) & uVar5;
    }
    *(uint *)((int)register0x00000038 + 0x44) = uVar5;
    if (*(char *)((int)piVar4 + 0xd) == '\x03') {
      iVar6 = *piVar4;
      uVar5 = *(uint *)((int)register0x00000038 + 0x44) >> 10 & 0xfc;
    }
    else if (*(char *)((int)piVar4 + 0xd) == '\x02') {
      iVar6 = *piVar4;
      uVar5 = *(word *)((int)register0x00000038 + 0x44) & 0xfc;
    }
    else {
      iVar6 = *piVar4;
      uVar5 = (uint)*(byte *)((int)register0x00000038 + 0x44) << 2;
    }
    param_1 = (uint *)(iVar6 + uVar5);
    if ((*param_1 & 3) == 2) {
      piVar3 = piVar1;
      _vm_to_srmmu_prot(piVar1,param_2);
      *(int **)((int)register0x00000038 + -0xc) = piVar4;
      _update_pte((undefined *)((int)register0x00000038 + -0xc),
                  *(undefined4 *)((int)register0x00000038 + 0x44),piVar3,*param_1 >> 7 & 1);
      piVar1[6] = 0;
    }
    _splx(puVar2);
  }
  return CONCAT44(param_2,param_1);
}

