
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
