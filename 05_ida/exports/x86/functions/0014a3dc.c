/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14a3dc. */
__int32 __cdecl ipc_marequest_rename(unsigned int a1, unsigned int a2, unsigned int a3)
{
  int v3; // edx
  _DWORD *v4; // eax
  _DWORD *i; // ecx
  int v6; // edx

  v3 = ipc_marequest_table + 8 * (ipc_marequest_mask & ((unsigned __int8)a2 + (a2 >> 8) + (a1 >> 4))); /*0x14a407*/
  do /*0x14a41e*/
  {
    while ( *(_DWORD *)v3 ) /*0x14a40c*/
      ; /*0x14a40e*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v3, 1) == 1 ); /*0x14a41e*/
  v4 = (_DWORD *)(v3 + 4); /*0x14a420*/
  for ( i = *(_DWORD **)(v3 + 4); i; i = (_DWORD *)i[3] ) /*0x14a428*/
  {
    if ( *i == a1 && i[1] == a2 ) /*0x14a436*/
      break; /*0x14a436*/
    v4 = i + 3; /*0x14a438*/
  }
  *v4 = i[3]; /*0x14a445*/
  _InterlockedExchange((volatile __int32 *)v3, 0); /*0x14a449*/
  i[1] = a3; /*0x14a44b*/
  v6 = ipc_marequest_table + 8 * (ipc_marequest_mask & ((unsigned __int8)a3 + (a3 >> 8) + (a1 >> 4))); /*0x14a46d*/
  do /*0x14a482*/
  {
    while ( *(_DWORD *)v6 ) /*0x14a470*/
      ; /*0x14a472*/
  }
  while ( _InterlockedExchange((volatile __int32 *)v6, 1) == 1 ); /*0x14a482*/
  i[3] = *(_DWORD *)(v6 + 4); /*0x14a487*/
  *(_DWORD *)(v6 + 4) = i; /*0x14a48a*/
  return _InterlockedExchange((volatile __int32 *)v6, 0); /*0x14a494*/
}
