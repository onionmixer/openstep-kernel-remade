
/* WARNING: Removing unreachable block (ram,0xf001b56c) */
/* WARNING: Removing unreachable block (ram,0xf001b590) */
/* WARNING: Removing unreachable block (ram,0xf001b504) */
/* WARNING: Removing unreachable block (ram,0xf001b4f4) */
/* WARNING: Removing unreachable block (ram,0xf001b588) */
/* WARNING: Removing unreachable block (ram,0xf001b5c4) */
/* WARNING: Removing unreachable block (ram,0xf001b624) */
/* WARNING: Removing unreachable block (ram,0xf001b470) */

undefined8 _ptsread(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar4;
  undefined4 unaff_l4;
  uint *puVar5;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
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
  iVar6 = (param_1 & 0xff) * 0x10;
  iVar3 = *(int *)(DAT_f012f20c + iVar6);
  iVar4 = 0;
  puVar5 = *(uint **)(DAT_f012f20c + iVar6 + 4);
  uVar1 = *puVar5;
  while ((uVar1 & 0x20) != 0) {
    if (iVar3 == _active_u[0x59]) {
      do {
        iVar6 = *_active_u;
        if (*(sword *)(iVar6 + 0x2e) == *(sword *)(iVar3 + 0x44)) break;
        if ((*(uint *)(iVar6 + 0x14) & 0x4000) == 0) {
          if ((*(uint *)(iVar6 + 0x20) & 0x100000) != 0) {
            iVar4 = 5;
            goto locret_F001B630;
          }
          if ((*(uint *)(iVar6 + 0x1c) & 0x100000) != 0) {
            iVar4 = 5;
            goto locret_F001B630;
          }
          if ((*(uint *)(iVar6 + 0x28) & 0x1000) != 0) goto loc_F001B4E4;
        }
        else {
          iVar2 = (int)*(sword *)(iVar6 + 0x30);
          _get_posix_proc();
          if ((*(uint *)(iVar6 + 0x20) & 0x100000) != 0) {
loc_F001B4E4:
            iVar4 = 5;
            goto locret_F001B630;
          }
          if ((*(uint *)(iVar6 + 0x1c) & 0x100000) != 0) {
            iVar4 = 5;
            goto locret_F001B630;
          }
          if (*(int *)(*(int *)(iVar2 + 0x10) + 0x10) == 0) {
            iVar4 = 5;
            goto locret_F001B630;
          }
        }
        _gsignal((int)*(sword *)(*_active_u + 0x2e),0x15);
        _sleep(_lbolt,0x1c);
      } while (iVar3 == _active_u[0x59]);
      iVar6 = *(int *)(iVar3 + 0xc);
    }
    else {
      iVar6 = *(int *)(iVar3 + 0xc);
    }
    if (iVar6 != 0) goto loc_F001B5AC;
    if ((*(uint *)(iVar3 + 0x40) & 0x2000) != 0) {
      iVar4 = 0x23;
      if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) {
        iVar4 = 0xb;
      }
      goto locret_F001B630;
    }
    _sleep(iVar3 + 0xc,0x1c);
    uVar1 = *puVar5;
  }
  if (*(int *)(iVar3 + 0x24) != 0) {
    iVar4 = iVar3;
    (**(code **)(DAT_f010b8d4 + *(char *)(iVar3 + 0x47) * 0x30))(iVar3,param_2);
  }
  goto loc_F001B624;
loc_F001B5AC:
  if (iVar6 < 2) goto loc_F001B5B4;
  if (*(int *)(param_2 + 0x14) < 1) {
    iVar6 = *(int *)(iVar3 + 0xc);
    goto loc_F001B5B8;
  }
  iVar6 = iVar3 + 0xc;
  _getc();
  _ureadc();
  if (iVar6 < 0) {
    iVar4 = 0xe;
    goto loc_F001B5B4;
  }
  iVar6 = *(int *)(iVar3 + 0xc);
  goto loc_F001B5AC;
loc_F001B5B4:
  iVar6 = *(int *)(iVar3 + 0xc);
loc_F001B5B8:
  if (iVar6 == 1) {
    _getc(iVar3 + 0xc);
    iVar6 = *(int *)(iVar3 + 0xc);
  }
  else {
    iVar6 = *(int *)(iVar3 + 0xc);
  }
  if (iVar6 != 0) goto locret_F001B630;
loc_F001B624:
  _ptcwakeup(iVar3,2);
locret_F001B630:
  return CONCAT44(param_2,iVar4);
}

