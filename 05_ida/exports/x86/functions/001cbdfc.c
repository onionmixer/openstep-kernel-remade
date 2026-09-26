/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cbdfc. */
NXAtom __cdecl NXUniqueStringNoCopy(const char *string)
{
  ++dword_1E555C; /*0x1cbdff*/
  if ( !dword_1E5558 ) /*0x1cbe0c*/
    dword_1E5558 = NXCreateHashTable(NXStrPrototype, 0, nullptr); /*0x1cbe33*/
  return (NXAtom)NXHashInsertIfAbsent(dword_1E5558, string); /*0x1cbe4d*/
}
