/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x122134. */
int *__cdecl arpwhohas(int a1, void *a2, char a3, void *a4)
{
  int *result; // eax
  int v5; // edi
  int v6; // ebx
  _WORD *v7; // ebx
  __int16 v8; // [esp+Ch] [ebp-10h] BYREF
  _BYTE v9[14]; // [esp+Eh] [ebp-Eh] BYREF

  result = m_get(0, 1); /*0x122141*/
  v5 = (int)result; /*0x122146*/
  if ( result ) /*0x12214d*/
  {
    *((_WORD *)result + 4) = 28; /*0x122153*/
    v8 = 2054; /*0x122159*/
    *((_WORD *)result + 4) = 28; /*0x12215f*/
    bcopy(&v8, &v9[2 * (unsigned __int8)word_1DB968], 2u); /*0x122177*/
    bcopy((char *)&unk_1DB96C + HIBYTE(word_1DB968) + (unsigned __int8)word_1DB968, v9, (unsigned __int8)word_1DB968); /*0x122197*/
    v6 = 124 - *(__int16 *)(v5 + 8); /*0x1221a5*/
    *(_DWORD *)(v5 + 4) = v6; /*0x1221a7*/
    v7 = (_WORD *)(v5 + v6); /*0x1221aa*/
    bcopy(&arpethertempl, v7, *(__int16 *)(v5 + 8)); /*0x1221b7*/
    bcopy(a2, v7 + 4, (unsigned __int8)word_1DB968); /*0x1221cf*/
    bcopy(&a3, (char *)v7 + (unsigned __int8)word_1DB968 + 8, HIBYTE(word_1DB968)); /*0x1221ec*/
    bcopy(a4, (char *)&v7[(unsigned __int8)word_1DB968 + 4] + HIBYTE(word_1DB968), HIBYTE(word_1DB968)); /*0x12220b*/
    *v7 = __ROR2__(*v7, 8); /*0x12221a*/
    v7[1] = __ROR2__(v7[1], 8); /*0x122225*/
    v7[3] = __ROR2__(v7[3], 8); /*0x122231*/
    v8 = 0; /*0x122235*/
    return (int *)if_output_mbuf(a1, v5, (int)&v8); /*0x122241*/
  }
  return result; /*0x122249*/
}
