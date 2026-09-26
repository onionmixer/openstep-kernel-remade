
byte _thread_go_and_switch(int param_1,int param_2)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  if (*(int *)(param_2 + 0x13c) != 0) {
    _reset_timeout(param_2 + 0x110);
  }
  uVar1 = *(uint *)(param_2 + 0x48);
  cVar5 = 0xe < (uVar1 & 0xf) - 1;
  switch(uVar1 & 0xf) {
  case :
  case :
  case :
    *(uint *)(param_2 + 0x48) = uVar1 & 0xfffffffe | 4;
    *(undefined4 *)(param_2 + 0x40) = 0;
    uVar1 = *(uint *)(param_2 + 0x178);
    if ((*(int *)(uVar1 + 0x110) < 1) &&
       (cVar5 = uVar1 < *(uint *)(_active_threads + 0x178),
       uVar1 == *(uint *)(_active_threads + 0x178))) {
      cVar2 = param_1 < 0;
      cVar3 = param_1 == 0;
      cVar4 = '\0';
      bVar6 = 0;
      _thread_run(param_1,param_2);
      return cVar5 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar6;
    }
    _thread_setrun(param_2,1);
    break;
  case :
  case :
  case :
  case :
  case :
    *(uint *)(param_2 + 0x48) = uVar1 & 0xfffffffe;
    *(undefined4 *)(param_2 + 0x40) = 0;
  }
  cVar4 = '\0';
  bVar6 = 0;
  cVar2 = param_1 < 0;
  cVar3 = param_1 == 0;
  if (!(bool)cVar3) {
    cVar5 = '\0';
    cVar2 = param_1 < 0;
    cVar3 = param_1 == 0;
    cVar4 = '\0';
    bVar6 = 0;
    _call_continuation(param_1);
  }
  return cVar5 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar6;
}
