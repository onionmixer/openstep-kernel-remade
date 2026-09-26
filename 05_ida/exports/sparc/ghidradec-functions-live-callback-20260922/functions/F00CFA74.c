
/* WARNING: Removing unreachable block (ram,0xf00cfcfc) */
/* WARNING: Removing unreachable block (ram,0xf00cfc98) */
/* WARNING: Removing unreachable block (ram,0xf00cfc64) */
/* WARNING: Removing unreachable block (ram,0xf00cfc34) */
/* WARNING: Removing unreachable block (ram,0xf00cfc00) */
/* WARNING: Removing unreachable block (ram,0xf00cfce0) */
/* WARNING: Removing unreachable block (ram,0xf00cfcc0) */
/* WARNING: Removing unreachable block (ram,0xf00cfb20) */
/* WARNING: Removing unreachable block (ram,0xf00cfb34) */
/* WARNING: Removing unreachable block (ram,0xf00cfcd8) */
/* WARNING: Removing unreachable block (ram,0xf00cfbdc) */
/* WARNING: Removing unreachable block (ram,0xf00cfc0c) */
/* WARNING: Removing unreachable block (ram,0xf00cfc50) */
/* WARNING: Removing unreachable block (ram,0xf00cfc84) */
/* WARNING: Removing unreachable block (ram,0xf00cfca8) */
/* WARNING: Removing unreachable block (ram,0xf00cfd18) */
/* WARNING: Removing unreachable block (ram,0xf00cfaf0) */
/* WARNING: Removing unreachable block (ram,0xf00cfaa0) */

undefined8 sub_F00CFA74(int param_1,uint param_2)

{
  undefined (*pauVar1) [12];
  undefined7 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar9;
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
  piVar8 = (int *)(param_1 + 0x1a8);
  if ((param_2 & 0xff) == 0) {
    piVar8 = (int *)(param_1 + 0x1b0);
  }
  piVar6 = (int *)*piVar8;
  if (piVar8 == piVar6) {
    _IOLog(aSdthreaddequeu);
    goto locret_F00CFD20;
  }
  piVar7 = (int *)piVar6[0xb];
  piVar5 = (int *)piVar6[0xc];
  piVar4 = piVar8;
  if (piVar8 != piVar7) {
    piVar4 = piVar7 + 0xb;
  }
  piVar4[1] = (int)piVar5;
  if (piVar8 != piVar5) {
    piVar8 = piVar5 + 0xb;
  }
  *piVar8 = (int)piVar7;
  if ((param_2 & 0xff) != 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1c0),paLock);
    *(int *)(param_1 + 0x1c4) = *(int *)(param_1 + 0x1c4) + 1;
    if (*piVar6 == 4) {
      *(undefined *)(param_1 + 0x1c8) = 1;
      _volCheckEjecting(param_1,2);
      uVar3 = *(undefined4 *)(param_1 + 0x1c0);
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 0x1c0);
    }
    _objc_msgSend(uVar3,paUnlockwith,*(undefined4 *)(param_1 + 0x1c4));
  }
  puVar2 = paUnlock;
  switch(*piVar6) {
  case :
  case :
  case :
  case :
    uVar3 = *(undefined4 *)(param_1 + 0x1b8);
    goto loc_F00CFC84;
  case :
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paUnlock);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1c0),paLockwhen,1);
    uVar3 = *(undefined4 *)(param_1 + 0x1c0);
loc_F00CFC84:
    _objc_msgSend(uVar3,puVar2);
    _objc_msgSend(param_1,paDosdbuf,piVar6);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paLock);
    break;
  case :
    piVar8 = (int *)(param_1 + 0x1a8);
    if (piVar8 != *(int **)(param_1 + 0x1a8)) {
      iVar9 = *piVar8;
      while( true ) {
        piVar7 = *(int **)(iVar9 + 0x2c);
        piVar5 = *(int **)(iVar9 + 0x30);
        piVar4 = piVar8;
        if (piVar8 != piVar7) {
          piVar4 = piVar7 + 0xb;
        }
        piVar4[1] = (int)piVar5;
        piVar4 = piVar8;
        if (piVar8 != piVar5) {
          piVar4 = piVar5 + 0xb;
        }
        *piVar4 = (int)piVar7;
        _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paUnlock);
        *(undefined4 *)(iVar9 + 0x28) = 0xfffffbb2;
        if (*(int *)(iVar9 + 0x14) != 0) {
          *(undefined4 *)(*(int *)(iVar9 + 0x14) + 0x20) = 0x10;
        }
        _objc_msgSend(param_1,paSdiocomplete,iVar9);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paLock);
        if (piVar8 == (int *)*piVar8) break;
        iVar9 = *piVar8;
      }
    }
  case :
    piVar6[10] = 0;
    _objc_msgSend(param_1,paSdiocomplete,piVar6);
    break;
  case :
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1b8),paUnlock);
    piVar6[10] = 0;
    _objc_msgSend(param_1,paSdiocomplete,piVar6);
    _IOExitThread();
  }
  if ((param_2 & 0xff) != 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1c0),paLock);
    pauVar1 = paUnlockwith;
    *(int *)(param_1 + 0x1c4) = *(int *)(param_1 + 0x1c4) + -1;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x1c0),pauVar1);
  }
locret_F00CFD20:
  return CONCAT44(param_2,param_1);
}

