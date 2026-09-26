/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a1750. */
void __cdecl PCcallMonitor(int a1, __int16 *a2)
{
  int *v2; // eax
  int v3; // ebx
  unsigned int v4; // edx
  int v5; // edi
  __int16 v6; // cx
  unsigned __int32 v7; // eax

  v2 = *(int **)(*(_DWORD *)(a1 + 40) + 236); /*0x1a175f*/
  v3 = 0; /*0x1a1765*/
  if ( v2 ) /*0x1a1769*/
    v3 = *v2; /*0x1a176b*/
  v4 = *(_DWORD *)(v3 + 132); /*0x1a176d*/
  if ( v4 > 7 ) /*0x1a1776*/
    v5 = 0; /*0x1a1788*/
  else
    v5 = v3 + 132 * v4 + 136; /*0x1a177f*/
  *(_DWORD *)(v3 + 128) = 0; /*0x1a178d*/
  if ( *(_DWORD *)(v5 + 108) ) /*0x1a1797*/
    *(_BYTE *)(v3 + 128) |= 4u; /*0x1a179d*/
  if ( (a2[33] & 2) != 0 ) /*0x1a17a8*/
  {
    *(_BYTE *)(v3 + 128) &= ~1u; /*0x1a17aa*/
    *(_WORD *)(v3 + 112) = a2[40]; /*0x1a17b5*/
    *(_WORD *)(v3 + 116) = a2[38]; /*0x1a17bd*/
    *(_WORD *)(v3 + 120) = a2[42]; /*0x1a17c5*/
    v6 = a2[44]; /*0x1a17c9*/
  }
  else
  {
    *(_BYTE *)(v3 + 128) |= 1u; /*0x1a17d0*/
    *(_WORD *)(v3 + 112) = a2[6]; /*0x1a17db*/
    *(_WORD *)(v3 + 116) = a2[4]; /*0x1a17e3*/
    *(_WORD *)(v3 + 120) = a2[2]; /*0x1a17eb*/
    v6 = *a2; /*0x1a17ef*/
  }
  *(_WORD *)(v3 + 124) = v6; /*0x1a17f2*/
  *(_DWORD *)(v3 + 100) = *((_DWORD *)a2 + 16); /*0x1a17f9*/
  if ( *(_DWORD *)(v5 + 104) ) /*0x1a17fc*/
    *(_DWORD *)(v3 + 100) |= 0x200u; /*0x1a1802*/
  else
    *(_DWORD *)(v3 + 100) &= ~0x200u; /*0x1a180c*/
  *(_DWORD *)(v3 + 100) |= *(_WORD *)(v5 + 112) & 0x7000; /*0x1a181c*/
  *(_WORD *)(v3 + 108) = a2[30]; /*0x1a1823*/
  *(_DWORD *)(v3 + 104) = *((_DWORD *)a2 + 14); /*0x1a182a*/
  *(_WORD *)(v3 + 96) = a2[36]; /*0x1a1831*/
  *(_DWORD *)(v3 + 92) = *((_DWORD *)a2 + 17); /*0x1a1838*/
  *(_DWORD *)(v3 + 88) = *((_DWORD *)a2 + 6); /*0x1a183e*/
  *(_DWORD *)(v3 + 84) = *((_DWORD *)a2 + 5); /*0x1a1844*/
  *(_DWORD *)(v3 + 80) = *((_DWORD *)a2 + 4); /*0x1a184a*/
  *(_DWORD *)(v3 + 76) = *((_DWORD *)a2 + 9); /*0x1a1850*/
  *(_DWORD *)(v3 + 72) = *((_DWORD *)a2 + 10); /*0x1a1856*/
  *(_DWORD *)(v3 + 68) = *((_DWORD *)a2 + 8); /*0x1a185c*/
  *(_DWORD *)(v3 + 64) = *((_DWORD *)a2 + 11); /*0x1a1862*/
  *(_DWORD *)(v5 + 72) = 0; /*0x1a1864*/
  v7 = __readcr0(); /*0x1a186b*/
  LOBYTE(v7) = v7 | 8; /*0x1a186e*/
  __writecr0(v7); /*0x1a1870*/
  PCdeliverTimers(v5); /*0x1a1874*/
  a2[6] = 107; /*0x1a1879*/
  a2[4] = 107; /*0x1a187f*/
  a2[2] = 0; /*0x1a1885*/
  *a2 = 0; /*0x1a188b*/
  a2[30] = 99; /*0x1a1890*/
  *((_DWORD *)a2 + 14) = *(_DWORD *)(v3 + 40); /*0x1a1899*/
  a2[36] = 107; /*0x1a189c*/
  *((_DWORD *)a2 + 17) = *(_DWORD *)(v5 + 36); /*0x1a18a5*/
  *((_DWORD *)a2 + 6) = 0; /*0x1a18a8*/
  *((_DWORD *)a2 + 16) &= 0xFFFDFAFF; /*0x1a18af*/
  thread_exception_return(); /*0x1a18b6*/
}
