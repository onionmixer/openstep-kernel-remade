/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x194814. */
int __cdecl findBootConfigString(int a1)
{
  int v1; // esi
  int v3; // ebx
  unsigned int v4; // kr04_4
  int v5; // eax
  int v6; // [esp+10h] [ebp-4h]

  v1 = 79100; /*0x19481d*/
  v6 = 0; /*0x194822*/
  if ( MEMORY[0x134FC] ) /*0x194830*/
  {
    v3 = 0; /*0x194840*/
    if ( a1 <= 0 ) /*0x194845*/
    {
      return v1; /*0x194882*/
    }
    else
    {
      while ( 1 ) /*0x194852*/
      {
        v4 = strlen((const char *)v1) + 1; /*0x194852*/
        v5 = v4 + v6; /*0x19485f*/
        v6 += v4; /*0x194863*/
        v1 += v4; /*0x194866*/
        if ( v4 == 1 || v5 > 53248 || !*(_BYTE *)v1 ) /*0x194873*/
          break; /*0x194873*/
        if ( a1 <= ++v3 ) /*0x194880*/
          return v1; /*0x194880*/
      }
      return 0; /*0x194878*/
    }
  }
  else
  {
    IOLog(aWarningNoConfi); /*0x194837*/
    return 0; /*0x19483c*/
  }
}
