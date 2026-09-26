
void _od_perror(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  sword sVar7;
  undefined *puVar8;
  word wVar9;
  
  cVar4 = *(char *)(param_1 + 599);
  wVar9 = 0;
  iVar2 = *(int *)(param_2 + 8);
  iVar3 = *(int *)(iVar2 + 0xae);
  piVar5 = (int *)((&_odcinfo)[(param_1 + -0x40c3b88) * 0x451ab30b >> 2] + 0x18);
  if (((&_odcinfo)[(param_1 + -0x40c3b88) * 0x451ab30b >> 2] != 0) &&
     (piVar1 = (int *)*piVar5, piVar1 != piVar5)) {
    iVar6 = _disksort_first(piVar1);
    if (iVar6 != 0) {
      wVar9 = *(word *)(iVar6 + 0x1e);
    }
  }
  if (((_od_errmsg_filter <= param_3) || ((_od_dbug._0_1_ & 0x10) != 0)) &&
     ((*(uint *)(param_1 + 0x220) & 0x40000) == 0)) {
    if (*(sword *)(param_1 + 0x248) == 2) {
      puVar8 = (undefined *)&aRead;
    }
    else if (*(sword *)(param_1 + 0x248) == 1) {
      puVar8 = (undefined *)&aWrite;
    }
    else {
      puVar8 = aDriveCommand;
      if (*(sword *)(param_1 + 0x248) == 4) {
        puVar8 = (undefined *)&aErase;
      }
    }
    if (wVar9 == 0) {
      sVar7 = 0x3f;
    }
    else {
      sVar7 = (wVar9 & 7) + 0x61;
    }
    _od_xpr_alert(aOdDCSS,*(undefined2 *)(iVar2 + 0xd2),sVar7,puVar8,
                  *(undefined4 *)(_od_errtype + param_3 * 4),0);
    puVar8 = &unk_40A62E7;
    if ((*(uint *)(param_1 + 0x220) & 0x40000) != 0) {
      puVar8 = aTesting;
    }
    _od_xpr_alert(aSSBlockDPhysBl,*(undefined4 *)(DAT_40b1c14 + cVar4 * 8),puVar8,param_4,
                  param_5 - *(int *)(iVar2 + 0xbe),0);
    iVar2 = *(int *)(iVar3 + 100);
    _od_xpr_alert(aDDD,param_5 / iVar2,0,param_5 % iVar2,0,0);
    if ((_od_dbug._0_1_ & 4) != 0) {
      _od_note(param_1,0x4000,_od_xpr_alert);
    }
  }
  return;
}

