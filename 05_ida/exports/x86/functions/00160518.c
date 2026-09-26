/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x160518. */
int __cdecl ns_sleep(__int64 a1)
{
  int v1; // edi
  __int64 v2; // rax
  __int64 v4; // [esp+Ch] [ebp-10h]

  v1 = splnet(); /*0x160532*/
  v4 = a1; /*0x160537*/
  v2 = clock_value(1); /*0x160542*/
  calloutDispatchDelayed(wakeup, &a1, v2 + v4, (unsigned __int64)(v2 + v4) >> 32); /*0x160566*/
  sleep((unsigned int)&a1); /*0x160574*/
  return splx(v1); /*0x160582*/
}
