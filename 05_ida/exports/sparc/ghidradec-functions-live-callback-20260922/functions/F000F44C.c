
/* WARNING: Removing unreachable block (ram,0xf000f51c) */
/* WARNING: Removing unreachable block (ram,0xf000f4a0) */
/* WARNING: Removing unreachable block (ram,0xf000f510) */
/* WARNING: Removing unreachable block (ram,0xf000f548) */
/* WARNING: Removing unreachable block (ram,0xf000f474) */

undefined8 __setgid(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  sword sVar5;
  undefined4 unaff_l1;
  sword sVar6;
  undefined4 unaff_l3;
  sword sVar7;
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
  sVar1 = *(sword *)(_active_u[7] + 8);
  iVar3 = (int)*(sword *)(*_active_u + 0x30);
  sVar5 = (sword)**(undefined4 **)(dword_F0133DDC + 0x24);
  _get_posix_proc();
  if (sVar5 < 0) {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
  }
  else {
    sVar2 = *(sword *)(iVar3 + 8);
    iVar4 = iVar3;
    _suser();
    sVar7 = sVar5;
    sVar6 = sVar5;
    if (((iVar4 == 0) && (sVar7 = sVar1, sVar6 = sVar2, sVar5 != sVar1)) && (sVar5 != sVar2)) {
      *(undefined *)(dword_F0133DDC + 0x38) = 1;
    }
    else {
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
      _lock_write(_active_u + 8);
      iVar4 = _active_u[7];
      _crcopy();
      _active_u[7] = iVar4;
      *(sword *)(_active_u[7] + 8) = sVar7;
      *(sword *)(_active_u[7] + 4) = sVar5;
      _lock_done(_active_u + 8);
      *(sword *)(iVar3 + 8) = sVar6;
    }
  }
  return CONCAT44(param_2,param_1);
}

