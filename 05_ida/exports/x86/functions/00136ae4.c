/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x136ae4. */
void __cdecl _seterr_reply(rpc_msg *a1, rpc_err *a2)
{
  unsigned __int32 cb_rpcvers; // eax
  unsigned __int32 oa_flavor; // eax
  unsigned __int32 cb_prog; // eax
  clnt_stat re_status; // eax
  unsigned __int32 cb_proc; // ecx

  cb_rpcvers = a1->ru.RM_cmb.cb_rpcvers; /*0x136aee*/
  if ( cb_rpcvers ) /*0x136af3*/
  {
    if ( cb_rpcvers == 1 ) /*0x136af8*/
    {
      cb_prog = a1->ru.RM_cmb.cb_prog; /*0x136b80*/
      if ( cb_prog ) /*0x136b85*/
      {
        if ( cb_prog == 1 ) /*0x136b8a*/
        {
          a2->re_status = RPC_AUTHERROR; /*0x136b98*/
        }
        else
        {
          a2->re_status = RPC_FAILED; /*0x136ba0*/
          a2->ru.RE_errno = 1; /*0x136ba6*/
          a2->ru.RE_vers.high = cb_prog; /*0x136bad*/
        }
      }
      else
      {
        a2->re_status = RPC_VERSMISMATCH; /*0x136b90*/
      }
    }
    else
    {
      a2->re_status = RPC_FAILED; /*0x136bb4*/
      a2->ru.RE_errno = a1->ru.RM_cmb.cb_rpcvers; /*0x136bbd*/
    }
  }
  else
  {
    oa_flavor = a1->ru.RM_cmb.cb_cred.oa_flavor; /*0x136b04*/
    if ( !oa_flavor ) /*0x136b09*/
    {
      a2->re_status = RPC_SUCCESS; /*0x136b0b*/
      return; /*0x136b11*/
    }
    switch ( oa_flavor ) /*0x136b1d*/
    {
      case 1u: /*0x136b1d*/
        a2->re_status = RPC_PROGUNAVAIL; /*0x136b3c*/
        break; /*0x136b42*/
      case 2u: /*0x136b1d*/
        a2->re_status = RPC_PROGVERSMISMATCH; /*0x136b44*/
        break; /*0x136b4a*/
      case 3u: /*0x136b1d*/
        a2->re_status = RPC_PROCUNAVAIL; /*0x136b4c*/
        break; /*0x136b52*/
      case 4u: /*0x136b1d*/
        a2->re_status = RPC_CANTDECODEARGS; /*0x136b54*/
        break; /*0x136b5a*/
      case 5u: /*0x136b1d*/
        a2->re_status = RPC_SYSTEMERROR; /*0x136b5c*/
        break; /*0x136b62*/
      default:
        a2->re_status = RPC_FAILED; /*0x136b6c*/
        a2->ru.RE_errno = 0; /*0x136b72*/
        a2->ru.RE_vers.high = oa_flavor; /*0x136b79*/
        break; /*0x136b7c*/
    }
  }
  re_status = a2->re_status; /*0x136bc0*/
  if ( a2->re_status == RPC_AUTHERROR ) /*0x136bc5*/
  {
    a2->ru.RE_errno = a1->ru.RM_cmb.cb_vers; /*0x136be7*/
    return; /*0x136bea*/
  }
  if ( a2->re_status <= RPC_AUTHERROR ) /*0x136bc7*/
  {
    if ( re_status != RPC_VERSMISMATCH ) /*0x136bcc*/
      return; /*0x136bcc*/
    a2->ru.RE_errno = a1->ru.RM_cmb.cb_vers; /*0x136bdb*/
    cb_proc = a1->ru.RM_cmb.cb_proc; /*0x136bde*/
LABEL_27:
    a2->ru.RE_vers.high = cb_proc; /*0x136bf5*/
    return; /*0x136bf5*/
  }
  if ( re_status == RPC_PROGVERSMISMATCH ) /*0x136bd3*/
  {
    a2->ru.RE_errno = (int)a1->ru.RM_cmb.cb_cred.oa_base; /*0x136bef*/
    cb_proc = a1->ru.RM_cmb.cb_cred.oa_length; /*0x136bf2*/
    goto LABEL_27; /*0x136bf2*/
  }
}
