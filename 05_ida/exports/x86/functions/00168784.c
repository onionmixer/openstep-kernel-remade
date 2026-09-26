/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x168784. */
int __cdecl thread_priority(int a1, unsigned int a2, int a3)
{
  int v3; // edi
  volatile __int32 *v5; // edx
  int v6; // [esp+Ch] [ebp-4h]

  v3 = 0; /*0x168793*/
  if ( !a1 || a2 > 0x1F ) /*0x16879c*/
    return 4; /*0x16879e*/
  v6 = splsched(); /*0x1687ad*/
  v5 = (volatile __int32 *)(a1 + 32); /*0x1687b0*/
  do /*0x1687c6*/
  {
    while ( *v5 ) /*0x1687b4*/
      ; /*0x1687b6*/
  }
  while ( _InterlockedExchange(v5, 1) == 1 ); /*0x1687c6*/
  if ( *(_DWORD *)(a1 + 84) >= (signed int)a2 ) /*0x1687cb*/
  {
    if ( *(int *)(a1 + 100) < 0 ) /*0x1687d8*/
    {
      *(_DWORD *)(a1 + 80) = a2; /*0x1687e0*/
      compute_priority((_DWORD *)a1, 1); /*0x1687e6*/
    }
    else
    {
      *(_DWORD *)(a1 + 100) = a2; /*0x1687da*/
    }
    if ( a3 ) /*0x1687f2*/
      *(_DWORD *)(a1 + 84) = a2; /*0x1687f4*/
  }
  else
  {
    v3 = 5; /*0x1687cd*/
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 0); /*0x1687f9*/
  splx(v6); /*0x168800*/
  return v3; /*0x16880a*/
}
