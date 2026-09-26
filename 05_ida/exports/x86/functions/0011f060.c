/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11f060. */
int __cdecl ifioctl(int a1, int a2, _DWORD *a3)
{
  _BYTE *v4; // esi
  int i; // ebx
  int v6; // esi
  int j; // ebx
  int v8; // eax
  int v9; // [esp+10h] [ebp-Ch]
  int v10; // [esp+14h] [ebp-8h]

  if ( a2 == -2145097440 ) /*0x11f072*/
  {
LABEL_9:
    if ( !suser() ) /*0x11f0af*/
      return *(char *)(dword_1E875C + 104); /*0x11f0af*/
    return arpioctl(a2, a3); /*0x11f0bf*/
  }
  if ( a2 <= -2145097440 ) /*0x11f074*/
  {
    if ( a2 != -2145097442 ) /*0x11f07c*/
      goto LABEL_11; /*0x11f07c*/
    goto LABEL_9; /*0x11f07c*/
  }
  if ( a2 == -1073190636 ) /*0x11f086*/
    return ifconf(-1073190636, a3); /*0x11f0a2*/
  if ( a2 == -1071355617 ) /*0x11f08e*/
    return arpioctl(a2, a3); /*0x11f08e*/
LABEL_11:
  v4 = a3; /*0x11f0c4*/
  if ( a3 < a3 + 4 ) /*0x11f0d4*/
  {
    while ( *v4 ) /*0x11f0dc*/
    {
      if ( (unsigned __int8)(*v4 - 48) > 9u && ++v4 < (_BYTE *)a3 + 16 ) /*0x11f0e7*/
        continue; /*0x11f0e7*/
      goto LABEL_15; /*0x11f0e7*/
    }
    return 6; /*0x11f0dc*/
  }
LABEL_15:
  if ( !*v4 || v4 == (_BYTE *)(a3 + 4) ) /*0x11f0f7*/
    return 6; /*0x11f0f7*/
  v10 = (char)*v4 - 48; /*0x11f0ff*/
  for ( i = ifnet; i; i = *(_DWORD *)(i + 92) ) /*0x11f10a*/
  {
    if ( !bcmp(*(const void **)i, a3, v4 - (_BYTE *)a3) && *(_DWORD *)(i + 20) == 4096 && v10 == *(__int16 *)(i + 8) ) /*0x11f135*/
      break; /*0x11f135*/
  }
  v6 = i; /*0x11f13e*/
  if ( !i ) /*0x11f142*/
    return 6; /*0x11f149*/
  if ( a2 == -2145359491 ) /*0x11f156*/
    goto LABEL_52; /*0x11f156*/
  if ( a2 > -2145359491 ) /*0x11f15c*/
  {
    if ( a2 == -1071617769 ) /*0x11f1a6*/
    {
      a3[4] = *(_DWORD *)(i + 16); /*0x11f1fa*/
      return 0; /*0x11f1fd*/
    }
    if ( a2 > -1071617769 ) /*0x11f1a8*/
    {
      if ( a2 != -1071617668 && a2 != -1071617666 ) /*0x11f1d6*/
        goto LABEL_58; /*0x11f1d6*/
    }
    else if ( a2 != -2145359489 ) /*0x11f1b0*/
    {
      if ( a2 != -1071617775 ) /*0x11f1bc*/
        goto LABEL_58; /*0x11f1bc*/
      *((_WORD *)a3 + 8) = *(_WORD *)(i + 12); /*0x11f1eb*/
      return 0; /*0x11f1ef*/
    }
LABEL_52:
    if ( *(_DWORD *)(i + 56) ) /*0x11f29c*/
      return if_ioctl(i, a2, a3); /*0x11f2a0*/
    return 45; /*0x11f2a0*/
  }
  if ( a2 == -2145359592 ) /*0x11f164*/
  {
    if ( !suser() ) /*0x11f28f*/
      return *(char *)(dword_1E875C + 104); /*0x11f28f*/
    *(_DWORD *)(i + 16) = a3[4]; /*0x11f297*/
    return 0; /*0x11f300*/
  }
  if ( a2 > -2145359592 ) /*0x11f16a*/
  {
    if ( a2 > -2145359566 || a2 < -2145359567 ) /*0x11f192*/
      goto LABEL_58; /*0x11f192*/
    if ( !suser() ) /*0x11f2b0*/
      return *(char *)(dword_1E875C + 104); /*0x11f2b7*/
    if ( *(_DWORD *)(i + 56) ) /*0x11f2c4*/
      return if_ioctl(i, a2, a3); /*0x11f2ad*/
    return 45; /*0x11f2e7*/
  }
  if ( a2 == -2145359600 ) /*0x11f172*/
  {
    if ( suser() ) /*0x11f204*/
    {
      if ( (*(_BYTE *)(i + 12) & 1) != 0 && (a3[4] & 1) == 0 ) /*0x11f21e*/
      {
        v9 = splimp(); /*0x11f225*/
        *(_BYTE *)(i + 12) &= 0xBEu; /*0x11f228*/
        for ( j = *(_DWORD *)(i + 24); j; j = *(_DWORD *)(j + 36) ) /*0x11f231*/
          pfctlinput(0, (sockaddr *)j); /*0x11f237*/
        if_qflush((int *)(v6 + 28)); /*0x11f24a*/
        splx(v9); /*0x11f256*/
      }
      *(_WORD *)(v6 + 12) = *(_WORD *)(v6 + 12) & 0xC852 | a3[4] & 0x37AD; /*0x11f275*/
      if_ioctl(v6, -2145359600, a3); /*0x11f27f*/
      return 0; /*0x11f284*/
    }
    return *(char *)(dword_1E875C + 104); /*0x11f2c2*/
  }
LABEL_58:
  v8 = *(_DWORD *)(a1 + 12); /*0x11f2d8*/
  if ( !v8 ) /*0x11f2e0*/
    return 45; /*0x11f2e0*/
  return (*(int (__cdecl **)(int, int, int, _DWORD *, int))(v8 + 28))(a1, 11, a2, a3, i); /*0x11f305*/
}
