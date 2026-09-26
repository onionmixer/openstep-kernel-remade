
int _vidProbeForFB(void)

{
  int iVar1;
  sword sVar2;
  
  sVar2 = 2;
  do {
    iVar1 = (**(code **)(unk_40B228C + sVar2 * 0x2c))();
    if (iVar1 == 1) {
      dword_40B2282 = (int)sVar2;
      (**(code **)(unk_40B228C + sVar2 * 0x2c + 8))();
      return (int)sVar2;
    }
    sVar2 = sVar2 + -1;
  } while (sVar2 != -1);
  return -1;
}
