
void _en_send(undefined2 param_1,undefined4 *param_2,int param_3)

{
  word wVar1;
  
  *param_2 = _en_pkt_hdr;
  param_2[1] = dword_40C8F0C;
  param_2[2] = dword_40C8F10;
  *(undefined2 *)(param_2 + 3) = word_40C8F14;
  _bcopy(0x40c8f0e,param_2,6);
  _bcopy(&_en_pkt_hdr,(int)param_2 + 6,6);
  *(undefined4 *)((int)param_2 + 0xe) = dword_40C8F16;
  *(undefined4 *)((int)param_2 + 0x12) = dword_40C8F1A;
  *(undefined4 *)((int)param_2 + 0x16) = dword_40C8F1E;
  *(undefined4 *)((int)param_2 + 0x1a) = dword_40C8F22;
  *(undefined4 *)((int)param_2 + 0x1e) = dword_40C8F26;
  *(undefined4 *)((int)param_2 + 0x1a) = dword_40C8F26;
  *(undefined4 *)((int)param_2 + 0x1e) = dword_40C8F22;
  *(sword *)(param_2 + 4) = (sword)param_3 + -0xe;
  *(undefined2 *)(param_2 + 6) = 0;
  wVar1 = _checksum_16((int)param_2 + 0xe,10);
  *(word *)(param_2 + 6) = ~wVar1;
  *(undefined2 *)(param_2 + 9) = param_1;
  *(undefined2 *)((int)param_2 + 0x22) = word_40C8F2C;
  *(sword *)((int)param_2 + 0x26) = (sword)param_3 + -0x22;
  *(undefined2 *)(param_2 + 10) = 0;
  _en_xmit(param_2,param_3 + 0xe);
  return;
}
