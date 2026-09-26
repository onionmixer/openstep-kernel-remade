/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b04b8 */

void FUN_001b04b8(int param_1,undefined4 param_2,int param_3,short *param_4,uint param_5,
                 int *param_6)

{
  short *psVar1;
  int *piVar2;
  short sVar3;
  short *psVar4;
  bool bVar5;
  int iVar6;
  byte bVar7;
  char **ppcVar8;
  char *pcStack_38;
  undefined4 uStack_34;
  int iStack_30;
  short *psStack_2c;
  
  psVar4 = *(short **)(param_1 + 0x168);
  sVar3 = *psVar4;
  psVar1 = psVar4 + psVar4[2] * 0x16 + 0x28;
  piVar2 = (int *)(psVar4 + psVar4[1] * 0x16 + 0x28);
  bVar7 = (byte)param_3;
  if (((0x1ffe >> (bVar7 & 0x1f) & 1U) != 0) &&
     (*(uint *)(param_1 + 0x1a4) = param_5 + *(int *)(param_1 + 0x1a0),
     *(char *)(param_1 + 0x1d3) != '\0')) {
    psStack_2c = (short *)PTR_s_undoAutoDim_001f99cc;
    iStack_30 = param_1;
    uStack_34 = 0x1b0532;
    _objc_msgSend();
  }
  if ((*(uint *)(psVar4 + 8) < param_5) && (param_5 < *(int *)(psVar4 + 8) + 0x140U)) {
    *(uint *)(psVar4 + 8) = param_5;
  }
  bVar5 = false;
  if ((*(char *)(param_1 + 0x1d2) != '\0') &&
     (**(short **)(param_1 + 0x168) != (*(short **)(param_1 + 0x168))[1])) {
    bVar5 = true;
  }
  if (((((*(byte *)((int)psVar4 + 0x33) & 0x40) == 0) &&
       ((int *)(psVar4 + sVar3 * 0x16 + 0x28) != piVar2)) && (*(int *)(psVar1 + 4) == param_3)) &&
     ((0x2e0 >> (bVar7 & 0x1f) & 1U) != 0)) {
    iStack_30 = 0x1b05b6;
    psStack_2c = psVar1 + 2;
    iVar6 = _ev_try_lock();
    if (iVar6 != 0) {
      *(int *)(psVar1 + 6) = (int)*param_4;
      *(int *)(psVar1 + 8) = (int)param_4[1];
      *(uint *)(psVar1 + 10) = param_5;
      if (param_6 != (int *)0x0) {
        *(int *)(psVar1 + 0x10) = *param_6;
        *(int *)(psVar1 + 0x12) = param_6[1];
        *(int *)(psVar1 + 0x14) = param_6[2];
      }
      iStack_30 = 0x1b060e;
      psStack_2c = psVar1 + 2;
      _ev_unlock();
      return;
    }
  }
  ppcVar8 = (char **)&stack0xffffffd8;
  if (*piVar2 == (int)*psVar4) {
    psStack_2c = (short *)PTR_s_name_001f9228;
    iStack_30 = param_1;
    uStack_34 = 0x1b0835;
    uStack_34 = _objc_msgSend();
    ppcVar8 = &pcStack_38;
    pcStack_38 = "%s: postEvent LLEventQueue overflow.\n";
    _IOLog();
    goto LAB_001b0840;
  }
  piVar2[2] = param_3;
  piVar2[3] = (int)*param_4;
  piVar2[4] = (int)param_4[1];
  piVar2[6] = *(int *)(psVar4 + 6);
  piVar2[5] = param_5;
  piVar2[7] = 0;
  if (param_6 != (int *)0x0) {
    piVar2[8] = *param_6;
    piVar2[9] = param_6[1];
    piVar2[10] = param_6[2];
  }
  if (param_3 == 2) {
    *(short *)((int)piVar2 + 0x22) = *(short *)(param_1 + 500);
    *(undefined2 *)(param_1 + 500) = 0;
  }
  else if (param_3 < 3) {
    if (param_3 == 1) {
      iVar6 = *(int *)(param_1 + 0x168);
      do {
        *(short *)(iVar6 + 6) = *(short *)(iVar6 + 6) + 1;
      } while (*(short *)(iVar6 + 6) == 0);
      sVar3 = *(short *)(iVar6 + 6);
      *(short *)(param_1 + 500) = sVar3;
      *(short *)((int)piVar2 + 0x22) = sVar3;
    }
  }
  else if (param_3 == 3) {
    iVar6 = *(int *)(param_1 + 0x168);
    do {
      *(short *)(iVar6 + 6) = *(short *)(iVar6 + 6) + 1;
    } while (*(short *)(iVar6 + 6) == 0);
    sVar3 = *(short *)(iVar6 + 6);
    *(short *)(param_1 + 0x1f6) = sVar3;
    *(short *)((int)piVar2 + 0x22) = sVar3;
  }
  else if (param_3 == 4) {
    *(short *)((int)piVar2 + 0x22) = *(short *)(param_1 + 0x1f6);
    *(undefined2 *)(param_1 + 0x1f6) = 0;
  }
  if ((0x66 >> (bVar7 & 0x1f) & 1U) != 0) {
    *(undefined1 *)(piVar2 + 10) = *(undefined1 *)(param_1 + 0x1c0);
  }
  if ((0x1e >> (bVar7 & 0x1f) & 1U) != 0) {
    if (param_5 - *(int *)(param_1 + 0x1b8) <= *(uint *)(param_1 + 0x1bc)) {
      iVar6 = (int)*param_4 - (int)*(short *)(param_1 + 0x1ac);
      if (iVar6 < 0) {
        iVar6 = -iVar6;
      }
      if (iVar6 <= *(short *)(param_1 + 0x1b0)) {
        iVar6 = (int)param_4[1] - (int)*(short *)(param_1 + 0x1ae);
        if (iVar6 < 0) {
          iVar6 = -iVar6;
        }
        if (iVar6 <= *(short *)(param_1 + 0x1b2)) {
          if ((param_3 == 1) || (param_3 == 3)) {
            *(uint *)(param_1 + 0x1b8) = param_5;
            iVar6 = *(int *)(param_1 + 0x1b4);
            *(int *)(param_1 + 0x1b4) = iVar6 + 1;
            piVar2[9] = iVar6 + 1;
          }
          else {
            piVar2[9] = *(int *)(param_1 + 0x1b4);
          }
          goto LAB_001b080b;
        }
      }
    }
    if ((param_3 == 1) || (param_3 == 3)) {
      *(undefined4 *)(param_1 + 0x1ac) = *(undefined4 *)param_4;
      *(uint *)(param_1 + 0x1b8) = param_5;
      *(undefined4 *)(param_1 + 0x1b4) = 1;
      piVar2[9] = 1;
    }
    else {
      piVar2[9] = 0;
    }
  }
LAB_001b080b:
  psVar4[1] = (short)*piVar2;
  psVar4[2] = (short)*(undefined4 *)psVar1;
  if (bVar5) {
    return;
  }
LAB_001b0840:
  *(undefined **)((int)ppcVar8 + -4) = PTR_s_kickEventConsumer_001f99c8;
  *(int *)((int)ppcVar8 + -8) = param_1;
  *(undefined4 *)((int)ppcVar8 + -0xc) = 0x1b084d;
  _objc_msgSend();
  return;
}

