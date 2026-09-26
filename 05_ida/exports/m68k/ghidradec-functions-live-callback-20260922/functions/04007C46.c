
byte _crfree(sword *param_1)

{
  sword sVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  
  sVar1 = *param_1;
  *param_1 = sVar1 + -1;
  if (sVar1 == 1) {
    _kfree(param_1,0x2a);
    bVar4 = _cractive == 0;
    bVar3 = SBORROW4(_cractive,1);
    _cractive = _cractive + -1;
    bVar2 = bVar4 << 4 | (_cractive < 0) << 3 | (_cractive == 0) << 2 | bVar3 << 1 | bVar4;
  }
  else {
    bVar2 = (sVar1 == 0) << 4 | ((sword)(sVar1 + -1) < 0) << 3 | SBORROW2(sVar1,1) << 1 | sVar1 == 0
    ;
  }
  return bVar2;
}

