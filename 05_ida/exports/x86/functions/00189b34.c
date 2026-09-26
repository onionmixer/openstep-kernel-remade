/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x189b34. */
int __cdecl copyinmsg(unsigned int a1, unsigned int a2, int a3)
{
  int v3; // ebx
  int v4; // ecx
  unsigned int v5; // edi
  unsigned int v6; // esi
  int v8; // edx
  int v9; // ecx
  int v10; // edx
  unsigned int v11; // edi
  unsigned int v12; // esi
  int v13; // ecx
  unsigned int v14; // edi
  unsigned int v15; // esi
  int v16; // edx
  int v17; // eax
  unsigned int v18; // [esp+Ch] [ebp-8h]
  _BYTE *v19; // [esp+Ch] [ebp-8h]
  unsigned int v20; // [esp+10h] [ebp-4h]
  unsigned int v21; // [esp+10h] [ebp-4h]

  v20 = a1; /*0x189b40*/
  v18 = a2; /*0x189b46*/
  v3 = a3; /*0x189b49*/
  *(_DWORD *)(active_threads + 116) = &loc_189C00; /*0x189b51*/
  if ( a3 > 15 ) /*0x189b5b*/
  {
    v8 = a1 & 3; /*0x189b73*/
    if ( (a1 & 3) != 0 ) /*0x189b76*/
    {
      v9 = 4 - v8; /*0x189b7d*/
      v10 = 4 - v8; /*0x189b7f*/
      v11 = a2; /*0x189b81*/
      v12 = a1; /*0x189b84*/
      while ( v9 ) /*0x189b87*/
      {
        __writefsbyte(v11++, __readfsbyte(v12++)); /*0x189b87*/
        --v9; /*0x189b87*/
      }
      v3 = a3 - v10; /*0x189b8a*/
      v18 = v10 + a2; /*0x189b8c*/
      v20 = v10 + a1; /*0x189b8f*/
    }
    v13 = v3 >> 2; /*0x189b97*/
    v14 = v18; /*0x189b99*/
    v15 = v20; /*0x189b9c*/
    while ( v13 ) /*0x189b9f*/
    {
      __writefsdword(v14, __readfsdword(v15)); /*0x189b9f*/
      v15 += 4; /*0x189b9f*/
      v14 += 4; /*0x189b9f*/
      --v13; /*0x189b9f*/
    }
    v16 = v3 & 3; /*0x189ba4*/
    if ( (v3 & 3) == 0 ) /*0x189ba7*/
      goto LABEL_23; /*0x189ba7*/
    v17 = v3; /*0x189ba9*/
    LOBYTE(v17) = v3 & 0xFC; /*0x189bab*/
    v21 = v17 + v20; /*0x189bad*/
    v19 = (_BYTE *)(v17 + v18); /*0x189bb0*/
    if ( v16 != 2 ) /*0x189bb6*/
    {
      if ( (v3 & 3u) <= 2 ) /*0x189bb8*/
      {
        if ( v16 != 1 ) /*0x189bbd*/
          goto LABEL_23; /*0x189bbd*/
        goto LABEL_22; /*0x189bbd*/
      }
      if ( v16 != 3 ) /*0x189bc7*/
      {
LABEL_23:
        *(_DWORD *)(active_threads + 116) = 0; /*0x189bf0*/
        return 0; /*0x189bfc*/
      }
      v19[2] = __readfsbyte(v21 + 2); /*0x189bd5*/
    }
    v19[1] = __readfsbyte(v21 + 1); /*0x189be2*/
LABEL_22:
    *v19 = __readfsbyte(v21); /*0x189be5*/
    goto LABEL_23; /*0x189bee*/
  }
  v4 = a3; /*0x189b5d*/
  v5 = a2; /*0x189b5f*/
  v6 = a1; /*0x189b62*/
  while ( v4 ) /*0x189b65*/
  {
    __writefsbyte(v5++, __readfsbyte(v6++)); /*0x189b65*/
    --v4; /*0x189b65*/
  }
  return 0; /*0x189c14*/
}
