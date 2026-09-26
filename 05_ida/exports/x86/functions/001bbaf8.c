/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bbaf8. */
int __cdecl _NXAudioStreamControl(id a1, int a2, int a3, int a4)
{
  id v5; // eax

  if ( !a1 ) /*0x1bbb09*/
    return 202; /*0x1bbb10*/
  objc_msgSend(a1, sel_ownerPort); /*0x1bbb20*/
  v5 = objc_msgSend(a1, sel_channel); /*0x1bbb35*/
  if ( !(unsigned __int8)objc_msgSend(v5, sel_checkOwner_) ) /*0x1bbb3e*/
    return 200; /*0x1bbb4f*/
  if ( a2 == 1 ) /*0x1bbb58*/
  {
    objc_msgSend(a1, sel_control_atTime_, 1, a3, a4); /*0x1bbb90*/
  }
  else if ( a2 > 1 ) /*0x1bbb5a*/
  {
    if ( a2 == 2 ) /*0x1bbb68*/
    {
      objc_msgSend(a1, sel_control_atTime_, 2, a3, a4); /*0x1bbb78*/
    }
    else
    {
      if ( a2 != 3 ) /*0x1bbb6e*/
        return 206; /*0x1bbb6e*/
      objc_msgSend(a1, sel_returnRecordedData); /*0x1bbba0*/
    }
  }
  else
  {
    if ( a2 ) /*0x1bbb60*/
      return 206; /*0x1bbbad*/
    objc_msgSend(a1, sel_control_atTime_, 0, a3, a4); /*0x1bbb80*/
  }
  return 0; /*0x1bbbb5*/
}
