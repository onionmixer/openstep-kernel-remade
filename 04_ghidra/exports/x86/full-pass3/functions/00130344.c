/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00130344 */

int FUN_00130344(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  int local_88;
  undefined4 local_84;
  undefined1 local_7c [4];
  undefined1 *local_78 [2];
  char **local_70;
  code *local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 *local_58;
  code *local_54;
  undefined4 local_50;
  undefined1 local_4c [16];
  undefined1 local_3c [4];
  undefined4 local_38;
  char *local_2c;
  char *local_28;
  undefined4 local_1c;
  undefined1 local_18 [4];
  undefined1 local_14 [2];
  undefined2 local_12;
  
  if (DAT_001dc76c != 0) {
    return 0;
  }
  DAT_001dc76c = 1;
  _bzero(local_14,0x10);
  iVar3 = _ifb_ifwithaf(2);
  if (iVar3 == 0) {
    _printf(s_whoami__zero_ifp_001dc770);
    return 0x41;
  }
  iVar4 = _initrootnet();
  if (iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_whoami__initrootnet_failed_001dc782);
  }
  iVar4 = _in_control(0,0xc0206912,local_4c,iVar3);
  if (iVar4 != 0) {
    _printf(s_whoami__in_control_0x_x_if_flags_001dc79d,iVar4,(int)*(short *)(iVar3 + 0xc));
                    /* WARNING: Subroutine does not return */
    _panic(s_bad_SIOCGIFBRDADDR_in_control_001dc7c4);
  }
  _bcopy(local_3c,local_14,0x10);
  _bcopy(local_3c,&DAT_001e59d8,0x10);
  local_1c = 1;
  iVar3 = _in_control(0,0xc020690d,local_4c,iVar3);
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_bad_SIOCGIFADDR_in_control_001dc7e2);
  }
  local_50 = local_38;
  _bcopy(&local_50,local_18,4);
  local_84 = 3;
  local_2c = (char *)_kalloc(0x100);
  local_28 = (char *)_kalloc(0x100);
  bVar2 = false;
  do {
    local_12 = 0x6f00;
    iVar3 = _clntkudp_create(local_14,100000,2,5,*(undefined4 *)(_active_u + 0x1c));
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_rmtcall__clntkudp_create_fa_001dc746);
    }
    local_68 = 0x186ba;
    local_64 = 1;
    local_60 = 1;
    local_58 = &local_1c;
    local_54 = _xdr_bp_whoami_arg;
    local_78[0] = local_7c;
    local_70 = &local_2c;
    local_6c = _xdr_bp_whoami_res;
    local_88 = _clntkudp_callit_addr
                         (iVar3,5,_xdr_rmtcall_args,&local_68,_xdr_rmtcallres,local_78,local_84,0,0)
    ;
    (**(code **)(*(int *)(iVar3 + 4) + 0x10))(iVar3);
    if ((local_88 == 5) && (!bVar2)) {
      _printf(s_No_bootparam_server_responding__s_001dc7fd);
      _printf(s_whoami__pmap_rmtcall_status_0x_x_001dc82b,5);
      bVar2 = true;
    }
    local_84 = 0x14;
  } while (local_88 == 5);
  if (bVar2) {
    _printf(s_Bootparam_response_received_001dc84d);
  }
  if (local_88 != 0) {
    _printf(s_whoami_RPC_call_failed_with_stat_001dc86a,local_88);
    goto LAB_00130676;
  }
  uVar5 = 0xffffffff;
  pcVar6 = local_2c;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  _hostnamelen = ~uVar5 - 1;
  if (_hostnamelen < 0x101) {
    if ((int)_hostnamelen < 1) {
      _printf(s_whoami__no_host_name_001dc8ab);
      local_88 = 6;
      goto LAB_00130676;
    }
    _bcopy(local_2c,&_hostname,_hostnamelen);
    _printf(s_hostname___s_001dc8c1,&_hostname);
    uVar5 = 0xffffffff;
    pcVar6 = local_28;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    _domainnamelen = ~uVar5 - 1;
    if (_domainnamelen < 0x101) {
      local_88 = 0;
      if (0 < (int)_domainnamelen) {
        _bcopy(local_28,&_domainname,_domainnamelen);
        _printf(s_domainname___s_001dc8eb,&_domainname);
      }
      goto LAB_00130676;
    }
    pcVar6 = s_whoami__domainname_too_long_001dc8cf;
  }
  else {
    pcVar6 = s_whoami__hostname_too_long_001dc891;
  }
  _printf(pcVar6);
  local_88 = 0x3f;
LAB_00130676:
  _kfree(local_2c,0x100);
  _kfree(local_28,0x100);
  return local_88;
}

