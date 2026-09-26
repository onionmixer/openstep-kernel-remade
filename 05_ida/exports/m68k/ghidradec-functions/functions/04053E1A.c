
byte _thread_doswapin(int param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  _stack_alloc(param_1,_thread_continue);
  cVar3 = '\0';
  uVar1 = *(uint *)(param_1 + 0x48);
  uVar2 = uVar1 & 0xfffffcff;
  *(uint *)(param_1 + 0x48) = uVar2;
  cVar4 = (int)uVar2 < 0;
  cVar6 = '\0';
  bVar7 = 0;
  cVar5 = (uVar1 & 4) == 0;
  if (!(bool)cVar5) {
    cVar4 = param_1 < 0;
    cVar5 = param_1 == 0;
    cVar6 = '\0';
    bVar7 = 0;
    _thread_setrun(param_1,1);
  }
  return cVar3 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar7;
}
