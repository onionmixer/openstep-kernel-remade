/* GHIDRADEC_FUNCTION index=4600 start=0xf00d4d8c */

/* WARNING: Removing unreachable block (ram,0xf00d4dc0) */
/* WARNING: Removing unreachable block (ram,0xf00d4d98) */

undefined8 -[EventDriver eventFlags](int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 uVar1;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  uVar1 = 0;
  if (*(char *)(param_1 + 0x1d2) != '\0') {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x168) + 0xc);
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4601 start=0xf00d4dd0 */

/* WARNING: Removing unreachable block (ram,0xf00d4ee8) */
/* WARNING: Removing unreachable block (ram,0xf00d4e0c) */
/* WARNING: Removing unreachable block (ram,0xf00d4ec0) */
/* WARNING: Removing unreachable block (ram,0xf00d4e34) */

undefined8
-[EventDriver _setButtonState:atTime:]
          (int param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x168);
  if ((*(uint *)(iVar2 + 8) & 4) != (param_3 & 4)) {
    if ((param_3 & 4) == 0) {
      _objc_msgSend(param_1,paPosteventAtAtt,2,iVar2 + 0x18,param_4,0);
      uVar1 = *(uint *)(iVar2 + 8) & 0xfffffffb;
    }
    else {
      _objc_msgSend(param_1,paPosteventAtAtt,1,iVar2 + 0x18,param_4,0);
      uVar1 = *(uint *)(iVar2 + 8) | 4;
    }
    *(uint *)(iVar2 + 8) = uVar1;
    *(byte *)(iVar2 + 0x33) = *(byte *)(iVar2 + 0x33) & 0xfd | *(byte *)(iVar2 + 0x33) >> 1 & 2;
    if ((*(byte *)(iVar2 + 0x33) & 2) == 0) {
      uVar1 = *(uint *)(iVar2 + 0xc) & 0xfffffeff;
    }
    else {
      uVar1 = *(uint *)(iVar2 + 0xc) | 0x100;
    }
    *(uint *)(iVar2 + 0xc) = uVar1;
  }
  if ((*(uint *)(iVar2 + 8) & 1) != (param_3 & 1)) {
    if ((param_3 & 1) == 0) {
      _objc_msgSend(param_1,paPosteventAtAtt,4,iVar2 + 0x18,param_4,0);
      uVar1 = *(uint *)(iVar2 + 8) & 0xfffffffe;
    }
    else {
      _objc_msgSend(param_1,paPosteventAtAtt,3,iVar2 + 0x18,param_4,0);
      uVar1 = *(uint *)(iVar2 + 8) | 1;
    }
    *(uint *)(iVar2 + 8) = uVar1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4602 start=0xf00d4f04 */

/* WARNING: Removing unreachable block (ram,0xf00d4f6c) */
/* WARNING: Removing unreachable block (ram,0xf00d4f3c) */

undefined8 -[EventDriver setCursorPosition:](int param_1,undefined4 param_2)

{
  undefined (*pauVar1) [27];
  undefined2 *puVar2;
  undefined8 in_o2_3;
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
  
  puVar2 = (undefined2 *)((qword)in_o2_3 >> 0x20);
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
  if (*(char *)(param_1 + 0x1d2) == '\x01') {
    *(undefined2 *)(param_1 + 0x1a8) = *puVar2;
    *(undefined2 *)(param_1 + 0x1aa) = puVar2[1];
    pauVar1 = paSetcursorposit_0;
    if (*(char *)(param_1 + 0x211) == '\0') {
      _IOGetTimestamp((undefined *)((int)register0x00000038 + -0x18));
      _objc_msgSend(param_1,pauVar1,puVar2);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4603 start=0xf00d4f7c */

/* WARNING: Removing unreachable block (ram,0xf00d52d4) */
/* WARNING: Removing unreachable block (ram,0xf00d5194) */
/* WARNING: Removing unreachable block (ram,0xf00d504c) */
/* WARNING: Removing unreachable block (ram,0xf00d4fb8) */
/* WARNING: Removing unreachable block (ram,0xf00d5120) */
/* WARNING: Removing unreachable block (ram,0xf00d5230) */
/* WARNING: Removing unreachable block (ram,0xf00d52e8) */
/* WARNING: Removing unreachable block (ram,0xf00d4f94) */

undefined8
-[EventDriver _setCursorPosition:atTime:]
          (int param_1,undefined4 param_2,sword *param_3,undefined4 param_4)

{
  sword sVar1;
  int iVar2;
  sword sVar3;
  undefined (*pauVar4) [11];
  undefined4 uVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  int iVar7;
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
  iVar7 = -1;
  iVar6 = *(int *)(param_1 + 0x168);
  if (*(int *)(param_1 + 0x188) == 0) goto locret_F00D52F0;
  iVar2 = iVar6 + 0x14;
  _ev_try_lock();
  if (iVar2 == 0) {
    *(undefined *)(param_1 + 0x211) = 1;
    _objc_msgSend(param_1,paSchedulenextpe);
    goto locret_F00D52F0;
  }
  *(undefined *)(param_1 + 0x211) = 0;
  iVar2 = *(int *)(param_1 + 0x18c) * 0x14 + *(int *)(param_1 + 0x180);
  if ((((*param_3 < *(sword *)(iVar2 + 0xc)) || (*(sword *)(iVar2 + 0xe) <= *param_3)) ||
      (param_3[1] < *(sword *)(iVar2 + 0x10))) || (*(sword *)(iVar2 + 0x12) <= param_3[1])) {
    iVar7 = param_1;
    _objc_msgSend(param_1,paPointtoscreen,param_3);
    if (iVar7 < 0) {
      sVar3 = *param_3;
      sVar1 = *(sword *)(param_1 + 400);
      if ((sVar3 < *(sword *)(param_1 + 400)) ||
         (sVar1 = *(sword *)(param_1 + 0x192), *(sword *)(param_1 + 0x192) < sVar3)) {
        sVar3 = sVar1;
        sVar1 = param_3[1];
      }
      else {
        sVar1 = param_3[1];
      }
      *param_3 = sVar3;
      sVar3 = *(sword *)(param_1 + 0x194);
      if ((sVar1 < sVar3) || (sVar3 = *(sword *)(param_1 + 0x196), sVar3 < sVar1)) {
        param_3[1] = sVar3;
      }
      else {
        param_3[1] = sVar1;
      }
      goto loc_F00D50B8;
    }
    sVar3 = *param_3;
  }
  else {
loc_F00D50B8:
    sVar3 = *param_3;
  }
  *(sword *)(param_1 + 0x1a8) = sVar3;
  *(sword *)(param_1 + 0x1aa) = param_3[1];
  if (*(sword *)(iVar6 + 0x18) == *param_3) {
    if (*(sword *)(iVar6 + 0x1a) != param_3[1]) {
      sVar3 = *param_3;
      goto loc_F00D5104;
    }
  }
  else {
    sVar3 = *param_3;
loc_F00D5104:
    *(sword *)(iVar6 + 0x18) = sVar3;
    *(sword *)(iVar6 + 0x1a) = param_3[1];
    pauVar4 = paMovecursor;
    if (-1 < iVar7) {
      _objc_msgSend(param_1,paHidecursor_0);
      *(int *)(param_1 + 0x18c) = iVar7;
      iVar7 = *(int *)(param_1 + 0x180) + iVar7 * 0x14;
      *(undefined2 *)(param_1 + 400) = *(undefined2 *)(iVar7 + 0xc);
      pauVar4 = paShowcursor;
      *(undefined2 *)(param_1 + 0x192) = *(undefined2 *)(iVar7 + 0xe);
      *(undefined2 *)(param_1 + 0x194) = *(undefined2 *)(iVar7 + 0x10);
      *(undefined2 *)(param_1 + 0x196) = *(undefined2 *)(iVar7 + 0x12);
      *(sword *)(param_1 + 0x192) = *(sword *)(param_1 + 0x192) + -1;
      *(sword *)(param_1 + 0x196) = *(sword *)(param_1 + 0x196) + -1;
    }
    _objc_msgSend(param_1,pauVar4);
    if (*(int *)(iVar6 + 0x34) != 0) {
      if (((*(uint *)(iVar6 + 0x34) & 0x40) == 0) || ((*(uint *)(iVar6 + 8) & 4) == 0)) {
        if (((*(uint *)(iVar6 + 0x34) & 0x80) == 0) || ((*(uint *)(iVar6 + 8) & 1) == 0)) {
          if ((*(uint *)(iVar6 + 0x34) & 0x20) == 0) goto loc_F00D5238;
          uVar5 = 5;
        }
        else {
          uVar5 = 7;
        }
      }
      else {
        uVar5 = 6;
      }
      _objc_msgSend(param_1,paPosteventAtAtt,uVar5,param_3,param_4,0);
    }
loc_F00D5238:
    if (((*(byte *)(iVar6 + 0x33) & 1) != 0) &&
       (((((*param_3 < *(sword *)(iVar6 + 0x28) || (*(sword *)(iVar6 + 0x2a) <= *param_3)) ||
          (param_3[1] < *(sword *)(iVar6 + 0x2c))) || (*(sword *)(iVar6 + 0x2e) <= param_3[1])) &&
        ((*(byte *)(iVar6 + 0x33) & 1) != 0)))) {
      _objc_msgSend(param_1,paPosteventAtAtt,9,param_3,param_4,0);
      *(byte *)(iVar6 + 0x33) = *(byte *)(iVar6 + 0x33) & 0xfe;
    }
  }
  _ev_unlock(iVar6 + 0x14);
locret_F00D52F0:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4604 start=0xf00d52f8 */

/* WARNING: Removing unreachable block (ram,0xf00d5308) */

undefined8 sub_F00D52F8(int param_1,undefined4 param_2)

{
  undefined (*pauVar1) [15];
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
  
  pauVar1 = paPeriodicevents;
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
  *(undefined *)(param_1 + 0x210) = 0;
  _objc_msgSend(param_1,pauVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4605 start=0xf00d5638 */

/* WARNING: Removing unreachable block (ram,0xf00d5658) */
/* WARNING: Removing unreachable block (ram,0xf00d5648) */

undefined8 +[IOEventSource registerEventSource:](undefined4 param_1,undefined4 param_2)

{
  undefined (*pauVar1) [12];
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
  pauVar1 = paEventdriver_0;
  _objc_msgSend(paEventdriver_0,paInstance);
  _objc_msgSend();
  return CONCAT44(param_2,pauVar1);
}
/* GHIDRADEC_FUNCTION index=4606 start=0xf00d5668 */

/* WARNING: Removing unreachable block (ram,0xf00d56a8) */
/* WARNING: Removing unreachable block (ram,0xf00d56bc) */
/* WARNING: Removing unreachable block (ram,0xf00d5684) */

undefined8 -[IOEventSource init](int param_1,undefined4 param_2)

{
  undefined7 *puVar1;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142208;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  if (*(int *)(param_1 + 0x110) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x110),paFree);
  }
  puVar1 = paNxlock;
  _objc_msgSend(paNxlock,paNew);
  *(undefined7 **)(param_1 + 0x110) = puVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4607 start=0xf00d56d0 */

/* WARNING: Removing unreachable block (ram,0xf00d5708) */
/* WARNING: Removing unreachable block (ram,0xf00d56e8) */

undefined8 -[IOEventSource free](int param_1,undefined4 param_2)

{
  undefined *puVar1;
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
  if (*(int *)(param_1 + 0x110) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x110),paFree);
  }
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142208;
  _objc_msgSendSuper(puVar1,paFree);
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=4608 start=0xf00d5718 */

undefined8 -[IOEventSource owner](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x108));
}
/* GHIDRADEC_FUNCTION index=4609 start=0xf00d5728 */

undefined8 -[IOEventSource ownerLock](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x110));
}
/* GHIDRADEC_FUNCTION index=4610 start=0xf00d5738 */

/* WARNING: Removing unreachable block (ram,0xf00d5788) */
/* WARNING: Removing unreachable block (ram,0xf00d57ac) */
/* WARNING: Removing unreachable block (ram,0xf00d576c) */
/* WARNING: Removing unreachable block (ram,0xf00d57b8) */
/* WARNING: Removing unreachable block (ram,0xf00d57e0) */
/* WARNING: Removing unreachable block (ram,0xf00d5744) */

undefined8 -[IOEventSource becomeOwner:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined (*pauVar1) [21];
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  pauVar1 = paRelinquishowne_0;
  uVar2 = *(uint *)(param_1 + 0x108);
  if (uVar2 == 0) {
    *(undefined4 *)(param_1 + 0x108) = param_3;
    iVar5 = 0;
  }
  else {
    _objc_msgSend(uVar2,paRespondsto,paRelinquishowne_0);
    if ((uVar2 & 0xff) == 0) {
      iVar5 = -0x2d5;
      iVar3 = param_1;
      _objc_msgSend(param_1,paName);
      _IOLog(aSOwnerDoesNotR,iVar3);
    }
    else {
      iVar5 = *(int *)(param_1 + 0x108);
      _objc_msgSend(iVar5,pauVar1,param_1);
    }
    if (iVar5 != 0) {
      uVar4 = *(undefined4 *)(param_1 + 0x110);
      goto loc_F00D57DC;
    }
    *(undefined4 *)(param_1 + 0x108) = param_3;
  }
  uVar4 = *(undefined4 *)(param_1 + 0x110);
loc_F00D57DC:
  _objc_msgSend(uVar4,paUnlock);
  return CONCAT44(param_2,iVar5);
}
/* GHIDRADEC_FUNCTION index=4611 start=0xf00d57f0 */

/* WARNING: Removing unreachable block (ram,0xf00d58a0) */
/* WARNING: Removing unreachable block (ram,0xf00d585c) */
/* WARNING: Removing unreachable block (ram,0xf00d5824) */
/* WARNING: Removing unreachable block (ram,0xf00d5894) */
/* WARNING: Removing unreachable block (ram,0xf00d5878) */
/* WARNING: Removing unreachable block (ram,0xf00d57fc) */

undefined8 -[IOEventSource relinquishOwnership:](int param_1,undefined4 param_2,uint param_3)

{
  undefined (*pauVar1) [16];
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  iVar3 = -0x2d5;
  if (*(uint *)(param_1 + 0x108) == param_3) {
    iVar3 = 0;
    *(undefined4 *)(param_1 + 0x108) = 0;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
  pauVar1 = paCanbecomeowner;
  if (iVar3 == 0) {
    uVar2 = *(uint *)(param_1 + 0x10c);
    if ((uVar2 != 0) && (uVar2 != param_3)) {
      _objc_msgSend(uVar2,paRespondsto,paCanbecomeowner);
      if ((uVar2 & 0xff) == 0) {
        _objc_msgSend(param_1,paName);
        _IOLog(aSDesiredownerD,param_1);
      }
      else {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x10c),pauVar1,param_1);
      }
    }
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=4612 start=0xf00d58b0 */

/* WARNING: Removing unreachable block (ram,0xf00d58f4) */
/* WARNING: Removing unreachable block (ram,0xf00d58bc) */

undefined8 -[IOEventSource desireOwnership:](int param_1,undefined4 param_2,int param_3)

{
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
  undefined4 uVar1;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  if (*(int *)(param_1 + 0x10c) == 0) {
    *(int *)(param_1 + 0x10c) = param_3;
  }
  else {
    if (*(int *)(param_1 + 0x10c) != param_3) {
      uVar1 = 0xfffffd2b;
      goto loc_F00D58EC;
    }
    *(int *)(param_1 + 0x10c) = param_3;
  }
  uVar1 = 0;
loc_F00D58EC:
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4613 start=0xf00d5904 */

/* WARNING: Removing unreachable block (ram,0xf00d5c74) */
/* WARNING: Removing unreachable block (ram,0xf00d5c88) */
/* WARNING: Removing unreachable block (ram,0xf00d5c7c) */
/* WARNING: Removing unreachable block (ram,0xf00d5c94) */
/* WARNING: Removing unreachable block (ram,0xf00d5910) */

undefined8
-[KeyMap _parseKeyMapping:length:into:]
          (undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined2 *param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  word *pwVar5;
  uint uVar6;
  word wVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 unaff_l0;
  int iVar11;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar12;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar13;
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
  iVar11 = -1;
  _bzero(param_5,0x4f0);
  *(undefined4 *)(param_5 + 0x42) = 0xffffffff;
  *(undefined4 *)(param_5 + 100) = 0xffffffff;
  *(undefined4 *)(param_5 + 0x166) = 0xffffffff;
  *(int *)((int)register0x00000038 + -0x1c) = param_3 + param_4;
  *(int *)((int)register0x00000038 + -0x20) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 1;
  *(int *)(param_5 + 0x274) = param_3;
  *(int *)(param_5 + 0x276) = param_4;
  pwVar5 = *(word **)((int)register0x00000038 + -0x20);
  uVar3 = 0;
  if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
    if (*(int *)((int)register0x00000038 + -0x18) == 0) {
      *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
      uVar3 = (uint)*(byte *)pwVar5;
    }
    else {
      *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
      uVar3 = (uint)*pwVar5;
    }
  }
  *(uint *)((int)register0x00000038 + -0x18) = uVar3;
  *param_5 = (sword)uVar3;
  pwVar5 = *(word **)((int)register0x00000038 + -0x20);
  uVar3 = 0;
  if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
    if (*(int *)((int)register0x00000038 + -0x18) == 0) {
      *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
      uVar3 = (uint)*(byte *)pwVar5;
    }
    else {
      *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
      uVar3 = (uint)*pwVar5;
    }
  }
  iVar2 = 0;
  pwVar5 = *(word **)((int)register0x00000038 + -0x20);
  if (uVar3 != 0) {
    do {
      uVar8 = 0;
      if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
        if (*(int *)((int)register0x00000038 + -0x18) == 0) {
          *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
          uVar8 = (uint)*(byte *)pwVar5;
        }
        else {
          *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
          uVar8 = (uint)*pwVar5;
        }
      }
      if (0xf < uVar8) {
        param_1 = 0;
        goto locret_F00D5F7C;
      }
      if (*(int *)(param_5 + 0x42) < (int)uVar8) {
        *(uint *)(param_5 + 0x42) = uVar8;
      }
      *(undefined4 *)(param_5 + uVar8 * 2 + 0x44) = *(undefined4 *)((int)register0x00000038 + -0x20)
      ;
      pwVar5 = *(word **)((int)register0x00000038 + -0x20);
      iVar9 = 0;
      if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
        if (*(int *)((int)register0x00000038 + -0x18) == 0) {
          *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
          uVar12 = (uint)*(byte *)pwVar5;
        }
        else {
          *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
          uVar12 = (uint)*pwVar5;
        }
      }
      else {
        uVar12 = 0;
      }
      if (uVar12 != 0) {
        do {
          pwVar5 = *(word **)((int)register0x00000038 + -0x20);
          if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
            if (*(int *)((int)register0x00000038 + -0x18) == 0) {
              *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
              uVar6 = (uint)*(byte *)pwVar5;
            }
            else {
              *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
              uVar6 = (uint)*pwVar5;
            }
          }
          else {
            uVar6 = 0;
          }
          if ((0x7f < uVar6) || (bVar1 = *(byte *)((int)param_5 + uVar6 + 2), (bVar1 & 0x10) != 0))
          goto loc_F00D5F3C;
          iVar9 = iVar9 + 1;
          *(byte *)((int)param_5 + uVar6 + 2) = bVar1 | (byte)uVar8 & 0xf | 0x10;
        } while (iVar9 < (int)uVar12);
      }
      iVar2 = iVar2 + 1;
      pwVar5 = *(word **)((int)register0x00000038 + -0x20);
    } while (iVar2 < (int)uVar3);
  }
  uVar3 = 0;
  if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
    if (*(int *)((int)register0x00000038 + -0x18) == 0) {
      *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
      uVar3 = (uint)*(byte *)pwVar5;
    }
    else {
      *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
      uVar3 = (uint)*pwVar5;
    }
  }
  *(uint *)(param_5 + 100) = uVar3;
  iVar2 = 0;
  puVar4 = param_5;
  do {
    if (iVar2 < (int)uVar3) {
      *(undefined4 *)(puVar4 + 0x66) = *(undefined4 *)((int)register0x00000038 + -0x20);
      pwVar5 = *(word **)((int)register0x00000038 + -0x20);
      uVar8 = 0;
      if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
        if (*(int *)((int)register0x00000038 + -0x18) == 0) {
          *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
          uVar8 = (uint)*(byte *)pwVar5;
        }
        else {
          *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
          uVar8 = (uint)*pwVar5;
        }
      }
      if (*(int *)((int)register0x00000038 + -0x18) == 0) {
        if (uVar8 != 0xff) goto loc_F00D5BD4;
        *(undefined4 *)(puVar4 + 0x66) = 0;
      }
      else if (uVar8 == 0xffff) {
        *(undefined4 *)(puVar4 + 0x66) = 0;
      }
      else {
loc_F00D5BD4:
        iVar9 = 0;
        *(byte *)((int)param_5 + iVar2 + 2) = *(byte *)((int)param_5 + iVar2 + 2) | 0x20;
        iVar10 = 1;
        if (*(uint *)(param_5 + 0x42) < 0x80000000) {
          do {
            if ((uVar8 & 1) != 0) {
              iVar10 = iVar10 << 1;
            }
            iVar9 = iVar9 + 1;
            uVar8 = (int)uVar8 >> 1;
          } while (iVar9 <= (int)*(uint *)(param_5 + 0x42));
        }
        iVar9 = 0;
        if (0 < iVar10) {
          pwVar5 = *(word **)((int)register0x00000038 + -0x20);
          do {
            wVar7 = 0;
            if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
              if (*(int *)((int)register0x00000038 + -0x18) == 0) {
                *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
                wVar7 = (word)*(byte *)pwVar5;
              }
              else {
                *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
                wVar7 = *pwVar5;
              }
            }
            if (*(int *)((int)register0x00000038 + -0x18) == 0) {
              if (wVar7 == 0xff) goto loc_F00D5CC0;
            }
            else if (wVar7 == 0xffff) {
loc_F00D5CC0:
              if (iVar11 < 0) {
                iVar11 = 0;
              }
            }
            iVar9 = iVar9 + 1;
            pwVar5 = *(word **)((int)register0x00000038 + -0x20);
          } while (iVar9 < iVar10);
        }
      }
    }
    else {
      *(undefined4 *)(puVar4 + 0x66) = 0;
    }
    iVar2 = iVar2 + 1;
    puVar4 = puVar4 + 2;
  } while (iVar2 < 0x80);
  pwVar5 = *(word **)((int)register0x00000038 + -0x20);
  uVar3 = 0;
  if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
    if (*(int *)((int)register0x00000038 + -0x18) == 0) {
      *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
      uVar3 = (uint)*(byte *)pwVar5;
    }
    else {
      *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
      uVar3 = (uint)*pwVar5;
    }
  }
  *(uint *)(param_5 + 0x166) = uVar3;
  if (iVar11 < (int)uVar3) {
    iVar11 = 0;
    pwVar5 = *(word **)((int)register0x00000038 + -0x20);
    puVar4 = param_5;
    if (uVar3 != 0) {
      do {
        *(undefined4 *)(puVar4 + 0x168) = *(undefined4 *)((int)register0x00000038 + -0x20);
        pwVar5 = *(word **)((int)register0x00000038 + -0x20);
        iVar2 = 0;
        if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
          if (*(int *)((int)register0x00000038 + -0x18) == 0) {
            *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
            uVar3 = (uint)*(byte *)pwVar5;
          }
          else {
            *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
            uVar3 = (uint)*pwVar5;
          }
        }
        else {
          uVar3 = 0;
        }
        if (uVar3 == 0) {
          iVar2 = *(int *)(param_5 + 0x166);
        }
        else {
          uVar8 = *(uint *)((int)register0x00000038 + -0x20);
          do {
            if (uVar8 < *(uint *)((int)register0x00000038 + -0x1c)) {
              if (*(int *)((int)register0x00000038 + -0x18) == 0) {
                iVar9 = uVar8 + 1;
              }
              else {
                iVar9 = uVar8 + 2;
              }
              *(int *)((int)register0x00000038 + -0x20) = iVar9;
            }
            uVar8 = *(uint *)((int)register0x00000038 + -0x20);
            if (uVar8 < *(uint *)((int)register0x00000038 + -0x1c)) {
              if (*(int *)((int)register0x00000038 + -0x18) == 0) {
                iVar9 = uVar8 + 1;
              }
              else {
                iVar9 = uVar8 + 2;
              }
              *(int *)((int)register0x00000038 + -0x20) = iVar9;
            }
            iVar2 = iVar2 + 1;
            uVar8 = *(uint *)((int)register0x00000038 + -0x20);
          } while (iVar2 < (int)uVar3);
          iVar2 = *(int *)(param_5 + 0x166);
        }
        iVar11 = iVar11 + 1;
        puVar4 = puVar4 + 2;
      } while (iVar11 < iVar2);
      pwVar5 = *(word **)((int)register0x00000038 + -0x20);
    }
    uVar3 = 0;
    if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
      if (*(int *)((int)register0x00000038 + -0x18) == 0) {
        *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
        uVar3 = (uint)*(byte *)pwVar5;
      }
      else {
        *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
        uVar3 = (uint)*pwVar5;
      }
    }
    if (9 < uVar3) {
      param_1 = 0;
      goto locret_F00D5F7C;
    }
    if (uVar3 != 0) {
      param_5[0x272] = 0xffff;
      puVar4 = param_5 + 8;
      while ((int)param_5 <= (int)(puVar4 + -1)) {
        puVar4[0x269] = 0xffff;
        puVar4 = puVar4 + -1;
      }
      iVar11 = 0;
      if (uVar3 != 0) {
        do {
          pwVar5 = *(word **)((int)register0x00000038 + -0x20);
          uVar8 = 0;
          bVar13 = false;
          if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
            if (*(int *)((int)register0x00000038 + -0x18) == 0) {
              *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
              uVar8 = (uint)*(byte *)pwVar5;
            }
            else {
              *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
              uVar8 = (uint)*pwVar5;
            }
            pwVar5 = *(word **)((int)register0x00000038 + -0x20);
            bVar13 = pwVar5 < *(word **)((int)register0x00000038 + -0x1c);
          }
          if (bVar13) {
            if (*(int *)((int)register0x00000038 + -0x18) == 0) {
              *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
              wVar7 = (word)*(byte *)pwVar5;
            }
            else {
              *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
              wVar7 = *pwVar5;
            }
          }
          else {
            wVar7 = 0;
          }
          if (8 < uVar8) goto loc_F00D5F3C;
          iVar11 = iVar11 + 1;
          param_5[uVar8 + 0x26a] = wVar7;
        } while (iVar11 < (int)uVar3);
      }
      iVar11 = 0;
      puVar4 = param_5;
      do {
        uVar3 = (uint)(word)puVar4[0x26a];
        iVar11 = iVar11 + 1;
        if (uVar3 != 0xffff) {
          *(byte *)((int)param_5 + uVar3 + 2) = *(byte *)((int)param_5 + uVar3 + 2) | 0x60;
        }
        puVar4 = puVar4 + 1;
      } while (iVar11 < 7);
      goto locret_F00D5F7C;
    }
  }
