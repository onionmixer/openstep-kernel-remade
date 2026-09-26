
/* WARNING: Removing unreachable block (ram,0xf00520fc) */
/* WARNING: Removing unreachable block (ram,0xf00520e8) */

undefined8 sub_F0052080(int param_1,sword param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
  undefined4 unaff_i1;
  int iVar4;
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
  iVar4 = (int)param_2;
  if (iVar4 == -1) {
    param_2 = *(sword *)(param_1 + 0x68);
  }
  if ((sword)param_3 == -1) {
    param_3 = (uint)*(word *)(param_1 + 0x6a);
  }
  iVar2 = (int)*(sword *)(*(int *)(_active_u + 0x1c) + 2);
  iVar1 = (int)param_2;
  if ((iVar2 == iVar1) && (iVar1 = param_3 << 0x10, iVar2 == *(sword *)(param_1 + 0x68))) {
    iVar2 = iVar1 >> 0x10;
    _groupmember();
    iVar1 = 0;
    if (iVar2 == 0) goto loc_F00520FC;
    *(sword *)(param_1 + 0x68) = param_2;
  }
  else {
loc_F00520FC:
    _suser();
    if (iVar1 == 0) {
      uVar3 = 1;
      goto locret_F0052154;
    }
    *(sword *)(param_1 + 0x68) = param_2;
  }
  *(sword *)(param_1 + 0x6a) = (sword)param_3;
  *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x40;
  if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
    uVar3 = 0;
  }
  else {
    *(word *)(param_1 + 100) = *(word *)(param_1 + 100) & 0xf3ff;
    uVar3 = 0;
  }
locret_F0052154:
  return CONCAT44(iVar4,uVar3);
}
