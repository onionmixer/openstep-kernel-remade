
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sub_4050186(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  byte abStack_34 [20];
  undefined auStack_20 [9];
  char cStack_17;
  undefined4 uStack_14;
  undefined4 uStack_10;
  sword sStack_a;
  word wStack_8;
  
  if (dword_40B3FBA != 0) {
    _kdp_panic(aKdpPoll);
  }
  dword_40B3FB2 = 0;
  _kdp_en_recv_pkt(unk_40B39C8,&unk_40B3FB6,3);
  iVar3 = dword_40B3FB2;
  iVar2 = dword_40B3FB2;
  if ((_unk_40B3FB6 != 0) && (0x29 < _unk_40B3FB6)) {
    puVar1 = unk_40B39C8 + dword_40B3FB2;
    iVar2 = dword_40B3FB2 + 0xe;
    if (*(sword *)(unk_40B39C8 + dword_40B3FB2 + 0xc) == 0x800) {
      iVar2 = dword_40B3FB2 + 0x40b39d6;
      dword_40B3FB2 = dword_40B3FB2 + 0xe;
      _bcopy(iVar2,auStack_20,0x1c);
      _bcopy(unk_40B39C8 + dword_40B3FB2,abStack_34,0x14);
      dword_40B3FB2 = dword_40B3FB2 + 0x1c;
      iVar2 = dword_40B3FB2;
      if (((cStack_17 == '\x11') && ((abStack_34[0] & 0xf) < 6)) && (sStack_a == 0x473)) {
        if (dword_40C259E == 0) {
          _bcopy(puVar1,&unk_40C25B8,6);
          _adr = uStack_10;
          _bcopy(iVar3 + 0x40b39ce,&unk_40C25C2,6);
          dword_40C25BE = uStack_14;
        }
        _unk_40B3FB6 = wStack_8 - 8;
        dword_40B3FBA = 1;
        iVar2 = dword_40B3FB2;
      }
    }
  }
  dword_40B3FB2 = iVar2;
  return;
}