loc_F00D5F3C:
  param_1 = 0;
locret_F00D5F7C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4614 start=0xf00d5f84 */

/* WARNING: Removing unreachable block (ram,0xf00d5fe8) */
/* WARNING: Removing unreachable block (ram,0xf00d5fc4) */
/* WARNING: Removing unreachable block (ram,0xf00d6000) */
/* WARNING: Removing unreachable block (ram,0xf00d5fa0) */

undefined8
-[KeyMap initFromKeyMapping:length:canFree:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,char param_5)

{
  undefined4 uVar1;
  int iVar2;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142230;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  if (*(int *)(param_1 + 0x4f4) == 0) {
    uVar1 = paNxlock;
    _objc_msgSend(paNxlock,paNew);
    *(undefined4 *)(param_1 + 0x4f4) = uVar1;
  }
  iVar2 = param_1;
  _objc_msgSend(param_1,paSetkeymappingL,param_3,param_4,(int)param_5);
  if (iVar2 == 0) {
    _objc_msgSend(param_1,paFree);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4615 start=0xf00d6014 */

/* WARNING: Removing unreachable block (ram,0xf00d6088) */
/* WARNING: Removing unreachable block (ram,0xf00d604c) */
/* WARNING: Removing unreachable block (ram,0xf00d6078) */
/* WARNING: Removing unreachable block (ram,0xf00d609c) */
/* WARNING: Removing unreachable block (ram,0xf00d602c) */

undefined8
-[KeyMap setKeyMapping:length:canFree:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined param_5)

{
  undefined4 uVar1;
  int iVar2;
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
  iVar2 = param_1;
  _objc_msgSend(param_1,paParsekeymappin,param_3,param_4,
                (undefined *)((int)register0x00000038 + -0x500));
  if (iVar2 == 0) {
    param_1 = 0;
  }
  else {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x4f4),paLock);
    if ((*(int *)(param_1 + 0x4ec) != 0) && (*(char *)(param_1 + 0x4fc) == '\x01')) {
      _IOFree(*(int *)(param_1 + 0x4ec),*(undefined4 *)(param_1 + 0x4f0));
    }
    _bcopy((undefined *)((int)register0x00000038 + -0x500),param_1 + 4,0x4f0);
    uVar1 = paUnlock;
    *(undefined *)(param_1 + 0x4fc) = param_5;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x4f4),uVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4616 start=0xf00d60ac */

undefined8 -[KeyMap keyMapping:](int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(param_1 + 0x4ec);
  }
  else {
    *param_3 = *(undefined4 *)(param_1 + 0x4f0);
    uVar1 = *(undefined4 *)(param_1 + 0x4ec);
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4617 start=0xf00d60d0 */

undefined8 -[KeyMap keyMappingLength](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x4f0));
}
/* GHIDRADEC_FUNCTION index=4618 start=0xf00d60e0 */

