
undefined4 _thread_depress_priority(int param_1,int param_2)

{
  uint uVar1;
  undefined2 extraout_D0u;
  undefined2 extraout_D0u_00;
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
  if (*(int *)(param_1 + 0x16c) != 0) {
    _reset_timeout(param_1 + 0x140);
    uVar2 = extraout_D0u;
  }
  *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  cVar7 = '\0';
  bVar8 = 0;
  cVar5 = '\0';
  cVar6 = uVar3 == 0;
  if (!(bool)cVar6) {
    cVar5 = '\0';
    cVar6 = uVar3 == 0;
    cVar7 = '\0';
    bVar8 = 0;
    _set_timeout(param_1 + 0x140,uVar3);
    uVar2 = extraout_D0u_00;
  }
  return CONCAT22(uVar2,(word)(byte)(cVar4 << 4 | cVar5 << 3 | cVar6 << 2 | cVar7 << 1 | bVar8));
}
