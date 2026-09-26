
char sub_40110A0(int param_1)

{
  undefined (*pauVar1) [256];
  int iVar2;
  bool bVar3;
  
  while( true ) {
    pauVar1 = off_40AE690;
    iVar2 = _b_to_q(unk_40B3344,off_40AE690[-0x40b34] + 0xbc,param_1 + 0x18);
    if (iVar2 == 0) {
      _ptsstart(param_1);
    }
    bVar3 = off_40AE690 < pauVar1;
    iVar2 = (int)off_40AE690 - (int)pauVar1;
    if (iVar2 == 0) break;
    _bcopy(pauVar1,unk_40B3344,iVar2);
    off_40AE690 = (undefined (*) [256])(unk_40B3344 + iVar2);
  }
  off_40AE690 = &unk_40B3344;
  return bVar3 << 4;
}

