
/* WARNING: Removing unreachable block (ram,0xf000f2e8) */
/* WARNING: Removing unreachable block (ram,0xf000f2c4) */
/* WARNING: Removing unreachable block (ram,0xf000f2dc) */
/* WARNING: Removing unreachable block (ram,0xf000f320) */
/* WARNING: Removing unreachable block (ram,0xf000f25c) */

undefined8 _setreuid(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  sword sVar4;
  sword sVar5;
  int *piVar2;
  int iVar3;
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
    uVar1 = (uint)*(word *)(_active_u[7] + 6);
  }
  sVar4 = (sword)uVar1;
  if ((int)*(sword *)(_active_u[7] + 6) == (int)sVar4) {
    uVar1 = puVar6[1];
  }
  else {
    iVar3 = (int)*(sword *)(_active_u[7] + 2);
    if (iVar3 == sVar4) {
      uVar1 = puVar6[1];
    }
    else {
      _suser();
      if (iVar3 == 0) goto locret_F000F328;
      uVar1 = puVar6[1];
    }
  }
  if (uVar1 == 0xffffffff) {
    uVar1 = (uint)*(word *)(_active_u[7] + 2);
  }
  sVar5 = (sword)uVar1;
  if (((*(sword *)(_active_u[7] + 6) == sVar5) || (*(sword *)(_active_u[7] + 2) == sVar5)) ||
     (piVar2 = _active_u, _suser(), piVar2 != (int *)0x0)) {
    _lock_write(_active_u + 8);
    iVar3 = _active_u[7];
    _crcopy();
    _active_u[7] = iVar3;
    *(sword *)(*_active_u + 0x2c) = sVar5;
    *(sword *)(_active_u[7] + 6) = sVar4;
    *(sword *)(_active_u[7] + 2) = sVar5;
    _lock_done(_active_u + 8);
  }
locret_F000F328:
  return CONCAT44(param_2,param_1);
}

