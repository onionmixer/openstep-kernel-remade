/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00162a24 */

void _kdp_raise_exception(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined2 local_e;
  char local_c;
  byte local_b;
  
  uVar1 = _kdp_intr_disbl();
  if (param_4 == 0) {
    _safe_prf(s_kdp_raise_exception_with_NULL_st_001df4ac);
  }
  if (param_1 != 6) {
    if ((6 < param_1) || (uVar2 = param_1, param_1 == 0)) {
      uVar2 = 0;
    }
    _safe_prf(s__s_exception___x__x__x__001df4d1,(&PTR_s_Unknown_001df358)[uVar2],param_1,param_2,
              param_3);
  }
  _kdp_flush_cache();
  DAT_001f66ac = param_4;
  if (DAT_001e6448 != 0) {
    _kdp_panic(s_kdp_raise_exception_001df4ea);
  }
  if (DAT_001f66a8 == 0) {
    _safe_prf(s_Waiting_for_remote_debugger_conn_001df402);
    _safe_prf(s__Type__c__to_continue_or__r__to_r_001df42b);
    DAT_001e5e50 = 0;
    do {
      while (DAT_001e6448 == 0) {
        iVar3 = _kmtrygetc();
        if (iVar3 == 99) {
          _safe_prf(s_Continuing____001df454);
          goto LAB_00162c2d;
        }
        if (iVar3 == 0x72) {
          _safe_prf(s_Rebooting____001df463);
          _kdp_reboot();
        }
        FUN_001628f4();
      }
      _bcopy(&DAT_001e5e54 + DAT_001e6440,&local_c,8);
      if (((local_c == '\0') && (local_b == DAT_001e5e50)) &&
         (iVar3 = _kdp_packet(&DAT_001e5e54 + DAT_001e6440,&DAT_001e6444,&local_e), iVar3 != 0)) {
        FUN_001624a8(local_e);
      }
      DAT_001e6448 = 0;
    } while (DAT_001f66a8 == 0);
    _safe_prf(s_Connected_to_remote_debugger__001df471);
  }
  else {
    iVar3 = 300;
    do {
      DAT_001e6440 = 0x2a;
      _kdp_exception(&DAT_001e5e7e,&DAT_001e6444,&local_e,param_1,param_2,param_3);
      FUN_001626dc(local_e);
      FUN_001628f4();
      if (DAT_001e6448 != 0) {
        _kdp_exception_ack(&DAT_001e5e54 + DAT_001e6440,DAT_001e6444);
      }
      DAT_001e6448 = 0;
      if ((DAT_001f66b8 == 0) || (_kdp_us_spin(100000), DAT_001f66b8 == 0)) goto LAB_00162c2d;
      iVar3 = iVar3 + -1;
    } while (iVar3 != -1);
    _safe_prf(s_kdp__exception_ack_timeout_001df490);
    _kdp_reset();
  }
LAB_00162c2d:
  if (DAT_001f66a8 != 0) {
    DAT_001f66b0 = 1;
    DAT_001f66ac = param_4;
    do {
      while (DAT_001e6448 == 0) {
        FUN_001628f4();
      }
      _bcopy(&DAT_001e5e54 + DAT_001e6440,&local_c,8);
      if (-1 < local_c) {
        if ((uint)local_b == DAT_001e5e50 - 1) {
          _kdp_en_send_pkt(&DAT_001e644c + DAT_001e6a38,DAT_001e6a3c);
        }
        else if (DAT_001e5e50 == local_b) {
          iVar3 = _kdp_packet(&DAT_001e5e54 + DAT_001e6440,&DAT_001e6444,&local_e);
          if (iVar3 != 0) {
            FUN_001624a8(local_e);
          }
        }
        else {
          _safe_prf(s_kdp__bad_sequence__d__want__d__001df3e2,(uint)local_b,(uint)DAT_001e5e50);
        }
      }
      DAT_001e6448 = 0;
    } while (DAT_001f66b0 != 0);
    if (DAT_001f66a8 == 0) {
      _safe_prf(s_Remote_debugger_disconnected__001df4fe);
    }
  }
  _kdp_flush_cache();
  _kdp_intr_enbl(uVar1);
  return;
}

