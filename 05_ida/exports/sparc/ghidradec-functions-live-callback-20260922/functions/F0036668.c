
/* WARNING: Removing unreachable block (ram,0xf00366f4) */
/* WARNING: Removing unreachable block (ram,0xf00366c0) */

undefined8 _tcp_pulloutofband(int param_1,int param_2,int *param_3)

{
  sword sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
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
  iVar4 = *(word *)(param_2 + 0x26) - 1;
  if (iVar4 < 0) {
loc_F00366F4:
    _panic(aTcpPulloutofba);
  }
  else {
    sVar1 = *(sword *)(param_3 + 2);
    while (sVar1 <= iVar4) {
      param_3 = (int *)*param_3;
      iVar4 = iVar4 - sVar1;
      if ((param_3 == (int *)0x0) || (iVar4 < 0)) goto loc_F00366F4;
      sVar1 = *(sword *)(param_3 + 2);
    }
    iVar2 = param_3[1];
    iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x20);
    *(undefined *)(iVar3 + 0x69) = *(undefined *)((int)param_3 + iVar4 + iVar2);
    iVar2 = (int)param_3 + iVar4 + iVar2;
    *(byte *)(iVar3 + 0x68) = *(byte *)(iVar3 + 0x68) | 1;
    _bcopy(iVar2 + 1,iVar2,(*(sword *)(param_3 + 2) - iVar4) + -1);
    *(sword *)(param_3 + 2) = *(sword *)(param_3 + 2) + -1;
  }
  return CONCAT44(param_2,param_1);
}

