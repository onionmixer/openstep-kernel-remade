
int _in_bootp_sendrequest
              (undefined4 param_1,int param_2,int param_3,char *param_4,int param_5,int *param_6)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  int *piVar8;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  int iStack_58;
  int iStack_54;
  uint auStack_50 [2];
  undefined2 uStack_48;
  undefined2 uStack_46;
  undefined4 uStack_44;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  bVar3 = false;
  bVar2 = false;
  _microtime(auStack_50);
  uVar1 = auStack_50[0] ^ *(byte *)(param_5 + 5);
  *(uint *)(param_3 + 0x20) = uVar1;
  uStack_48 = 2;
  uStack_46 = 0x43;
  uStack_44 = 0xffffffff;
  iStack_64 = 1;
  iStack_68 = 0;
  iStack_6c = 0;
loc_40901F8:
  if (iStack_68 == 0) {
    uVar4 = _in_bootp_bptombuf(param_3);
    iVar5 = _if_output_mbuf(param_1,uVar4,&uStack_48);
    if (iVar5 != 0) {
loc_409057A:
      _untimeout(_in_bootp_promisctimeout,&iStack_58);
      return iVar5;
    }
  }
  uStack_38 = *(undefined4 *)(dword_40B57D4 + 0x28);
  uStack_34 = *(undefined4 *)(dword_40B57D4 + 0x2c);
  uStack_30 = *(undefined4 *)(dword_40B57D4 + 0x30);
  uStack_2c = *(undefined4 *)(dword_40B57D4 + 0x34);
  uStack_28 = *(undefined4 *)(dword_40B57D4 + 0x38);
  uStack_24 = *(undefined4 *)(dword_40B57D4 + 0x3c);
  uStack_20 = *(undefined4 *)(dword_40B57D4 + 0x40);
  uStack_1c = *(undefined4 *)(dword_40B57D4 + 0x44);
  uStack_18 = *(undefined4 *)(dword_40B57D4 + 0x48);
  uStack_14 = *(undefined4 *)(dword_40B57D4 + 0x4c);
  uStack_10 = *(undefined4 *)(dword_40B57D4 + 0x50);
  uStack_c = *(undefined4 *)(dword_40B57D4 + 0x54);
  uStack_8 = *(undefined4 *)(dword_40B57D4 + 0x58);
  iVar6 = _setjmp(dword_40B57D4 + 0x28);
  iVar5 = dword_40B57D4;
  if (iVar6 == 0) {
    iStack_54 = param_2;
    piVar8 = &iStack_54;
    pcVar7 = _in_bootp_timeout;
    iVar5 = _hz;
loc_4090312:
    _timeout(pcVar7,piVar8,iVar5);
loc_409031C:
    do {
      while ((iVar5 = _in_bootp_getpacket(param_2,param_4,300), iVar6 = dword_40B57D4, iVar5 == 0x23
             && (iStack_54 == param_2))) {
        _sbwait(iStack_54 + 0x22);
      }
      if ((iVar5 != 0) && (iVar5 != 0x23)) {
        *(undefined4 *)(dword_40B57D4 + 0x28) = uStack_38;
        *(undefined4 *)(iVar6 + 0x2c) = uStack_34;
        *(undefined4 *)(iVar6 + 0x30) = uStack_30;
        *(undefined4 *)(iVar6 + 0x34) = uStack_2c;
        *(undefined4 *)(iVar6 + 0x38) = uStack_28;
        *(undefined4 *)(iVar6 + 0x3c) = uStack_24;
        *(undefined4 *)(iVar6 + 0x40) = uStack_20;
        *(undefined4 *)(iVar6 + 0x44) = uStack_1c;
        *(undefined4 *)(iVar6 + 0x48) = uStack_18;
        *(undefined4 *)(iVar6 + 0x4c) = uStack_14;
        *(undefined4 *)(iVar6 + 0x50) = uStack_10;
        *(undefined4 *)(iVar6 + 0x54) = uStack_c;
        *(undefined4 *)(iVar6 + 0x58) = uStack_8;
        _untimeout(_in_bootp_timeout,&iStack_54);
        goto loc_409057A;
      }
      if (iStack_54 == 0) {
        *(undefined4 *)(dword_40B57D4 + 0x28) = uStack_38;
        *(undefined4 *)(iVar6 + 0x2c) = uStack_34;
        *(undefined4 *)(iVar6 + 0x30) = uStack_30;
        *(undefined4 *)(iVar6 + 0x34) = uStack_2c;
        *(undefined4 *)(iVar6 + 0x38) = uStack_28;
        *(undefined4 *)(iVar6 + 0x3c) = uStack_24;
        *(undefined4 *)(iVar6 + 0x40) = uStack_20;
        *(undefined4 *)(iVar6 + 0x44) = uStack_1c;
        *(undefined4 *)(iVar6 + 0x48) = uStack_18;
        *(undefined4 *)(iVar6 + 0x4c) = uStack_14;
        *(undefined4 *)(iVar6 + 0x50) = uStack_10;
        *(undefined4 *)(iVar6 + 0x54) = uStack_c;
        *(undefined4 *)(iVar6 + 0x58) = uStack_8;
        iStack_68 = iStack_68 + 1;
        iStack_6c = iStack_6c + 1;
        if (iStack_68 == iStack_64) {
          if (iStack_68 < 0x40) {
            iStack_64 = iStack_68 * 2;
          }
          iStack_68 = 0;
        }
        if (iStack_6c != 0x14) goto loc_40901F8;
        if ((*param_6 == 0) && (iVar5 = _in_bootp_openconsole(param_6), iVar5 != 0))
        goto loc_409057A;
        _printf(aNoResponseFrom);
        bVar3 = true;
        goto loc_40901F8;
      }
    } while (((*(uint *)(param_4 + 4) != uVar1) || (*param_4 != '\x02')) ||
            (iVar6 = _bcmp(param_4 + 0x1c,param_5,6), iVar5 = dword_40B57D4, iVar6 != 0));
    if ((*(char *)(param_3 + 0x10e) == '\0') && (param_4[0xf2] != '\0')) {
      if (!bVar2) goto loc_40904cc;
      if (iStack_58 == 1) goto loc_409031C;
    }
    *(undefined4 *)(dword_40B57D4 + 0x28) = uStack_38;
    *(undefined4 *)(iVar5 + 0x2c) = uStack_34;
    *(undefined4 *)(iVar5 + 0x30) = uStack_30;
    *(undefined4 *)(iVar5 + 0x34) = uStack_2c;
    *(undefined4 *)(iVar5 + 0x38) = uStack_28;
    *(undefined4 *)(iVar5 + 0x3c) = uStack_24;
    *(undefined4 *)(iVar5 + 0x40) = uStack_20;
    *(undefined4 *)(iVar5 + 0x44) = uStack_1c;
    *(undefined4 *)(iVar5 + 0x48) = uStack_18;
    *(undefined4 *)(iVar5 + 0x4c) = uStack_14;
    *(undefined4 *)(iVar5 + 0x50) = uStack_10;
    *(undefined4 *)(iVar5 + 0x54) = uStack_c;
    *(undefined4 *)(iVar5 + 0x58) = uStack_8;
    _untimeout(_in_bootp_timeout,&iStack_54);
    if (bVar3) {
      _printf(aNetworkRespond);
    }
    iVar5 = 0;
    goto loc_409057A;
  }
  *(undefined4 *)(dword_40B57D4 + 0x28) = uStack_38;
  *(undefined4 *)(iVar5 + 0x2c) = uStack_34;
  *(undefined4 *)(iVar5 + 0x30) = uStack_30;
  *(undefined4 *)(iVar5 + 0x34) = uStack_2c;
  *(undefined4 *)(iVar5 + 0x38) = uStack_28;
  *(undefined4 *)(iVar5 + 0x3c) = uStack_24;
  *(undefined4 *)(iVar5 + 0x40) = uStack_20;
  *(undefined4 *)(iVar5 + 0x44) = uStack_1c;
  *(undefined4 *)(iVar5 + 0x48) = uStack_18;
  *(undefined4 *)(iVar5 + 0x4c) = uStack_14;
  *(undefined4 *)(iVar5 + 0x50) = uStack_10;
  *(undefined4 *)(iVar5 + 0x54) = uStack_c;
  *(undefined4 *)(iVar5 + 0x58) = uStack_8;
  _untimeout(_in_bootp_timeout,&iStack_54);
  iVar5 = 4;
  goto loc_409057A;
loc_40904cc:
  bVar2 = true;
  iStack_58 = 1;
  iVar5 = _hz * 10;
  piVar8 = &iStack_58;
  pcVar7 = _in_bootp_promisctimeout;
  goto loc_4090312;
}
