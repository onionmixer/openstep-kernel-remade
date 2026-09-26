/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb3e0. */
id __cdecl audio_port_to_stream(int a1)
{
  id result; // eax

  result = +[AudioChannel streamForUserPort:](aAudiochannel, sel_streamForUserPort_, a1); /*0x1bb3f5*/
  if ( !result )
  {
    IOLog((int)"Audio: server can't translate port to stream\n");
    return nullptr; /*0x1bb40b*/
  }
  return result; /*0x1bb40f*/
}
