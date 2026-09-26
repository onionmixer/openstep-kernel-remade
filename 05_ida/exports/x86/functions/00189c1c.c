/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x189c1c. */
int __cdecl copywithin(char *a1, char *a2, signed int a3)
{
  int v3; // ebx
  int v5; // edx
  int v6; // edx
  int v7; // eax
  char *v8; // [esp+14h] [ebp+8h]
  char *v9; // [esp+18h] [ebp+Ch]

  v3 = a3; /*0x189c22*/
  *(_DWORD *)(active_threads + 116) = &loc_189CD0; /*0x189c2a*/
  if ( a3 <= 15 ) /*0x189c34*/
  {
    qmemcpy(a2, a1, a3); /*0x189c3e*/
    return 0; /*0x189c42*/
  }
  v5 = (unsigned __int8)a1 & 3; /*0x189c4b*/
  if ( ((unsigned __int8)a1 & 3) != 0 ) /*0x189c4e*/
  {
    qmemcpy(a2, a1, 4 - v5); /*0x189c5f*/
    v3 = a3 - (4 - v5); /*0x189c61*/
    a2 += 4 - v5; /*0x189c63*/
    a1 += 4 - v5; /*0x189c66*/
  }
  qmemcpy(a2, a1, 4 * (v3 >> 2)); /*0x189c76*/
  v6 = v3 & 3; /*0x189c7a*/
  if ( (v3 & 3) != 0 ) /*0x189c7d*/
  {
    v7 = v3; /*0x189c7f*/
    LOBYTE(v7) = v3 & 0xFC; /*0x189c81*/
    v8 = &a1[v7]; /*0x189c83*/
    v9 = &a2[v7]; /*0x189c86*/
    if ( v6 == 2 ) /*0x189c8c*/
    {
LABEL_12:
      v9[1] = v8[1]; /*0x189ca9*/
LABEL_13:
      *v9 = *v8; /*0x189cb5*/
      goto LABEL_14; /*0x189cbd*/
    }
    if ( (v3 & 3u) <= 2 ) /*0x189c8e*/
    {
      if ( v6 != 1 ) /*0x189c93*/
        goto LABEL_14; /*0x189c93*/
      goto LABEL_13; /*0x189c93*/
    }
    if ( v6 == 3 ) /*0x189c9b*/
    {
      v9[2] = v8[2]; /*0x189ca6*/
      goto LABEL_12; /*0x189ca6*/
    }
  }
LABEL_14:
  *(_DWORD *)(active_threads + 116) = 0; /*0x189cbf*/
  return 0; /*0x189ce4*/
}
