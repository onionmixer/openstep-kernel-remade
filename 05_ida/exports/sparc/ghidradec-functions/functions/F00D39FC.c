
/* WARNING: Removing unreachable block (ram,0xf00d3ae8) */
/* WARNING: Removing unreachable block (ram,0xf00d3a00) */

undefined8 -[EventDriver scheduleNextPeriodicEvent](int param_1,undefined4 param_2)

{
  uint uVar1;
  char cVar3;
  uint uVar2;
  uint uVar4;
  undefined8 uVar5;
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
  _IOGetTimestamp((undefined *)((int)register0x00000038 + -0x18));
  uVar4 = (uint)*(undefined8 *)((int)register0x00000038 + -0x18);
  uVar2 = uVar4 + 0xa000000;
  uVar4 = (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x18) >> 0x20) +
          (uint)(0xf5ffffff < uVar4);
  uVar5 = CONCAT44(uVar4,uVar2);
  if (*(uint *)((int)register0x00000038 + -0x18) < *(uint *)(param_1 + 0x1f0)) {
    uVar1 = *(uint *)(param_1 + 0x1f0);
loc_F00D3A50:
    if (uVar1 < uVar4) {
      uVar5 = *(undefined8 *)(param_1 + 0x1f0);
loc_F00D3A78:
      cVar3 = *(char *)(param_1 + 0x210);
    }
    else if (uVar4 == uVar1) {
      if (*(uint *)(param_1 + 500) < uVar2) {
        uVar5 = *(undefined8 *)(param_1 + 0x1f0);
        goto loc_F00D3A78;
      }
      cVar3 = *(char *)(param_1 + 0x210);
    }
    else {
      cVar3 = *(char *)(param_1 + 0x210);
    }
  }
  else if (*(uint *)(param_1 + 0x1f0) == *(uint *)((int)register0x00000038 + -0x18)) {
    if (*(uint *)((int)register0x00000038 + -0x14) < *(uint *)(param_1 + 500)) {
      uVar1 = *(uint *)(param_1 + 0x1f0);
      goto loc_F00D3A50;
    }
    cVar3 = *(char *)(param_1 + 0x210);
  }
  else {
    cVar3 = *(char *)(param_1 + 0x210);
  }
  uVar2 = (uint)((qword)uVar5 >> 0x20);
  if (cVar3 == '\0') {
    *(undefined8 *)(param_1 + 0x208) = uVar5;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x208);
    if (uVar2 < uVar4) {
      *(undefined8 *)(param_1 + 0x208) = uVar5;
    }
    else {
      if (uVar4 == uVar2) {
        if ((uint)uVar5 < *(uint *)(param_1 + 0x20c)) {
          *(undefined8 *)(param_1 + 0x208) = uVar5;
          goto loc_F00D3AE0;
        }
        uVar2 = *(uint *)(param_1 + 0x200);
      }
      else {
        uVar2 = *(uint *)(param_1 + 0x200);
      }
      if (uVar2 <= uVar4 && uVar4 != uVar2) goto locret_F00D3AF0;
      if (uVar4 == uVar2) {
        if (*(uint *)(param_1 + 0x204) < *(uint *)(param_1 + 0x20c)) goto locret_F00D3AF0;
        *(undefined8 *)(param_1 + 0x208) = uVar5;
      }
      else {
        *(undefined8 *)(param_1 + 0x208) = uVar5;
      }
    }
  }
loc_F00D3AE0:
  _objc_msgSend(param_1,paRunperiodiceve);
locret_F00D3AF0:
  return CONCAT44(param_2,param_1);
}
