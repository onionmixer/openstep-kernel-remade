/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c9c50. */
id __cdecl +[Object alloc](id a1, SEL a2)
{
  void *v2; // eax
  int v4; // [esp+0h] [ebp-4h]
  int savedregs; // [esp+4h] [ebp+0h]

  v2 = (void *)NXDefaultMallocZone(v4, savedregs); /*0x1c9c57*/
  return _zoneAlloc((Class)a1, 0, v2); /*0x1c9c67*/
}
