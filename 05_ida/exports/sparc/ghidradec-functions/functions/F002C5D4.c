
/* WARNING: Removing unreachable block (ram,0xf002c640) */
/* WARNING: Removing unreachable block (ram,0xf002c61c) */

undefined8 _raw_bind(int param_1,uint param_2)

{
  undefined4 unaff_l0;
  int iVar1;
  undefined4 unaff_l1;
  int iVar2;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  iVar2 = param_2 + *(int *)(param_2 + 4);
  if (_ifnet != 0) {
    param_2 = (uint)*(word *)(param_2 + *(int *)(param_2 + 4));
    if (3 < param_2) {
      uVar3 = 0x2f;
      goto locret_F002C658;
    }
    if (param_2 < 2) {
      uVar3 = 0x2f;
      goto locret_F002C658;
    }
    if ((*(int *)(iVar2 + 4) == 0) || (iVar1 = iVar2, _ifa_ifwithaddr(), iVar1 != 0)) {
      iVar1 = *(int *)(param_1 + 8);
      _bcopy(iVar2,iVar1 + 0x1c,0x10);
      uVar3 = 0;
      *(word *)(iVar1 + 0x4c) = *(word *)(iVar1 + 0x4c) | 1;
      goto locret_F002C658;
    }
  }
  uVar3 = 0x31;
locret_F002C658:
  return CONCAT44(param_2,uVar3);
}
