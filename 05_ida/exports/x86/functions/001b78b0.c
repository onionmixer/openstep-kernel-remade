/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b78b0. */
id __cdecl +[AudioChannel streamForOwnerPort:](id a1, SEL a2, int a3)
{
  unsigned int i; // esi
  id v4; // ebx

  for ( i = 0; i < (unsigned int)objc_msgSend(dword_1E5398, sel_count); ++i ) /*0x1b78b9*/
  {
    v4 = objc_msgSend(dword_1E5398, sel_objectAt_, i); /*0x1b78ea*/
    if ( objc_msgSend(v4, sel_ownerPort) == (id)a3 ) /*0x1b78fe*/
      return v4; /*0x1b7902*/
  }
  return nullptr; /*0x1b790d*/
}
