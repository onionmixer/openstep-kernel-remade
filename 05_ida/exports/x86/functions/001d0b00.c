/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d0b00. */
int __cdecl vm_read_EXTERNAL(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  int result; // eax
  mach_port_t v6; // [esp+0h] [ebp-3Ch]
  int v7; // [esp+Ch] [ebp-30h] BYREF
  int v8; // [esp+10h] [ebp-2Ch]
  int v9; // [esp+14h] [ebp-28h]
  mach_port_t reply_port; // [esp+18h] [ebp-24h]
  int v11; // [esp+1Ch] [ebp-20h]
  int v12; // [esp+20h] [ebp-1Ch]
  int v13; // [esp+24h] [ebp-18h]
  int v14; // [esp+28h] [ebp-14h]
  int v15; // [esp+2Ch] [ebp-10h]
  int v16; // [esp+30h] [ebp-Ch]
  int v17; // [esp+34h] [ebp-8h]
  int v18; // [esp+38h] [ebp-4h]

  v13 = 268509186; /*0x1d0b18*/
  v14 = a2; /*0x1d0b1b*/
  v15 = 268509186; /*0x1d0b24*/
  v16 = a3; /*0x1d0b2a*/
  HIBYTE(v7) = 1; /*0x1d0b2d*/
  v8 = 40; /*0x1d0b31*/
  v9 = 256; /*0x1d0b38*/
  v11 = a1; /*0x1d0b3f*/
  reply_port = mig_get_reply_port(); /*0x1d0b47*/
  v12 = 2026; /*0x1d0b4a*/
  result = msg_rpc(&v7, 0, 0x30u, 0, 0); /*0x1d0b5a*/
  if ( result ) /*0x1d0b66*/
  {
    if ( result == -202 ) /*0x1d0b6e*/
      mig_dealloc_reply_port(v6); /*0x1d0b70*/
  }
  else
  {
    if ( v12 != 2126 ) /*0x1d0b8a*/
      return -301; /*0x1d0b91*/
    if ( (v8 != 48 || HIBYTE(v7)) && (v8 != 32 || HIBYTE(v7) != 1 || !v14) || v13 != 268509186 ) /*0x1d0bb5*/
      return -300; /*0x1d0bb5*/
    result = v14; /*0x1d0bb7*/
    if ( v14 ) /*0x1d0bbc*/
      return result; /*0x1d0bbc*/
    if ( (HIBYTE(v15) & 0x30) == 0x20 && v16 == 524297 ) /*0x1d0bce*/
    {
      *a4 = v18; /*0x1d0bde*/
      *a5 = v17; /*0x1d0be6*/
      return v14; /*0x1d0be8*/
    }
    else
    {
      return -300; /*0x1d0bd0*/
    }
  }
  return result; /*0x1d0bee*/
}
