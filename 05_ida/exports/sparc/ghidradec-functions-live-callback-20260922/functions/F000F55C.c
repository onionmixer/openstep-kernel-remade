
/* WARNING: Removing unreachable block (ram,0xf000f688) */
/* WARNING: Removing unreachable block (ram,0xf000f650) */
/* WARNING: Removing unreachable block (ram,0xf000f62c) */
/* WARNING: Removing unreachable block (ram,0xf000f644) */
/* WARNING: Removing unreachable block (ram,0xf000f680) */
/* WARNING: Removing unreachable block (ram,0xf000f6ac) */
/* WARNING: Removing unreachable block (ram,0xf000f5c4) */

undefined8 _setregid(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  sword sVar4;
  int iVar2;
  sword sVar5;
  undefined4 uVar3;
  undefined4 unaff_l0;
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
  puVar6 = *(uint **)(dword_F0133DDC + 0x24);
  uVar1 = *puVar6;
  if (uVar1 == 0xffffffff) {
    uVar1 = (uint)*(word *)(*(int *)(_active_u + 0x1c) + 8);
  }
  sVar4 = (sword)uVar1;
  if ((int)*(sword *)(*(int *)(_active_u + 0x1c) + 8) == (int)sVar4) {
    uVar1 = puVar6[1];
  }
  else {
    iVar2 = (int)*(sword *)(*(int *)(_active_u + 0x1c) + 4);
    if (iVar2 == sVar4) {
      uVar1 = puVar6[1];
    }
    else {
      _suser();
      if (iVar2 == 0) goto locret_F000F6B4;
      uVar1 = puVar6[1];
    }
  }
  if (uVar1 == 0xffffffff) {
    uVar1 = (uint)*(word *)(*(int *)(_active_u + 0x1c) + 4);
  }
  sVar5 = (sword)uVar1;
  if (((*(sword *)(*(int *)(_active_u + 0x1c) + 8) == sVar5) ||
      (*(sword *)(*(int *)(_active_u + 0x1c) + 4) == sVar5)) ||
     (iVar2 = _active_u, _suser(), iVar2 != 0)) {
    _lock_write(_active_u + 0x20);
    uVar3 = *(undefined4 *)(_active_u + 0x1c);
    _crcopy();
    *(undefined4 *)(_active_u + 0x1c) = uVar3;
    if ((int)*(sword *)(*(int *)(_active_u + 0x1c) + 8) != (int)sVar4) {
      _leavegroup();
      _entergroup((int)sVar4);
      *(sword *)(*(int *)(_active_u + 0x1c) + 8) = sVar4;
    }
    *(sword *)(*(int *)(_active_u + 0x1c) + 4) = sVar5;
    _lock_done(_active_u + 0x20);
  }
locret_F000F6B4:
  return CONCAT44(param_2,param_1);
}

