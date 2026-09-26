
/* WARNING: Removing unreachable block (ram,0xf001b314) */
/* WARNING: Removing unreachable block (ram,0xf001b2c0) */
/* WARNING: Removing unreachable block (ram,0xf001b374) */
/* WARNING: Removing unreachable block (ram,0xf001b278) */

undefined8 _ptsopen(uint param_1,uint param_2)

{
  sword sVar3;
  sword *psVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  if ((param_1 & 0xff) < 0x20) {
    sVar3 = (sword)param_1;
    psVar1 = (sword *)(int)sVar3;
    _pty_alloc();
    iVar4 = *(int *)(psVar1 + 4);
    *psVar1 = sVar3;
    if ((*(uint *)(iVar4 + 0x40) & 4) == 0) {
      _ttychars(iVar4);
      *(undefined *)(iVar4 + 0x4a) = 0xf;
      *(undefined *)(iVar4 + 0x49) = 0xf;
      *(undefined4 *)(iVar4 + 0x3c) = 0;
    }
    else if (((*(uint *)(iVar4 + 0x40) & 0x80) != 0) &&
            (iVar5 = 0x10, *(sword *)(*(int *)(_active_u + 0x1c) + 2) != 0)) goto locret_F001B37C;
    if (*(int *)(iVar4 + 0x24) != 0) {
      *(uint *)(iVar4 + 0x40) = *(uint *)(iVar4 + 0x40) | 0x10;
    }
    uVar2 = *(uint *)(iVar4 + 0x40);
    if ((param_2 & 4) == 0) {
      while ((uVar2 & 0x10) == 0) {
        *(uint *)(iVar4 + 0x40) = uVar2 | 2;
        _sleep(iVar4,0x1c);
        uVar2 = *(uint *)(iVar4 + 0x40);
      }
    }
    else {
      *(uint *)(iVar4 + 0x40) = uVar2 | 0x8000;
    }
    iVar5 = (int)sVar3;
    (**(code **)(_linesw + *(char *)(iVar4 + 0x47) * 0x30))(iVar5,iVar4);
    if (iVar5 == 0) {
      *(uint *)(psVar1 + 2) = *(uint *)(psVar1 + 2) | 1;
    }
    _ptcwakeup(iVar4,3);
  }
  else {
    iVar5 = 6;
  }
locret_F001B37C:
  return CONCAT44(param_2,iVar5);
}

