/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x103658. */
void __cdecl timeout(int a1)
{
  __int64 v1; // rax
  int v2; // [esp+14h] [ebp+Ch]
  int v3; // [esp+18h] [ebp+10h]

  v1 = ticks_to_ns_time(v3); /*0x103669*/
  ns_timeout(a1, v2, v1, HIDWORD(v1)); /*0x103675*/
}
