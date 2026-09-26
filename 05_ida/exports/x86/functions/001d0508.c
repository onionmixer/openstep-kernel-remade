/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d0508. */
int __cdecl port_deallocate_EXTERNAL(int a1, int a2)
{
  int result; // eax
  mach_port_t v3; // [esp+0h] [ebp-24h]
  int v4; // [esp+4h] [ebp-20h] BYREF
  int v5; // [esp+8h] [ebp-1Ch]
  int v6; // [esp+Ch] [ebp-18h]
  mach_port_t reply_port; // [esp+10h] [ebp-14h]
  int v8; // [esp+14h] [ebp-10h]
  int v9; // [esp+18h] [ebp-Ch]
  int v10; // [esp+1Ch] [ebp-8h]
  int v11; // [esp+20h] [ebp-4h]

  v10 = 268509186; /*0x1d051e*/
  v11 = a2; /*0x1d0521*/
  HIBYTE(v4) = 1; /*0x1d0524*/
  v5 = 32; /*0x1d0528*/
  v6 = 256; /*0x1d052f*/
  v8 = a1; /*0x1d0536*/
  reply_port = mig_get_reply_port(); /*0x1d053e*/
  v9 = 2077; /*0x1d0541*/
  result = msg_rpc(&v4, 0, 0x20u, 0, 0); /*0x1d0551*/
  if ( result ) /*0x1d055d*/
  {
    if ( result == -202 ) /*0x1d0565*/
      mig_dealloc_reply_port(v3); /*0x1d0567*/
  }
  else if ( v9 == 2177 ) /*0x1d057e*/
  {
    if ( v5 == 32 && HIBYTE(v4) == 1 && v10 == 268509186 ) /*0x1d059a*/
    {
      result = v11; /*0x1d05a4*/
      if ( !v11 ) /*0x1d05a9*/
        return 0; /*0x1d05ab*/
    }
    else
    {
      return -300; /*0x1d059c*/
    }
  }
  else
  {
    return -301; /*0x1d0580*/
  }
  return result; /*0x1d05ad*/
}
