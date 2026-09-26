
uint _fc_motor_on(int *param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  
  iVar1 = *param_1;
  bVar4 = (byte)(0x10 << (*(byte *)(param_1[7] + 0x58) & 0x3f));
  bVar2 = bVar4 & *(byte *)(iVar1 + 2);
  uVar3 = (uint)bVar2;
  if (bVar2 == 0) {
    *(byte *)(iVar1 + 2) = bVar4 | *(byte *)(iVar1 + 2);
    _fc_flags_bclr(param_1,0x40);
    uVar3 = sub_406B38A(param_1,500000,1000000);
  }
  return uVar3;
}

