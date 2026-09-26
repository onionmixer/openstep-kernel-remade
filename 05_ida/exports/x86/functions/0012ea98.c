/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12ea98. */
int *__cdecl sub_12EA98(int a1, int a2)
{
  int v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // edx
  unsigned int j; // eax
  int v7; // ecx
  int v8; // ebx
  unsigned int i; // eax
  int v11; // ecx
  int v12; // ebx
  __int16 *v13; // [esp+Ch] [ebp-14h]
  __int16 *v14; // [esp+10h] [ebp-10h]
  int *v15; // [esp+14h] [ebp-Ch]
  int *v16; // [esp+18h] [ebp-8h]
  _DWORD *v17; // [esp+1Ch] [ebp-4h]

  if ( (*(_BYTE *)(a1 + 20) & 9) == 8 ) /*0x12eaae*/
    v2 = 1; /*0x12eab0*/
  else
    v2 = *(_DWORD *)(a1 + 48); /*0x12eac7*/
  ++dword_1EEF84; /*0x12eaca*/
  v17 = &chtable; /*0x12ead0*/
  if ( &chtable >= (_UNKNOWN *)((char *)&chtable + 12 * MAXCLIENTS) )
  {
LABEL_28:
    ++cltoomany; /*0x12ec68*/
    v16 = (int *)clntkudp_create(a1, 100003, 2, v2, a2); /*0x12ec80*/
    if ( !v16 ) /*0x12ec88*/
      panic(aClgetNullClien_0); /*0x12ec8f*/
    (*(void (__cdecl **)(int))(*(_DWORD *)(*v16 + 32) + 16))(*v16); /*0x12eca3*/
    for ( i = *(_DWORD *)(a1 + 92); i > 1; i = 0 )
      printf("authget: unknown authflavor %d\n", i);
    v11 = MAXCLIENTS; /*0x12ecb9*/
    while ( 1 ) /*0x12ecca*/
    {
      v12 = 4 * nextunixvictim; /*0x12ecca*/
      v14 = &unixauthtab[4 * nextunixvictim++]; /*0x12ecd7*/
      nextunixvictim %= (unsigned int)MAXCLIENTS; /*0x12ecea*/
      if ( !unixauthtab[v12] ) /*0x12ecf0*/
        break; /*0x12ecf0*/
      if ( --v11 <= 0 ) /*0x12ecfd*/
      {
        v3 = authkern_create(); /*0x12eab8*/
        goto LABEL_40; /*0x12eabd*/
      }
    }
    if ( !*((_DWORD *)v14 + 1) ) /*0x12ed07*/
      *((_DWORD *)v14 + 1) = authkern_create(); /*0x12ed12*/
    unixauthtab[v12] = 1; /*0x12ed15*/
    v3 = *((_DWORD *)v14 + 1); /*0x12ed21*/
LABEL_40:
    *v16 = v3; /*0x12ed40*/
    if ( !v3 ) /*0x12ed47*/
      panic(aClgetNullAuth_0); /*0x12ed4e*/
    if ( (*(_BYTE *)(a1 + 20) & 5) == 5 ) /*0x12ed60*/
      clntkudp_interruptable(v16, 1); /*0x12ed68*/
    return v16; /*0x12ed6d*/
  }
  else
  {
    v15 = &dword_1EEF38; /*0x12eaef*/
    while ( *(v15 - 1) ) /*0x12eaff*/
    {
      v15 += 3; /*0x12ec48*/
      v17 += 3; /*0x12ec4c*/
      if ( v17 >= (_DWORD *)&chtable + 3 * MAXCLIENTS ) /*0x12ec62*/
        goto LABEL_28; /*0x12ec62*/
    }
    *(v15 - 1) = 1; /*0x12eb05*/
    if ( *v15 ) /*0x12eb0c*/
    {
      clntkudp_init(*v15, a1, v2, a2); /*0x12eb63*/
    }
    else
    {
      v4 = clntkudp_create(a1, 100003, 2, v2, a2); /*0x12eb1f*/
      *v15 = v4; /*0x12eb24*/
      if ( !v4 ) /*0x12eb2b*/
        panic(aClgetNullClien); /*0x12eb32*/
      (*(void (__cdecl **)(_DWORD))(*(_DWORD *)(*(_DWORD *)*v15 + 32) + 16))(*(_DWORD *)*v15); /*0x12eb48*/
    }
    for ( j = *(_DWORD *)(a1 + 92); j > 1; j = 0 )
      printf("authget: unknown authflavor %d\n", j);
    v7 = MAXCLIENTS; /*0x12eb7d*/
    while ( 1 ) /*0x12eb8e*/
    {
      v8 = 4 * nextunixvictim; /*0x12eb8e*/
      v13 = &unixauthtab[4 * nextunixvictim++]; /*0x12eb9b*/
      nextunixvictim %= (unsigned int)MAXCLIENTS; /*0x12ebae*/
      if ( !unixauthtab[v8] ) /*0x12ebb4*/
        break; /*0x12ebb4*/
      if ( --v7 <= 0 ) /*0x12ebc1*/
      {
        v5 = authkern_create(); /*0x12eb55*/
        goto LABEL_22; /*0x12eb57*/
      }
    }
    if ( !*((_DWORD *)v13 + 1) ) /*0x12ebcb*/
      *((_DWORD *)v13 + 1) = authkern_create(); /*0x12ebd6*/
    unixauthtab[v8] = 1; /*0x12ebd9*/
    v5 = *((_DWORD *)v13 + 1); /*0x12ebe5*/
LABEL_22:
    *(_DWORD *)*v15 = v5; /*0x12ec04*/
    if ( !*(_DWORD *)*v15 ) /*0x12ec0d*/
      panic(aClgetNullAuth); /*0x12ec17*/
    ++*v17; /*0x12ec22*/
    if ( (*(_BYTE *)(a1 + 20) & 5) == 5 ) /*0x12ec2e*/
      clntkudp_interruptable(*v15, 1); /*0x12ec38*/
    return (int *)*v15; /*0x12ec40*/
  }
}