/* WARNING: Removing unreachable block (ram,0xf00d6144) */
/* WARNING: Removing unreachable block (ram,0xf00d611c) */
/* WARNING: Removing unreachable block (ram,0xf00d6130) */
/* WARNING: Removing unreachable block (ram,0xf00d6160) */
/* WARNING: Removing unreachable block (ram,0xf00d60ec) */

undefined8 -[KeyMap free](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar3;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x4f4),paLock);
  uVar3 = *(undefined4 *)(param_1 + 0x4f4);
  *(undefined4 *)(param_1 + 0x4f4) = 0;
  if ((*(int *)(param_1 + 0x4ec) != 0) && (*(char *)(param_1 + 0x4fc) == '\x01')) {
    _IOFree(*(int *)(param_1 + 0x4ec),*(undefined4 *)(param_1 + 0x4f0));
    *(undefined4 *)(param_1 + 0x4ec) = 0;
  }
  _objc_msgSend(uVar3,paUnlock);
  uVar1 = paFree;
  _objc_msgSend(uVar3,paFree);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0142230;
  _objc_msgSendSuper(puVar2,uVar1);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4619 start=0xf00d6170 */

/* WARNING: Removing unreachable block (ram,0xf00d61a8) */
/* WARNING: Removing unreachable block (ram,0xf00d61b4) */
/* WARNING: Removing unreachable block (ram,0xf00d6184) */

