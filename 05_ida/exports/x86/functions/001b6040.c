/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b6040. */
id __cdecl +[IOAudio _channelForUserPort:](id a1, SEL a2, int a3)
{
  unsigned int i; // esi
  id v4; // ebx

  for ( i = 0; i < (unsigned int)objc_msgSend(dword_1E5390, sel_count); ++i ) /*0x1b6049*/
  {
    v4 = objc_msgSend(dword_1E5390, sel_objectAt_, i); /*0x1b607a*/
    if ( objc_msgSend(v4, sel_userChannelPort) == (id)a3 ) /*0x1b608e*/
      return v4; /*0x1b6092*/
  }
  return nullptr; /*0x1b609d*/
}
