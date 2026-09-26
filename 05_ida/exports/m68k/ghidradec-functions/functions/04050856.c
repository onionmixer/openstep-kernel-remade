
byte _clear_wait(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  if ((param_3 != 0) && ((*(byte *)((int)param_1 + 0x4b) & 8) != 0)) {
    return (param_3 < 0) << 3;
  }
  uVar2 = param_1[0xe];
  if (uVar2 != 0) {
    cVar6 = uVar2 < (uint)param_1[0xe];
    if (uVar2 == param_1[0xe]) {
      *(int *)(*param_1 + 4) = param_1[1];
      *(int *)param_1[1] = *param_1;
      param_1[0xe] = 0;
      uVar2 = 0;
    }
    cVar5 = '\0';
    cVar3 = (int)uVar2 < 0;
    cVar4 = '\0';
    bVar7 = 0;
    if (uVar2 != 0) goto loc_4050942;
  }
  uVar2 = param_1[0x12];
  if (param_1[0x4f] != 0) {
    _reset_timeout(param_1 + 0x44);
  }
  uVar1 = (uVar2 & 0xf) - 1;
  cVar6 = 0xe < uVar1;
  cVar5 = SBORROW4(0xe,uVar1);
  cVar3 = (int)(0xe - uVar1) < 0;
  cVar4 = uVar1 == 0xe;
  bVar7 = cVar6;
  switch(uVar1) {
  case :
  case :
  case :
    param_1[0x12] = uVar2 & 0xfffffffe | 4;
    param_1[0x10] = param_2;
    cVar3 = (int)param_1 < 0;
    cVar4 = param_1 == (int *)0x0;
    cVar5 = '\0';
    bVar7 = 0;
    _thread_setrun(param_1,1);
    break;
  case :
  case :
  case :
  case :
  case :
    param_1[0x12] = uVar2 & 0xfffffffe;
    param_1[0x10] = param_2;
    cVar3 = param_2 < 0;
    cVar4 = param_2 == 0;
    cVar5 = '\0';
    bVar7 = 0;
  }
loc_4050942:
  return cVar6 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar7;
}
