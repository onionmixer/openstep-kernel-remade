
/* WARNING: Removing unreachable block (ram,0xf00bf490) */

undefined8 -[EventSrcPCKeyboard setRepeat:forCode:](int param_1,undefined4 param_2)

{
  undefined (*pauVar1) [19];
  int iVar2;
  undefined8 in_o2_3;
  uint uVar3;
  uint uVar4;
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
  iVar2 = (int)((qword)in_o2_3 >> 0x20);
  if (*(char *)(param_1 + 0x14e) == '\0') {
    if (iVar2 == 10) {
      *(int *)(param_1 + 0x150) = (int)in_o2_3;
      pauVar1 = paScheduleautore;
      uVar3 = (uint)*(undefined8 *)(param_1 + 0x170);
      uVar4 = (uint)*(undefined8 *)(param_1 + 0x158);
      *(qword *)(param_1 + 0x160) =
           CONCAT44((int)((qword)*(undefined8 *)(param_1 + 0x170) >> 0x20) +
                    (int)((qword)*(undefined8 *)(param_1 + 0x158) >> 0x20) +
                    (uint)CARRY4(uVar3,uVar4),uVar3 + uVar4);
    }
    else {
      if ((iVar2 != 0xb) || (*(int *)(param_1 + 0x150) != (int)in_o2_3)) goto locret_F00BF498;
      *(undefined4 *)(param_1 + 0x150) = 0xffffffff;
      pauVar1 = paScheduleautore;
      *(undefined8 *)(param_1 + 0x160) = 0;
    }
    _objc_msgSend(param_1,pauVar1);
  }
locret_F00BF498:
  return CONCAT44(param_2,param_1);
}

