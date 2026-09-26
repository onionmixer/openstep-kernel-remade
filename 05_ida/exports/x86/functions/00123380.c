/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x123380. */
int __cdecl localetheraddr(int a1, int a2)
{
  const char *v3; // eax

  if ( !dword_1DBA6C ) /*0x123391*/
  {
    dword_1DBA6C = 1; /*0x123393*/
    if ( !a1 ) /*0x12339f*/
      return 0; /*0x1233a3*/
    dword_1E58DC = *(_DWORD *)a1; /*0x1233aa*/
    word_1E58E0 = *(_WORD *)(a1 + 4); /*0x1233b4*/
    v3 = (const char *)ether_sprintf(&dword_1E58DC); /*0x1233bf*/
    printf("Ethernet address = %s\n", v3); /*0x1233ca*/
  }
  if ( a2 ) /*0x1233d1*/
  {
    *(_DWORD *)a2 = dword_1E58DC; /*0x1233d9*/
    *(_WORD *)(a2 + 4) = word_1E58E0; /*0x1233e2*/
  }
  return 1; /*0x1233eb*/
}
