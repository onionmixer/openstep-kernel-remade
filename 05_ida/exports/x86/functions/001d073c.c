/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d073c. */
int __cdecl port_set_deallocate_EXTERNAL(int a1, int a2)
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

  v10 = 268509186; /*0x1d0752*/
  v11 = a2; /*0x1d0755*/
  HIBYTE(v4) = 1; /*0x1d0758*/
  v5 = 32; /*0x1d075c*/
  v6 = 256; /*0x1d0763*/
  v8 = a1; /*0x1d076a*/
  reply_port = mig_get_reply_port(); /*0x1d0772*/
  v9 = 2081; /*0x1d0775*/
  result = msg_rpc(&v4, 0, 0x20u, 0, 0); /*0x1d0785*/
  if ( result ) /*0x1d0791*/
  {
    if ( result == -202 ) /*0x1d0799*/
      mig_dealloc_reply_port(v3); /*0x1d079b*/
  }
  else if ( v9 == 2181 ) /*0x1d07b2*/
  {
    if ( v5 == 32 && HIBYTE(v4) == 1 && v10 == 268509186 ) /*0x1d07ce*/
    {
      result = v11; /*0x1d07d8*/
      if ( !v11 ) /*0x1d07dd*/
        return 0; /*0x1d07df*/
    }
    else
    {
      return -300; /*0x1d07d0*/
    }
  }
  else
  {
    return -301; /*0x1d07b4*/
  }
  return result; /*0x1d07e1*/
}
