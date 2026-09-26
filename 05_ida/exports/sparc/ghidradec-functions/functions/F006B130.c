
/* WARNING: Removing unreachable block (ram,0xf006b1c4) */
/* WARNING: Removing unreachable block (ram,0xf006b198) */
/* WARNING: Removing unreachable block (ram,0xf006b1e8) */
/* WARNING: Removing unreachable block (ram,0xf006b17c) */

undefined8 sub_F006B130(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
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
  pcVar4 = (char *)(param_1 + *(int *)(param_1 + 8));
  pcVar3 = pcVar4;
  do {
    pcVar2 = (char *)0x2;
    if ((char *)(param_1 + *(int *)(param_1 + 4)) <= pcVar3) goto locret_F006B1F0;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  sub_F006B3CC(pcVar4,(undefined *)((int)register0x00000038 + -0x28),
               (undefined *)((int)register0x00000038 + -0x44),
               (undefined *)((int)register0x00000038 + -0x48),
               (undefined *)((int)register0x00000038 + -0x4c));
  pcVar2 = pcVar4;
  if (pcVar4 == (char *)0x0) {
    _memset((undefined *)((int)register0x00000038 + -0x40),0,0x14);
    *(undefined4 *)((int)register0x00000038 + -0x40) = 0;
    pcVar2 = *(char **)((int)register0x00000038 + -0x4c);
    sub_F006A83C(pcVar2,param_2,(undefined *)((int)register0x00000038 + -0x28),
                 *(undefined4 *)((int)register0x00000038 + -0x44),
                 *(undefined4 *)((int)register0x00000038 + -0x48),param_3,
                 (undefined *)((int)register0x00000038 + -0x50),
                 (undefined *)((int)register0x00000038 + -0x40));
    if ((pcVar2 == (char *)0x0) &&
       (*(uint *)((int)register0x00000038 + -0x50) < *(uint *)(param_1 + 0xc))) {
      pcVar2 = (char *)0x3;
    }
    _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x4c));
  }
locret_F006B1F0:
  return CONCAT44(param_2,pcVar2);
}
