
/* WARNING: Removing unreachable block (ram,0xf0090cf0) */
/* WARNING: Removing unreachable block (ram,0xf0090d1c) */
/* WARNING: Removing unreachable block (ram,0xf0090ccc) */
/* WARNING: Removing unreachable block (ram,0xf0090cd4) */
/* WARNING: Removing unreachable block (ram,0xf0090d38) */
/* WARNING: Removing unreachable block (ram,0xf0090d08) */
/* WARNING: Removing unreachable block (ram,0xf0090cb4) */

undefined8 _kern_IOUnloadDriver(int param_1,undefined (*param_2) [14])

{
  undefined (*pauVar1) [14];
  undefined (*pauVar2) [14];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  if (param_1 == 0) {
    uVar3 = 0xfffffd3f;
  }
  else {
    pauVar1 = paIoconfigtable;
    _objc_msgSend(paIoconfigtable,paNewforconfigda,param_2);
    param_2 = pauVar1;
    _objc_msgSend();
    pauVar2 = param_2;
    _objc_getClass();
    if (pauVar2 == (undefined (*) [14])0x0) {
      _IOLog(aIounloaddriver,param_2);
      if (pauVar1 != (undefined (*) [14])0x0) {
        _objc_msgSend(pauVar1,paFree);
      }
      uVar3 = 0xfffffd3e;
    }
    else {
      _objc_msgSend();
      if (pauVar1 == (undefined (*) [14])0x0) {
        uVar3 = 0;
      }
      else {
        _objc_msgSend(pauVar1,paFree);
        uVar3 = 0;
      }
    }
  }
  return CONCAT44(param_2,uVar3);
}

