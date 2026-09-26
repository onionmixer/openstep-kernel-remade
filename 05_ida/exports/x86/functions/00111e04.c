/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x111e04. */
int __cdecl ptsread(unsigned __int8 a1, _DWORD *a2)
{
  int v2; // eax
  int v3; // esi
  int v4; // edi
  int v5; // ebx
  _DWORD *posix_proc; // eax
  int v8; // eax
  char v9; // al
  _BYTE *v10; // [esp+Ch] [ebp-4h]

  v2 = 8 * a1; /*0x111e11*/
  v3 = *(_DWORD *)&word_1E56C8[v2 + 4]; /*0x111e19*/
  v10 = *(_BYTE **)&word_1E56C8[v2 + 6]; /*0x111e21*/
  v4 = 0; /*0x111e24*/
  while ( 1 ) /*0x111e26*/
  {
    if ( (*v10 & 0x20) == 0 ) /*0x111e2c*/
    {
      if ( *(_DWORD *)(v3 + 36) ) /*0x111f58*/
        v4 = (*(&off_1DAFF0 + 12 * *(char *)(v3 + 71)))((FILE *)v3, (int)a2); /*0x111f75*/
LABEL_33:
      ptcwakeup(v3, 2); /*0x111f7a*/
      return v4; /*0x111f82*/
    }
    while ( *(_DWORD *)(active_u + 360) == v3 ) /*0x111eaf*/
    {
      v5 = *(_DWORD *)active_u; /*0x111e34*/
      if ( *(_WORD *)(*(_DWORD *)active_u + 46) == *(_WORD *)(v3 + 68) ) /*0x111e3e*/
        break; /*0x111e3e*/
      if ( (*(_BYTE *)(v5 + 22) & 2) != 0 ) /*0x111e44*/
      {
        posix_proc = get_posix_proc(*(__int16 *)(v5 + 48)); /*0x111e4b*/
        if ( (*(_BYTE *)(v5 + 34) & 0x10) != 0 || (*(_BYTE *)(v5 + 30) & 0x10) != 0 || !*(_DWORD *)(posix_proc[4] + 16) ) /*0x111e62*/
          return 5; /*0x111e66*/
      }
      else if ( (*(_BYTE *)(v5 + 34) & 0x10) != 0 /*0x111e7c*/
             || (*(_BYTE *)(v5 + 30) & 0x10) != 0
             || (*(_BYTE *)(v5 + 41) & 0x10) != 0 )
      {
        return 5; /*0x111e83*/
      }
      gsignal((_DWORD *)*(__int16 *)(*(_DWORD *)active_u + 46), (char *)0x15); /*0x111e96*/
      sleep((unsigned int)&lbolt); /*0x111ea2*/
    }
    v8 = *(_DWORD *)(v3 + 12); /*0x111ebb*/
    if ( v8 ) /*0x111ec0*/
    {
      if ( v8 > 1 ) /*0x111f0b*/
      {
        while ( (int)a2[5] > 0 ) /*0x111f17*/
        {
          v9 = getc((FILE *)(v3 + 12)); /*0x111f1e*/
          if ( ureadc(v9, a2) < 0 ) /*0x111f31*/
          {
            v4 = 14; /*0x111f00*/
            break; /*0x111f05*/
          }
          if ( *(int *)(v3 + 12) <= 1 ) /*0x111f37*/
            break; /*0x111f37*/
        }
      }
      if ( *(_DWORD *)(v3 + 12) == 1 ) /*0x111f3d*/
        getc((FILE *)(v3 + 12)); /*0x111f43*/
      if ( *(_DWORD *)(v3 + 12) ) /*0x111f4b*/
        return v4; /*0x111f53*/
      goto LABEL_33; /*0x111f4f*/
    }
    if ( (*(_BYTE *)(v3 + 65) & 0x20) != 0 ) /*0x111ec6*/
      break; /*0x111ec6*/
    sleep(v3 + 12); /*0x111ef2*/
  }
  if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x111ed3*/
    return 11; /*0x111ed5*/
  else
    return 35; /*0x111ee0*/
}
