
/* WARNING: Removing unreachable block (ram,0xf006e5c0) */

undefined8 _set_calendar_time_value(uint *param_1,undefined4 param_2)

{
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  uint uVar6;
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
  uVar6 = *param_1;
  iVar5 = (int)uVar6 >> 0x1f;
  *(uint *)((int)register0x00000038 + -0x38) =
       uVar6 * 0x7b >> 0x1c |
       (((uVar6 * 0x1f >> 0x1e |
         (((uVar6 >> 0x1b | iVar5 << 5) - iVar5) - (uint)(uVar6 * 0x20 < uVar6)) * 4) - iVar5) -
       (uint)(uVar6 * 0x7c < uVar6)) * 0x10;
  *(uint *)((int)register0x00000038 + -0x34) = uVar6 * 0x7b0;
  uVar1 = *(undefined8 *)((int)register0x00000038 + -0x38);
  *(undefined8 *)((int)register0x00000038 + -0x38) = uVar1;
  *(qword *)((int)register0x00000038 + -0x38) =
       CONCAT44((int)((qword)uVar1 >> 0x20) + iVar5 + (uint)CARRY4((uint)uVar1,uVar6),
                (uint)uVar1 + uVar6);
  uVar3 = *(int *)((int)register0x00000038 + -0x34) * 8 - uVar6;
  iVar4 = ((*(uint *)((int)register0x00000038 + -0x34) >> 0x1d |
           *(int *)((int)register0x00000038 + -0x38) << 3) - iVar5) -
          (uint)((uint)(*(int *)((int)register0x00000038 + -0x34) * 8) < uVar6);
  uVar2 = uVar3 * 0x7c + uVar6;
  *(uint *)((int)register0x00000038 + -0x10) =
       uVar2 >> 0x17 |
       ((uVar3 * 0x1f >> 0x1e |
        (((uVar3 >> 0x1b | iVar4 * 0x20) - iVar4) - (uint)(uVar3 * 0x20 < uVar3)) * 4) + iVar5 +
       (uint)CARRY4(uVar3 * 0x7c,uVar6)) * 0x200;
  uVar3 = param_1[1];
  *(uint *)((int)register0x00000038 + -0xc) = uVar2 * 0x200;
  iVar4 = (int)uVar3 >> 0x1f;
  *(uint *)((int)register0x00000038 + -0x18) =
       uVar3 * 0x1f >> 0x1e |
       (((uVar3 >> 0x1b | iVar4 << 5) - iVar4) - (uint)(uVar3 * 0x20 < uVar3)) * 4;
  *(uint *)((int)register0x00000038 + -0x14) = uVar3 * 0x7c;
  uVar1 = *(undefined8 *)((int)register0x00000038 + -0x18);
  *(undefined8 *)((int)register0x00000038 + -0x10) =
       *(undefined8 *)((int)register0x00000038 + -0x10);
  *(undefined8 *)((int)register0x00000038 + -0x18) = uVar1;
  uVar2 = (uint)uVar1 + uVar3;
  *(uint *)((int)register0x00000038 + -0x20) =
       uVar2 >> 0x1d | ((int)((qword)uVar1 >> 0x20) + iVar4 + (uint)CARRY4((uint)uVar1,uVar3)) * 8;
  *(uint *)((int)register0x00000038 + -0x1c) = uVar2 * 8;
  uVar1 = *(undefined8 *)((int)register0x00000038 + -0x20);
  uVar2 = (uint)*(undefined8 *)((int)register0x00000038 + -0x10);
  *(undefined8 *)((int)register0x00000038 + -0x20) = uVar1;
  _set_clock(0,(int)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20) +
               (int)((qword)uVar1 >> 0x20) + (uint)CARRY4(uVar2,(uint)uVar1),uVar2 + (uint)uVar1);
  return CONCAT44(param_2,param_1);
}

