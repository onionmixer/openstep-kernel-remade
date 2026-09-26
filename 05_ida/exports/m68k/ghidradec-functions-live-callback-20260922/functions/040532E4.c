
undefined4 _thread_release(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 extraout_D0u;
  undefined4 in_D0;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  
  uVar3 = (undefined2)((uint)in_D0 >> 0x10);
  uVar1 = *(uint *)(param_1 + 0x3c);
  *(uint *)(param_1 + 0x3c) = uVar1 - 1;
  cVar7 = 1 < uVar1;
  cVar6 = SBORROW4(1,uVar1);
  cVar4 = (int)(1 - uVar1) < 0;
  cVar5 = '\0';
  bVar8 = cVar7;
  if (uVar1 == 1) {
    uVar1 = *(uint *)(param_1 + 0x48);
    uVar2 = uVar1 & 0xffffffed;
    *(uint *)(param_1 + 0x48) = uVar2;
    cVar6 = '\0';
    bVar8 = 0;
    uVar3 = 0;
    cVar4 = '\0';
    cVar5 = '\0';
    if ((uVar1 & 5) == 0) {
      *(uint *)(param_1 + 0x48) = uVar2 | 4;
      cVar4 = param_1 < 0;
      cVar5 = param_1 == 0;
      cVar6 = '\0';
      bVar8 = 0;
      _thread_setrun(param_1,1);
      uVar3 = extraout_D0u;
    }
  }
  return CONCAT22(uVar3,(word)(byte)(cVar7 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar8));
}

