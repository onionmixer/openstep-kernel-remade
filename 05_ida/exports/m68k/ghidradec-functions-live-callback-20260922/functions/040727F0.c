
byte _np_setmask(int *param_1,byte param_2)

{
  int iVar1;
  uint in_D0;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  *(byte *)(param_1 + 0x47) = param_2 | *(byte *)(param_1 + 0x47);
  cVar2 = (in_D0 >> 8 & 1) != 0;
  iVar1 = *param_1;
  cVar3 = iVar1 < 0;
  cVar4 = iVar1 == 0;
  cVar5 = '\0';
  bVar6 = 0;
  _np_send(iVar1,0xc5,(*(byte *)(param_1 + 0x47) & 0x3f) << 0x18);
  return cVar2 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6;
}

