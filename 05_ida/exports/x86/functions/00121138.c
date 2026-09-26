/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x121138. */
int __cdecl if_output_mbuf(int a1, int a2, int a3)
{
  int i; // edx
  unsigned int v5; // edi
  int j; // esi
  int v7; // edx
  size_t v8; // ebx
  __int16 v9; // ax
  int v10; // [esp-10h] [ebp-34h]
  int v11; // [esp-Ch] [ebp-30h]
  int v12; // [esp-8h] [ebp-2Ch]
  size_t v13; // [esp+10h] [ebp-14h]
  unsigned int v14; // [esp+14h] [ebp-10h]
  char *v15; // [esp+18h] [ebp-Ch]
  signed __int32 v16; // [esp+1Ch] [ebp-8h]
  int v17; // [esp+20h] [ebp-4h]

  v16 = 0; /*0x121141*/
  for ( i = a2; i; i = *(_DWORD *)i ) /*0x12114d*/
    v16 += *(__int16 *)(i + 8); /*0x121154*/
  if ( v16 <= *(__int16 *)(a1 + 10) ) /*0x121167*/
  {
    v17 = (*(int (__cdecl **)(int))(a1 + 64))(a1); /*0x121185*/
    if ( v17 ) /*0x12118d*/
    {
      v15 = (char *)nb_map(v17); /*0x1211ad*/
      v14 = 0; /*0x1211b0*/
      v13 = v16; /*0x1211ba*/
      v5 = 0; /*0x1211c0*/
      for ( j = a2; j; j = *(_DWORD *)j ) /*0x1211c7*/
      {
        if ( v14 >= v5 ) /*0x1211cf*/
        {
          v7 = *(__int16 *)(j + 8); /*0x1211d1*/
          if ( v14 < v7 + v5 ) /*0x1211db*/
          {
            v8 = v7 - (v14 - v5); /*0x1211ec*/
            if ( v13 < v8 ) /*0x1211f1*/
              v8 = v13; /*0x1211f3*/
            bcopy((const void *)(v14 - v5 + *(_DWORD *)(j + 4) + j), v15, v8); /*0x1211ff*/
            v15 += v8; /*0x121204*/
            v14 += v8; /*0x121207*/
            v13 -= v8; /*0x12120a*/
            if ( !v13 ) /*0x121214*/
              break; /*0x121214*/
          }
        }
        v5 += *(__int16 *)(j + 8); /*0x12121a*/
      }
      v9 = nb_size(v17); /*0x121226*/
      nb_shrink_bot(v17, v9 - v16); /*0x121233*/
      m_freem(a2); /*0x12123c*/
      return (*(int (__stdcall **)(int, int, int, int, int, int))(a1 + 52))(a1, v17, a3, v10, v11, v12); /*0x121250*/
    }
    else
    {
      m_freem(a2); /*0x121193*/
      return 55; /*0x121198*/
    }
  }
  else
  {
    m_freem(a2); /*0x12116d*/
    return 40; /*0x121172*/
  }
}
