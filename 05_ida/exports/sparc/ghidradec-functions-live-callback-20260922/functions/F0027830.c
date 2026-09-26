
/* WARNING: Removing unreachable block (ram,0xf002795c) */
/* WARNING: Removing unreachable block (ram,0xf002788c) */
/* WARNING: Removing unreachable block (ram,0xf0027984) */
/* WARNING: Removing unreachable block (ram,0xf0027878) */

undefined8 _mknod(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  if ((puVar3[1] & 0xf000) == 0) {
    puVar3[1] = puVar3[1] | 0x8000;
  }
  uVar1 = puVar3[1] & 0xf000;
  if ((uVar1 == 0x1000) || (_suser(), uVar1 != 0)) {
    _vattr_null((undefined *)((int)register0x00000038 + -0x48));
    uVar2 = *(undefined4 *)(_mftovt_tab + ((int)(puVar3[1] & 0xf000) >> 0xd) * 4);
    *(undefined4 *)((int)register0x00000038 + -0x48) = uVar2;
    *(word *)((int)register0x00000038 + -0x44) =
         (word)puVar3[1] & 0xfff & ~*(word *)(_active_u + 0x16a);
    switch(uVar2) {
    case :
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
      break;
    case :
      *(undefined *)(dword_F0133DDC + 0x38) = 0x15;
      break;
    case :
    case :
    case :
    case :
      *(sword *)((int)register0x00000038 + -0x10) = (sword)puVar3[2];
    :
      uVar2 = *puVar3;
      _vn_create(uVar2,0,(undefined *)((int)register0x00000038 + -0x48),1,0,
                 (undefined *)((int)register0x00000038 + -0x4c));
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar2;
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x4c));
      }
    }
  }
  return CONCAT44(param_2,param_1);
}

