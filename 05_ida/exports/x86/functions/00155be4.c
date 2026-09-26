/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155be4. */
int __cdecl port_translate_compat(unsigned int a1, unsigned int a2, volatile __int32 **a3)
{
  int v3; // edx
  volatile __int32 *v5; // edx
  int v6; // [esp+Ch] [ebp-Ch] BYREF
  int v7; // [esp+10h] [ebp-8h] BYREF
  int *v8; // [esp+14h] [ebp-4h] BYREF

  if ( ipc_right_lookup_write(a1, a2, &v8) || ipc_right_info(a1, a2, v8, &v7, &v6) ) /*0x155c16*/
    return 4; /*0x155c45*/
  v3 = v7; /*0x155c1f*/
  if ( (v7 & 0x20000) == 0 ) /*0x155c28*/
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x155c2c*/
    if ( (v3 & 0x170000) != 0 ) /*0x155c35*/
      return 7; /*0x155c3c*/
    return 4; /*0x155c35*/
  }
  v5 = (volatile __int32 *)v8[1]; /*0x155c4b*/
  do /*0x155c62*/
  {
    while ( *v5 ) /*0x155c50*/
      ; /*0x155c52*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x155c62*/
  _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x155c66*/
  *a3 = v5; /*0x155c69*/
  return 0; /*0x155c70*/
}
