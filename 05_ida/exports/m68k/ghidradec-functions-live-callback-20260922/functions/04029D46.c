
int sub_4029D46(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uStack_50;
  undefined auStack_4c [16];
  undefined auStack_3c [4];
  undefined4 uStack_38;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_1c;
  undefined auStack_18 [4];
  undefined auStack_14 [16];
  
  if (dword_40AEE7E != 0) {
    return 0;
  }
  dword_40AEE7E = 1;
  _bzero(auStack_14,0x10);
  iVar2 = _ifb_ifwithaf(2);
  if (iVar2 == 0) {
    _printf(aWhoamiZeroIfp);
    return 0x41;
  }
  iVar3 = _initrootnet();
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aWhoamiInitroot);
  }
  iVar3 = _in_control(0,0xc0206912,auStack_4c,iVar2);
  if (iVar3 != 0) {
    _printf(aWhoamiInContro,iVar3,(int)*(sword *)(iVar2 + 0xc));
                    /* WARNING: Subroutine does not return */
    _panic(aBadSiocgifbrda);
  }
  _bcopy(auStack_3c,auStack_14,0x10);
  _bcopy(auStack_3c,unk_40B3554,0x10);
  uStack_1c = 1;
  iVar2 = _in_control(0,0xc020690d,auStack_4c,iVar2);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aBadSiocgifaddr);
  }
  uStack_50 = uStack_38;
  _bcopy(&uStack_50,auStack_18,4);
  uVar4 = 3;
  uStack_2c = _kalloc(0x100);
  uStack_28 = _kalloc(0x100);
  bVar1 = false;
  do {
    iVar2 = sub_4029C74(auStack_14,0x186ba,1,1,_xdr_bp_whoami_arg,&uStack_1c,_xdr_bp_whoami_res,
                        &uStack_2c,uVar4,0,0);
    if ((iVar2 == 5) && (!bVar1)) {
      _printf(aNoBootparamSer_0);
      _printf(aWhoamiPmapRmtc,5);
      bVar1 = true;
    }
    uVar4 = 0x14;
  } while (iVar2 == 5);
  if (bVar1) {
    _printf(aBootparamRespo);
  }
  if (iVar2 != 0) {
    _printf(aWhoamiRpcCallF,iVar2);
    goto loc_4029FCA;
  }
  _hostnamelen = _strlen(uStack_2c);
  if (_hostnamelen < 0x101) {
    if ((int)_hostnamelen < 1) {
      _printf(aWhoamiNoHostNa);
      iVar2 = 6;
      goto loc_4029FCA;
    }
    _bcopy(uStack_2c,_hostname,_hostnamelen);
    _printf(aHostnameS,_hostname);
    _domainnamelen = _strlen(uStack_28);
    if (_domainnamelen < 0x101) {
      iVar2 = 0;
      if (0 < (int)_domainnamelen) {
        _bcopy(uStack_28,_domainname,_domainnamelen);
        _printf(aDomainnameS,_domainname);
      }
      goto loc_4029FCA;
    }
    _printf(aWhoamiDomainna);
  }
  else {
    _printf(aWhoamiHostname);
  }
  iVar2 = 0x3f;
loc_4029FCA:
  _kfree(uStack_2c,0x100);
  _kfree(uStack_28,0x100);
  return iVar2;
}

