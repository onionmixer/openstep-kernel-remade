/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001304d3 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001304d3(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  char *pcVar4;
  
  while( true ) {
    *(undefined4 *)(unaff_EBP + -100) = 0x186ba;
    *(undefined4 *)(unaff_EBP + -0x60) = 1;
    *(undefined4 *)(unaff_EBP + -0x5c) = 1;
    *(int *)(unaff_EBP + -0x54) = unaff_EBP + -0x18;
    *(code **)(unaff_EBP + -0x50) = _xdr_bp_whoami_arg;
    *(int *)(unaff_EBP + -0x74) = unaff_EBP + -0x78;
    *(int *)(unaff_EBP + -0x6c) = unaff_EBP + -0x28;
    *(code **)(unaff_EBP + -0x68) = _xdr_bp_whoami_res;
    iVar2 = _clntkudp_callit_addr
                      (unaff_ESI,5,_xdr_rmtcall_args,unaff_EBP + -100,_xdr_rmtcallres,
                       unaff_EBP + -0x74,*(undefined4 *)(unaff_EBP + -0x80),
                       *(undefined4 *)(unaff_EBP + -0x7c));
    (**(code **)(*(int *)(unaff_ESI + 4) + 0x10))();
    if ((iVar2 == 5) && (unaff_EDI == 0)) {
      _printf(s_No_bootparam_server_responding__s_001dc7fd);
      _printf(s_whoami__pmap_rmtcall_status_0x_x_001dc82b,5);
      unaff_EDI = 1;
    }
    *(undefined4 *)(unaff_EBP + -0x80) = 0x14;
    *(undefined4 *)(unaff_EBP + -0x7c) = 0;
    if (iVar2 != 5) break;
    *(undefined2 *)(unaff_EBP + -0xe) = 0x6f00;
    unaff_ESI = _clntkudp_create(*(undefined4 *)(unaff_EBP + -0x8c),100000,2,5);
    if (unaff_ESI == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_pmap_rmtcall__clntkudp_create_fa_001dc746);
    }
  }
  if (unaff_EDI != 0) {
    _printf(s_Bootparam_response_received_001dc84d);
  }
  if (iVar2 != 0) {
    *(int *)(unaff_EBP + -0x84) = iVar2;
    _printf(s_whoami_RPC_call_failed_with_stat_001dc86a);
    goto LAB_00130676;
  }
  uVar3 = 0xffffffff;
  pcVar4 = *(char **)(unaff_EBP + -0x28);
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  _hostnamelen = ~uVar3 - 1;
  if (_hostnamelen < 0x101) {
    if ((int)_hostnamelen < 1) {
      _printf(s_whoami__no_host_name_001dc8ab);
      *(undefined4 *)(unaff_EBP + -0x84) = 6;
      goto LAB_00130676;
    }
    _bcopy(*(char **)(unaff_EBP + -0x28),&_hostname,_hostnamelen);
    _printf(s_hostname___s_001dc8c1);
    uVar3 = 0xffffffff;
    pcVar4 = *(char **)(unaff_EBP + -0x24);
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    _domainnamelen = ~uVar3 - 1;
    if (_domainnamelen < 0x101) {
      if (0 < (int)_domainnamelen) {
        _bcopy(*(char **)(unaff_EBP + -0x24),&_domainname,_domainnamelen);
        _printf(s_domainname___s_001dc8eb,&_domainname);
      }
      goto LAB_00130676;
    }
    pcVar4 = s_whoami__domainname_too_long_001dc8cf;
  }
  else {
    pcVar4 = s_whoami__hostname_too_long_001dc891;
  }
  _printf(pcVar4);
  *(undefined4 *)(unaff_EBP + -0x84) = 0x3f;
LAB_00130676:
  _kfree(*(undefined4 *)(unaff_EBP + -0x28));
  _kfree(*(undefined4 *)(unaff_EBP + -0x24),0x100);
  return *(undefined4 *)(unaff_EBP + -0x84);
}

