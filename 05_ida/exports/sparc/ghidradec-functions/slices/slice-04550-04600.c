/* GHIDRADEC_FUNCTION index=4550 start=0xf00d2fa0 */

undefined8 -[EventDriver evs_port](int param_1,undefined4 param_2)

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
/* GHIDRADEC_FUNCTION index=4551 start=0xf00d2fb0 */

/* WARNING: Removing unreachable block (ram,0xf00d2ff0) */
/* WARNING: Removing unreachable block (ram,0xf00d2fd4) */
/* WARNING: Removing unreachable block (ram,0xf00d3024) */
/* WARNING: Removing unreachable block (ram,0xf00d2fc0) */

undefined8
-[EventDriver evSpecialKeyMsg:direction:flags:level:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6)

{
  int iVar1;
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
  iVar1 = param_1;
  _objc_msgSend(param_1,paSpecialkeyport_0,param_3);
  if (iVar1 != 0) {
    iVar2 = 0x38;
    _IOMalloc();
    if (iVar2 != 0) {
      _bcopy(unk_F00F9688,iVar2,0x38);
      *(int *)(iVar2 + 0x10) = iVar1;
      *(undefined4 *)(iVar2 + 0x1c) = param_3;
      *(undefined4 *)(iVar2 + 0x24) = param_4;
      *(undefined4 *)(iVar2 + 0x2c) = param_5;
      *(undefined4 *)(iVar2 + 0x34) = param_6;
      _objc_msgSend(param_1,paSendiothreadas,paPerformspecial,param_1,iVar2);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4552 start=0xf00d3034 */

/* WARNING: Removing unreachable block (ram,0xf00d309c) */
/* WARNING: Removing unreachable block (ram,0xf00d3064) */
/* WARNING: Removing unreachable block (ram,0xf00d3074) */
/* WARNING: Removing unreachable block (ram,0xf00d30a8) */
/* WARNING: Removing unreachable block (ram,0xf00d3040) */

undefined8 -[EventDriver _performSpecialKeyMsg:](int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
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
  iVar1 = param_3;
  _msg_send(param_3,1,0);
  if (iVar1 != 0) {
    iVar2 = param_1;
    _objc_msgSend(param_1,paName);
    _IOLog(aSPerformspecia,iVar2,iVar1);
  }
  if (iVar1 == -0x66) {
    _objc_msgSend(param_1,paSetspecialkeyp,*(undefined4 *)(param_1 + 0x134),
                  *(undefined4 *)(param_3 + 0x1c),0);
  }
  _IOFree(param_3,0x38);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4553 start=0xf00d30b8 */

/* WARNING: Removing unreachable block (ram,0xf00d3198) */
/* WARNING: Removing unreachable block (ram,0xf00d3150) */
/* WARNING: Removing unreachable block (ram,0xf00d3184) */
/* WARNING: Removing unreachable block (ram,0xf00d3168) */

undefined8
-[EventDriver evDispatch:command:](int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined (*pauVar1) [21];
  int iVar2;
  undefined (*pauVar3) [24];
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar6;
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
  
  pauVar1 = paSetbrightnessT;
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
  iVar5 = *(int *)(param_1 + 0x180);
  iVar4 = param_3 * 0x14;
  if (*(char *)(param_1 + 0x1d2) != '\0') {
    iVar2 = *(int *)(param_1 + 0x168);
    *(undefined2 *)((int)register0x00000038 + -0x18) = *(undefined2 *)(iVar2 + 0x18);
    *(undefined2 *)((int)register0x00000038 + -0x16) = *(undefined2 *)(iVar2 + 0x1a);
    if (*(int *)(iVar5 + iVar4) != 0) {
      pauVar3 = paShowcursorFram;
      if (param_4 != 2) {
        if (param_4 < 3) {
          if (param_4 == 1) {
            _objc_msgSend(*(undefined4 *)(iVar5 + iVar4),paHidecursor,param_3 + 0x100);
          }
          goto locret_F00D31A0;
        }
        pauVar3 = paMovecursorFram;
        if (param_4 != 3) {
          if (param_4 == 4) {
            uVar6 = *(undefined4 *)(iVar5 + iVar4);
            iVar4 = param_1;
            _objc_msgSend(param_1,paCurrentbrightn);
            _objc_msgSend(uVar6,pauVar1,iVar4,param_3 + 0x100);
          }
          goto locret_F00D31A0;
        }
      }
      _objc_msgSend(*(undefined4 *)(iVar5 + iVar4),pauVar3,
                    (undefined *)((int)register0x00000038 + -0x18),
                    *(undefined4 *)(*(int *)(param_1 + 0x168) + 0x1c),param_3 + 0x100);
    }
  }
locret_F00D31A0:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4554 start=0xf00d31a8 */

/* WARNING: Removing unreachable block (ram,0xf00d3568) */
/* WARNING: Removing unreachable block (ram,0xf00d332c) */
/* WARNING: Removing unreachable block (ram,0xf00d32e8) */
/* WARNING: Removing unreachable block (ram,0xf00d355c) */
/* WARNING: Removing unreachable block (ram,0xf00d3578) */
/* WARNING: Removing unreachable block (ram,0xf00d325c) */

undefined8
-[EventDriver postEvent:at:atTime:withData:]
          (int param_1,undefined4 param_2,int param_3,sword *param_4,uint param_5,int *param_6)

{
  char cVar1;
  sword *psVar2;
  sword sVar4;
  int iVar3;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  sword *psVar6;
  undefined4 unaff_l3;
  sword *psVar7;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  byte bVar8;
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
  psVar6 = *(sword **)(param_1 + 0x168);
  bVar8 = (byte)param_3;
  sVar4 = *psVar6;
  psVar7 = psVar6 + psVar6[2] * 0x16 + 0x28;
  piVar5 = (int *)(psVar6 + psVar6[1] * 0x16 + 0x28);
  if (((0x1ffe >> (bVar8 & 0x1f) & 1U) != 0) &&
     (*(uint *)(param_1 + 0x1a4) = param_5 + *(int *)(param_1 + 0x1a0),
     *(char *)(param_1 + 0x1d3) != '\0')) {
    _objc_msgSend(param_1,paUndoautodim);
  }
  if (*(uint *)(psVar6 + 8) < param_5) {
    if (param_5 < *(int *)(psVar6 + 8) + 0x140U) {
      *(uint *)(psVar6 + 8) = param_5;
    }
    cVar1 = *(char *)(param_1 + 0x1d2);
  }
  else {
    cVar1 = *(char *)(param_1 + 0x1d2);
  }
  bVar9 = false;
  if (cVar1 != '\0') {
    bVar9 = **(sword **)(param_1 + 0x168) != (*(sword **)(param_1 + 0x168))[1];
  }
  if (((((*(byte *)((int)psVar6 + 0x33) & 2) == 0) &&
       ((int *)(psVar6 + sVar4 * 0x16 + 0x28) != piVar5)) && (*(int *)(psVar7 + 4) == param_3)) &&
     ((0x2e0 >> (bVar8 & 0x1f) & 1U) != 0)) {
    psVar2 = psVar7 + 2;
    _ev_try_lock();
    if (psVar2 != (sword *)0x0) {
      *(int *)(psVar7 + 6) = (int)*param_4;
      *(int *)(psVar7 + 8) = (int)param_4[1];
      *(uint *)(psVar7 + 10) = param_5;
      if (param_6 != (int *)0x0) {
        *(int *)(psVar7 + 0x10) = *param_6;
        *(int *)(psVar7 + 0x12) = param_6[1];
        *(int *)(psVar7 + 0x14) = param_6[2];
      }
      _ev_unlock(psVar7 + 2);
      goto locret_F00D3580;
    }
  }
  if (*piVar5 == (int)*psVar6) {
    iVar3 = param_1;
    _objc_msgSend(param_1,paName);
    _IOLog(aSPosteventLlev,iVar3);
  }
  else {
    piVar5[2] = param_3;
    piVar5[3] = (int)*param_4;
    piVar5[4] = (int)param_4[1];
    piVar5[6] = *(int *)(psVar6 + 6);
    piVar5[5] = param_5;
    piVar5[7] = 0;
    if (param_6 != (int *)0x0) {
      piVar5[8] = *param_6;
      piVar5[9] = param_6[1];
      piVar5[10] = param_6[2];
    }
    if (param_3 == 2) {
      *(sword *)((int)piVar5 + 0x22) = *(sword *)(param_1 + 0x1f8);
      *(undefined2 *)(param_1 + 0x1f8) = 0;
    }
    else if (param_3 < 3) {
      if (param_3 == 1) {
        iVar3 = *(int *)(param_1 + 0x168);
        do {
          *(sword *)(iVar3 + 6) = *(sword *)(iVar3 + 6) + 1;
        } while (*(sword *)(iVar3 + 6) == 0);
        sVar4 = *(sword *)(iVar3 + 6);
        *(sword *)(param_1 + 0x1f8) = sVar4;
        *(sword *)((int)piVar5 + 0x22) = sVar4;
      }
    }
    else if (param_3 == 3) {
      iVar3 = *(int *)(param_1 + 0x168);
      do {
        *(sword *)(iVar3 + 6) = *(sword *)(iVar3 + 6) + 1;
      } while (*(sword *)(iVar3 + 6) == 0);
      sVar4 = *(sword *)(iVar3 + 6);
      *(sword *)(param_1 + 0x1fa) = sVar4;
      *(sword *)((int)piVar5 + 0x22) = sVar4;
    }
    else if (param_3 == 4) {
      *(sword *)((int)piVar5 + 0x22) = *(sword *)(param_1 + 0x1fa);
      *(undefined2 *)(param_1 + 0x1fa) = 0;
    }
    if ((0x66 >> (bVar8 & 0x1f) & 1U) != 0) {
      *(undefined *)(piVar5 + 10) = *(undefined *)(param_1 + 0x1c0);
    }
    if ((0x1e >> (bVar8 & 0x1f) & 1U) == 0) {
      sVar4 = (sword)*piVar5;
    }
    else {
      if (*(uint *)(param_1 + 0x1bc) < param_5 - *(int *)(param_1 + 0x1b8)) {
loc_F00D3500:
        if ((param_3 == 1) || (param_3 == 3)) {
          *(sword *)(param_1 + 0x1ac) = *param_4;
          *(sword *)(param_1 + 0x1ae) = param_4[1];
          *(uint *)(param_1 + 0x1b8) = param_5;
          iVar3 = 1;
loc_F00D3528:
          *(int *)(param_1 + 0x1b4) = iVar3;
          piVar5[9] = iVar3;
        }
        else {
          piVar5[9] = 0;
        }
      }
      else {
        iVar3 = (int)*param_4 - (int)*(sword *)(param_1 + 0x1ac);
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        if (*(sword *)(param_1 + 0x1b0) < iVar3) goto loc_F00D3500;
        iVar3 = (int)param_4[1] - (int)*(sword *)(param_1 + 0x1ae);
        if (iVar3 < 0) {
          iVar3 = -iVar3;
        }
        if (*(sword *)(param_1 + 0x1b2) < iVar3) goto loc_F00D3500;
        if ((param_3 == 1) || (param_3 == 3)) {
          *(uint *)(param_1 + 0x1b8) = param_5;
          iVar3 = *(int *)(param_1 + 0x1b4) + 1;
          goto loc_F00D3528;
        }
        piVar5[9] = *(int *)(param_1 + 0x1b4);
      }
      sVar4 = (sword)*piVar5;
    }
    psVar6[1] = sVar4;
    psVar6[2] = (sword)*(undefined4 *)psVar7;
    if (bVar9) goto locret_F00D3580;
  }
  _objc_msgSend(param_1,paKickeventconsu);
locret_F00D3580:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4555 start=0xf00d3588 */

/* WARNING: Removing unreachable block (ram,0xf00d35b8) */
/* WARNING: Removing unreachable block (ram,0xf00d35ec) */
/* WARNING: Removing unreachable block (ram,0xf00d35d8) */
/* WARNING: Removing unreachable block (ram,0xf00d3594) */

undefined8 -[EventDriver kickEventConsumer](int param_1,undefined4 param_2)

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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x214),paLock);
  puVar1 = paUnlock;
  if (*(char *)(param_1 + 0x212) == '\x01') {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x214),paUnlock);
  }
  else {
    *(undefined *)(param_1 + 0x212) = 1;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x214),puVar1);
    _objc_msgSend(param_1,paSendiothreadas,paPerformkickeve,param_1,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4556 start=0xf00d35fc */

/* WARNING: Removing unreachable block (ram,0xf00d3658) */
/* WARNING: Removing unreachable block (ram,0xf00d361c) */
/* WARNING: Removing unreachable block (ram,0xf00d362c) */
/* WARNING: Removing unreachable block (ram,0xf00d3668) */
/* WARNING: Removing unreachable block (ram,0xf00d3608) */

undefined8 -[EventDriver _performKickEventConsumer:](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x214),paLock);
  uVar1 = paUnlock;
  *(undefined *)(param_1 + 0x212) = 0;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x214),uVar1);
  iVar2 = *(int *)(param_1 + 0x14c);
  _msg_send(iVar2,1,0);
  if ((iVar2 != -0x67) && (iVar2 != 0)) {
    iVar3 = param_1;
    _objc_msgSend(param_1,paName);
    _IOLog(aSPerformkickev,iVar3,iVar2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4557 start=0xf00d3678 */

/* WARNING: Removing unreachable block (ram,0xf00d369c) */

undefined8
-[EventDriver sendIOThreadMsg:to:with:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

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
  *(undefined4 *)((int)register0x00000038 + -0x20) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_5;
  _objc_msgSend(param_1,paThreadopcommon,2,(undefined *)((int)register0x00000038 + -0x20),0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4558 start=0xf00d36ac */

/* WARNING: Removing unreachable block (ram,0xf00d36d0) */

undefined8
-[EventDriver sendIOThreadAsyncMsg:to:with:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

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
  *(undefined4 *)((int)register0x00000038 + -0x20) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_5;
  _objc_msgSend(param_1,paThreadopcommon,2,(undefined *)((int)register0x00000038 + -0x20),1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4559 start=0xf00d36e0 */

/* WARNING: Removing unreachable block (ram,0xf00d3764) */
/* WARNING: Removing unreachable block (ram,0xf00d3744) */
/* WARNING: Removing unreachable block (ram,0xf00d3738) */
/* WARNING: Removing unreachable block (ram,0xf00d3750) */
/* WARNING: Removing unreachable block (ram,0xf00d3718) */
/* WARNING: Removing unreachable block (ram,0xf00d36f0) */

undefined8 -[EventDriver _doPerformInIOThread:](undefined4 param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
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
  uVar1 = *param_3;
  _objc_msgSend(uVar1,paRespondsto,param_3[1]);
  if ((uVar1 & 0xff) == 0) {
    _objc_msgSend(param_1,paName);
    uVar1 = *param_3;
    _object_getClassName(uVar1);
    uVar2 = param_3[1];
    _sel_getName(uVar2);
    _IOLog(aSDoperforminio,param_1,uVar1,uVar2);
    uVar3 = 0xfffffd41;
  }
  else {
    _objc_msgSend(*param_3,paPerformWith,param_3[1],param_3[2]);
    uVar3 = 0;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=4560 start=0xf00d3778 */

/* WARNING: Removing unreachable block (ram,0xf00d3898) */
/* WARNING: Removing unreachable block (ram,0xf00d38c4) */
/* WARNING: Removing unreachable block (ram,0xf00d3824) */
/* WARNING: Removing unreachable block (ram,0xf00d3868) */
/* WARNING: Removing unreachable block (ram,0xf00d3888) */
/* WARNING: Removing unreachable block (ram,0xf00d38ec) */
/* WARNING: Removing unreachable block (ram,0xf00d3810) */

undefined8
-[EventDriver _threadOpCommon:opParams:async:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,uint param_5
          )

{
  undefined (*pauVar1) [16];
  undefined *puVar2;
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
  *(undefined4 *)((int)register0x00000038 + -0x48) = dword_F012EEAC;
  *(undefined4 *)((int)register0x00000038 + -0x44) = DAT_f012eeb0._0_4_;
  *(undefined4 *)((int)register0x00000038 + -0x40) = DAT_f012eeb0._4_4_;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = DAT_f012eeb0._8_4_;
  *(undefined4 *)((int)register0x00000038 + -0x38) = DAT_f012eeb0._12_4_;
  *(undefined4 *)((int)register0x00000038 + -0x34) = DAT_f012eeb0._16_4_;
  *(undefined4 *)((int)register0x00000038 + -0x30) = DAT_f012eeb0._20_4_;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = DAT_f012eeb0._24_4_;
  *(undefined4 *)((int)register0x00000038 + -0x28) = DAT_f012eeb0._28_4_;
  *(undefined4 *)((int)register0x00000038 + -0x24) = DAT_f012eeb0._32_4_;
  *(undefined4 *)((int)register0x00000038 + -0x20) = DAT_f012eeb0._36_4_;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = DAT_f012eeb0._40_4_;
  *(undefined4 *)((int)register0x00000038 + -0x18) = DAT_f012eeb0._44_4_;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = param_3;
  if ((char)param_5 == '\0') {
    pauVar1 = paNxconditionloc;
    _objc_msgSend(paNxconditionloc,paAlloc);
    *(undefined (**) [16])((int)register0x00000038 + -0x28) = pauVar1;
    _objc_msgSend();
    *(undefined **)((int)register0x00000038 + -0x24) =
         (undefined *)((int)register0x00000038 + -0x4c);
    *(undefined4 *)((int)register0x00000038 + -0x4c) = 0xfffffd3e;
  }
  puVar2 = (undefined *)((int)register0x00000038 + -0x48);
  *(undefined4 *)((int)register0x00000038 + -0x20) = *param_4;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_4[1];
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_4[2];
  *(undefined4 *)((int)register0x00000038 + -0x38) = _ev_port_list;
  _msg_send_from_kernel(puVar2,0,0);
  if (puVar2 == (undefined *)0x0) {
    if ((char)param_5 == '\0') {
      _objc_msgSend(*(undefined4 *)((int)register0x00000038 + -0x28),paLockwhen,2);
    }
    else {
      *(undefined4 *)((int)register0x00000038 + -0x4c) = 0;
    }
  }
  else {
    _objc_msgSend(param_1,paName);
    _IOLog(aSThreadopcommo,param_1,puVar2);
    *(undefined4 *)((int)register0x00000038 + -0x4c) = 0xfffffd41;
  }
  uVar3 = *(undefined4 *)((int)register0x00000038 + -0x4c);
  if ((param_5 & 0xff) == 0) {
    _objc_msgSend(*(undefined4 *)((int)register0x00000038 + -0x28),paFree);
    uVar3 = *(undefined4 *)((int)register0x00000038 + -0x4c);
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=4561 start=0xf00d3900 */

/* WARNING: Removing unreachable block (ram,0xf00d3984) */
/* WARNING: Removing unreachable block (ram,0xf00d3950) */
/* WARNING: Removing unreachable block (ram,0xf00d3964) */
/* WARNING: Removing unreachable block (ram,0xf00d39a0) */
/* WARNING: Removing unreachable block (ram,0xf00d3948) */

undefined8 -[EventDriver _ioOpHandler:](undefined4 param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
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
  if ((undefined4 *)param_3[2] != (undefined4 *)0x0) {
    *(undefined4 *)param_3[2] = 0;
  }
  uVar1 = *param_3;
  if (uVar1 == 1) {
    uVar1 = param_3[1];
    goto loc_F00D3990;
  }
  if (uVar1 < 2) {
    _objc_msgSend(param_3[1],paUnlockwith,2);
    _IOExitThread();
loc_F00D395C:
    uVar2 = param_1;
    _objc_msgSend(param_1,paDoperforminiot,param_3 + 3);
    if ((undefined4 *)param_3[2] == (undefined4 *)0x0) {
      uVar1 = param_3[1];
      goto loc_F00D3990;
    }
    *(undefined4 *)param_3[2] = uVar2;
  }
  else {
    if (uVar1 == 2) goto loc_F00D395C;
    _IOPanic(aEventdriverBog);
  }
  uVar1 = param_3[1];
loc_F00D3990:
  if (uVar1 != 0) {
    _objc_msgSend(uVar1,paUnlockwith,2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4562 start=0xf00d39b0 */

/* WARNING: Removing unreachable block (ram,0xf00d39e4) */
/* WARNING: Removing unreachable block (ram,0xf00d39c8) */

undefined8
-[EventDriver runPeriodicEvent:]
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  if (*(char *)(param_1 + 0x210) == '\x01') {
    _ns_untimeout(sub_F00D52F8,param_1);
  }
  _ns_abstimeout(sub_F00D52F8,param_1,param_3,param_4,4);
  *(undefined *)(param_1 + 0x210) = 1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4563 start=0xf00d39fc */

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
/* GHIDRADEC_FUNCTION index=4564 start=0xf00d3af8 */

/* WARNING: Removing unreachable block (ram,0xf00d3cfc) */
/* WARNING: Removing unreachable block (ram,0xf00d3ce4) */
/* WARNING: Removing unreachable block (ram,0xf00d3ca8) */
/* WARNING: Removing unreachable block (ram,0xf00d3b80) */
/* WARNING: Removing unreachable block (ram,0xf00d3b64) */
/* WARNING: Removing unreachable block (ram,0xf00d3b20) */
/* WARNING: Removing unreachable block (ram,0xf00d3b6c) */
/* WARNING: Removing unreachable block (ram,0xf00d3c5c) */
/* WARNING: Removing unreachable block (ram,0xf00d3cb0) */
/* WARNING: Removing unreachable block (ram,0xf00d3cec) */
/* WARNING: Removing unreachable block (ram,0xf00d3d0c) */
/* WARNING: Removing unreachable block (ram,0xf00d3b04) */

undefined8 -[EventDriver periodicEvents](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined (*pauVar4) [15];
  undefined4 unaff_l0;
  int iVar5;
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
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    uVar1 = *(undefined4 *)(param_1 + 0x110);
    goto loc_F00D3D08;
  }
  iVar5 = *(int *)(param_1 + 0x168);
  _IOGetTimestamp(param_1 + 0x200);
  uVar3 = (int)((qword)*(undefined8 *)(param_1 + 0x200) >> 0x20) << 8 |
          (uint)*(undefined8 *)(param_1 + 0x200) >> 0x18;
  if (uVar3 == 0) {
    uVar3 = 1;
  }
  *(uint *)(iVar5 + 0x10) = uVar3;
  if (*(char *)(param_1 + 0x211) == '\x01') {
    _objc_msgSend(param_1,paSetcursorposit_0);
  }
  iVar2 = iVar5 + 0x40;
  _ev_try_lock();
  if (iVar2 != 0) {
    iVar2 = iVar5 + 0x14;
    _ev_try_lock();
    if (iVar2 != 0) {
      if ((*(int *)(iVar5 + 0x38) != *(int *)(iVar5 + 0x3c)) &&
         ((int)*(sword *)(iVar5 + 0x4c) < *(int *)(iVar5 + 0x10) - *(int *)(iVar5 + 0x38))) {
        *(undefined *)(iVar5 + 0x48) = 1;
      }
      if (((*(char *)(iVar5 + 0x49) == '\0') || (*(char *)(iVar5 + 0x4a) == '\0')) ||
         (*(char *)(iVar5 + 0x48) == '\0')) {
        if (((*(int *)(iVar5 + 0x44) != 0) &&
            (*(uint *)(param_1 + 0x1e0) <= *(uint *)(param_1 + 0x200))) &&
           ((pauVar4 = paHidewaitcursor, *(uint *)(param_1 + 0x1e0) != *(uint *)(param_1 + 0x200) ||
            (*(uint *)(param_1 + 0x1e4) <= *(uint *)(param_1 + 0x204))))) goto loc_F00D3C5C;
      }
      else {
        pauVar4 = paShowwaitcursor;
        if (*(int *)(iVar5 + 0x44) == 0) {
loc_F00D3C5C:
          _objc_msgSend(param_1,pauVar4);
        }
      }
      if (((*(int *)(iVar5 + 0x44) != 0) &&
          (*(uint *)(param_1 + 0x1f0) <= *(uint *)(param_1 + 0x200))) &&
         ((*(uint *)(param_1 + 0x1f0) != *(uint *)(param_1 + 0x200) ||
          (*(uint *)(param_1 + 500) <= *(uint *)(param_1 + 0x204))))) {
        _objc_msgSend(param_1,paAnimatewaitcur);
      }
      _ev_unlock(iVar5 + 0x14);
      if ((*(uint *)(param_1 + 0x1a4) < *(uint *)(iVar5 + 0x10)) &&
         (*(char *)(param_1 + 0x1d3) == '\0')) {
        _objc_msgSend(param_1,paDoautodim);
      }
    }
    _ev_unlock(iVar5 + 0x40);
  }
  _objc_msgSend(param_1,paSchedulenextpe);
  uVar1 = *(undefined4 *)(param_1 + 0x110);
loc_F00D3D08:
  _objc_msgSend(uVar1,paUnlock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4565 start=0xf00d3d1c */

/* WARNING: Removing unreachable block (ram,0xf00d3e10) */
/* WARNING: Removing unreachable block (ram,0xf00d3df0) */
/* WARNING: Removing unreachable block (ram,0xf00d3d78) */
/* WARNING: Removing unreachable block (ram,0xf00d3e00) */
/* WARNING: Removing unreachable block (ram,0xf00d3e24) */
/* WARNING: Removing unreachable block (ram,0xf00d3d34) */

undefined8 -[EventDriver startCursor](int param_1,undefined4 param_2)

{
  undefined (*pauVar1) [14];
  undefined (*pauVar2) [26];
  int iVar3;
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
  if (*(int *)(param_1 + 0x188) != 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
    if (*(char *)(param_1 + 0x1d2) == '\0') {
      iVar3 = *(int *)(param_1 + 0x110);
      pauVar2 = paUnlock;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x168);
      *(undefined2 *)((int)register0x00000038 + -0x18) = *(undefined2 *)(iVar3 + 0x18);
      *(undefined2 *)((int)register0x00000038 + -0x16) = *(undefined2 *)(iVar3 + 0x1a);
      iVar3 = param_1;
      _objc_msgSend(param_1,paPointtoscreen,(undefined *)((int)register0x00000038 + -0x18));
      *(int *)(param_1 + 0x18c) = iVar3;
      if (iVar3 < 0) {
        iVar3 = *(int *)(param_1 + 0x110);
        pauVar2 = paUnlock;
      }
      else {
        iVar3 = *(int *)(param_1 + 0x180) + iVar3 * 0x14;
        *(undefined2 *)(param_1 + 400) = *(undefined2 *)(iVar3 + 0xc);
        pauVar1 = paSetbrightness_0;
        *(undefined2 *)(param_1 + 0x192) = *(undefined2 *)(iVar3 + 0xe);
        *(undefined2 *)(param_1 + 0x194) = *(undefined2 *)(iVar3 + 0x10);
        *(undefined2 *)(param_1 + 0x196) = *(undefined2 *)(iVar3 + 0x12);
        *(sword *)(param_1 + 0x192) = *(sword *)(param_1 + 0x192) + -1;
        *(sword *)(param_1 + 0x196) = *(sword *)(param_1 + 0x196) + -1;
        _objc_msgSend(param_1,pauVar1);
        _objc_msgSend(param_1,paShowcursor);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
        iVar3 = param_1;
        pauVar2 = paAttachdefaulte;
      }
    }
    _objc_msgSend(iVar3,pauVar2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4566 start=0xf00d3e34 */

/* WARNING: Removing unreachable block (ram,0xf00d3e50) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00d3e50 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int -[EventDriver showWaitCursor](void)

{
  int iVar1;
  undefined8 in_o0_1;
  uint uVar2;
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
  
  iVar1 = (int)((qword)in_o0_1 >> 0x20);
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
  *(undefined4 *)(*(int *)(iVar1 + 0x168) + 0x44) = 1;
  _objc_msgSend(iVar1,(int)in_o0_1,1);
  uVar2 = (uint)*(undefined8 *)(iVar1 + 0x1e8);
  uVar3 = (uint)*(undefined8 *)(iVar1 + 0x200);
  *(qword *)(iVar1 + 0x1f0) =
       CONCAT44((int)((qword)*(undefined8 *)(iVar1 + 0x1e8) >> 0x20) +
                (int)((qword)*(undefined8 *)(iVar1 + 0x200) >> 0x20) + (uint)CARRY4(uVar2,uVar3),
                uVar2 + uVar3);
  uVar2 = (uint)*(undefined8 *)(iVar1 + 0x1d8);
  uVar3 = (uint)*(undefined8 *)(iVar1 + 0x200);
  *(qword *)(iVar1 + 0x1e0) =
       CONCAT44((int)((qword)*(undefined8 *)(iVar1 + 0x1d8) >> 0x20) +
                (int)((qword)*(undefined8 *)(iVar1 + 0x200) >> 0x20) + (uint)CARRY4(uVar2,uVar3),
                uVar2 + uVar3);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=4567 start=0xf00d3e88 */

/* WARNING: Removing unreachable block (ram,0xf00d3ea0) */

undefined8 -[EventDriver hideWaitCursor](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  
  uVar1 = paChangecursor;
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
  *(undefined4 *)(*(int *)(param_1 + 0x168) + 0x44) = 0;
  _objc_msgSend(param_1,uVar1,0);
  *(undefined8 *)(param_1 + 0x1f0) = 0;
  *(undefined8 *)(param_1 + 0x1e0) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4568 start=0xf00d3ec0 */

/* WARNING: Removing unreachable block (ram,0xf00d3ed8) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00d3ed8 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int -[EventDriver animateWaitCursor](void)

{
  int iVar1;
  undefined8 in_o0_1;
  uint uVar2;
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
  
  iVar1 = (int)((qword)in_o0_1 >> 0x20);
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
  _objc_msgSend(iVar1,(int)in_o0_1,*(int *)(*(int *)(iVar1 + 0x168) + 0x1c) + 1);
  uVar2 = (uint)*(undefined8 *)(iVar1 + 0x1e8);
  uVar3 = (uint)*(undefined8 *)(iVar1 + 0x200);
  *(qword *)(iVar1 + 0x1f0) =
       CONCAT44((int)((qword)*(undefined8 *)(iVar1 + 0x1e8) >> 0x20) +
                (int)((qword)*(undefined8 *)(iVar1 + 0x200) >> 0x20) + (uint)CARRY4(uVar2,uVar3),
                uVar2 + uVar3);
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=4569 start=0xf00d3efc */

/* WARNING: Removing unreachable block (ram,0xf00d3f20) */

undefined8 -[EventDriver changeCursor:](int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
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
  iVar1 = 1;
  if (param_3 < 4) {
    iVar1 = param_3;
  }
  *(int *)(*(int *)(param_1 + 0x168) + 0x1c) = iVar1;
  _objc_msgSend(param_1,paMovecursor);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4570 start=0xf00d3f30 */

undefined8 -[EventDriver pointToScreen:](int param_1,undefined4 param_2,sword *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar1;
  int iVar2;
  undefined4 unaff_i1;
  int iVar3;
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
  iVar3 = *(int *)(param_1 + 0x188) + -1;
  if (iVar3 != -1) {
    piVar1 = (int *)(iVar3 * 0x14 + *(int *)(param_1 + 0x180));
    iVar2 = iVar3;
    do {
      if ((((*piVar1 != 0) && (*(sword *)(piVar1 + 3) <= *param_3)) &&
          (*param_3 < *(sword *)((int)piVar1 + 0xe))) &&
         ((*(sword *)(piVar1 + 4) <= param_3[1] &&
          (iVar3 = iVar2, param_3[1] < *(sword *)((int)piVar1 + 0x12))))) goto locret_F00D3FE8;
      iVar3 = iVar2 + -1;
      piVar1 = piVar1 + -5;
      iVar2 = iVar3;
    } while (iVar3 != -1);
  }
  iVar2 = -1;
locret_F00D3FE8:
  return CONCAT44(iVar3,iVar2);
}
/* GHIDRADEC_FUNCTION index=4571 start=0xf00d3ff0 */

/* WARNING: Removing unreachable block (ram,0xf00d4038) */

undefined8 -[EventDriver setBrightness:](int param_1,undefined4 param_2,int param_3)

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
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x40 < param_3) {
    param_3 = 0x40;
  }
  if ((param_3 != *(int *)(param_1 + 0x1cc)) &&
     (*(int *)(param_1 + 0x1cc) = param_3, *(char *)(param_1 + 0x1d3) == '\0')) {
    _objc_msgSend(param_1,paSetbrightness_0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4572 start=0xf00d404c */

undefined8 -[EventDriver brightness](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x1cc));
}
/* GHIDRADEC_FUNCTION index=4573 start=0xf00d405c */

/* WARNING: Removing unreachable block (ram,0xf00d40a4) */

undefined8 -[EventDriver setAutoDimBrightness:](int param_1,undefined4 param_2,int param_3)

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
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x40 < param_3) {
    param_3 = 0x40;
  }
  if ((param_3 != *(int *)(param_1 + 0x1c8)) &&
     (*(int *)(param_1 + 0x1c8) = param_3, *(char *)(param_1 + 0x1d3) == '\x01')) {
    _objc_msgSend(param_1,paSetbrightness_0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4574 start=0xf00d40b8 */

undefined8 -[EventDriver autoDimBrightness](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x1c8));
}
/* GHIDRADEC_FUNCTION index=4575 start=0xf00d40c8 */

undefined8 -[EventDriver currentBrightness](int param_1,undefined4 param_2)

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
  if (*(char *)(param_1 + 0x1d3) == '\x01') {
    iVar1 = *(int *)(param_1 + 0x1c8);
    if (*(int *)(param_1 + 0x1cc) <= iVar1) {
      iVar1 = *(int *)(param_1 + 0x1cc);
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1cc);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=4576 start=0xf00d40fc */

/* WARNING: Removing unreachable block (ram,0xf00d4110) */

undefined8 -[EventDriver doAutoDim](int param_1,undefined4 param_2)

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
  *(undefined *)(param_1 + 0x1d3) = 1;
  _objc_msgSend(param_1,paSetbrightness_0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4577 start=0xf00d4120 */

/* WARNING: Removing unreachable block (ram,0xf00d4130) */

undefined8 -[EventDriver undoAutoDim](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  
  uVar1 = paSetbrightness_0;
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
  *(undefined *)(param_1 + 0x1d3) = 0;
  _objc_msgSend(param_1,uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4578 start=0xf00d4140 */

/* WARNING: Removing unreachable block (ram,0xf00d41c4) */

undefined8 -[EventDriver forceAutoDimState:](int param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
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
  if (param_3 == '\x01') {
    if (*(char *)(param_1 + 0x1d3) != '\0') goto locret_F00D41CC;
    uVar1 = paDoautodim;
    if (*(char *)(param_1 + 0x1d2) == '\x01') {
      *(undefined4 *)(param_1 + 0x1a4) = *(undefined4 *)(*(int *)(param_1 + 0x168) + 0x10);
      uVar1 = paDoautodim;
    }
  }
  else {
    if (*(char *)(param_1 + 0x1d3) != '\x01') goto locret_F00D41CC;
    uVar1 = paUndoautodim;
    if (*(char *)(param_1 + 0x1d2) == '\x01') {
      *(int *)(param_1 + 0x1a4) =
           *(int *)(*(int *)(param_1 + 0x168) + 0x10) + *(int *)(param_1 + 0x1a0);
      uVar1 = paUndoautodim;
    }
  }
  _objc_msgSend(param_1,uVar1);
locret_F00D41CC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4579 start=0xf00d41d4 */

undefined8 -[EventDriver setAudioVolume:](int param_1,undefined4 param_2,int param_3)

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
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (0x40 < param_3) {
    param_3 = 0x40;
  }
  *(int *)(param_1 + 0x1c4) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4580 start=0xf00d4200 */

/* WARNING: Removing unreachable block (ram,0xf00d4230) */
/* WARNING: Removing unreachable block (ram,0xf00d4210) */

undefined8 -[EventDriver setUserAudioVolume:](int param_1,undefined4 param_2,undefined4 param_3)

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
  _objc_msgSend(param_1,paSetaudiovolume,param_3);
  _objc_msgSend(param_1,paEvspecialkeyms,0,10,0,*(undefined4 *)(param_1 + 0x1c4));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4581 start=0xf00d4240 */

undefined8 -[EventDriver audioVolume](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x1c4));
}
/* GHIDRADEC_FUNCTION index=4582 start=0xf00d4250 */

/* WARNING: Removing unreachable block (ram,0xf00d4274) */

undefined8 -[EventDriver setBrightness](int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int iVar1;
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
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x188)) {
    do {
      _objc_msgSend(param_1,paEvdispatchComm,iVar1,4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x188));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4583 start=0xf00d4298 */

/* WARNING: Removing unreachable block (ram,0xf00d42ac) */

undefined8 -[EventDriver showCursor](int param_1,undefined4 param_2)

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
  _objc_msgSend(param_1,paEvdispatchComm,*(undefined4 *)(param_1 + 0x18c),2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4584 start=0xf00d42bc */

/* WARNING: Removing unreachable block (ram,0xf00d42d0) */

undefined8 -[EventDriver hideCursor](int param_1,undefined4 param_2)

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
  _objc_msgSend(param_1,paEvdispatchComm,*(undefined4 *)(param_1 + 0x18c),1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4585 start=0xf00d42e0 */

/* WARNING: Removing unreachable block (ram,0xf00d42f4) */

undefined8 -[EventDriver moveCursor](int param_1,undefined4 param_2)

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
  _objc_msgSend(param_1,paEvdispatchComm,*(undefined4 *)(param_1 + 0x18c),3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4586 start=0xf00d4304 */

/* WARNING: Removing unreachable block (ram,0xf00d432c) */
/* WARNING: Removing unreachable block (ram,0xf00d4308) */

undefined8 -[EventDriver attachDefaultEventSources](int *param_1,undefined4 param_2)

{
  int *piVar1;
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
  piVar1 = param_1;
  _defaultEventSources();
  iVar2 = *piVar1;
  while (iVar2 != 0) {
    _objc_msgSend(param_1,paAttacheventsou,*piVar1);
    piVar1 = piVar1 + 1;
    iVar2 = *piVar1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4587 start=0xf00d4350 */

/* WARNING: Removing unreachable block (ram,0xf00d4418) */
/* WARNING: Removing unreachable block (ram,0xf00d43c4) */
/* WARNING: Removing unreachable block (ram,0xf00d4394) */
/* WARNING: Removing unreachable block (ram,0xf00d43f4) */
/* WARNING: Removing unreachable block (ram,0xf00d4428) */
/* WARNING: Removing unreachable block (ram,0xf00d4358) */

undefined8 -[EventDriver attachEventSource:](int param_1,undefined4 param_2,uint param_3)

{
  undefined6 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
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
  uVar5 = param_3;
  _objc_getClass();
  puVar1 = paProbe_0;
  if (uVar5 == 0) {
    puVar4 = aSSNoSuchClass;
  }
  else {
    uVar2 = uVar5;
    _objc_msgSend(uVar5,paRespondsto,paProbe_0);
    if ((uVar2 & 0xff) == 0) {
      puVar4 = aSSDoesNotRespo;
    }
    else {
      _objc_msgSend(uVar5,puVar1);
      if (uVar5 == 0) {
        puVar4 = aSProbeOfSFaile;
      }
      else {
        iVar3 = param_1;
        _objc_msgSend(param_1,paRegisterevents,uVar5);
        if (iVar3 != 0) goto locret_F00D4430;
        puVar4 = aSBecomeownerOf;
      }
    }
  }
  uVar5 = 0;
  _objc_msgSend(param_1,paName);
  _IOLog(puVar4,param_1,param_3);
locret_F00D4430:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=4588 start=0xf00d4438 */

/* WARNING: Removing unreachable block (ram,0xf00d44d4) */
/* WARNING: Removing unreachable block (ram,0xf00d44bc) */
/* WARNING: Removing unreachable block (ram,0xf00d44a4) */
/* WARNING: Removing unreachable block (ram,0xf00d44c8) */
/* WARNING: Removing unreachable block (ram,0xf00d44f4) */
/* WARNING: Removing unreachable block (ram,0xf00d4444) */

undefined8 -[EventDriver detachEventSources](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  int *piVar5;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paLock);
  iVar3 = param_1 + 0x174;
  if (iVar3 == *(int *)(param_1 + 0x174)) {
    uVar1 = *(undefined4 *)(param_1 + 0x170);
  }
  else {
    piVar5 = *(int **)(param_1 + 0x174);
    while( true ) {
      iVar4 = piVar5[1];
      iVar2 = piVar5[2];
      if (iVar3 == iVar4) {
        *(int *)(param_1 + 0x178) = iVar2;
      }
      else {
        *(int *)(iVar4 + 8) = iVar2;
      }
      if (iVar3 == iVar2) {
        *(int *)(param_1 + 0x174) = iVar4;
      }
      else {
        *(int *)(iVar2 + 4) = iVar4;
      }
      _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paUnlock);
      if (*piVar5 != 0) {
        _objc_msgSend(*piVar5,paRelinquishowne_0,param_1);
      }
      _IOFree(piVar5,0xc);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paLock);
      if (iVar3 == *(int *)(param_1 + 0x174)) break;
      piVar5 = *(int **)(param_1 + 0x174);
    }
    uVar1 = *(undefined4 *)(param_1 + 0x170);
  }
  _objc_msgSend(uVar1,paUnlock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4589 start=0xf00d4504 */

/* WARNING: Removing unreachable block (ram,0xf00d4550) */
/* WARNING: Removing unreachable block (ram,0xf00d4530) */
/* WARNING: Removing unreachable block (ram,0xf00d453c) */
/* WARNING: Removing unreachable block (ram,0xf00d4588) */
/* WARNING: Removing unreachable block (ram,0xf00d4514) */

undefined8 -[EventDriver registerEventSource:](int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
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
  iVar2 = param_3;
  _objc_msgSend(param_3,paBecomeowner,param_1);
  if (iVar2 == 0) {
    piVar1 = (int *)0xc;
    _IOMalloc();
    _bzero();
    *piVar1 = param_3;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paLock);
    iVar2 = *(int *)(param_1 + 0x178);
    if (param_1 + 0x174 == iVar2) {
      *(int **)(param_1 + 0x174) = piVar1;
    }
    else {
      *(int **)(iVar2 + 4) = piVar1;
    }
    piVar1[2] = iVar2;
    piVar1[1] = param_1 + 0x174;
    *(int **)(param_1 + 0x178) = piVar1;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x170),paUnlock);
  }
  else {
    param_1 = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4590 start=0xf00d4598 */

qword -[EventDriver relinquishOwnershipRequest:](int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,-(uint)(*(char *)(param_1 + 0x1d2) != '\0')) & 0xfffffffffffffd2b;
}
/* GHIDRADEC_FUNCTION index=4591 start=0xf00d45b4 */

/* WARNING: Removing unreachable block (ram,0xf00d4610) */
/* WARNING: Removing unreachable block (ram,0xf00d45e8) */
/* WARNING: Removing unreachable block (ram,0xf00d45f8) */
/* WARNING: Removing unreachable block (ram,0xf00d4624) */
/* WARNING: Removing unreachable block (ram,0xf00d45c4) */

undefined8 -[EventDriver canBecomeOwner:](undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
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
  iVar1 = param_3;
  _objc_msgSend(param_3,paBecomeowner,param_1);
  uVar3 = paName;
  if (iVar1 != 0) {
    uVar2 = param_1;
    _objc_msgSend(param_1,paName);
    _objc_msgSend(param_3,uVar3);
    uVar3 = param_1;
    _objc_msgSend(param_1,paStringfromretu,iVar1);
    _IOLog(aSBecomeownerOf_0,uVar2,param_3,uVar3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4592 start=0xf00d4634 */

/* WARNING: Removing unreachable block (ram,0xf00d4660) */
/* WARNING: Removing unreachable block (ram,0xf00d4638) */
/* WARNING: Heritage AFTER dead removal. Example location: o3 : 0xf00d4660 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined8
-[EventDriver relativePointerEvent:deltaX:deltaY:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
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
  _objc_msgSend(param_1,paRelativepointe,(int)((qword)in_o2_3 >> 0x20),
                (int)*(undefined8 *)((int)register0x00000038 + -0x18),param_3,
                (int)((qword)*(undefined8 *)((int)register0x00000038 + -0x18) >> 0x20));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4593 start=0xf00d4670 */

/* WARNING: Removing unreachable block (ram,0xf00d4744) */
/* WARNING: Removing unreachable block (ram,0xf00d46f0) */
/* WARNING: Removing unreachable block (ram,0xf00d4754) */
/* WARNING: Removing unreachable block (ram,0xf00d4698) */

undefined8
-[EventDriver relativePointerEvent:deltaX:deltaY:atTime:]
          (int param_1,undefined4 param_2,uint param_3,int param_4)

{
  sword sVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
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
  *(int *)((int)register0x00000038 + 0x58) = (int)in_o4_5;
  uVar4 = (uint)((qword)*(undefined8 *)((int)register0x00000038 + 0x58) >> 0x20);
  uVar3 = uVar4 << 8 | (uint)*(undefined8 *)((int)register0x00000038 + 0x58) >> 0x18;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock,uVar4 >> 0x18,uVar3);
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    uVar2 = *(undefined4 *)(param_1 + 0x110);
  }
  else {
    if ((param_3 & 4) != (*(uint *)(*(int *)(param_1 + 0x168) + 8) & 4)) {
      if ((param_3 & 4) == 0) {
        *(undefined *)(param_1 + 0x1c0) = 0;
      }
      else {
        *(undefined *)(param_1 + 0x1c0) = 0xff;
      }
    }
    _objc_msgSend(param_1,paSetbuttonstate,param_3,uVar3);
    if (param_4 == 0) {
      if ((int)((qword)in_o4_5 >> 0x20) == 0) {
        uVar2 = *(undefined4 *)(param_1 + 0x110);
        goto loc_F00D4750;
      }
      sVar1 = *(sword *)(param_1 + 0x1a8);
    }
    else {
      sVar1 = *(sword *)(param_1 + 0x1a8);
    }
    *(sword *)(param_1 + 0x1a8) = sVar1 + (sword)param_4;
    *(sword *)(param_1 + 0x1aa) = *(sword *)(param_1 + 0x1aa) + (sword)((qword)in_o4_5 >> 0x20);
    if (*(char *)(param_1 + 0x211) == '\0') {
      _objc_msgSend(param_1,paSetcursorposit_0,param_1 + 0x1a8,uVar3);
    }
    uVar2 = *(undefined4 *)(param_1 + 0x110);
  }
loc_F00D4750:
  _objc_msgSend(uVar2,paUnlock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4594 start=0xf00d4764 */

/* WARNING: Removing unreachable block (ram,0xf00d4804) */
/* WARNING: Removing unreachable block (ram,0xf00d4778) */
/* WARNING: Removing unreachable block (ram,0xf00d47d0) */
/* WARNING: Removing unreachable block (ram,0xf00d4798) */
/* WARNING: Removing unreachable block (ram,0xf00d4768) */
/* WARNING: Heritage AFTER dead removal. Example location: o3 : 0xf00d4804 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined8
-[EventDriver absolutePointerEvent:at:inProximity:](int param_1,undefined4 param_2,char param_3)

{
  uint uVar1;
  qword in_o2_3;
  undefined4 unaff_l0;
  char cVar2;
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
  uVar1 = (uint)(in_o2_3 >> 0x20);
  _IOGetTimestamp((undefined *)((int)register0x00000038 + -0x18));
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  cVar2 = *(char *)(param_1 + 0x1c0);
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
  }
  else {
    if ((uVar1 & 4) != (*(uint *)(*(int *)(param_1 + 0x168) + 8) & 4)) {
      cVar2 = -((in_o2_3 & 0x400000000) != 0);
    }
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
    _objc_msgSend(param_1,paAbsolutepointe,uVar1,(int)in_o2_3,(int)param_3,cVar2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4595 start=0xf00d4814 */

/* WARNING: Removing unreachable block (ram,0xf00d484c) */
/* WARNING: Removing unreachable block (ram,0xf00d4818) */
/* WARNING: Heritage AFTER dead removal. Example location: o3 : 0xf00d484c */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined8
-[EventDriver absolutePointerEvent:at:inProximity:withPressure:]
          (undefined4 param_1,undefined4 param_2,char param_3,undefined4 param_4)

{
  undefined4 uVar1;
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
  
  uVar1 = (undefined4)((qword)in_o2_3 >> 0x20);
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
  _objc_msgSend(param_1,paAbsolutepointe,uVar1,(int)in_o2_3,(int)param_3,param_4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4596 start=0xf00d485c */

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
/* GHIDRADEC_FUNCTION index=4597 start=0xf00d4a0c */

/* WARNING: Removing unreachable block (ram,0xf00d4ab8) */
/* WARNING: Removing unreachable block (ram,0xf00d4ac8) */
/* WARNING: Removing unreachable block (ram,0xf00d4a64) */

undefined8
-[EventDriver keyboardEvent:flags:keyCode:charCode:charSet:originalCharCode:originalCharSet:repeat:atTime:]
          (int param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined2 param_5,
          undefined2 param_6)

{
  undefined4 uVar1;
  uint uVar2;
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
  *(undefined2 *)((int)register0x00000038 + -0x18) = param_5;
  uVar2 = *(uint *)((int)register0x00000038 + 0x6c);
  uVar3 = *(uint *)((int)register0x00000038 + 0x70);
  *(undefined2 *)((int)register0x00000038 + -0x1a) = param_6;
  *(sword *)((int)register0x00000038 + -0x1e) =
       (sword)(char)*(undefined4 *)((int)register0x00000038 + 0x68);
  *(sword *)((int)register0x00000038 + -0x1c) =
       (sword)*(undefined4 *)((int)register0x00000038 + 0x5c);
  *(sword *)((int)register0x00000038 + -0x20) =
       (sword)*(undefined4 *)((int)register0x00000038 + 100);
  *(sword *)((int)register0x00000038 + -0x16) =
       (sword)*(undefined4 *)((int)register0x00000038 + 0x60);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock,
                *(undefined4 *)((int)register0x00000038 + 0x5c),
                *(undefined4 *)((int)register0x00000038 + 100),uVar2 >> 0x18);
  uVar1 = paPosteventAtAtt;
  if (*(char *)(param_1 + 0x1d2) != '\0') {
    *(uint *)(*(int *)(param_1 + 0x168) + 0xc) =
         *(uint *)(*(int *)(param_1 + 0x168) + 0xc) & 0xff80ff80 | param_4 & 0x7f007f;
    _objc_msgSend(param_1,uVar1,param_3,param_1 + 0x1a8,uVar2 << 8 | uVar3 >> 0x18,
                  (undefined *)((int)register0x00000038 + -0x20));
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4598 start=0xf00d4ad8 */

/* WARNING: Removing unreachable block (ram,0xf00d4cf4) */
/* WARNING: Removing unreachable block (ram,0xf00d4bf8) */
/* WARNING: Removing unreachable block (ram,0xf00d4c38) */
/* WARNING: Removing unreachable block (ram,0xf00d4ca4) */
/* WARNING: Removing unreachable block (ram,0xf00d4c94) */
/* WARNING: Removing unreachable block (ram,0xf00d4b7c) */
/* WARNING: Removing unreachable block (ram,0xf00d4b0c) */
/* WARNING: Removing unreachable block (ram,0xf00d4b2c) */
/* WARNING: Removing unreachable block (ram,0xf00d4ce4) */
/* WARNING: Removing unreachable block (ram,0xf00d4c68) */
/* WARNING: Removing unreachable block (ram,0xf00d4c28) */
/* WARNING: Removing unreachable block (ram,0xf00d4be8) */
/* WARNING: Removing unreachable block (ram,0xf00d4cb4) */
/* WARNING: Removing unreachable block (ram,0xf00d4d1c) */
/* WARNING: Removing unreachable block (ram,0xf00d4ae8) */

undefined8
-[EventDriver keyboardSpecialEvent:flags:keyCode:specialty:atTime:]
          (int param_1,undefined4 param_2,int param_3,uint param_4,undefined4 param_5,
          undefined4 param_6)

{
  undefined (*pauVar1) [15];
  undefined4 uVar2;
  undefined (*pauVar3) [12];
  undefined4 unaff_l0;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l1;
  uint uVar6;
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
  uVar4 = *(uint *)((int)register0x00000038 + 0x5c);
  uVar6 = *(uint *)((int)register0x00000038 + 0x60);
  _bzero((undefined *)((int)register0x00000038 + -0x20),0xc);
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock,uVar4 >> 0x18);
  iVar5 = -1;
  if (*(char *)(param_1 + 0x1d2) == '\0') {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
    goto locret_F00D4D24;
  }
  *(uint *)(*(int *)(param_1 + 0x168) + 0xc) =
       *(uint *)(*(int *)(param_1 + 0x168) + 0xc) & 0xff80ff80 | param_4 & 0x7f007f;
  if (*(char *)(param_1 + 0x1d3) == '\x01') {
    _objc_msgSend(param_1,paForceautodimst,0);
  }
  pauVar1 = paSetbrightness;
  uVar2 = paSetaudiovolume;
  if (param_3 != 10) {
    uVar2 = *(undefined4 *)(param_1 + 0x110);
    goto loc_F00D4CF0;
  }
  pauVar3 = paAudiovolume;
  switch(param_6) {
  case :
    if ((param_4 & 0x1c0000) == 0) {
      iVar5 = param_1;
      _objc_msgSend(param_1,paAudiovolume);
      _objc_msgSend(param_1,uVar2,iVar5 + 1);
      pauVar3 = paAudiovolume;
    }
    break;
  case :
    if ((param_4 & 0x1c0000) == 0) {
      iVar5 = param_1;
      _objc_msgSend(param_1,paAudiovolume);
      _objc_msgSend(param_1,uVar2,iVar5 + -1);
      pauVar3 = paAudiovolume;
    }
    break;
  case :
    pauVar3 = (undefined (*) [12])paBrightness;
    if ((param_4 & 0x1c0000) == 0) {
      iVar5 = param_1;
      _objc_msgSend(param_1,paBrightness);
      iVar5 = iVar5 + 1;
loc_F00D4CA0:
      _objc_msgSend(param_1,pauVar1,iVar5);
      pauVar3 = (undefined (*) [12])paBrightness;
    }
    break;
  case :
    pauVar3 = (undefined (*) [12])paBrightness;
    if ((param_4 & 0x1c0000) == 0) {
      iVar5 = param_1;
      _objc_msgSend(param_1,paBrightness);
      iVar5 = iVar5 + -1;
      goto loc_F00D4CA0;
    }
    break;
  :
    goto def_F00D4BA8;
  case :
    *(undefined2 *)((int)register0x00000038 + -0x1e) = 1;
    _objc_msgSend(param_1,paPosteventAtAtt,0xe,param_1 + 0x1a8,uVar4 << 8 | uVar6 >> 0x18,
                  (undefined *)((int)register0x00000038 + -0x20));
    goto def_F00D4BA8;
  }
  iVar5 = param_1;
  _objc_msgSend(param_1,pauVar3);
def_F00D4BA8:
  uVar2 = *(undefined4 *)(param_1 + 0x110);
loc_F00D4CF0:
  _objc_msgSend(uVar2,paUnlock);
  if (iVar5 != -1) {
    _objc_msgSend(param_1,paEvspecialkeyms,param_6,param_3,param_4,iVar5);
  }
locret_F00D4D24:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4599 start=0xf00d4d2c */

/* WARNING: Removing unreachable block (ram,0xf00d4d7c) */
/* WARNING: Removing unreachable block (ram,0xf00d4d38) */

undefined8 -[EventDriver updateEventFlags:](int param_1,undefined4 param_2,uint param_3)

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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paLock);
  if (*(char *)(param_1 + 0x1d2) != '\0') {
    *(uint *)(*(int *)(param_1 + 0x168) + 0xc) =
         *(uint *)(*(int *)(param_1 + 0x168) + 0xc) & 0xff80ff80 | param_3 & 0x7f007f;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x110),paUnlock);
  return CONCAT44(param_2,param_1);
}

