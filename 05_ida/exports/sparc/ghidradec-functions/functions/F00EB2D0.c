
/* WARNING: Removing unreachable block (ram,0xf00eb328) */
/* WARNING: Removing unreachable block (ram,0xf00eb318) */

undefined8 -[List insertObject:at:](undefined4 *param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
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
  if (param_3 == 0) {
    param_1 = (undefined4 *)0x0;
  }
  else if ((uint)param_1[2] < param_4) {
    param_1 = (undefined4 *)0x0;
  }
  else {
    if ((uint)param_1[3] < param_1[2] + 1) {
      param_1[3] = param_1[3] * 2 + 1;
      puVar1 = param_1;
      _objc_msgSend(param_1,paZone);
      puVar2 = param_1;
      _objc_msgSend(param_1,paZone);
      (*(code *)*puVar1)();
      param_1[1] = puVar2;
    }
    piVar3 = (int *)(param_4 * 4 + param_1[1]);
    piVar4 = (int *)(param_1[2] * 4 + param_1[1]);
    piVar5 = piVar4;
    for (; piVar3 < piVar4; piVar4 = piVar4 + -1) {
      piVar5 = piVar5 + -1;
      *piVar4 = *piVar5;
    }
    *piVar3 = param_3;
    param_1[2] = param_1[2] + 1;
  }
  return CONCAT44(param_2,param_1);
}
