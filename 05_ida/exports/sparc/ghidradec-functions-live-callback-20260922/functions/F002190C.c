
/* WARNING: Removing unreachable block (ram,0xf002199c) */
/* WARNING: Removing unreachable block (ram,0xf002192c) */

undefined8 _recvfrom(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
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
  puVar2 = *(undefined4 **)(dword_F0133DDC + 0x24);
  iVar1 = puVar2[5];
  if (iVar1 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  }
  else {
    _copyin(iVar1,(undefined *)((int)register0x00000038 + -0x2c),4);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
  }
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    *(qword *)((int)register0x00000038 + -0x20) =
         CONCAT44(puVar2[4],*(undefined4 *)((int)register0x00000038 + -0x2c));
    *(undefined **)((int)register0x00000038 + -0x18) =
         (undefined *)((int)register0x00000038 + -0x28);
    *(undefined4 *)((int)register0x00000038 + -0x14) = 1;
    *(undefined4 *)((int)register0x00000038 + -0x28) = puVar2[1];
    *(undefined4 *)((int)register0x00000038 + -0x24) = puVar2[2];
    *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    _recvit(*puVar2,(undefined *)((int)register0x00000038 + -0x20),puVar2[3],puVar2[5],0);
  }
  return CONCAT44(param_2,param_1);
}

