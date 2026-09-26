/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cc0dc. */
_DWORD *__cdecl NXCreateMapTable(int data, int a2, int a3, int a4, unsigned int a5)
{
  int v5; // eax
  int v7; // [esp+0h] [ebp-4h]
  int savedregs; // [esp+4h] [ebp+0h]

  v5 = NXDefaultMallocZone(v7, savedregs); /*0x1cc0e3*/
  return NXCreateMapTableFromZone(data, a2, a3, a4, a5, v5); /*0x1cc0ff*/
}