undefined8 -[KeyMap setDelegate:](int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
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
  uVar1 = param_3;
  _objc_msgSend(param_3,paConformsto,stru_F0145ADC);
  if ((uVar1 & 0xff) == 0) {
    _object_getClassName(param_3);
    _IOLog(aKeymapSetdeleg,param_3);
  }
  else {
    *(uint *)(param_1 + 0x4f8) = param_3;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4620 start=0xf00d61c4 */

undefined8 -[KeyMap delegate](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x4f8));
}
/* GHIDRADEC_FUNCTION index=4621 start=0xf00d61d4 */

/* WARNING: Removing unreachable block (ram,0xf00d62c4) */
/* WARNING: Removing unreachable block (ram,0xf00d62a0) */
/* WARNING: Removing unreachable block (ram,0xf00d6244) */
/* WARNING: Removing unreachable block (ram,0xf00d62d4) */
/* WARNING: Removing unreachable block (ram,0xf00d61e0) */

undefined8
-[KeyMap doKeyboardEvent:direction:keyBits:]
          (int param_1,undefined4 param_2,uint param_3,char param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  undefined (*pauVar3) [22];
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x4f4),paLock);
  if (*(int *)(param_1 + 0x4ec) != 0) {
    bVar1 = *(byte *)(param_1 + param_3 + 6);
    if (param_4 == 1) {
      iVar2 = (param_3 >> 5) * 4;
      *(uint *)(param_5 + iVar2) = *(uint *)(param_5 + iVar2) | 1 << ((byte)param_3 & 0x1f);
      if ((bVar1 & 0x10) != 0) {
        _objc_msgSend(param_1,paDomodcalcKeybi,param_3,param_5);
      }
      if ((bVar1 & 0x20) == 0) goto loc_F00D62CC;
      param_5 = 1;
      pauVar3 = paDochargenDirec;
    }
    else {
      iVar2 = (param_3 >> 5) * 4;
      *(uint *)(param_5 + iVar2) = *(uint *)(param_5 + iVar2) & ~(1 << ((byte)param_3 & 0x1f));
      if ((bVar1 & 0x20) != 0) {
        _objc_msgSend(param_1,paDochargenDirec,param_3,(int)param_4);
      }
      pauVar3 = (undefined (*) [22])paDomodcalcKeybi;
      if ((bVar1 & 0x10) == 0) goto loc_F00D62CC;
    }
    _objc_msgSend(param_1,pauVar3,param_3,param_5);
  }
