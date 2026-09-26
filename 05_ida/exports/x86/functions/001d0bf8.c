/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d0bf8. */
int __cdecl port_set_backlog_EXTERNAL(int a1, int a2, int a3)
{
  int result; // eax
  mach_port_t v4; // [esp+0h] [ebp-30h]
  int v5; // [esp+8h] [ebp-28h] BYREF
  int v6; // [esp+Ch] [ebp-24h]
  int v7; // [esp+10h] [ebp-20h]
  mach_port_t reply_port; // [esp+14h] [ebp-1Ch]
  int v9; // [esp+18h] [ebp-18h]
  int v10; // [esp+1Ch] [ebp-14h]
  int v11; // [esp+20h] [ebp-10h]
  int v12; // [esp+24h] [ebp-Ch]
  int v13; // [esp+28h] [ebp-8h]
  int v14; // [esp+2Ch] [ebp-4h]

  v11 = 268509186; /*0x1d0c12*/
  v12 = a2; /*0x1d0c15*/
  v13 = 268509186; /*0x1d0c1e*/
  v14 = a3; /*0x1d0c21*/
  HIBYTE(v5) = 1; /*0x1d0c24*/
  v6 = 40; /*0x1d0c28*/
  v7 = 256; /*0x1d0c2f*/
  v9 = a1; /*0x1d0c36*/
  reply_port = mig_get_reply_port(); /*0x1d0c3e*/
  v10 = 2078; /*0x1d0c41*/
  result = msg_rpc(&v5, 0, 0x20u, 0, 0); /*0x1d0c51*/
  if ( result ) /*0x1d0c5d*/
  {
    if ( result == -202 ) /*0x1d0c65*/
      mig_dealloc_reply_port(v4); /*0x1d0c67*/
  }
  else if ( v10 == 2178 ) /*0x1d0c7e*/
  {
    if ( v6 == 32 && HIBYTE(v5) == 1 && v11 == 268509186 ) /*0x1d0c9a*/
    {
      result = v12; /*0x1d0ca4*/
      if ( !v12 ) /*0x1d0ca9*/
        return 0; /*0x1d0cab*/
    }
    else
    {
      return -300; /*0x1d0c9c*/
    }
  }
  else
  {
    return -301; /*0x1d0c80*/
  }
  return result; /*0x1d0cb0*/
}
