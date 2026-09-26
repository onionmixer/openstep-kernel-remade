
byte _calloutEntryDispatch(undefined4 *param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar4 = '\0';
  bVar5 = 0;
  cVar2 = (int)param_1[7] < 0;
  cVar3 = '\0';
  if (param_1[7] == 0) {
    param_1[3] = param_1[4];
    param_1[5] = 0;
    param_1[6] = 0;
    *param_1 = &dword_40B4DC0;
    param_1[1] = dword_40B4DC4;
    *(undefined4 **)param_1[1] = param_1;
    dword_40B4DC4 = param_1;
    cVar1 = 0xfffffffe < dword_40B4DD0;
    dword_40B4DD0 = dword_40B4DD0 + 1;
    param_1[7] = 1;
    cVar2 = '\0';
    cVar3 = '\0';
    cVar4 = '\0';
    bVar5 = 0;
    sub_4054786();
  }
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
