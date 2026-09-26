
/* WARNING: Removing unreachable block (ram,0xf0015118) */
/* WARNING: Removing unreachable block (ram,0xf00150b4) */
/* WARNING: Removing unreachable block (ram,0xf00150d0) */
/* WARNING: Removing unreachable block (ram,0xf0015140) */
/* WARNING: Removing unreachable block (ram,0xf0015098) */

undefined8
sub_F0015074(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,int param_6)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  char *pcVar5;
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
  char acStack_18 [24];
  
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
  if ((param_2 == 10) && (param_1 < 0)) {
    sub_F00152F0(0x2d,param_3,param_4);
    param_1 = -param_1;
  }
  pcVar2 = (char *)((int)register0x00000038 + -0x18);
  do {
    pcVar5 = pcVar2;
    iVar3 = param_1;
    .urem(param_1,param_2);
    *pcVar5 = DAT_f010b4a8[iVar3];
    .udiv(param_1,param_2);
    pcVar2 = pcVar5 + 1;
  } while (param_1 != 0);
  if (param_6 != 0) {
    for (param_6 = param_6 - ((int)(pcVar5 + 1) - (int)((int)register0x00000038 + -0x18));
        0 < param_6; param_6 = param_6 + -1) {
      uVar4 = 0x20;
      if (param_5 != 0) {
        uVar4 = 0x30;
      }
      sub_F00152F0(uVar4,param_3,param_4);
    }
  }
  do {
    sub_F00152F0((int)*pcVar5,param_3,param_4);
    bVar1 = (char *)((int)register0x00000038 + -0x18) < pcVar5;
    pcVar5 = pcVar5 + -1;
  } while (bVar1);
  return CONCAT44(param_2,(char *)((int)register0x00000038 + -0x18));
}
