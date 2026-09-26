/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00161f4c */

undefined4 _kdp_packet(void *param_1,uint *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  byte local_608;
  undefined1 local_607;
  ushort local_606;
  undefined4 local_604;
  
  uVar2 = *param_2;
  _bcopy(param_1,&local_608,0x604);
  if ((uVar2 < 8) || (local_606 != uVar2)) {
    _safe_prf(s_kdp_packet_bad_len_pkt__d_hdr__d_001df2b0,uVar2,local_606);
    uVar1 = 0;
  }
  else if ((char)local_608 < '\0') {
    _safe_prf(s_kdp_packet_reply_recvd_req__x_se_001df2d2,local_608 & 0x7f,local_607);
    uVar1 = 0;
  }
  else {
    uVar2 = local_608 & 0x7f;
    if (uVar2 < 0xf) {
      uVar1 = (*(code *)(&PTR_FUN_001df274)[uVar2])(&local_608,param_2,param_3);
      _bcopy(&local_608,param_1,*param_2);
    }
    else {
      _safe_prf(s_kdp_packet_bad_request__x_len__d_001df2f8,uVar2,(uint)local_606,local_607,
                local_604);
      uVar1 = 0;
    }
  }
  return uVar1;
}

