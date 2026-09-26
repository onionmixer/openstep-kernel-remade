/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b518. */
void __cdecl dnlc_enterSymLink(char *a1, int a2, int a3)
{
  unsigned int v3; // esi
  unsigned int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // edi

  v3 = *(_DWORD *)(a3 + 8); /*0x11b527*/
  if ( v3 )
  {
    v4 = strlen(a1) + 1; /*0x11b53c*/
    v5 = (int)(v4 - 1) > 32 ? 0 : sub_11B8DC(a2, a1, v4 - 1, ((_BYTE)a2 + (_BYTE)v4 - 1 + a1[v4 - 2] + *a1) & 0x3F, -1);
    if ( v5 ) /*0x11b578*/
    {
      if ( !*(_BYTE *)(v5 + 68) ) /*0x11b582*/
        goto LABEL_10; /*0x11b582*/
      if ( *(_DWORD *)(a3 + 8) != *(__int16 *)(v5 + 70) /*0x11b598*/
        || bcmp(*(const void **)a3, *(const void **)(v5 + 64), *(__int16 *)(v5 + 70)) )
      {
        kfree(*(_DWORD *)(v5 + 64), *(__int16 *)(v5 + 70)); /*0x11b5ad*/
LABEL_10:
        v6 = kalloc(v3); /*0x11b5b5*/
        *(_DWORD *)(v5 + 64) = v6; /*0x11b5bb*/
        if ( v6 ) /*0x11b5c3*/
        {
          *(_BYTE *)(v5 + 68) = 1; /*0x11b5c5*/
          *(_WORD *)(v5 + 70) = v3; /*0x11b5c9*/
          bcopy(*(const void **)a3, *(void **)(v5 + 64), v3); /*0x11b5d8*/
          *(_DWORD *)(*(_DWORD *)(v5 + 12) + 8) = *(_DWORD *)(v5 + 8); /*0x11b5e3*/
          *(_DWORD *)(*(_DWORD *)(v5 + 8) + 12) = *(_DWORD *)(v5 + 12); /*0x11b5ec*/
          v7 = dword_1E9BEC; /*0x11b5ef*/
          v8 = *(_DWORD *)(dword_1E9BEC + 8); /*0x11b5f4*/
          *(_DWORD *)(dword_1E9BEC + 8) = v5; /*0x11b5f7*/
          *(_DWORD *)(v5 + 8) = v8; /*0x11b5fa*/
          *(_DWORD *)(v8 + 12) = v5; /*0x11b5fd*/
          *(_DWORD *)(v5 + 12) = v7; /*0x11b600*/
        }
      }
    }
  }
}
