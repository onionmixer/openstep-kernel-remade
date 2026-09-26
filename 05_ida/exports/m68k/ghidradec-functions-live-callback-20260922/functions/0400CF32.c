
byte _ttrstrt(int param_1)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&aTtrstrt);
  }
  *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) & 0xfffffffe;
  cVar1 = ((uint)(*(char *)(param_1 + 0x45) * 3) >> 0x1c & 1) != 0;
  cVar2 = param_1 < 0;
  cVar3 = param_1 == 0;
  cVar4 = '\0';
  bVar5 = 0;
  (**(code **)(DAT_40ae4cc + *(char *)(param_1 + 0x45) * 0x30))(param_1);
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}

