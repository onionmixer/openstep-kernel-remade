
uint * _arptnew(uint param_1,uint *param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  byte *pbVar6;
  
  uVar4 = 0xffffffff;
  puVar5 = (uint *)0x0;
  if (dword_40AE934 != 0) {
    dword_40AE934 = 0;
    _timeout(_arptimer,0,_hz);
  }
  iVar1 = (*param_2 % 0x13) * 0xb4;
  puVar2 = (uint *)(_arptab + iVar1);
  iVar3 = 0;
  pbVar6 = &unk_40B6E62 + iVar1;
  do {
    if (*(byte *)((int)puVar2 + 0xb) == 0) goto loc_401E7C2;
    if (((*(byte *)((int)puVar2 + 0xb) & 4) == 0) &&
       ((puVar5 == (uint *)0x0 || ((int)uVar4 < (int)(uint)*pbVar6)))) {
      uVar4 = (uint)*pbVar6;
      puVar5 = puVar2;
    }
    iVar3 = iVar3 + 1;
    pbVar6 = pbVar6 + 0x14;
    puVar2 = puVar2 + 5;
  } while (iVar3 < 9);
  if (puVar5 == (uint *)0x0) {
    puVar2 = (uint *)0x0;
  }
  else {
    _arptfree(puVar5);
    puVar2 = puVar5;
loc_401E7C2:
    *puVar2 = *param_2;
    *(undefined *)((int)puVar2 + 0xb) = 1;
    puVar2[4] = param_1;
  }
  return puVar2;
}