loc_F00D62CC:
  _objc_msgSend(*(undefined4 *)(param_1 + 0x4f4),paUnlock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4622 start=0xf00d62e4 */

/* WARNING: Removing unreachable block (ram,0xf00d648c) */
/* WARNING: Removing unreachable block (ram,0xf00d644c) */
/* WARNING: Removing unreachable block (ram,0xf00d64c8) */
/* WARNING: Removing unreachable block (ram,0xf00d6420) */
/* WARNING: Removing unreachable block (ram,0xf00d6468) */
/* WARNING: Removing unreachable block (ram,0xf00d64dc) */
/* WARNING: Removing unreachable block (ram,0xf00d62fc) */

undefined8 -[KeyMap _calcModBit:keyBits:](int param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined (*pauVar4) [18];
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  undefined4 unaff_l0;
  uint uVar8;
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
  bool bVar9;
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
  uVar1 = *(uint *)(param_1 + 0x4f8);
  uVar8 = 1 << ((char)param_3 + 0x10U & 0x1f);
  _objc_msgSend(uVar1,paDeviceflags);
  pbVar5 = *(byte **)(param_1 + param_3 * 4 + 0x8c);
  uVar1 = uVar1 & ~uVar8;
  if (pbVar5 == (byte *)0x0) {
loc_F00D63A8:
    bVar9 = false;
  }
  else {
    iVar6 = 0;
    if (*(sword *)(param_1 + 4) == 0) {
      uVar7 = (uint)*pbVar5;
      pbVar5 = pbVar5 + 1;
    }
    else {
      uVar7 = (uint)*(sword *)pbVar5;
      pbVar5 = pbVar5 + 2;
    }
    if (0 < (int)uVar7) {
      do {
        if (*(sword *)(param_1 + 4) == 0) {
          uVar3 = (uint)*pbVar5;
          pbVar5 = pbVar5 + 1;
        }
        else {
          uVar3 = (uint)*(sword *)pbVar5;
          pbVar5 = pbVar5 + 2;
        }
        iVar6 = iVar6 + 1;
        if ((*(uint *)(param_4 + (uVar3 >> 5) * 4) & 1 << ((byte)uVar3 & 0x1f)) != 0) {
          bVar9 = true;
          goto loc_F00D63AC;
        }
      } while (iVar6 < (int)uVar7);
      goto loc_F00D63A8;
    }
    bVar9 = false;
  }
loc_F00D63AC:
  if (bVar9) {
    uVar1 = uVar1 | uVar8;
  }
  if (param_3 == 1) {
    if ((((uVar1 & 0x100000) != 0) && (*(int *)(param_1 + 0x8c) == 0)) &&
       (*(sword *)(param_1 + 0x4e0) == -1)) {
      bVar9 = false;
      if ((uVar1 & 0x20000) == 0) {
        uVar8 = *(uint *)(param_1 + 0x4f8);
        _objc_msgSend(uVar8,paCharkeyactive,0);
        pauVar4 = (undefined (*) [18])paSetalphalock;
        if ((uVar8 & 0xff) != 0) goto loc_F00D6478;
        uVar7 = *(uint *)(param_1 + 0x4f8);
        uVar8 = uVar7;
        _objc_msgSend(uVar7,paAlphalock);
        bVar9 = (uVar8 & 0xff) == 0;
      }
      else {
        uVar7 = *(uint *)(param_1 + 0x4f8);
        pauVar4 = paSetcharkeyacti;
      }
      _objc_msgSend(uVar7,pauVar4,bVar9);
    }
loc_F00D6478:
    uVar8 = uVar1 & 0xfffeffff;
    uVar2 = *(undefined4 *)(param_1 + 0x4f8);
    _objc_msgSend(uVar2,paAlphalock,uVar1 & 0x20000);
    uVar1 = uVar8 | (uVar1 & 0x20000) >> 1;
    if ((char)uVar2 == '\x01') {
      uVar1 = uVar8 | 0x10000;
    }
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x4f8);
    if (param_3 != 0) goto loc_F00D64D4;
    _objc_msgSend(uVar2,paSetalphalock,uVar1 >> 0x10 & 1);
  }
  uVar2 = *(undefined4 *)(param_1 + 0x4f8);
loc_F00D64D4:
  _objc_msgSend(uVar2,paSetdeviceflags,uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4623 start=0xf00d64ec */

/* WARNING: Removing unreachable block (ram,0xf00d652c) */
/* WARNING: Removing unreachable block (ram,0xf00d6574) */
/* WARNING: Removing unreachable block (ram,0xf00d6584) */
/* WARNING: Removing unreachable block (ram,0xf00d6558) */
/* WARNING: Removing unreachable block (ram,0xf00d6510) */

undefined8
-[KeyMap _doModCalc:keyBits:](int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  undefined (*pauVar2) [18];
  undefined4 uVar3;
  undefined4 unaff_l0;
  undefined4 uVar4;
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
  bVar1 = *(byte *)(param_1 + param_3 + 6);
  if ((bVar1 & 0x10) != 0) {
    _objc_msgSend(param_1,paCalcmodbitKeyb,bVar1 & 0xf,param_4);
    pauVar2 = paUpdateeventfla;
    if ((bVar1 & 0x20) == 0) {
      uVar3 = *(undefined4 *)(param_1 + 0x4f8);
      _objc_msgSend(uVar3,paEventflags);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),paKeyboardeventF,0xc,uVar3,param_3,0,0,0,0);
    }
    else {
      uVar4 = *(undefined4 *)(param_1 + 0x4f8);
      uVar3 = uVar4;
      _objc_msgSend(uVar4,paEventflags);
      _objc_msgSend(uVar4,pauVar2,uVar3);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4624 start=0xf00d6594 */

/* WARNING: Removing unreachable block (ram,0xf00d6a38) */
/* WARNING: Removing unreachable block (ram,0xf00d69ec) */
/* WARNING: Removing unreachable block (ram,0xf00d69a8) */
/* WARNING: Removing unreachable block (ram,0xf00d68fc) */
/* WARNING: Removing unreachable block (ram,0xf00d6858) */
/* WARNING: Removing unreachable block (ram,0xf00d67d0) */
/* WARNING: Removing unreachable block (ram,0xf00d65cc) */
/* WARNING: Removing unreachable block (ram,0xf00d67e4) */
/* WARNING: Removing unreachable block (ram,0xf00d68d0) */
/* WARNING: Removing unreachable block (ram,0xf00d6950) */
/* WARNING: Removing unreachable block (ram,0xf00d69d8) */
/* WARNING: Removing unreachable block (ram,0xf00d6a0c) */
/* WARNING: Removing unreachable block (ram,0xf00d6a64) */
/* WARNING: Removing unreachable block (ram,0xf00d65a8) */

undefined8 -[KeyMap _doCharGen:direction:](int param_1,uint param_2,uint param_3,char param_4)

{
  sword sVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  word wVar11;
  undefined4 uVar10;
  uint uVar12;
  undefined4 unaff_l0;
  word *pwVar13;
  byte *pbVar14;
  undefined4 unaff_l1;
  int iVar15;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 uVar16;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar17;
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
  uVar16 = 0xb;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),paSetcharkeyacti,1);
  if (param_4 == '\x01') {
    uVar16 = 10;
  }
  uVar4 = *(uint *)(param_1 + 0x4f8);
  _objc_msgSend(uVar4,paEventflags);
  pwVar13 = *(word **)(param_3 * 4 + param_1 + 0xd0);
  sVar1 = *(sword *)(param_1 + 4);
  uVar5 = uVar4 >> 0x10;
  uVar8 = uVar4;
  if (pwVar13 == (word *)0x0) goto loc_F00D6958;
  if (sVar1 == 0) {
    wVar11 = (word)*(byte *)pwVar13;
    pwVar13 = (word *)((int)pwVar13 + 1);
  }
  else {
    wVar11 = *pwVar13;
    pwVar13 = pwVar13 + 1;
  }
  if ((wVar11 != 0) && (uVar5 != 0)) {
    iVar9 = 2;
    if (sVar1 != 0) {
      iVar9 = 4;
    }
    iVar15 = 0;
    if (*(uint *)(param_1 + 0x88) < 0x80000000) {
      do {
        if ((wVar11 & 1) != 0) {
          if ((uVar5 & 1) != 0) {
            pwVar13 = (word *)((int)pwVar13 + iVar9);
          }
          iVar9 = iVar9 << 1;
        }
        wVar11 = (sword)wVar11 >> 1;
        iVar15 = iVar15 + 1;
        uVar5 = (int)uVar5 >> 1;
      } while (iVar15 <= (int)*(uint *)(param_1 + 0x88));
    }
  }
  if (sVar1 == 0) {
    uVar5 = (uint)*(byte *)pwVar13;
    uVar12 = (uint)(byte)*pwVar13;
  }
  else {
    uVar5 = (uint)(sword)*pwVar13;
    uVar12 = (uint)(sword)pwVar13[1];
  }
  pwVar13 = *(word **)(param_3 * 4 + param_1 + 0xd0);
  uVar6 = uVar4 >> 0x10 & 3;
  if (sVar1 == 0) {
    wVar11 = (word)*(byte *)pwVar13;
    pwVar13 = (word *)((int)pwVar13 + 1);
  }
  else {
    wVar11 = *pwVar13;
    pwVar13 = pwVar13 + 1;
  }
  if ((wVar11 != 0) && (uVar6 != 0)) {
    iVar9 = 2;
    if (sVar1 != 0) {
      iVar9 = 4;
    }
    iVar15 = 0;
    if (*(uint *)(param_1 + 0x88) < 0x80000000) {
      do {
        if ((wVar11 & 1) != 0) {
          if ((uVar6 & 1) != 0) {
            pwVar13 = (word *)((int)pwVar13 + iVar9);
          }
          iVar9 = iVar9 << 1;
        }
        wVar11 = (sword)wVar11 >> 1;
        iVar15 = iVar15 + 1;
        uVar6 = (int)uVar6 >> 1;
      } while (iVar15 <= (int)*(uint *)(param_1 + 0x88));
    }
  }
  if (sVar1 == 0) {
    uVar3 = (uint)*(byte *)pwVar13;
    uVar6 = (uint)(byte)*pwVar13;
    if (uVar5 != 0xff) goto loc_F00D6930;
loc_F00D6788:
    pbVar14 = *(byte **)(uVar12 * 4 + param_1 + 0x2d4);
    iVar9 = 0;
    if (sVar1 == 0) {
      uVar5 = (uint)*pbVar14;
      pbVar14 = pbVar14 + 1;
    }
    else {
      uVar5 = (uint)*(sword *)pbVar14;
      pbVar14 = pbVar14 + 2;
    }
    iVar15 = 0;
    if (0 < (int)uVar5) {
      do {
        iVar15 = iVar9;
        .rem(iVar9,10);
        if (iVar15 == 9) {
          _thread_block();
        }
        if (sVar1 == 0) {
          uVar12 = (uint)*pbVar14;
          pbVar14 = pbVar14 + 1;
        }
        else {
          uVar12 = (uint)*(sword *)pbVar14;
          pbVar14 = pbVar14 + 2;
        }
        if (uVar12 == 0xff) {
          if (param_4 == '\x01') {
            if (sVar1 != 0) {
              bVar2 = (byte)*(sword *)pbVar14;
              pbVar14 = pbVar14 + 2;
            }
            else {
              bVar2 = *pbVar14;
              pbVar14 = pbVar14 + 1;
            }
            uVar3 = uVar8 | 1 << (bVar2 + 0x10 & 0x1f);
            uVar8 = *(uint *)(param_1 + 0x4f8);
            _objc_msgSend(uVar8,paDeviceflags);
            uVar7 = *(undefined4 *)(param_1 + 0x4f8);
            uVar6 = 0;
            uVar12 = 0;
            uVar10 = 0xc;
            goto loc_F00D68D0;
          }
          if (sVar1 != 0) {
            pbVar14 = pbVar14 + 2;
          }
          else {
            pbVar14 = pbVar14 + 1;
          }
        }
        else {
          if (sVar1 == 0) {
            uVar6 = (uint)*pbVar14;
            pbVar14 = pbVar14 + 1;
          }
          else {
            uVar6 = (uint)*(sword *)pbVar14;
            pbVar14 = pbVar14 + 2;
          }
          uVar7 = *(undefined4 *)(param_1 + 0x4f8);
          uVar10 = uVar16;
          uVar3 = uVar8;
loc_F00D68D0:
          _objc_msgSend(uVar7,paKeyboardeventF,uVar10,uVar8,param_3,uVar6,uVar12,uVar6,uVar12);
          uVar8 = uVar3;
        }
        iVar9 = iVar9 + 1;
      } while (iVar9 < (int)uVar5);
      iVar15 = uVar8 - uVar4;
    }
    param_2 = uVar4;
    if (iVar15 == 0) goto loc_F00D6958;
    uVar8 = *(uint *)(param_1 + 0x4f8);
    _objc_msgSend(uVar8,paDeviceflags);
    uVar10 = 0xc;
    uVar12 = 0;
    uVar7 = *(undefined4 *)(param_1 + 0x4f8);
    uVar5 = 0;
    uVar6 = 0;
    uVar3 = 0;
  }
  else {
    uVar3 = (uint)(sword)*pwVar13;
    uVar6 = (uint)(sword)pwVar13[1];
    if (uVar5 == 0xffff) goto loc_F00D6788;
loc_F00D6930:
    uVar7 = *(undefined4 *)(param_1 + 0x4f8);
    uVar10 = uVar16;
  }
  _objc_msgSend(uVar7,paKeyboardeventF,uVar10,uVar8,param_3,uVar12,uVar5,uVar6,uVar3);
  uVar8 = uVar4;
loc_F00D6958:
  iVar15 = 0;
  iVar9 = param_1;
  if ((*(byte *)(param_1 + param_3 + 6) & 0x40) != 0) {
    do {
      if (param_3 == *(word *)(iVar9 + 0x4d8)) {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),paKeyboardspecia,uVar16,uVar8,param_3,iVar15)
        ;
        if (((iVar15 == 4) && (*(int *)(param_1 + 0x8c) == 0)) && (param_4 == '\x01')) {
          uVar8 = *(uint *)(param_1 + 0x4f8);
          _objc_msgSend(uVar8,paDeviceflags);
          uVar4 = *(uint *)(param_1 + 0x4f8);
          _objc_msgSend(uVar4,paAlphalock);
          bVar17 = (uVar4 & 0xff) == 0;
          _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),paSetalphalock,bVar17);
          if (bVar17) {
            uVar8 = uVar8 | 0x10000;
          }
          else {
            uVar8 = uVar8 & 0xfffeffff;
          }
          _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),paSetdeviceflags,uVar8);
          _objc_msgSend(*(undefined4 *)(param_1 + 0x4f8),paKeyboardeventF,0xc,uVar8,param_3,0,0,0,0)
          ;
        }
        break;
      }
      iVar15 = iVar15 + 1;
      iVar9 = iVar9 + 2;
    } while (iVar15 < 7);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4625 start=0xf00d6af4 */

