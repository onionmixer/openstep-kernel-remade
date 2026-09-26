/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1871e8. */
char sub_1871E8()
{
  _BYTE *v0; // ecx
  int v1; // eax
  int v2; // esi
  int v3; // eax
  unsigned int v4; // edx
  _BYTE *v5; // ecx
  int v6; // eax
  int v7; // esi
  int v8; // eax
  unsigned int v9; // edx
  _BYTE *v10; // ecx
  int v11; // eax
  int v12; // esi
  int v13; // eax
  unsigned int v14; // edx
  char result; // al
  char v16; // [esp+Ch] [ebp-10h]
  char v17; // [esp+10h] [ebp-Ch]
  char v18; // [esp+18h] [ebp-4h]

  v0 = gdt; /*0x1871f6*/
  v1 = MEMORY[0x1136C] - 0x40000000; /*0x187201*/
  v2 = MEMORY[0x11378]; /*0x187206*/
  *((_WORD *)gdt + 61) = MEMORY[0x1136C]; /*0x18720c*/
  v0[124] = BYTE2(v1); /*0x187215*/
  v0[127] = HIBYTE(v1); /*0x18721b*/
  v0[125] = -102; /*0x18721e*/
  v18 = v0[126]; /*0x187225*/
  v0[126] = v18 | 0x40; /*0x18722e*/
  v3 = v2 - 1; /*0x187231*/
  if ( (unsigned int)(v2 - 1) > 0xFFFFF ) /*0x187239*/
  {
    v0[126] = v18 | 0xC0; /*0x18726b*/
    *((_WORD *)v0 + 60) = (((v2 + 4095) & 0xFFFFF000) - 4096) >> 12; /*0x187273*/
    v4 = (((v2 + 4095) & 0xFFFFF000) - 4096) >> 28; /*0x187277*/
  }
  else
  {
    v0[126] = v18 & 0x3F | 0x40; /*0x187240*/
    *((_WORD *)v0 + 60) = v3; /*0x187243*/
    LOBYTE(v4) = BYTE2(v3) & 0xF; /*0x18724c*/
  }
  v0[126] = v4 | v0[126] & 0xF0; /*0x187281*/
  v5 = gdt; /*0x187284*/
  v6 = MEMORY[0x11370] - 0x40000000; /*0x187290*/
  v7 = MEMORY[0x11378]; /*0x187295*/
  *((_WORD *)gdt + 65) = MEMORY[0x11370]; /*0x18729b*/
  v5[132] = BYTE2(v6); /*0x1872a7*/
  v5[135] = HIBYTE(v6); /*0x1872b0*/
  v5[133] = -102; /*0x1872b6*/
  v16 = v5[134]; /*0x1872c3*/
  v5[134] = v16 & 0xBF; /*0x1872cc*/
  v8 = v7 - 1; /*0x1872d2*/
  if ( (unsigned int)(v7 - 1) > 0xFFFFF ) /*0x1872da*/
  {
    v5[134] = v16 & 0x3F | 0x80; /*0x187313*/
    *((_WORD *)v5 + 64) = (((v7 + 4095) & 0xFFFFF000) - 4096) >> 12; /*0x18731e*/
    v9 = (((v7 + 4095) & 0xFFFFF000) - 4096) >> 28; /*0x187325*/
  }
  else
  {
    v5[134] = v16 & 0x3F; /*0x1872e4*/
    *((_WORD *)v5 + 64) = v8; /*0x1872ea*/
    LOBYTE(v9) = BYTE2(v8) & 0xF; /*0x1872f6*/
  }
  v5[134] = v9 | v5[134] & 0xF0; /*0x187332*/
  v10 = gdt; /*0x187338*/
  v11 = MEMORY[0x11374] - 0x40000000; /*0x187344*/
  v12 = MEMORY[0x1137C]; /*0x187349*/
  *((_WORD *)gdt + 69) = MEMORY[0x11374]; /*0x18734f*/
  v10[140] = BYTE2(v11); /*0x18735b*/
  v10[143] = HIBYTE(v11); /*0x187364*/
  v10[141] = -110; /*0x18736a*/
  v17 = v10[142]; /*0x187377*/
  v10[142] = v17 | 0x40; /*0x187380*/
  v13 = v12 - 1; /*0x187386*/
  if ( (unsigned int)(v12 - 1) > 0xFFFFF ) /*0x18738e*/
  {
    v10[142] = v17 | 0xC0; /*0x1873c3*/
    *((_WORD *)v10 + 68) = (((v12 + 4095) & 0xFFFFF000) - 4096) >> 12; /*0x1873ce*/
    v14 = (((v12 + 4095) & 0xFFFFF000) - 4096) >> 28; /*0x1873d5*/
  }
  else
  {
    v10[142] = v17 & 0x3F | 0x40; /*0x187395*/
    *((_WORD *)v10 + 68) = v13; /*0x18739b*/
    LOBYTE(v14) = BYTE2(v13) & 0xF; /*0x1873a7*/
  }
  result = v14 | v10[142] & 0xF0; /*0x1873e0*/
  v10[142] = result; /*0x1873e2*/
  dword_1E75B4 = MEMORY[0x11380]; /*0x1873ee*/
  return result; /*0x1873f7*/
}
