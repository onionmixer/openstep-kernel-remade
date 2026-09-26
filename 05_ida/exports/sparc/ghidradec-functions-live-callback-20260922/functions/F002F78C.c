
/* WARNING: Removing unreachable block (ram,0xf002f810) */
/* WARNING: Removing unreachable block (ram,0xf002f7b0) */
/* WARNING: Removing unreachable block (ram,0xf002f808) */
/* WARNING: Removing unreachable block (ram,0xf002f818) */
/* WARNING: Removing unreachable block (ram,0xf002f790) */

undefined8 _in_delmulti(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
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
  undefined auStackX_0 [92];
  
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
  puVar1 = param_1;
  _splnet();
  iVar2 = param_1[3];
  param_1[3] = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    _igmp_leavegroup(param_1);
    piVar4 = (int *)(param_1[2] + 0x44);
    puVar3 = *(undefined4 **)(param_1[2] + 0x44);
    while (puVar3 != param_1) {
      iVar2 = *piVar4;
      piVar4 = (int *)(iVar2 + 0x14);
      puVar3 = *(undefined4 **)(iVar2 + 0x14);
    }
    *piVar4 = *(int *)(*piVar4 + 0x14);
    *(undefined2 *)((int)register0x00000038 + -0x18) = 2;
    *(undefined4 *)((int)register0x00000038 + -0x14) = *param_1;
    _if_ioctl(param_1[1],0x80206932,(undefined *)((int)register0x00000038 + -0x28));
    _m_free((uint)param_1 & 0xffffff80);
  }
  _splx(puVar1);
  return CONCAT44(param_2,param_1);
}

