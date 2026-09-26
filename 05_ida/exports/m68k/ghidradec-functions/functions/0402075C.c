
undefined4 _icmp_sendMaskPacket(int param_1,char param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 uStack_14;
  undefined2 uStack_12;
  undefined4 uStack_10;
  
  iVar6 = 0;
  if (((*(word *)(param_1 + 0xc) & 1) == 0) || ((*(word *)(param_1 + 0xc) & 8) != 0)) {
    return 0;
  }
  iVar2 = _ifptoia(param_1);
  if (iVar2 == 0) {
    uVar5 = 0x33;
  }
  else {
    iVar6 = _m_get(1,2);
    if (iVar6 == 0) {
      uVar5 = 0x37;
    }
    else {
      *(undefined2 *)(iVar6 + 8) = 0x20;
      *(undefined4 *)(iVar6 + 4) = 0x5c;
      _bzero(iVar6 + 0x5c,(int)*(sword *)(iVar6 + 8));
      *(sword *)(iVar6 + 8) = *(sword *)(iVar6 + 8) + -0x14;
      iVar1 = *(int *)(iVar6 + 4) + 0x14;
      *(int *)(iVar6 + 4) = iVar1;
      puVar4 = (undefined *)(iVar6 + iVar1);
      if (param_2 == '\x12') {
        *puVar4 = 0x12;
        iVar1 = *(int *)(iVar2 + 0x34);
        *(int *)(puVar4 + 8) = iVar1;
        if (iVar1 == 0) {
          uVar5 = 0x16;
          goto loc_402090A;
        }
      }
      else {
        *puVar4 = 0x11;
      }
      puVar4[1] = 0;
      *(undefined2 *)(puVar4 + 2) = 0;
      *(undefined4 *)(puVar4 + 4) = 0;
      uVar3 = _in_cksum(iVar6,0xc);
      *(undefined2 *)(puVar4 + 2) = uVar3;
      *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + -0x14;
      *(sword *)(iVar6 + 8) = *(sword *)(iVar6 + 8) + 0x14;
      puVar4 = (undefined *)(*(int *)(iVar6 + 4) + iVar6);
      *puVar4 = 0x45;
      *(sword *)(puVar4 + 4) = _ip_id;
      _ip_id = _ip_id + 1;
      puVar4[8] = 0xff;
      puVar4[9] = 1;
      *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)(iVar2 + 4);
      *(undefined4 *)(puVar4 + 0x10) = 0xffffffff;
      *(undefined2 *)(puVar4 + 2) = 0x20;
      *(undefined2 *)(puVar4 + 10) = 0;
      uVar3 = _in_cksum(iVar6,0x14);
      *(undefined2 *)(puVar4 + 10) = uVar3;
      uStack_14 = 2;
      uStack_12 = 0;
      uStack_10 = 0xffffffff;
      if (0 < param_3) {
        _timeout(_wakeup,iVar2 + 0x34,_hz * param_3);
        _sleep(iVar2 + 0x34,0x19);
      }
      uVar5 = _if_output_mbuf(param_1,iVar6,&uStack_14);
      iVar6 = 0;
      if (param_2 == '\x11') {
        _timeout(_wakeup,iVar2 + 0x34,_hz);
        _sleep(iVar2 + 0x34,0x19);
      }
    }
  }
loc_402090A:
  if (iVar6 != 0) {
    _m_freem(iVar6);
  }
  return uVar5;
}
