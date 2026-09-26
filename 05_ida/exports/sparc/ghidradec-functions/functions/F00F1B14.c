
/* WARNING: Removing unreachable block (ram,0xf00f1bd0) */
/* WARNING: Removing unreachable block (ram,0xf00f1bb4) */

undefined8
_objc_msgSendv(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
              undefined4 param_6)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  int in_o7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 *puVar6;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 *puVar7;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  uVar2 = 0xffffffa0;
  if (param_3 + -0x1c != 0 && 0x1b < param_3) {
    uVar2 = -(param_3 + -0x1c) - 0x60U & 0xfffffff8;
  }
  puVar5 = (undefined *)register0x00000038;
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
  iVar3 = param_3;
  iVar4 = param_4;
  if ((((param_3 != 8) && (iVar3 = *(int *)(param_4 + 8), param_3 != 0xc)) &&
      (iVar4 = *(int *)(param_4 + 0xc), param_3 != 0x10)) &&
     (param_5 = *(undefined4 *)(param_4 + 0x10), param_3 != 0x14)) {
    param_6 = *(undefined4 *)(param_4 + 0x14);
    param_3 = param_3 + -0x18;
    if (param_3 != 0) {
      puVar6 = (undefined4 *)(param_4 + 0x18);
      puVar7 = (undefined4 *)(&stack0x0000005c + uVar2);
      do {
        param_3 = param_3 + -4;
        *puVar7 = *puVar6;
        puVar7 = puVar7 + 1;
        puVar6 = puVar6 + 1;
      } while (param_3 != 0);
    }
  }
  if ((*(uint *)(in_o7 + 8) & 0xffc00000) != 0) {
    _objc_msgSend(param_1,param_2,iVar3,iVar4,param_5,param_6);
    return CONCAT44(param_2,param_1);
  }
  *(undefined4 *)(auStackX_0 + uVar2 + 0x40) = *(undefined4 *)(puVar5 + 0x40);
  _objc_msgSend(param_1,param_2,iVar3,iVar4,param_5,param_6);
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(0);
  (*pcVar1)();
}
