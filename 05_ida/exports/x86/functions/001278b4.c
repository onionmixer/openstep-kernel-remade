/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1278b4. */
int *__cdecl ip_insertoptions(int a1, int a2, _DWORD *a3)
{
  int *v3; // esi
  _DWORD *v4; // edx
  _DWORD *v5; // edi
  int v6; // eax
  unsigned int v7; // ebx
  int *v8; // ebx
  char *v10; // edi
  int v11; // [esp+Ch] [ebp-Ch]
  size_t v12; // [esp+10h] [ebp-8h]
  _DWORD *v13; // [esp+14h] [ebp-4h]

  v3 = (int *)a1; /*0x1278bd*/
  v4 = (_DWORD *)(*(_DWORD *)(a2 + 4) + a2); /*0x1278c5*/
  v13 = v4; /*0x1278c8*/
  v5 = (_DWORD *)(*(_DWORD *)(a1 + 4) + a1); /*0x1278cd*/
  v6 = *(__int16 *)(a2 + 8); /*0x1278d0*/
  v12 = v6 - 4; /*0x1278d7*/
  if ( *v4 ) /*0x1278da*/
    v5[4] = *v4; /*0x1278e0*/
  v7 = *(_DWORD *)(a1 + 4); /*0x1278e3*/
  if ( v7 <= 0x7B && v6 + 8 <= v7 ) /*0x1278f0*/
  {
    *(_DWORD *)(a1 + 4) = v7 - v12; /*0x1279a7*/
    *(_WORD *)(a1 + 8) += v12; /*0x1279ae*/
    ovbcopy(v5, (void *)(*(_DWORD *)(a1 + 4) + a1), 0x14u); /*0x1279bb*/
  }
  else
  {
    v11 = splimp(); /*0x1278fb*/
    v8 = (int *)mfree; /*0x1278fe*/
    if ( mfree ) /*0x127906*/
    {
      if ( *(_WORD *)(mfree + 10) ) /*0x127908*/
        panic(aMget_9); /*0x127914*/
      *(_WORD *)(mfree + 10) = 2; /*0x12791c*/
      --word_1E917C[0]; /*0x127922*/
      ++word_1E9180; /*0x127929*/
      mfree = *v8; /*0x127932*/
      *v8 = 0; /*0x127938*/
      v8[1] = 12; /*0x12793e*/
    }
    else
    {
      v8 = m_more(0, 2); /*0x127951*/
    }
    splx(v11); /*0x12795a*/
    if ( !v8 ) /*0x127964*/
      return (int *)a1; /*0x127968*/
    *(_WORD *)(a1 + 8) -= 20; /*0x127970*/
    *(_DWORD *)(a1 + 4) += 20; /*0x127975*/
    *v8 = a1; /*0x127979*/
    v3 = v8; /*0x12797b*/
    v8[1] = 104 - v12; /*0x127985*/
    *((_WORD *)v8 + 4) = v12 + 20; /*0x127990*/
    bcopy(v5, (char *)v8 + v8[1], 0x14u); /*0x12799d*/
  }
  v10 = (char *)v3 + v3[1]; /*0x1279c5*/
  bcopy(v13 + 1, v10 + 20, v12); /*0x1279d7*/
  *a3 = v12 + 20; /*0x1279e5*/
  *((_WORD *)v10 + 1) += v12; /*0x1279eb*/
  return v3; /*0x1279f4*/
}
