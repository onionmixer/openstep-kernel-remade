/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x187e94. */
unsigned __int64 event_get()
{
  int v0; // ecx
  unsigned __int16 v1; // bx
  unsigned __int8 v2; // al
  unsigned __int8 v3; // si
  unsigned __int8 v4; // al
  unsigned __int16 v5; // si
  __int64 v7; // [esp+24h] [ebp-10h]
  __int64 v8; // [esp+2Ch] [ebp-8h]

  v0 = splusclock(); /*0x187ea2*/
  v8 = qword_1E75D0; /*0x187ea9*/
  v1 = word_1E75D8; /*0x187eb4*/
  __outbyte(0x43u, 0); /*0x187ec2*/
  _InterlockedIncrement(&dword_1E75C4); /*0x187ec3*/
  v2 = __inbyte(0x40u); /*0x187ed3*/
  v3 = v2; /*0x187edc*/
  v4 = __inbyte(0x40u); /*0x187ede*/
  v5 = (v4 << 8) | v3; /*0x187eed*/
  word_1E75D8 = v5; /*0x187ef0*/
  splx(v0); /*0x187ef8*/
  if ( v5 > v1 ) /*0x187f03*/
    v8 += 10000000; /*0x187f05*/
  v7 = (unsigned __int16)word_1E75DA - v5; /*0x187f1d*/
  return 1000000000 * v7 / 0x1234CFuLL + v8; /*0x187fe2*/
}
