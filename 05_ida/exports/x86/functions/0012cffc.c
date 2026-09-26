/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12cffc. */
int nfs_svc()
{
  int v0; // eax
  int result; // eax
  int v2; // [esp+4h] [ebp-18h]
  unsigned int i; // [esp+8h] [ebp-14h]
  unsigned int j; // [esp+8h] [ebp-14h]
  SVCXPRT *v5; // [esp+Ch] [ebp-10h]
  int v6; // [esp+14h] [ebp-8h]

  v0 = getsock(**(_DWORD **)(dword_1E875C + 36)); /*0x12d011*/
  if ( v0 ) /*0x12d01e*/
  {
    v6 = *(_DWORD *)(v0 + 24); /*0x12d033*/
    v2 = soreserve(v6, nfs_chars, nfs_chars + 32); /*0x12d047*/
    if ( !v2 ) /*0x12d04f*/
    {
      v5 = (SVCXPRT *)svckudp_create(v6, 2049); /*0x12d072*/
      for ( i = 2; i <= 2; ++i ) /*0x12d075*/
        svc_register(v5, 0x186A3u, i, sub_12D7D4, 0); /*0x12d094*/
      if ( setjmp((int *)(dword_1E875C + 40)) ) /*0x12d0b1*/
      {
        if ( !--nfsd_count ) /*0x12d0c3*/
        {
          for ( j = 2; j <= 2; ++j ) /*0x12d0c5*/
            svc_unregister(0x186A3u, j); /*0x12d0d5*/
        }
        v5->xp_ops->xp_destroy(v5); /*0x12d0f3*/
        *(_BYTE *)(dword_1E875C + 104) = 4; /*0x12d0fa*/
        exit(0); /*0x12d100*/
      }
      ++nfsd_count; /*0x12d108*/
      svc_run(); /*0x12d112*/
    }
    result = dword_1E875C; /*0x12d051*/
    *(_BYTE *)(dword_1E875C + 104) = v2; /*0x12d059*/
  }
  else
  {
    result = dword_1E875C; /*0x12d020*/
    *(_BYTE *)(dword_1E875C + 104) = 9; /*0x12d025*/
  }
  return result; /*0x12d117*/
}
