/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b6108. */
id __cdecl +[IOAudio _inputChannelForSndPort:](id a1, SEL a2, int a3)
{
  unsigned int i; // esi
  id v4; // ebx
  id v5; // eax

  for ( i = 0; i < (unsigned int)objc_msgSend(dword_1E5390, sel_count); ++i ) /*0x1b6111*/
  {
    v4 = objc_msgSend(dword_1E5390, sel_objectAt_, i); /*0x1b6142*/
    v5 = objc_msgSend(v4, sel_audioDevice); /*0x1b6153*/
    if ( v4 == objc_msgSend(v5, sel__inputChannel) && objc_msgSend(v4, sel_userSndPort) == (id)a3 ) /*0x1b617a*/
      return v4; /*0x1b617e*/
  }
  return nullptr; /*0x1b6189*/
}
