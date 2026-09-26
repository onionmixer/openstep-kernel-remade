/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119c10. */
int *__cdecl breada(int a1, int a2, int a3, int a4, int a5)
{
  int *v5; // esi
  int v6; // eax
  _DWORD *v7; // ebx
  int *v8; // ebx
  int v9; // eax
  int v11; // [esp+0h] [ebp-Ch]

  ++dword_1E99C8; /*0x119c1c*/
  v5 = nullptr; /*0x119c22*/
  if ( !incore(a1, a2) ) /*0x119c29*/
  {
    v5 = (int *)getblk(a1, a2, a3); /*0x119c43*/
    v6 = *v5; /*0x119c45*/
    if ( (*v5 & 2) != 0 ) /*0x119c4c*/
    {
      ++dword_1E99CC; /*0x119c84*/
    }
    else
    {
      LOBYTE(v6) = v6 | 1; /*0x119c4e*/
      *v5 = v6; /*0x119c50*/
      if ( v5[5] > v5[6] ) /*0x119c58*/
        panic(aBreada); /*0x119c5f*/
      (*(void (__cdecl **)(int *))(*(_DWORD *)(v5[16] + 28) + 84))(v5); /*0x119c71*/
      ++*(_DWORD *)(active_u + 412); /*0x119c78*/
    }
  }
  if ( a4 && !incore(a1, a4) ) /*0x119c90*/
  {
    v7 = (_DWORD *)getblk(a1, a4, a5); /*0x119ca7*/
    if ( (*v7 & 2) != 0 ) /*0x119cb0*/
    {
      brelse((int)v7); /*0x119cb3*/
      ++dword_1E99D0; /*0x119cb8*/
    }
    else
    {
      *v7 |= 0x101u; /*0x119cc5*/
      if ( v7[5] > v7[6] ) /*0x119ccd*/
        panic(aBreadrabp); /*0x119cd4*/
      (*(void (__cdecl **)(_DWORD *))(*(_DWORD *)(v7[16] + 28) + 84))(v7); /*0x119ce6*/
      ++*(_DWORD *)(active_u + 412); /*0x119ced*/
    }
  }
  if ( v5 ) /*0x119cf8*/
  {
    biowait((unsigned int)v5); /*0x119d75*/
    return v5; /*0x119d7a*/
  }
  else
  {
    ++bstats; /*0x119cfa*/
    if ( !a3 ) /*0x119d04*/
      panic(aBreadSize0); /*0x119d0b*/
    v8 = (int *)getblk(a1, a2, a3); /*0x119d21*/
    v9 = *v8; /*0x119d23*/
    if ( (*v8 & 2) != 0 ) /*0x119d2a*/
    {
      ++dword_1E99C4; /*0x119d2c*/
      return v8; /*0x119d32*/
    }
    else
    {
      LOBYTE(v9) = v9 | 1; /*0x119d38*/
      *v8 = v9; /*0x119d3a*/
      if ( v8[5] > v8[6] ) /*0x119d42*/
        panic(aBread); /*0x119d49*/
      (*(void (__stdcall **)(int *, int))(*(_DWORD *)(v8[16] + 28) + 84))(v8, v11); /*0x119d5b*/
      ++*(_DWORD *)(active_u + 412); /*0x119d62*/
      biowait((unsigned int)v8); /*0x119d69*/
      return v8; /*0x119d6e*/
    }
  }
}
