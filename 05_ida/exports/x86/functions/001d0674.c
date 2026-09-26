/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d0674. */
int __cdecl port_set_allocate_EXTERNAL(int a1, _DWORD *a2)
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

  HIBYTE(v4) = 1; /*0x1d0686*/
  v5 = 24; /*0x1d068a*/
  v6 = 256; /*0x1d0691*/
  v8 = a1; /*0x1d0698*/
  reply_port = mig_get_reply_port(); /*0x1d06a0*/
  v9 = 2080; /*0x1d06a3*/
  result = msg_rpc(&v4, 0, 0x28u, 0, 0); /*0x1d06b3*/
  if ( result ) /*0x1d06bf*/
  {
    if ( result == -202 ) /*0x1d06c7*/
      mig_dealloc_reply_port(v3); /*0x1d06c9*/
  }
  else
  {
    if ( v9 != 2180 ) /*0x1d06e2*/
      return -301; /*0x1d06e9*/
    if ( (v5 != 40 || HIBYTE(v4) != 1) && (v5 != 32 || HIBYTE(v4) != 1 || !v11) || v10 != 268509186 ) /*0x1d070e*/
      return -300; /*0x1d070e*/
    result = v11; /*0x1d0710*/
    if ( v11 ) /*0x1d0715*/
      return result; /*0x1d0715*/
    if ( v12 == 268509186 ) /*0x1d071f*/
    {
      *a2 = v13; /*0x1d0724*/
      return v11; /*0x1d0726*/
    }
    else
    {
      return -300; /*0x1d072c*/
    }
  }
  return result; /*0x1d0734*/
}
