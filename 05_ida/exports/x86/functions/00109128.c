/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x109128. */
int __cdecl sigvec(int a1, sigvec *a2, sigvec *a3)
{
  int v3; // ebx
  unsigned int v4; // edx
  int result; // eax
  int v6; // edx
  char v7; // dl
  int *v8; // [esp+Ch] [ebp-10h]
  _DWORD v9[2]; // [esp+10h] [ebp-Ch] BYREF
  int v10; // [esp+18h] [ebp-4h]

  v8 = *(int **)(dword_1E875C + 36); /*0x109139*/
  v3 = *v8; /*0x10913c*/
  v4 = *v8 - 1; /*0x10913e*/
  if ( v4 > 0x1E || v3 == 9 || v3 == 17 ) /*0x10914e*/
  {
    result = dword_1E875C; /*0x109150*/
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x109155*/
  }
  else
  {
    if ( !v8[2] ) /*0x109166*/
      goto LABEL_9; /*0x109166*/
    v9[0] = *(_DWORD *)(active_u + 4 * v3 + 48); /*0x109175*/
    v9[1] = *(_DWORD *)(active_u + 4 * v3 + 180); /*0x10917f*/
    v6 = 1 << v4; /*0x10918b*/
    v10 = (v6 & *(_DWORD *)(active_u + 316)) != 0; /*0x10919c*/
    if ( (v6 & *(_DWORD *)(active_u + 320)) != 0 ) /*0x1091a9*/
      LOBYTE(v10) = v10 | 2; /*0x1091ab*/
    *(_BYTE *)(dword_1E875C + 104) = copyout(v9, v8[2], 12); /*0x1091c5*/
    result = dword_1E875C; /*0x1091c8*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x1091d0*/
    {
LABEL_9:
      result = v8[1]; /*0x1091d9*/
      if ( result ) /*0x1091de*/
      {
        v7 = copyin(result, v9, 12); /*0x1091e9*/
        result = dword_1E875C; /*0x1091eb*/
        *(_BYTE *)(dword_1E875C + 104) = v7; /*0x1091f0*/
        if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x1091fc*/
        {
          if ( v3 == 19 && v9[0] == 1 && (result = *(_DWORD *)active_u, (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) == 0) ) /*0x109217*/
          {
            *(_BYTE *)(dword_1E875C + 104) = 22; /*0x109219*/
          }
          else
          {
            setsigvec(v3, v9); /*0x109222*/
            result = active_u; /*0x109227*/
            *(_DWORD *)(active_u + 312) = *(_DWORD *)(*(_DWORD *)dword_1E875C + 36); /*0x109237*/
          }
        }
      }
    }
  }
  return result; /*0x109240*/
}
