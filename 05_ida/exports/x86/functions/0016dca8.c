/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16dca8. */
int __cdecl kern_serv_panic(int a1, char *__src)
{
  int result; // eax
  mach_port_t v3; // [esp+0h] [ebp-12Ch]
  int v4; // [esp+8h] [ebp-124h] BYREF
  int v5; // [esp+Ch] [ebp-120h]
  int v6; // [esp+10h] [ebp-11Ch]
  mach_port_t reply_port; // [esp+14h] [ebp-118h]
  int v8; // [esp+18h] [ebp-114h]
  int v9; // [esp+1Ch] [ebp-110h]
  int v10; // [esp+20h] [ebp-10Ch]
  int v11; // [esp+24h] [ebp-108h]
  int v12; // [esp+28h] [ebp-104h]
  char __dst[256]; // [esp+2Ch] [ebp-100h] BYREF

  v10 = 805306368; /*0x16dcc5*/
  v11 = 134217740; /*0x16dcd1*/
  v12 = 1; /*0x16dcdd*/
  strncpy(__dst, __src, 0x100u); /*0x16dcf0*/
  __dst[255] = 0; /*0x16dcf5*/
  HIBYTE(v4) = 1; /*0x16dcf9*/
  v5 = 292; /*0x16dd00*/
  v6 = 256; /*0x16dd0a*/
  v8 = a1; /*0x16dd14*/
  reply_port = mig_get_reply_port(); /*0x16dd1f*/
  v9 = 200; /*0x16dd25*/
  result = msg_rpc(&v4, 0, 0x20u, 0, 0); /*0x16dd38*/
  if ( result ) /*0x16dd44*/
  {
    if ( result == -202 ) /*0x16dd4c*/
      mig_dealloc_reply_port(v3); /*0x16dd4e*/
  }
  else if ( v9 == 300 ) /*0x16dd6f*/
  {
    if ( v5 == 32 && HIBYTE(v4) == 1 && v10 == 268509186 ) /*0x16dd8d*/
    {
      result = v11; /*0x16dd98*/
      if ( !v11 ) /*0x16dda0*/
        return 0; /*0x16dda2*/
    }
    else
    {
      return -300; /*0x16dd8f*/
    }
  }
  else
  {
    return -301; /*0x16dd71*/
  }
  return result; /*0x16ddaa*/
}
