
byte _pmap_remove(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  bVar5 = 0;
  if (param_1 != 0) {
    cVar1 = '\0';
    cVar2 = param_1 < 0;
    cVar3 = param_1 == 0;
    cVar4 = '\0';
    bVar5 = 0;
    _pmap_remove_range(param_1,param_2,param_3);
    bVar5 = cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
  }
  return bVar5;
}

