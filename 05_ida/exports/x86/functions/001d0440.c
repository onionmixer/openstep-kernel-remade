/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d0440. */
int __cdecl port_allocate_EXTERNAL(int a1, _DWORD *a2)
{
  int result; // eax
  mach_port_t v3; // [esp+0h] [ebp-34h]
  int v4; // [esp+Ch] [ebp-28h] BYREF
  int v5; // [esp+10h] [ebp-24h]
  int v6; // [esp+14h] [ebp-20h]
  mach_port_t reply_port; // [esp+18h] [ebp-1Ch]
  int v8; // [esp+1Ch] [ebp-18h]
  int v9; // [esp+20h] [ebp-14h]
  int v10; // [esp+24h] [ebp-10h]
  int v11; // [esp+28h] [ebp-Ch]
  int v12; // [esp+2Ch] [ebp-8h]
  int v13; // [esp+30h] [ebp-4h]

  HIBYTE(v4) = 1; /*0x1d0452*/
  v5 = 24; /*0x1d0456*/
  v6 = 256; /*0x1d045d*/
  v8 = a1; /*0x1d0464*/
  reply_port = mig_get_reply_port(); /*0x1d046c*/
  v9 = 2076; /*0x1d046f*/
  result = msg_rpc(&v4, 0, 0x28u, 0, 0); /*0x1d047f*/
  if ( result ) /*0x1d048b*/
  {
    if ( result == -202 ) /*0x1d0493*/
      mig_dealloc_reply_port(v3); /*0x1d0495*/
  }
  else
  {
    if ( v9 != 2176 ) /*0x1d04ae*/
      return -301; /*0x1d04b5*/
    if ( (v5 != 40 || HIBYTE(v4) != 1) && (v5 != 32 || HIBYTE(v4) != 1 || !v11) || v10 != 268509186 ) /*0x1d04da*/
      return -300; /*0x1d04da*/
    result = v11; /*0x1d04dc*/
    if ( v11 ) /*0x1d04e1*/
      return result; /*0x1d04e1*/
    if ( v12 == 268509186 ) /*0x1d04eb*/
    {
      *a2 = v13; /*0x1d04f0*/
      return v11; /*0x1d04f2*/
    }
    else
    {
      return -300; /*0x1d04f8*/
    }
  }
  return result; /*0x1d0500*/
}
