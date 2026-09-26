/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bad40. */
_BOOL4 __cdecl audio_enroll_stream_port(int a1, int a2)
{
  int v2; // eax
  int v4; // [esp+0h] [ebp-4h]

  if ( a2 )
  {
    v2 = kern_serv_port_serv((int *)dword_1E8718, a1, (int)audioMessages, a1); /*0x1bad5d*/
    if ( v2 )
    {
      v4 = v2; /*0x1bad6f*/
      IOLog((int)"Audio: kern_serv_port_serv returns %d\n", v2);
      v2 = v4; /*0x1bad77*/
    }
  }
  else
  {
    kern_serv_port_gone((int *)dword_1E8718, a1); /*0x1bad84*/
    v2 = 0; /*0x1bad89*/
  }
  return v2 == 0; /*0x1bad95*/
}
