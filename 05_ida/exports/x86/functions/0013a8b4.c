/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13a8b4. */
int __cdecl compress_data(int *a1, int a2, char *a3)
{
  char *v3; // esi
  char v4; // cl
  signed int v5; // ebx
  unsigned int i; // [esp+Ch] [ebp-14h]
  int v8; // [esp+10h] [ebp-10h]
  _BYTE *v9; // [esp+14h] [ebp-Ch]
  signed int v10; // [esp+18h] [ebp-8h]

  v10 = (unsigned int)(a2 + 3) >> 2; /*0x13a8ce*/
  v9 = a3 + 4; /*0x13a8d7*/
  v3 = &a3[((unsigned int)(a2 + 3) >> 5) + 4]; /*0x13a8e0*/
  v4 = 0; /*0x13a8e4*/
  v8 = 0; /*0x13a8e6*/
  v5 = 0; /*0x13a8ed*/
  if ( v10 ) /*0x13a8f2*/
  {
    do /*0x13a942*/
    {
      for ( i = 0; i <= 7; ++i ) /*0x13a8f4*/
      {
        if ( v10 <= v5 ) /*0x13a8ff*/
          break; /*0x13a8ff*/
        v4 *= 2; /*0x13a901*/
        if ( v8 != *a1 ) /*0x13a90b*/
        {
          v4 |= 1u; /*0x13a90d*/
          v8 = *a1; /*0x13a910*/
          *(_DWORD *)v3 = *a1; /*0x13a913*/
          v3 += 4; /*0x13a915*/
          if ( a2 == v3 - a3 ) /*0x13a920*/
            return a2; /*0x13a925*/
        }
        ++a1; /*0x13a928*/
        ++v5; /*0x13a92f*/
      }
      *v9++ = v4; /*0x13a939*/
    }
    while ( v10 > v5 ); /*0x13a942*/
  }
  *(_DWORD *)a3 = a2; /*0x13a94a*/
  return v3 - a3; /*0x13a953*/
}
