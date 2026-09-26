
byte sub_407F0A8(undefined4 *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  *param_2 = (int)param_1;
  *param_1 = param_2;
  param_2[1] = 0;
  uVar1 = param_1[2];
  param_1[2] = uVar1 & 0xffffffbe | 2;
  if ((uVar1 & 8) != 0) {
    param_1[2] = uVar1 & 0xffffffb6 | 2;
    _vol_panel_remove(*(undefined4 *)((int)param_1 + 0x12));
  }
  cVar3 = '\0';
  iVar2 = _disksort_first(param_1 + 0x18);
  cVar6 = '\0';
  bVar7 = 0;
  cVar4 = iVar2 < 0;
  cVar5 = iVar2 == 0;
  if (!(bool)cVar5) {
    *(word *)((int)param_1 + 10) = *(word *)((int)param_1 + 10) & 0xfdff;
    *(undefined *)(param_2 + 4) = 0;
    cVar4 = '\0';
    cVar6 = '\0';
    bVar7 = 0;
    iVar2 = param_2[2];
    cVar5 = '\0';
    if ((*(byte *)(iVar2 + 0x24) & 0x20) == 0) {
      cVar4 = iVar2 < 0;
      cVar5 = iVar2 == 0;
      cVar6 = '\0';
      bVar7 = 0;
      _scsi_dstart(iVar2);
    }
  }
  return cVar3 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar7;
}

