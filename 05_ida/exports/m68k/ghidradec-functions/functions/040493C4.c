
undefined4 _thread_will_wait_with_timeout(int param_1,int param_2)

{
  uint uVar1;
  undefined2 extraout_D0u;
  undefined2 uVar2;
  uint uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  
  uVar1 = _hz * param_2 + 999;
  uVar3 = uVar1 / 1000;
  uVar2 = (undefined2)(uVar1 / 0xfa000);
  cVar4 = '\0';
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 1;
  if (uVar3 == 0) {
    cVar7 = '\0';
    bVar8 = 0;
    cVar5 = param_2 < 0;
    cVar6 = param_2 == 0;
    if (!(bool)cVar6) goto loc_4049416;
  }
  cVar5 = '\0';
  cVar6 = uVar3 == 0;
  cVar7 = '\0';
  bVar8 = 0;
  _set_timeout(param_1 + 0x110,uVar3);
  uVar2 = extraout_D0u;
loc_4049416:
  return CONCAT22(uVar2,(word)(byte)(cVar4 << 4 | cVar5 << 3 | cVar6 << 2 | cVar7 << 1 | bVar8));
}
