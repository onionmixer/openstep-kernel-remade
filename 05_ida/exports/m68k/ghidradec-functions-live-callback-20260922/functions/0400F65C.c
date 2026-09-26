
byte _ttyretype(int *param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  undefined4 uStack_8;
  
  iVar1 = *param_1;
  if (*(char *)(iVar1 + 0x56) != -1) {
    _ttyecho(*(char *)(iVar1 + 0x56),param_1);
  }
  _ttyoutput(10,iVar1);
  iVar3 = *(int *)(iVar1 + 0x10) + -1;
  while( true ) {
    iVar3 = _nextc3(iVar1 + 0xc,iVar3,&uStack_8);
    if (iVar3 == 0) break;
    _ttyecho(uStack_8,param_1);
  }
  cVar4 = *(int *)(iVar1 + 4) == 0;
  iVar3 = *(int *)(iVar1 + 4) + -1;
  while( true ) {
    iVar3 = _nextc3(iVar1,iVar3,&uStack_8);
    if (iVar3 == 0) break;
    _ttyecho(uStack_8,param_1);
  }
  bVar2 = *(byte *)(iVar1 + 0x3f);
  *(byte *)(iVar1 + 0x3f) = bVar2 & 0xfb;
  *(undefined *)(iVar1 + 0x49) = *(undefined *)(iVar1 + 3);
  *(undefined *)(iVar1 + 0x4a) = 0;
  return cVar4 << 4 | ((bVar2 & 4) == 0) << 2;
}

