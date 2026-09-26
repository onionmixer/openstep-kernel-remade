
byte _calloutRemove(int param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  cVar2 = '\0';
  iVar1 = sub_4054012(param_1,param_2,0);
  cVar5 = '\0';
  bVar6 = 0;
  cVar3 = iVar1 < 0;
  cVar4 = '\0';
  if (iVar1 == 0) {
    cVar3 = param_1 < 0;
    cVar4 = param_1 == 0;
    cVar5 = '\0';
    bVar6 = 0;
    sub_405409E(param_1,param_2,0);
  }
  return cVar2 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6;
}

