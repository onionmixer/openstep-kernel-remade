/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15606c. */
int __cdecl port_set_backlog(unsigned int a1, unsigned int a2, unsigned int a3)
{
  int result; // eax
  int v4; // edx
  volatile __int32 *v5; // edx
  int v6; // [esp+Ch] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-Ch] BYREF
  int *v8; // [esp+14h] [ebp-8h] BYREF
  volatile __int32 *v9; // [esp+18h] [ebp-4h]

  if ( !a1 || a3 - 1 > 0xF || ipc_right_lookup_write(a1, a2, &v8) || ipc_right_info(a1, a2, v8, &v7, &v6) ) /*0x1560b4*/
    return 4; /*0x15608f*/
  v4 = v7; /*0x1560c0*/
  if ( (v7 & 0x20000) != 0 ) /*0x1560c9*/
  {
    v5 = (volatile __int32 *)v8[1]; /*0x1560e7*/
    do /*0x1560fe*/
    {
      while ( *v5 ) /*0x1560ec*/
        ; /*0x1560ee*/
    }
    while ( _InterlockedExchange(v5, 1) == 1 ); /*0x1560fe*/
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x156102*/
    v9 = v5; /*0x156105*/
    result = 0; /*0x156108*/
  }
  else
  {
    _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x1560cd*/
    result = 4; /*0x1560d0*/
    if ( (v4 & 0x170000) != 0 ) /*0x1560db*/
      return 7; /*0x1560e2*/
  }
  if ( !result ) /*0x15610c*/
  {
    ipc_port_set_qlimit((int)v9, a3); /*0x156113*/
    _InterlockedExchange(v9, 0); /*0x15611d*/
    return 0; /*0x15611f*/
  }
  return result; /*0x156124*/
}
