/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1084d0. */
int __cdecl setpgid(pid_t a1, pid_t a2)
{
  int *v2; // esi
  int result; // eax
  int v4; // ebx
  _DWORD *posix_proc; // edi
  int v6; // eax
  int v7; // edx
  _DWORD *v8; // edx
  _DWORD *v9; // [esp+Ch] [ebp-4h]

  v2 = *(int **)(dword_1E875C + 36); /*0x1084df*/
  result = active_u; /*0x1084e2*/
  v4 = *(_DWORD *)active_u; /*0x1084e7*/
  if ( v2[1] < 0 ) /*0x1084ed*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x1084ef*/
    return result; /*0x1084f3*/
  }
  posix_proc = get_posix_proc(*(__int16 *)(v4 + 48)); /*0x108502*/
  if ( !*v2 || *v2 == *(__int16 *)(v4 + 48) ) /*0x108513*/
  {
    v9 = posix_proc; /*0x108570*/
  }
  else
  {
    v6 = pfind(*v2); /*0x108516*/
    v4 = v6; /*0x10851b*/
    if ( !v6 || !inferior(v6) ) /*0x108525*/
    {
      result = dword_1E875C; /*0x108531*/
      *(_BYTE *)(dword_1E875C + 104) = 3; /*0x108536*/
      return result; /*0x10853a*/
    }
    v9 = get_posix_proc(*(__int16 *)(v4 + 48)); /*0x10854a*/
    if ( *(_DWORD *)(v9[4] + 8) != *(_DWORD *)(posix_proc[4] + 8) ) /*0x10855c*/
      goto LABEL_18; /*0x10855c*/
    if ( *(int *)(v4 + 40) < 0 ) /*0x108562*/
    {
      result = dword_1E875C; /*0x108564*/
      *(_BYTE *)(dword_1E875C + 104) = 13; /*0x108569*/
      return result; /*0x10856d*/
    }
  }
  if ( *(_DWORD *)(*(_DWORD *)(v9[4] + 8) + 4) == v4 ) /*0x10857f*/
  {
LABEL_18:
    result = dword_1E875C; /*0x1085b6*/
    *(_BYTE *)(dword_1E875C + 104) = 1; /*0x1085bb*/
    return result; /*0x1085bf*/
  }
  v7 = v2[1]; /*0x108581*/
  if ( v7 ) /*0x108586*/
  {
    if ( v7 == *(__int16 *)(v4 + 48) ) /*0x10859a*/
      goto LABEL_19; /*0x10859a*/
    v8 = pgfind(v2[1]); /*0x1085a2*/
    if ( v8 ) /*0x1085a9*/
    {
      if ( v8[2] == *(_DWORD *)(posix_proc[4] + 8) ) /*0x1085b4*/
        goto LABEL_19; /*0x1085b4*/
    }
    goto LABEL_18; /*0x1085b4*/
  }
  v2[1] = *(__int16 *)(v4 + 48); /*0x10858c*/
LABEL_19:
  LOWORD(result) = enterpgrp(v4, v2[1], 0); /*0x1085c4*/
  return result; /*0x1085d3*/
}
