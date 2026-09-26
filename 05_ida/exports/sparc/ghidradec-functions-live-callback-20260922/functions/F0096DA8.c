
int _movtuc(int param_1,byte *param_2,int param_3,int param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_1) {
    bVar1 = *param_2;
    while( true ) {
      cVar2 = *(char *)(param_4 + (uint)bVar1);
      *(char *)(param_3 + iVar3) = cVar2;
      if (cVar2 == '\0') {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      if (param_1 <= iVar3) break;
      bVar1 = param_2[iVar3];
    }
  }
  return iVar3;
}

