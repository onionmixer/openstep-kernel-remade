
int _strlen(uint *param_1)

{
  char cVar1;
  word wVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)param_1 & 3;
  iVar3 = 0;
  if (uVar4 != 0) {
    if (uVar4 != 2) {
      cVar1 = *(char *)param_1;
      param_1 = (uint *)((int)param_1 + 1);
      if (uVar4 == 3) {
        if (cVar1 == '\0') {
          return 0;
        }
        iVar3 = 1;
        goto loc_F00074B8;
      }
      if (cVar1 == '\0') {
        return 0;
      }
      iVar3 = 1;
    }
    wVar2 = *(word *)param_1;
    param_1 = (uint *)((int)param_1 + 2);
    if (wVar2 >> 8 == 0) {
      return iVar3;
    }
    if ((wVar2 & 0xff) == 0) {
      return iVar3 + 1;
    }
    iVar3 = iVar3 + 2;
  }
loc_F00074B8:
  while( true ) {
    while( true ) {
      uVar4 = *param_1;
      param_1 = param_1 + 1;
      if (((uVar4 + 0x7efefeff ^ uVar4) & 0x81010100) != 0x81010100) break;
      iVar3 = iVar3 + 4;
    }
    if ((uVar4 & 0xff000000) == 0) {
      return iVar3;
    }
    if ((uVar4 & 0xff0000) == 0) {
      return iVar3 + 1;
    }
    if ((uVar4 & 0xff00) == 0) break;
    if ((uVar4 & 0xff) == 0) {
      return iVar3 + 3;
    }
    iVar3 = iVar3 + 4;
  }
  return iVar3 + 2;
}