/* WARNING: Removing unreachable block (ram,0xf00d6bc8) */
/* WARNING: Removing unreachable block (ram,0xf00d6bf8) */
/* WARNING: Removing unreachable block (ram,0xf00d6c28) */
/* WARNING: Removing unreachable block (ram,0xf00d6c58) */
/* WARNING: Removing unreachable block (ram,0xf00d6c88) */
/* WARNING: Removing unreachable block (ram,0xf00d6cb8) */
/* WARNING: Removing unreachable block (ram,0xf00d6d20) */
/* WARNING: Removing unreachable block (ram,0xf00d6d00) */
/* WARNING: Removing unreachable block (ram,0xf00d6d88) */
/* WARNING: Removing unreachable block (ram,0xf00d6d68) */
/* WARNING: Removing unreachable block (ram,0xf00d6dc0) */
/* WARNING: Removing unreachable block (ram,0xf00d6df8) */
/* WARNING: Removing unreachable block (ram,0xf00d6e30) */
/* WARNING: Removing unreachable block (ram,0xf00d6e68) */
/* WARNING: Removing unreachable block (ram,0xf00d6ea0) */
/* WARNING: Removing unreachable block (ram,0xf00d6ed8) */
/* WARNING: Removing unreachable block (ram,0xf00d6f10) */
/* WARNING: Removing unreachable block (ram,0xf00d6f48) */
/* WARNING: Removing unreachable block (ram,0xf00d6f80) */
/* WARNING: Removing unreachable block (ram,0xf00d6fb8) */
/* WARNING: Removing unreachable block (ram,0xf00d6ff0) */
/* WARNING: Removing unreachable block (ram,0xf00d7028) */
/* WARNING: Removing unreachable block (ram,0xf00d7060) */
/* WARNING: Removing unreachable block (ram,0xf00d7098) */
/* WARNING: Removing unreachable block (ram,0xf00d70d0) */
/* WARNING: Removing unreachable block (ram,0xf00d7108) */
/* WARNING: Removing unreachable block (ram,0xf00d7140) */
/* WARNING: Removing unreachable block (ram,0xf00d7178) */
/* WARNING: Removing unreachable block (ram,0xf00d71b0) */
/* WARNING: Removing unreachable block (ram,0xf00d71e8) */
/* WARNING: Removing unreachable block (ram,0xf00d7204) */
/* WARNING: Removing unreachable block (ram,0xf00d6b10) */
/* WARNING: Removing unreachable block (ram,0xf00d71d8) */
/* WARNING: Removing unreachable block (ram,0xf00d71a0) */
/* WARNING: Removing unreachable block (ram,0xf00d7168) */
/* WARNING: Removing unreachable block (ram,0xf00d7130) */
/* WARNING: Removing unreachable block (ram,0xf00d70f8) */
/* WARNING: Removing unreachable block (ram,0xf00d70c0) */
/* WARNING: Removing unreachable block (ram,0xf00d7088) */
/* WARNING: Removing unreachable block (ram,0xf00d7050) */
/* WARNING: Removing unreachable block (ram,0xf00d7018) */
/* WARNING: Removing unreachable block (ram,0xf00d6fe0) */
/* WARNING: Removing unreachable block (ram,0xf00d6fa8) */
/* WARNING: Removing unreachable block (ram,0xf00d6f70) */
/* WARNING: Removing unreachable block (ram,0xf00d6f38) */
/* WARNING: Removing unreachable block (ram,0xf00d6f00) */
/* WARNING: Removing unreachable block (ram,0xf00d6ec8) */
/* WARNING: Removing unreachable block (ram,0xf00d6e90) */
/* WARNING: Removing unreachable block (ram,0xf00d6e58) */
/* WARNING: Removing unreachable block (ram,0xf00d6e20) */
/* WARNING: Removing unreachable block (ram,0xf00d6de8) */
/* WARNING: Removing unreachable block (ram,0xf00d6db0) */
/* WARNING: Removing unreachable block (ram,0xf00d6d40) */
/* WARNING: Removing unreachable block (ram,0xf00d6d78) */
/* WARNING: Removing unreachable block (ram,0xf00d6cd8) */
/* WARNING: Removing unreachable block (ram,0xf00d6d10) */
/* WARNING: Removing unreachable block (ram,0xf00d6ca8) */
/* WARNING: Removing unreachable block (ram,0xf00d6c78) */
/* WARNING: Removing unreachable block (ram,0xf00d6c48) */
/* WARNING: Removing unreachable block (ram,0xf00d6c18) */
/* WARNING: Removing unreachable block (ram,0xf00d6be8) */
/* WARNING: Removing unreachable block (ram,0xf00d6bb8) */
/* WARNING: Removing unreachable block (ram,0xf00d7218) */
/* WARNING: Removing unreachable block (ram,0xf00d6b04) */

undefined8 -[IOAudio _commandOccurred](uint param_1,undefined4 param_2)

{
  undefined (*pauVar1) [20];
  undefined (*pauVar2) [14];
  uint uVar3;
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
  
  pauVar2 = paAudiocommand_0;
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
  uVar3 = param_1;
  _objc_msgSend(param_1,paAudiocommand_0);
  _objc_msgSend();
  switch(uVar3) {
  case :
    _objc_msgSend(param_1,paUpdateinputgai_0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paUpdateinputgai);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paUpdateoutputmu);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paUpdateoutputat_0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paUpdateoutputat);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paUpdateloudness);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    uVar3 = param_1;
    _objc_msgSend(param_1,paIsinputactive_0);
    pauVar1 = paStopdmaforchan_0;
    if ((uVar3 & 0xff) != 0) {
      uVar3 = param_1;
      _objc_msgSend(param_1,paInputchannel);
      _objc_msgSend(param_1,pauVar1,uVar3);
    }
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    uVar3 = param_1;
    _objc_msgSend(param_1,paIsoutputactive_0);
    pauVar1 = paStopdmaforchan_0;
    if ((uVar3 & 0xff) != 0) {
      uVar3 = param_1;
      _objc_msgSend(param_1,paOutputchannel);
      _objc_msgSend(param_1,pauVar1,uVar3);
    }
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x1e,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x1e,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x1f,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x1f,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x20,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x20,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x21,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x21,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x22,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetinputEnable,0x22,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x19,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x19,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1a,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1a,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1b,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1b,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1c,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1c,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1d,1);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  case :
    _objc_msgSend(param_1,paSetoutputEnabl,0x1d,0);
    _objc_msgSend(param_1,paAudiocommand_0);
    break;
  :
    _objc_msgSend(param_1,pauVar2);
  }
  _objc_msgSend();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4626 start=0xf00d7228 */

