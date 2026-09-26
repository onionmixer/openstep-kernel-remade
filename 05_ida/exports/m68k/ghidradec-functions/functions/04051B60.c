
byte _thread_depress_timeout(int param_1)

{
  int iVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  cVar2 = '\0';
  iVar1 = *(int *)(param_1 + 0x60);
  cVar3 = iVar1 < 0;
  cVar4 = iVar1 == 0;
  cVar5 = '\0';
  bVar6 = 0;
  if (!(bool)cVar3) {
    *(int *)(param_1 + 0x4c) = iVar1;
    *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
    cVar3 = param_1 < 0;
    cVar4 = param_1 == 0;
    cVar5 = '\0';
    bVar6 = 0;
    _compute_priority(param_1,0);
  }
  return cVar2 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6;
}
