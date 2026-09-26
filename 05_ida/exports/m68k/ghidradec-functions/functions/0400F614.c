
void _ttyrubo(int param_1,int param_2)

{
  word wVar1;
  sword sVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)&DAT_40a63bf;
  if ((*(byte *)(param_1 + 0x3b) & 4) != 0) {
    puVar3 = &DAT_40a63bb;
  }
  param_2 = param_2 + -1;
  if (-1 < param_2) {
    do {
      do {
        _ttyoutstr(puVar3,param_1);
        wVar1 = (word)((uint)param_2 >> 0x10);
        sVar2 = (sword)param_2 + -1;
        param_2 = CONCAT22(wVar1,sVar2);
      } while (sVar2 != -1);
      param_2 = (uint)wVar1 * 0x10000 + -1;
    } while (wVar1 != 0);
  }
  return;
}
