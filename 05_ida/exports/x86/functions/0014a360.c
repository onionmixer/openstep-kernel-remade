/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14a360. */
__int32 __cdecl ipc_marequest_cancel(unsigned int a1, unsigned int a2)
{
  int v2; // ecx
  _DWORD *v3; // eax
  _DWORD *i; // edx
  __int32 result; // eax

  v2 = ipc_marequest_table + 8 * (ipc_marequest_mask & ((unsigned __int8)a2 + (a2 >> 8) + (a1 >> 4))); /*0x14a389*/
  do /*0x14a39e*/
  {
    while ( *(_DWORD *)v2 ) /*0x14a38c*/
      ; /*0x14a38e*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v2, 1) == 1 ); /*0x14a39e*/
  v3 = (_DWORD *)(v2 + 4); /*0x14a3a0*/
  for ( i = *(_DWORD **)(v2 + 4); i; i = (_DWORD *)i[3] ) /*0x14a3a8*/
  {
    if ( *i == a1 && i[1] == a2 ) /*0x14a3b3*/
      break; /*0x14a3b3*/
    v3 = i + 3; /*0x14a3b5*/
  }
  *v3 = i[3]; /*0x14a3c2*/
  result = _InterlockedExchange((volatile __int32 *)v2, 0); /*0x14a3c6*/
  i[1] = 0; /*0x14a3c8*/
  return result; /*0x14a3d2*/
}
