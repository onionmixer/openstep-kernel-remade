/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x117258. */
int __cdecl socketpair(int a1, int a2, int a3, int *a4)
{
  int *v4; // edi
  int result; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // ebx
  int v10; // [esp+Ch] [ebp-10h] BYREF
  int v11; // [esp+10h] [ebp-Ch]
  char *v12; // [esp+14h] [ebp-8h] BYREF
  char *v13; // [esp+18h] [ebp-4h] BYREF

  v4 = *(int **)(dword_1E875C + 36); /*0x117266*/
  if ( !useracc(v4[3], 8, 0) ) /*0x117271*/
  {
    result = dword_1E875C; /*0x11727d*/
    *(_BYTE *)(dword_1E875C + 104) = 14; /*0x117282*/
    return result; /*0x117286*/
  }
  *(_BYTE *)(dword_1E875C + 104) = socreate(*v4, &v13, v4[1], v4[2]); /*0x1172a7*/
  result = dword_1E875C; /*0x1172aa*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x1172b2*/
  {
    *(_BYTE *)(dword_1E875C + 104) = socreate(*v4, &v12, v4[1], v4[2]); /*0x1172d7*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x1172e2*/
    {
      v6 = falloc(); /*0x1172ec*/
      v7 = v6; /*0x1172f1*/
      if ( v6 ) /*0x1172f5*/
      {
        v10 = *(_DWORD *)(dword_1E875C + 96); /*0x117303*/
        *(_DWORD *)(v6 + 8) = 3; /*0x117306*/
        *(_WORD *)(v6 + 12) = 2; /*0x11730d*/
        *(_DWORD *)(v6 + 20) = &socketops; /*0x117313*/
        *(_DWORD *)(v6 + 24) = v13; /*0x11731d*/
        *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * *(_DWORD *)(dword_1E875C + 96)) = v6; /*0x117334*/
        v8 = falloc(); /*0x117337*/
        v9 = v8; /*0x11733c*/
        if ( v8 ) /*0x117340*/
        {
          *(_DWORD *)(v8 + 8) = 3; /*0x117346*/
          *(_WORD *)(v8 + 12) = 2; /*0x11734d*/
          *(_DWORD *)(v8 + 20) = &socketops; /*0x117353*/
          *(_DWORD *)(v8 + 24) = v12; /*0x11735d*/
          *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * *(_DWORD *)(dword_1E875C + 96)) = v8; /*0x117374*/
          v11 = *(_DWORD *)(dword_1E875C + 96); /*0x11737f*/
          *(_BYTE *)(dword_1E875C + 104) = soconnect2((int)v13, (int)v12); /*0x117396*/
          if ( !*(_BYTE *)(dword_1E875C + 104) /*0x1173cc*/
            && (v4[1] != 2 || (*(_BYTE *)(dword_1E875C + 104) = soconnect2((int)v12, (int)v13)) == 0) )
          {
            *(_DWORD *)(dword_1E875C + 96) = 0; /*0x1173d7*/
            return copyout(&v10, v4[3], 8); /*0x1173ed*/
          }
          *(_WORD *)(v9 + 14) = 0; /*0x1173f0*/
          *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v11) = 0; /*0x117404*/
        }
        *(_WORD *)(v7 + 14) = 0; /*0x11740b*/
        *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v10) = 0; /*0x11741f*/
      }
      soclose((int)v12); /*0x11742a*/
    }
    return soclose((int)v13); /*0x117436*/
  }
  return result; /*0x11743e*/
}
