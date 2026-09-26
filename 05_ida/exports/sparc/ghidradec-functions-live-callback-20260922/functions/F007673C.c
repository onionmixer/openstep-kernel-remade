
/* WARNING: Removing unreachable block (ram,0xf0076784) */
/* WARNING: Removing unreachable block (ram,0xf00767c8) */
/* WARNING: Removing unreachable block (ram,0xf0076740) */

undefined8 sub_F007673C(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 *puVar3;
  uint uVar4;
  uint uVar6;
  undefined8 uVar7;
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
  undefined8 uVar5;
  
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
  uVar2 = 1;
  uVar4 = param_2;
  _clock_value();
  if ((*(uint *)(param_1 + 0x18) < uVar2) ||
     ((uVar2 == *(uint *)(param_1 + 0x18) && (*(uint *)(param_1 + 0x1c) < uVar4)))) {
    uVar5 = 0;
  }
  else {
    puVar3 = (undefined8 *)0x0;
    _timer_attributes();
    uVar7 = *puVar3;
    uVar6 = (uint)*(undefined8 *)(param_1 + 0x18);
    uVar1 = uVar6 - uVar4;
    uVar4 = ((int)((qword)*(undefined8 *)(param_1 + 0x18) >> 0x20) - uVar2) - (uint)(uVar6 < uVar4);
    uVar5 = CONCAT44(uVar4,uVar1);
    uVar2 = (uint)((qword)uVar7 >> 0x20);
    if ((uVar2 < uVar4) || ((uVar4 == uVar2 && ((uint)uVar7 < uVar1)))) {
      uVar5 = uVar7;
    }
  }
  _set_timer(0,(int)((qword)uVar5 >> 0x20),(int)uVar5);
  return CONCAT44(param_2,param_1);
}

