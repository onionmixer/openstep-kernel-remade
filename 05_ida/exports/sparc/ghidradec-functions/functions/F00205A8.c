
/* WARNING: Removing unreachable block (ram,0xf002062c) */

undefined8 _sbappendrecord(sword *param_1,undefined4 *param_2)

{
  sword sVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
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
  if (param_2 != (undefined4 *)0x0) {
    iVar4 = *(int *)(param_1 + 6);
    if (iVar4 == 0) {
      sVar1 = *param_1;
    }
    else {
      iVar3 = *(int *)(iVar4 + 0x7c);
      while (iVar3 != 0) {
        iVar4 = *(int *)(iVar4 + 0x7c);
        iVar3 = *(int *)(iVar4 + 0x7c);
      }
      sVar1 = *param_1;
    }
    sVar2 = param_1[2];
    *param_1 = sVar1 + *(sword *)(param_2 + 2);
    param_1[2] = sVar2 + 0x80;
    if (0x7c < (uint)param_2[1]) {
      param_1[2] = sVar2 + 0x480;
    }
    if (iVar4 == 0) {
      *(undefined4 **)(param_1 + 6) = param_2;
    }
    else {
      *(undefined4 **)(iVar4 + 0x7c) = param_2;
    }
    uVar5 = *param_2;
    *param_2 = 0;
    _sbcompress(param_1,uVar5);
  }
  return CONCAT44(param_2,param_1);
}
