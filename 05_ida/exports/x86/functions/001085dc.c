/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1085dc. */
int __cdecl getpriority(int a1, id_t a2)
{
  int *v2; // ecx
  int v3; // ebx
  int v4; // eax
  int v5; // edx
  unsigned int v6; // edx
  int v7; // ecx
  unsigned int v8; // edx
  int v9; // ecx
  int result; // eax

  v2 = *(int **)(dword_1E875C + 36); /*0x1085e5*/
  v3 = 21; /*0x1085e8*/
  v4 = *v2; /*0x1085ed*/
  if ( *v2 == 1 ) /*0x1085f2*/
  {
    if ( !v2[1] ) /*0x108638*/
      v2[1] = *(__int16 *)(*(_DWORD *)active_u + 46); /*0x108649*/
    v6 = allproc; /*0x10864c*/
    if ( allproc ) /*0x108654*/
    {
      v7 = v2[1]; /*0x108656*/
      do /*0x108673*/
      {
        if ( *(__int16 *)(v6 + 46) == v7 && *(char *)(v6 + 21) < v3 ) /*0x10866a*/
          v3 = *(char *)(v6 + 21); /*0x10866c*/
        v6 = *(_DWORD *)(v6 + 8); /*0x10866e*/
      }
      while ( v6 ); /*0x108673*/
    }
  }
  else if ( *v2 > 1 ) /*0x1085f4*/
  {
    if ( v4 != 2 ) /*0x108603*/
      goto LABEL_30; /*0x108603*/
    if ( !v2[1] ) /*0x108678*/
      v2[1] = *(__int16 *)(*(_DWORD *)(active_u + 28) + 2); /*0x10868a*/
    v8 = allproc; /*0x10868d*/
    if ( allproc ) /*0x108695*/
    {
      v9 = v2[1]; /*0x108697*/
      do /*0x1086b3*/
      {
        if ( *(__int16 *)(v8 + 44) == v9 && *(char *)(v8 + 21) < v3 ) /*0x1086aa*/
          v3 = *(char *)(v8 + 21); /*0x1086ac*/
        v8 = *(_DWORD *)(v8 + 8); /*0x1086ae*/
      }
      while ( v8 ); /*0x1086b3*/
    }
  }
  else
  {
    if ( v4 ) /*0x1085f8*/
    {
LABEL_30:
      result = dword_1E875C; /*0x1086b8*/
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x1086bd*/
      return result; /*0x1086c1*/
    }
    if ( v2[1] ) /*0x10860c*/
      v5 = pfind(v2[1]); /*0x108622*/
    else
      v5 = *(_DWORD *)active_u; /*0x108618*/
    if ( v5 ) /*0x108626*/
      v3 = *(char *)(v5 + 21); /*0x10862c*/
  }
  result = dword_1E875C; /*0x1086c9*/
  if ( v3 == 21 ) /*0x1086c7*/
    *(_BYTE *)(dword_1E875C + 104) = 3; /*0x1086ce*/
  else
    *(_DWORD *)(dword_1E875C + 96) = v3; /*0x1086d9*/
  return result; /*0x1086dc*/
}
