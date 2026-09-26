/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10d050. */
int ioctl(int a1, unsigned __int32 a2, ...)
{
  int v2; // edx
  int result; // eax
  int v4; // esi
  int v5; // ebx
  char v6; // al
  char v7; // dl
  size_t v8; // [esp+Ch] [ebp-90h]
  int *v9; // [esp+18h] [ebp-84h]
  int v10[32]; // [esp+1Ch] [ebp-80h] BYREF

  v9 = *(int **)(dword_1E875C + 36); /*0x10d06b*/
  v2 = *v9; /*0x10d07d*/
  if ( *(_DWORD *)(active_u + 348) <= (unsigned int)*v9 /*0x10d09a*/
    || (result = *(_DWORD *)(active_u + 336), (v4 = *(_DWORD *)(result + 4 * v2)) == 0)
    || v4 == -65536 )
  {
    result = dword_1E875C; /*0x10d09c*/
    *(_BYTE *)(dword_1E875C + 104) = 9; /*0x10d0a1*/
    return result; /*0x10d0a5*/
  }
  if ( (*(_BYTE *)(v4 + 8) & 3) == 0 ) /*0x10d0b0*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 9; /*0x10d0b8*/
    return result; /*0x10d0bc*/
  }
  v5 = v9[1]; /*0x10d0ca*/
  if ( v5 == 536897025 ) /*0x10d0d3*/
  {
    result = *(_DWORD *)(active_u + 340); /*0x10d0db*/
    *(_BYTE *)(v2 + result) |= 1u; /*0x10d0e1*/
    return result; /*0x10d0e5*/
  }
  if ( v5 == 536897026 ) /*0x10d0f2*/
  {
    result = *(_DWORD *)(active_u + 340); /*0x10d0fa*/
    *(_BYTE *)(v2 + result) &= ~1u; /*0x10d100*/
    return result; /*0x10d104*/
  }
  result = (v5 & 0x1FFFFFFFu) >> 16; /*0x10d113*/
  v8 = result; /*0x10d116*/
  if ( (unsigned int)result > 0x80 ) /*0x10d121*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 14; /*0x10d129*/
    return result; /*0x10d12d*/
  }
  if ( v5 < 0 ) /*0x10d136*/
  {
    if ( result ) /*0x10d13f*/
    {
      *(_BYTE *)(dword_1E875C + 104) = copyin(v9[2], v10, result); /*0x10d162*/
      result = dword_1E875C; /*0x10d165*/
      if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x10d16d*/
        return result; /*0x10d171*/
      goto LABEL_22; /*0x10d171*/
    }
LABEL_21:
    v10[0] = v9[2]; /*0x10d1ac*/
    goto LABEL_22; /*0x10d1b5*/
  }
  if ( (v5 & 0x40000000) != 0 && result ) /*0x10d18b*/
  {
    bzero(v10, result); /*0x10d198*/
    goto LABEL_22; /*0x10d1a0*/
  }
  if ( (v5 & 0x20000000) != 0 ) /*0x10d1aa*/
    goto LABEL_21; /*0x10d1aa*/
LABEL_22:
  if ( v5 == -2147195267 ) /*0x10d1be*/
  {
    v6 = fset(v4, 64, v10[0]); /*0x10d1fb*/
    goto LABEL_37; /*0x10d200*/
  }
  if ( v5 > -2147195267 ) /*0x10d1c0*/
  {
    if ( v5 == -2147195266 ) /*0x10d1d2*/
    {
      v6 = fset(v4, 4, v10[0]); /*0x10d1e7*/
    }
    else
    {
      if ( v5 != 1074030203 ) /*0x10d1da*/
        goto LABEL_33; /*0x10d1da*/
      v6 = fgetown(v4, v10); /*0x10d215*/
    }
LABEL_37:
    v7 = v6; /*0x10d276*/
    result = dword_1E875C; /*0x10d278*/
    *(_BYTE *)(dword_1E875C + 104) = v7; /*0x10d27d*/
    return result; /*0x10d27d*/
  }
  if ( v5 == -2147195268 ) /*0x10d1c8*/
  {
    v6 = fsetown(v4, v10[0]); /*0x10d209*/
    goto LABEL_37; /*0x10d20e*/
  }
LABEL_33:
  *(_BYTE *)(dword_1E875C + 104) = (*(int (__cdecl **)(int, int, int *))(*(_DWORD *)(v4 + 20) + 4))(v4, v5, v10); /*0x10d21c*/
  result = dword_1E875C; /*0x10d23a*/
  if ( !*(_BYTE *)(dword_1E875C + 104) && (v5 & 0x40000000) != 0 && v8 ) /*0x10d257*/
  {
    v6 = copyout(v10, v9[2], v8); /*0x10d271*/
    goto LABEL_37; /*0x10d271*/
  }
  return result; /*0x10d286*/
}
