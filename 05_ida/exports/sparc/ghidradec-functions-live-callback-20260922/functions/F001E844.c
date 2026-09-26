
/* WARNING: Removing unreachable block (ram,0xf001e97c) */
/* WARNING: Removing unreachable block (ram,0xf001e904) */
/* WARNING: Removing unreachable block (ram,0xf001e888) */
/* WARNING: Removing unreachable block (ram,0xf001e868) */
/* WARNING: Removing unreachable block (ram,0xf001e8c4) */
/* WARNING: Removing unreachable block (ram,0xf001e968) */
/* WARNING: Removing unreachable block (ram,0xf001e984) */
/* WARNING: Removing unreachable block (ram,0xf001e848) */

undefined8 _soclose(int param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  iVar4 = 0;
  iVar2 = param_1;
  _splnet();
  if ((*(word *)(param_1 + 2) & 2) != 0) {
    iVar3 = *(int *)(param_1 + 0x14);
    while (iVar3 != param_1) {
      _soabort(*(undefined4 *)(param_1 + 0x14));
      iVar3 = *(int *)(param_1 + 0x14);
    }
    iVar3 = *(int *)(param_1 + 0x1c);
    while (iVar3 != param_1) {
      _soabort(*(undefined4 *)(param_1 + 0x1c));
      iVar3 = *(int *)(param_1 + 0x1c);
    }
  }
  wVar1 = *(word *)(param_1 + 6);
  if (*(int *)(param_1 + 8) == 0) goto loc_F001E958;
  if ((wVar1 & 2) == 0) {
loc_F001E91C:
    iVar3 = *(int *)(param_1 + 8);
  }
  else if ((wVar1 & 8) == 0) {
    iVar4 = param_1;
    _sodisconnect();
    if (iVar4 == 0) {
      wVar1 = *(word *)(param_1 + 2);
      goto loc_F001E8DC;
    }
    iVar3 = *(int *)(param_1 + 8);
  }
  else {
    wVar1 = *(word *)(param_1 + 2);
loc_F001E8DC:
    if ((wVar1 & 0x80) == 0) {
      iVar3 = *(int *)(param_1 + 8);
    }
    else {
      if ((*(uint *)(param_1 + 4) & 0x108) != 0x108) {
        wVar1 = *(word *)(param_1 + 6);
        while ((wVar1 & 2) != 0) {
          _sleep(param_1 + 0x54,0x1a);
          wVar1 = *(word *)(param_1 + 6);
        }
        goto loc_F001E91C;
      }
      iVar3 = *(int *)(param_1 + 8);
    }
  }
  if ((iVar3 != 0) &&
     (iVar3 = param_1, (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,1,0,0,0), iVar4 == 0))
  {
    iVar4 = iVar3;
  }
  wVar1 = *(word *)(param_1 + 6);
loc_F001E958:
  if ((wVar1 & 1) == 0) {
    wVar1 = *(word *)(param_1 + 6);
  }
  else {
    _panic(aSocloseNofdref);
    wVar1 = *(word *)(param_1 + 6);
  }
  *(word *)(param_1 + 6) = wVar1 | 1;
  _sofree();
  _splx(iVar2);
  return CONCAT44(param_2,iVar4);
}

