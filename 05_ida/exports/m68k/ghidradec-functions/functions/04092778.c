
int _isbad(int param_1,int param_2,int param_3,int param_4)

{
  sword sVar1;
  int iVar2;
  int iVar3;
  
  param_4 = param_4 + param_3 * 0x100 + param_2 * 0x10000;
  iVar3 = 0;
  do {
    sVar1 = *(sword *)(param_1 + 8 + iVar3 * 4);
    iVar2 = CONCAT22(sVar1,*(undefined2 *)(param_1 + 10 + iVar3 * 4));
    if (iVar2 == param_4) {
      return iVar3;
    }
  } while (((iVar2 <= param_4) && (-1 < sVar1)) && (iVar3 = iVar3 + 1, iVar3 < 0x7e));
  return -1;
}
