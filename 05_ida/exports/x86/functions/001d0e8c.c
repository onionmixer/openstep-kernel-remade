/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d0e8c. */
int __cdecl vm_write_EXTERNAL(int a1, int a2, int a3, int a4)
{
  int result; // eax
  mach_port_t v5; // [esp+0h] [ebp-3Ch]
  int v6; // [esp+Ch] [ebp-30h] BYREF
  int v7; // [esp+10h] [ebp-2Ch]
  int v8; // [esp+14h] [ebp-28h]
  mach_port_t reply_port; // [esp+18h] [ebp-24h]
  int v10; // [esp+1Ch] [ebp-20h]
  int v11; // [esp+20h] [ebp-1Ch]
  int v12; // [esp+24h] [ebp-18h]
  int v13; // [esp+28h] [ebp-14h]
  int v14; // [esp+2Ch] [ebp-10h]
  int v15; // [esp+30h] [ebp-Ch]
  int v16; // [esp+34h] [ebp-8h]
  int v17; // [esp+38h] [ebp-4h]

  v12 = 268509186; /*0x1d0eaa*/
  v13 = a2; /*0x1d0ead*/
  v14 = 0x20000000; /*0x1d0eb6*/
  v15 = 524297; /*0x1d0ebf*/
  v17 = a3; /*0x1d0ecb*/
  v16 = a4; /*0x1d0ece*/
  HIBYTE(v6) = 0; /*0x1d0ed1*/
  v7 = 48; /*0x1d0ed5*/
  v8 = 256; /*0x1d0edc*/
  v10 = a1; /*0x1d0ee3*/
  reply_port = mig_get_reply_port(); /*0x1d0eeb*/
  v11 = 2027; /*0x1d0eee*/
  result = msg_rpc(&v6, 0, 0x20u, 0, 0); /*0x1d0efe*/
  if ( result ) /*0x1d0f0a*/
  {
    if ( result == -202 ) /*0x1d0f12*/
      mig_dealloc_reply_port(v5); /*0x1d0f14*/
  }
  else if ( v11 == 2127 ) /*0x1d0f2e*/
  {
    if ( v7 == 32 && HIBYTE(v6) == 1 && v12 == 268509186 ) /*0x1d0f4a*/
    {
      result = v13; /*0x1d0f54*/
      if ( !v13 ) /*0x1d0f59*/
        return 0; /*0x1d0f5b*/
    }
    else
    {
      return -300; /*0x1d0f4c*/
    }
  }
  else
  {
    return -301; /*0x1d0f30*/
  }
  return result; /*0x1d0f60*/
}
