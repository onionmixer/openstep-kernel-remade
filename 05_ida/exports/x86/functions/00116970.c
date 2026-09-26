/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116970. */
void __cdecl sbcompress(int a1, int a2, int a3)
{
  __int16 v5; // dx
  int v6; // ecx
  __int16 v7; // ax
  unsigned int v8; // [esp+Ch] [ebp-Ch]
  unsigned int v9; // [esp+14h] [ebp-4h]

  while ( a2 ) /*0x116981*/
  {
    v5 = *(_WORD *)(a2 + 8); /*0x116987*/
    if ( v5 ) /*0x11698e*/
    {
      if ( a3 /*0x1169d8*/
        && (v8 = *(_DWORD *)(a3 + 4), v8 <= 0x7C)
        && (v9 = *(_DWORD *)(a2 + 4), v9 <= 0x7C)
        && (v6 = *(__int16 *)(a3 + 8), v5 + v6 + v8 <= 0x7C)
        && *(_WORD *)(a3 + 10) == *(_WORD *)(a2 + 10) )
      {
        bcopy((const void *)(a2 + v9), (void *)(v6 + a3 + v8), v5); /*0x1169e9*/
        *(_WORD *)(a3 + 8) += *(_WORD *)(a2 + 8); /*0x1169f2*/
        *(_WORD *)a1 += *(_WORD *)(a2 + 8); /*0x1169fd*/
        a2 = m_free(a2); /*0x116a06*/
      }
      else
      {
        *(_WORD *)a1 += *(_WORD *)(a2 + 8); /*0x116a17*/
        v7 = *(_WORD *)(a1 + 4); /*0x116a1a*/
        *(_WORD *)(a1 + 4) = v7 + 128; /*0x116a25*/
        if ( *(_DWORD *)(a2 + 4) > 0x7Cu ) /*0x116a2d*/
          *(_WORD *)(a1 + 4) = v7 + 1152; /*0x116a33*/
        if ( a3 ) /*0x116a39*/
          *(_DWORD *)a3 = a2; /*0x116a3b*/
        else
          *(_DWORD *)(a1 + 12) = a2; /*0x116a43*/
        a3 = a2; /*0x116a46*/
        a2 = *(_DWORD *)a2; /*0x116a48*/
        *(_DWORD *)a3 = 0; /*0x116a4a*/
      }
    }
    else
    {
      a2 = m_free(a2); /*0x116996*/
    }
  }
}
