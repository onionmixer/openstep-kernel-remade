/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d0980. */
int __cdecl thread_set_special_port_EXTERNAL(int a1, int a2, int a3)
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

  v11 = 268509186; /*0x1d099a*/
  v12 = a2; /*0x1d099d*/
  v13 = 268509190; /*0x1d09a6*/
  v14 = a3; /*0x1d09a9*/
  HIBYTE(v5) = 0; /*0x1d09ac*/
  v6 = 40; /*0x1d09b0*/
  v7 = 256; /*0x1d09b7*/
  v9 = a1; /*0x1d09be*/
  reply_port = mig_get_reply_port(); /*0x1d09c6*/
  v10 = 2068; /*0x1d09c9*/
  result = msg_rpc(&v5, 0, 0x20u, 0, 0); /*0x1d09d9*/
  if ( result ) /*0x1d09e5*/
  {
    if ( result == -202 ) /*0x1d09ed*/
      mig_dealloc_reply_port(v4); /*0x1d09ef*/
  }
  else if ( v10 == 2168 ) /*0x1d0a06*/
  {
    if ( v6 == 32 && HIBYTE(v5) == 1 && v11 == 268509186 ) /*0x1d0a22*/
    {
      result = v12; /*0x1d0a2c*/
      if ( !v12 ) /*0x1d0a31*/
        return 0; /*0x1d0a33*/
    }
    else
    {
      return -300; /*0x1d0a24*/
    }
  }
  else
  {
    return -301; /*0x1d0a08*/
  }
  return result; /*0x1d0a38*/
}
