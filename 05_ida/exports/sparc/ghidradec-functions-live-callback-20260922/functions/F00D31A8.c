
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

