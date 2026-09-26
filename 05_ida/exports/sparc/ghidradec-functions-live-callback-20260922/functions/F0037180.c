
/* WARNING: Removing unreachable block (ram,0xf00371c8) */
/* WARNING: Removing unreachable block (ram,0xf00371ac) */

undefined8 _tcp_setpersist(int param_1,undefined4 param_2)

{
  sword sVar1;
  undefined2 uVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = ((int)((uint)*(word *)(param_1 + 0x60) << 0x10) >> 0x12) + (int)*(sword *)(param_1 + 0x62)
          >> 1;
  if (*(sword *)(param_1 + 10) != 0) {
    _panic(aTcpOutputRexmt);
  }
  umul(iVar3,*(undefined4 *)(_tcp_backoff + *(sword *)(param_1 + 0x12) * 4));
  sVar1 = (sword)iVar3;
  *(sword *)(param_1 + 0xc) = sVar1;
  if (sVar1 < 10) {
    uVar2 = 10;
  }
  else {
    uVar2 = 0x78;
    if (sVar1 < 0x79) goto loc_F00371FC;
  }
  *(undefined2 *)(param_1 + 0xc) = uVar2;
loc_F00371FC:
  if (*(sword *)(param_1 + 0x12) < 0xc) {
    *(sword *)(param_1 + 0x12) = *(sword *)(param_1 + 0x12) + 1;
  }
  return CONCAT44(param_2,param_1);
}

