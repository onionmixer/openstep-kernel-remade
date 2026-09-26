/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb3a8. */
id __cdecl audio_port_to_device(int a1)
{
  id result; // eax

  result = +[IOAudio _channelForUserPort:](aIoaudio, sel__channelForUserPort_, a1); /*0x1bb3bd*/
  if ( !result )
  {
    IOLog((int)"Audio: server can't translate port to channel\n");
    return nullptr; /*0x1bb3d3*/
  }
  return result; /*0x1bb3d7*/
}
