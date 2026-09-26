/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187d48. */
unsigned __int64 sub_187D48()
{
  int v0; // ecx
  unsigned __int16 v1; // bx
  unsigned __int8 v2; // al
  unsigned __int8 v3; // si
  unsigned __int8 v4; // al
  unsigned __int16 v5; // si
  __int64 v7; // [esp+24h] [ebp-10h]
  __int64 v8; // [esp+2Ch] [ebp-8h]

  v0 = splusclock(); /*0x187d56*/
  v7 = qword_1E75D0; /*0x187d5d*/
  v1 = word_1E75D8; /*0x187d68*/
  __outbyte(0x43u, 0); /*0x187d76*/
  _InterlockedIncrement(&dword_1E75C4); /*0x187d77*/
  v2 = __inbyte(0x40u); /*0x187d87*/
  v3 = v2; /*0x187d90*/
  v4 = __inbyte(0x40u); /*0x187d92*/
  v5 = (v4 << 8) | v3; /*0x187da1*/
  word_1E75D8 = v5; /*0x187da4*/
  splx(v0); /*0x187dac*/
  if ( v5 > v1 ) /*0x187db7*/
    v7 += 10000000; /*0x187db9*/
  v8 = (unsigned __int16)word_1E75DA - v5; /*0x187dd1*/
  return v7 + 1000000000 * v8 / 0x1234CFuLL; /*0x187e8d*/
}
