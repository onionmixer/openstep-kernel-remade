
undefined sub_408DB8A(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined uStack_5;
  
  iVar3 = 0;
  do {
    iVar2 = _copywithin(param_1,&uStack_5,1);
    if (iVar2 != 0xe) {
      return uStack_5;
    }
    bVar1 = iVar3 < 0x10;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return 0;
}

