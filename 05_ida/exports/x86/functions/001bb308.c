/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bb308. */
int __cdecl audioMessages(_DWORD *a1, _DWORD *a2)
{
  int result; // eax

  if ( a1[3] )
  {
    if ( (int)a1[5] > 699 )
    {
      if ( !audio_server(a1, a2) )
        IOLog((int)"Audio: unrecognized audio user message %d\n", a1[5]);
    }
    else if ( !snd_server(a1, a2) )
    {
      IOLog((int)"Audio: unrecognized snd user message %d\n", a1[5]);
    }
  }
  else if ( !sub_1BAE88(a1, (int)a2) )
  {
    IOLog((int)"Audio: unrecognized control message %d\n", a1[5]);
  }
  result = msg_send(a2, 1, 1000); /*0x1bb37f*/
  if ( result ) /*0x1bb389*/
    result = IOLog((int)"msg_send failed %d\n", result); /*0x1bb391*/
  a2[7] = -305; /*0x1bb396*/
  return result; /*0x1bb3a0*/
}
