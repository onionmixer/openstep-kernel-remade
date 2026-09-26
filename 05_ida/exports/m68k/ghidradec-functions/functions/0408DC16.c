
bool sub_408DC16(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined uStack_5;
  
  iVar2 = 0;
  do {
    iVar1 = _copywithin(param_1,&uStack_5,1);
    if (iVar1 != 0xe) break;
    _delay(1000);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  return iVar2 != 10;
}
