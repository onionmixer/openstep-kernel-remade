
byte _thread_go(int param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  
  if (*(int *)(param_1 + 0x13c) != 0) {
    _reset_timeout(param_1 + 0x110);
  }
  uVar1 = *(uint *)(param_1 + 0x48);
  uVar2 = (uVar1 & 0xf) - 1;
  cVar6 = 0xe < uVar2;
  cVar5 = SBORROW4(0xe,uVar2);
  cVar3 = (int)(0xe - uVar2) < 0;
  cVar4 = uVar2 == 0xe;
  bVar7 = cVar6;
  switch(uVar2) {
  case :
  case :
  case :
    *(uint *)(param_1 + 0x48) = uVar1 & 0xfffffffe | 4;
    *(undefined4 *)(param_1 + 0x40) = 0;
    cVar3 = param_1 < 0;
    cVar4 = param_1 == 0;
    cVar5 = '\0';
    bVar7 = 0;
    _thread_setrun(param_1,1);
    break;
  case :
  case :
  case :
  case :
  case :
    *(uint *)(param_1 + 0x48) = uVar1 & 0xfffffffe;
    *(undefined4 *)(param_1 + 0x40) = 0;
    cVar3 = '\0';
    cVar4 = '\x01';
    cVar5 = '\0';
    bVar7 = 0;
  }
  return cVar6 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar7;
}

