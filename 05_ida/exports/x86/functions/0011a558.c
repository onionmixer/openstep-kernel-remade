/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11a558. */
int __cdecl geteblk(int a1)
{
  int v1; // ebx

  if ( a1 > 0x2000 ) /*0x11a566*/
    panic(aGeteblkSizeToo); /*0x11a56d*/
  do /*0x11a5d7*/
  {
    v1 = getnewbuf(); /*0x11a57a*/
    *(_DWORD *)v1 |= 0x10000u; /*0x11a57c*/
    bfree(v1); /*0x11a583*/
    *(_DWORD *)(*(_DWORD *)(v1 + 8) + 4) = *(_DWORD *)(v1 + 4); /*0x11a58e*/
    *(_DWORD *)(*(_DWORD *)(v1 + 4) + 8) = *(_DWORD *)(v1 + 8); /*0x11a597*/
    sub_11B26C(v1); /*0x11a59b*/
    *(_WORD *)(v1 + 28) = 0; /*0x11a5a0*/
    *(_DWORD *)(v1 + 40) = 0; /*0x11a5a6*/
    *(_DWORD *)(v1 + 4) = dword_1E87EC; /*0x11a5b3*/
    *(_DWORD *)(v1 + 8) = &unk_1E87E8; /*0x11a5b6*/
    *(_DWORD *)(dword_1E87EC + 8) = v1; /*0x11a5c2*/
    dword_1E87EC = v1; /*0x11a5c5*/
  }
  while ( !brealloc(v1, a1) ); /*0x11a5d7*/
  return v1; /*0x11a5de*/
}
