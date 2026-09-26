/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17c2c4. */
int __cdecl fake_u(int a1, int a2)
{
  int v2; // ebx
  int v3; // ebx
  volatile __int32 *v4; // esi
  int result; // eax
  int v6; // [esp+Ch] [ebp-14h]
  _DWORD v7[2]; // [esp+10h] [ebp-10h] BYREF
  _DWORD v8[2]; // [esp+18h] [ebp-8h] BYREF

  v6 = *(_DWORD *)(*(_DWORD *)(a2 + 12) + 56); /*0x17c2d6*/
  v2 = *(_DWORD *)(a2 + 132); /*0x17c2d9*/
  bcopy((const void *)(v6 + 8), (void *)(a1 + 8), 0x11u); /*0x17c2ef*/
  bcopy((const void *)(v2 + 4), (void *)(a1 + 28), 0x20u); /*0x17c301*/
  *(_DWORD *)(a1 + 132) = *(_DWORD *)(v6 + 28); /*0x17c30f*/
  bcopy((const void *)(v6 + 48), (void *)(a1 + 160), 0x84u); /*0x17c32a*/
  *(_DWORD *)(a1 + 440) = *(_DWORD *)(v2 + 116); /*0x17c335*/
  *(_DWORD *)(a1 + 1744) = *(_DWORD *)(v6 + 360); /*0x17c344*/
  *(_WORD *)(a1 + 1748) = *(_WORD *)(v6 + 364); /*0x17c357*/
  qmemcpy((void *)(a1 + 1752), (const void *)(v6 + 368), 0x48u); /*0x17c376*/
  v3 = splsched(); /*0x17c380*/
  v4 = (volatile __int32 *)(a2 + 32); /*0x17c385*/
  do /*0x17c39a*/
  {
    while ( *v4 ) /*0x17c388*/
      ; /*0x17c38a*/
  }
  while ( _InterlockedExchange(v4, 1) == 1 ); /*0x17c39a*/
  thread_read_times((_DWORD *)a2, v8, v7); /*0x17c3a8*/
  _InterlockedExchange((volatile __int32 *)(a2 + 32), 0); /*0x17c3b5*/
  result = splx(v3); /*0x17c3b9*/
  *(_DWORD *)(a1 + 1760) = v7[0]; /*0x17c3c4*/
  *(_DWORD *)(a1 + 1764) = v7[1]; /*0x17c3cd*/
  *(_DWORD *)(a1 + 1752) = v8[0]; /*0x17c3d6*/
  *(_DWORD *)(a1 + 1756) = v8[1]; /*0x17c3df*/
  qmemcpy((void *)(a1 + 1824), (const void *)(v6 + 440), 0x48u); /*0x17c3fd*/
  return result; /*0x17c402*/
}
