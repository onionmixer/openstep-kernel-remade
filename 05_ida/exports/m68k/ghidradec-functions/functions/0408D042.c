
void sub_408D042(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined *puVar7;
  undefined *puVar8;
  int *piStack_10;
  undefined auStack_c [8];
  
  iVar2 = 0;
  puVar8 = unk_40B5418;
  puVar7 = unk_40B5404;
  piStack_10 = (int *)(unk_40B5404 + 0x10);
  piVar5 = (int *)(unk_40B5404 + 4);
  iVar6 = 0x40b5420;
  piVar4 = (int *)(unk_40B5404 + 8);
  piVar3 = (int *)(unk_40B5404 + 0xc);
  do {
    iVar1 = *piVar3;
    if ((iVar1 != 0) && (*piVar3 = iVar1 + -1, iVar1 == 1)) {
      _printf(aZsDLostRecvSwI,iVar2);
      sub_408C552(iVar2);
    }
    iVar1 = *piVar4;
    if ((iVar1 != 0) && (*piVar4 = iVar1 + -1, iVar1 == 1)) {
      _printf(aZsDLostXmitSwI,iVar2);
      sub_408CC8C(iVar2);
    }
    iVar1 = *piVar5;
    if (((iVar1 != 0) && ((*(byte *)(iVar6 + 3) & 8) != 0)) && (*piVar5 = iVar1 + -1, iVar1 == 1)) {
      _printf(aZsDLostXmitHwI,iVar2);
      sub_408CBAC(iVar2);
    }
    if (*piStack_10 == 0) {
      if ((*(uint *)puVar7 & 1) != 0) {
        _log(4,aZsDRecvBufferO,iVar2);
        *piStack_10 = (_hz / _hz) * 10;
      }
    }
    else {
      *piStack_10 = *piStack_10 + -1;
      *(uint *)puVar7 = *(uint *)puVar7 & 0xfffffffe;
    }
    if (*(int *)puVar8 == 0) {
      if ((*(uint *)puVar7 & 2) != 0) {
        _log(4,aZsDRecvUartOve,iVar2);
        *(int *)puVar8 = (_hz / _hz) * 10;
      }
    }
    else {
      *(int *)puVar8 = *(int *)puVar8 + -1;
      *(uint *)puVar7 = *(uint *)puVar7 & 0xfffffffd;
    }
    puVar8 = (undefined *)((int)puVar8 + 0x164);
    puVar7 = (undefined *)((int)puVar7 + 0x164);
    piStack_10 = piStack_10 + 0x59;
    piVar5 = piVar5 + 0x59;
    iVar6 = iVar6 + 0x164;
    piVar4 = piVar4 + 0x59;
    piVar3 = piVar3 + 0x59;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 2);
  _ticks_to_timeval(_hz,auStack_c);
  _us_timeout(sub_408D042,0,auStack_c,0);
  return;
}
