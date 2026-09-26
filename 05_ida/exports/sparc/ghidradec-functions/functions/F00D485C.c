
/* WARNING: Removing unreachable block (ram,0xf00d49e4) */
/* WARNING: Removing unreachable block (ram,0xf00d4988) */
/* WARNING: Removing unreachable block (ram,0xf00d493c) */
/* WARNING: Removing unreachable block (ram,0xf00d48f8) */
/* WARNING: Removing unreachable block (ram,0xf00d495c) */
/* WARNING: Removing unreachable block (ram,0xf00d49c4) */
/* WARNING: Removing unreachable block (ram,0xf00d49fc) */
/* WARNING: Removing unreachable block (ram,0xf00d4880) */

undefined8
-[EventDriver absolutePointerEvent:at:inProximity:withPressure:withAngle:atTime:]
          (int param_1,undefined4 param_2,undefined4 param_3,sword *param_4)

{
  char cVar1;
  char cVar3;
  undefined4 uVar2;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 in_o4_5;
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
  uVar6 = (uint)((qword)*(undefined8 *)((int)register0x00000038 + 0x60) >> 0x20);
  uVar5 = uVar6 << 8 | (uint)*(undefined8 *)((int)register0x00000038 + 0x60) >> 0x18;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock,uVar6 >> 0x18);
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    uVar2 = *(undefined4 *)(param_1 + 0x110);
    uVar4 = paUnlock;
    goto loc_F00D49FC;
  }
  *(char *)(param_1 + 0x1c0) = (char)in_o4_5;
  if ((*param_4 == *(sword *)(param_1 + 0x1a8)) && (param_4[1] == *(sword *)(param_1 + 0x1aa))) {
    cVar1 = *(char *)(param_1 + 0x1c1);
  }
  else {
    *(sword *)(param_1 + 0x1a8) = *param_4;
    *(sword *)(param_1 + 0x1aa) = param_4[1];
    if (*(char *)(param_1 + 0x211) == '\0') {
      _objc_msgSend(param_1,paSetcursorposit_0,param_1 + 0x1a8,uVar5);
    }
    cVar1 = *(char *)(param_1 + 0x1c1);
  }
  cVar3 = (char)((qword)in_o4_5 >> 0x20);
  if ((cVar1 != cVar3) && (cVar3 == '\x01')) {
    *(uint *)(*(int *)(param_1 + 0x168) + 0xc) = *(uint *)(*(int *)(param_1 + 0x168) + 0xc) | 0x80;
    _bzero((undefined *)((int)register0x00000038 + -0x20),0xc);
    _objc_msgSend(param_1,paPosteventAtAtt,0xc,param_1 + 0x1a8,uVar5);
  }
  if (cVar3 == '\x01') {
    _objc_msgSend(param_1,paSetbuttonstate,param_3,uVar5);
    cVar1 = *(char *)(param_1 + 0x1c1);
  }
  else {
    cVar1 = *(char *)(param_1 + 0x1c1);
  }
  if (cVar1 == cVar3) {
loc_F00D49EC:
    uVar2 = *(undefined4 *)(param_1 + 0x110);
  }
  else {
    if (cVar3 == '\0') {
      *(uint *)(*(int *)(param_1 + 0x168) + 0xc) =
           *(uint *)(*(int *)(param_1 + 0x168) + 0xc) & 0xffffff7f;
      _bzero((undefined *)((int)register0x00000038 + -0x20),0xc);
      _objc_msgSend(param_1,paPosteventAtAtt,0xc,param_1 + 0x1a8,uVar5);
      goto loc_F00D49EC;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x110);
  }
  uVar4 = paUnlock;
  *(char *)(param_1 + 0x1c1) = cVar3;
loc_F00D49FC:
  _objc_msgSend(uVar2,uVar4);
  return CONCAT44(param_2,param_1);
}
