/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001303f4 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001303f4(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int unaff_EBP;
  char *pcVar7;
  
  _bcopy((void *)(unaff_EBP + -0x38),*(void **)(unaff_EBP + -0x88),0x10);
  _bcopy((void *)(unaff_EBP + -0x38),&DAT_001e59d8,0x10);
  *(undefined4 *)(unaff_EBP + -0x18) = 1;
  iVar3 = _in_control(0,0xc020690d);
  if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_bad_SIOCGIFADDR_in_control_001dc7e2);
  }
  *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(unaff_EBP + -0x34);
  _bcopy((void *)(unaff_EBP + -0x4c),(void *)(unaff_EBP + -0x14),4);
  *(undefined4 *)(unaff_EBP + -0x80) = 3;
  *(undefined4 *)(unaff_EBP + -0x7c) = 0;
  uVar4 = _kalloc();
  *(undefined4 *)(unaff_EBP + -0x28) = uVar4;
  uVar4 = _kalloc(0x100);
  *(undefined4 *)(unaff_EBP + -0x24) = uVar4;
  bVar2 = false;
  *(undefined4 *)(unaff_EBP + -0x8c) = *(undefined4 *)(unaff_EBP + -0x88);
  do {
    *(undefined2 *)(unaff_EBP + -0xe) = 0x6f00;
    iVar3 = _clntkudp_create(*(undefined4 *)(unaff_EBP + -0x8c));
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_rmtcall__clntkudp_create_fa_001dc746);
    }
    *(undefined4 *)(unaff_EBP + -100) = 0x186ba;
    *(undefined4 *)(unaff_EBP + -0x60) = 1;
    *(undefined4 *)(unaff_EBP + -0x5c) = 1;
    *(int *)(unaff_EBP + -0x54) = unaff_EBP + -0x18;
    *(code **)(unaff_EBP + -0x50) = _xdr_bp_whoami_arg;
    *(int *)(unaff_EBP + -0x74) = unaff_EBP + -0x78;
    *(int *)(unaff_EBP + -0x6c) = unaff_EBP + -0x28;
    *(code **)(unaff_EBP + -0x68) = _xdr_bp_whoami_res;
    iVar5 = _clntkudp_callit_addr(iVar3,5,_xdr_rmtcall_args,unaff_EBP + -100,_xdr_rmtcallres);
    (**(code **)(*(int *)(iVar3 + 4) + 0x10))();
    if ((iVar5 == 5) && (!bVar2)) {
      _printf(s_No_bootparam_server_responding__s_001dc7fd);
      _printf(s_whoami__pmap_rmtcall_status_0x_x_001dc82b);
      bVar2 = true;
    }
    *(undefined4 *)(unaff_EBP + -0x80) = 0x14;
    *(undefined4 *)(unaff_EBP + -0x7c) = 0;
  } while (iVar5 == 5);
  if (bVar2) {
    _printf(s_Bootparam_response_received_001dc84d);
  }
  if (iVar5 != 0) {
    *(int *)(unaff_EBP + -0x84) = iVar5;
    _printf(s_whoami_RPC_call_failed_with_stat_001dc86a);
    goto LAB_00130676;
  }
  uVar6 = 0xffffffff;
  pcVar7 = *(char **)(unaff_EBP + -0x28);
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  _hostnamelen = ~uVar6 - 1;
  if (_hostnamelen < 0x101) {
    if ((int)_hostnamelen < 1) {
      _printf(s_whoami__no_host_name_001dc8ab);
      *(undefined4 *)(unaff_EBP + -0x84) = 6;
      goto LAB_00130676;
    }
    _bcopy(*(char **)(unaff_EBP + -0x28),&_hostname,_hostnamelen);
    _printf(s_hostname___s_001dc8c1);
    uVar6 = 0xffffffff;
    pcVar7 = *(char **)(unaff_EBP + -0x24);
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    _domainnamelen = ~uVar6 - 1;
    if (_domainnamelen < 0x101) {
      if (0 < (int)_domainnamelen) {
        _bcopy(*(char **)(unaff_EBP + -0x24),&_domainname,_domainnamelen);
        _printf(s_domainname___s_001dc8eb);
      }
      goto LAB_00130676;
    }
    pcVar7 = s_whoami__domainname_too_long_001dc8cf;
  }
  else {
    pcVar7 = s_whoami__hostname_too_long_001dc891;
  }
  _printf(pcVar7);
  *(undefined4 *)(unaff_EBP + -0x84) = 0x3f;
LAB_00130676:
  _kfree();
  _kfree();
  return *(undefined4 *)(unaff_EBP + -0x84);
}

