/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x162a24. */
int __cdecl kdp_raise_exception(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int v4; // eax
  int v5; // eax
  int v6; // ebx
  int v8; // [esp+10h] [ebp-10h]
  __int16 v9; // [esp+16h] [ebp-Ah] BYREF
  char v10; // [esp+18h] [ebp-8h] BYREF
  unsigned __int8 v11; // [esp+19h] [ebp-7h]

  v8 = kdp_intr_disbl(); /*0x162a38*/
  if ( !a4 ) /*0x162a3f*/
    safe_prf(aKdpRaiseExcept); /*0x162a46*/
  v4 = a1; /*0x162a4e*/
  if ( a1 != 6 ) /*0x162a53*/
  {
    if ( a1 > 6 || !a1 ) /*0x162a59*/
      v4 = 0; /*0x162a5b*/
    safe_prf("%s exception (%x,%x,%x)\n", (&off_1DF358)[v4], a1, a2, a3); /*0x162a70*/
  }
  kdp_flush_cache(); /*0x162a78*/
  dword_1F66AC = a4; /*0x162a80*/
  if ( dword_1E6448 ) /*0x162a8d*/
    kdp_panic(aKdpRaiseExcept_0); /*0x162a94*/
  if ( dword_1F66A8 ) /*0x162aa3*/
  {
    v6 = 300; /*0x162b88*/
    while ( 1 ) /*0x162b90*/
    {
      dword_1E6440 = 42; /*0x162b90*/
      kdp_exception(&unk_1E5E7E, &dword_1E6444, &v9, a1, a2, a3); /*0x162bae*/
      sub_1626DC(v9); /*0x162bb8*/
      sub_1628F4(); /*0x162bbd*/
      if ( dword_1E6448 ) /*0x162bcc*/
        kdp_exception_ack(dword_1E6440 + 1990228, dword_1E6444); /*0x162be0*/
      dword_1E6448 = 0; /*0x162be8*/
      if ( !dword_1F66B8 ) /*0x162bf9*/
        break; /*0x162bf9*/
      kdp_us_spin(100000); /*0x162c00*/
      if ( !dword_1F66B8 ) /*0x162c0f*/
        break; /*0x162c0f*/
      if ( --v6 == -1 ) /*0x162c15*/
      {
        safe_prf(aKdpExceptionAc); /*0x162c20*/
        kdp_reset(); /*0x162c25*/
        break; /*0x162c25*/
      }
    }
  }
  else
  {
    safe_prf(aWaitingForRemo); /*0x162aae*/
    safe_prf(aTypeCToContinu); /*0x162ab8*/
    byte_1E5E50 = 0; /*0x162abd*/
    do /*0x162b74*/
    {
      while ( !dword_1E6448 ) /*0x162b0e*/
      {
        v5 = kmtrygetc(); /*0x162acc*/
        if ( v5 == 99 ) /*0x162ad4*/
        {
          safe_prf(aContinuing_1); /*0x162ae5*/
          goto LABEL_32; /*0x162aea*/
        }
        if ( v5 == 114 ) /*0x162ad9*/
        {
          safe_prf(aRebooting_0); /*0x162af5*/
          kdp_reboot(); /*0x162afa*/
        }
        sub_1628F4(); /*0x162b02*/
      }
      bcopy((const void *)(dword_1E6440 + 1990228), &v10, 8u); /*0x162b1e*/
      if ( !v10 && v11 == byte_1E5E50 && kdp_packet((void *)(dword_1E6440 + 1990228), (size_t *)&dword_1E6444) ) /*0x162b4a*/
        sub_1624A8(v9); /*0x162b5b*/
      dword_1E6448 = 0; /*0x162b63*/
    }
    while ( !dword_1F66A8 ); /*0x162b74*/
    safe_prf(aConnectedToRem); /*0x162b7b*/
  }
LABEL_32:
  if ( dword_1F66A8 )
  {
    dword_1F66B0 = 1; /*0x162c3a*/
    dword_1F66AC = a4; /*0x162c4a*/
    do
    {
      while ( !dword_1E6448 ) /*0x162c60*/
        sub_1628F4(); /*0x162c54*/
      bcopy((const void *)(dword_1E6440 + 1990228), &v10, 8u); /*0x162c70*/
      if ( v10 >= 0 )
      {
        if ( v11 == (unsigned __int8)byte_1E5E50 - 1 )
        {
          kdp_en_send_pkt(dword_1E6A38 + 1991756, dword_1E6A3C); /*0x162ca8*/
        }
        else if ( byte_1E5E50 == v11 )
        {
          if ( kdp_packet((void *)(dword_1E6440 + 1990228), (size_t *)&dword_1E6444) ) /*0x162ce0*/
            sub_1624A8(v9); /*0x162cf1*/
        }
        else
        {
          safe_prf("kdp: bad sequence %d (want %d)\n", v11, (unsigned __int8)byte_1E5E50);
        }
      }
      dword_1E6448 = 0; /*0x162cf9*/
    }
    while ( dword_1F66B0 );
    if ( !dword_1F66A8 ) /*0x162d17*/
      safe_prf(aRemoteDebugger); /*0x162d1e*/
  }
  kdp_flush_cache(); /*0x162d26*/
  return kdp_intr_enbl(v8); /*0x162d37*/
}
