/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19523c. */
int __cdecl writetodc(_DWORD *a1)
{
  int i; // ebx
  int v2; // ebx
  int v3; // ebx
  int v4; // edi
  int v5; // ecx
  int v6; // ecx
  int *v7; // edi
  int j; // ebx
  int v10; // [esp+Ch] [ebp-2Ch]
  int v11; // [esp+Ch] [ebp-2Ch]
  char v12; // [esp+20h] [ebp-18h]
  unsigned __int8 v13; // [esp+24h] [ebp-14h]
  _BYTE v14[16]; // [esp+28h] [ebp-10h] BYREF

  v10 = splusclock(); /*0x19524a*/
  if ( dword_1E36A8 ) /*0x195257*/
  {
    outb(0x70u, 0xAu); /*0x19525d*/
    outb(0x71u, 0x26u); /*0x195266*/
    outb(0x70u, 0xBu); /*0x19526f*/
    outb(0x71u, 2u); /*0x195278*/
    dword_1E36A8 = 0; /*0x195280*/
  }
  outb(0x70u, 0xDu); /*0x19528e*/
  inb(0x71u); /*0x195295*/
  do /*0x1952b5*/
    outb(0x70u, 0xAu); /*0x1952a1*/
  while ( (inb(0x71u) & 0x80u) != 0 ); /*0x1952b5*/
  for ( i = 0; i <= 13; ++i ) /*0x1952b7*/
  {
    outb(0x70u, i); /*0x1952bf*/
    v14[i] = inb(0x71u); /*0x1952cb*/
  }
  splx(v10); /*0x1952db*/
  v2 = *a1 % 86400 / 60; /*0x1952fd*/
  v14[0] = (*a1 % 86400 % 60 % 10) & 0xF | (16 * (*a1 % 86400 % 60 / 10)); /*0x19531b*/
  v14[2] = (v2 % 60 % 10) & 0xF | (16 * (v2 % 60 / 10)); /*0x195345*/
  v14[4] = (v2 / 60 % 10) & 0xF | (16 * (v2 / 60 / 10)); /*0x195361*/
  v3 = *a1 / 86400; /*0x195373*/
  v14[6] = (v3 + 4) % 7; /*0x195384*/
  v4 = 1970; /*0x195387*/
  v5 = 365; /*0x19538c*/
  while ( v3 >= v5 ) /*0x195397*/
  {
    v3 -= v5; /*0x19539c*/
    ++v4; /*0x19539e*/
    v5 = 366; /*0x19539f*/
    if ( (v4 & 3) != 0 ) /*0x1953aa*/
      v5 = 365; /*0x1953ac*/
  }
  v14[9] = (v4 % 100 % 10) & 0xF | (16 * (v4 % 100 / 10)); /*0x1953e3*/
  v13 = (v4 / 100 % 10) & 0xF | (16 * (v4 / 100 / 10)); /*0x1953fe*/
  if ( v5 == 366 ) /*0x195407*/
    dword_1E36B0 = 29; /*0x195409*/
  v6 = 0; /*0x195413*/
  if ( dword_1E36AC[0] <= v3 ) /*0x19541b*/
  {
    v7 = dword_1E36AC; /*0x19541d*/
    do /*0x19542c*/
    {
      v3 -= *v7++; /*0x195424*/
      ++v6; /*0x195429*/
    }
    while ( *v7 <= v3 ); /*0x19542c*/
  }
  dword_1E36B0 = 28; /*0x19542e*/
  v14[8] = ((v6 + 1) % 10) & 0xF | (16 * ((v6 + 1) / 10)); /*0x195452*/
  v14[7] = ((v3 + 1) % 10) & 0xF | (16 * ((v3 + 1) / 10)); /*0x19546f*/
  v11 = splusclock(); /*0x195477*/
  if ( dword_1E36A8 ) /*0x195484*/
  {
    outb(0x70u, 0xAu); /*0x19548a*/
    outb(0x71u, 0x26u); /*0x195493*/
    outb(0x70u, 0xBu); /*0x19549c*/
    outb(0x71u, 2u); /*0x1954a5*/
    dword_1E36A8 = 0; /*0x1954ad*/
  }
  outb(0x70u, 0xBu); /*0x1954bb*/
  v12 = inb(0x71u); /*0x1954c7*/
  outb(0x70u, 0xBu); /*0x1954ce*/
  outb(0x71u, v12 | 0x80); /*0x1954e0*/
  for ( j = 0; j <= 9; ++j ) /*0x1954e5*/
  {
    outb(0x70u, j); /*0x1954ef*/
    outb(0x71u, v14[j]); /*0x1954fb*/
  }
  outb(0x70u, 0x32u); /*0x19550d*/
  outb(0x71u, v13); /*0x195518*/
  outb(0x70u, 0xBu); /*0x195521*/
  outb(0x71u, v12 & 0x7F); /*0x19552f*/
  splx(v11); /*0x19553b*/
  return 0; /*0x195545*/
}
