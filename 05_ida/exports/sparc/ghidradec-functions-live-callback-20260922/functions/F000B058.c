
/* WARNING: Removing unreachable block (ram,0xf000b0d8) */
/* WARNING: Removing unreachable block (ram,0xf000b158) */
/* WARNING: Removing unreachable block (ram,0xf000b0b8) */

undefined8 _close(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  uint uVar1;
  undefined4 unaff_l1;
  int iVar2;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined *puVar3;
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
  uVar1 = **(uint **)(dword_F0133DDC + 0x24);
  if (((uVar1 < (uint)_active_u[0x56]) &&
      (iVar2 = *(int *)(_active_u[0x53] + uVar1 * 4), iVar2 != 0)) && (iVar2 != -0x10000)) {
    _vno_lockrelease(iVar2);
    puVar3 = (undefined *)(_active_u[0x54] + uVar1);
    if ((*(byte *)(_active_u[0x54] + uVar1) & 2) != 0) {
      _munmapfd(uVar1);
    }
    *(undefined4 *)(_active_u[0x53] + uVar1 * 4) = 0;
    if (_active_u[0x55] < 0) {
      *puVar3 = 0;
    }
    else if (*(int *)(_active_u[0x53] + _active_u[0x55] * 4) == 0) {
      do {
        _active_u[0x55] = _active_u[0x55] + -1;
        if (_active_u[0x55] < 0) break;
      } while (*(int *)(_active_u[0x53] + _active_u[0x55] * 4) == 0);
      *puVar3 = 0;
    }
    else {
      *puVar3 = 0;
    }
    _closef(iVar2);
    if ((((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) &&
        (*(char *)(dword_F0133DDC + 0x38) == '\x1c')) && ((*(uint *)(iVar2 + 8) & 0x1000) != 0)) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
    }
  }
  else {
    *(undefined *)(dword_F0133DDC + 0x38) = 9;
  }
  return CONCAT44(param_2,param_1);
}

