
undefined4 _kdp_packet(undefined4 param_1,uint *param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  byte bStack_608;
  undefined uStack_607;
  word wStack_606;
  undefined4 uStack_604;
  
  uVar1 = *param_2;
  _bcopy(param_1,&bStack_608,0x604);
  if ((uVar1 < 8) || (uVar1 != wStack_606)) {
    _safe_prf(aKdpPacketBadLe,uVar1,wStack_606);
  }
  else if ((bStack_608 & 1) == 0) {
    uVar1 = (uint)(bStack_608 >> 1);
    if (uVar1 < 0xf) {
      uVar2 = (**(code **)(unk_40AF948 + uVar1 * 4))(&bStack_608,param_2,param_3);
      _bcopy(&bStack_608,param_1,*param_2);
      return uVar2;
    }
    _safe_prf(aKdpPacketBadRe,uVar1,(uint)wStack_606,uStack_607,uStack_604);
  }
  else {
    _safe_prf(aKdpPacketReply,bStack_608 >> 1,uStack_607);
  }
  return 0;
}

