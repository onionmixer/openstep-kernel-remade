/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1226cc. */
void __cdecl arpinput(int a1, void *a2, int a3, int a4)
{
  __int16 v4; // si
  _WORD v5[4]; // [esp+Ch] [ebp-8h] BYREF

  if ( *(char *)(a1 + 12) >= 0 /*0x12273f*/
    && *(_WORD *)(a4 + 8) > 7u
    && (bcopy((const void *)(*(_DWORD *)(a4 + 4) + a4), v5, 8u), v4 = __ROR2__(v5[1], 8), __ROR2__(v5[0], 8) == 1)
    && *(__int16 *)(a4 + 8) >= 2 * (HIBYTE(word_1DB968) + (unsigned int)(unsigned __int8)word_1DB968) + 8
    && (v4 == 2048 || v4 == 4096) )
  {
    in_arpinput(a1, a2, a3, a4); /*0x12274b*/
  }
  else
  {
    m_freem(a4); /*0x122755*/
  }
}
