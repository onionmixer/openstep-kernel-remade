/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1669b0. */
int __cdecl task_priority(int a1, unsigned int a2, int a3)
{
  unsigned int v3; // edx
  int i; // ebx
  int v6; // eax
  unsigned int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  v3 = a2; /*0x1669bc*/
  v8 = 0; /*0x1669bf*/
  if ( !a1 || a2 > 0x1F ) /*0x1669cd*/
    return 4; /*0x1669cf*/
  do /*0x1669ea*/
  {
    while ( *(_DWORD *)a1 ) /*0x1669d8*/
      ; /*0x1669da*/
  }
  while ( _InterlockedExchange((volatile __int32 *)a1, 1) == 1 ); /*0x1669ea*/
  *(_DWORD *)(a1 + 72) = a2; /*0x1669ec*/
  if ( a3 ) /*0x1669f3*/
  {
    for ( i = *(_DWORD *)(a1 + 28); a1 + 28 != i; i = *(_DWORD *)(i + 16) ) /*0x1669fd*/
    {
      v7 = v3; /*0x166a04*/
      v6 = thread_priority(i, v3, 0); /*0x166a07*/
      v3 = v7; /*0x166a0f*/
      if ( v6 ) /*0x166a14*/
        v8 = 5; /*0x166a16*/
    }
  }
  _InterlockedExchange((volatile __int32 *)a1, 0); /*0x166a26*/
  return v8; /*0x166a2e*/
}
