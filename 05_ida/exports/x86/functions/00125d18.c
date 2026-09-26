/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x125d18. */
unsigned __int32 iptime()
{
  _DWORD v1[2]; // [esp+Ch] [ebp-8h] BYREF

  microtime(v1); /*0x125d24*/
  return _byteswap_ulong(v1[1] / 1000 + 1000 * (v1[0] % 86400)); /*0x125d68*/
}
