
int _in_bootp_processreply(int param_1,int param_2,int param_3)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  undefined auStack_c [4];
  undefined4 uStack_8;
  
  uStack_8 = 1;
  bVar3 = false;
  uVar4 = _strlen(param_3 + 0xf4);
  if (0x37 < uVar4) {
    *(undefined *)(param_3 + 299) = 0;
  }
  _printf(&aS_3,param_3 + 0xf4);
  iVar5 = (**(code **)(*(int *)(param_1 + 0x1c) + 0xc))(param_1,0x80047410,&uStack_8,0,0);
  if (iVar5 != 0) goto loc_409099A;
  bVar2 = *(byte *)(param_3 + 0xf2);
  if (bVar2 == 2) {
    iVar5 = _in_bootp_noecho(param_1);
    if (iVar5 != 0) goto loc_409099A;
    bVar3 = true;
  }
  else {
    if (2 < bVar2) {
      if (bVar2 == 3) {
        *(undefined4 *)(param_2 + 0x10) = 0xffffffff;
        *(undefined *)(param_2 + 0x10e) = 0;
        *(undefined *)(param_2 + 0x10f) = 0;
      }
      goto loc_409099A;
    }
    if (bVar2 != 1) goto loc_409099A;
  }
  pcVar6 = (char *)(param_2 + 0x110);
  iVar5 = _vn_rdwr(0,param_1,pcVar6,0x37,0,1,0,auStack_c);
  if (iVar5 == 0) {
    if (bVar3) {
      _printf(&asc_40A6049);
    }
    cVar1 = *pcVar6;
    while (cVar1 != '\0') {
      if ((*pcVar6 == '\n') || (*pcVar6 == '\r')) {
        *pcVar6 = '\0';
        break;
      }
      pcVar6 = pcVar6 + 1;
      cVar1 = *pcVar6;
    }
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_3 + 0x14);
    *(undefined *)(param_2 + 0x10e) = *(undefined *)(param_3 + 0xf2);
    *(undefined *)(param_2 + 0x10f) = *(undefined *)(param_3 + 0xf3);
  }
loc_409099A:
  if (bVar3) {
    _in_bootp_echo(param_1);
  }
  return iVar5;
}
