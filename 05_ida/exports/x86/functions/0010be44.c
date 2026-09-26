/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10be44. */
int __cdecl logread(int a1, _DWORD *a2)
{
  int v2; // ebx
  int v3; // eax
  int v5; // edx
  int v6; // ebx
  unsigned int v7; // edx
  int v8; // eax
  bool v9; // sf
  unsigned int v10; // eax
  int v11; // [esp+Ch] [ebp-4h]

  v11 = 0; /*0x10be50*/
  v2 = splhigh(); /*0x10be5c*/
  while ( *(_DWORD *)(pmsgbuf + 8) == *(_DWORD *)(pmsgbuf + 4) ) /*0x10bea0*/
  {
    v3 = logsoftc; /*0x10be60*/
    if ( (logsoftc & 2) != 0 ) /*0x10be67*/
    {
      splx(v2); /*0x10be6a*/
      return 35; /*0x10be74*/
    }
    LOBYTE(v3) = logsoftc | 8; /*0x10be7c*/
    logsoftc = v3; /*0x10be7e*/
    sleep(pmsgbuf); /*0x10be8c*/
  }
  splx(v2); /*0x10bea3*/
  logsoftc &= ~8u; /*0x10bea8*/
  while ( (int)a2[5] > 0 ) /*0x10beb2*/
  {
    v5 = *(_DWORD *)(pmsgbuf + 8); /*0x10bebe*/
    v6 = *(_DWORD *)(pmsgbuf + 4) - v5; /*0x10bec4*/
    if ( v6 < 0 ) /*0x10bec6*/
      v6 = 4084 - v5; /*0x10becd*/
    if ( v6 > a2[5] ) /*0x10bed4*/
      v6 = a2[5]; /*0x10bed6*/
    if ( !v6 ) /*0x10beda*/
      break; /*0x10beda*/
    v11 = uiomove(pmsgbuf + v5 + 12, v6, 0, a2); /*0x10beea*/
    if ( v11 ) /*0x10bef2*/
      break; /*0x10bef2*/
    v7 = pmsgbuf; /*0x10bef4*/
    v8 = *(_DWORD *)(pmsgbuf + 8); /*0x10befa*/
    v9 = v6 + v8 < 0; /*0x10befd*/
    v10 = v6 + v8; /*0x10befd*/
    *(_DWORD *)(pmsgbuf + 8) = v10; /*0x10beff*/
    if ( v9 || v10 > 0xFF3 ) /*0x10bf09*/
      *(_DWORD *)(v7 + 8) = 0; /*0x10bf0b*/
  }
  return v11; /*0x10bf1a*/
}
