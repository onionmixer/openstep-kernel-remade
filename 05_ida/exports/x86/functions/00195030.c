/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x195030. */
int __cdecl readtodc(_DWORD *a1)
{
  int v1; // esi
  int i; // ebx
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int j; // eax
  int k; // eax
  int v9; // edx
  int v11; // [esp+10h] [ebp-20h]
  int v12; // [esp+14h] [ebp-1Ch]
  _BYTE v13[2]; // [esp+20h] [ebp-10h] BYREF
  unsigned __int8 v14; // [esp+22h] [ebp-Eh]
  unsigned __int8 v15; // [esp+24h] [ebp-Ch]
  unsigned __int8 v16; // [esp+27h] [ebp-9h]
  unsigned __int8 v17; // [esp+28h] [ebp-8h]
  unsigned __int8 v18; // [esp+29h] [ebp-7h]

  v1 = 0; /*0x195039*/
  v11 = splusclock(); /*0x195040*/
  if ( dword_1E36A8 ) /*0x195050*/
  {
    outb(0x70u, 0xAu); /*0x195056*/
    outb(0x71u, 0x26u); /*0x19505f*/
    outb(0x70u, 0xBu); /*0x195068*/
    outb(0x71u, 2u); /*0x195071*/
    dword_1E36A8 = 0; /*0x195079*/
  }
  outb(0x70u, 0xDu); /*0x195087*/
  inb(0x71u); /*0x19508e*/
  do /*0x1950ae*/
    outb(0x70u, 0xAu); /*0x19509a*/
  while ( (inb(0x71u) & 0x80u) != 0 ); /*0x1950ae*/
  for ( i = 0; i <= 13; ++i ) /*0x1950b0*/
  {
    outb(0x70u, i); /*0x1950b7*/
    v13[i] = inb(0x71u); /*0x1950c6*/
  }
  splx(v11); /*0x1950d6*/
  v12 = (v17 & 0xF) + 10 * (v17 >> 4); /*0x195158*/
  v3 = (v18 & 0xF) + 10 * (v18 >> 4); /*0x195170*/
  v4 = v3; /*0x195173*/
  if ( v3 <= 69 ) /*0x195178*/
    v4 = v3 + 100; /*0x19517a*/
  v5 = v4; /*0x19517d*/
  v6 = 366; /*0x1951b6*/
  if ( (v5 & 3) != 0 ) /*0x1951be*/
    v6 = 365; /*0x1951c0*/
  if ( v6 == 366 ) /*0x1951ca*/
    dword_1E36B0 = 29; /*0x1951cc*/
  for ( j = v12 - 2; j >= 0; --j ) /*0x1951dc*/
    v1 += dword_1E36AC[j]; /*0x1951e0*/
  dword_1E36B0 = 28; /*0x1951ea*/
  for ( k = 70; k < v5; ++k ) /*0x1951fb*/
  {
    v9 = 366; /*0x195200*/
    if ( (k & 3) != 0 ) /*0x195207*/
      v9 = 365; /*0x195209*/
    v1 += v9; /*0x19520e*/
  }
  *a1 = 86400 * v1 /*0x19522b*/
      + 86400 * ((v16 & 0xF) + 10 * (v16 >> 4) - 1)
      + 3600 * ((v15 & 0xF) + 10 * (v15 >> 4))
      + (v13[0] & 0xF)
      + 10 * (v13[0] >> 4)
      + 60 * ((v14 & 0xF) + 10 * (v14 >> 4));
  return 0; /*0x195232*/
}
