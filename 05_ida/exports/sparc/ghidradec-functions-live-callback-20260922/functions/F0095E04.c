
void _swift_vac_flush(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  iVar2 = param_1 - (param_1 & 0xf);
  uVar3 = param_2 + (param_1 & 0xf);
  do {
    bVar4 = 0xf < uVar3;
    uVar3 = uVar3 - 0x10;
    iVar1 = segment(0x10);
    *(undefined4 *)(iVar2 + iVar1) = 0;
    iVar2 = iVar2 + 0x10;
  } while (bVar4);
  return;
}

