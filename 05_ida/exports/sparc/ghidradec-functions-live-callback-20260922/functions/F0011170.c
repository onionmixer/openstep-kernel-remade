
/* WARNING: Removing unreachable block (ram,0xf0011268) */
/* WARNING: Removing unreachable block (ram,0xf00111ec) */
/* WARNING: Removing unreachable block (ram,0xf00111ac) */
/* WARNING: Removing unreachable block (ram,0xf001131c) */
/* WARNING: Removing unreachable block (ram,0xf0011334) */
/* WARNING: Removing unreachable block (ram,0xf00111e4) */
/* WARNING: Removing unreachable block (ram,0xf0011254) */
/* WARNING: Removing unreachable block (ram,0xf00112dc) */
/* WARNING: Removing unreachable block (ram,0xf0011308) */

undefined8 _kill(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  int iVar2;
  int iVar3;
  undefined uVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar7;
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
  piVar7 = *(int **)(dword_F0133DDC + 0x24);
  uVar5 = piVar7[1];
  if (0x20 < uVar5) {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
    goto locret_F0011348;
  }
  iVar2 = *piVar7;
  if (iVar2 < 1) {
    if (iVar2 == -1) {
      _killpg1(uVar5,0,1);
      uVar4 = (undefined)uVar5;
    }
    else if (iVar2 == 0) {
      _killpg1(uVar5,0,0);
      uVar4 = (undefined)uVar5;
    }
    else {
      iVar2 = piVar7[1];
      _killpg1(iVar2,-*piVar7,0);
      uVar4 = (undefined)iVar2;
    }
  }
  else {
    _pfind();
    if (iVar2 != 0) {
      if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) {
        if (*(sword *)(_active_u[7] + 2) != 0) {
          if (*(sword *)(_active_u[7] + 2) != *(sword *)(iVar2 + 0x2c)) {
            uVar4 = 1;
            goto loc_F0011344;
          }
          goto loc_F00112CC;
        }
        iVar6 = piVar7[1];
      }
      else {
        iVar3 = (int)*(sword *)(iVar2 + 0x30);
        _get_posix_proc();
        iVar6 = iVar3;
        _suser();
        if (iVar6 == 0) {
          sVar1 = *(sword *)(_active_u[7] + 2);
          if ((((sVar1 != *(sword *)(iVar3 + 4)) && (sVar1 != *(sword *)(iVar3 + 6))) &&
              (sVar1 = *(sword *)(_active_u[7] + 6), sVar1 != *(sword *)(iVar3 + 4))) &&
             (sVar1 != *(sword *)(iVar3 + 6))) {
            if (piVar7[1] == 0x13) {
              iVar6 = (int)*(sword *)(iVar2 + 0x30);
              _get_posix_proc();
              iVar3 = *(int *)(iVar6 + 0x10);
              iVar6 = (int)*(sword *)(*_active_u + 0x30);
              _get_posix_proc();
              if (*(int *)(iVar3 + 8) == *(int *)(*(int *)(iVar6 + 0x10) + 8)) goto loc_F001128C;
            }
            uVar4 = 1;
            goto loc_F0011344;
          }
        }
loc_F001128C:
        *(undefined *)(dword_F0133DDC + 0x38) = 0;
loc_F00112CC:
        iVar6 = piVar7[1];
      }
      if (iVar6 != 0) {
        _psignal(iVar2);
      }
      goto locret_F0011348;
    }
    uVar4 = 3;
  }
loc_F0011344:
  *(undefined *)(dword_F0133DDC + 0x38) = uVar4;
locret_F0011348:
  return CONCAT44(param_2,param_1);
}

