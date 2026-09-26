/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d08a8. */
int __cdecl thread_get_special_port_EXTERNAL(int a1, int a2, _DWORD *a3)
{
  int result; // eax
  mach_port_t v4; // [esp+0h] [ebp-34h]
  int v5; // [esp+Ch] [ebp-28h] BYREF
  int v6; // [esp+10h] [ebp-24h]
  int v7; // [esp+14h] [ebp-20h]
  mach_port_t reply_port; // [esp+18h] [ebp-1Ch]
  int v9; // [esp+1Ch] [ebp-18h]
  int v10; // [esp+20h] [ebp-14h]
  int v11; // [esp+24h] [ebp-10h]
  int v12; // [esp+28h] [ebp-Ch]
  int v13; // [esp+2Ch] [ebp-8h]
  int v14; // [esp+30h] [ebp-4h]

  v11 = 268509186; /*0x1d08c3*/
  v12 = a2; /*0x1d08c6*/
  HIBYTE(v5) = 1; /*0x1d08c9*/
  v6 = 32; /*0x1d08cd*/
  v7 = 256; /*0x1d08d4*/
  v9 = a1; /*0x1d08db*/
  reply_port = mig_get_reply_port(); /*0x1d08e3*/
  v10 = 2067; /*0x1d08e6*/
  result = msg_rpc(&v5, 0, 0x28u, 0, 0); /*0x1d08f6*/
  if ( result ) /*0x1d0902*/
  {
    if ( result == -202 ) /*0x1d090a*/
      mig_dealloc_reply_port(v4); /*0x1d090c*/
  }
  else
  {
    if ( v10 != 2167 ) /*0x1d0926*/
      return -301; /*0x1d092d*/
    if ( (v6 != 40 || HIBYTE(v5)) && (v6 != 32 || HIBYTE(v5) != 1 || !v12) || v11 != 268509186 ) /*0x1d0951*/
      return -300; /*0x1d0951*/
    result = v12; /*0x1d0953*/
    if ( v12 ) /*0x1d0958*/
      return result; /*0x1d0958*/
    if ( v13 == 268509190 ) /*0x1d0962*/
    {
      *a3 = v14; /*0x1d0967*/
      return v12; /*0x1d0969*/
    }
    else
    {
      return -300; /*0x1d0970*/
    }
  }
  return result; /*0x1d0978*/
}
