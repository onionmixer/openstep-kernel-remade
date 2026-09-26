
void sub_40502A6(undefined4 param_1)

{
  int iVar1;
  undefined2 uStack_e;
  byte bStack_c;
  byte bStack_b;
  
  dword_40C25A2 = param_1;
  do {
    while (dword_40B3FBA == 0) {
      sub_4050186();
    }
    _bcopy(unk_40B39C8 + dword_40B3FB2,&bStack_c,8);
    if ((bStack_c & 1) == 0) {
      if (byte_40B39C6 - 1 == (uint)bStack_b) {
        _kdp_en_send_pkt(unk_40B3FBE + dword_40B45A8,dword_40B45AC);
      }
      else if (byte_40B39C6 == bStack_b) {
        iVar1 = _kdp_packet(unk_40B39C8 + dword_40B3FB2,&unk_40B3FB6,&uStack_e);
        if (iVar1 != 0) {
          sub_404FD9A(uStack_e);
        }
      }
      else {
        _safe_prf(aKdpBadSequence,(uint)bStack_b,(uint)byte_40B39C6);
      }
    }
    dword_40B3FBA = 0;
  } while (dword_40C25A6 != 0);
  return;
}

