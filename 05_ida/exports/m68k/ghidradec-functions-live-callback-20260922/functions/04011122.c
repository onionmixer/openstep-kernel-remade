
uint _ptsputc(byte param_1,char param_2)

{
  int iVar1;
  undefined (*pauVar2) [256];
  int iVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  char cStack_6;
  undefined uStack_5;
  
  iVar1 = *(int *)((int)&dword_40B318A + (sword)(word)param_1 * 0xe);
  cStack_6 = param_2;
  uVar4 = 1;
  if (param_2 == '\n') {
    uStack_5 = 0xd;
    uVar4 = 2;
  }
  iVar3 = _curipl();
  if (iVar3 < 1) {
    uVar4 = _b_to_q(&cStack_6,uVar4,iVar1 + 0x18);
    if (uVar4 == 0) {
      uVar4 = _ptsstart(iVar1);
    }
  }
  else {
    if (off_40AE690[-0x40b34] == (undefined *)0xffffff44) {
      _callout_dispatch(0,sub_40110A0,iVar1);
    }
    else if (off_40AE690[-0x40b34] == (undefined *)0x44) {
      return (uint)(byte)(((int)(off_40AE690[-0x40b35] + 0xbc) < 0) << 3 | 4);
    }
    (*off_40AE690)[0] = cStack_6;
    pauVar2 = (undefined (*) [256])(*off_40AE690 + 1);
    bVar8 = 2 < uVar4;
    bVar7 = SBORROW4(2,uVar4);
    bVar5 = (int)(2 - uVar4) < 0;
    bVar6 = false;
    if (uVar4 == 2) {
      bVar8 = pauVar2 < unk_40B3444;
      bVar7 = SBORROW4((int)pauVar2,0x40b3444);
      bVar5 = (int)(off_40AE690[-0x40b35] + 0xbd) < 0;
      bVar6 = pauVar2 == (undefined (*) [256])unk_40B3444;
      if (!bVar6) {
        off_40AE690 = pauVar2;
        (*pauVar2)[0] = uStack_5;
        bVar8 = (undefined (*) [256])0xfffffffe < off_40AE690;
        bVar7 = SCARRY4((int)off_40AE690,1);
        pauVar2 = (undefined (*) [256])(*off_40AE690 + 1);
        bVar5 = (int)pauVar2 < 0;
        bVar6 = pauVar2 == (undefined (*) [256])0x0;
      }
    }
    off_40AE690 = pauVar2;
    uVar4 = (uint)(byte)(bVar8 << 4 | bVar5 << 3 | bVar6 << 2 | bVar7 << 1 | bVar8);
  }
  return uVar4;
}

