/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b784c. */
id __cdecl +[AudioChannel streamForUserPort:](id a1, SEL a2, int a3)
{
  unsigned int i; // esi
  id v4; // ebx

  for ( i = 0; i < (unsigned int)objc_msgSend(dword_1E5398, sel_count); ++i ) /*0x1b7855*/
  {
    v4 = objc_msgSend(dword_1E5398, sel_objectAt_, i); /*0x1b7886*/
    if ( objc_msgSend(v4, sel_userPort) == (id)a3 ) /*0x1b789a*/
      return v4; /*0x1b789e*/
  }
  return nullptr; /*0x1b78a9*/
}
