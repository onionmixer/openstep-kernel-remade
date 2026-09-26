
word _kybd_process(uint *param_1)

{
  byte bVar1;
  int iVar2;
  word wVar3;
  int iVar4;
  word wVar5;
  
  bVar1 = *(byte *)((int)param_1 + 2);
  if (((char)bVar1 < '\0') && ((*param_1 & 0xfffffff) >> 0x18 == 0)) {
    iVar2 = -((int)((uint)(byte)*param_1 << 0x18) >> 0x1f);
    iVar4 = 0;
    if ((bVar1 & 1) != 0) {
      iVar4 = 0xa2;
    }
    wVar5 = *(word *)(_ascii + (iVar4 + (-(int)-((bVar1 & 6) != 0) | ((byte)*param_1 & 0x7f) * 2)) *
                               2);
    wVar3 = 0;
    if ((bVar1 & 0x60) != 0) {
      wVar3 = 0x80;
    }
    switch(wVar5) {
    case :
    case :
    case :
    case :
      sub_40705D8(*param_1,iVar2);
      break;
    :
      wVar5 = wVar3 | wVar5;
      break;
    case :
    case :
      break;
    }
    wVar3 = 0x100;
    if (iVar2 == 0) {
      wVar3 = wVar5;
    }
  }
  else {
    wVar3 = 0x100;
  }
  return wVar3;
}