/* WARNING: Removing unreachable block (ram,0xf00d733c) */
/* WARNING: Removing unreachable block (ram,0xf00d72e0) */
/* WARNING: Removing unreachable block (ram,0xf00d7304) */
/* WARNING: Removing unreachable block (ram,0xf00d739c) */
/* WARNING: Removing unreachable block (ram,0xf00d7370) */
/* WARNING: Removing unreachable block (ram,0xf00d7260) */
/* WARNING: Removing unreachable block (ram,0xf00d7270) */
/* WARNING: Removing unreachable block (ram,0xf00d7384) */
/* WARNING: Removing unreachable block (ram,0xf00d73a4) */
/* WARNING: Removing unreachable block (ram,0xf00d72d0) */
/* WARNING: Removing unreachable block (ram,0xf00d731c) */
/* WARNING: Removing unreachable block (ram,0xf00d735c) */
/* WARNING: Removing unreachable block (ram,0xf00d724c) */

void sub_F00D7228(uint param_1)

{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined (*pauVar6) [19];
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
loc_F00D7240:
  while( true ) {
    while( true ) {
      *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
      uVar1 = param_1;
      _objc_msgSend(param_1,paDeviceportset);
      *(uint *)((int)register0x00000038 + -0x14) = uVar1;
      uVar1 = param_1;
      _objc_msgSend(param_1,paTimeout);
      puVar2 = (undefined *)((int)register0x00000038 + -0x20);
      _msg_receive((undefined *)((int)register0x00000038 + -0x20),0x100,uVar1);
      if (puVar2 == (undefined *)0xffffff35) goto loc_F00D7314;
      if (puVar2 == (undefined *)0x0) break;
      uVar1 = param_1;
      _objc_msgSend(param_1,paName);
      uVar3 = param_1;
      _objc_msgSend(param_1,paDevicekind_0);
      _IOLog(aSSThreadMsgRec,uVar1,uVar3,puVar2);
      _IOExitThread();
    }
    iVar4 = *(int *)((int)register0x00000038 + -0xc);
    pauVar6 = paInterruptoccur_2;
    if (iVar4 == 0x232325) break;
    uVar5 = paInputchannel;
    if ((iVar4 == 0x385) || (uVar5 = paOutputchannel, iVar4 == 900)) {
      uVar1 = param_1;
      _objc_msgSend(param_1,uVar5);
      _objc_msgSend(param_1,paDatapendingocc,uVar1);
    }
    else {
      pauVar6 = (undefined (*) [19])paCommandoccurre;
      if (iVar4 == 0x386) break;
      _IOLog(aAudioUnknownMe);
    }
  }
loc_F00D735C:
  _objc_msgSend(param_1,pauVar6);
  goto loc_F00D7240;
loc_F00D7314:
  uVar1 = param_1;
  _objc_msgSend(param_1,paIsinputactive_0);
  pauVar6 = (undefined (*) [19])paTimeoutoccurre;
  if (((uVar1 & 0xff) == 0) &&
     (uVar1 = param_1, _objc_msgSend(param_1,paIsoutputactive_0),
     pauVar6 = (undefined (*) [19])paTimeoutoccurre, (uVar1 & 0xff) == 0)) goto loc_F00D7240;
  goto loc_F00D735C;
}
/* GHIDRADEC_FUNCTION index=4627 start=0xf00d73bc */

/* WARNING: Removing unreachable block (ram,0xf00d7510) */
/* WARNING: Removing unreachable block (ram,0xf00d74f0) */
/* WARNING: Removing unreachable block (ram,0xf00d74d4) */
/* WARNING: Removing unreachable block (ram,0xf00d749c) */
/* WARNING: Removing unreachable block (ram,0xf00d7470) */
/* WARNING: Removing unreachable block (ram,0xf00d7454) */
/* WARNING: Removing unreachable block (ram,0xf00d7420) */
/* WARNING: Removing unreachable block (ram,0xf00d7408) */
/* WARNING: Removing unreachable block (ram,0xf00d73e0) */
/* WARNING: Removing unreachable block (ram,0xf00d73c8) */
/* WARNING: Removing unreachable block (ram,0xf00d73f0) */
/* WARNING: Removing unreachable block (ram,0xf00d7410) */
/* WARNING: Removing unreachable block (ram,0xf00d7430) */
/* WARNING: Removing unreachable block (ram,0xf00d7468) */
/* WARNING: Removing unreachable block (ram,0xf00d7488) */
/* WARNING: Removing unreachable block (ram,0xf00d74a4) */
/* WARNING: Removing unreachable block (ram,0xf00d74e8) */
/* WARNING: Removing unreachable block (ram,0xf00d7508) */
/* WARNING: Removing unreachable block (ram,0xf00d7528) */
/* WARNING: Removing unreachable block (ram,0xf00d73c0) */

void sub_F00D73BC(int param_1)

