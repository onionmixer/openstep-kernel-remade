/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1120ec. */
int __cdecl ptcopen(__int16 a1)
{
  int v2; // eax
  __int16 *v3; // ebx
  __int16 *v4; // eax
  void *v5; // eax
  void *v6; // eax
  int v7; // ebx
  unsigned int v8; // eax
  int v9; // eax

  if ( (unsigned __int8)a1 > 0x1Fu ) /*0x1120fd*/
    return 6; /*0x1120ff*/
  v2 = 8 * (unsigned __int8)a1; /*0x11210d*/
  v3 = &word_1E56C8[v2]; /*0x112110*/
  if ( *(_DWORD *)&word_1E56C8[v2 + 4] ) /*0x112116*/
  {
    v4 = &word_1E56C8[v2]; /*0x11211c*/
  }
  else
  {
    lock_write((int)&pty_alloc_lock); /*0x112125*/
    if ( !*((_DWORD *)v3 + 2) ) /*0x11212d*/
    {
      v5 = (void *)kalloc(0x88u); /*0x112138*/
      *((_DWORD *)v3 + 2) = v5; /*0x11213d*/
      bzero(v5, 0x88u); /*0x112146*/
      v6 = (void *)kalloc(0x10u); /*0x11214d*/
      *((_DWORD *)v3 + 3) = v6; /*0x112152*/
      bzero(v6, 0x10u); /*0x112158*/
    }
    lock_done(&pty_alloc_lock); /*0x112165*/
    v4 = v3; /*0x11216a*/
  }
  v7 = *((_DWORD *)v4 + 2); /*0x11216f*/
  if ( *(_DWORD *)(v7 + 36) ) /*0x112172*/
    return 5; /*0x1121d0*/
  *(_DWORD *)(v7 + 36) = ptsstart; /*0x112178*/
  ((void (__stdcall *)(int, int))*(&off_1DB00C + 12 * *(char *)(v7 + 71)))(v7, 1); /*0x112192*/
  v8 = *(_DWORD *)(v7 + 64) & 0xFFBFFFFF; /*0x112197*/
  LOBYTE(v8) = *(_BYTE *)(v7 + 64) | 0x10; /*0x11219c*/
  *(_DWORD *)(v7 + 64) = v8; /*0x11219e*/
  v9 = dword_1E56D4[4 * (unsigned __int8)a1]; /*0x1121a9*/
  *(_DWORD *)v9 = 0; /*0x1121af*/
  *(_BYTE *)(v9 + 12) = 0; /*0x1121b5*/
  *(_BYTE *)(v9 + 13) = 0; /*0x1121b9*/
  *(_DWORD *)(v9 + 8) = 0; /*0x1121bd*/
  *(_DWORD *)(v9 + 4) = 0; /*0x1121c4*/
  return 0; /*0x1121d8*/
}
