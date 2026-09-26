
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte _tcp_slowtimo(void)

{
  undefined4 *puVar1;
  int iVar2;
  sword sVar3;
  byte bVar4;
  undefined4 *puVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  
  __tcp_maxidle = _tcp_keepintvl << 3;
  puVar1 = _tcb;
  if (_tcb == (undefined4 *)0x0) {
    bVar4 = ((_tcp_keepintvl >> 0x1d & 1) != 0) * '\x10' | 4;
  }
  else {
joined_r0x04024b92:
    puVar5 = puVar1;
    if ((undefined4 **)puVar5 != &_tcb) {
      puVar1 = (undefined4 *)*puVar5;
      iVar2 = puVar5[7];
      if (iVar2 != 0) {
        iVar6 = 0;
        do {
          sVar3 = *(sword *)(iVar2 + 10 + iVar6 * 2);
          if (((sVar3 != 0) && (*(sword *)(iVar2 + 10 + iVar6 * 2) = sVar3 + -1, sVar3 == 1)) &&
             (_tcp_usrreq(*(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x18),0x13,0,iVar6,0),
             puVar5 != (undefined4 *)puVar1[1])) goto joined_r0x04024b92;
          iVar6 = iVar6 + 1;
        } while (iVar6 < 4);
        *(sword *)(iVar2 + 0x58) = *(sword *)(iVar2 + 0x58) + 1;
        if (*(sword *)(iVar2 + 0x5a) != 0) {
          *(sword *)(iVar2 + 0x5a) = *(sword *)(iVar2 + 0x5a) + 1;
        }
      }
      goto joined_r0x04024b92;
    }
    bVar8 = 0xffff05ff < _tcp_iss;
    bVar7 = SCARRY4(_tcp_iss,64000);
    _tcp_iss = _tcp_iss + 64000;
    bVar4 = bVar8 << 4 | ((int)_tcp_iss < 0) << 3 | (_tcp_iss == 0) << 2 | bVar7 << 1 | bVar8;
  }
  return bVar4;
}