{
  undefined (*pauVar1) [37];
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 uVar6;
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
  iVar5 = param_1;
  _task_self();
  _port_allocate_EXTERNAL();
  uVar6 = *(undefined4 *)((int)register0x00000038 + -0x44);
  if (iVar5 != 0) {
    _IOLog(aAudioPortAlloc);
    uVar6 = *(undefined4 *)((int)register0x00000038 + -0x44);
  }
  puVar2 = aEventdriver;
  _objc_lookUpClass();
  if (puVar2 == (undefined *)0x0) {
    _IOLog(aAudioObjcLooku);
    _IOExitThread();
  }
  _objc_msgSend(puVar2,paInstance);
  puVar3 = puVar2;
  _objc_msgSend();
  pauVar1 = paSetspecialkeyp;
  puVar4 = puVar2;
  _objc_msgSend(puVar2,paSetspecialkeyp,puVar3,0,uVar6);
  if (puVar4 != (undefined *)0x0) {
    _IOLog(aAudioSetspecia,puVar4);
    _IOExitThread();
  }
  _objc_msgSend(puVar2,pauVar1,puVar3,1,uVar6);
  if (puVar2 != (undefined *)0x0) {
    _IOLog(aAudioSetspecia,puVar2);
    _IOExitThread();
  }
  *(undefined4 *)((int)register0x00000038 + -0x34) = uVar6;
  do {
    *(undefined4 *)((int)register0x00000038 + -0x3c) = 0x38;
    puVar2 = (undefined *)((int)register0x00000038 + -0x40);
    _msg_receive(puVar2,0,0);
    if (puVar2 == (undefined *)0x0) {
      iVar5 = *(int *)((int)register0x00000038 + -0x2c);
    }
    else {
      _IOLog(aAudioKeythread,puVar2);
      _IOExitThread();
      iVar5 = *(int *)((int)register0x00000038 + -0x2c);
    }
    if (iVar5 != 0x536b6579) {
      _IOLog(aAudioUnknownMs);
      _IOExitThread();
    }
    _objc_msgSend(param_1,paKeyoccurredEve,*(undefined4 *)((int)register0x00000038 + -0x24),
                  *(undefined4 *)((int)register0x00000038 + -0x1c),
                  *(undefined4 *)((int)register0x00000038 + -0x14));
    *(undefined4 *)((int)register0x00000038 + -0x34) = uVar6;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=4628 start=0xf00d7540 */

/* WARNING: Removing unreachable block (ram,0xf00d7570) */
/* WARNING: Removing unreachable block (ram,0xf00d7588) */
/* WARNING: Removing unreachable block (ram,0xf00d7564) */

undefined8 +[IOAudio _addChannel:](undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined5 *puVar1;
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
  if (dword_F012EF0C == (undefined5 *)0x0) {
    puVar1 = paList;
    _objc_msgSend(paList,paAlloc);
    _objc_msgSend();
    dword_F012EF0C = puVar1;
  }
  _objc_msgSend(dword_F012EF0C,paAddobject,param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4629 start=0xf00d7598 */

/* WARNING: Removing unreachable block (ram,0xf00d75cc) */
/* WARNING: Removing unreachable block (ram,0xf00d75d8) */
/* WARNING: Removing unreachable block (ram,0xf00d75b4) */

undefined8 +[IOAudio _channelForUserPort:](undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
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
  uVar2 = 0;
  do {
    uVar3 = dword_F012EF0C;
    _objc_msgSend(dword_F012EF0C,paCount_0);
    if (uVar3 <= uVar2) {
      uVar3 = 0;
      break;
    }
    uVar3 = dword_F012EF0C;
    _objc_msgSend(dword_F012EF0C,paObjectat,uVar2);
    uVar1 = uVar3;
    _objc_msgSend();
    uVar2 = uVar2 + 1;
  } while (uVar1 != param_3);
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=4630 start=0xf00d7600 */

/* WARNING: Removing unreachable block (ram,0xf00d7634) */
/* WARNING: Removing unreachable block (ram,0xf00d7640) */
/* WARNING: Removing unreachable block (ram,0xf00d761c) */

undefined8 +[IOAudio _channelForExclusivePort:](undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
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
  uVar2 = 0;
  do {
    uVar3 = dword_F012EF0C;
    _objc_msgSend(dword_F012EF0C,paCount_0);
    if (uVar3 <= uVar2) {
      uVar3 = 0;
      break;
    }
    uVar3 = dword_F012EF0C;
    _objc_msgSend(dword_F012EF0C,paObjectat,uVar2);
    uVar1 = uVar3;
    _objc_msgSend();
    uVar2 = uVar2 + 1;
  } while (uVar1 != param_3);
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=4631 start=0xf00d7668 */

/* WARNING: Removing unreachable block (ram,0xf00d76b8) */
/* WARNING: Removing unreachable block (ram,0xf00d76a4) */
/* WARNING: Removing unreachable block (ram,0xf00d76b0) */
/* WARNING: Removing unreachable block (ram,0xf00d76d0) */
/* WARNING: Removing unreachable block (ram,0xf00d768c) */

undefined8 +[IOAudio _inputChannelForSndPort:](undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
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
  uVar2 = 0;
  do {
    while( true ) {
      uVar3 = dword_F012EF0C;
      _objc_msgSend(dword_F012EF0C,paCount_0);
      if (uVar3 <= uVar2) {
        uVar3 = 0;
        goto locret_F00D76F0;
      }
      uVar3 = dword_F012EF0C;
      _objc_msgSend(dword_F012EF0C,paObjectat,uVar2);
      uVar1 = uVar3;
      _objc_msgSend();
      _objc_msgSend();
      if (uVar3 == uVar1) break;
      uVar2 = uVar2 + 1;
    }
    uVar1 = uVar3;
    _objc_msgSend(uVar3,paUsersndport);
    uVar2 = uVar2 + 1;
  } while (uVar1 != param_3);
locret_F00D76F0:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=4632 start=0xf00d76f8 */

/* WARNING: Removing unreachable block (ram,0xf00d7748) */
/* WARNING: Removing unreachable block (ram,0xf00d7734) */
/* WARNING: Removing unreachable block (ram,0xf00d7740) */
/* WARNING: Removing unreachable block (ram,0xf00d7760) */
/* WARNING: Removing unreachable block (ram,0xf00d771c) */

undefined8 +[IOAudio _outputChannelForSndPort:](undefined4 param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
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
  uVar2 = 0;
  do {
    while( true ) {
      uVar3 = dword_F012EF0C;
      _objc_msgSend(dword_F012EF0C,paCount_0);
      if (uVar3 <= uVar2) {
        uVar3 = 0;
        goto locret_F00D7780;
      }
      uVar3 = dword_F012EF0C;
      _objc_msgSend(dword_F012EF0C,paObjectat,uVar2);
      uVar1 = uVar3;
      _objc_msgSend();
      _objc_msgSend();
      if (uVar3 == uVar1) break;
      uVar2 = uVar2 + 1;
    }
    uVar1 = uVar3;
    _objc_msgSend(uVar3,paUsersndport);
    uVar2 = uVar2 + 1;
  } while (uVar1 != param_3);
locret_F00D7780:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=4633 start=0xf00d7788 */

undefined8 +[IOAudio _setInstance:](undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
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
  dword_F012EF10 = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4634 start=0xf00d779c */

undefined8 +[IOAudio _instance](undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,dword_F012EF10);
}
/* GHIDRADEC_FUNCTION index=4635 start=0xf00d77b0 */

undefined8 -[IOAudio _inputChannel](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x128));
}
/* GHIDRADEC_FUNCTION index=4636 start=0xf00d77c0 */

undefined8 -[IOAudio _outputChannel](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 300));
}
/* GHIDRADEC_FUNCTION index=4637 start=0xf00d77d0 */

undefined8 -[IOAudio _channelWillAddStream](undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=4638 start=0xf00d77dc */

undefined8 -[IOAudio _audioCommand](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x130));
}
/* GHIDRADEC_FUNCTION index=4639 start=0xf00d77ec */

undefined8 -[IOAudio _setSampleRate:](int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x144) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4640 start=0xf00d77fc */

undefined8 -[IOAudio _setDataEncoding:](int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x148) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4641 start=0xf00d780c */

undefined8 -[IOAudio _setChannelCount:](int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x14c) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4642 start=0xf00d781c */

/* WARNING: Removing unreachable block (ram,0xf00d78a8) */
/* WARNING: Removing unreachable block (ram,0xf00d7874) */
/* WARNING: Removing unreachable block (ram,0xf00d78c4) */
/* WARNING: Removing unreachable block (ram,0xf00d7830) */

undefined8 -[IOAudio _dataPendingForChannel:](int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
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
  if (*(int *)(param_1 + 0x13c) == 0) {
    iVar2 = 0x18;
    _IOMalloc();
    *(int *)(param_1 + 0x13c) = iVar2;
    *(undefined *)(iVar2 + 3) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + 4) = 0x18;
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + 0xc) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x13c) + 0x10) = *(undefined4 *)(param_1 + 0x134);
  }
  _objc_msgSend(param_3,paIsread);
  uVar1 = 0x385;
  if ((param_3 & 0xff) == 0) {
    iVar2 = *(int *)(param_1 + 0x13c);
    uVar1 = 900;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x13c);
  }
  *(undefined4 *)(iVar2 + 0x14) = uVar1;
  iVar2 = *(int *)(param_1 + 0x13c);
  _msg_send_from_kernel(iVar2,1,1000);
  if ((iVar2 != 0) && (iVar2 != -0x67)) {
    _IOLog(aAudioDataPendi);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4643 start=0xf00d78d4 */

/* WARNING: Removing unreachable block (ram,0xf00d78fc) */
/* WARNING: Removing unreachable block (ram,0xf00d7920) */
/* WARNING: Removing unreachable block (ram,0xf00d78e0) */

undefined8 -[IOAudio _dataPendingOccurred:](uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
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
  uVar1 = param_1;
  _objc_msgSend(param_1,paIsinputactive_0);
  if (((uVar1 & 0xff) == 0) &&
     (uVar1 = param_1, _objc_msgSend(param_1,paIsoutputactive_0), (uVar1 & 0xff) == 0)) {
    _objc_msgSend(param_1,paAttempttostart,param_3,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4644 start=0xf00d7930 */

/* WARNING: Removing unreachable block (ram,0xf00d7a0c) */
/* WARNING: Removing unreachable block (ram,0xf00d79d8) */
/* WARNING: Removing unreachable block (ram,0xf00d79b4) */
/* WARNING: Removing unreachable block (ram,0xf00d79e8) */
/* WARNING: Removing unreachable block (ram,0xf00d7a1c) */
/* WARNING: Removing unreachable block (ram,0xf00d7970) */

undefined8 -[IOAudio _interruptOccurred](undefined4 param_1,undefined4 param_2)

{
  undefined (*pauVar1) [29];
  undefined4 uVar2;
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
  *(undefined *)((int)register0x00000038 + -0x11) = 0;
  *(undefined *)((int)register0x00000038 + -0x12) = 0;
  if ((unk_F012EEFC._0_1_ == '\0') || (dword_F012EF08 == 0)) {
    _objc_msgSend(param_1,paInterruptoccur_1,(undefined *)((int)register0x00000038 + -0x11));
  }
  if ((unk_F012EEFC._0_1_ == '\0') &&
     ((*(char *)((int)register0x00000038 + -0x11) != '\0' ||
      (*(char *)((int)register0x00000038 + -0x12) != '\0')))) {
    _objc_msgSend(param_1,paSetlastinterru,(int)((qword)qword_F01330D8 >> 0x20));
    pauVar1 = paAttempttostopd;
    if (*(char *)((int)register0x00000038 + -0x11) != '\0') {
      uVar2 = param_1;
      _objc_msgSend(param_1,paInputchannel);
      _objc_msgSend(param_1,pauVar1,uVar2);
    }
    pauVar1 = paAttempttostopd;
    if (*(char *)((int)register0x00000038 + -0x12) != '\0') {
      uVar2 = param_1;
      _objc_msgSend(param_1,paOutputchannel);
      _objc_msgSend(param_1,pauVar1,uVar2);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4645 start=0xf00d7a2c */

undefined8 -[IOAudio _setTimeout:](int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x140) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4646 start=0xf00d7a3c */

undefined8 -[IOAudio _timeout](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x140));
}
/* GHIDRADEC_FUNCTION index=4647 start=0xf00d7a4c */

undefined8 -[IOAudio _devicePortSet](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x138));
}
/* GHIDRADEC_FUNCTION index=4648 start=0xf00d7a5c */

undefined8 -[IOAudio _setLastInterruptTimeStamp:](int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  iVar1 = *(int *)(param_1 + 0x174);
  *(undefined8 *)(iVar1 + 8) = qword_F01330D8;
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=4649 start=0xf00d7a78 */

undefined8 -[IOAudio _lastInterruptTimeStamp](int param_1)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined8 in_i0_1;
  undefined8 uVar1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(int *)(in_CWP * 0x40 + 0x8000) = (int)((qword)in_i0_1 >> 0x20);
    *(int *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = (int)in_i0_1;
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
  uVar1 = *(undefined8 *)(*(int *)(param_1 + 0x174) + 8);
  return CONCAT44((int)uVar1,(int)((qword)uVar1 >> 0x20));
}

