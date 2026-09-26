/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142600. */
int __cdecl sub_142600(_DWORD *a1, _DWORD *a2, char a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *v5; // ebx
  unsigned int v7; // edi
  unsigned int v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // eax

  v5 = a1; /*0x142609*/
  *a5 = a1; /*0x14260f*/
  if ( !a1 ) /*0x142613*/
    return 0; /*0x142745*/
  v7 = a2[1]; /*0x14262b*/
  v8 = a2[2]; /*0x14262e*/
  while ( 1 ) /*0x142634*/
  {
    if ( (a3 & 1) != 0 && v5[3] != a2[3] || (a3 & 2) != 0 && v5[3] == a2[3] ) /*0x142654*/
    {
      *a4 = v5 + 5; /*0x14265c*/
      v5 = (_DWORD *)v5[5]; /*0x14265e*/
      *a5 = v5; /*0x142664*/
      goto LABEL_40; /*0x142666*/
    }
    v9 = v5[2]; /*0x14266c*/
    if ( (v9 == -1 || v7 <= v9) && (v8 == -1 || v5[1] <= v8) ) /*0x142680*/
      break; /*0x142680*/
    if ( (a3 & 1) != 0 && v8 != -1 && v5[1] > v8 ) /*0x142690*/
      return 0; /*0x142690*/
    *a4 = v5 + 5; /*0x14269c*/
    v5 = (_DWORD *)v5[5]; /*0x14269e*/
    *a5 = v5; /*0x1426a4*/
LABEL_40:
    if ( !v5 ) /*0x14273f*/
      return 0; /*0x14273f*/
  }
  v10 = v5[1]; /*0x1426ac*/
  if ( v10 == v7 && v5[2] == v8 ) /*0x1426b6*/
    return 1; /*0x14261c*/
  if ( v10 <= v7 && v8 != -1 ) /*0x1426c3*/
  {
    v11 = v5[2]; /*0x1426c5*/
    if ( v11 >= v8 || v11 == -1 ) /*0x1426cf*/
      return 2; /*0x1426d1*/
  }
  if ( v5[1] >= v7 ) /*0x1426db*/
  {
    if ( v8 == -1 ) /*0x1426e0*/
      return 3; /*0x1426e0*/
    v12 = v5[2]; /*0x1426e2*/
    if ( v12 != -1 && v8 >= v12 ) /*0x1426ec*/
      return 3; /*0x1426ee*/
  }
  if ( v5[1] < v7 ) /*0x1426fb*/
  {
    v13 = v5[2]; /*0x1426fd*/
    if ( v13 >= v7 || v13 == -1 ) /*0x142707*/
      return 4; /*0x142709*/
  }
  if ( v5[1] <= v7 || v8 == -1 || (v14 = v5[2], v14 <= v8) && v14 != -1 ) /*0x142724*/
    panic(aLfFindoverlapD); /*0x142735*/
  return 5; /*0x14274a*/
}
