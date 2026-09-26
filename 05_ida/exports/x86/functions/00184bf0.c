/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x184bf0. */
int __cdecl volioctl(int a1, int a2, __int16 *a3)
{
  int v3; // edi
  void *v4; // ebx
  _UNKNOWN **v5; // esi
  _UNKNOWN **v6; // edx
  _UNKNOWN **v7; // eax
  __int16 v8; // dx

  v3 = 0; /*0x184bfc*/
  if ( a2 == -2147195884 ) /*0x184c03*/
  {
    if ( get_kern_port(*(_DWORD *)(active_threads + 12), *(_DWORD *)a3, &dword_1E13EC) ) /*0x184c45*/
      return 22; /*0x184d5c*/
    lock_write(&unk_1E758C); /*0x184c5a*/
    v4 = off_1E13FC; /*0x184c5f*/
    if ( off_1E13FC != (_UNKNOWN *)&off_1E13FC ) /*0x184c6e*/
    {
      do /*0x184ce7*/
      {
        v5 = *(_UNKNOWN ***)v4; /*0x184c70*/
        v6 = *(_UNKNOWN ***)v4; /*0x184c72*/
        v7 = *((_UNKNOWN ***)v4 + 1); /*0x184c74*/
        if ( *(_UNKNOWN ***)v4 == &off_1E13FC ) /*0x184c7d*/
          off_1E1400[0] = *((_UNKNOWN ***)v4 + 1); /*0x184c7f*/
        else
          v5[1] = v7; /*0x184c88*/
        if ( v7 == &off_1E13FC ) /*0x184c90*/
          off_1E13FC = v6; /*0x184c92*/
        else
          *v7 = v6; /*0x184c9c*/
        v8 = *((_WORD *)v4 + 6); /*0x184c9e*/
        if ( rootdev != v8 ) /*0x184ca9*/
          sub_184D9C( /*0x184ccc*/
            *((_DWORD *)v4 + 2),
            v8,
            *((_WORD *)v4 + 7),
            *((_DWORD *)v4 + 4),
            *((_DWORD *)v4 + 5),
            (char *)v4 + 24,
            (char *)v4 + 88,
            *((_DWORD *)v4 + 24));
        kfree(v4, 100); /*0x184cd7*/
        v4 = v5; /*0x184cdc*/
      }
      while ( v5 != &off_1E13FC ); /*0x184ce7*/
    }
    lock_done(&unk_1E758C); /*0x184cee*/
    port_request_notification(dword_1E13EC, dword_1E13F4); /*0x184d07*/
  }
  else if ( a2 > -2147195884 ) /*0x184c05*/
  {
    if ( a2 == -2147195882 ) /*0x184c1d*/
    {
      if ( get_kern_port(*(_DWORD *)(active_threads + 12), *(_DWORD *)a3, &panel_req_port) ) /*0x184d1d*/
        v3 = 22; /*0x184d29*/
      port_request_notification(panel_req_port, dword_1E13F4); /*0x184d3c*/
    }
    else
    {
      if ( a2 != 536896538 ) /*0x184c28*/
        return 22; /*0x184c28*/
      dword_1E759C = 1; /*0x184d44*/
    }
  }
  else
  {
    if ( a2 != -2147326949 ) /*0x184c0c*/
      return 22; /*0x184c0c*/
    vol_notify_cancel(*a3); /*0x184d54*/
  }
  return v3; /*0x184d66*/
}
