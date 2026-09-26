/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12c6c4. */
__int16 __cdecl nattr_to_vattr(int *a1, int *a2, int a3)
{
  unsigned int v3; // edx
  unsigned int v4; // eax
  int v5; // eax
  int v7; // [esp+Ch] [ebp-8h]

  v7 = a1[12]; /*0x12c6d9*/
  *(_DWORD *)a3 = *a2; /*0x12c6de*/
  *(_WORD *)(a3 + 4) = *((_WORD *)a2 + 2); /*0x12c6e4*/
  *(_WORD *)(a3 + 6) = *((_WORD *)a2 + 6); /*0x12c6ec*/
  *(_WORD *)(a3 + 8) = *((_WORD *)a2 + 8); /*0x12c6f4*/
  *(_DWORD *)(a3 + 12) = (unsigned __int16)(*(unsigned __int8 *)(*(_DWORD *)(a1[9] + 296) + 40) /*0x12c71e*/
                                          | (unsigned __int16)((unsigned __int16)vfs_fixedmajor(a1[9]) << 8));
  *(_DWORD *)(a3 + 16) = a2[10]; /*0x12c724*/
  *(_WORD *)(a3 + 20) = *((_WORD *)a2 + 4); /*0x12c72b*/
  v3 = *(_DWORD *)(*a1 + 20); /*0x12c731*/
  if ( a2[5] < v3 && ((*(_BYTE *)(*a1 + 56) & 2) != 0 || (*(_BYTE *)(v7 + 96) & 0x10) != 0) ) /*0x12c746*/
    *(_DWORD *)(a3 + 24) = v3; /*0x12c748*/
  else
    *(_DWORD *)(a3 + 24) = a2[5]; /*0x12c753*/
  v4 = *(_DWORD *)(a3 + 24); /*0x12c756*/
  if ( *(_DWORD *)(v7 + 152) < v4 || (*(_BYTE *)(v7 + 96) & 0x10) == 0 ) /*0x12c768*/
    *(_DWORD *)(v7 + 152) = v4; /*0x12c76d*/
  *(_DWORD *)(a3 + 32) = a2[11]; /*0x12c776*/
  *(_DWORD *)(a3 + 36) = a2[12]; /*0x12c77c*/
  *(_DWORD *)(a3 + 40) = a2[13]; /*0x12c782*/
  *(_DWORD *)(a3 + 44) = a2[14]; /*0x12c788*/
  *(_DWORD *)(a3 + 48) = a2[15]; /*0x12c78e*/
  *(_DWORD *)(a3 + 52) = a2[16]; /*0x12c794*/
  *(_WORD *)(a3 + 56) = *((_WORD *)a2 + 14); /*0x12c79b*/
  *(_DWORD *)(a3 + 60) = a2[8]; /*0x12c7a2*/
  v5 = *a2; /*0x12c7a5*/
  if ( *a2 == 3 ) /*0x12c7aa*/
  {
    *(_DWORD *)(a3 + 28) = 2048; /*0x12c7b4*/
  }
  else if ( v5 == 4 ) /*0x12c7af*/
  {
    *(_DWORD *)(a3 + 28) = 0x2000; /*0x12c7c0*/
  }
  else
  {
    *(_DWORD *)(a3 + 28) = a2[6]; /*0x12c7cf*/
  }
  if ( *a2 == 4 && a2[7] == -1 ) /*0x12c7db*/
  {
    *(_DWORD *)a3 = 8; /*0x12c7dd*/
    LOWORD(v5) = *(_WORD *)(a3 + 4); /*0x12c7e3*/
    BYTE1(v5) = BYTE1(v5) & 0xF | 0x10; /*0x12c7ea*/
    *(_WORD *)(a3 + 4) = v5; /*0x12c7ed*/
    *(_WORD *)(a3 + 56) = 0; /*0x12c7f1*/
    *(_DWORD *)(a3 + 28) = a2[6]; /*0x12c7fa*/
  }
  return v5; /*0x12c800*/
}
