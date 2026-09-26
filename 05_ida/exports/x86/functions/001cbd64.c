/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cbd64. */
NXAtom __cdecl NXUniqueString(const char *buffer)
{
  NXAtom result; // eax
  const char *v2; // ebx

  if ( !buffer ) /*0x1cbd6e*/
    return nullptr; /*0x1cbdee*/
  ++dword_1E555C; /*0x1cbd70*/
  if ( !dword_1E5558 ) /*0x1cbd7d*/
    dword_1E5558 = NXCreateHashTable(NXStrPrototype, 0, nullptr); /*0x1cbda4*/
  result = (NXAtom)NXHashGet(dword_1E5558, buffer); /*0x1cbdb4*/
  if ( !result )
  {
    v2 = (const char *)sub_1CBC80(buffer); /*0x1cbdc8*/
    if ( !NXHashInsert(dword_1E5558, v2) ) /*0x1cbdd2*/
      return v2; /*0x1cbde0*/
    _NXLogError("*** NXUniqueString: invariant broken\n");
    return nullptr; /*0x1cbde9*/
  }
  return result; /*0x1cbdf3*/
}
