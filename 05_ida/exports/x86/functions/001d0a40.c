/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d0a40. */
int __cdecl vm_deallocate_EXTERNAL(int a1, int a2, int a3)
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

  v11 = 268509186; /*0x1d0a5a*/
  v12 = a2; /*0x1d0a5d*/
  v13 = 268509186; /*0x1d0a66*/
  v14 = a3; /*0x1d0a69*/
  HIBYTE(v5) = 1; /*0x1d0a6c*/
  v6 = 40; /*0x1d0a70*/
  v7 = 256; /*0x1d0a77*/
  v9 = a1; /*0x1d0a7e*/
  reply_port = mig_get_reply_port(); /*0x1d0a86*/
  v10 = 2023; /*0x1d0a89*/
  result = msg_rpc(&v5, 0, 0x20u, 0, 0); /*0x1d0a99*/
  if ( result ) /*0x1d0aa5*/
  {
    if ( result == -202 ) /*0x1d0aad*/
      mig_dealloc_reply_port(v4); /*0x1d0aaf*/
  }
  else if ( v10 == 2123 ) /*0x1d0ac6*/
  {
    if ( v6 == 32 && HIBYTE(v5) == 1 && v11 == 268509186 ) /*0x1d0ae2*/
    {
      result = v12; /*0x1d0aec*/
      if ( !v12 ) /*0x1d0af1*/
        return 0; /*0x1d0af3*/
    }
    else
    {
      return -300; /*0x1d0ae4*/
    }
  }
  else
  {
    return -301; /*0x1d0ac8*/
  }
  return result; /*0x1d0af8*/
}
