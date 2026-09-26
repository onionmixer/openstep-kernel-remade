
void sub_407DCC4(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  
  _scsi_sensemsg(*(undefined4 *)(*param_1 + 8),*(undefined4 *)((int)param_1 + 0xc6));
  uVar2 = *(uint *)(*(int *)((int)param_1 + 0xc6) + 4) >> 8 |
          (uint)*(byte *)(*(int *)((int)param_1 + 0xc6) + 3) << 0x18;
  if ((*(byte *)((int)param_1 + 0xb) & 4) == 0) {
    puVar7 = aScsiBlockInErr_1;
  }
  else {
    uVar3 = uVar2 / *(uint *)((int)param_1 + 0xe);
    iVar6 = (int)*(sword *)(*(int *)((int)param_1 + 0xd2) + 0x70);
    if (iVar6 <= (int)uVar3) {
      piVar4 = (int *)(*(int *)((int)param_1 + 0xd2) + 0xbe);
      iVar5 = 0;
      iVar6 = uVar3 - iVar6;
      iVar1 = *piVar4;
      while (iVar1 < iVar6) {
        piVar4 = (int *)((int)piVar4 + 0x2e);
        iVar5 = iVar5 + 1;
        iVar1 = *piVar4;
        if ((iVar1 == -1) || (iVar5 == 8)) break;
      }
      _printf(aScsiBlockInErr,uVar2,iVar5 + 0x60,iVar6 - *(int *)((int)piVar4 + -0x2e));
      return;
    }
    puVar7 = aScsiBlockInErr_0;
  }
  _printf(puVar7,uVar2);
  return;
}

