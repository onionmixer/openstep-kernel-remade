
int _snd_dspcmd_def_dmasize(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)*(word *)((&unk_40C6DF4)[param_1] + 0x4e);
  bVar1 = *(byte *)((&unk_40C6DF4)[param_1] + 0x53);
  if (bVar1 == 5) {
    iVar2 = uVar3 * 2;
  }
  else {
    iVar2 = uVar3 * bVar1;
  }
  return iVar2;
}

