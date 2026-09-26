
void _vattr_null(undefined *param_1)

{
  word wVar1;
  int iVar2;
  sword sVar3;
  undefined *puVar4;
  
  iVar2 = 0x39;
  do {
    do {
      puVar4 = param_1 + 1;
      *param_1 = 0xff;
      wVar1 = (word)((uint)iVar2 >> 0x10);
      sVar3 = (sword)iVar2 + -1;
      iVar2 = CONCAT22(wVar1,sVar3);
      param_1 = puVar4;
    } while (sVar3 != -1);
    iVar2 = (uint)wVar1 * 0x10000 + -1;
  } while (wVar1 != 0);
  return;
}
