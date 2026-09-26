
/* WARNING: Removing unreachable block (ram,0xf009eea8) */

undefined8 _pmap_resident_extract(int *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
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
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  dword_F013DEF0 = dword_F013DEF0 + 1;
  _pmap_page_table_entry(param_1,param_2,0);
  if (param_1 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    if (*(char *)((int)param_1 + 0xd) == '\x03') {
      iVar3 = *param_1;
      uVar1 = *(uint *)((int)register0x00000038 + 0x48) >> 10 & 0xfc;
    }
    else if (*(char *)((int)param_1 + 0xd) == '\x02') {
      iVar3 = *param_1;
      uVar1 = *(word *)((int)register0x00000038 + 0x48) & 0xfc;
    }
    else {
      iVar3 = *param_1;
      uVar1 = (uint)*(byte *)((int)register0x00000038 + 0x48) << 2;
    }
    uVar1 = *(uint *)(iVar3 + uVar1);
    iVar3 = 0;
    if ((uVar1 & 3) == 2) {
      if (*(char *)((int)param_1 + 0xd) == '\x03') {
        uVar2 = (uVar1 >> 8) << 0xc;
        uVar1 = *(uint *)((int)register0x00000038 + 0x48) & 0xfff;
      }
      else {
        uVar1 = (uVar1 >> 8) << 0xc;
        uVar2 = *(uint *)((int)register0x00000038 + 0x48) & 0x3ffff;
      }
      iVar3 = uVar1 + uVar2;
    }
  }
  return CONCAT44(param_2,iVar3);
}

