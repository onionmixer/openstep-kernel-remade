/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x111c84. */
int __cdecl ptsopen(__int16 a1, char a2)
{
  int v3; // eax
  __int16 *v4; // ebx
  __int16 *v5; // edi
  void *v6; // eax
  void *v7; // eax
  unsigned int v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // esi

  if ( (unsigned __int8)a1 > 0x1Fu ) /*0x111c96*/
    return 6; /*0x111c9d*/
  v3 = 8 * (unsigned __int8)a1; /*0x111ca5*/
  v4 = &word_1E56C8[v3]; /*0x111ca8*/
  if ( *(_DWORD *)&word_1E56C8[v3 + 4] ) /*0x111cae*/
  {
    v5 = &word_1E56C8[v3]; /*0x111cb4*/
  }
  else
  {
    lock_write((int)&pty_alloc_lock); /*0x111cbd*/
    if ( !*((_DWORD *)v4 + 2) ) /*0x111cc5*/
    {
      v6 = (void *)kalloc(0x88u); /*0x111cd0*/
      *((_DWORD *)v4 + 2) = v6; /*0x111cd5*/
      bzero(v6, 0x88u); /*0x111cde*/
      v7 = (void *)kalloc(0x10u); /*0x111ce5*/
      *((_DWORD *)v4 + 3) = v7; /*0x111cea*/
      bzero(v7, 0x10u); /*0x111cf0*/
    }
    lock_done(&pty_alloc_lock); /*0x111cfd*/
    v5 = v4; /*0x111d02*/
  }
  v8 = *((_DWORD *)v5 + 2); /*0x111d07*/
  *v5 = a1; /*0x111d0a*/
  v9 = *(_DWORD *)(v8 + 64); /*0x111d0d*/
  if ( (v9 & 4) != 0 ) /*0x111d12*/
  {
    if ( (v9 & 0x80u) != 0 && *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) ) /*0x111d20*/
      return 16; /*0x111d2c*/
  }
  else
  {
    ttychars(v8); /*0x111d31*/
    *(_BYTE *)(v8 + 74) = 15; /*0x111d36*/
    *(_BYTE *)(v8 + 73) = 15; /*0x111d3a*/
    *(_DWORD *)(v8 + 60) = 0; /*0x111d3e*/
  }
  if ( *(_DWORD *)(v8 + 36) ) /*0x111d48*/
    *(_BYTE *)(v8 + 64) |= 0x10u; /*0x111d4e*/
  if ( (a2 & 4) != 0 ) /*0x111d58*/
  {
    *(_DWORD *)(v8 + 64) |= 0x8000u; /*0x111d5a*/
  }
  else
  {
    while ( 1 ) /*0x111d74*/
    {
      v10 = *(_DWORD *)(v8 + 64); /*0x111d74*/
      if ( (v10 & 0x10) != 0 ) /*0x111d79*/
        break; /*0x111d79*/
      LOBYTE(v10) = v10 | 2; /*0x111d64*/
      *(_DWORD *)(v8 + 64) = v10; /*0x111d66*/
      sleep(v8); /*0x111d6c*/
    }
  }
  v11 = (*(&linesw + 12 * *(char *)(v8 + 71)))(a1, (FILE *)v8); /*0x111d92*/
  if ( !v11 ) /*0x111d99*/
    *((_BYTE *)v5 + 4) |= 1u; /*0x111d9b*/
  ptcwakeup(v8, 3); /*0x111da2*/
  return v11; /*0x111dac*/
}
