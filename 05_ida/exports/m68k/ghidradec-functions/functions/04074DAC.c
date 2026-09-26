
int _odattach(int param_1)

{
  word wVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  undefined *puVar7;
  
  iVar3 = *(sword *)(param_1 + 6) * 0x28c;
  puVar7 = _od_ctrl + iVar3;
  iVar4 = (int)*(sword *)(param_1 + 4);
  iVar2 = iVar4 * 0x20;
  puVar6 = _od_drive + iVar2;
  iVar3 = *(int *)(_od_ctrl + iVar3 + 0x210);
  wVar1 = (&word_40C3E30)[iVar4 * 0x10];
  if (((wVar1 & 0x800) == 0) && (_od_label == 0)) {
    _od_buf_alloc();
  }
  _bzero(puVar6,0x20);
  *(undefined4 *)(_od_drive + iVar2 + 0x10) = *(undefined4 *)(param_1 + 0x22);
  *(int *)(_od_drive + iVar2 + 0x14) = param_1;
  *(undefined **)(_od_drive + iVar2 + 0xc) = puVar7;
  (&byte_40C3E34)[iVar2] = 0;
  (&DAT_40c3e35)[iVar2] = 0xff;
  (&DAT_40c3e32)[iVar4 * 0x10] = 0xffff;
  _od_status(puVar7,puVar6,iVar3,0x2000,9);
  _od_drive_cmd(puVar7,puVar6,0x5000,9);
  *(undefined *)(iVar3 + 5) = 0xf2;
  if ((wVar1 & 0x800) == 0) {
    uVar5 = _od_status(puVar7,puVar6,iVar3,0x3f00,9);
    if (uVar5 != 0xffffffff) {
      _printf(aDriveRomVDServ,(uVar5 & 0xfff) >> 8,(uVar5 & 0xff) >> 4);
    }
  }
  (&word_40C3E30)[iVar4 * 0x10] = (&word_40C3E30)[iVar4 * 0x10] | 0x200;
  iVar3 = _od_read_label(puVar7,puVar6,wVar1 & 0x800);
  if ((iVar3 != 0) && ((*(byte *)(&word_40C3E30 + iVar4 * 0x10) & 0x40) != 0)) {
    _printf(aSDNoValidDiskL,*(undefined4 *)(**(int **)(_od_drive + iVar2 + 0x14) + 0x20),iVar2 >> 5)
    ;
  }
  (&word_40C3E30)[iVar4 * 0x10] = (&word_40C3E30)[iVar4 * 0x10] & 0xfdff;
  return iVar3;
}
