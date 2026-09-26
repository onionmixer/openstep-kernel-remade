
/* WARNING: Removing unreachable block (ram,0xf004f2f4) */
/* WARNING: Removing unreachable block (ram,0xf004f2e8) */
/* WARNING: Removing unreachable block (ram,0xf004f298) */
/* WARNING: Removing unreachable block (ram,0xf004f250) */
/* WARNING: Removing unreachable block (ram,0xf004f310) */
/* WARNING: Removing unreachable block (ram,0xf004f2c8) */
/* WARNING: Removing unreachable block (ram,0xf004f320) */
/* WARNING: Removing unreachable block (ram,0xf004f244) */

undefined8 _lf_lockctl(int param_1,sword *param_2,int param_3)

{
  sword *psVar1;
  int iVar2;
  sword *psVar3;
  sword sVar4;
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
  sub_F004F334();
  psVar1 = (sword *)0x1c;
  _kalloc();
  psVar1[1] = *param_2;
  *(undefined4 *)(psVar1 + 2) = *(undefined4 *)(param_2 + 2);
  if (*(int *)(param_2 + 4) == 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = *(int *)(param_2 + 2) + *(int *)(param_2 + 4) + -1;
  }
  *(int *)(psVar1 + 4) = iVar2;
  iVar2 = (int)*(sword *)(*_active_u + 0x30);
  _get_posix_proc();
  *(int *)(psVar1 + 6) = iVar2;
  *(int *)(psVar1 + 8) = param_1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  psVar1[10] = 0;
  psVar1[0xb] = 0;
  psVar1[0xc] = 0;
  psVar1[0xd] = 0;
  psVar3 = psVar1;
  if (param_3 == 7) {
    sub_F004F8C0(psVar1,param_2);
  }
  else {
    if (*param_2 != 3) {
      if (param_3 == 8) {
        sVar4 = 1;
      }
      else {
        sVar4 = 2;
      }
      *psVar1 = sVar4;
      sub_F004F460(psVar1);
      goto locret_F004F32C;
    }
    sub_F004F78C(psVar1);
  }
  sub_F004FCE0(psVar1);
  sub_F004F3DC(param_1);
  psVar1 = psVar3;
  param_2 = psVar3;
locret_F004F32C:
  return CONCAT44(param_2,psVar1);
}

