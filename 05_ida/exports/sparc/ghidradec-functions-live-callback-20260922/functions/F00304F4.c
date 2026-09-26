
/* WARNING: Removing unreachable block (ram,0xf003054c) */
/* WARNING: Removing unreachable block (ram,0xf0030508) */

undefined8 sub_F00304F4(undefined4 *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  char *pcVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar2;
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
  char acStack_27 [39];
  
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
  pcVar1 = (char *)((int)register0x00000038 + -0x28);
  puVar2 = *(undefined4 **)((int)register0x00000038 + 0x40);
  _strcpy(pcVar1,*param_1);
  if (*(char *)((int)register0x00000038 + -0x28) != '\0') {
    for (pcVar1 = (char *)((int)register0x00000038 + -0x27); *pcVar1 != '\0'; pcVar1 = pcVar1 + 1) {
    }
  }
  *pcVar1 = (char)*(undefined2 *)(param_1 + 2) + '0';
  pcVar1[1] = '\0';
  _bcopy(param_2,(undefined *)((int)register0x00000038 + -0x18),0x10);
  *puVar2 = *(undefined4 *)((int)register0x00000038 + -0x28);
  puVar2[1] = *(undefined4 *)((int)register0x00000038 + -0x24);
  puVar2[2] = *(undefined4 *)((int)register0x00000038 + -0x20);
  puVar2[3] = *(undefined4 *)((int)register0x00000038 + -0x1c);
  puVar2[4] = *(undefined4 *)((int)register0x00000038 + -0x18);
  puVar2[5] = *(undefined4 *)((int)register0x00000038 + -0x14);
  puVar2[6] = *(undefined4 *)((int)register0x00000038 + -0x10);
  puVar2[7] = *(undefined4 *)((int)register0x00000038 + -0xc);
  return CONCAT44(param_2,puVar2);
}

