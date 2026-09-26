/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b60a4. */
id __cdecl +[IOAudio _channelForExclusivePort:](id a1, SEL a2, int a3)
{
  unsigned int i; // esi
  id v4; // ebx

  for ( i = 0; i < (unsigned int)objc_msgSend(dword_1E5390, sel_count); ++i ) /*0x1b60ad*/
  {
    v4 = objc_msgSend(dword_1E5390, sel_objectAt_, i); /*0x1b60de*/
    if ( objc_msgSend(v4, sel_exclusiveUser) == (id)a3 ) /*0x1b60f2*/
      return v4; /*0x1b60f6*/
  }
  return nullptr; /*0x1b6101*/
}
