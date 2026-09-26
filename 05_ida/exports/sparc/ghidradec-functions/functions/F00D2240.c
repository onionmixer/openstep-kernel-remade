
/* WARNING: Removing unreachable block (ram,0xf00d2348) */
/* WARNING: Removing unreachable block (ram,0xf00d2314) */
/* WARNING: Removing unreachable block (ram,0xf00d22f0) */
/* WARNING: Removing unreachable block (ram,0xf00d22bc) */
/* WARNING: Removing unreachable block (ram,0xf00d2298) */
/* WARNING: Removing unreachable block (ram,0xf00d22a8) */
/* WARNING: Removing unreachable block (ram,0xf00d22cc) */
/* WARNING: Removing unreachable block (ram,0xf00d22fc) */
/* WARNING: Removing unreachable block (ram,0xf00d2338) */
/* WARNING: Removing unreachable block (ram,0xf00d2280) */
/* WARNING: Removing unreachable block (ram,0xf00d2250) */

undefined8
-[EventDriver evClose:token:](int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
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
  
  uVar2 = paLock;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  if (*(char *)(param_1 + 0x1d0) == '\0') {
    uVar2 = *(undefined4 *)(param_1 + 0x110);
  }
  else {
    if (param_4 == *(int *)(param_1 + 0x114)) {
      _objc_msgSend(param_1,paForceautodimst,0);
      _objc_msgSend(param_1,paHidecursor_0);
      uVar1 = paUnlock;
      _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
      _objc_msgSend(param_1,paDetacheventsou);
      if (*(char *)(param_1 + 0x1d2) == '\x01') {
        _objc_msgSend(param_1,paUnmapeventshme,*(undefined4 *)(param_1 + 0x114));
        uVar3 = *(undefined4 *)(param_1 + 0x110);
      }
      else {
        uVar3 = *(undefined4 *)(param_1 + 0x110);
      }
      _objc_msgSend(uVar3,uVar2);
      if (*(int *)(param_1 + 0x180) != 0) {
        _IOFree(*(int *)(param_1 + 0x180),*(undefined4 *)(param_1 + 0x17c));
        *(undefined4 *)(param_1 + 0x180) = 0;
        *(undefined4 *)(param_1 + 0x17c) = 0;
        *(undefined4 *)(param_1 + 0x188) = 0;
        *(undefined4 *)(param_1 + 0x184) = 0;
      }
      _objc_msgSend(param_1,paSeteventport,0);
      *(undefined *)(param_1 + 0x1d0) = 0;
      _objc_msgSend(*(undefined4 *)(param_1 + 0x110),uVar1);
      uVar2 = 0;
      goto locret_F00D2354;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x110);
  }
  _objc_msgSend(uVar2,paUnlock);
  uVar2 = 0xfffffd3e;
locret_F00D2354:
  return CONCAT44(param_2,uVar2);
}
