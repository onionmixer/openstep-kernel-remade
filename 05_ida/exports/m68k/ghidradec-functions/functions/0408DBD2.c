
void sub_408DBD2(undefined4 param_1,undefined param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined uStack_5;
  
  uStack_5 = param_2;
  iVar3 = 0;
  do {
    iVar2 = _copywithin(&uStack_5,param_1,1);
    if (iVar2 != 0xe) {
      return;
    }
    bVar1 = iVar3 < 0x10;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  return;
}
