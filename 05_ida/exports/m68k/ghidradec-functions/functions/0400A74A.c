
uint _realitexpire(int param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  uint uStack_c;
  uint uStack_8;
  
  uVar2 = _psignal(param_1,0xe);
  if ((*(int *)(param_1 + 0x52) == 0) && (*(int *)(param_1 + 0x56) == 0)) {
    *(undefined4 *)(param_1 + 0x5e) = 0;
    *(undefined4 *)(param_1 + 0x5a) = 0;
  }
  else {
    _getthetime(&uStack_c);
    cVar7 = uStack_c - 10 < *(uint *)(param_1 + 0x5a);
    if ((int)*(uint *)(param_1 + 0x5a) < (int)(uStack_c - 10)) {
      *(uint *)(param_1 + 0x5a) = uStack_c;
      *(uint *)(param_1 + 0x5e) = uStack_8;
      uVar3 = _hzto(param_1 + 0x5a);
      cVar4 = param_1 < 0;
      cVar5 = param_1 == 0;
      cVar6 = '\0';
      bVar8 = 0;
      _timeout(_realitexpire,param_1,uVar3);
      uVar2 = (uint)(byte)(cVar7 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar8);
    }
    else {
      puVar1 = (uint *)(param_1 + 0x5a);
      do {
        _timevaladd(puVar1,param_1 + 0x52);
        uVar2 = *puVar1;
        cVar7 = uStack_c < uVar2;
        if ((int)uStack_c < (int)uVar2) break;
      } while ((uStack_c != uVar2) ||
              (cVar7 = *(uint *)(param_1 + 0x5e) < uStack_8,
              (int)*(uint *)(param_1 + 0x5e) <= (int)uStack_8));
      uVar3 = _hzto(puVar1);
      cVar4 = param_1 < 0;
      cVar5 = param_1 == 0;
      cVar6 = '\0';
      bVar8 = 0;
      _timeout(_realitexpire,param_1,uVar3);
      uVar2 = (uint)(byte)(cVar7 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar8);
    }
  }
  return uVar2;
}
