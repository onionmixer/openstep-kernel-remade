
undefined4 sub_408229E(undefined4 param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  word extraout_D0u;
  word wVar5;
  word extraout_D0u_00;
  byte bVar6;
  int iVar7;
  char cVar8;
  
  bVar6 = 1;
  if (param_4 == 0) {
    bVar6 = 2;
  }
  bVar6 = *(byte *)(_slot_id_bmap + 0x2008000) & 0x18 | bVar6;
  iVar3 = (&unk_40C6DF4)[param_2];
  iVar2 = *(int *)(iVar3 + 0x3e);
  iVar7 = *(int *)(iVar2 + 0x2c);
  if (iVar7 == iVar3 + 0x3e) {
    *(int *)(iVar3 + 0x42) = iVar7;
  }
  else {
    *(int *)(iVar7 + 0x30) = iVar3 + 0x3e;
  }
  *(int *)(iVar3 + 0x3e) = iVar7;
  dword_40C6D1C = param_4;
  *(undefined4 *)(iVar2 + 0x18) = 4;
  if ((param_3 - 1 < 2) && (param_4 == 0)) {
    iVar7 = 10;
    bVar4 = *(byte *)(_slot_id_bmap + 0x2008002);
    while ((bVar4 & 4) == 0) {
      _delay(1);
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) goto loc_4082358;
      bVar4 = *(byte *)(_slot_id_bmap + 0x2008002);
    }
    if (iVar7 == 0) {
loc_4082358:
      _printf(aDspDmaTimedOut);
    }
    if (param_3 == 1) {
      *(undefined *)(_slot_id_bmap + 0x2008005) = 0;
      *(undefined *)(_slot_id_bmap + 0x2008006) = 0;
    }
    else if (param_3 == 2) {
      *(undefined *)(_slot_id_bmap + 0x2008005) = 0;
    }
  }
  sub_40826E6(1);
  _dma_enqueue(&_dsp_var,iVar2 + 0xc);
  wVar5 = extraout_D0u;
  if (param_3 == 2) {
    *(byte *)(_slot_id_bmap + 0x2008000) = bVar6 | 0x40;
    cVar8 = '\0';
  }
  else if ((int)param_3 < 3) {
    cVar8 = 1 < param_3;
    if (param_3 == 1) {
      *(byte *)(_slot_id_bmap + 0x2008000) = bVar6 | 0x60;
    }
  }
  else if (param_3 == 3) {
    uVar1 = *_scr2;
    *_scr2 = uVar1 & 0xdfffffff;
    wVar5 = (word)(uVar1 >> 0x10) & 0xdfff;
    *(byte *)(_slot_id_bmap + 0x2008000) = bVar6 | 0x20;
    cVar8 = '\0';
  }
  else {
    cVar8 = 4 < param_3;
    if (param_3 == 4) {
      uVar1 = *_scr2;
      *_scr2 = uVar1 | 0x20000000;
      wVar5 = (word)(uVar1 >> 0x10) | 0x2000;
      *(byte *)(_slot_id_bmap + 0x2008000) = bVar6 | 0x20;
      cVar8 = _dma_chip < 0x139;
      if (_dma_chip == 0x139) {
        _printf(aAttemptToUseBr);
        wVar5 = extraout_D0u_00;
      }
    }
  }
  bVar6 = *(byte *)(_slot_id_bmap + 0x2008000) | 0x10;
  *(byte *)(_slot_id_bmap + 0x2008000) = bVar6;
  return CONCAT22(wVar5,(word)(byte)(cVar8 << 4 | ((char)bVar6 < '\0') << 3 | (bVar6 == 0) << 2));
}

