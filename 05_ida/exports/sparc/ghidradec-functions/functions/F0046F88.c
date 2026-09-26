
/* WARNING: Removing unreachable block (ram,0xf004701c) */
/* WARNING: Removing unreachable block (ram,0xf0047050) */
/* WARNING: Removing unreachable block (ram,0xf0046fd8) */

undefined8 sub_F0046F88(int param_1,int param_2)

{
  word wVar2;
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 uVar4;
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
  iVar3 = *(int *)(param_1 + 0x30);
  if (param_2 == 1) {
    if (*(int *)(iVar3 + 0x7c) != 0) {
      uVar4 = 1;
      goto locret_F0047074;
    }
    iVar1 = iVar3 + 0x70;
    _selthreadcache();
    if (iVar1 == 0) {
      uVar4 = 0;
      goto locret_F0047074;
    }
    wVar2 = *(word *)(iVar3 + 0x88) | 4;
  }
  else if (param_2 < 2) {
    if (param_2 != 0) {
      uVar4 = 0;
      goto locret_F0047074;
    }
    if (*(sword *)(iVar3 + 0x82) == 0) {
      uVar4 = 1;
      goto locret_F0047074;
    }
    iVar1 = iVar3 + 0x78;
    _selthreadcache();
    if (iVar1 == 0) {
      uVar4 = 0;
      goto locret_F0047074;
    }
    wVar2 = *(word *)(iVar3 + 0x88) | 0x10;
  }
  else {
    if (param_2 != 2) {
      uVar4 = 0;
      goto locret_F0047074;
    }
    if ((*(uint *)(iVar3 + 0x7c) < _fifoinfo) && (0 < *(sword *)(iVar3 + 0x82))) {
      uVar4 = 1;
      goto locret_F0047074;
    }
    iVar1 = iVar3 + 0x74;
    _selthreadcache();
    if (iVar1 == 0) {
      uVar4 = 0;
      goto locret_F0047074;
    }
    wVar2 = *(word *)(iVar3 + 0x88) | 8;
  }
  *(word *)(iVar3 + 0x88) = wVar2;
  uVar4 = 0;
locret_F0047074:
  return CONCAT44(param_2,uVar4);
}
